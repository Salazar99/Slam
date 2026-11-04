"""S3/S4: USM-T synthetic challenges. S3: stimulus-seed variability on And/Next/Eventually (the TODAES 2026
challenges); S4: the NextAnd and Until challenges.

    python s3_usmt.py gen [--challenges ...] [--seeds ...]      # generate + install <Ch>_s<seed> into USM-T
    python s3_usmt.py run [--challenges ...] [--seeds ...] [--miners ...] [--reference]
    python s3_usmt.py collect

USM-T: USMT_ROOT env (default ~/usm-t-todaes: usm-t main 28dff1c, the code of the TODAES submission, built with
golden_check, plus the seed knob). The stimulus seed is USMT_SEED (srand in the generated testbench).
PYTHONHASHSEED=0 and random.seed(0) in input_generator.py keep the golden specifications identical across seeds.
Generation aborts if a golden specification does not hold or is never activated (golden_check).
Gemini (paid API) is dropped from every test. Generated tests get the published case study's hand edits
(Texada caps, HARM dtLimits on And, Samples2LTL trim on And/Next); NextAnd/Until keep the generator's defaults.
--reference runs the published tests/todaes2026_case_studies/<Ch>_synthetic.xml once.
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
USMT = Path(os.environ.get("USMT_ROOT", Path.home() / "usm-t-todaes"))
RUNS = USMT / "thesis_runs"
# Templates as in tool/synthetic_gen/challengeGenerators/generate_<Ch>.sh (trace length 10000).
TEMPLATES = {
    "And": "{formula : G(..&&.. |-> ..&&..), nant : 2, ncon : 2, nspec: 10, overlap : 0}",
    "Next": "{formula : G(..##1.. |-> ..##1..), nant : 2, ncon : 2, nspec: 10, overlap : 10}",
    "Eventually": "{formula : G(..&&.. |-> F ..&&..), nant : 2, ncon : 1, nspec: 10, overlap : 0}",
    "NextAnd": "{formula : G(..#1&.. |-> ..#1&..), nant : 3, ncon : 3, nspec: 10, overlap : 0}",
    "Until": "{formula : G(..&&.. |-> ..&&.. U ..&&..), nant : 2, ncon : 2, nspec : 10, overlap : 0}",
}
# usm-t flags of scripts/run_todaes2026_experiments/run_case_study.sh: Eventually is evaluated on finite-trace
# semantics with at most 10000 mined specifications. Until (not published) gets the same, as the other unbounded operator.
FLAGS = {"Eventually": "--max-mined 10000 --ltlf", "Until": "--max-mined 10000 --ltlf"}
# Texada time caps (s) of the published configurations (miners/tools/texada/configurations/todaes2026): And 120,
# Eventually 600, Next none. NextAnd and Until (not published) get 600.
TEXADA_CAP = {"And": 120, "Eventually": 600, "NextAnd": 600, "Until": 600}
# Other hand edits of the published case study over the generator's output: HARM's And templates use
# dtLimits="3A,0.05E" (generator: 0E); Samples2LTL reads only the first 100 rows of the trace on And and Next.
HARM_DT = {"And": "3A,0.05E"}
S2L_TRIM = {"And": "100", "Next": "100"}
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


def without_gemini(src, dst, miners=None, trim=None, tag=""):
    """Copy of a USM-T test with the gemini use cases (and their API key) removed, or only `miners` kept;
    `trim` sets Samples2LTL's trim_csv_to; `tag` is appended to the use-case ids (parallel runs: USM-T names
    run folders <id>_<minute> and wipes an existing one)."""
    # 28dff1c's default config has GEMINI_API_KEY="<key>", not well-formed XML; the use case is dropped anyway
    root = ET.fromstring(Path(src).read_text().replace('"<key>"', '""'))
    tree = ET.ElementTree(root)
    keep = {u.get("id") for u in root.findall("usecase")
            if "gemini" not in u.find("miner").get("name") and (not miners or u.find("miner").get("name") in miners)}
    for parent in [root, *root.findall("test")]:
        for u in parent.findall("usecase"):
            if u.get("id") not in keep:
                parent.remove(u)
            else:
                if trim and parent is root and u.find("miner").get("name") == "samples2ltl":   # <test> holds id refs
                    u.find("input").set("trim_csv_to", trim)
                u.set("id", u.get("id") + tag)
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
            texada = USMT / f"miners/tools/texada/configurations/{name}/run_miner.sh"
            if ch in TEXADA_CAP and texada.exists():
                texada.write_text(texada.read_text().replace(
                    "./texada ", f"timeout --foreground {TEXADA_CAP[ch]}s ./texada "))
            if ch in HARM_DT:
                harm_dt(name, HARM_DT[ch])
            print(f"{name}: rc={rc} faults={n_faults(name)} golden_check={golden_check(name)} "
                  f"{time.time() - t0:.0f}s", flush=True)


def harm_dt(name, dt):
    cfg = USMT / f"miners/tools/harm/configurations/{name}/config.xml"
    cfg.write_text(cfg.read_text().replace('dtLimits="3A,0E"', f'dtLimits="{dt}"'))


def n_faults(name):
    return len(list((USMT / f"input/{name}/faulty_traces/vcd").glob("fault_*.vcd")))


def golden_check(name):
    """'k/n hold+active, min activations a' from the generator's golden_check report, or 'missing'."""
    rep = USMT / f"input/{name}/expected/golden_check_report.txt"
    if not rep.exists():
        return "missing"
    rows = list(csv.DictReader(open(rep), delimiter=";"))
    ok = [r for r in rows if r["holds"] == "yes" and int(r["activations"]) > 0]
    return f"{len(ok)}/{len(rows)} hold+active, min activations {min(int(r['activations']) for r in rows)}"


def run(challenges, seeds, miners, reference, tag=""):
    RUNS.mkdir(exist_ok=True)
    tests = [(f"{ch}_s{s}", USMT / f"tests/{ch}_s{s}_synthetic.xml") for ch in challenges for s in seeds]
    if reference:
        tests += [(f"todaes2026_{ch}", USMT / f"tests/todaes2026_case_studies/{ch}_synthetic.xml")
                  for ch in challenges if ch in ("And", "Next", "Eventually")]
    for name, src in tests:
        out = RUNS / (f"{name}+{'-'.join(miners)}" if miners else name)   # a miner subset gets its own dump
        out.mkdir(exist_ok=True)
        xml = out / "test.xml"
        ch = name.split("_")[1] if name.startswith("todaes2026_") else name.rsplit("_s", 1)[0]
        # the published tests already carry their trim
        without_gemini(src, xml, miners, None if name.startswith("todaes2026_") else S2L_TRIM.get(ch), tag)
        t0 = time.time()
        flags = FLAGS.get(ch, "")
        rc = tty(f"./usm-t {flags} --test {xml} --dump-to {out} --continue-on-error", out / "usmt.log",
                 env=env(), cwd=USMT / "tool/build")
        print(f"{name}: rc={rc} {time.time() - t0:.0f}s", flush=True)


def collect():
    rows = {}
    # sorted: a miner-subset rerun (<name>+<miners>) comes after <name> and replaces its rows
    for rep in sorted(RUNS.glob("*/summary_report_*.csv")):
        name = rep.parent.name.split("+")[0]
        ch, seed = (name.split("_")[1], "todaes2026") if name.startswith("todaes2026_") else name.rsplit("_s", 1)
        inp = f"todaes2026/{ch}" if seed == "todaes2026" else name
        for r in list(csv.reader(open(rep)))[2:]:
            vals = r[1:10] + [r[10].rstrip("s")]
            uc = r[0].split("__")[0]   # drop a run's --tag
            rows[name, uc] = dict(campaign=CAMPAIGN[ch], challenge=ch, seed=seed, usecase=uc,
                                    **{m: v.strip() for m, v in zip(METRICS, vals)}, n_faults=n_faults(inp),
                                    dump=rep.parent.name)
    rows = list(rows.values())
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
            if r["seed"] != "todaes2026":
                by[(r["challenge"], r["usecase"])].append(r)
        # the radar axes of the paper's Fig. 5 (hybrid MS, RS, SFC, time) first
        cols = ["hyb_MS", "hyb_RS", "SFC", "time_s", "n_mined", "MC", "sem_MS", "syn_MS", "n_faults"]
        out = ["Mean ± std [min–max] over the seeds.", "",
               "| Challenge | Miner | Seeds | " + " | ".join(cols) + " |", "|---|---|---|" + "---|" * len(cols)]
        for (ch, uc), g in sorted(by.items()):
            def ms(vals):
                vals = [float(v) for v in vals if v not in ("", "-", "nan")]
                if not vals:
                    return "-"
                if len(vals) == 1:
                    return f"{vals[0]:.3g}"
                return f"{st.mean(vals):.3g} ± {st.stdev(vals):.2g} [{min(vals):.3g}–{max(vals):.3g}]"
            out.append(f"| {ch} | {uc} | {len(g)} | " + " | ".join(ms(r[c] for r in g) for c in cols) + " |")
        ref = [r for r in rs if r["seed"] == "todaes2026"]
        if ref:
            out += ["", "Published TODAES challenge (input/todaes2026, one run, reference):", "",
                    "| Challenge | Miner | " + " | ".join(cols) + " |", "|---|---|" + "---|" * len(cols)]
            out += [f"| {r['challenge']} | {r['usecase']} | " + " | ".join(str(r[c]) for c in cols) + " |" for r in ref]
        (RESULTS / f"{camp}_usmt.md").write_text("\n".join(out) + "\n")
        print("\n".join(out))


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("cmd", choices=["gen", "run", "collect"])
    ap.add_argument("--challenges", nargs="+", default=list(TEMPLATES))
    ap.add_argument("--seeds", nargs="*", type=int, default=SEEDS)
    ap.add_argument("--miners", nargs="+", help="miner names to keep (harm texada samples2ltl goldminer)")
    ap.add_argument("--reference", action="store_true")
    ap.add_argument("--tag", default="", help="suffix for the use-case ids, '__<x>' (parallel runs)")
    a = ap.parse_args()
    if a.cmd == "gen":
        gen(a.challenges, a.seeds)
    elif a.cmd == "run":
        run(a.challenges, a.seeds, a.miners, a.reference, a.tag)
    else:
        collect()


if __name__ == "__main__":
    main()
