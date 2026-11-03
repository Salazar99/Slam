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
  - Seed knob (uncommitted, 2 lines):
    - `hif_utils.py:334` writes `srand(<USMT_SEED>)` in the generated testbench;
    - `input_generator.py` calls `random.seed(0)`.
  - Generation runs with `PYTHONHASHSEED=0` and `CMAKE_POLICY_VERSION_MINIMUM=3.5`.
