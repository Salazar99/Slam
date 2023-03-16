
// Generated from stl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  stlLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, STL_EVENTUALLY = 7, 
    STL_ALWAYS = 8, RELEASE = 9, IMPL = 10, SCOL = 11, COL = 12, COMMA = 13, 
    FIRST_MATCH = 14, SIGN = 15, LGPAREN = 16, RGPAREN = 17, LCPAREN = 18, 
    RCPAREN = 19, LPAREN = 20, RPAREN = 21, VARIABLE = 22, NUMERIC = 23, 
    VERILOG_BINARY = 24, GCC_BINARY = 25, HEX = 26, BOOLEAN = 27, PLUS = 28, 
    MINUS = 29, TIMES = 30, DIV = 31, GT = 32, GE = 33, LT = 34, LE = 35, 
    EQ = 36, NEQ = 37, BAND = 38, BOR = 39, BXOR = 40, NEG = 41, LSHIFT = 42, 
    RSHIFT = 43, AND = 44, OR = 45, NOT = 46, WS = 47
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

