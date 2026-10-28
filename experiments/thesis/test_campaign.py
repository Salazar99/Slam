"""Smallest checks of the campaign plumbing: python test_campaign.py"""
from fractions import Fraction

from common import check_on_traces, scores, to_fragment
from score import summarize
from s6_llm import to_formula

truth = "T >= 16.2 -> Status == 0"
# SLAM line -> fragment, @(x,k) -> x_dk
assert to_fragment("G(F[0,0]((T >= 16.2)) -> F[0,0]((@(T,1) == 0)))") == "F[0,0]((T >= 16.2)) -> F[0,0]((T_d1 == 0))"
# best-G of a formula against a set containing itself is 1, a perturbed one scores below 1
sc = scores([(truth, truth), (truth, "T >= 16 -> Status == 0")], Fraction(17))
assert abs(sc[(truth, truth)]["G"] - 1) < 1e-9
assert 0 < sc[(truth, "T >= 16 -> Status == 0")]["G"] < 1
# the requirement holds on its trace and is triggered
assert check_on_traces(truth, "Heater") == (0, 36)
# an implication nested under G[a,b] is checked (no trigger count) instead of raising
assert check_on_traces("G[0,1](T >= 16.2 -> Status == 0)", "Heater") == (0, 0)
# LLM answers: constant-first comparisons are flipped, signal names ending in digits untouched
assert to_formula("16.2 <= T && x_d1 > 0 -> F[0,1] Status == 0") == "T >= 16.2 && x_d1 > 0 -> F[0,1] Status == 0"
# coverage: 2 requirements, one exact, one at 0.95
rows = [dict(case="Heater", source="x", sample=0, best_G=1.0), dict(case="Heater", source="x", sample=0, best_G=0.95)]
t = summarize([dict(case="Heater", encodable="yes")] * 2, rows)[0]
assert t["cov@1"] == 0.5 and t["cov@0.9"] == 1.0 and abs(t["meanG"] - 0.975) < 1e-9
print("ok")
