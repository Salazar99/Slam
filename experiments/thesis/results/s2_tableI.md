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
| absbrake | slip_limit | - | vs (le,ge, 0.01), ww (le,ge, 0.01) | `G( ..F.. -> F[0,0](slip <= 0.3))` | 3A,0.1E,100maxd,0mind | 10540 |
| absbrake | deceleration | - | vs (le,ge, 0.01), slip (le,ge, 0.01) | `G( ..F.. -> F[0,0](@(vs,1) < 0))` | 3A,0.1E,100maxd,0mind | 10540 |
| absbrake | distance | - | vs (le,ge, 0.01) | `G( ..F.. -> F[0,0](@(sd,1) > 0))` | 3A,0.1E,100maxd,0mind | 10540 |
| autotrans | speed_limit | - | rpm (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](speed < 120))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | rpm_limit | - | speed (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](rpm < 4750))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | gear1 | - | speed (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](gear == 1))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | gear2 | - | speed (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](gear == 2))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | gear3 | - | speed (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](gear == 3))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | gear4 | - | speed (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](gear == 4))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | speed_below_35 | - | rpm (le, 0.01) | `G( ..F.. -> F[0,0](speed < 35))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | speed_below_50 | - | rpm (le, 0.01) | `G( ..F.. -> F[0,0](speed < 50))` | 3A,0.1E,100maxd,0mind | 12040 |
| autotrans | speed_below_65 | - | rpm (le, 0.01) | `G( ..F.. -> F[0,0](speed < 65))` | 3A,0.1E,100maxd,0mind | 12040 |
| fuelsys | afr_regulation | - | map (le,ge, 0.01), throttle (le,ge, 0.01), speed (le,ge, 0.01) | `G( ..F.. -> F[0,0](afr >= 14 && afr <= 15.2))` | 3A,0.1E,100maxd,0mind | 5620 |
| fuelsys | fuel_on | - | map (le,ge, 0.01), throttle (le,ge, 0.01) | `G( ..F.. -> F[0,0](fuel > 0))` | 3A,0.1E,100maxd,0mind | 5620 |
| fuelsys | map_rise | - | throttle (le,ge, 0.01), map (le,ge, 0.01) | `G( ..F.. -> F[0,0](@(map,1) > 0))` | 3A,0.1E,100maxd,0mind | 5620 |
| fuelsys | fuel_fall | - | throttle (le,ge, 0.01), map (le,ge, 0.01) | `G( ..F.. -> F[0,0](@(fuel,1) < 0))` | 3A,0.1E,100maxd,0mind | 5620 |
| househeat | comfort | - | tout (le,ge, 0.01) | `G( ..F.. -> F[0,0](tin >= 64.9 && tin <= 75.1))` | 3A,0.1E,100maxd,0mind | 57620 |
| househeat | heater_on | - | tin (le,ge, 0.01), tout (le,ge, 0.01) | `G( ..F.. -> F[0,0](heater == 1))` | 3A,0.1E,100maxd,0mind | 57620 |
| househeat | heater_off | - | tin (le,ge, 0.01), tout (le,ge, 0.01) | `G( ..F.. -> F[0,0](heater == 0))` | 3A,0.1E,100maxd,0mind | 57620 |
| househeat | no_cost | - | heater (le,ge, 0.01), tin (le,ge, 0.01) | `G( ..F.. -> F[0,0](@(cost,1) == 0))` | 3A,0.1E,100maxd,0mind | 57620 |
