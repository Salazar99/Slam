
// Generated from stl.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  stlParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, DT_AND = 7, 
    STL_EVENTUALLY = 8, STL_ALWAYS = 9, RELEASE = 10, IMPL = 11, SCOL = 12, 
    COL = 13, COMMA = 14, FIRST_MATCH = 15, SIGN = 16, LGPAREN = 17, RGPAREN = 18, 
    LCPAREN = 19, RCPAREN = 20, LPAREN = 21, RPAREN = 22, VARIABLE = 23, 
    NUMERIC = 24, VERILOG_BINARY = 25, GCC_BINARY = 26, HEX = 27, BOOLEAN = 28, 
    PLUS = 29, MINUS = 30, TIMES = 31, DIV = 32, GT = 33, GE = 34, LT = 35, 
    LE = 36, EQ = 37, NEQ = 38, BAND = 39, BOR = 40, BXOR = 41, NEG = 42, 
    LSHIFT = 43, RSHIFT = 44, AND = 45, OR = 46, NOT = 47, WS = 48
  };

  enum {
    RuleFile = 0, RuleFormula = 1, RuleTformula = 2, RulePlaceholder = 3, 
    RuleInterval = 4, RuleBoolean = 5, RuleBooleanAtom = 6, RuleBooleanConstant = 7, 
    RuleBooleanVariable = 8, RuleLogic = 9, RuleBitSelect = 10, RuleLogicAtom = 11, 
    RuleLogicConstant = 12, RuleLogicVariable = 13, RuleNumeric = 14, RuleNumericAtom = 15, 
    RuleNumericConstant = 16, RuleNumericVariable = 17, RuleVariable = 18, 
    RuleRelop = 19
  };

  stlParser(antlr4::TokenStream *input);
  ~stlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class FormulaContext;
  class TformulaContext;
  class PlaceholderContext;
  class IntervalContext;
  class BooleanContext;
  class BooleanAtomContext;
  class BooleanConstantContext;
  class BooleanVariableContext;
  class LogicContext;
  class BitSelectContext;
  class LogicAtomContext;
  class LogicConstantContext;
  class LogicVariableContext;
  class NumericContext;
  class NumericAtomContext;
  class NumericConstantContext;
  class NumericVariableContext;
  class VariableContext;
  class RelopContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STL_ALWAYS();
    FormulaContext *formula();
    antlr4::tree::TerminalNode *EOF();
    antlr4::tree::TerminalNode *LCPAREN();
    std::vector<IntervalContext *> interval();
    IntervalContext* interval(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FileContext* file();

  class  FormulaContext : public antlr4::ParserRuleContext {
  public:
    FormulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TformulaContext *> tformula();
    TformulaContext* tformula(size_t i);
    antlr4::tree::TerminalNode *IMPL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FormulaContext* formula();

  class  TformulaContext : public antlr4::ParserRuleContext {
  public:
    TformulaContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanContext *boolean();
    PlaceholderContext *placeholder();
    antlr4::tree::TerminalNode *DT_AND();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<TformulaContext *> tformula();
    TformulaContext* tformula(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *NOT();
    antlr4::tree::TerminalNode *STL_EVENTUALLY();
    antlr4::tree::TerminalNode *LCPAREN();
    std::vector<IntervalContext *> interval();
    IntervalContext* interval(size_t i);
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TformulaContext* tformula();
  TformulaContext* tformula(int precedence);
  class  PlaceholderContext : public antlr4::ParserRuleContext {
  public:
    PlaceholderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PlaceholderContext* placeholder();

  class  IntervalContext : public antlr4::ParserRuleContext {
  public:
    IntervalContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntervalContext* interval();

  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *booleanop = nullptr;;
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    std::vector<BooleanContext *> boolean();
    BooleanContext* boolean(size_t i);
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    RelopContext *relop();
    std::vector<NumericContext *> numeric();
    NumericContext* numeric(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    BooleanAtomContext *booleanAtom();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanContext* boolean();
  BooleanContext* boolean(int precedence);
  class  BooleanAtomContext : public antlr4::ParserRuleContext {
  public:
    BooleanAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanConstantContext *booleanConstant();
    BooleanVariableContext *booleanVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanAtomContext* booleanAtom();

  class  BooleanConstantContext : public antlr4::ParserRuleContext {
  public:
    BooleanConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanConstantContext* booleanConstant();

  class  BooleanVariableContext : public antlr4::ParserRuleContext {
  public:
    BooleanVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanVariableContext* booleanVariable();

  class  LogicContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;;
    antlr4::Token *logop = nullptr;;
    LogicContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NEG();
    std::vector<LogicContext *> logic();
    LogicContext* logic(size_t i);
    LogicAtomContext *logicAtom();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *LSHIFT();
    antlr4::tree::TerminalNode *RSHIFT();
    antlr4::tree::TerminalNode *BAND();
    antlr4::tree::TerminalNode *BXOR();
    antlr4::tree::TerminalNode *BOR();
    BitSelectContext *bitSelect();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicContext* logic();
  LogicContext* logic(int precedence);
  class  BitSelectContext : public antlr4::ParserRuleContext {
  public:
    BitSelectContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCPAREN();
    std::vector<antlr4::tree::TerminalNode *> NUMERIC();
    antlr4::tree::TerminalNode* NUMERIC(size_t i);
    antlr4::tree::TerminalNode *RCPAREN();
    antlr4::tree::TerminalNode *COL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BitSelectContext* bitSelect();

  class  LogicAtomContext : public antlr4::ParserRuleContext {
  public:
    LogicAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicConstantContext *logicConstant();
    LogicVariableContext *logicVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicAtomContext* logicAtom();

  class  LogicConstantContext : public antlr4::ParserRuleContext {
  public:
    LogicConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERILOG_BINARY();
    antlr4::tree::TerminalNode *GCC_BINARY();
    antlr4::tree::TerminalNode *NUMERIC();
    antlr4::tree::TerminalNode *HEX();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicConstantContext* logicConstant();

  class  LogicVariableContext : public antlr4::ParserRuleContext {
  public:
    LogicVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();
    antlr4::tree::TerminalNode *SIGN();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LogicVariableContext* logicVariable();

  class  NumericContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *artop = nullptr;;
    NumericContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericAtomContext *numericAtom();
    LogicContext *logic();
    antlr4::tree::TerminalNode *LPAREN();
    std::vector<NumericContext *> numeric();
    NumericContext* numeric(size_t i);
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericContext* numeric();
  NumericContext* numeric(int precedence);
  class  NumericAtomContext : public antlr4::ParserRuleContext {
  public:
    NumericAtomContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumericConstantContext *numericConstant();
    NumericVariableContext *numericVariable();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericAtomContext* numericAtom();

  class  NumericConstantContext : public antlr4::ParserRuleContext {
  public:
    NumericConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericConstantContext* numericConstant();

  class  NumericVariableContext : public antlr4::ParserRuleContext {
  public:
    NumericVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LT();
    VariableContext *variable();
    antlr4::tree::TerminalNode *NUMERIC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumericVariableContext* numericVariable();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  RelopContext : public antlr4::ParserRuleContext {
  public:
    RelopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *GE();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *LE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelopContext* relop();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool tformulaSempred(TformulaContext *_localctx, size_t predicateIndex);
  bool booleanSempred(BooleanContext *_localctx, size_t predicateIndex);
  bool logicSempred(LogicContext *_localctx, size_t predicateIndex);
  bool numericSempred(NumericContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

