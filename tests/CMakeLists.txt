message("-- Including test cases...")

#add_executable(gtests ./traceTests.cc ./evalTests.cc)
#target_link_libraries(gtests gtest_main stdc++fs all_utils progresscpp logging exp commandLineParser templateParser miner )

set(WORK_DIR ${CMAKE_BINARY_DIR})
set(TEST_DIR ${CMAKE_BINARY_DIR}/../tests)


#tests
#add_test(NAME AllTests COMMAND gtests WORKING_DIRECTORY ${WORK_DIR})
#add_test(NAME TraceTest COMMAND gtests --gtest_filter=TraceTest* WORKING_DIRECTORY ${WORK_DIR})
#add_test(NAME EvalTest COMMAND gtests --gtest_filter=EvalTest* WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME tank COMMAND harm --csv ${TEST_DIR}/waterTanksCase/Trace_final.csv --conf ${TEST_DIR}/waterTanksCase/WT_config.xml --min-final 0.90  --dump-stat WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME gear COMMAND harm --csv ${TEST_DIR}/gearboxCase/trace_gearbox_Date.csv --conf ${TEST_DIR}/gearboxCase/Gearbox_config.xml --min-final 0.90  --dump-stat WORKING_DIRECTORY ${WORK_DIR})

add_test(NAME heater COMMAND harm --csv ${TEST_DIR}/HeaterCase/HT_trace.csv --conf ${TEST_DIR}/HeaterCase/HT_config.xml --min-final 0.90  --dump-stat WORKING_DIRECTORY ${WORK_DIR})
