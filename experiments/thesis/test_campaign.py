"""Smallest checks of the campaign plumbing: python test_campaign.py"""
from fractions import Fraction

from common import check_on_traces, scores, to_fragment
from score import per_requirement, summarize
from s6_llm import to_formula

truth = "T >= 16.2 -> Status == 0"
# SLAM line -> fragment, @(x,k) -> x_dk
assert to_fragment("G(F[0,0]((T >= 16.2)) -> F[0,0]((@(T,1) == 0)))") == "F[0,0]((T >= 16.2)) -> F[0,0]((T_d1 == 0))"
# SLAM prints float32 constants (16.200001 = float32(16.2)): written back as the value SLAM compares with
assert to_fragment("G(F[0,0]((T >= 16.200001)) -> F[0,0]((Status == 1.000000)))") == "F[0,0]((T >= 16.2)) -> F[0,0]((Status == 1))"
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
rows = [dict(case="Heater", source="x", sample=0, best_G=1.0, covered=1),
        dict(case="Heater", source="x", sample=0, best_G=0.95, covered=0)]
t = summarize([dict(case="Heater", encodable="yes")] * 2, rows)[0]
assert t["cov@1"] == 0.5 and t["cov@0.9"] == 1.0 and abs(t["meanG"] - 0.975) < 1e-9 and t["cov_paper"] == 0.5
# paper coverage: a holding, triggered assertion of the requirement's own context covers it; another context does not
req = [dict(case="Heater", req_id="HT2", context="off", stl=truth, encodable="yes")]
cand = dict(case="Heater", source="x", sample="0", formula=truth)
assert per_requirement(req, [{**cand, "context": "off"}])[0]["covered"] == 1
assert per_requirement(req, [{**cand, "context": "on"}])[0]["covered"] == 0
print("ok")
