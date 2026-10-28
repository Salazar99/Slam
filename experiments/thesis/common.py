"""Shared helpers of the thesis campaign: run SLAM, load the ground truth, score with G.

The similarity G comes from tabex (TABEX env, default ~/tabex); its helpers are
reused as they are: SLAM -> fragment translation (rq3_mining.mine.to_fragment),
Boolean evaluation on a trace (rq3_mining.quality), the forked time budget
(rq4_llm.analyze.budgeted) and the LLM-answer cleanup (analyze.clean, deepstl.convert).
"""
import csv
import json
import os
import re
import subprocess
import sys
import tempfile
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from fractions import Fraction
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
RESULTS = HERE / "results"
SLAM = Path(os.environ.get("SLAM_BIN", HERE / "bin" / "slam"))
TABEX = Path(os.environ.get("TABEX", Path.home() / "tabex"))
sys.path[:0] = [str(TABEX), str(TABEX / "experiments" / "rq4_llm")]

from similarity.intervals import UnsupportedFormula  # noqa: E402
from similarity.reference_semantics import constants, parse, variables  # noqa: E402
from fast_similarity.engine import one_way, regions  # noqa: E402
from experiments.rq3_mining.mine import to_fragment  # noqa: E402,F401
from experiments.rq3_mining.quality import antecedent, column, evaluate, read_trace  # noqa: E402,F401
from experiments.rq3_mining.prune import TAUS  # noqa: E402,F401
import experiments.rq4_llm.analyze as _analyze  # noqa: E402
from experiments.rq4_llm.analyze import budgeted, clean  # noqa: E402,F401
from deepstl import convert  # noqa: E402,F401

TESTS = REPO / "tests"
# case: (config, trace file or directory of traces). FDL 2024 configs as of 38ff97a,
# traces as in each case's run.sh of that commit.
CASES = {
    "WaterTanks": (HERE / "configs/fdl/WaterTanks.xml", TESTS / "waterTanksCase/WT_Trace_Date.csv"),
    "Gearbox": (HERE / "configs/fdl/Gearbox.xml", TESTS / "gearboxCase/trace_gearbox_Date.csv"),
    "Heater": (HERE / "configs/fdl/Heater.xml", TESTS / "HeaterCase/HT_trace.csv"),
}
for _d in sorted((TESTS / "simulink").glob("*/config.xml")):   # Simulink benchmarks, once generated
    CASES[_d.parent.name] = (_d, _d.parent / "traces")


def run_slam(conf, trace, extra=(), cwd=None, timeout=None):
    """SLAM in a scratch dir. Returns ({context: [assertion, ...]}, {context: time to mine s}, wall s)."""
    with tempfile.TemporaryDirectory() as tmp:
        src = ["--csv-dir" if Path(trace).is_dir() else "--csv", str(trace)]
        cmd = [str(SLAM), *src, "--conf", str(conf), "--dump-to", tmp, "--dump-stat",
               "--divide-stat", "--silent", *map(str, extra)]
        start = time.perf_counter()
        subprocess.run(cmd, cwd=cwd or tmp, check=True, timeout=timeout,
                       stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        wall = time.perf_counter() - start
        ass = {p.name[:-len("_ass.txt")]: [l.strip() for l in p.read_text().splitlines() if l.strip()]
               for p in Path(tmp).glob("*_ass.txt")}
        ttm = {}
        with open(Path(cwd or tmp) / "stat_out.csv") as fh:
            for row in csv.reader(fh, delimiter=";"):
                if row and row[0] != "Name":
                    ttm[row[0].strip()] = float(row[2])
    return ass, ttm, wall


def traces_of(case):
    path = CASES[case][1]
    files = sorted(path.glob("*.csv")) if path.is_dir() else [path]
    return [read_trace(f) for f in files]


def load_truth(path=HERE / "ground_truth.csv"):
    with open(path) as fh:
        return list(csv.DictReader(fh))


def domain(case, formulas):
    """D for scoring against a requirement: observed |value| of the signals of `formulas`
    (derivative columns included) and their constants, + 1. Called with the requirement
    alone, so every candidate (SLAM or LLM) of that requirement is scored on one domain;
    a case-wide D would be dominated by the widest signal (Gearbox theta: 1486)."""
    names = {v for f in formulas for v in variables(parse(f))}
    hi = Fraction(0)
    for tr in traces_of(case):
        for v in names:
            m = re.fullmatch(r"(\w+)_d(\d+)", v)
            if v in tr or m:
                x = column(tr, v)
                x = x if v in tr else x[:-int(m.group(2))]   # column() pads the last k with v(t)
                hi = max(hi, Fraction(float(np.abs(x).max())).limit_denominator(1000))
    for f in formulas:
        hi = max([hi, *(abs(c) for c in constants(parse(f)))])
    return Fraction(int(hi) + 1)


def _pair_D(a, b, D):
    """D grows only if a candidate has a constant outside the case domain (reported)."""
    hi = max([Fraction(0), *(abs(c) for f in (a, b) for c in constants(parse(f)))])
    return D if hi < D else Fraction(int(hi) + 1)


# ---- G with a persistent cache -------------------------------------------------------------
CACHE = RESULTS / "g_cache.jsonl"
_cache = {}
# Per-pair time budget (s) of tabex's forked harness; timeouts recorded under a smaller
# budget are retried when it is raised (G_BUDGET_S=600 python score.py ...).
BUDGET_S = _analyze.BUDGET_S = int(os.environ.get("G_BUDGET_S", 120))


def _key(truth, cand, D):
    return f"{truth}\t{cand}\t{D}"


def _load_cache():
    if not _cache and CACHE.exists():
        for line in CACHE.read_text().splitlines():
            r = json.loads(line)
            _cache[_key(r["truth"], r["cand"], r["D"])] = r


def _pair(job):
    truth, cand, D = job
    start = time.perf_counter()
    r1, r2, _, _ = regions(truth, cand)
    fw, bw = one_way(r1, r2, D), one_way(r2, r1, D)
    return {"truth": truth, "cand": cand, "D": str(D), "fw": fw, "bw": bw, "G": (fw + bw) / 2,
            "secs": time.perf_counter() - start}


def scores(pairs, D, workers=int(os.environ.get("G_WORKERS", 30))):
    """{(truth, cand): record} with G, fw = truth->cand one-way, bw = cand->truth; G None on timeout."""
    _load_cache()
    jobs = {(t, c): (t, c, _pair_D(t, c, D)) for t, c in pairs}
    todo = [j for j in set(jobs.values())
            if (rec := _cache.get(_key(*j))) is None
            or rec["G"] is None and (rec.get("budget", 0) < BUDGET_S or rec.get("status") != "timeout")]
    if todo:
        RESULTS.mkdir(exist_ok=True)
        def run(j):
            start = time.perf_counter()
            fail = lambda j: {"truth": j[0], "cand": j[1], "D": str(j[2]), "fw": None, "bw": None,  # noqa: E731
                              "G": None, "budget": BUDGET_S, "secs": time.perf_counter() - start,
                              "status": "timeout" if time.perf_counter() - start >= BUDGET_S else "crash"}
            return budgeted(_pair, j, fail)

        # The scorer recurses over the formula tree; children forked from pool threads keep
        # the thread's fixed stack, so give threads a large one (deep windows crash at 8 MB).
        threading.stack_size(512 << 20)
        with ThreadPoolExecutor(workers) as pool, open(CACHE, "a") as fh:
            for rec in pool.map(run, todo):
                _cache[_key(rec["truth"], rec["cand"], rec["D"])] = rec
                fh.write(json.dumps(rec) + "\n")
                fh.flush()
    return {(t, c): _cache[_key(*j)] for (t, c), j in jobs.items()}


def valid(tree, n):
    """Instants where `tree` is decided on an n-sample trace: its horizon must fit, and an
    x_dk signal is undefined on the last k samples (tabex column() pads them with x)."""
    ks = [int(m.group(1)) for v in variables(tree) if (m := re.fullmatch(r"\w+_d(\d+)", v))]
    return max(n - tree.horizon() - max(ks, default=0), 0)


def check_on_traces(formula, case):
    """(violations, triggers) of an implication body over all instants where its horizon fits.
    Triggers stay 0 if the formula is not a top-level implication (e.g. `G[1,2](p -> q)`)."""
    viol = trig = 0
    tree = parse(formula)
    ant = None
    if "->" in formula:
        try:
            ant, _ = antecedent(f"G({formula})")
        except ValueError:      # '->' only nested under a temporal operator
            pass
    for tr in traces_of(case):
        n = len(next(iter(tr.values())))
        m = valid(tree, n)
        viol += int((~evaluate(tree, tr, n)[:m]).sum())
        if ant is not None:
            trig += int(evaluate(parse(ant), tr, n)[:m].sum())
    return viol, trig
