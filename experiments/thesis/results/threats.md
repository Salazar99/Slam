# Threats to validity (campaign notes for Ch. 5, 6, 8)

## Dropped campaigns
- **S3 (USM-T seed variability) and S4 (NextAnd/Until challenges) were not run.**
  - The miners run as Docker images, and this machine has no Docker.
  - The original And/Next/Eventually challenge inputs are not on disk.
  - The stimulus seed is hard-coded: `srand(0)` in `tool/synthetic_gen/testGenerator/input_generator/hif_utils.py:334`. In addition, the input order depends on `PYTHONHASHSEED` and the overlap step uses an unseeded `random`, so regenerating a challenge also changes its golden specifications.

  Keep the Sec. 8.1 argument ("long traces, golden specs checked to hold and be non-vacuous") and state the single run as a limitation. Soften the ">99%" minimisation claim in 7.2, because S3 cannot support it.

- **S5 (TeLEx baseline) was dropped.** TeLEx (Jha et al., FMSD 2019; github.com/susmitjha/TeLEX, last commit 89cd49c, 2017-05-12) cannot run on a current toolchain without extensive changes. The source was inspected but never executed.
  - **Python 2.7 only.** The supported environment (`telex.yml`) pins Python 2.7.13, numpy 1.11.2, pandas 0.19.2, scipy 0.18.1 and parsimonious 0.7.0. All of these are years past end of life; Python 2.7 itself ended in January 2020.
  - **Python 3 fails at import.** `telex/synth.py` contains Python 2 `print` statements (6 of them), which are a syntax error in Python 3. It also does `from time import clock`, and `time.clock` was removed in Python 3.8. The import would therefore fail even after an automatic 2to3 conversion.
  - **Running it would need a port, not a configuration change.** That means rewriting the synthesis module and re-validating the grammar visitor against the current parsimonious API and the optimizer calls against current scipy (`minimize`, `differential_evolution`). Every number it then produced would come from our port, not from the published tool.
  - **Its input and method also differ from SLAM's:**
    - Traces must start with a `time` column, which is a reserved token in SLAM's CSV grammar, so every benchmark would need separate copies.
    - TeLEx only fits the parameters (`a?`, `b?` with ranges) of a template the user writes. It does not mine the formula structure. A per-requirement template would hand it the ground-truth shape, so the S1 comparison would be unfair in its favour.

  No other external STL miner was attempted within the campaign. The LLM baseline (S6) is the only quantitative external reference.

## SLAM (Ch. 5)
- **No quantitative comparison with other STL miners.** The LLM baseline (S6) is the only external reference (TeLEx, S5, was dropped: see above).
- **Few, small benchmarks.** These are the 3 FDL designs (1001 samples each) plus the Simulink application examples (if completed). Every case is mined and scored on the same trace, with no held-out traces.
- **The ground truth was formalized a posteriori.** The informal requirements of the FDL 2024 paper survive only as the SLAM config contexts (`38ff97a`, one per requirement). Requirement text and STL were reconstructed from the configs, the hybrid-automaton report and the traces, then reviewed by the author. Every ground-truth formula is checked to hold on its nominal trace and to be non-vacuously triggered (`score.py --check-truth`).
- **Table I counts are not reproduced exactly.** Same configs, traces and mining code (only the Spot removal differs between `38ff97a` and `b1149a4`), at `--min-final 0.90`:

  | | Paper | Now |
  |---|---|---|
  | Water tanks | 46 | 218 |
  | Gearbox | 34 | 40 |
  | Thermostat | 25 | 17 |

  The paper-time configs or traces probably differed. With th×10, the Thermostat count is 25.
- **Sample-based time.** One row is one time unit. Mined windows count samples, not seconds.
- **The derivative at the end of the trace.** SLAM's `@(x,k)` returns x itself on the last k samples. The G evaluation ignores those instants (it checks only the instants where the horizon fits).

## STL similarity G (Ch. 6) as the S1 metric
- **Restricted fragment.** Atoms compare one signal with one constant, and only bounded temporal operators are allowed. All 14 FDL requirements were encodable. `@(x,1)` is encoded as a fresh signal `x_d1`, so G treats it as an independent signal, not as a function of x.
- **G is strict on temporal structure.** For example, G(`T>=16.2 -> Status==0`, `T>=16.2 -> F[0,5] Status==0`) = 0.154, even though the second formula is implied by the first. Coverage at G = 1 is therefore a very demanding criterion. Report the one-way scores and the G ≥ τ coverage alongside it.
- **The domain D is one per requirement**, from the observed range of its signals. A single D per design would be dominated by the widest signal (theta up to 1486 in Gearbox).
- **One D per formula pair.** tabex uses a single domain bound D for all signals. When the signals have different ranges (rpm up to 4755 vs speed up to 50 in AT6), comparisons on the narrow signal become coarse.
- **Exponential worst case.** Every pair finished within the 600 s budget, after the forked scorer's stack size was raised.

## LLM baseline (S6)
- Two free local open-weight models (`qwen2.5:7b-instruct`, the Ch. 6 RQ4 model, and `qwen2.5:14b-instruct`) ran through Ollama on an RTX 3060, with 5 samples per prompt (temperature 0.8, seeds 1..5) and one prompt per mode. Results do not generalize to larger or proprietary LLMs, or to LLM miners at large. Paid APIs were not used.
- Mode *req* reads the requirement text, which is an unfair advantage. Mode *trace* sees the same hints SLAM gets, plus a short description of the system and an excerpt of one trace, while SLAM mines all traces. The excerpt is the longest prefix of the first trace that fits a 20480-token context with 1500 tokens left for the answer: the whole run for Heater, absbrake, autotrans and fuelsys; 545/1000 rows for WaterTanks, 663/1001 for Gearbox, 889/2881 for househeat.
- Ollama cuts a prompt longer than `num_ctx` to `num_ctx/2` without an error, keeping only the first 4 tokens. The first trace-mode run was lost to this, because Qwen tokenizes digits one by one (a numeric CSV is about one token per byte). Its 230 samples are kept apart (`s6_samples_trace_truncated.jsonl`) and not scored. The final prompts fit by construction (bytes + answer budget ≤ `num_ctx`), and the server log shows no truncation.
- Answers are parsed into the G fragment with tabex's `convert` (as RQ4) plus one equivalence-preserving rewrite: constant-first comparisons (`15.2 <= omega`) are flipped. Anything else outside the fragment counts as a failure, as do missing `->`, bare Boolean atoms, unbounded or fractional windows and signal-vs-signal comparisons. The failure rates are reported with the results; SLAM's output is in the fragment by construction.

- **Fault detection** counts only the assertions that hold on the nominal traces, because a violated one would be a false alarm. A sample with no such assertion detects nothing. This filter makes the unchecked trace-mode set identical to `-trace-checked`.
- **G timeouts:** 18 of the 12,357 (requirement, candidate) pairs exceeded the 120 s per-pair budget. They are left out of the best-G maximum (all are LLM candidates). The forked scorer also crashed transiently on some pairs, about 2%; those were recomputed and all were scored.

## Simulink application benchmarks
- These are MathWorks examples (`sldemo_autotrans`, `sldemo_fuelsys`, `sldemo_absbrake`, `sldemo_househeat`, R2026b), driven by seeded random inputs within documented ranges. They are not industrial field data.
- The fuelsys nominal runs are restricted to the sensors' validity envelope: 10 input draws whose MAP reading exceeded 0.95 were redrawn, because that latches the controller's fail-safe mode. The first 2 s (start-up) are dropped.
- Requirements for fuelsys, absbrake and househeat were formalized from the example descriptions and checked on the traces. The autotrans requirements are the published ARCH-COMP AT ones. AT2, AT51, AT52 and AT53 are **falsified** by the model on the random inputs, so they are reported, not used as ground truth.
- **SLAM limits exposed by these benchmarks:**
  - The `G(..F.. -> F[0,0] c)` template cannot express invariants (contexts whose consequent always holds mine nothing), `G` in the consequent (AT5x) or `G` in the antecedent (AT6x).
  - `@(x,k)` is an operator computed on the trace, not a trace signal, so it cannot be a decision-tree numeric (such contexts mine nothing). Antecedents are therefore built from trace signals and their sums/differences; derivatives appear only in the template consequent (e.g. WT2–WT5, GB5, HT3).
- Sample-based windows: autotrans and fuelsys at 0.1 s, absbrake at 0.05 s, househeat at 60 s per row.
