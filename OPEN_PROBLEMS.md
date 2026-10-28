# SLAM — Open Problems

Snapshot: 2026-10-16. Branches reviewed: `develop` @ `e195c41`,
`f_STLG` @ `c40510b`, `f_robustnesscalc` @ `87103eb`.

This document lists the open work items for SLAM. For each one it gives the
current state of the code, what is missing, the main technical difficulties,
and a proposed direction. Both feature branches were built and run on their
own examples. Findings marked *(observed)* come from those runs; the others
come from reading the code. Paths given as `file:line (branch)` point into
the feature branch, not into `develop`. A section on integrating the
branches and a short list of housekeeping items close the document.

| # | Problem | Status |
|---|---------|--------|
| 1 | `..G..` decision-tree operator | Implemented, not tested (`f_STLG`). The branch HEAD does not compile. |
| 2 | Robustness as a qualification metric | Implemented, not tested (`f_robustnesscalc`). Builds, but the robustness semantics have bugs. |
| 3 | Filtering with STLSAT (`--remove-impl`) | Prototype (v1). Needs further testing. |
| 4 | New benchmarks (MATLAB) | Partial. Golden assertions still need to be defined, traces generated, and results produced on more designs. |

Every point is more or less independent, since each module can be activated
or not independently of the others. The feature branches do share core code,
though (the expression layer, the DT operator interface and `TLMiner`), so
merging them needs some integration work (see
[Integrating the feature branches](#integrating-the-feature-branches)).

---

## 1. `..G..` decision-tree operator (`f_STLG`)

### Goal
A decision-tree placeholder `..G..`, the counterpart of `..F..`. With it, the
miner can learn antecedents in which a condition must **persist** over a
window, instead of occurring at some point in it. It also allows `G[a,b]` in
the consequent:

```
G( G[0,0](p0) && G[t1,t2](p1) && ... -> F[c1,c2](q) )
G( ..G.. -> G[c1,c2](q) )
```

### What the branch implements
11 commits, the last on 2026-07-02, branched from `develop` HEAD.
- **`Globally` temporal node** with correct three-valued semantics: `F` on
  the first false sample, `U` when the window crosses the end of the trace,
  `T` otherwise (`src/exp/src/classes/temporal/Globally.cc`). It is
  registered in all visitors.
- **Grammar**:
  - `G[a,b]` inside `tformula`;
  - the `..G..` token;
  - `G[a,b]` as the consequent operator, both after `..F..`/`..G..` and
    after an explicit antecedent.
- **`DTAndG`**, a decision-tree operator. The DT interface now carries an
  (interval, shift) pair per operand instead of a single interval.
- **G-specific interval discovery** (`Template::gatherGInterestingValue`)
  works on runs of consecutive "antecedent ∧ consequent" points, together
  with G-specific clustering in `minerUtils.cc`.
- **Mining the interval of a `G` consequent** before the DT run
  (`Template::makeGConInterval`).
- **Example and test:** `examples/GloballyChain` and a gtest
  (`tests/GCon_parser.cc`) for parsing G consequents.

### Open issues
1. **HEAD does not compile** *(observed)*:
   - `Template.cc:577/583 (f_STLG)` declares `delta` twice, once as `int`
     and once as `size_t`;
   - `Template.cc:602,609` call `std::min(int&, size_t&)`;
   - `StlParserHandler.cc:41,61` call a 3-argument `Globally` constructor
     that does not exist (the only constructor also takes a `shift`).

   Fixing those lines locally is enough to get a working build. The last
   commit that compiles is `1630bb8`. The parser calls broke in `421cf31`,
   which used the constructor signature from before `cbc183d` added
   `shift`. The `delta` errors come from `c40510b`, which added a `size_t
   delta` without removing the `int delta` stub left by `dff4c07`.
2. **`makeGConInterval` always yields `G[0,0]`.**
   - `delta` starts at 0 and is updated with `std::min` at every step, so it
     never grows. Even starting from `SIZE_MAX`, taking the minimum *inside*
     a run captures the value 1. The minimum has to be taken over the
     lengths of completed runs.
   - The function also adds a `true` operand to the DT operator and never
     pops it, so the DT starts mining with a spurious operand.
     `gatherGInterestingValue`, by contrast, pops it correctly.
3. **Offsets are output as onsets.** The offset loop in `TLMiner.cc` now
   calls `fillContingency(..., 0)`, `fillValues` and `getAssertion()`, so the
   consequent is no longer negated. An antecedent after which the consequent
   *never* holds is therefore printed as `ant -> con`, which is false on the
   trace.
   - *(Observed)* on `examples/GloballyChain`: the only output is
     `G(G[0,8](p0 <= 0) -> F[8,8](consequent == 1))`, with causality 1.00
     and support NaN (`atct = 0`). This assertion is violated at t=58: `p0`
     is 0 over 58..66, and `consequent` is 0 at 66.
   - This is the most likely cause of "mined assertions appear out of
     nowhere" in commit `1630bb8`.
   - The pattern the example was built for (a burst of `p1`, then `p0 == 100`,
     then `consequent`) is not found.
4. **A `G` consequent with an explicit antecedent becomes `F`.** In
   `exitImplication`, the branch for `tformula -> G[a,b] tformula` still
   builds an `Eventually`. As a result, `G(p -> G[0,5] q)` is silently mined
   as `F[0,5]`.
5. **Interval bookkeeping needs checking.**
   - `DTAndG::removeItems` resets the consequent interval to `[0,0]`. It runs
     after every solution, so it can wipe the interval computed by
     `makeGConInterval` once the first assertion is found.
   - With a single operand, `popItem` subtracts the whole consequent
     interval, not that operand's shift.
6. **Shift semantics for `G` (design decision).** Adding an operand shifts
   the earlier windows by `[s1,s2]` on both bounds, so `G[a,b]` becomes
   `G[a+s1, b+s2]`. For `F` this is the right over-approximation. For `G` it
   requires the condition to hold over the *union* of all possible offsets,
   which is stronger than "held for b−a samples at some offset". The intended
   semantics should be stated and tested.
7. **STLSAT pre-filter.** `getAssPropsAsString` (`Template.cc:51-62`) still
   unpacks only `Eventually`. The propositions under `G[a,b]` are therefore
   not extracted, and `same_props` (see 3) compares incomplete sets.
8. **Branch hygiene.**
   - The branch **deletes the whole `examples/` folder** except
     `GloballyChain` (bl_master, camellia, faultCov, paperRE, …, about 3.9 M
     lines). Merging it as-is removes them from `develop`.
   - `tree.dot`/`vac.txt` are committed at the repo root.
   - `GCon_parser.cc` is not wired into `ctest`.
   - The `DTAndG.hh` doc comment still says `..F..`.

### Done when
- The branch builds and `GCon_parser` runs in `ctest`.
- Unit tests cover `G[a,b]` evaluation on hand-written traces, including
  end-of-trace cases.
- `GloballyChain` mines its intended assertion, and every reported assertion
  holds on the trace.
- At least one real benchmark yields an assertion that `..F..` cannot
  express.

---

## 2. Robustness as a qualification metric (`f_robustnesscalc`)

### Goal
Use STL quantitative semantics (robustness) as a ranking and filtering
feature next to the contingency-table features (`atct`, `afct`, ...). The
aim is to prefer assertions that hold with a margin.

### What the branch implements
6 commits, the last on 2026-02-10, branched from `32dca10` (one commit,
README only, behind `develop`). The branch builds.
- **Real-valued evaluation on every `TemporalExp`**, in three variants:
  - standard STL (`evaluate_std_robustness`);
  - *cumulative* (positive and negative parts);
  - *tropical* (positive and negative parts).

  Propositions use signed distance for `<`, `<=`, `>`, `>=`, `-|x−c|` for
  `==`, and negation for `!`. Other operators raise an error.
- **`Template::fillRobustness`** computes, per assertion, the minimum over
  the trace (`final`) and the mean for the 5 variants. These are exposed as
  10 numeric metric variables (`stdrob`, `mstdrob`, `cumpos`, `mcumpos`,
  `cumneg`, `mcumneg`, `tropos`, `mtropos`, `troneg`, `mtroneg`) that can be
  used in `<sort>`/`<filter>`.
- **Metric normalization** changed from `x/max` to min–max for all metrics.
- **Debugging aids:**
  - `--debug-rob` dumps per-instant values for the top-ranked assertion;
  - `third_party/csv_plotter.py` plots the dump;
  - `tests/waterTanksCase/robtest_config.xml` and `run_rob.sh` exercise the
    feature;
  - `--debug-sat` gates the STLSAT logging.

### Open issues
1. **Semantics bugs.**
   - **Missing return values.** `Expression<AND, Proposition,
     Proposition>::evaluate_robustness` has no `return` (compiler warning,
     `Expression.cc:130`). Range propositions `(x >= a) && (x <= b)`,
     generated by `op="r"`, therefore have undefined robustness.
     `robtest_config.xml` uses `op="e,r,ge,le"`. The default
     `Atom::evaluate_robustness(){}` (`Atom.hh:33`) has the same problem.
   - **Accumulators start at 0 instead of ∓∞.**
     - `Eventually::evaluate_std_robustness` starts its `max` from 0, so
       ρ(F[a,b]φ) ≥ 0 always. Every template consequent is an `F`, and
       ρ(ant → con) = max(−ρ(ant), ρ(con)), so **standard robustness can
       never be negative**: it cannot flag a violated assertion.
     - The negative part of `TemporalOr`'s cumulative robustness is always 0
       for the same reason.
   - **No end-of-trace guard.** The Boolean `Eventually` returns `U` when its
     window crosses the end of the trace. The robustness loops have no such
     check and read `_v[i]` past the end of the signal arrays (no bounds
     check in `NumericVariable`). *(Observed)* the last rows of the
     water-tank dump look wrong: `stdrob` is constant at 0.6189 and `cumpos`
     keeps growing (28.5 → 29.2). In addition, when `time + a > length` the
     value 0 is returned, and it is included in both the mean and the
     minimum.
   - **"Tropical" is mostly a copy of "cumulative".** The two are identical
     in `Eventually` and `TemporalAnd`, and
     `TemporalNot::evaluate_tro_robustness` calls
     `evaluate_cum_robustness`. Only `Implication` and `TemporalOr` differ.
     The definitions should be tied to a reference and covered by tests.
   - **Boolean signals.** `Constant<bool>` has robustness +∞ for both `true`
     and `false`. Boolean and logic variables return 0/1, so a false Boolean
     has robustness 0 instead of a negative value.
   - **Offset assertions.** Only onset assertions get `fillRobustness`.
     Offset assertions keep an uninitialized `_robval`, because
     `robustnessStruct` has no default initializers.
2. **The predicted degeneracy is confirmed** *(observed)*. On
   `robtest_config.xml` (TankEmptying_OpenValve), all 3 assertions have
   `stdrob = 0`, `cumneg = 0` and the same `cumpos`. As a result, the final
   score is 0.00 for all three. Only the *mean* variants discriminate. The
   design questions remain open:
   - equality consequents (−|x−c| ≤ 0);
   - thresholds that sit on observed values;
   - normalization across signal units;
   - vacuity (combine with `atct`);
   - which of the 10 variants to recommend.

   None of the variants is documented in the README.
3. **The new normalization changes existing results.** Min–max now applies
   to every metric, not only robustness.
   - **Filters:** an assertion whose value equals the minimum is always
     filtered. If all assertions share a value (e.g. causality = 1.0, which
     is common), **all of them are filtered**, whatever the threshold.
   - **Sorting:** tied values all get `scoreFunction(0.1)`.
   - `max` is still initialized to 0, which is wrong for all-negative
     metrics (`cumneg`, `troneg`).
   - This breaks the reproducibility of the FDL 2024 results. Scope the new
     normalization to the robustness metrics.
4. **Cost.** Every mined assertion is evaluated in all 5 variants, at every
   time step and over every window, with no caching. This happens even when
   the config uses no robustness metric. For `Fuel_control` (203k rows,
   `maxd` 100) this matters. Compute robustness only when a robustness
   metric is referenced.
5. **Minor.**
   - The `values` vectors allocated for `--debug-rob` are never freed.
   - `--debug-rob` dereferences `assertions[0]` without checking that the
     list is not empty.
   - In `robtest_config.xml`, the `causality` sort is defined as
     `traceLength` (a constant), and the `mean_std_robustness` sort appears
     twice.
   - IDE-generated `.antlr/*.java` files are committed.

### Done when
- Unit tests on hand-written traces check each variant against values
  computed by hand, including violated assertions and end-of-trace windows.
- Existing configs give the same ranking as on `develop` when no robustness
  metric is used.
- The chosen variant(s) are documented, and on the benchmarks they
  measurably change the ranking compared with causality/support alone.

---

## 3. Filtering with STLSAT (`--remove-impl`)

### Goal
Remove redundant assertions: if mined assertion `b` implies `a`, keep only
`b`. Implication is checked with the external `stlsat` tool by testing that
`b && !a` is unsatisfiable.

### Current state
Implemented in
[Qualifier.cc:406-535](src/miner/modules/src/propertyQualification/qualifier/Qualifier.cc#L406-L535):
- a greedy O(n²) pass over the assertions;
- pairs are compared only when their proposition strings are identical
  (`same_props`);
- each comparison writes a temporary `.stl` file and calls `stlsat` through
  `popen`.

It runs after metric filtering and before sorting/truncation (`--max-ass`).

### Correctness issues (should be fixed first)
1. **The result parsing is fragile, and probably inverted.**
   `stlsatImplies` returns "implied" whenever the output does **not**
   contain the substring `false`
   ([:448](src/miner/modules/src/propertyQualification/qualifier/Qualifier.cc#L448)).
   - Current stlsat `master` prints `Tableau result: Some(false)` for
     **unsat**, which is exactly the case "implication holds". It prints
     `Some(true)` for sat. Against that format, the check is inverted.
   - The branch the code was developed against no longer exists (see 2), so
     it cannot be confirmed which format it targeted.
   - Quick check: run `tests/stlsat_test/wt_formulas.stl`. The expected
     result is unsat.
   - Independently of the format, any output without `false` is read as
     "implied" and the assertion is dropped silently. This includes a
     missing `stlsat` binary (`popen` still succeeds and stdout is empty),
     a parse error, and `None`/unknown. On `f_robustnesscalc`, a failed
     `popen` now aborts, but empty output is still read as "implied".
   - **Fix:** call `stlsat --smtlib-result`, treat only an exact `unsat` as
     "implied", and treat anything else as "keep both" with a warning. Also
     check the exit status from `pclose`.
2. **The installer is broken.**
   [install_stlsat.sh](third_party/install_stlsat.sh) runs
   `cargo install ... --branch fix`, but the `fix` branch no longer exists
   upstream (current branches: `master`, `recursive-pre-check`,
   `recursive-tableau`, `simplification`, `stl-dataset-gen`). Pin a commit
   or tag of `master`.
3. **Unsupported syntax is passed to stlsat.** stlsat accepts affine
   arithmetic with integers, non-negative decimals or fractions. SLAM can
   emit:
   - derivatives `@(x,1)`, which are used in the Gearbox and Heater configs;
   - non-affine products;
   - negative decimal constants (e.g. `error > -1`).

   Because of issue 1, each of these currently turns into a dropped
   assertion. Such assertions should be detected and skipped before calling
   stlsat.
4. **Semantic gap.**
   - SLAM evaluates over **discrete, finite traces** in which each row is
     one time unit.
   - The unbounded outer `G(` is textually replaced with `G[0,100](`
     ([:425](src/miner/modules/src/propertyQualification/qualifier/Qualifier.cc#L425)).
     The bound 100 is arbitrary: it is unrelated to the trace length and to
     `maxd`, and inner intervals already reach `F[63,140]`.
   - stlsat defaults to STL semantics but offers `--mltl` (finite-trace).

   It must be established which mode and which bound make "`b ⇒ a` in
   stlsat" sound with respect to SLAM's semantics.

### Effectiveness / engineering issues
5. **The pre-filter is too strict.** `same_props` requires identical
   proposition strings, so assertions that differ only by a threshold
   (`z <= 1.276` vs `z <= 1.29`) are never compared. Threshold relationships
   are the dominant redundancy in mined output (see
   [TankEmptying_OpenValve_ass.txt](tests/waterTanksCase/TankEmptying_OpenValve_ass.txt))
   and are exactly what an arithmetic-aware solver can decide. Pre-filter on
   the same variable set plus the same consequent instead.
6. **Scalability.**
   - Up to 2·n² process spawns, with no caching and no timeout. A hard
     instance (`--max-depth` defaults to 10⁶) can block SLAM indefinitely.
   - Options: run calls with a timeout and in parallel with `--max-threads`,
     and cache results per pair.
7. **Robustness of the integration.**
   - The fixed temp file `tempImplicationCheck.stl` in the working directory
     clobbers concurrent runs (e.g. `ctest -j`); use `mkstemp`.
   - `same_props` logs every pair at info level, giving O(n²) lines.
   - The `.stl` dump is gated by `--debug-cls`, which is the clustering debug
     flag. This is fixed on `f_robustnesscalc` (`--debug-sat`).
8. **Order dependence.** The greedy pass depends on input order. Among
   equivalent assertions, the first one encountered survives, not the
   best-ranked one. Running the filter after sorting would keep the
   higher-ranked one.

### Done when
- Unit tests cover the implied / not-implied / unsupported / tool-missing
  cases.
- The installer works from a clean machine.
- On the water-tank case, the reduced set is checked by hand to be a
  subset-minimal, equivalent cover.

---

## 4. New benchmarks

### Goal
A benchmark suite that supports (a) regression testing and (b) a credible
experimental evaluation of 1–3 against a ground truth and against other STL
miners.

### Current state
- **Registered in `ctest`**
  ([tests/CMakeLists.txt](tests/CMakeLists.txt)): water tanks, gearbox and
  heater (FDL 2024 cases), plus scalability variants produced by
  `--multiply-trace`. Replicating one trace does not add behavioural
  diversity.
- **On `develop`, added but not integrated:** the MATLAB/Simulink cases
  `Engine_timing`, `Fuel_control` (≈203k rows) and `Controlled_PU`.
  - They are not registered in `ctest`.
  - Their `run.sh` scripts use inconsistent hard-coded paths
    (`~/Slam/build/slam` vs `./slam`).
  - `Controlled_PU/CPU_config.xml` contains only a `check="1"` context;
    every mining context is commented out.
- **On `f_robustnesscalc`:**
  - the MATLAB cases are moved to `tests/Matlab_benchmarks/`;
  - `ABS` and a new `Gearbox` trace (fixed step, 0.04 s) are added, with
    their `.xlsx` sources;
  - `behavior.txt` notes describe the signals. These notes are informal and
    are not golden assertions.
- **No oracle.**
  - `ctest` tests pass on exit status alone; mined assertions are never
    compared with an expected result.
  - The gtest unit tests are commented out
    ([tests/CMakeLists.txt:3-13](tests/CMakeLists.txt#L3-L13)).

### Issues
1. **The ABS benchmark does not run** *(observed)*.
   - `ABS_trace.csv` uses `;` as the separator and decimal commas (`0,2`).
   - It has a column named `time`, which is a reserved token in the
     variable-declaration grammar.
   - SLAM rejects the header and then segfaults (exit 139). The parser
     should fail cleanly instead.
   - `ABS_config.xml` is a copy of the Gearbox config: it refers to
     `TransRPM` and `gear`, which are not in the ABS trace.
2. **Variable-step sampling.** The Simulink traces `Fuel_control` and
   `Engine_timing` come from variable-step solvers (`Fuel_Control.csv`:
   Δt ≈ 0.00056 s between the first two rows). SLAM treats each row as one
   time unit, so `F[a,b]` bounds count samples, not seconds. Mined bounds
   then have no physical meaning and cannot be compared with requirements
   stated in seconds. The time column (`ddd`/`cnt`, `timing`, `TIMES`) is
   also ingested as an ordinary signal. Either resample to a fixed step
   before mining, as the new Gearbox trace already does, or add a
   time-column option that converts intervals.
3. **No ground truth.** Without reference properties, "SLAM found good
   assertions" cannot be measured. Benchmarks that come with published STL
   requirements give this for free. The ARCH-COMP falsification benchmarks
   (e.g. Automatic Transmission, Abstract Fuel Control, Chasing Cars, Wind
   Turbine) are the obvious candidates, and the existing gearbox/fuel cases
   are close relatives. Once problem 3 is fixed, STLSAT can check
   automatically whether a mined assertion implies, or is implied by, a
   reference requirement.
4. **No held-out evaluation.** All assertions are mined and scored on the
   same trace. Mine on one set of traces and measure false alarms on
   another; `--csv-dir` already supports multiple traces.
5. **No baselines.** Candidate comparisons:
   - requirement mining with Breach (Jin et al., HSCC 2013), which also uses
     the fuel-control model;
   - decision-tree STL classifiers (Bombara et al., HSCC 2016);
   - TeLEx (Jha et al., FMSD 2019).

### Proposed metrics
- Runtime and memory.
- Number of assertions before and after `--remove-impl`.
- Recall of the reference requirements.
- False-alarm rate on held-out traces.
- Robustness margin, once 2 is stable.

### Done when
- Every benchmark in `tests/` is registered in `ctest` and has a fixed-step
  trace, a documented config and an expected-output file that the test
  compares against.
- At least two benchmarks have reference requirements.

---

## Integrating the feature branches

A trial merge of `f_STLG` into `f_robustnesscalc` (`git merge-tree`) shows:

- **One textual conflict:** `AntecedentGenerator.cc`.
- **Auto-merged files that still need review**, because both branches change
  them: `TLMiner.cc`, `Template.hh`, `Template.cc` and
  `AntecedentGenerator.hh`. `f_STLG` also changes the `DTOperator` signature
  used throughout.
- **A guaranteed build break:** `f_robustnesscalc` adds three pure-virtual
  robustness methods to `TemporalExp`, and `Globally` from `f_STLG` does not
  implement them. Standard robustness for `G` is the minimum over the
  window; the cumulative and tropical variants must be defined.
- **`examples/` would be deleted** by `f_STLG` (see 1.8).

Suggested order:
1. Fix the `f_STLG` build and the offset bug.
2. Restore `examples/`.
3. Merge.
4. Add `Globally` robustness.
5. Run both features on the same benchmarks.

---

## Related housekeeping

- **Derivatives at the end of the trace (pre-existing on `develop`).**
  `@(x,k)` returns the value of `x` itself on the last `k` samples
  ([Derivative.cc:19-20,29-30](src/exp/src/classes/expression/Derivative.cc#L19-L30)),
  not a difference or `U`. This affects every template that uses
  derivatives (e.g. `@(d,1) > 0`), in both Boolean and robustness
  evaluation.
- **The build fails with CMake ≥ 4** *(observed with 4.3.2)*. The vendored
  googletest declares `cmake_minimum_required` < 3.5. Workaround:
  `-DCMAKE_POLICY_VERSION_MINIMUM=3.5`. Fix: bump googletest or the
  minimum version.
- **Leftover fault-based qualification.** Fault-based qualification was
  removed in `32dca10`, but:
  - `--fd`, `--ftm`, `--find-min-subset` and `--sva` are still accepted
    ([commandLineParser.cc](src/commandLineParser/src/commandLineParser.cc),
    [main.cc:120-196](src/main.cc#L120-L196)) and documented in the README;
  - the faulty traces are orphaned: [CPU_faulty.csv](CPU_faulty.csv) at the
    repo root, `tests/waterTanksCase/faulty/`,
    `tests/Controlled_PU/CPU_faulty.csv` and `run_faulty.sh`.
- **Stray files.** `tests/Controlled_PU/export.csv:Zone.Identifier` is
  Windows metadata, and the `tree.dot`/`vac.txt` debug outputs are committed
  in several test folders and, on `f_STLG`, at the repo root.
