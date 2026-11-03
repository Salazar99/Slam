"""S3/S4: USM-T synthetic challenges. S3: stimulus-seed variability on And/Next/Eventually (the TCAD 2026
challenges); S4: the NextAnd and Until challenges.

    python s3_usmt.py gen [--challenges ...] [--seeds ...]      # generate + install <Ch>_s<seed> into USM-T
    python s3_usmt.py run [--challenges ...] [--seeds ...] [--miners ...] [--reference]
    python s3_usmt.py collect

USM-T: USMT_ROOT env (default ~/usm-t-main: usm-t origin/main 3c6d0ca, built, plus the seed knob). The stimulus
seed is USMT_SEED (srand in the generated testbench). PYTHONHASHSEED=0 and random.seed(0) in input_generator.py
keep the golden specifications identical across seeds. Gemini (paid API) is dropped from every test.
--reference runs the published tests/tcad2026_case_studies/<Ch>_synthetic.xml once.
Outputs in results/: s3_usmt.{csv,md}, s4_usmt.{csv,md}.
"""
import argparse
import csv
import os
import statistics as st
import subprocess
import time
import xml.etree.ElementTree as ET
from collections import defaultdict
from pathlib import Path

RESULTS = Path(__file__).resolve().parent / "results"   # not from common: it needs tabex, USM-T does not
USMT = Path(os.environ.get("USMT_ROOT", Path.home() / "usm-t-main"))
RUNS = USMT / "thesis_runs"
# Templates as in tool/synthetic_gen/challengeGenerators/generate_<Ch>.sh (trace length 10000).
TEMPLATES = {
    "And": "{formula : G(..&&.. |-> ..&&..), nant : 2, ncon : 2, nspec: 10, overlap : 0}",
    "Next": "{formula : G(..##1.. |-> ..##1..), nant : 2, ncon : 2, nspec: 10, overlap : 10}",
    "Eventually": "{formula : G(..&&.. |-> F ..&&..), nant : 2, ncon : 1, nspec: 10, overlap : 0}",
    "NextAnd": "{formula : G(..#1&.. |-> ..#1&..), nant : 3, ncon : 3, nspec: 10, overlap : 0}",
    "Until": "{formula : G(..&&.. |-> ..&&.. U ..&&..), nant : 2, ncon : 2, nspec : 10, overlap : 0}",
}
CAMPAIGN = {"And": "s3", "Next": "s3", "Eventually": "s3", "NextAnd": "s4", "Until": "s4"}
SEEDS = [1, 2, 3, 4, 5]   # glibc treats srand(0) as srand(1): seed 1 is the generator's original stimulus
METRICS = ["n_mined", "syn_MS", "syn_RS", "sem_MS", "sem_RS", "hyb_MS", "hyb_RS", "SFC", "MC", "time_s"]


def env(seed=0):
    tp = USMT / "tool/third_party"
    e = dict(os.environ, USMT_ROOT=str(USMT), VARIABLES_MAP_FILE="variables_map.txt",
             MINED_SPECIFICATIONS_FILE="mined_specifications.txt", MAX_N_CORES=str(os.cpu_count()),
             PYTHONHASHSEED="0", USMT_SEED=str(seed),
             CMAKE_POLICY_VERSION_MINIMUM="3.5")   # the generated testbench's CMakeLists predates CMake 4
    e["PATH"] = f"{tp}/ltlsynt/bin:{tp}/oss-cad-suite/bin:{tp}/hifsuite_linux_x86_stand_alone:{e['PATH']}"
    e["LD_LIBRARY_PATH"] = f"{e.get('LD_LIBRARY_PATH', '')}:{tp}/hifsuite_linux_x86_stand_alone"
    return e


def tty(cmd, log, **kw):
    """USM-T writes to /dev/tty and runs `docker run -it`: give it a pseudo-terminal, 200 columns wide
    (GoldMine's banner, pyfiglet, crashes on the 0-column default)."""
    with open(log, "w") as f:
        return subprocess.run(["script", "-qec", f"stty cols 200 rows 50; {cmd}", "/dev/null"],
                              stdout=f, stderr=subprocess.STDOUT, **kw).returncode


def without_gemini(src, dst, miners=None):
    """Copy of a USM-T test with the gemini use cases (and their API key) removed, or only `miners` kept."""
    tree = ET.parse(src)
    root = tree.getroot()
    keep = {u.get("id") for u in root.findall("usecase")
            if "gemini" not in u.find("miner").get("name") and (not miners or u.find("miner").get("name") in miners)}
    for parent in [root, *root.findall("test")]:
        for u in parent.findall("usecase"):
            if u.get("id") not in keep:
                parent.remove(u)
    tree.write(dst)


def gen(challenges, seeds):
    wrapper = USMT / "tool/synthetic_gen/testGenerator/wrapper.sh"
    RUNS.mkdir(exist_ok=True)
    for ch in challenges:
        for seed in seeds:
            name = f"{ch}_s{seed}"
            subprocess.run(["bash", wrapper, "x", name, "x", "x", "x", "x", "x", "0", "2", "0"],   # uninstall
                           env=env(), stdout=subprocess.DEVNULL, check=True)
            t0 = time.time()
            rc = tty(f"bash {wrapper} {USMT}/raw_challenges/{name} {name} {name}_top clk '{TEMPLATES[ch]}' rst "
                     f"{name}_top_bench::{name}_top_ 10000 1 0", RUNS / f"gen_{name}.log", env=env(seed), cwd=USMT)
            golden = USMT / f"input/{name}/traces/csv/golden.csv"
            n_faults = len(list((USMT / f"input/{name}/faulty_traces/vcd").glob("fault_*.vcd")))
            print(f"{name}: rc={rc} golden={golden.exists()} faults={n_faults} {time.time() - t0:.0f}s", flush=True)


def run(challenges, seeds, miners, reference):
    RUNS.mkdir(exist_ok=True)
    tests = [(f"{ch}_s{s}", USMT / f"tests/{ch}_s{s}_synthetic.xml") for ch in challenges for s in seeds]
    if reference:
        tests += [(f"tcad2026_{ch}", USMT / f"tests/tcad2026_case_studies/{ch}_synthetic.xml")
                  for ch in challenges if ch in ("And", "Next", "Eventually")]
    for name, src in tests:
        out = RUNS / (f"{name}+{'-'.join(miners)}" if miners else name)   # a miner subset gets its own dump
        out.mkdir(exist_ok=True)
        xml = out / "test.xml"
        without_gemini(src, xml, miners)
        t0 = time.time()
        rc = tty(f"./usm-t --test {xml} --dump-to {out} --continue-on-error", out / "usmt.log",
                 env=env(), cwd=USMT / "tool/build")
        print(f"{name}: rc={rc} {time.time() - t0:.0f}s", flush=True)


def collect():
    rows = []
    for rep in sorted(RUNS.glob("*/summary_report_*.csv")):
        name = rep.parent.name.split("+")[0]
        ch, seed = (name.split("_")[1], "tcad2026") if name.startswith("tcad2026_") else name.rsplit("_s", 1)
        for r in list(csv.reader(open(rep)))[2:]:
            vals = r[1:10] + [r[10].rstrip("s")]
            rows.append(dict(campaign=CAMPAIGN[ch], challenge=ch, seed=seed, usecase=r[0],
                             **{m: v.strip() for m, v in zip(METRICS, vals)}))
    for camp in ("s3", "s4"):
        rs = [r for r in rows if r["campaign"] == camp]
        if not rs:
            continue
        with open(RESULTS / f"{camp}_usmt.csv", "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rs[0]))
            w.writeheader()
            w.writerows(rs)
        by = defaultdict(list)
        for r in rs:
            if r["seed"] != "tcad2026":
                by[(r["challenge"], r["usecase"])].append(r)
        cols = ["n_mined", "sem_MS", "sem_RS", "syn_MS", "hyb_MS", "SFC", "MC", "time_s"]
        out = ["| Challenge | Miner | Seeds | " + " | ".join(cols) + " | Reduction 1-MC/n_mined |",
               "|---|---|---|" + "---|" * (len(cols) + 1)]
        for (ch, uc), g in sorted(by.items()):
            def ms(vals):
                vals = [float(v) for v in vals if v not in ("", "-", "nan")]
                if not vals:
                    return "-"
                return f"{st.mean(vals):.3g} ± {st.stdev(vals):.2g}" if len(vals) > 1 else f"{vals[0]:.3g}"
            red = [1 - float(r["MC"]) / float(r["n_mined"]) for r in g
                   if r["MC"] not in ("", "-") and float(r["n_mined"] or 0) > 0]
            out.append(f"| {ch} | {uc} | {len(g)} | " + " | ".join(ms(r[c] for r in g) for c in cols)
                       + f" | {ms(red)} |")
        ref = [r for r in rs if r["seed"] == "tcad2026"]
        if ref:
            out += ["", "Published TCAD 2026 challenge (one run, reference):", "",
                    "| Challenge | Miner | " + " | ".join(cols) + " |", "|---|---|" + "---|" * len(cols)]
            out += [f"| {r['challenge']} | {r['usecase']} | " + " | ".join(r[c] for c in cols) + " |" for r in ref]
        (RESULTS / f"{camp}_usmt.md").write_text("\n".join(out) + "\n")
        print("\n".join(out))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["gen", "run", "collect"])
    ap.add_argument("--challenges", nargs="+", default=list(TEMPLATES))
    ap.add_argument("--seeds", nargs="*", type=int, default=SEEDS)
    ap.add_argument("--miners", nargs="+", help="miner names to keep (harm texada samples2ltl goldminer)")
    ap.add_argument("--reference", action="store_true")
    a = ap.parse_args()
    if a.cmd == "gen":
        gen(a.challenges, a.seeds)
    elif a.cmd == "run":
        run(a.challenges, a.seeds, a.miners, a.reference)
    else:
        collect()


if __name__ == "__main__":
    main()
