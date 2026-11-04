# Environment

- SLAM binary: `experiments/thesis/bin/slam`, copy of `build/slam` built from develop `b1149a4` (Release).
  sha256 `e898f944142fa9a763135304971d6b4eb63b29af1fb75491dbdb8044efcbc259`.
  Links `third_party/antlr4` 4.13.2 and `third_party/z3`.
- Experiment branch: `exp/thesis-campaign` from develop `e195c41`.
- FDL 2024 configs: `git show 38ff97a:<cfg>` (all contexts active).
- G engine: tabex `09d6d17` (`fast_similarity`).
- Python 3.12.3 (`.venv` with system site packages; numpy 1.26.4, matplotlib 3.6.3).
- CPU: Intel Core i9-14900KF, 32 logical cores, 15 GB RAM (WSL2).
- MATLAB R2026b (26.2.0.3386108) with Simulink and Stateflow, on the Windows host, driven from WSL with
  `matlab.exe -batch`. Simulink traces: `tests/simulink/<model>/gen_<model>.m` (staged in `C:\Users\danni\slam_sim`).
- S6 LLMs: Ollama 0.40.12 (user space, `~/ollama`; flash attention, q8_0 KV cache), on an NVIDIA RTX 3060 12 GB
  (driver 621.01; GPU shared with a Windows process). Models (Q4_K_M):
  `qwen2.5:7b-instruct` (digest 845dbda0ea48), `qwen2.5:14b-instruct` (digest 7cdf5a0187d5).

## S3/S4 and the Table I stage counts (second machine, 2026-11-02)
- CPU: Intel Core Ultra 5 225U, 14 logical cores, 15 GB RAM (WSL2); gcc 11.4.0, CMake 4.4.5.
- SLAM: the frozen binary is not on this machine. `b1149a4` rebuilt in Release (sha256 `64841c95497bb844390459e835edbfb126850f15059da2c6efd74d0389b3df5b`, needs `-DCMAKE_POLICY_VERSION_MINIMUM=3.5` under CMake 4).
  - It reproduces the FDL counts exactly at `--min-final 0.90` (218 / 40 / 17).
  - It does not reproduce the Simulink counts: autotrans 12 vs 11 and fuelsys 18 vs 12, deterministic over 3 runs. The S1/S2/S6 Simulink results are therefore not regenerated with it; only the FDL Table I stage counts use it.
- tabex `09d6d17` (worktree `~/tabex-09d6d17`, `TABEX=` env).
- Docker Engine 29.9.2. Images (digests):
  - `samger/harm` `sha256:b35d92b0ca91…`
  - `samger/texada` `sha256:06406922…`
  - `samger/samples2ltl` `sha256:066e7939…`
  - `samger/goldminer2` `sha256:4c8d76a6…`
- USM-T: `~/usm-t-main`, a worktree of usm-t `origin/main` `3c6d0ca` on a local branch `exp/thesis-seeds` (not pushed). Built in Release with `-DCMAKE_POLICY_VERSION_MINIMUM=3.5`.
  - `third_party` is linked to the installs of `~/usm-t` (`syntgen_develop` `3a7d422`), plus radarChartPlotter `c64d38f`.
  - Seed knob (2 lines, uncommitted in the worktrees; saved as `experiments/thesis/usmt_seed.patch`, applies to both 3c6d0ca and 28dff1c):
    - `hif_utils.py:334` writes `srand(<USMT_SEED>)` in the generated testbench;
    - `input_generator.py` calls `random.seed(0)`.
  - Generation runs with `PYTHONHASHSEED=0` and `CMAKE_POLICY_VERSION_MINIMUM=3.5`.

## S3/S4 on USM-T 28dff1c, the TODAES submission's code (main machine, 2026-11-03/04)
- **Supersedes the `3c6d0ca` run below** (kept in `~/usm-t-main/thesis_runs` and `s3_run_3c6d0ca.log`, not used). On `3c6d0ca` the overlapping Next design drove shared outputs from several submodules (7/10 golden specifications failed); `28dff1c` ORs them and checks the golden specifications at generation.
- USM-T: worktree `~/usm-t-todaes` at `28dff1c` (local branch `exp/thesis-seeds-todaes`, not pushed), with the same 2-line seed knob. `tool/third_party` is a symlink to `~/usm-t/tool/third_party` (the tracked one is moved to `third_party.tracked`). Built as below, plus `make golden_check`.
- Inputs: `input/<Ch>_s<seed>`, seeds 1–5. All 25 pass `golden_check` (10/10 hold and are activated). Designs and golden specifications are identical across seeds (md5); traces differ.
- **Hand edits of the published case study** (`tests/todaes2026_case_studies`, configs `*/configurations/todaes2026`), copied by `s3_usmt.py` onto the generated tests: Texada caps (120 s And, 600 s Eventually, none Next); HARM `dtLimits="3A,0.05E"` on And (generator: `0E`); Samples2LTL `trim_csv_to="100"` on And and Next; `--max-mined 10000 --ltlf` on Eventually. Every other config and test setting matches the published ones. NextAnd and Until have no published test: generator defaults, Texada 600 s, and the Eventually flags on Until.
  - The HARM/Samples2LTL edits were found after the main run had done And and Next; those two miners were rerun alone on And/Next (`<name>+<miners>` dumps, which `collect` prefers).
- **Order:** `run --reference` ran sequentially until Until seed 4 (`s3_run.log`). The 3 published tests then ran alongside it (`s3_ref.log`; their use-case ids, `harm` vs `harm_default`, keep the minute-stamped run folders apart). The rest ran as three parallel lanes with distinct `--tag` suffixes: Until seed 5 (`s3_lane1.log`), the HARM/Samples2LTL reruns on And (`s3_lane2.log`), and the Samples2LTL reruns on Next (`s3_lane3.log`).
- Run times depend on the host: on Next seeds 3–5 and NextAnd seed 5 all miners slowed down together by 1.3–2.7×.

## S3/S4 rerun on the main machine on 3c6d0ca (2026-11-03, superseded)
- The results of the second machine's S3/S4 runs were not uploaded, so S3/S4 were rerun here (i9-14900KF, WSL2).
- Docker Engine 29.1.3 (Ubuntu `docker.io`). The image digests match the second machine's:
  - `samger/harm` `sha256:b35d92b0ca91059174c5a7627688e7276bfdcd154b9e0d7f4d165f83098712eb`
  - `samger/texada` `sha256:064069220f0e7ffe3123594b7c3f46a8bd114f064136ecc41986c38fb91ad2b6`
  - `samger/samples2ltl` `sha256:066e79398a668edbe4e958f9f3712e554a320061e13d79ea63e5a667b7a2a7d6`
  - `samger/goldminer2` `sha256:4c8d76a64f170aa91450ffafee9f9784cd2387a9e2e8f87b9e96f28064b4dc10`
- USM-T: worktree `~/usm-t-main` at `3c6d0ca` (local branch `exp/thesis-seeds`, not pushed), with the same 2-line seed knob as the second machine. `tool/third_party` is a symlink to `~/usm-t/tool/third_party`.
  - Built in Release with CMake 4.3.2 and `-DCMAKE_POLICY_VERSION_MINIMUM=3.5`.
  - The ANTLR4 runtime headers come from SLAM's `third_party/antlr4` (same 4.13.2 runtime), via `-DANTRL4_INCLUDE_PATH` and `-DANTRL4_LIB_PATH`; the install in `~/usm-t` has the library but no headers.
  - `vcd2csv` is built explicitly (`make vcd2csv`); the generator needs it for the CSV traces.
  - radarChartPlotter is not installed. USM-T stops with an error after writing the summary report, which is the only file `collect` reads, so no radar charts are drawn.
- **Texada time caps, as in the published TODAES 2026 configs.** The generator writes Texada configs without caps. The published ones wrap each call in `timeout --foreground`: 120 s for And, 600 s for Eventually, none for Next. The same caps were applied to the generated And/Eventually configs, which are then byte-identical to the published ones. NextAnd and Until (S4) have no published config, and use 600 s (the larger published cap). An uncapped Texada ran for more than 55 min, at 5.4 GB, on one And template.
- The golden specifications are identical across the 5 seeds of each challenge (same md5), while the golden traces differ (the seed knob works).
