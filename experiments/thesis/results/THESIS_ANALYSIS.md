# Thesis campaign: research questions and data analysis

Working notes for writing Ch. 5 (SLAM) and Ch. 6 (validation of miners). Each block gives:
- the question;
- where it goes in the thesis;
- the setup;
- the data;
- the analysis;
- the caveats;
- the source files.

**Numbers:** every number comes from `experiments/thesis/results/` on branch `exp/thesis-campaign` (commits `63254e5`, `b103fa0`, `82dceb0`, `957bc73`). The regenerated overview is `SUMMARY.md`; environment and provenance are in `ENV.md`; threats are in `threats.md`.

**Research questions** (draft, from `thesis/chapters/research_questions.tex`):
- **RQ2** (Ch. 5): can STL specifications be mined from CPS traces while overcoming the limitations of current approaches?
- **RQ3** (Ch. 6): how can specification miners be compared objectively against a common baseline?

**Benchmarks:**
- **FDL 2024 designs:** WaterTanks, Gearbox, Thermostat (= Heater). These have 14 informal requirements in total, use the paper's SLAM configs, and are mined with `--min-final 0.90`.
- **MathWorks Simulink application examples** (R2026b):
  - sldemo_autotrans (40 runs);
  - sldemo_fuelsys (20);
  - sldemo_absbrake (30);
  - sldemo_househeat (20).

  They have 12 requirements, written from the model documentation and parameters and restricted to SLAM's template.
- **Golden reference:** 26 encodable requirements in `ground_truth.csv`. Each holds on all its traces and is triggered (`score.py --check-truth`).

---

## Ch. 5, RQ2: SLAM

### Q5.1 Does SLAM cover the informal requirements?
**Thesis:** Ch. 5, experimental results (Table I and its extension to the Simulink examples).

**Setup:**
- **Coverage, in the paper's sense:** a requirement is covered if *its own context* mines at least one assertion that holds on all traces and is triggered at least once. This is the FDL 2024 notion "covered by at least one related assertion", made reproducible; in the paper, relatedness was a manual judgement, and here it is given by the per-requirement context.
- **Binary:** frozen `b1149a4` (sha256 in ENV.md).
- **FDL:** the paper's configs.
- **Simulink:** one context per requirement, configured by `s2_sweep.py tune` (see Q5.4).

**Data:**

| Design | Reqs | Coverage | Assertions kept | Mining time (s) |
|---|---|---|---|---|
| WaterTanks | 5 | 5/5 | 218 | 1.88 |
| Gearbox | 6 | 6/6 | 40 | 0.11 |
| Thermostat | 3 | 3/3 | 17 | 0.06 |
| absbrake | 3 | 3/3 | 17 | 0.21 |
| autotrans | 4 | 4/4 | 11 | 0.16 |
| fuelsys | 2 | 2/2 | 12 | 0.05 |
| househeat | 3 | 3/3 | 6 | 1.15 |

The published Table I reports 100% coverage, N ass 34/25/46 and 0.32/0.21/2.04 s for Gearbox/Thermostat/Water tanks. The thesis reuses it as published.

**Analysis:**
- SLAM covers **26/26** requirements on all 7 designs. That reproduces the paper's 100% on the FDL designs and extends it to 4 industrial examples.
- **Soundness:** every mined assertion holds on its traces (0 violations over all designs) and translates into the G fragment (0 out of fragment).
- **Mining time:** at most 1.9 s per design, even on 20–40 concatenated runs (househeat has 57,620 samples).

**Caveats:**
- The Simulink contexts were configured against the golden reference. The Simulink result therefore shows that SLAM *can* mine each requirement with a suitable context, not blind mining. At the default context config, 8/12 are covered (Q5.4).
- The FDL requirement text and STL were reconstructed a posteriori, and the user's review is pending (threats.md, "ground truth").

Sources: `s1_table.csv`, `s1_per_req.csv`, `s1_mining.csv`, `s1_mine.log`.

### Q5.2 How close are the mined assertions to an exact formalization of each requirement?
**Thesis:** Ch. 5, as a stricter view than coverage; this links Ch. 5 and Ch. 6 (G from the similarity chapter).

**Setup:**
- **Best-G:** the G similarity of each requirement against the design's whole SLAM set (the best match, in any context).
- **Own-context G:** the same, restricted to the requirement's own context.
- **D:** one per requirement, from the observed range of its signals.

**Data (SLAM):**

| Scope | Reqs | Coverage at G = 1 | Coverage at G ≥ 0.9 | Mean best-G |
|---|---|---|---|---|
| FDL | 14 | 0 | 1 (WT3, 0.94) | 0.34 |
| Simulink | 12 | 0 | 7 (ATS2, ATS3, FSE1, FSE2, AB1, AB3, HH2) | 0.86 |
| All | 26 | 0 | 8 | 0.58 |

Best-G per requirement:
- **WaterTanks:** WT1 0.63, WT2 0.27, WT3 0.94, WT4 0.14, WT5 0.14.
- **Gearbox:** GB1 0.26, GB2 0.26, GB3 0.20, GB4 0.19, GB5 0.88, GB6 0.34.
- **Thermostat:** HT1 0.34, HT2 0.15, HT3 0.08.
- **autotrans:** ATS1 0.77, ATS2 1.00 (0.9996), ATS3 0.92, ATS4 0.76.
- **fuelsys:** FSE1 0.97, FSE2 1.00 (0.997).
- **absbrake:** AB1 0.97, AB2 0.83, AB3 0.93.
- **househeat:** HH2 1.00 (0.9995), HH3 0.63, HH4 0.55.

**Analysis:**
- **G = 1 is never reached.** SLAM picks its thresholds by clustering the trace values, not from the documented constants.
  - Examples: `vs >= 16.714` vs `vs > 10` (AB1, 0.97); `speed >= 17.8132` vs `speed > 17.8816` (ATS2, 0.9996).
  - Coverage at G = 1 is therefore not a useful criterion for a trace-based miner. Report G ≥ τ and mean best-G instead.
- **Why FDL is low (0.34):**
  - The paper's configs allow antecedent windows up to 100 samples (`100maxd`), so SLAM ranks long-lag patterns first, such as `z <= 1.29 -> F[53,77] a == 1`.
  - G is strict on windows: `T>=16.2 -> F[0,5] Status==0` scores 0.154 against `T>=16.2 -> Status==0`, even though the requirement implies it (HT2).
  - The Gearbox gear contexts mine `omega == 0` or throttle predicates (own-context G ≤ 0.004). The best Gearbox match, 0.19–0.34, comes from another context (`omega >= 14.91 -> theta_d1 > 0`).
- **Three FDL requirements cannot be matched exactly with the paper's configs,** because their context does not list one antecedent signal: WT5 lacks `z`, HT1 lacks `Status`, HT3 lacks `T`.
- **Why Simulink is high (0.86):** single-operand contexts and fine clustering (Q5.4) give compact assertions with thresholds near the documented ones.

**Caveats:**
- G compares against *my* formalization of the windows (e.g. `F[0,15]`), and its value depends on it directly.
- One D per requirement (2–100) makes comparisons on narrow signals coarse when one requirement mixes ranges.

Sources: `s1_per_req.csv` (columns `best_G`, `best_own_ctx_G`, `best_cand`, `D`), `s1_table.csv`.

### Q5.3 How does SLAM compare with LLM-based mining?
**Thesis:** Ch. 5, as the external baseline. No STL miner was runnable: TeLEx is Python 2.7-only (threats.md, S5).

**Setup:**
- **Models:** qwen2.5 7B and 14B (Q4_K_M), local via Ollama; 5 samples per prompt (temperature 0.8, seeds 1–5).
- **Modes:**
  - `-req`: one formula per requirement *text*, the tabex RQ4 prompt. This mode has an unfair advantage: it reads the requirement.
  - `-trace`: a trace excerpt plus the same hints SLAM gets (context consequent, antecedent signals), up to 10 assertions per context.
  - `-trace-checked`: only the trace answers that hold on the traces, which SLAM guarantees by construction.
- **Scoring:** answers are parsed into the G fragment (tabex `convert`, plus flipping `c op x` to `x op' c`) and scored exactly like SLAM.

**Data** (mean over 5 samples, 26 requirements):

| Source | Coverage | G ≥ 0.9 share | Mean best-G | FDL coverage / mean best-G | Simulink coverage / mean best-G |
|---|---|---|---|---|---|
| **SLAM** | **1.00** | 0.31 | 0.58 | 1.00 / 0.34 | 1.00 / **0.86** |
| 14B -req | 0.51 | **0.39** | **0.66** | 0.56 / 0.71 | 0.45 / 0.59 |
| 14B -trace | 0.52 | 0.15 | 0.52 | 0.47 / 0.47 | 0.57 / 0.58 |
| 14B -trace-checked | 0.52 | 0.08 | 0.37 | 0.47 / 0.35 | 0.57 / 0.40 |
| 7B -req | 0.07 | 0.05 | 0.31 | 0.10 / 0.37 | 0.03 / 0.23 |
| 7B -trace | 0.29 | 0.10 | 0.45 | 0.21 / 0.31 | 0.38 / 0.61 |
| 7B -trace-checked | 0.29 | 0.04 | 0.29 | 0.21 / 0.21 | 0.38 / 0.38 |

Output validity (all 7 designs):

| Source | Answer lines | Outside the fragment | Parsed but violated on the traces | Kept by `-checked` |
|---|---|---|---|---|
| 14B -req | 130 | 29 (22%) | 21 of 101 (21%) | — |
| 7B -req | 130 | 72 (55%) | 45 of 58 (78%) | — |
| 14B -trace | 1292 | 182 (14%) | 770 of 1110 (69%) | 340 (26%) |
| 7B -trace | 799 | 371 (46%) | 298 of 428 (70%) | 130 (16%) |

Per requirement (best-G, margin 0.05):
- SLAM vs 14B -trace-checked: SLAM better on 15, LLM better on 6, ties 5.
- SLAM vs 14B -req: SLAM 11, LLM 12, ties 3.

**Analysis:**
- **Coverage:** SLAM is the only source that covers every requirement. The best LLM covers about half, in either mode.
- **Like-for-like** (trace mode, holding answers, which is what SLAM guarantees):
  - SLAM wins clearly on Simulink: mean best-G 0.86 vs 0.40, G ≥ 0.9 share 0.58 vs 0.17;
  - SLAM is level on FDL: 0.34 vs 0.35.
- **Validity:** about 70% of the parsed trace-mode answers are false on the traces, and only 16–26% of the lines survive the check. The 7B model also fails the fragment on 46–55% of its lines.
- **Reading the requirement text helps 14B on closeness.** It has the best mean best-G (0.66) and is perfect on fuelsys, where the text gives the constants. But it still covers only 0.51, because many answers are violated or out of the fragment.
- **Model size matters strongly:** 7B is far below 14B in every mode.
- **Near misses:** unchecked trace answers score higher G than checked ones (e.g. autotrans 14B: 0.91 vs 0.73). Some answers are close to the requirement but wrong on the data, typically constants slightly off, so they fail on the traces.

**Caveats:**
- These are small open models on one GPU, with one prompt per mode, so the results do not generalize to large or proprietary LLMs.
- The trace mode sees an excerpt of one run: the whole run for Thermostat, absbrake, autotrans and fuelsys; 545/1000, 663/1001 and 889/2881 rows for WaterTanks, Gearbox and househeat. SLAM mines all runs.
- A first trace-mode run was silently truncated by Ollama; it was discarded and rerun with prompts that fit by construction (threats.md).

Sources: `s1_table.csv`, `s1_per_req.csv`, `s6_parse.md`, `s6_samples.jsonl`, `s6_candidates.csv`.

### Q5.4 How sensitive is SLAM to its configuration?
**Thesis:** Ch. 5, sensitivity (the planned S2 sweep), plus a short note on configuring contexts.

**Setup:**
- **Grid:** `--min-final` {0.80, 0.85, 0.90, 0.95} × clustering threshold th scaled ×{0.1, 1, 10}, on the shipped configs.
- **Tuning** (Simulink, `s2_sweep.py tune`): 48–96 configs per context over:
  - DT operands `A` {1, 3};
  - antecedent window `maxd` {0, 5, 20, 100};
  - `clsEffort` {0.001, 0.01, 0.1};
  - ranking {causality × support, support only};
  - consequent window {0, documented}.

  The winner covers its requirement, then has the best own-context G, then the fewest assertions.

**Data, `--min-final` × th grid:**

| Design | Coverage over the 12 cells | Assertions (min–max) | Mean best-G |
|---|---|---|---|
| WaterTanks | 1.00 everywhere | 187–260 | 0.42 |
| Gearbox | 1.00, except 0.83 at th×10 | 16–55 | 0.36 |
| Thermostat | 1.00 everywhere | 8–25 | 0.13–0.19 |
| autotrans | 1.00, except 0.75 at th×10 | 8–17 | 0.86 |
| fuelsys / absbrake / househeat | 1.00 everywhere | 12–14 / 17 / 6 | 0.98 / 0.91 / 0.72 |

**Data, tuning grid** (default = 3A, maxd 100, clsEffort 0.01, causality × support, no consequent window):

| Context (req) | Configs that cover | Default: covered, own G | Chosen: config, own G |
|---|---|---|---|
| shift_gear1 (ATS1) | 96/96 | yes, 0.06 | 1A maxd0 cls0.1, 0.48 |
| shift_gear2up (ATS2) | 88/96 | yes, 1.00 | 1A maxd100 cls0.001, 1.00 |
| shift_gear3up (ATS3) | 88/96 | yes, 0.13 | 1A maxd20 cls0.1, 0.66 |
| shift_gear4 (ATS4) | 24/96 | **no**, 0.08 | 1A maxd0 cls0.001, 0.42 |
| ego_rich (FSE1) | 40/48 | **no** (0 assertions), 0 | 1A maxd0 cls0.001, 0.97 |
| ego_lean (FSE2) | 36/48 | **no** (0 assertions), 0 | 1A maxd0 cls0.001, 1.00 |
| slip_limit (AB1) | 48/48 | yes, 0.97 | 1A maxd100 cls0.001, 0.97 |
| deceleration (AB2) | 48/48 | yes, 0.07 | 3A maxd0 cls0.001, 0.83 |
| distance (AB3) | 48/48 | yes, 0.93 | 1A maxd5 cls0.001, 0.93 |
| heater_on (HH2) | 60/96 | **no** (0 assertions), 0 | 1A maxd5 cls0.001, 1.00 |
| heater_off (HH3) | 96/96 | yes, 0.08 | 1A maxd0 cls0.001, 0.48 |
| no_cost (HH4) | 12/48 | yes, 0.03 | 1A maxd100 cls0.001, 0.03 |

Knob values among the 12 winners:
- `A`: 1A in 11 of 12;
- `clsEffort`: 0.001 in 10, 0.1 in 2;
- `maxd`: 0 in 6, 5 in 2, 20 in 1, 100 in 3;
- ranking: causality × support in all 12;
- consequent window: 0 in all 12.

**Analysis:**
- **`--min-final` barely matters** for coverage, between 0.80 and 0.95. It only changes how many assertions are kept: WaterTanks keeps 187–260.
- **The clustering threshold is the sensitive knob.** At th×10 (coarser clusters), Gearbox drops to 0.83 and autotrans to 0.75.
- **With one standard context per requirement, 8/12 Simulink requirements are covered.** The 4 misses have two causes:
  - ranking: the causality × support product is near 0 when no assertion tops both metrics, so fuelsys and heater_on keep 0 assertions at 0.90;
  - vacuity at the trace end: ATS4's only assertion triggers at the speed maximum of the last samples, where its window doesn't fit.
- **Finer clustering and single-operand antecedents fix all four.** They also raise own-context G a lot (deceleration 0.07 → 0.83, heater_on 0 → 1.00, ego_rich 0 → 0.97).
- **Support-only ranking (the paper's description) and consequent windows never won.**
- **Message for the thesis:** SLAM's result depends on the engineer-supplied context (P/NE sets, effort). Coverage is robust to the ranking threshold, but not to clustering effort.

Sources: `s2_sensitivity.csv`, `s2_sensitivity_sim.csv`, `s2_tuning.csv`, `s2_tuning.log`.

### Q5.5 What do SLAM's filtering stages do, and why does N ass differ from the paper?
**Thesis:** Ch. 5, a footnote to Table I (the thesis keeps the published numbers).

**Setup:** per FDL design, SLAM's own log counts (`s2_sweep.py table1`, added on the second machine in `957bc73`):
- **mined:** every assertion that holds and is triggered;
- **after dedup:** `--min-final 0`;
- **after the 0.90 cut:** the stage the paper's N ass was counted at (`Qualifier.cc:283` at `38ff97a`).

**Data:**

| Design (trace) | Mined | After dedup | After the 0.90 cut | Removed by the cut | Paper N ass |
|---|---|---|---|---|---|
| WaterTanks (`WT_Trace_Date.csv`, campaign) | 3199 | 3072 | 218 | 93% | 46 |
| WaterTanks (`Trace_final.csv`, paper) | 4347 | 4114 | 156 | 96% | 46 |
| Gearbox | 97 | 96 | 40 | 58% | 34 |
| Thermostat | 49 | 44 | 17 | 61% | 25 |

**Analysis:**
- **Dedup removes little** (1–10%). **The ranking cut is the stage that shrinks the set,** by 58–96%.
- **The counts are deterministic across machines and builds:** a `b1149a4` rebuilt on the second machine gives the same 218/40/17.
- **The paper's N ass is not reproduced** (156 vs 46 on the paper's own trace; 40 vs 34; 17 vs 25):
  - Thermostat keeps *fewer* than the paper, so a stricter filter cannot explain the gap.
  - The code diff `38ff97a` → `b1149a4` is mostly removed spot/LTL code. The paper-era binary was not rebuilt, so the gap is reported, not explained.

Sources: `s2_tableI.md`, `threats.md` (Table I), `ENV.md` (second machine).

### Q5.6 How does mining time scale with the number of numeric expressions?
**Thesis:** Ch. 5, scalability. The paper's published scalability, in trace length via `--multiply-trace`, is not rerun.

**Setup:**
- WaterTanks, a 1000-sample trace, one context with the template `G(..F.. -> F[0,0] a==1)`;
- k decision-tree numerics, taken from trace signals and their sums/differences;
- 16 threads, 5 repetitions.

**Data:**

| k | Assertions | Wall time (s, mean ± std) | × per doubling of k |
|---|---|---|---|
| 1 | 6 | 0.029 ± 0.021 | — |
| 2 | 6 | 0.235 ± 0.027 | 8.2 |
| 4 | 47 | 5.76 ± 0.22 | 24.5 |
| 8 | 32 | 61.5 ± 1.4 | 10.7 |
| 16 | 53 | 1017 ± 64 | 16.5 |

**Analysis:**
- Time grows super-linearly: between k = 4 and 16 it goes roughly as k^3.7, so k = 16 takes about 17 min.
- On the real benchmarks (1–3 numerics per context), mining takes at most 2 s (Q5.1).
- The number of assertions is not monotone in k, because it is what remains after the ranking cut, not what is mined.

**Caveat:** an earlier series used `@(x,1)` derivatives as numerics. That is invalid: the derivative is computed on the trace and cannot be a DT numeric. It is kept only as `s2_scalability_with_deriv.csv` (similar growth, k^3.6).

Sources: `s2_scalability.csv`, `s2_scalability.pdf`.

### Q5.7 Are SLAM's assertions useful to detect faults?
**Thesis:** Ch. 5, extending the paper's single faulty-water-tank row.

**Setup:**
- **FDL sensor mutations** from T0 = 300: stuck, offset, drift, noise, on 4–5 signals per design.
- **WaterTanks valve-stuck-open:** the paper's faulty trace.
- **fuelsys:** re-simulated sensor failures (EGO, MAP, speed, throttle switches).
- **Detection:** at least one assertion that holds nominally is violated on the faulty trace.

**Data:**

| Design | Faults | SLAM | Ground truth | 14B -trace-checked | 14B -req |
|---|---|---|---|---|---|
| WaterTanks | 5 | 4 (all but z-offset) | 3 | 3.2 ± 1.8 | 2.4 ± 0.5 |
| Gearbox | 4 | 4 | 4 | 3.6 ± 0.9 | 3.4 ± 0.9 |
| Thermostat | 4 | 2 (drift, noise) | 4 | 3.2 ± 0.4 | 3.4 ± 0.5 |
| fuelsys | 4 | 1 (EGO) | 1 | 0.6 ± 0.9 | 1.0 ± 0.0 |
| Total | 17 | **11** | 12 | 10.6 | 10.2 |

**Analysis:**
- **SLAM is close to the golden requirements overall** (11 vs 12 of 17).
- **WaterTanks: SLAM catches the paper's own fault (valve stuck open), which the ground truth misses.** Its long-window assertions capture dynamics the requirements do not state.
- **Thermostat: SLAM misses the offset and stuck faults.** Its assertions only constrain the `T >= 16.2` threshold region.
- **fuelsys is limited by the requirements, not by SLAM:** the golden reference only relates AFR and EGO, so both detect only the EGO failure.

**Caveat:** there are few faults (17), mostly synthetic sensor mutations.

Sources: `faults.csv`, `faults.md`.

### Q5.8 Which limitations did the campaign expose?
**Thesis:** Ch. 5 (limitations) and Ch. 8 (future work).

- **Template scope.** `G(..F.. -> F[0,k] c)` cannot express:
  - invariants (a context whose consequent always holds mines nothing): AT1, FS1, FS2, HH1;
  - `G` in the consequent (ARCH-COMP AT5x);
  - long `G` windows in the antecedent (AT6x).

  These were archived as out of scope (`ground_truth_v1_simulink.csv`).
- **Derivatives cannot be DT numerics.** `@(x,k)` is computed on the trace, so it can only appear in consequents.
- **Ranking.** The code multiplies sigmoid-normalized metrics (causality × support), whereas the paper describes support normalized to 1. A context can therefore lose all assertions at `--min-final 0.90` (Q5.4).
- **Constants** are printed as float32 (`16.200001`). Taken literally in double precision, they make assertions look vacuous. Fixed in the evaluation (`common.to_fragment`), not in SLAM.
- **Vacuity at the trace end:** a threshold at a signal's maximum, reached only in the last samples, yields assertions with no checkable trigger (ATS4 at the default config).
- **Thresholds come from clustering,** so assertions are never exactly the documented constants (Q5.2).

---

## Ch. 6, RQ3: validation of miners

### Q6.1 Is the STL similarity G a usable semantic replacement for manual coverage judgement?
**Thesis:** Ch. 6 (STL similarity), with one sentence pointing to the Ch. 5 S1 table.

**Setup:**
- tabex `09d6d17` (`fast_similarity`), G = (fw + bw)/2;
- the fragment: `var op const` atoms and bounded temporal operators;
- `x_d1` is encoded as a fresh signal;
- per-pair budget 120 s, in a forked scorer.

**Data:**
- **7,786 (requirement, candidate) pairs** in the final tables. 12 are unscored because they timed out, all LLM candidates. Scored pairs take a median under 0.01 s, p90 0.2 s, max 3.8 s.
- **One-way scores are almost symmetric** over all scored pairs: |fw − bw| has mean 0.017, median 0.003 and p90 0.046; corr(fw, bw) = 0.983.
- **D per requirement:** 2–100.
- **Fragment fit:** 100% of SLAM's assertions; 45–86% of the LLM answer lines (Q5.3).

**Analysis:**
- **G works as a graded ranking of candidate sets.** It separates SLAM from the LLMs, and the tuned from the default configs.
- **As a binary "covers" test it is too strict.**
  - G = 1 is never reached by a trace-based miner, because of the constants.
  - A weaker but implied formula scores low (HT2: 0.154).
- **The one-way scores do not measure entailment:** they are distance-based and nearly symmetric. They cannot stand in for the paper's "related to" notion either. Hence the campaign uses the context-based coverage as the main measure, with G as the stricter view.
- **Practical cost is low** for this fragment. The 12 timeouts all involve long LLM windows.

**Caveats:**
- The fragment excludes signal-vs-signal comparisons and arithmetic (e.g. `ww <= vs`).
- One D for all signals of a pair.
- These are discussed in threats.md, "STL similarity G".

Sources: `g_cache.jsonl`, `s1_per_req.csv`.

### Q6.2 (S3) Are the USM-T qualification results stable across stimulus seeds?
**Thesis:** Ch. 6 (USM-T), testing the single-run argument of Sec. 8.1 (TODAES version: "Different stimuli seeds are therefore expected to expose the same behaviors, and a single run is sufficient"). The ">99%" claim of Sec. 7.2 is about post-synthesis minimisation of the generated AIGER circuit, not about mined specifications: S3 says nothing about it (1 − MC/n_mined is only the share of mined specifications the fault cover does not need).

**Setup** (`s3_usmt.py`):
- USM-T `28dff1c` (the TODAES submission's code), with the published case study's settings (ENV.md);
- the And / Next / Eventually challenges (TODAES 2026 templates, trace length 10,000);
- 5 stimulus seeds (`USMT_SEED`; golden specifications kept identical through `PYTHONHASHSEED=0` and `random.seed(0)`);
- miners: HARM, Texada, Samples2LTL, GoldMine (Docker), with Gemini dropped;
- metrics: n_mined, syntactic/semantic/hybrid MS and RS, SFC, MC, time;
- reported as mean ± std [min–max] over the seeds, alongside one run of the published TODAES 2026 tests.

**Data** (`s3_usmt.md`; hybrid MS, mean [range] over 5 seeds; RS and SFC identical across seeds unless noted):

| Challenge | HARM | GoldMine | Texada | Samples2LTL |
|---|---|---|---|---|
| And | 1.00 | 0.75 | 0.50 | 0.50 |
| Next | 0.95 [0.95–0.96], SFC 0.91–1.00 | 0.33 | **0.86 [0.71–1.00]** | 0.10 |
| Eventually | 0.95 [0.94–0.96] | 0.50 | 0.87 [0.84–0.89]* | 0.42 |

\* within the spread of identical runs (0.83 / 0.87 / 0.88 on seed 1): USM-T shuffles the mined specifications with an unseeded `shuf` and `--max-mined` keeps 10,000 of Texada's ~82k. Texada on Next (no cut) gives the same 62,717 specifications and MS 0.90 in three runs of seed 1, so its spread there is a seed effect. MC varies by up to 3 on identical input (greedy cover over the shuffled order).

**Published inputs, one run (28dff1c):**
- And reproduces the paper (HARM 1.00, GoldMine 0.75, Texada 0.50, Samples2LTL 0.50).
- Next does not: HARM MS 0.78 and SFC 0.83 (paper 1.0/1.0). This is consistent with the 4/10 golden specifications that fail `golden_check` on the published Next.
- Eventually: Texada 0.85 (paper 1.0; 0.83–0.89 in our 8 runs), HARM 0.94 (paper 0.88), Samples2LTL 0.42 (paper 0.22). HARM ranks above Texada on every run.

The published hand edits (HARM `dtLimits` on And, Samples2LTL trim) were checked by rerunning without them: MS/RS/SFC were identical.

**Answer:** a single run is sufficient on And and Eventually (apart from the sampling effect), but not on Next. There, Texada's MS spans 0.71–1.00 with the seed and swaps rank with HARM on seed 5. Any run where a miner exceeds `--max-mined` is a random sample, regardless of the stimulus.

### Q6.3 (S4) How do the miners perform on the NextAnd and Until challenges?
**Thesis:** Ch. 6 (USM-T): one extra radar panel or a sentence, closing the "redundant" justification in Sec. 8.1.

**Setup:** same as Q6.2, on the NextAnd (`G(..#1&.. |-> ..#1&..)`) and Until (`G(..&&.. |-> ..&&.. U ..&&..)`) templates.

**Data** (`s4_usmt.md`; mean [range] over 5 seeds):

| Challenge | Miner | hybrid MS | RS | SFC | Mining time |
|---|---|---|---|---|---|
| NextAnd | HARM | 0.72 [0.62–0.83] | 0.54 [0.29–0.71] | 0.76 [0.74–0.78] | 2.2–3.0 h |
| | GoldMine | 0.58 | 0.92 | 1.00 | 385–555 s |
| | Texada | 0.38 | 1.00 | 0.81 | 735–950 s |
| | Samples2LTL | 0.20 | 0.90 | 0.07 | 1000–1848 s |
| Until | HARM | 1.00 | 0.95 | 1.00 | 54–68 s |
| | GoldMine | 0.50 | 0.67 | 1.00 | 128–167 s |
| | Texada | no output: both templates hit the 600 s cap | | | |
| | Samples2LTL | 0.44 | 0.98 | 0.00 | 1556–1845 s (own 1800 s timeout) |

**Answer:** neither challenge is redundant.
- **NextAnd vs Next:**
  - GoldMine moves from 3rd to 2nd and Texada from 2nd to 3rd.
  - HARM stays 1st, but its runtime grows from about 10 s to 2.2–3.0 h, and it is seed-sensitive (it returns 14–34 assertions).
- **Until vs Eventually:** HARM, GoldMine and Samples2LTL behave as on Eventually, but Texada (2nd on Eventually) returns nothing within its limit.

---

## Threats to validity (condensed; full text in `threats.md`)
- **Golden reference:**
  - the FDL requirements were formalized a posteriori, and the user's review is pending;
  - the Simulink requirements are restricted to SLAM's template, written from documentation and checked on the traces.
- **Tuning:** the Simulink contexts were configured against the golden reference.
- **Table I:** reused from the paper; the frozen binary's counts differ (Q5.5).
- **Same data:** every benchmark is mined and scored on the same traces, with no held-out runs. The Simulink inputs are seeded random stimuli, not field data.
- **LLM baseline:** small local models, with the prompt and excerpt limits above.
- **Dropped campaign:** S5 (TeLEx: Python 2.7-only, unmaintained since 2017).

## Open items
- **Ground-truth review** (`ground_truth.csv`). In particular, whether to rewrite WT5 and HT1 using only their context's signals (`rain > 0 && a == 1 -> z_d1 > 0`; `T <= 15.2 -> F[0,1] Status >= 1`; both hold). HT3 has no such rewrite.
- **For the USM-T co-authors:**
  - the published Next fails `golden_check` (4/10);
  - the paper's Next and Eventually values are not reproduced with `28dff1c`;
  - `shuf` is unseeded;
  - capped Texada calls duplicate output.
