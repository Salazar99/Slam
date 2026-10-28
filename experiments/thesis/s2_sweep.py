"""S2: SLAM sensitivity, scalability and the Table I details.

    python s2_sweep.py sensitivity [--cases ...] [--tag s2_sensitivity_sim]   # --min-final x clsEffort scale
    python s2_sweep.py scalability   # number of dt numeric expressions at fixed trace length
    python s2_sweep.py table1        # P/NE sets, template, trace length per benchmark
    python s2_sweep.py tune [--cases ...]   # per-context SLAM configuration search (Simulink designs)

Outputs in results/: s2_sensitivity.{csv,md}, s2_scalability.{csv,md,png}, s2_tableI.md.
"""
import argparse
import csv
import itertools
import re
import statistics as st
import subprocess
import tempfile
from pathlib import Path

from common import CASES, RESULTS, UnsupportedFormula, load_truth, run_slam, to_fragment, traces_of
from score import per_requirement, summarize

MIN_FINAL = [0.80, 0.85, 0.90, 0.95]
CLS_SCALE = [0.1, 1, 10]
FDL = ["WaterTanks", "Gearbox", "Heater"]
SIM = ["autotrans", "fuelsys", "absbrake", "househeat"]
# Per-context configuration search (user: "use the best template to mine with SLAM", not a standard one):
# the knobs SLAM exposes (README: dtLimits operands/windows, clustering effort, ranking metrics, consequent
# window). The winner covers its requirement (paper notion), then has the best own-context G, then fewest
# assertions. Selected against the golden reference: an existence result, not blind mining.
TUNE = dict(A=[1, 3], maxd=[0, 5, 20, 100], cls=[0.001, 0.01, 0.1], sorts=["causality,support", "support"])
SORT_EXP = {"causality": "1-afct/traceLength", "support": "atct/traceLength"}


def scaled(conf, factor):
    """SLAM configs are not well-formed XML (raw < and > in attributes): edit them as text.
    Config with every clsEffort (elbow threshold th) multiplied by factor, as a temp file."""
    text = re.sub(r'clsEffort\s*=\s*"([\d.eE+-]+)"',
                  lambda m: f'clsEffort="{float(m.group(1)) * factor:g}"', Path(conf).read_text())
    tmp = tempfile.NamedTemporaryFile("w", suffix=".xml", delete=False)
    tmp.write(text)
    tmp.close()
    return tmp.name


def candidates(case, ass, source):
    rows = []
    for context, lines in ass.items():
        for rank, line in enumerate(lines, 1):
            try:
                formula = to_fragment(line)
            except (UnsupportedFormula, ValueError):
                formula = ""
            rows.append(dict(case=case, source=source, sample=0, context=context, rank=rank, formula=formula))
    return rows


def sensitivity(cases, tag):
    truth = [r for r in load_truth() if r["case"] in cases]
    out = []
    for case in cases:
        for scale in CLS_SCALE:
            conf = scaled(CASES[case][0], scale)
            for mf in MIN_FINAL:
                ass, ttm, wall = run_slam(conf, CASES[case][1], ["--min-final", mf])
                src = f"mf{mf}_th{scale}"
                rows = per_requirement([r for r in truth if r["case"] == case], candidates(case, ass, src))
                s = summarize([r for r in truth if r["case"] == case], rows)[0] if rows else {}
                out.append(dict(case=case, min_final=mf, th_scale=scale,
                                n_ass=sum(map(len, ass.values())), time_to_mine_s=round(sum(ttm.values()), 3),
                                wall_s=round(wall, 3), **{k: s.get(k, 0.0) for k in ("cov_paper", "cov@1", "cov@0.9", "cov@0.5", "meanG")}))
                print(out[-1], flush=True)
    write(out, tag)


# Numeric expressions for the scalability series: WaterTanks trace signals, then pairwise
# sums/differences; the first k are used. No @(x,k): the derivative is computed on the trace,
# it is not a trace signal, so it cannot be a decision-tree numeric.
EXPRS = ["z", "d", "rain", "w", "clk", "amount", "z+d", "z-d",
         "d-w", "z+rain", "d+rain", "z-w", "w+d", "z+w", "z-amount", "d+amount"]
SCAL_CONF = """<slam>
\t<context name="scal">
{numerics}
\t\t<template dtLimits="3A,0.1E,100maxd,0mind" exp="G( ..F.. -> F[0,0]a==1)" />
\t\t<sort name="causality" exp="1-afct/traceLength"/>
\t\t<sort name="support" exp="atct/traceLength"/>
\t</context>
</slam>
"""


def scalability(ks, reps, threads, timeout):
    trace = CASES["WaterTanks"][1]
    out = []
    for k in ks:
        numerics = "\n".join(f'\t\t<numeric op="le,ge" clsEffort="0.01" exp="{e}" loc="dt"/>' for e in EXPRS[:k])
        with tempfile.NamedTemporaryFile("w", suffix=".xml", delete=False) as fh:
            fh.write(SCAL_CONF.format(numerics=numerics))
        for rep in range(reps):
            try:
                ass, ttm, wall = run_slam(fh.name, trace, ["--min-final", 0.90, "--max-threads", threads],
                                          timeout=timeout)
                row = dict(k=k, rep=rep, n_ass=sum(map(len, ass.values())),
                           time_to_mine_s=round(sum(ttm.values()), 3), wall_s=round(wall, 3), status="ok")
            except subprocess.TimeoutExpired:
                row = dict(k=k, rep=rep, n_ass="", time_to_mine_s="", wall_s="", status=f"timeout {timeout}s")
            out.append(row)
            print(row, flush=True)
            if row["status"] != "ok":
                break       # larger k will not be faster
        if out[-1]["status"] != "ok":
            break
    write(out, "s2_scalability")
    plot(out)


def plot(rows):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    ks = sorted({r["k"] for r in rows if r["status"] == "ok"})
    mean = [st.mean(r["wall_s"] for r in rows if r["k"] == k and r["status"] == "ok") for k in ks]
    sd = [st.stdev([r["wall_s"] for r in rows if r["k"] == k and r["status"] == "ok"] or [0, 0]) for k in ks]
    fig, ax = plt.subplots(figsize=(4.5, 3))
    ax.errorbar(ks, mean, yerr=sd, marker="o", color="#2a78d6", capsize=3, lw=1.5)
    ax.set_xscale("log", base=2)
    ax.set_yscale("log")
    ax.set_xticks(ks, [str(k) for k in ks])
    ax.set_xlabel("dt numeric expressions")
    ax.set_ylabel("mining time (s)")
    ax.spines[["top", "right"]].set_visible(False)
    ax.grid(axis="y", color="#e6e6e6", lw=0.6)
    fig.tight_layout()
    fig.savefig(RESULTS / "s2_scalability.png", dpi=200)
    fig.savefig(RESULTS / "s2_scalability.pdf")


def table1():
    lines = ["| Benchmark | Context | P (prop) | NE (numeric, op, th) | Template | dtLimits | Trace length |",
             "|---|---|---|---|---|---|---|"]
    for case, (conf, _) in CASES.items():
        n = sum(len(next(iter(t.values()))) for t in traces_of(case))
        text = re.sub(r"<!--.*?-->", "", Path(conf).read_text(), flags=re.S)
        for name, body in re.findall(r'<context\s+name\s*=\s*"([^"]*)"\s*>(.*?)</context>', text, re.S):
            tags = lambda t: [dict(re.findall(r'(\w+)\s*=\s*"([^"]*)"', a))  # noqa: E731
                              for a in re.findall(rf"<{t}\b(.*?)/>", body, re.S)]
            props = ", ".join(p["exp"] for p in tags("prop")) or "-"
            nes = ", ".join(f"{e['exp']} ({e.get('op', 'r,e')}, {e.get('clsEffort', '0.3')})"
                            for e in tags("numeric")) or "-"
            for t in tags("template"):
                lines.append(f"| {case} | {name} | {props} | {nes} | `{t['exp']}` | "
                             f"{t.get('dtLimits', '')} | {n} |")
    (RESULTS / "s2_tableI.md").write_text("\n".join(lines) + "\n")
    print("\n".join(lines))


def config_contexts(conf):
    """[(name, numeric expressions, consequent)] of a config, read as text (not well-formed XML)."""
    text = re.sub(r"<!--.*?-->", "", Path(conf).read_text(), flags=re.S)
    return [(name, re.findall(r'<numeric\b[^>]*?exp="([^"]*)"', body),
             re.search(r'exp="G\( \.\.F\.\. -> F\[0,\d+\]\((.*)\)\)"', body).group(1))
            for name, body in re.findall(r'<context\s+name="([^"]*)">(.*?)</context>', text, re.S)]


def context_xml(name, numerics, cons, A, maxd, cls, sorts, window):
    nums = "".join(f'\t\t<numeric op="le,ge" clsEffort="{cls:g}" exp="{e}" loc="dt"/>\n' for e in numerics)
    srt = "".join(f'\t\t<sort name="{m}" exp="{SORT_EXP[m]}"/>\n' for m in sorts.split(","))
    return (f'\t<context name="{name}">\n{nums}\t\t<template dtLimits="{A}A,0.1E,{maxd}maxd,0mind" '
            f'exp="G( ..F.. -> F[0,{window}]({cons}))" />\n{srt}\t</context>\n')


def tune(cases):
    truth = {(r["case"], r["context"]): r for r in load_truth() if r["encodable"] == "yes"}
    log = []
    for case in cases:
        chosen = []
        for name, nums, cons in config_contexts(CASES[case][0]):
            req = truth[(case, name)]
            m = re.search(r"->\s*F\[0,(\d+)\]", req["stl"])     # documented reaction window, if any
            best = None
            for A, maxd, cls, sorts, w in itertools.product(*TUNE.values(), sorted({0, int(m[1]) if m else 0})):
                xml = context_xml(name, nums, cons, A, maxd, cls, sorts, w)
                with tempfile.NamedTemporaryFile("w", suffix=".xml", delete=False) as fh:
                    fh.write(f"<slam>\n{xml}</slam>\n")
                ass, _, _ = run_slam(fh.name, CASES[case][1], ["--min-final", 0.90])
                cands = candidates(case, ass, "tune") or [dict(case=case, source="tune", sample=0, context=name,
                                                               rank=0, formula="")]
                r = per_requirement([req], cands)[0]
                n = sum(map(len, ass.values()))
                log.append(dict(case=case, context=name, A=A, maxd=maxd, clsEffort=cls, sorts=sorts, window=w,
                                n_ass=n, covered=r["covered"], own_G=r["best_G"]))
                key = (r["covered"], r["best_G"], -n)
                if best is None or key > best[0]:
                    best = (key, xml, log[-1])
            chosen.append(best[1])
            print("chosen", best[2], flush=True)
        Path(CASES[case][0]).write_text(
            "<slam>\n\t<!-- One context per golden-reference requirement (experiments/thesis/ground_truth.csv), "
            "configured by\n\t     `s2_sweep.py tune` (grid and choice in experiments/thesis/results/s2_tuning.csv). -->\n"
            + "".join(chosen) + "</slam>\n")
    write(log, "s2_tuning")


def write(rows, name):
    with open(RESULTS / f"{name}.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    md = ["| " + " | ".join(rows[0]) + " |", "|" + "---|" * len(rows[0])]
    md += ["| " + " | ".join(str(v) for v in r.values()) + " |" for r in rows]
    (RESULTS / f"{name}.md").write_text("\n".join(md) + "\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("what", choices=["sensitivity", "scalability", "table1", "tune"])
    ap.add_argument("--cases", nargs="*", default=FDL)
    ap.add_argument("--ks", nargs="*", type=int, default=[1, 2, 4, 8, 16])
    ap.add_argument("--reps", type=int, default=5)
    ap.add_argument("--threads", type=int, default=16)
    ap.add_argument("--timeout", type=int, default=3600)
    ap.add_argument("--tag", default="s2_sensitivity", help="output name of the sensitivity grid")
    args = ap.parse_args()
    if args.what == "sensitivity":
        sensitivity(args.cases, args.tag)
    elif args.what == "tune":
        tune(args.cases if args.cases != FDL else SIM)
    elif args.what == "scalability":
        scalability(args.ks, args.reps, args.threads, args.timeout)
    else:
        table1()


if __name__ == "__main__":
    main()
