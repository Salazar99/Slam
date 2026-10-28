"""Score candidate sets against the ground truth with G (S1, S2, S6).

    python score.py --check-truth
    python score.py results/s1_candidates.csv [results/s6_candidates.csv ...] [--tag s1]

For every requirement r and every candidate set (case, source, sample): best-G of r against
all candidates of the case (and, for SLAM, against its own context only), on the domain D
of r (see common.domain). Outputs:
  results/<tag>_per_req.csv  one row per (requirement, source, sample)
  results/<tag>_table.{csv,md,tex}  per case and source: coverage at G = 1 and at G >= tau,
                                    mean best-G; mean +- std over samples for LLM sources.
"""
import argparse
import csv
import statistics as st
import sys
from collections import defaultdict

from common import RESULTS, TAUS, check_on_traces, domain, load_truth, parse, scores

EXACT = 1 - 1e-9
MAIN_TAU = 0.9


def check_truth(truth):
    bad = 0
    for r in truth:
        if r["encodable"] != "yes":   # "no" (outside the fragment) or "falsified" (violated by the system)
            print(f"{r['req_id']:5} skipped ({r['encodable']}): {r['note']}")
            continue
        try:
            parse(r["stl"])
            viol, trig = check_on_traces(r["stl"], r["case"])
        except Exception as exc:  # noqa: BLE001
            viol, trig = f"error {exc}", 0
        ok = viol == 0 and (trig > 0 or "->" not in r["stl"])   # invariants have nothing to trigger
        bad += not ok
        print(f"{r['req_id']:5} {'ok ' if ok else 'BAD'} violations={viol} triggers={trig}  {r['stl']}")
    return bad


def per_requirement(truth, cands):
    groups = defaultdict(list)
    for c in cands:
        if c["formula"]:
            groups[(c["case"], c["source"], c["sample"])].append(c)
    keys = sorted({(c["case"], c["source"], c["sample"]) for c in cands})
    rows = []
    for r in (r for r in truth if r["encodable"] == "yes"):
        D = domain(r["case"], [r["stl"]])
        for case, source, sample in (k for k in keys if k[0] == r["case"]):
            group = groups[(case, source, sample)]
            sc = scores([(r["stl"], c["formula"]) for c in group], D)
            done = [(sc[(r["stl"], c["formula"])], c) for c in group if sc[(r["stl"], c["formula"])]["G"] is not None]
            best, bc = max(done, key=lambda x: x[0]["G"], default=({"G": 0.0, "fw": None, "bw": None}, {}))
            own = [s["G"] for s, c in done if c["context"] == r["context"]]
            rows.append(dict(case=case, req_id=r["req_id"], source=source, sample=sample, D=str(D),
                             n_cands=len(group), timeouts=len(group) - len(done),
                             best_G=round(best["G"], 6), fw=best["fw"], bw=best["bw"],
                             best_cand=bc.get("formula", ""), best_ctx=bc.get("context", ""),
                             best_own_ctx_G=round(max(own), 6) if own else ""))
    return rows


def summarize(truth, rows):
    """Per (case, source): metrics per sample, then mean and std over samples."""
    n_req = defaultdict(int)
    n_enc = defaultdict(int)
    for r in truth:
        n_req[r["case"]] += 1
        n_enc[r["case"]] += r["encodable"] == "yes"
    by = defaultdict(lambda: defaultdict(list))
    for x in rows:
        by[(x["case"], x["source"])][x["sample"]].append(x["best_G"])
    out = []
    for (case, source), samples in sorted(by.items()):
        per = []
        for gs in samples.values():
            m = {"cov@1": sum(g >= EXACT for g in gs) / n_enc[case], "meanG": st.mean(gs)}
            m.update({f"cov@{t}": sum(g >= t - 1e-12 for g in gs) / n_enc[case] for t in TAUS})
            per.append(m)
        row = dict(case=case, source=source, n_req=n_req[case], encodable=n_enc[case], samples=len(per))
        for k in per[0]:
            vals = [m[k] for m in per]
            row[k] = round(st.mean(vals), 4)
            row[k + "_std"] = round(st.stdev(vals), 4) if len(vals) > 1 else 0.0
        out.append(row)
    return out


def fmt(row, k):
    return f"{row[k]:.2f}" + (f" ± {row[k + '_std']:.2f}" if row["samples"] > 1 else "")


def write(tag, rows, table):
    with open(RESULTS / f"{tag}_per_req.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    with open(RESULTS / f"{tag}_table.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, list(table[0]))
        w.writeheader()
        w.writerows(table)
    cols = ["cov@1", f"cov@{MAIN_TAU}", "meanG"]
    head = f"| Design | Source | Reqs (encodable) | Coverage G = 1 | Coverage G ≥ {MAIN_TAU} | Mean best-G |"
    md = [head, "|---|---|---|---|---|---|"]
    tex = [r"\begin{tabular}{llcccc}", r"\toprule",
           rf"Design & Source & Reqs & Cov.\ $G{{=}}1$ & Cov.\ $G{{\geq}}{MAIN_TAU}$ & Mean best-$G$ \\", r"\midrule"]
    for t in table:
        vals = [fmt(t, k) for k in cols]
        md.append(f"| {t['case']} | {t['source']} | {t['n_req']} ({t['encodable']}) | " + " | ".join(vals) + " |")
        tex.append(f"{t['case']} & {t['source']} & {t['n_req']} ({t['encodable']}) & "
                   + " & ".join(v.replace("±", r"$\pm$") for v in vals) + r" \\")
    tex += [r"\bottomrule", r"\end{tabular}"]
    (RESULTS / f"{tag}_table.md").write_text("\n".join(md) + "\n")
    (RESULTS / f"{tag}_table.tex").write_text("\n".join(tex) + "\n")
    print("\n".join(md))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("candidates", nargs="*")
    ap.add_argument("--check-truth", action="store_true")
    ap.add_argument("--tag", default="s1")
    args = ap.parse_args()
    truth = load_truth()
    if check_truth(truth) and not args.check_truth:
        sys.exit("ground truth fails on its traces: fix it before scoring")
    if args.check_truth:
        return
    cands = [c for path in args.candidates for c in csv.DictReader(open(path))]
    rows = per_requirement(truth, cands)
    write(args.tag, rows, summarize(truth, rows))


if __name__ == "__main__":
    main()
