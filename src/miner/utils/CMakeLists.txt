SET(NAME miner_utils)
project(${NAME})


#############################################
# Sources.
#############################################

SET(MINER_UTILS_SRC src/Trace.cc src/DataType.cc src/Template.cc
    src/Automaton.cc
    src/TemplateEval.cc
	src/PermGenerator.cc
    #	src/Hstring.cc  
    src/EdgeProposition.cc
    src/DTAndF.cc
    src/minerUtils.cc
    src/Context.cc
    src/Assertion.cc
    src/DTUtils.cc
    )

#############################################
# Targets.
#############################################
add_library(${NAME} ${MINER_UTILS_SRC})
target_link_libraries(${NAME} fort clustering)


