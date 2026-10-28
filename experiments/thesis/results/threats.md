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
- **Few, small benchmarks.** These are the 3 FDL designs (about 1000 samples each) plus 4 Simulink application examples. Every case is mined and scored on the same trace, with no held-out traces.
- **The ground truth was formalized a posteriori.** The informal requirements of the FDL 2024 paper survive only as the SLAM config contexts (`38ff97a`, one per requirement). Requirement text and STL were reconstructed from the configs, the hybrid-automaton report and the traces, then reviewed by the author. Every ground-truth formula is checked to hold on its nominal trace and to be non-vacuously triggered (`score.py --check-truth`).
- **Table I is the published one.** The thesis reports the FDL 2024 Table I (time, N ass, N specs, 100% coverage, faulty water tanks) as published. Re-mining with the frozen binary does not give the same counts, at `--min-final 0.90`:

  | | Paper | Frozen binary |
  |---|---|---|
  | Water tanks | 46 | 218 |
  | Gearbox | 34 | 40 |
  | Thermostat | 25 | 17 |

  Causes:
  - The paper mined Water tanks on `tests/waterTanksCase/Trace_final.csv` (801 rows; `tests/CMakeLists.txt` at `142e952`/`38ff97a`), while the campaign uses `WT_Trace_Date.csv` (1000 rows, first 363 identical).
  - Gearbox and Thermostat use the paper's traces and identical configs (only the root tag was renamed), so their difference presumably comes from the code (paper-era `142e952`/`38ff97a` vs `b1149a4`), which was not rebuilt.

  The campaign's own measurements (S1 coverage, S2, faults) use the frozen binary throughout.
- **SLAM prints constants as float32** with 6 decimals (`16.200001` is float32(16.2)). The translation to the G fragment writes them back as their shortest decimal (`16.2`), otherwise an assertion such as `T >= 16.200001` would never trigger in double precision and would look vacuous (`common.to_fragment`).
- **Ranking in the frozen binary vs the paper's description.**
  - The paper describes a support ranking normalized to 1 at the best assertion and cut at 0.90.
  - The code (`Qualifier::sortAssertionsWithMetrics`) multiplies one sigmoid score per `<sort>` metric. The FDL configs define two: causality and support. When no assertion is near the top on both, every assertion scores close to 0 and `--min-final 0.90` keeps nothing.
  - This is why fuelsys yields no assertion: its contexts mine 12 and 8 assertions at `--min-final 0`, all with a final score of 0.00. It is reported as observed.
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
- **S6 covers all 7 designs.** The Simulink samples were regenerated for the template-restricted golden reference and the tuned contexts. The samples for the earlier Simulink requirements are kept in `s6_samples_simulink_v1.jsonl` and are not scored. The LLM prompts give each context's consequent and antecedent signals, not SLAM's tuned settings.
- Mode *req* reads the requirement text, which is an unfair advantage. Mode *trace* sees the same hints SLAM gets, plus a short description of the system and an excerpt of one trace, while SLAM mines all traces. The excerpt is the longest prefix of the first trace that fits a 20480-token context with 1500 tokens left for the answer: the whole run for Heater, absbrake, autotrans and fuelsys; 545/1000 rows for WaterTanks, 663/1001 for Gearbox, 889/2881 for househeat.
- Ollama cuts a prompt longer than `num_ctx` to `num_ctx/2` without an error, keeping only the first 4 tokens. The first trace-mode run was lost to this, because Qwen tokenizes digits one by one (a numeric CSV is about one token per byte). Its 230 samples are kept apart (`s6_samples_trace_truncated.jsonl`) and not scored. The final prompts fit by construction (bytes + answer budget ≤ `num_ctx`), and the server log shows no truncation.
- Answers are parsed into the G fragment with tabex's `convert` (as RQ4) plus one equivalence-preserving rewrite: constant-first comparisons (`15.2 <= omega`) are flipped. Anything else outside the fragment counts as a failure, as do missing `->`, bare Boolean atoms, unbounded or fractional windows and signal-vs-signal comparisons. The failure rates are reported with the results; SLAM's output is in the fragment by construction.

- **Fault detection** counts only the assertions that hold on the nominal traces, because a violated one would be a false alarm. A sample with no such assertion detects nothing. This filter makes the unchecked trace-mode set identical to `-trace-checked`.
- **G timeouts:** 12 of the 5,310 (requirement, candidate) pairs in the final tables exceeded the 120 s per-pair budget. They are left out of the best-G maximum (all are LLM candidates). The forked scorer also crashed transiently on some pairs, about 2%; those were recomputed and all were scored.

## Simulink application benchmarks
- These are MathWorks examples (`sldemo_autotrans`, `sldemo_fuelsys`, `sldemo_absbrake`, `sldemo_househeat`, R2026b), driven by seeded random inputs within documented ranges. They are not industrial field data.
- The fuelsys nominal runs are restricted to the sensors' validity envelope: 10 input draws whose MAP reading exceeded 0.95 were redrawn, because that latches the controller's fail-safe mode. The first 2 s (start-up) are dropped.
- **The Simulink golden reference is restricted to SLAM's template** (implications whose antecedent compares plain trace signals with constants, possibly under bounded F, and whose consequent is a single non-invariant predicate). The paper's coverage claim is scoped to this template.
  - The requirements were written from the model documentation and parameters, not from SLAM's output:
    - autotrans: the ShiftLogic schedule (lowest 2→1 downshift and highest upshift speeds; one-sample debounce, since `TWAIT` ticks of the 0.04 s chart fall within one 0.1 s sample);
    - fuelsys: the EGO switching threshold of 0.5 and stoichiometric AFR 14.6;
    - absbrake and househeat: the example descriptions.
  - Every requirement holds on all traces and is triggered.
  - Drafts falsified by the traces were dropped: brake with low throttle → speed decreasing; EGO rich → fuel rate decreasing (the feed-forward term dominates); heater on → indoor temperature rising; heater off with cold outdoor → falling.
  - The earlier, broader set is archived in `ground_truth_v1_simulink.csv` and not scored. It holds the published ARCH-COMP AT1, AT2, AT5x and AT6x, the fuelsys invariants (AFR band, fuel > 0), derivative-antecedent requirements and `ww <= vs`, some of them falsified by the model and others outside SLAM's template.
- **The Simulink contexts are configured per requirement, against the golden reference.** At the user's direction no standard template is imposed.
  - Each context's configuration was picked by a grid search (`s2_sweep.py tune`, logged in `s2_tuning.csv`) over the knobs SLAM exposes:
    - DT operands (`1A`/`3A`);
    - antecedent window bound (`maxd` 0/5/20/100);
    - clustering effort (`clsEffort` 0.001/0.01/0.1);
    - ranking metrics (causality × support, or support only, as the paper describes the ranking);
    - consequent window (`F[0,0]`, or the requirement's documented reaction window).
  - All runs use `--min-final 0.90`. The pick covers its requirement, then has the best own-context G, then the fewest assertions.
  - The Simulink coverage therefore shows that SLAM *can* mine each requirement with a suitable context. It is not a blind-mining result. The FDL designs keep the paper's own configs.
- **SLAM's template limits** (why requirements were out of scope):
  - The `G(..F.. -> F[0,0] c)` template cannot express invariants (a context whose consequent always holds mines nothing), `G` in the consequent (AT5x) or long `G` windows in the antecedent (AT6x).
  - `@(x,k)` is an operator computed on the trace, not a trace signal, so it cannot be a decision-tree numeric. Derivatives appear only in consequents.
- Sample-based windows: autotrans and fuelsys at 0.1 s, absbrake at 0.05 s, househeat at 60 s per row.
