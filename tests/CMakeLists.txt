message("-- Including test cases...")

#add_executable(gtests ./traceTests.cc ./evalTests.cc)
#target_link_libraries(gtests gtest_main stdc++fs all_utils progresscpp logging exp commandLineParser templateParser miner )

set(WORK_DIR ${CMAKE_BINARY_DIR})
set(TEST_DIR ${CMAKE_BINARY_DIR}/../tests)


#tests
#add_test(NAME AllTests COMMAND gtests WORKING_DIRECTORY ${WORK_DIR})
#add_test(NAME TraceTest COMMAND gtests --gtest_filter=TraceTest* WORKING_DIRECTORY ${WORK_DIR})
#add_test(NAME EvalTest COMMAND gtests --gtest_filter=EvalTest* WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME tank COMMAND ex-harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90  --dump-stat --divide-stat WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME gear COMMAND ex-harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat --divide-stat WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME heater COMMAND ex-harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat --divide-stat WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME heater_1k COMMAND ex-harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat --multiply-trace 1 --name heater_1k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME heater_10k COMMAND ex-harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat --multiply-trace 10 --name heater_10k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME heater_100k COMMAND ex-harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat --multiply-trace 100 --name heater_100k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME heater_1000k COMMAND ex-harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat --multiply-trace 1000 --name heater_1000k WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME gear_1k COMMAND ex-harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat --multiply-trace 1 --name gear_1k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME gear_10k COMMAND ex-harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat --multiply-trace 10 --name gear_10k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME gear_100k COMMAND ex-harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat --multiply-trace 100 --name gear_100k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME gear_1000k COMMAND ex-harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat --multiply-trace 1000 --name gear_1000k WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME tank_1k COMMAND ex-harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90 --dump-stat --multiply-trace 1 --name tank_1k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME tank_10k COMMAND ex-harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90 --dump-stat --multiply-trace 10 --name tank_10k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME tank_100k COMMAND ex-harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90 --dump-stat --multiply-trace 100 --name tank_100k WORKING_DIRECTORY ${WORK_DIR})
add_test(NAME tank_1000k COMMAND ex-harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90 --dump-stat --multiply-trace 1000 --name tank_1000k WORKING_DIRECTORY ${WORK_DIR})

