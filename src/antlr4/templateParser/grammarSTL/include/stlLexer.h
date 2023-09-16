
// Generated from stl.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"




class  stlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    DT_ANDF = 8, STL_EVENTUALLY = 9, STL_ALWAYS = 10, RELEASE = 11, IMPL = 12, 
    SCOL = 13, COL = 14, COMMA = 15, FIRST_MATCH = 16, SIGN = 17, DER = 18, 
    LCPAREN = 19, RCPAREN = 20, LPAREN = 21, RPAREN = 22, VARIABLE = 23, 
    NUMERIC = 24, VERILOG_BINARY = 25, GCC_BINARY = 26, HEX = 27, BOOLEAN = 28, 
    PLUS = 29, MINUS = 30, TIMES = 31, DIV = 32, GT = 33, GE = 34, LT = 35, 
    LE = 36, EQ = 37, NEQ = 38, BAND = 39, BOR = 40, BXOR = 41, NEG = 42, 
    LSHIFT = 43, RSHIFT = 44, AND = 45, OR = 46, NOT = 47, WS = 48
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

