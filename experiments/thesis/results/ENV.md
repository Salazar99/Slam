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
