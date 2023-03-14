
// Generated from stl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  stlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, EVENTUALLY = 7, 
    STL_ALWAYS = 8, RELEASE = 9, IMPL = 10, SCOL = 11, COL = 12, FIRST_MATCH = 13, 
    SIGN = 14, LGPAREN = 15, RGPAREN = 16, LCPAREN = 17, RCPAREN = 18, LPAREN = 19, 
    RPAREN = 20, VARIABLE = 21, NUMERIC = 22, VERILOG_BINARY = 23, GCC_BINARY = 24, 
    HEX = 25, BOOLEAN = 26, PLUS = 27, MINUS = 28, TIMES = 29, DIV = 30, 
    GT = 31, GE = 32, LT = 33, LE = 34, EQ = 35, NEQ = 36, BAND = 37, BOR = 38, 
    BXOR = 39, NEG = 40, LSHIFT = 41, RSHIFT = 42, AND = 43, OR = 44, NOT = 45, 
    WS = 46
  };

  stlLexer(antlr4::CharStream *input);
  ~stlLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

