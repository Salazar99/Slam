| Benchmark | Context | P (prop) | NE (numeric, op, th) | Template | dtLimits | Trace length |
|---|---|---|---|---|---|---|
| WaterTanks | TankEmptying_OpenValve | - | z (le, 0.01), d (ge, 0.01) | `G( ..F.. -> F[0,0]a==1)` | 3A,0.1E,100maxd,0mind | 1001 |
| WaterTanks | ValveClose_SecondaryTankFilling | - | a (e,r,ge,le, 0.001) | `G( (..F..) -> F[0,0]( @(d,1) > 0 ))` | 1A,0.1E,100maxd | 1001 |
| WaterTanks | ValveOpen_SecondaryTankEmptying | - | a (ge, 0.001) | `G( (..F..) -> F[0,0](@(d,1) < 0 || d<=0.1 ))` | 1A,0.1E,10maxd | 1001 |
| WaterTanks | MainTankEmptying | - | a (r,e,ge,le, 0.001), rain (r,e,ge,le, 0.001), d (r,e,ge,le, 0.001) | `G( (..F..) -> F[0,0](@(z,1) < 0))` | 3A,0.1E,20maxd | 1001 |
| WaterTanks | MainTankFilling | - | a (ge,le, 0.001), rain (ge,le, 0.001), d (ge,le, 0.001) | `G( (..F..) -> F[0,0](@(z,1) > 0))` | 3A,0.1E,100maxd | 1001 |
| Gearbox | threshold_gear1 | - | omega (r,e, 0.01), throttle (r,e, 0.01) | `G( ..F.. -> F[0,0](gear==1))` | 3A,0.1E,100maxd,0mind | 1001 |
| Gearbox | threshold_gear4 | - | omega (ge, 0.01), throttle (r,e, 0.01) | `G( ..F.. -> F[0,0](gear==4))` | 3A,0.1E,100maxd,0mind | 1001 |
| Gearbox | threshold_gear3 | - | omega (r,e, 0.01), throttle (r,e, 0.01) | `G( ..F.. -> F[0,0](gear==3))` | 3A,0.1E,100maxd,0mind | 1001 |
| Gearbox | threshold_gear2 | - | omega (r,e, 0.01), throttle (r,e, 0.01) | `G( ..F.. -> F[0,0](gear==2))` | 3A,0.1E,100maxd,0mind | 1001 |
| Gearbox | theta_increasing | - | omega (ge, 0.01) | `G( ..F.. -> F[0,0](@(theta,1) > 0))` | 3A,0.1E,100maxd,0mind | 1001 |
| Gearbox | theta_stable | - | omega (ge, 0.01) | `G( ..F.. -> F[0,0](@(theta,1) == 0))` | 3A,0.1E,100maxd,0mind | 1001 |
| Heater | threshold_heateron | - | T (le,ge, 0.01), C (le,ge,r, 0.01) | `G( ..F.. -> F[0,0](Status==1))` | 2A,0E,50maxd,0mind | 1001 |
| Heater | threshold_heater_off | - | T (ge, 0.01) | `G( ..F.. -> F[0,0](Status==0))` | 3A,0.1E,100maxd,0mind | 1001 |
| Heater | threshold_heater_night | - | Status (e, 0.01), C (le, 0.01) | `G( ..F.. -> F[0,0](@(T,1)==0))` | 2A,0.45E,100maxd,0mind | 1001 |
| absbrake | slip_limit | - | vs (le,ge, 0.001) | `G( ..F.. -> F[0,0](slip <= 0.3))` | 1A,0.1E,100maxd,0mind | 10540 |
| absbrake | deceleration | - | vs (le,ge, 0.001), slip (le,ge, 0.001) | `G( ..F.. -> F[0,0](@(vs,1) < 0))` | 3A,0.1E,0maxd,0mind | 10540 |
| absbrake | distance | - | vs (le,ge, 0.001) | `G( ..F.. -> F[0,0](@(sd,1) > 0))` | 1A,0.1E,5maxd,0mind | 10540 |
| autotrans | shift_gear1 | - | speed (le,ge, 0.1) | `G( ..F.. -> F[0,0](gear == 1))` | 1A,0.1E,0maxd,0mind | 12040 |
| autotrans | shift_gear2up | - | speed (le,ge, 0.001) | `G( ..F.. -> F[0,0](gear >= 2))` | 1A,0.1E,100maxd,0mind | 12040 |
| autotrans | shift_gear3up | - | speed (le,ge, 0.1) | `G( ..F.. -> F[0,0](gear >= 3))` | 1A,0.1E,20maxd,0mind | 12040 |
| autotrans | shift_gear4 | - | speed (le,ge, 0.001) | `G( ..F.. -> F[0,0](gear == 4))` | 1A,0.1E,0maxd,0mind | 12040 |
| fuelsys | ego_rich | - | afr (le,ge, 0.001) | `G( ..F.. -> F[0,0](ego > 0.5))` | 1A,0.1E,0maxd,0mind | 5620 |
| fuelsys | ego_lean | - | afr (le,ge, 0.001) | `G( ..F.. -> F[0,0](ego < 0.5))` | 1A,0.1E,0maxd,0mind | 5620 |
| househeat | heater_on | - | tin (le,ge, 0.001) | `G( ..F.. -> F[0,0](heater == 1))` | 1A,0.1E,5maxd,0mind | 57620 |
| househeat | heater_off | - | tin (le,ge, 0.001) | `G( ..F.. -> F[0,0](heater == 0))` | 1A,0.1E,0maxd,0mind | 57620 |
| househeat | no_cost | - | heater (le,ge, 0.001) | `G( ..F.. -> F[0,0](@(cost,1) == 0))` | 1A,0.1E,100maxd,0mind | 57620 |
