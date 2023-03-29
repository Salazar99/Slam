
// Generated from stl.g4 by ANTLR 4.7.2


#include "stlListener.h"

#include "stlParser.h"


using namespace antlrcpp;
using namespace antlr4;

stlParser::stlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

stlParser::~stlParser() {
  delete _interpreter;
}

std::string stlParser::getGrammarFileName() const {
  return "stl.g4";
}

const std::vector<std::string>& stlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& stlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

stlParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::FileContext::STL_ALWAYS() {
  return getToken(stlParser::STL_ALWAYS, 0);
}

stlParser::FormulaContext* stlParser::FileContext::formula() {
  return getRuleContext<stlParser::FormulaContext>(0);
}

tree::TerminalNode* stlParser::FileContext::EOF() {
  return getToken(stlParser::EOF, 0);
}

tree::TerminalNode* stlParser::FileContext::LCPAREN() {
  return getToken(stlParser::LCPAREN, 0);
}

std::vector<stlParser::IntervalContext *> stlParser::FileContext::interval() {
  return getRuleContexts<stlParser::IntervalContext>();
}

stlParser::IntervalContext* stlParser::FileContext::interval(size_t i) {
  return getRuleContext<stlParser::IntervalContext>(i);
}

tree::TerminalNode* stlParser::FileContext::COMMA() {
  return getToken(stlParser::COMMA, 0);
}

tree::TerminalNode* stlParser::FileContext::RCPAREN() {
  return getToken(stlParser::RCPAREN, 0);
}

tree::TerminalNode* stlParser::FileContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

tree::TerminalNode* stlParser::FileContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}


size_t stlParser::FileContext::getRuleIndex() const {
  return stlParser::RuleFile;
}

void stlParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void stlParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

stlParser::FileContext* stlParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, stlParser::RuleFile);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(55);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(40);
      match(stlParser::STL_ALWAYS);
      setState(41);
      formula();
      setState(42);
      match(stlParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(44);
      match(stlParser::STL_ALWAYS);
      setState(45);
      match(stlParser::LCPAREN);
      setState(46);
      interval();
      setState(47);
      match(stlParser::COMMA);
      setState(48);
      interval();
      setState(49);
      match(stlParser::RCPAREN);
      setState(50);
      match(stlParser::LPAREN);
      setState(51);
      formula();
      setState(52);
      match(stlParser::RPAREN);
      setState(53);
      match(stlParser::EOF);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormulaContext ------------------------------------------------------------------

stlParser::FormulaContext::FormulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<stlParser::TformulaContext *> stlParser::FormulaContext::tformula() {
  return getRuleContexts<stlParser::TformulaContext>();
}

stlParser::TformulaContext* stlParser::FormulaContext::tformula(size_t i) {
  return getRuleContext<stlParser::TformulaContext>(i);
}

tree::TerminalNode* stlParser::FormulaContext::IMPL() {
  return getToken(stlParser::IMPL, 0);
}


size_t stlParser::FormulaContext::getRuleIndex() const {
  return stlParser::RuleFormula;
}

void stlParser::FormulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormula(this);
}

void stlParser::FormulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormula(this);
}

stlParser::FormulaContext* stlParser::formula() {
  FormulaContext *_localctx = _tracker.createInstance<FormulaContext>(_ctx, getState());
  enterRule(_localctx, 2, stlParser::RuleFormula);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    tformula(0);
    setState(58);
    match(stlParser::IMPL);
    setState(59);
    tformula(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TformulaContext ------------------------------------------------------------------

stlParser::TformulaContext::TformulaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

stlParser::BooleanContext* stlParser::TformulaContext::boolean() {
  return getRuleContext<stlParser::BooleanContext>(0);
}

stlParser::PlaceholderContext* stlParser::TformulaContext::placeholder() {
  return getRuleContext<stlParser::PlaceholderContext>(0);
}

tree::TerminalNode* stlParser::TformulaContext::DT_AND() {
  return getToken(stlParser::DT_AND, 0);
}

tree::TerminalNode* stlParser::TformulaContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

std::vector<stlParser::TformulaContext *> stlParser::TformulaContext::tformula() {
  return getRuleContexts<stlParser::TformulaContext>();
}

stlParser::TformulaContext* stlParser::TformulaContext::tformula(size_t i) {
  return getRuleContext<stlParser::TformulaContext>(i);
}

tree::TerminalNode* stlParser::TformulaContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}

tree::TerminalNode* stlParser::TformulaContext::NOT() {
  return getToken(stlParser::NOT, 0);
}

tree::TerminalNode* stlParser::TformulaContext::STL_EVENTUALLY() {
  return getToken(stlParser::STL_EVENTUALLY, 0);
}

tree::TerminalNode* stlParser::TformulaContext::LCPAREN() {
  return getToken(stlParser::LCPAREN, 0);
}

std::vector<stlParser::IntervalContext *> stlParser::TformulaContext::interval() {
  return getRuleContexts<stlParser::IntervalContext>();
}

stlParser::IntervalContext* stlParser::TformulaContext::interval(size_t i) {
  return getRuleContext<stlParser::IntervalContext>(i);
}

tree::TerminalNode* stlParser::TformulaContext::COMMA() {
  return getToken(stlParser::COMMA, 0);
}

tree::TerminalNode* stlParser::TformulaContext::RCPAREN() {
  return getToken(stlParser::RCPAREN, 0);
}

tree::TerminalNode* stlParser::TformulaContext::AND() {
  return getToken(stlParser::AND, 0);
}

tree::TerminalNode* stlParser::TformulaContext::OR() {
  return getToken(stlParser::OR, 0);
}


size_t stlParser::TformulaContext::getRuleIndex() const {
  return stlParser::RuleTformula;
}

void stlParser::TformulaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTformula(this);
}

void stlParser::TformulaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTformula(this);
}


stlParser::TformulaContext* stlParser::tformula() {
   return tformula(0);
}

stlParser::TformulaContext* stlParser::tformula(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  stlParser::TformulaContext *_localctx = _tracker.createInstance<TformulaContext>(_ctx, parentState);
  stlParser::TformulaContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, stlParser::RuleTformula, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      setState(62);
      boolean(0);
      break;
    }

    case 2: {
      setState(63);
      placeholder();
      break;
    }

    case 3: {
      setState(64);
      match(stlParser::DT_AND);
      break;
    }

    case 4: {
      setState(65);
      match(stlParser::LPAREN);
      setState(66);
      tformula(0);
      setState(67);
      match(stlParser::RPAREN);
      break;
    }

    case 5: {
      setState(69);
      match(stlParser::NOT);
      setState(70);
      tformula(4);
      break;
    }

    case 6: {
      setState(71);
      match(stlParser::STL_EVENTUALLY);
      setState(72);
      match(stlParser::LCPAREN);
      setState(73);
      interval();
      setState(74);
      match(stlParser::COMMA);
      setState(75);
      interval();
      setState(76);
      match(stlParser::RCPAREN);
      setState(77);
      tformula(1);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(89);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(87);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(81);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(82);
          match(stlParser::AND);
          setState(83);
          tformula(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(84);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(85);
          match(stlParser::OR);
          setState(86);
          tformula(3);
          break;
        }

        } 
      }
      setState(91);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PlaceholderContext ------------------------------------------------------------------

stlParser::PlaceholderContext::PlaceholderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::PlaceholderContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::PlaceholderContext::getRuleIndex() const {
  return stlParser::RulePlaceholder;
}

void stlParser::PlaceholderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlaceholder(this);
}

void stlParser::PlaceholderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlaceholder(this);
}

stlParser::PlaceholderContext* stlParser::placeholder() {
  PlaceholderContext *_localctx = _tracker.createInstance<PlaceholderContext>(_ctx, getState());
  enterRule(_localctx, 6, stlParser::RulePlaceholder);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(stlParser::T__0);
    setState(93);
    match(stlParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntervalContext ------------------------------------------------------------------

stlParser::IntervalContext::IntervalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::IntervalContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::IntervalContext::getRuleIndex() const {
  return stlParser::RuleInterval;
}

void stlParser::IntervalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterval(this);
}

void stlParser::IntervalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterval(this);
}

stlParser::IntervalContext* stlParser::interval() {
  IntervalContext *_localctx = _tracker.createInstance<IntervalContext>(_ctx, getState());
  enterRule(_localctx, 8, stlParser::RuleInterval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(stlParser::T__1);
    setState(96);
    match(stlParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

stlParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::BooleanContext::NOT() {
  return getToken(stlParser::NOT, 0);
}

std::vector<stlParser::BooleanContext *> stlParser::BooleanContext::boolean() {
  return getRuleContexts<stlParser::BooleanContext>();
}

stlParser::BooleanContext* stlParser::BooleanContext::boolean(size_t i) {
  return getRuleContext<stlParser::BooleanContext>(i);
}

std::vector<stlParser::LogicContext *> stlParser::BooleanContext::logic() {
  return getRuleContexts<stlParser::LogicContext>();
}

stlParser::LogicContext* stlParser::BooleanContext::logic(size_t i) {
  return getRuleContext<stlParser::LogicContext>(i);
}

stlParser::RelopContext* stlParser::BooleanContext::relop() {
  return getRuleContext<stlParser::RelopContext>(0);
}

std::vector<stlParser::NumericContext *> stlParser::BooleanContext::numeric() {
  return getRuleContexts<stlParser::NumericContext>();
}

stlParser::NumericContext* stlParser::BooleanContext::numeric(size_t i) {
  return getRuleContext<stlParser::NumericContext>(i);
}

tree::TerminalNode* stlParser::BooleanContext::EQ() {
  return getToken(stlParser::EQ, 0);
}

tree::TerminalNode* stlParser::BooleanContext::NEQ() {
  return getToken(stlParser::NEQ, 0);
}

stlParser::BooleanAtomContext* stlParser::BooleanContext::booleanAtom() {
  return getRuleContext<stlParser::BooleanAtomContext>(0);
}

tree::TerminalNode* stlParser::BooleanContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

tree::TerminalNode* stlParser::BooleanContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}

tree::TerminalNode* stlParser::BooleanContext::AND() {
  return getToken(stlParser::AND, 0);
}

tree::TerminalNode* stlParser::BooleanContext::OR() {
  return getToken(stlParser::OR, 0);
}


size_t stlParser::BooleanContext::getRuleIndex() const {
  return stlParser::RuleBoolean;
}

void stlParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void stlParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


stlParser::BooleanContext* stlParser::boolean() {
   return boolean(0);
}

stlParser::BooleanContext* stlParser::boolean(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  stlParser::BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, parentState);
  stlParser::BooleanContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, stlParser::RuleBoolean, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(99);
      match(stlParser::NOT);
      setState(100);
      boolean(15);
      break;
    }

    case 2: {
      setState(101);
      logic(0);
      setState(102);
      relop();
      setState(103);
      logic(0);
      break;
    }

    case 3: {
      setState(105);
      numeric(0);
      setState(106);
      relop();
      setState(107);
      numeric(0);
      break;
    }

    case 4: {
      setState(109);
      logic(0);
      setState(110);
      match(stlParser::EQ);
      setState(111);
      logic(0);
      break;
    }

    case 5: {
      setState(113);
      numeric(0);
      setState(114);
      match(stlParser::EQ);
      setState(115);
      numeric(0);
      break;
    }

    case 6: {
      setState(117);
      logic(0);
      setState(118);
      match(stlParser::NEQ);
      setState(119);
      logic(0);
      break;
    }

    case 7: {
      setState(121);
      numeric(0);
      setState(122);
      match(stlParser::NEQ);
      setState(123);
      numeric(0);
      break;
    }

    case 8: {
      setState(125);
      booleanAtom();
      break;
    }

    case 9: {
      setState(126);
      logic(0);
      break;
    }

    case 10: {
      setState(127);
      numeric(0);
      break;
    }

    case 11: {
      setState(128);
      match(stlParser::LPAREN);
      setState(129);
      boolean(0);
      setState(130);
      match(stlParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(148);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(146);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(134);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(135);
          match(stlParser::EQ);
          setState(136);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(137);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(138);
          match(stlParser::NEQ);
          setState(139);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(140);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(141);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(stlParser::AND);
          setState(142);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(143);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(144);
          dynamic_cast<BooleanContext *>(_localctx)->booleanop = match(stlParser::OR);
          setState(145);
          boolean(6);
          break;
        }

        } 
      }
      setState(150);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanAtomContext ------------------------------------------------------------------

stlParser::BooleanAtomContext::BooleanAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

stlParser::BooleanConstantContext* stlParser::BooleanAtomContext::booleanConstant() {
  return getRuleContext<stlParser::BooleanConstantContext>(0);
}

stlParser::BooleanVariableContext* stlParser::BooleanAtomContext::booleanVariable() {
  return getRuleContext<stlParser::BooleanVariableContext>(0);
}


size_t stlParser::BooleanAtomContext::getRuleIndex() const {
  return stlParser::RuleBooleanAtom;
}

void stlParser::BooleanAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanAtom(this);
}

void stlParser::BooleanAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanAtom(this);
}

stlParser::BooleanAtomContext* stlParser::booleanAtom() {
  BooleanAtomContext *_localctx = _tracker.createInstance<BooleanAtomContext>(_ctx, getState());
  enterRule(_localctx, 12, stlParser::RuleBooleanAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(153);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(151);
        booleanConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(152);
        booleanVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanConstantContext ------------------------------------------------------------------

stlParser::BooleanConstantContext::BooleanConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::BooleanConstantContext::BOOLEAN() {
  return getToken(stlParser::BOOLEAN, 0);
}


size_t stlParser::BooleanConstantContext::getRuleIndex() const {
  return stlParser::RuleBooleanConstant;
}

void stlParser::BooleanConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanConstant(this);
}

void stlParser::BooleanConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanConstant(this);
}

stlParser::BooleanConstantContext* stlParser::booleanConstant() {
  BooleanConstantContext *_localctx = _tracker.createInstance<BooleanConstantContext>(_ctx, getState());
  enterRule(_localctx, 14, stlParser::RuleBooleanConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(155);
    match(stlParser::BOOLEAN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanVariableContext ------------------------------------------------------------------

stlParser::BooleanVariableContext::BooleanVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::BooleanVariableContext::LT() {
  return getToken(stlParser::LT, 0);
}

stlParser::VariableContext* stlParser::BooleanVariableContext::variable() {
  return getRuleContext<stlParser::VariableContext>(0);
}


size_t stlParser::BooleanVariableContext::getRuleIndex() const {
  return stlParser::RuleBooleanVariable;
}

void stlParser::BooleanVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanVariable(this);
}

void stlParser::BooleanVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanVariable(this);
}

stlParser::BooleanVariableContext* stlParser::booleanVariable() {
  BooleanVariableContext *_localctx = _tracker.createInstance<BooleanVariableContext>(_ctx, getState());
  enterRule(_localctx, 16, stlParser::RuleBooleanVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(stlParser::LT);
    setState(158);
    variable();
    setState(159);
    match(stlParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicContext ------------------------------------------------------------------

stlParser::LogicContext::LogicContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::LogicContext::NEG() {
  return getToken(stlParser::NEG, 0);
}

std::vector<stlParser::LogicContext *> stlParser::LogicContext::logic() {
  return getRuleContexts<stlParser::LogicContext>();
}

stlParser::LogicContext* stlParser::LogicContext::logic(size_t i) {
  return getRuleContext<stlParser::LogicContext>(i);
}

stlParser::LogicAtomContext* stlParser::LogicContext::logicAtom() {
  return getRuleContext<stlParser::LogicAtomContext>(0);
}

tree::TerminalNode* stlParser::LogicContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

tree::TerminalNode* stlParser::LogicContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}

tree::TerminalNode* stlParser::LogicContext::TIMES() {
  return getToken(stlParser::TIMES, 0);
}

tree::TerminalNode* stlParser::LogicContext::DIV() {
  return getToken(stlParser::DIV, 0);
}

tree::TerminalNode* stlParser::LogicContext::PLUS() {
  return getToken(stlParser::PLUS, 0);
}

tree::TerminalNode* stlParser::LogicContext::MINUS() {
  return getToken(stlParser::MINUS, 0);
}

tree::TerminalNode* stlParser::LogicContext::LSHIFT() {
  return getToken(stlParser::LSHIFT, 0);
}

tree::TerminalNode* stlParser::LogicContext::RSHIFT() {
  return getToken(stlParser::RSHIFT, 0);
}

tree::TerminalNode* stlParser::LogicContext::BAND() {
  return getToken(stlParser::BAND, 0);
}

tree::TerminalNode* stlParser::LogicContext::BXOR() {
  return getToken(stlParser::BXOR, 0);
}

tree::TerminalNode* stlParser::LogicContext::BOR() {
  return getToken(stlParser::BOR, 0);
}

stlParser::BitSelectContext* stlParser::LogicContext::bitSelect() {
  return getRuleContext<stlParser::BitSelectContext>(0);
}


size_t stlParser::LogicContext::getRuleIndex() const {
  return stlParser::RuleLogic;
}

void stlParser::LogicContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic(this);
}

void stlParser::LogicContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic(this);
}


stlParser::LogicContext* stlParser::logic() {
   return logic(0);
}

stlParser::LogicContext* stlParser::logic(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  stlParser::LogicContext *_localctx = _tracker.createInstance<LogicContext>(_ctx, parentState);
  stlParser::LogicContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 18;
  enterRecursionRule(_localctx, 18, stlParser::RuleLogic, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(169);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NEG: {
        setState(162);
        match(stlParser::NEG);
        setState(163);
        logic(11);
        break;
      }

      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX:
      case stlParser::LT: {
        setState(164);
        logicAtom();
        break;
      }

      case stlParser::LPAREN: {
        setState(165);
        match(stlParser::LPAREN);
        setState(166);
        logic(0);
        setState(167);
        match(stlParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(196);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(194);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(171);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(172);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::TIMES

          || _la == stlParser::DIV)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(173);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(174);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(175);
          dynamic_cast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::PLUS

          || _la == stlParser::MINUS)) {
            dynamic_cast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(176);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(177);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(178);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(stlParser::LSHIFT);
          setState(179);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(180);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(181);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(stlParser::RSHIFT);
          setState(182);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(183);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(184);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(stlParser::BAND);
          setState(185);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(186);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(187);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(stlParser::BXOR);
          setState(188);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(189);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(190);
          dynamic_cast<LogicContext *>(_localctx)->logop = match(stlParser::BOR);
          setState(191);
          logic(4);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(192);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(193);
          bitSelect();
          break;
        }

        } 
      }
      setState(198);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BitSelectContext ------------------------------------------------------------------

stlParser::BitSelectContext::BitSelectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::BitSelectContext::LCPAREN() {
  return getToken(stlParser::LCPAREN, 0);
}

std::vector<tree::TerminalNode *> stlParser::BitSelectContext::NUMERIC() {
  return getTokens(stlParser::NUMERIC);
}

tree::TerminalNode* stlParser::BitSelectContext::NUMERIC(size_t i) {
  return getToken(stlParser::NUMERIC, i);
}

tree::TerminalNode* stlParser::BitSelectContext::RCPAREN() {
  return getToken(stlParser::RCPAREN, 0);
}

tree::TerminalNode* stlParser::BitSelectContext::COL() {
  return getToken(stlParser::COL, 0);
}


size_t stlParser::BitSelectContext::getRuleIndex() const {
  return stlParser::RuleBitSelect;
}

void stlParser::BitSelectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBitSelect(this);
}

void stlParser::BitSelectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBitSelect(this);
}

stlParser::BitSelectContext* stlParser::bitSelect() {
  BitSelectContext *_localctx = _tracker.createInstance<BitSelectContext>(_ctx, getState());
  enterRule(_localctx, 20, stlParser::RuleBitSelect);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(stlParser::LCPAREN);
    setState(200);
    match(stlParser::NUMERIC);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == stlParser::COL) {
      setState(201);
      match(stlParser::COL);
      setState(202);
      match(stlParser::NUMERIC);
    }
    setState(205);
    match(stlParser::RCPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicAtomContext ------------------------------------------------------------------

stlParser::LogicAtomContext::LogicAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

stlParser::LogicConstantContext* stlParser::LogicAtomContext::logicConstant() {
  return getRuleContext<stlParser::LogicConstantContext>(0);
}

stlParser::LogicVariableContext* stlParser::LogicAtomContext::logicVariable() {
  return getRuleContext<stlParser::LogicVariableContext>(0);
}


size_t stlParser::LogicAtomContext::getRuleIndex() const {
  return stlParser::RuleLogicAtom;
}

void stlParser::LogicAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicAtom(this);
}

void stlParser::LogicAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicAtom(this);
}

stlParser::LogicAtomContext* stlParser::logicAtom() {
  LogicAtomContext *_localctx = _tracker.createInstance<LogicAtomContext>(_ctx, getState());
  enterRule(_localctx, 22, stlParser::RuleLogicAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(209);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        logicConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(208);
        logicVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicConstantContext ------------------------------------------------------------------

stlParser::LogicConstantContext::LogicConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::LogicConstantContext::VERILOG_BINARY() {
  return getToken(stlParser::VERILOG_BINARY, 0);
}

tree::TerminalNode* stlParser::LogicConstantContext::GCC_BINARY() {
  return getToken(stlParser::GCC_BINARY, 0);
}

tree::TerminalNode* stlParser::LogicConstantContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}

tree::TerminalNode* stlParser::LogicConstantContext::HEX() {
  return getToken(stlParser::HEX, 0);
}


size_t stlParser::LogicConstantContext::getRuleIndex() const {
  return stlParser::RuleLogicConstant;
}

void stlParser::LogicConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicConstant(this);
}

void stlParser::LogicConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicConstant(this);
}

stlParser::LogicConstantContext* stlParser::logicConstant() {
  LogicConstantContext *_localctx = _tracker.createInstance<LogicConstantContext>(_ctx, getState());
  enterRule(_localctx, 24, stlParser::RuleLogicConstant);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << stlParser::NUMERIC)
      | (1ULL << stlParser::VERILOG_BINARY)
      | (1ULL << stlParser::GCC_BINARY)
      | (1ULL << stlParser::HEX))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicVariableContext ------------------------------------------------------------------

stlParser::LogicVariableContext::LogicVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::LogicVariableContext::LT() {
  return getToken(stlParser::LT, 0);
}

stlParser::VariableContext* stlParser::LogicVariableContext::variable() {
  return getRuleContext<stlParser::VariableContext>(0);
}

tree::TerminalNode* stlParser::LogicVariableContext::SIGN() {
  return getToken(stlParser::SIGN, 0);
}

tree::TerminalNode* stlParser::LogicVariableContext::COMMA() {
  return getToken(stlParser::COMMA, 0);
}

tree::TerminalNode* stlParser::LogicVariableContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::LogicVariableContext::getRuleIndex() const {
  return stlParser::RuleLogicVariable;
}

void stlParser::LogicVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicVariable(this);
}

void stlParser::LogicVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicVariable(this);
}

stlParser::LogicVariableContext* stlParser::logicVariable() {
  LogicVariableContext *_localctx = _tracker.createInstance<LogicVariableContext>(_ctx, getState());
  enterRule(_localctx, 26, stlParser::RuleLogicVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(stlParser::LT);
    setState(214);
    variable();
    setState(215);
    match(stlParser::T__3);
    setState(216);
    match(stlParser::SIGN);
    setState(217);
    match(stlParser::COMMA);
    setState(218);
    match(stlParser::NUMERIC);
    setState(219);
    match(stlParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericContext ------------------------------------------------------------------

stlParser::NumericContext::NumericContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

stlParser::NumericAtomContext* stlParser::NumericContext::numericAtom() {
  return getRuleContext<stlParser::NumericAtomContext>(0);
}

stlParser::LogicContext* stlParser::NumericContext::logic() {
  return getRuleContext<stlParser::LogicContext>(0);
}

tree::TerminalNode* stlParser::NumericContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

std::vector<stlParser::NumericContext *> stlParser::NumericContext::numeric() {
  return getRuleContexts<stlParser::NumericContext>();
}

stlParser::NumericContext* stlParser::NumericContext::numeric(size_t i) {
  return getRuleContext<stlParser::NumericContext>(i);
}

tree::TerminalNode* stlParser::NumericContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}

tree::TerminalNode* stlParser::NumericContext::TIMES() {
  return getToken(stlParser::TIMES, 0);
}

tree::TerminalNode* stlParser::NumericContext::DIV() {
  return getToken(stlParser::DIV, 0);
}

tree::TerminalNode* stlParser::NumericContext::PLUS() {
  return getToken(stlParser::PLUS, 0);
}

tree::TerminalNode* stlParser::NumericContext::MINUS() {
  return getToken(stlParser::MINUS, 0);
}


size_t stlParser::NumericContext::getRuleIndex() const {
  return stlParser::RuleNumeric;
}

void stlParser::NumericContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumeric(this);
}

void stlParser::NumericContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumeric(this);
}


stlParser::NumericContext* stlParser::numeric() {
   return numeric(0);
}

stlParser::NumericContext* stlParser::numeric(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  stlParser::NumericContext *_localctx = _tracker.createInstance<NumericContext>(_ctx, parentState);
  stlParser::NumericContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, stlParser::RuleNumeric, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(228);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(222);
      numericAtom();
      break;
    }

    case 2: {
      setState(223);
      logic(0);
      break;
    }

    case 3: {
      setState(224);
      match(stlParser::LPAREN);
      setState(225);
      numeric(0);
      setState(226);
      match(stlParser::RPAREN);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(238);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(236);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(230);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(231);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::TIMES

          || _la == stlParser::DIV)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(232);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(233);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(234);
          dynamic_cast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::PLUS

          || _la == stlParser::MINUS)) {
            dynamic_cast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(235);
          numeric(5);
          break;
        }

        } 
      }
      setState(240);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NumericAtomContext ------------------------------------------------------------------

stlParser::NumericAtomContext::NumericAtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

stlParser::NumericConstantContext* stlParser::NumericAtomContext::numericConstant() {
  return getRuleContext<stlParser::NumericConstantContext>(0);
}

stlParser::NumericVariableContext* stlParser::NumericAtomContext::numericVariable() {
  return getRuleContext<stlParser::NumericVariableContext>(0);
}


size_t stlParser::NumericAtomContext::getRuleIndex() const {
  return stlParser::RuleNumericAtom;
}

void stlParser::NumericAtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericAtom(this);
}

void stlParser::NumericAtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericAtom(this);
}

stlParser::NumericAtomContext* stlParser::numericAtom() {
  NumericAtomContext *_localctx = _tracker.createInstance<NumericAtomContext>(_ctx, getState());
  enterRule(_localctx, 30, stlParser::RuleNumericAtom);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(243);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        numericConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(242);
        numericVariable();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericConstantContext ------------------------------------------------------------------

stlParser::NumericConstantContext::NumericConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::NumericConstantContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::NumericConstantContext::getRuleIndex() const {
  return stlParser::RuleNumericConstant;
}

void stlParser::NumericConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericConstant(this);
}

void stlParser::NumericConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericConstant(this);
}

stlParser::NumericConstantContext* stlParser::numericConstant() {
  NumericConstantContext *_localctx = _tracker.createInstance<NumericConstantContext>(_ctx, getState());
  enterRule(_localctx, 32, stlParser::RuleNumericConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    match(stlParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumericVariableContext ------------------------------------------------------------------

stlParser::NumericVariableContext::NumericVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::NumericVariableContext::LT() {
  return getToken(stlParser::LT, 0);
}

stlParser::VariableContext* stlParser::NumericVariableContext::variable() {
  return getRuleContext<stlParser::VariableContext>(0);
}

tree::TerminalNode* stlParser::NumericVariableContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::NumericVariableContext::getRuleIndex() const {
  return stlParser::RuleNumericVariable;
}

void stlParser::NumericVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumericVariable(this);
}

void stlParser::NumericVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumericVariable(this);
}

stlParser::NumericVariableContext* stlParser::numericVariable() {
  NumericVariableContext *_localctx = _tracker.createInstance<NumericVariableContext>(_ctx, getState());
  enterRule(_localctx, 34, stlParser::RuleNumericVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
    match(stlParser::LT);
    setState(248);
    variable();
    setState(249);
    match(stlParser::T__5);
    setState(250);
    match(stlParser::NUMERIC);
    setState(251);
    match(stlParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

stlParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::VariableContext::VARIABLE() {
  return getToken(stlParser::VARIABLE, 0);
}


size_t stlParser::VariableContext::getRuleIndex() const {
  return stlParser::RuleVariable;
}

void stlParser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void stlParser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

stlParser::VariableContext* stlParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 36, stlParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    match(stlParser::VARIABLE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelopContext ------------------------------------------------------------------

stlParser::RelopContext::RelopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::RelopContext::GT() {
  return getToken(stlParser::GT, 0);
}

tree::TerminalNode* stlParser::RelopContext::GE() {
  return getToken(stlParser::GE, 0);
}

tree::TerminalNode* stlParser::RelopContext::LT() {
  return getToken(stlParser::LT, 0);
}

tree::TerminalNode* stlParser::RelopContext::LE() {
  return getToken(stlParser::LE, 0);
}


size_t stlParser::RelopContext::getRuleIndex() const {
  return stlParser::RuleRelop;
}

void stlParser::RelopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelop(this);
}

void stlParser::RelopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelop(this);
}

stlParser::RelopContext* stlParser::relop() {
  RelopContext *_localctx = _tracker.createInstance<RelopContext>(_ctx, getState());
  enterRule(_localctx, 38, stlParser::RuleRelop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << stlParser::GT)
      | (1ULL << stlParser::GE)
      | (1ULL << stlParser::LT)
      | (1ULL << stlParser::LE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool stlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return tformulaSempred(dynamic_cast<TformulaContext *>(context), predicateIndex);
    case 5: return booleanSempred(dynamic_cast<BooleanContext *>(context), predicateIndex);
    case 9: return logicSempred(dynamic_cast<LogicContext *>(context), predicateIndex);
    case 14: return numericSempred(dynamic_cast<NumericContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool stlParser::tformulaSempred(TformulaContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool stlParser::booleanSempred(BooleanContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

bool stlParser::logicSempred(LogicContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 9);
    case 7: return precpred(_ctx, 8);
    case 8: return precpred(_ctx, 7);
    case 9: return precpred(_ctx, 6);
    case 10: return precpred(_ctx, 5);
    case 11: return precpred(_ctx, 4);
    case 12: return precpred(_ctx, 3);
    case 13: return precpred(_ctx, 10);

  default:
    break;
  }
  return true;
}

bool stlParser::numericSempred(NumericContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 14: return precpred(_ctx, 5);
    case 15: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> stlParser::_decisionToDFA;
atn::PredictionContextCache stlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN stlParser::_atn;
std::vector<uint16_t> stlParser::_serializedATN;

std::vector<std::string> stlParser::_ruleNames = {
  "file", "formula", "tformula", "placeholder", "interval", "boolean", "booleanAtom", 
  "booleanConstant", "booleanVariable", "logic", "bitSelect", "logicAtom", 
  "logicConstant", "logicVariable", "numeric", "numericAtom", "numericConstant", 
  "numericVariable", "variable", "relop"
};

std::vector<std::string> stlParser::_literalNames = {
  "", "'P'", "'X'", "',bool>'", "',logic('", "')>'", "',numeric('", "'..&&..'", 
  "'F'", "'G'", "'release'", "'->'", "';'", "':'", "','", "'first_match'", 
  "", "'{'", "'}'", "'['", "']'", "'('", "')'", "", "", "", "", "", "", 
  "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", 
  "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", "'!'"
};

std::vector<std::string> stlParser::_symbolicNames = {
  "", "", "", "", "", "", "", "DT_AND", "STL_EVENTUALLY", "STL_ALWAYS", 
  "RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH", "SIGN", "LGPAREN", 
  "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "NUMERIC", 
  "VERILOG_BINARY", "GCC_BINARY", "HEX", "BOOLEAN", "PLUS", "MINUS", "TIMES", 
  "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", 
  "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
};

dfa::Vocabulary stlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> stlParser::_tokenNames;

stlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x32, 0x104, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x3a, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x52, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x7, 0x4, 0x5a, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x5d, 0xb, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x87, 0xa, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x95, 0xa, 0x7, 
    0xc, 0x7, 0xe, 0x7, 0x98, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9c, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0xac, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0xc5, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0xc8, 0xb, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xce, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 
    0x3, 0xd, 0x5, 0xd, 0xd4, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x5, 0x10, 0xe7, 0xa, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0xef, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 
    0xf2, 0xb, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xf6, 0xa, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x2, 
    0x6, 0x6, 0xc, 0x14, 0x1e, 0x16, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2, 0x6, 0x3, 0x2, 0x21, 0x22, 0x3, 0x2, 0x1f, 0x20, 0x3, 0x2, 
    0x1a, 0x1d, 0x3, 0x2, 0x23, 0x26, 0x2, 0x117, 0x2, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x5e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x61, 0x3, 0x2, 0x2, 0x2, 0xc, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x14, 0xab, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd7, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x20, 0xf5, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xf7, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf9, 0x3, 0x2, 0x2, 0x2, 0x26, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0x101, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2b, 0x7, 
    0xb, 0x2, 0x2, 0x2b, 0x2c, 0x5, 0x4, 0x3, 0x2, 0x2c, 0x2d, 0x7, 0x2, 
    0x2, 0x3, 0x2d, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0xb, 0x2, 
    0x2, 0x2f, 0x30, 0x7, 0x15, 0x2, 0x2, 0x30, 0x31, 0x5, 0xa, 0x6, 0x2, 
    0x31, 0x32, 0x7, 0x10, 0x2, 0x2, 0x32, 0x33, 0x5, 0xa, 0x6, 0x2, 0x33, 
    0x34, 0x7, 0x16, 0x2, 0x2, 0x34, 0x35, 0x7, 0x17, 0x2, 0x2, 0x35, 0x36, 
    0x5, 0x4, 0x3, 0x2, 0x36, 0x37, 0x7, 0x18, 0x2, 0x2, 0x37, 0x38, 0x7, 
    0x2, 0x2, 0x3, 0x38, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x39, 0x2a, 0x3, 0x2, 
    0x2, 0x2, 0x39, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x3c, 0x5, 0x6, 0x4, 0x2, 0x3c, 0x3d, 0x7, 0xd, 0x2, 0x2, 
    0x3d, 0x3e, 0x5, 0x6, 0x4, 0x2, 0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 
    0x40, 0x8, 0x4, 0x1, 0x2, 0x40, 0x52, 0x5, 0xc, 0x7, 0x2, 0x41, 0x52, 
    0x5, 0x8, 0x5, 0x2, 0x42, 0x52, 0x7, 0x9, 0x2, 0x2, 0x43, 0x44, 0x7, 
    0x17, 0x2, 0x2, 0x44, 0x45, 0x5, 0x6, 0x4, 0x2, 0x45, 0x46, 0x7, 0x18, 
    0x2, 0x2, 0x46, 0x52, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x31, 0x2, 
    0x2, 0x48, 0x52, 0x5, 0x6, 0x4, 0x6, 0x49, 0x4a, 0x7, 0xa, 0x2, 0x2, 
    0x4a, 0x4b, 0x7, 0x15, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0xa, 0x6, 0x2, 0x4c, 
    0x4d, 0x7, 0x10, 0x2, 0x2, 0x4d, 0x4e, 0x5, 0xa, 0x6, 0x2, 0x4e, 0x4f, 
    0x7, 0x16, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x6, 0x4, 0x3, 0x50, 0x52, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x51, 0x41, 0x3, 0x2, 
    0x2, 0x2, 0x51, 0x42, 0x3, 0x2, 0x2, 0x2, 0x51, 0x43, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x47, 0x3, 0x2, 0x2, 0x2, 0x51, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0xc, 0x5, 0x2, 0x2, 0x54, 
    0x55, 0x7, 0x2f, 0x2, 0x2, 0x55, 0x5a, 0x5, 0x6, 0x4, 0x6, 0x56, 0x57, 
    0xc, 0x4, 0x2, 0x2, 0x57, 0x58, 0x7, 0x30, 0x2, 0x2, 0x58, 0x5a, 0x5, 
    0x6, 0x4, 0x5, 0x59, 0x53, 0x3, 0x2, 0x2, 0x2, 0x59, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x3, 0x2, 0x2, 0x5f, 
    0x60, 0x7, 0x1a, 0x2, 0x2, 0x60, 0x9, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x4, 0x2, 0x2, 0x62, 0x63, 0x7, 0x1a, 0x2, 0x2, 0x63, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x64, 0x65, 0x8, 0x7, 0x1, 0x2, 0x65, 0x66, 0x7, 0x31, 
    0x2, 0x2, 0x66, 0x87, 0x5, 0xc, 0x7, 0x11, 0x67, 0x68, 0x5, 0x14, 0xb, 
    0x2, 0x68, 0x69, 0x5, 0x28, 0x15, 0x2, 0x69, 0x6a, 0x5, 0x14, 0xb, 0x2, 
    0x6a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x5, 0x1e, 0x10, 0x2, 0x6c, 
    0x6d, 0x5, 0x28, 0x15, 0x2, 0x6d, 0x6e, 0x5, 0x1e, 0x10, 0x2, 0x6e, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0x14, 0xb, 0x2, 0x70, 0x71, 
    0x7, 0x27, 0x2, 0x2, 0x71, 0x72, 0x5, 0x14, 0xb, 0x2, 0x72, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x74, 0x5, 0x1e, 0x10, 0x2, 0x74, 0x75, 0x7, 0x27, 
    0x2, 0x2, 0x75, 0x76, 0x5, 0x1e, 0x10, 0x2, 0x76, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x77, 0x78, 0x5, 0x14, 0xb, 0x2, 0x78, 0x79, 0x7, 0x28, 0x2, 0x2, 
    0x79, 0x7a, 0x5, 0x14, 0xb, 0x2, 0x7a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x7c, 0x5, 0x1e, 0x10, 0x2, 0x7c, 0x7d, 0x7, 0x28, 0x2, 0x2, 0x7d, 0x7e, 
    0x5, 0x1e, 0x10, 0x2, 0x7e, 0x87, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x87, 0x5, 
    0xe, 0x8, 0x2, 0x80, 0x87, 0x5, 0x14, 0xb, 0x2, 0x81, 0x87, 0x5, 0x1e, 
    0x10, 0x2, 0x82, 0x83, 0x7, 0x17, 0x2, 0x2, 0x83, 0x84, 0x5, 0xc, 0x7, 
    0x2, 0x84, 0x85, 0x7, 0x18, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x64, 0x3, 0x2, 0x2, 0x2, 0x86, 0x67, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x86, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x77, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x86, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x81, 0x3, 0x2, 0x2, 0x2, 0x86, 0x82, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x96, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0xc, 0xc, 0x2, 0x2, 
    0x89, 0x8a, 0x7, 0x27, 0x2, 0x2, 0x8a, 0x95, 0x5, 0xc, 0x7, 0xd, 0x8b, 
    0x8c, 0xc, 0x9, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x28, 0x2, 0x2, 0x8d, 0x95, 
    0x5, 0xc, 0x7, 0xa, 0x8e, 0x8f, 0xc, 0x8, 0x2, 0x2, 0x8f, 0x90, 0x7, 
    0x2f, 0x2, 0x2, 0x90, 0x95, 0x5, 0xc, 0x7, 0x9, 0x91, 0x92, 0xc, 0x7, 
    0x2, 0x2, 0x92, 0x93, 0x7, 0x30, 0x2, 0x2, 0x93, 0x95, 0x5, 0xc, 0x7, 
    0x8, 0x94, 0x88, 0x3, 0x2, 0x2, 0x2, 0x94, 0x8b, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x94, 0x91, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x98, 0x3, 0x2, 0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x97, 0xd, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x9c, 0x5, 0x10, 0x9, 0x2, 0x9a, 0x9c, 0x5, 0x12, 
    0xa, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0xf, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0x7, 0x1e, 0x2, 0x2, 
    0x9e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x25, 0x2, 0x2, 0xa0, 
    0xa1, 0x5, 0x26, 0x14, 0x2, 0xa1, 0xa2, 0x7, 0x5, 0x2, 0x2, 0xa2, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x8, 0xb, 0x1, 0x2, 0xa4, 0xa5, 0x7, 
    0x2c, 0x2, 0x2, 0xa5, 0xac, 0x5, 0x14, 0xb, 0xd, 0xa6, 0xac, 0x5, 0x18, 
    0xd, 0x2, 0xa7, 0xa8, 0x7, 0x17, 0x2, 0x2, 0xa8, 0xa9, 0x5, 0x14, 0xb, 
    0x2, 0xa9, 0xaa, 0x7, 0x18, 0x2, 0x2, 0xaa, 0xac, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xab, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xac, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 
    0xc, 0xb, 0x2, 0x2, 0xae, 0xaf, 0x9, 0x2, 0x2, 0x2, 0xaf, 0xc5, 0x5, 
    0x14, 0xb, 0xc, 0xb0, 0xb1, 0xc, 0xa, 0x2, 0x2, 0xb1, 0xb2, 0x9, 0x3, 
    0x2, 0x2, 0xb2, 0xc5, 0x5, 0x14, 0xb, 0xb, 0xb3, 0xb4, 0xc, 0x9, 0x2, 
    0x2, 0xb4, 0xb5, 0x7, 0x2d, 0x2, 0x2, 0xb5, 0xc5, 0x5, 0x14, 0xb, 0xa, 
    0xb6, 0xb7, 0xc, 0x8, 0x2, 0x2, 0xb7, 0xb8, 0x7, 0x2e, 0x2, 0x2, 0xb8, 
    0xc5, 0x5, 0x14, 0xb, 0x9, 0xb9, 0xba, 0xc, 0x7, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x29, 0x2, 0x2, 0xbb, 0xc5, 0x5, 0x14, 0xb, 0x8, 0xbc, 0xbd, 0xc, 
    0x6, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x2b, 0x2, 0x2, 0xbe, 0xc5, 0x5, 0x14, 
    0xb, 0x7, 0xbf, 0xc0, 0xc, 0x5, 0x2, 0x2, 0xc0, 0xc1, 0x7, 0x2a, 0x2, 
    0x2, 0xc1, 0xc5, 0x5, 0x14, 0xb, 0x6, 0xc2, 0xc3, 0xc, 0xc, 0x2, 0x2, 
    0xc3, 0xc5, 0x5, 0x16, 0xc, 0x2, 0xc4, 0xad, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xb0, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xc4, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xbc, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc2, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0x15, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x7, 0x15, 0x2, 0x2, 0xca, 
    0xcd, 0x7, 0x1a, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0xf, 0x2, 0x2, 0xcc, 0xce, 
    0x7, 0x1a, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 0x16, 
    0x2, 0x2, 0xd0, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd4, 0x5, 0x1a, 0xe, 
    0x2, 0xd2, 0xd4, 0x5, 0x1c, 0xf, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd5, 
    0xd6, 0x9, 0x4, 0x2, 0x2, 0xd6, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 
    0x7, 0x25, 0x2, 0x2, 0xd8, 0xd9, 0x5, 0x26, 0x14, 0x2, 0xd9, 0xda, 0x7, 
    0x6, 0x2, 0x2, 0xda, 0xdb, 0x7, 0x12, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x10, 
    0x2, 0x2, 0xdc, 0xdd, 0x7, 0x1a, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x7, 0x2, 
    0x2, 0xde, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x8, 0x10, 0x1, 0x2, 
    0xe0, 0xe7, 0x5, 0x20, 0x11, 0x2, 0xe1, 0xe7, 0x5, 0x14, 0xb, 0x2, 0xe2, 
    0xe3, 0x7, 0x17, 0x2, 0x2, 0xe3, 0xe4, 0x5, 0x1e, 0x10, 0x2, 0xe4, 0xe5, 
    0x7, 0x18, 0x2, 0x2, 0xe5, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xdf, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe7, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0xc, 0x7, 0x2, 
    0x2, 0xe9, 0xea, 0x9, 0x2, 0x2, 0x2, 0xea, 0xef, 0x5, 0x1e, 0x10, 0x8, 
    0xeb, 0xec, 0xc, 0x6, 0x2, 0x2, 0xec, 0xed, 0x9, 0x3, 0x2, 0x2, 0xed, 
    0xef, 0x5, 0x1e, 0x10, 0x7, 0xee, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xee, 0xeb, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf1, 0x1f, 0x3, 0x2, 
    0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x5, 0x22, 0x12, 
    0x2, 0xf4, 0xf6, 0x5, 0x24, 0x13, 0x2, 0xf5, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0x21, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf8, 0x7, 0x1a, 0x2, 0x2, 0xf8, 0x23, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
    0x7, 0x25, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x26, 0x14, 0x2, 0xfb, 0xfc, 0x7, 
    0x8, 0x2, 0x2, 0xfc, 0xfd, 0x7, 0x1a, 0x2, 0x2, 0xfd, 0xfe, 0x7, 0x7, 
    0x2, 0x2, 0xfe, 0x25, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x19, 0x2, 
    0x2, 0x100, 0x27, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x9, 0x5, 0x2, 0x2, 
    0x102, 0x29, 0x3, 0x2, 0x2, 0x2, 0x13, 0x39, 0x51, 0x59, 0x5b, 0x86, 
    0x94, 0x96, 0x9b, 0xab, 0xc4, 0xc6, 0xcd, 0xd3, 0xe6, 0xee, 0xf0, 0xf5, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

stlParser::Initializer stlParser::_init;
