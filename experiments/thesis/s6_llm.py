"""S6: LLM baseline for SLAM (free local models through Ollama), scored with G like S1.

    python s6_llm.py estimate          # prompt sizes against the context window
    python s6_llm.py run               # 5 samples per prompt and model, resumable
    python s6_llm.py candidates        # results/s6_candidates.csv for score.py

Needs `ollama serve` (OLLAMA_URL, default http://127.0.0.1:11434) with the MODELS pulled.
Two modes, as gemini_design / gemini_trace in USM-T:
  req   one formula per informal requirement (the RQ4 prompt of the similarity paper, plus a
        signal glossary). Unfair advantage: it reads the requirement text.
  trace up to 10 assertions per SLAM context from the trace and the same hints SLAM gets
        (consequent of the context template, antecedent signals). Like-for-like with SLAM.
        Also scored keeping only the assertions that hold on the trace ('-checked'),
        which SLAM guarantees by construction.
"""
import argparse
import csv
import json
import os
import re
import time
import urllib.request

import numpy as np

from common import CASES, RESULTS, UnsupportedFormula, check_on_traces, clean, convert, load_truth, parse
from experiments.rq4_llm.generate import PROMPT

K, TEMPERATURE = 5, 0.8            # as tabex RQ4, with 5 samples
MODELS = ["qwen2.5:7b-instruct", "qwen2.5:14b-instruct"]   # free, local (Ollama, RTX 3060)
NUM_CTX = {"req": 4096, "trace": 20480}
NUM_PREDICT = {"req": 200, "trace": 1500}                  # req: as RQ4
# Ollama silently cuts a prompt longer than num_ctx to num_ctx/2 (keeping only the first 4 tokens).
# Every token covers at least one byte, so bytes + NUM_PREDICT + MARGIN <= NUM_CTX guarantees no cut
# (Qwen tokenizes digits one by one: a numeric CSV is close to one token per byte).
MARGIN = 256           # chat template and default system prompt
SAMPLES = RESULTS / "s6_samples.jsonl"

SYSTEM = {
    "WaterTanks": "Two water tanks, main (level z) and secondary (level d). Weather (w, rain) fills or dries the "
                  "main tank; water flows from the main to the secondary tank; a controller opens a return valve "
                  "(aperture a, 0 = closed, 1 = open) from the secondary to the main tank to prevent overflow "
                  "(z = 2) and drying out.",
    "Gearbox": "A 4-speed automatic transmission of a vehicle: speed omega, travelled distance theta, throttle "
               "input, selected gear (0 = stopped, 1-4).",
    "Heater": "A thermostat regulating the temperature T of a room: heater status Status (1 = on, 0 = off, "
              "2 = night mode), clock C counting the hours of the current day or night period.",
    "autotrans": "Simulink sldemo_autotrans: automatic transmission controller of a vehicle (4 gears). Inputs "
                 "throttle (0-100 %) and brake (0-325 lb-ft); outputs vehicle speed (mph), engine speed rpm and "
                 "selected gear. One row every 0.1 s.",
    "fuelsys": "Simulink sldemo_fuelsys: fault-tolerant fuel control of a gasoline engine in fault-free operation. "
               "Throttle angle (deg), engine speed (rad/s), manifold pressure map (bar), oxygen sensor voltage ego, "
               "air-fuel ratio afr (stoichiometric 14.6), fuel rate. One row every 0.1 s.",
    "absbrake": "Simulink sldemo_absbrake: anti-lock braking of a single wheel with ABS on. Vehicle speed vs and "
                "wheel speed ww (angular-velocity units), relative slip (target 0.2), stopping distance sd. "
                "One row every 0.05 s.",
    "househeat": "Simulink sldemo_househeat: thermal model of a house with a thermostat (set point 70 F, "
                 "+-5 F hysteresis). Indoor temperature tin and outdoor temperature tout (F), heater on/off, "
                 "cumulative heating cost. One row every minute.",
}
DERIV = "The one-step increment x(t+1) - x(t) of a signal x is available as the signal x_d1."

TRACE_PROMPT = """You mine Signal Temporal Logic (STL) assertions from an execution trace of a cyber-physical system.

System: {system}
Signals (observed range): {signals}
Time is discrete: each trace row is one time unit. {deriv}

Trace (CSV, {n} rows):
{csv}

Mine assertions of the form
  antecedent -> F[a,b] consequent
that hold at every instant of the trace and describe the intended behaviour of the system, where
  consequent is exactly: {consequent}
  antecedent uses only the signals {ant_signals}, combined with &&, ||, ! and bounded F[a,b] / G[a,b]
Intervals [a,b] are closed, with non-negative integer bounds, relative to the current instant.
An atom compares ONE signal with ONE constant: signal op constant, op one of < <= > >= == != (no "x > y", no arithmetic).

Answer with up to 10 assertions, one per line, most relevant first: no explanation, no numbering, no markdown."""


def glossary(case):
    tr = __import__("common").traces_of(case)[0]
    return ", ".join(f"{k} [{v.min():g}, {v.max():g}]" for k, v in tr.items())


def trace_csv(case, budget):
    """First trace of the case (first file of a trace directory), cut to `budget` bytes."""
    path = CASES[case][1]
    path = sorted(path.glob("*.csv"))[0] if path.is_dir() else path
    lines = path.read_text().splitlines()
    header = ",".join(tok.split()[-1] for tok in lines[0].split(","))
    rows, size = [], len(header)
    for l in lines[1:]:
        row = ",".join(f"{float(x):.4g}" for x in l.split(","))
        size += len(row) + 1
        if size > budget:
            break
        rows.append(row)
    return header + "\n" + "\n".join(rows), len(rows)


def contexts(case):
    """[(context, consequent, antecedent signals)] from the SLAM config, as given to SLAM."""
    text = re.sub(r"<!--.*?-->", "", CASES[case][0].read_text(), flags=re.S)
    out = []
    for name, body in re.findall(r'<context\s+name\s*=\s*"([^"]*)"\s*>(.*?)</context>', text, re.S):
        tmpl = re.search(r'<template\b[^/]*?exp\s*=\s*"([^"]*)"', body).group(1)
        cons = re.search(r"->\s*F\[0,0\]\s*(.*)\)\s*$", tmpl.strip()).group(1).strip()
        cons = re.sub(r"@\(\s*(\w+)\s*,\s*(\d+)\s*\)", r"\1_d\2", cons)
        sigs = sorted({e for e in re.findall(r'<numeric\b[^/]*?exp\s*=\s*"([^"]*)"', body)})
        out.append((name, cons, sigs))
    return out


def prompts(cases):
    """[(mode, id, case, context, text)]. All the trace prompts of a case share the same excerpt
    (the longest that fits every context's prompt) and the same prefix, which Ollama caches."""
    out = []
    for r in load_truth():
        if r["case"] in cases and r["encodable"] == "yes":
            english = f"{r['english']}\nSignals of the system (observed range): {glossary(r['case'])}. {DERIV}"
            out.append(("req", r["req_id"], r["case"], r["context"], PROMPT.format(english=english)))
    for case in cases:
        fmt = [dict(system=SYSTEM.get(case, ""), signals=glossary(case), deriv=DERIV, consequent=cons,
                    ant_signals=", ".join(sigs)) for _, cons, sigs in contexts(case)]
        fixed = max(len(TRACE_PROMPT.format(**f, n=10 ** 6, csv="").encode()) for f in fmt)
        csv_text, n = trace_csv(case, NUM_CTX["trace"] - NUM_PREDICT["trace"] - MARGIN - fixed)
        for (name, _, _), f in zip(contexts(case), fmt):
            out.append(("trace", f"{case}/{name}", case, name, TRACE_PROMPT.format(**f, n=n, csv=csv_text)))
    for mode, pid, *_, text in out:
        assert len(text.encode()) + NUM_PREDICT[mode] + MARGIN <= NUM_CTX[mode], f"{pid}: prompt may be cut"
    return out


def done():
    if not SAMPLES.exists():
        return set()
    return {(r["mode"], r["id"], r["model"], r["sample"]) for r in map(json.loads, SAMPLES.read_text().splitlines())}


def generate(model, text, mode, k, url):
    """One Ollama completion (as tabex rq4_llm.generate.run_ollama). Returns (answer, record fields)."""
    body = json.dumps({"model": model, "prompt": text, "stream": False,
                       "options": {"temperature": TEMPERATURE, "seed": k + 1, "num_ctx": NUM_CTX[mode],
                                   "num_predict": NUM_PREDICT[mode]}}).encode()
    req = urllib.request.Request(f"{url}/api/generate", data=body, headers={"Content-Type": "application/json"})
    start = time.perf_counter()
    with urllib.request.urlopen(req, timeout=3600) as resp:
        out = json.load(resp)
    return out.get("response", ""), dict(tokens_in=out.get("prompt_eval_count", 0),
                                         tokens_out=out.get("eval_count", 0),
                                         secs=round(time.perf_counter() - start, 2), cost_usd=0.0)


def run(cases, models, url):
    keys = done()
    for model in models:
        for mode, pid, case, context, text in prompts(cases):
            for k in range(K):
                if (mode, pid, model, k) in keys:
                    continue
                answer, extra = generate(model, text, mode, k, url)
                with open(SAMPLES, "a") as fh:
                    fh.write(json.dumps(dict(mode=mode, id=pid, case=case, context=context, model=model,
                                             sample=k, answer=answer, temperature=TEMPERATURE, seed=k + 1,
                                             **extra)) + "\n")
                print(f"{model:22} {mode:5} {pid:45} {k} {extra['secs']:7.1f}s {extra['tokens_in']:6} tok in",
                      flush=True)


FLIP = {"<": ">", ">": "<", "<=": ">=", ">=": "<=", "==": "==", "!=": "!="}


def to_formula(line):
    t = re.sub(r"^\s*(?:[-*•]\s*|\d+[.)]\s+)", "", line)       # bullet / "3. " numbering, not "16.2".strip().strip("`\"' ").rstrip(".;")
    t = convert(t)
    t = re.sub(r"@\(\s*(\w+)\s*,\s*(\d+)\s*\)", r"\1_d\2", t)
    # constant op signal -> signal op' constant (same meaning; the fragment wants the signal first)
    t = re.sub(r"(?<![\w.])(-?\d+(?:\.\d+)?)\s*(<=|>=|==|!=|<|>)\s*([A-Za-z_]\w*)",
               lambda m: f"{m[3]} {FLIP[m[2]]} {m[1]}", t)
    parse(t)   # raises UnsupportedFormula / ValueError outside the fragment
    return t


def candidates():
    rows = []
    for r in map(json.loads, SAMPLES.read_text().splitlines()):
        lines = [clean(r["answer"])] if r["mode"] == "req" else \
            [l for l in re.sub(r"```[a-zA-Z]*", "", r["answer"]).splitlines() if l.strip()][:10]
        src = f"{r['model']}-{r['mode']}"
        for rank, line in enumerate(lines, 1):
            try:
                formula, reason = to_formula(line), ""
                viol = check_on_traces(formula, r["case"])[0]
            except (UnsupportedFormula, ValueError, KeyError, TypeError) as exc:
                formula, reason, viol = "", f"{type(exc).__name__}: {str(exc).splitlines()[0][:100]}", ""
            row = dict(case=r["case"], source=src, sample=r["sample"], context=r["context"], rank=rank,
                       slam=line.strip(), formula=formula, unsupported=reason, violations=viol)
            rows.append(row)
            if r["mode"] == "trace":
                rows.append({**row, "source": src + "-checked", "formula": formula if viol == 0 else ""})
    with open(RESULTS / "s6_candidates.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    table = ["| Source | Lines | Outside fragment / dropped | Violated on the traces |", "|---|---|---|---|"]
    for src in sorted({r["source"] for r in rows}):
        sel = [r for r in rows if r["source"] == src]
        ok = [r for r in sel if r["formula"]]
        table.append(f"| {src} | {len(sel)} | {len(sel) - len(ok)} | {sum(1 for r in ok if r['violations'] not in (0, ''))} |")
    (RESULTS / "s6_parse.md").write_text("\n".join(table) + "\n")
    print("\n".join(table))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("what", choices=["estimate", "run", "candidates"])
    ap.add_argument("--cases", nargs="*", default=list(CASES))
    ap.add_argument("--models", nargs="*", default=MODELS)
    ap.add_argument("--url", default=os.environ.get("OLLAMA_URL", "http://127.0.0.1:11434"))
    args = ap.parse_args()
    if args.what == "estimate":
        ps = prompts(args.cases)      # asserts that no prompt can be cut
        for mode in NUM_CTX:
            size = np.array([len(p[4].encode()) for p in ps if p[0] == mode])
            print(f"{mode:5}: {len(size)} prompts x {K} samples x {len(args.models)} models; prompt <= {size.max():,} "
                  f"tokens (bytes) vs num_ctx {NUM_CTX[mode]} - {NUM_PREDICT[mode]} for the answer")
        for case in args.cases:
            n = next(int(re.search(r"Trace \(CSV, (\d+) rows", p[4]).group(1)) for p in ps if p[2] == case and p[0] == "trace")
            print(f"  {case:10} excerpt {n} rows")
    elif args.what == "run":
        run(args.cases, args.models, args.url)
    else:
        candidates()


if __name__ == "__main__":
    main()
