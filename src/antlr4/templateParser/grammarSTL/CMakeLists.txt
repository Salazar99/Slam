#############################################
# Configuration.
#############################################

SET(NAME antlr4StlParserGrammar)


#############################################
# Sources.
#############################################
SET (ANTLR4_STL_PARSER_GRAMMAR
     src/stlLexer.cpp
     src/stlParser.cpp
     src/stlListener.cpp
     src/stlBaseListener.cpp
     )

 set_source_files_properties(
     ${ANTLR4_STL_PARSER_GRAMMAR}
     PROPERTIES
     COMPILE_FLAGS "-w"
     )

#############################################
# Targets.
#############################################
add_library(${NAME} ${ANTLR4_STL_PARSER_GRAMMAR})
target_include_directories(${NAME} PUBLIC
    include/
    ${ANTLR4CPP_INCLUDE_DIRS}
)
target_link_libraries(${NAME} ${ANTLR4_RUNTIME})


