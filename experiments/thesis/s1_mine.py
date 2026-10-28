"""S1 step 1: mine every case with its config (FDL protocol: --min-final 0.90).

    python s1_mine.py [--min-final 0.90] [--maxd N] [--cases WaterTanks Gearbox ...]

Output: results/s1_candidates.csv (case, source, sample, context, rank, slam, formula,
unsupported, violations) and results/s1_mining.csv (case, context, n, time_to_mine_s, wall_s).
`violations` counts the instants where the assertion is false on its own trace(s):
it must be 0 for every row (sanity check of the miner and of the translation).
"""
import argparse
import csv
import re
import tempfile
from pathlib import Path

from common import CASES, RESULTS, UnsupportedFormula, check_on_traces, run_slam, to_fragment

FIELDS = ["case", "source", "sample", "context", "rank", "slam", "formula", "unsupported", "violations"]


def capped(conf, maxd):
    """Config with every template's maxd capped (the RQ3 cap of tabex), as a temp file."""
    text = re.sub(r"(\d+)maxd", lambda m: f"{min(int(m.group(1)), maxd)}maxd", Path(conf).read_text())
    tmp = tempfile.NamedTemporaryFile("w", suffix=".xml", delete=False)
    tmp.write(text)
    tmp.close()
    return tmp.name


def mine(case, extra, conf=None):
    conf = conf or CASES[case][0]
    ass, ttm, wall = run_slam(conf, CASES[case][1], extra)
    rows = []
    for context in sorted(ass):
        for rank, line in enumerate(ass[context], 1):
            try:
                formula, reason = to_fragment(line), ""
            except (UnsupportedFormula, ValueError) as exc:
                formula, reason = "", str(exc).splitlines()[0][:120]
            viol = check_on_traces(formula, case)[0] if formula else ""
            rows.append(dict(case=case, source="slam", sample=0, context=context, rank=rank,
                             slam=line, formula=formula, unsupported=reason, violations=viol))
    if not rows:    # nothing mined: the case is still scored (every requirement uncovered)
        rows.append(dict(case=case, source="slam", sample=0, context="", rank=0, slam="", formula="",
                         unsupported="no assertion mined", violations=""))
    return rows, ttm, wall


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-final", default="0.90")
    ap.add_argument("--maxd", type=int)
    ap.add_argument("--cases", nargs="*", default=list(CASES))
    ap.add_argument("--tag", default="s1")
    args = ap.parse_args()
    RESULTS.mkdir(exist_ok=True)
    rows, stats = [], []
    for case in args.cases:
        conf = capped(CASES[case][0], args.maxd) if args.maxd else None
        r, ttm, wall = mine(case, ["--min-final", args.min_final], conf)
        rows += r
        for context, t in ttm.items():
            stats.append(dict(case=case, context=context, time_to_mine_s=t, wall_s=round(wall, 3),
                              n=sum(1 for x in r if x["context"] == context)))
        bad = sum(1 for x in r if x["violations"] not in ("", 0))
        print(f"{case:12} {len(r):4} assertions, {sum(1 for x in r if x['unsupported'])} outside "
              f"fragment, {bad} violated on own trace, wall {wall:.2f}s", flush=True)
    with open(RESULTS / f"{args.tag}_candidates.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, FIELDS)
        w.writeheader()
        w.writerows(rows)
    with open(RESULTS / f"{args.tag}_mining.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, ["case", "context", "n", "time_to_mine_s", "wall_s"])
        w.writeheader()
        w.writerows(stats)


if __name__ == "__main__":
    main()
