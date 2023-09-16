SET(NAME templateParser)

add_subdirectory(grammarSVA)
add_subdirectory(grammarSTL)
add_subdirectory(handler)


add_library(${NAME} INTERFACE)
target_include_directories(${NAME} INTERFACE ./)
target_link_libraries(${NAME} INTERFACE antlr4SVAParserGrammar antlr4StlParserGrammar antlr4TemplateParserHandler)

