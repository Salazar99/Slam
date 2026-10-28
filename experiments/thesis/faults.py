"""S2 optional: fault detection of the mined assertions (3-5 faults per FDL design).

    python faults.py [--candidates results/s1_candidates.csv results/s6_candidates.csv]

FDL designs: sensor faults applied to the nominal trace from instant T0 on (stuck-at, offset,
drift, noise), plus the re-simulated water-tank trace with the valve stuck open shipped with
SLAM (tests/waterTanksCase/faulty); actuator faults would need the ARIADNE models, which are
not available. fuelsys: the model's four sensor failures, re-simulated in Simulink with the
same inputs as the nominal runs (tests/simulink/fuelsys/faulty/<switch>). A fault is detected by a candidate set when at least one of its assertions is
violated on the faulty trace; the ground truth is scored the same way as a reference.
Only candidates that hold on the nominal traces count (the others would raise false alarms).

Output: results/faults.{csv,md}
"""
import argparse
import csv
from collections import defaultdict

import numpy as np

from common import CASES, RESULTS, TESTS, evaluate, load_truth, parse, read_trace, traces_of, valid

T0 = 300
SEED = 7


def mutate(trace, sig, kind):
    tr = {k: v.copy() for k, v in trace.items()}
    x = tr[sig]
    span = float(x.max() - x.min()) or 1.0
    if kind == "stuck":
        x[T0:] = x[T0]
    elif kind == "offset":
        x[T0:] += 0.1 * span
    elif kind == "drift":
        x[T0:] += 0.3 * span * np.arange(len(x) - T0) / (len(x) - T0)
    elif kind == "noise":
        x[T0:] += np.random.default_rng(SEED).normal(0, 0.05 * span, len(x) - T0)
    return tr


FAULTS = {   # case: [(fault id, signal, kind)]
    "WaterTanks": [("z-stuck", "z", "stuck"), ("z-offset", "z", "offset"), ("d-drift", "d", "drift"),
                   ("z-noise", "z", "noise"), ("valve-stuck-open", None, "resim")],
    "Gearbox": [("omega-stuck", "omega", "stuck"), ("omega-offset", "omega", "offset"),
                ("theta-stuck", "theta", "stuck"), ("omega-noise", "omega", "noise")],
    "Heater": [("T-stuck", "T", "stuck"), ("T-offset", "T", "offset"), ("T-drift", "T", "drift"),
               ("T-noise", "T", "noise")],
    "fuelsys": [(f"{s}-failure", s, "resim") for s in ("ego_sw", "map_sw", "speed_sw", "throttle_sw")],
}
RESIM = {"valve-stuck-open": TESTS / "waterTanksCase/faulty",
         **{f"{s}-failure": TESTS / f"simulink/fuelsys/faulty/{s}" for s in ("ego_sw", "map_sw", "speed_sw", "throttle_sw")}}


def faulty_traces(case):
    """(fault id, [faulty traces]); a mutation is applied to every nominal trace of the case."""
    nominal = traces_of(case)
    for fid, sig, kind in FAULTS[case]:
        if kind == "resim":
            yield fid, [read_trace(f) for f in sorted(RESIM[fid].glob("*.csv"))]
        else:
            yield fid, [mutate(tr, sig, kind) for tr in nominal]


def violated(formula, traces):
    tree = parse(formula)
    for tr in traces:
        n = len(next(iter(tr.values())))
        if (~evaluate(tree, tr, n)[:valid(tree, n)]).any():
            return True
    return False


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--candidates", nargs="*", default=[str(RESULTS / "s1_candidates.csv")])
    args = ap.parse_args()
    sets = defaultdict(list)    # (case, source, sample) -> formulas
    for path in args.candidates:
        for c in csv.DictReader(open(path)):
            # only assertions that hold on the nominal traces: a violated one is a false alarm.
            # '-trace' filtered this way is the '-trace-checked' set, so it is skipped.
            if c["case"] not in FAULTS or c["source"].endswith("-trace"):
                continue
            group = sets[(c["case"], c["source"], c["sample"])]     # an empty set detects nothing
            if c["formula"] and c["violations"] == "0":
                group.append(c["formula"])
    for r in load_truth():
        if r["case"] in FAULTS and r["encodable"] == "yes":
            sets[(r["case"], "ground-truth", "0")].append(r["stl"])
    rows = []
    for case in (c for c in FAULTS if c in CASES):
        for fid, tr in faulty_traces(case):
            for (c, source, sample), formulas in sorted(sets.items()):
                if c != case:
                    continue
                n_viol = sum(violated(f, tr) for f in formulas)
                rows.append(dict(case=case, fault=fid, source=source, sample=sample, n_ass=len(formulas),
                                 n_violated=n_viol, detected=int(n_viol > 0)))
    with open(RESULTS / "faults.csv", "w", newline="") as fh:
        w = csv.DictWriter(fh, list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    # per (case, source): detected faults, mean over samples
    agg = defaultdict(lambda: defaultdict(list))
    for r in rows:
        agg[(r["case"], r["source"])][r["sample"]].append(r["detected"])
    md = ["| Design | Source | Faults | Detected (mean over samples) |", "|---|---|---|---|"]
    for (case, source), per in sorted(agg.items()):
        det = [sum(v) for v in per.values()]
        md.append(f"| {case} | {source} | {len(FAULTS[case])} | {np.mean(det):.1f}"
                  + (f" ± {np.std(det, ddof=1):.1f}" if len(det) > 1 else "") + " |")
    (RESULTS / "faults.md").write_text("\n".join(md) + "\n")
    print("\n".join(md))


if __name__ == "__main__":
    main()
