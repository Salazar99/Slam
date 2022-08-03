
// Generated from spot.g4 by ANTLR 4.10.1

#pragma once


#include "antlr4-runtime.h"




class  spotLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, DT_AND = 10, SEP = 11, EVENTUALLY = 12, ALWAYS = 13, 
    NEXT = 14, UNTIL = 15, RELEASE = 16, DOTS = 17, IMPL = 18, IMPL2 = 19, 
    IFF = 20, XOR = 21, BIND1 = 22, BIND2 = 23, SEREIMPL1 = 24, SEREIMPL2 = 25, 
    ASS = 26, DELAY = 27, SCOL = 28, COL = 29, FIRST_MATCH = 30, SIGN = 31, 
    LGPAREN = 32, RGPAREN = 33, LCPAREN = 34, RCPAREN = 35, LPAREN = 36, 
    RPAREN = 37, VARIABLE = 38, NUMERIC = 39, VERILOG_BINARY = 40, GCC_BINARY = 41, 
    HEX = 42, BOOLEAN = 43, PLUS = 44, MINUS = 45, TIMES = 46, DIV = 47, 
    GT = 48, GE = 49, LT = 50, LE = 51, EQ = 52, NEQ = 53, BAND = 54, BOR = 55, 
    BXOR = 56, NEG = 57, LSHIFT = 58, RSHIFT = 59, AND = 60, OR = 61, NOT = 62, 
    WS = 63
  };

  explicit spotLexer(antlr4::CharStream *input);

  ~spotLexer() override;


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

