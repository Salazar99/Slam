
// Generated from stl.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  stlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    DT_ANDF = 8, DT_ANDG = 9, STL_EVENTUALLY = 10, STL_ALWAYS = 11, RELEASE = 12, 
    IMPL = 13, SCOL = 14, COL = 15, COMMA = 16, FIRST_MATCH = 17, SIGN = 18, 
    DER = 19, LCPAREN = 20, RCPAREN = 21, LPAREN = 22, RPAREN = 23, VARIABLE = 24, 
    NUMERIC = 25, VERILOG_BINARY = 26, GCC_BINARY = 27, HEX = 28, BOOLEAN = 29, 
    PLUS = 30, MINUS = 31, TIMES = 32, DIV = 33, GT = 34, GE = 35, LT = 36, 
    LE = 37, EQ = 38, NEQ = 39, BAND = 40, BOR = 41, BXOR = 42, NEG = 43, 
    LSHIFT = 44, RSHIFT = 45, AND = 46, OR = 47, NOT = 48, WS = 49
  };

  explicit stlLexer(antlr4::CharStream *input);

  ~stlLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

