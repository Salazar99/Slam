
// Generated from limits.g4 by ANTLR 4.12.0


#include "limitsListener.h"

#include "limitsParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct LimitsParserStaticData final {
  LimitsParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LimitsParserStaticData(const LimitsParserStaticData&) = delete;
  LimitsParserStaticData(LimitsParserStaticData&&) = delete;
  LimitsParserStaticData& operator=(const LimitsParserStaticData&) = delete;
  LimitsParserStaticData& operator=(LimitsParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag limitsParserOnceFlag;
LimitsParserStaticData *limitsParserStaticData = nullptr;

void limitsParserInitialize() {
  assert(limitsParserStaticData == nullptr);
  auto staticData = std::make_unique<LimitsParserStaticData>(
    std::vector<std::string>{
      "file", "parameter", "atom", "maxDistance", "minDistance", "dep", 
      "width", "all", "offset", "negated", "effort", "strategy"
    },
    std::vector<std::string>{
      "", "','", "'maxd'", "'mind'", "'D'", "'W'", "'A'", "'O'", "'N'", 
      "'E'", "'S'", "'R'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "SEQ", "RAN", "NOT", "NUMERIC", 
      "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,14,76,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,
  	1,3,1,33,8,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,44,8,2,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,7,1,8,3,8,62,8,8,1,8,
  	1,8,1,9,3,9,67,8,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,0,0,12,0,2,4,
  	6,8,10,12,14,16,18,20,22,0,1,1,0,10,11,74,0,24,1,0,0,0,2,32,1,0,0,0,4,
  	43,1,0,0,0,6,45,1,0,0,0,8,48,1,0,0,0,10,51,1,0,0,0,12,54,1,0,0,0,14,57,
  	1,0,0,0,16,61,1,0,0,0,18,66,1,0,0,0,20,70,1,0,0,0,22,73,1,0,0,0,24,25,
  	3,2,1,0,25,26,5,0,0,1,26,1,1,0,0,0,27,28,3,4,2,0,28,29,5,1,0,0,29,30,
  	3,2,1,0,30,33,1,0,0,0,31,33,3,4,2,0,32,27,1,0,0,0,32,31,1,0,0,0,33,3,
  	1,0,0,0,34,44,3,10,5,0,35,44,3,12,6,0,36,44,3,14,7,0,37,44,3,16,8,0,38,
  	44,3,20,10,0,39,44,3,22,11,0,40,44,3,18,9,0,41,44,3,6,3,0,42,44,3,8,4,
  	0,43,34,1,0,0,0,43,35,1,0,0,0,43,36,1,0,0,0,43,37,1,0,0,0,43,38,1,0,0,
  	0,43,39,1,0,0,0,43,40,1,0,0,0,43,41,1,0,0,0,43,42,1,0,0,0,44,5,1,0,0,
  	0,45,46,5,13,0,0,46,47,5,2,0,0,47,7,1,0,0,0,48,49,5,13,0,0,49,50,5,3,
  	0,0,50,9,1,0,0,0,51,52,5,13,0,0,52,53,5,4,0,0,53,11,1,0,0,0,54,55,5,13,
  	0,0,55,56,5,5,0,0,56,13,1,0,0,0,57,58,5,13,0,0,58,59,5,6,0,0,59,15,1,
  	0,0,0,60,62,5,12,0,0,61,60,1,0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,64,
  	5,7,0,0,64,17,1,0,0,0,65,67,5,12,0,0,66,65,1,0,0,0,66,67,1,0,0,0,67,68,
  	1,0,0,0,68,69,5,8,0,0,69,19,1,0,0,0,70,71,5,13,0,0,71,72,5,9,0,0,72,21,
  	1,0,0,0,73,74,7,0,0,0,74,23,1,0,0,0,4,32,43,61,66
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  limitsParserStaticData = staticData.release();
}

}

limitsParser::limitsParser(TokenStream *input) : limitsParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

limitsParser::limitsParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  limitsParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *limitsParserStaticData->atn, limitsParserStaticData->decisionToDFA, limitsParserStaticData->sharedContextCache, options);
}

limitsParser::~limitsParser() {
  delete _interpreter;
}

const atn::ATN& limitsParser::getATN() const {
  return *limitsParserStaticData->atn;
}

std::string limitsParser::getGrammarFileName() const {
  return "limits.g4";
}

const std::vector<std::string>& limitsParser::getRuleNames() const {
  return limitsParserStaticData->ruleNames;
}

const dfa::Vocabulary& limitsParser::getVocabulary() const {
  return limitsParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView limitsParser::getSerializedATN() const {
  return limitsParserStaticData->serializedATN;
}


//----------------- FileContext ------------------------------------------------------------------

limitsParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

limitsParser::ParameterContext* limitsParser::FileContext::parameter() {
  return getRuleContext<limitsParser::ParameterContext>(0);
}

tree::TerminalNode* limitsParser::FileContext::EOF() {
  return getToken(limitsParser::EOF, 0);
}


size_t limitsParser::FileContext::getRuleIndex() const {
  return limitsParser::RuleFile;
}

void limitsParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void limitsParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}

limitsParser::FileContext* limitsParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, limitsParser::RuleFile);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(24);
    parameter();
    setState(25);
    match(limitsParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

limitsParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

limitsParser::AtomContext* limitsParser::ParameterContext::atom() {
  return getRuleContext<limitsParser::AtomContext>(0);
}

limitsParser::ParameterContext* limitsParser::ParameterContext::parameter() {
  return getRuleContext<limitsParser::ParameterContext>(0);
}


size_t limitsParser::ParameterContext::getRuleIndex() const {
  return limitsParser::RuleParameter;
}

void limitsParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void limitsParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

limitsParser::ParameterContext* limitsParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 2, limitsParser::RuleParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(32);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(27);
      atom();
      setState(28);
      match(limitsParser::T__0);
      setState(29);
      parameter();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(31);
      atom();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomContext ------------------------------------------------------------------

limitsParser::AtomContext::AtomContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

limitsParser::DepContext* limitsParser::AtomContext::dep() {
  return getRuleContext<limitsParser::DepContext>(0);
}

limitsParser::WidthContext* limitsParser::AtomContext::width() {
  return getRuleContext<limitsParser::WidthContext>(0);
}

limitsParser::AllContext* limitsParser::AtomContext::all() {
  return getRuleContext<limitsParser::AllContext>(0);
}

limitsParser::OffsetContext* limitsParser::AtomContext::offset() {
  return getRuleContext<limitsParser::OffsetContext>(0);
}

limitsParser::EffortContext* limitsParser::AtomContext::effort() {
  return getRuleContext<limitsParser::EffortContext>(0);
}

limitsParser::StrategyContext* limitsParser::AtomContext::strategy() {
  return getRuleContext<limitsParser::StrategyContext>(0);
}

limitsParser::NegatedContext* limitsParser::AtomContext::negated() {
  return getRuleContext<limitsParser::NegatedContext>(0);
}

limitsParser::MaxDistanceContext* limitsParser::AtomContext::maxDistance() {
  return getRuleContext<limitsParser::MaxDistanceContext>(0);
}

limitsParser::MinDistanceContext* limitsParser::AtomContext::minDistance() {
  return getRuleContext<limitsParser::MinDistanceContext>(0);
}


size_t limitsParser::AtomContext::getRuleIndex() const {
  return limitsParser::RuleAtom;
}

void limitsParser::AtomContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtom(this);
}

void limitsParser::AtomContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtom(this);
}

limitsParser::AtomContext* limitsParser::atom() {
  AtomContext *_localctx = _tracker.createInstance<AtomContext>(_ctx, getState());
  enterRule(_localctx, 4, limitsParser::RuleAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(43);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(34);
      dep();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(35);
      width();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(36);
      all();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(37);
      offset();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(38);
      effort();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(39);
      strategy();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(40);
      negated();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(41);
      maxDistance();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(42);
      minDistance();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MaxDistanceContext ------------------------------------------------------------------

limitsParser::MaxDistanceContext::MaxDistanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::MaxDistanceContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::MaxDistanceContext::getRuleIndex() const {
  return limitsParser::RuleMaxDistance;
}

void limitsParser::MaxDistanceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMaxDistance(this);
}

void limitsParser::MaxDistanceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMaxDistance(this);
}

limitsParser::MaxDistanceContext* limitsParser::maxDistance() {
  MaxDistanceContext *_localctx = _tracker.createInstance<MaxDistanceContext>(_ctx, getState());
  enterRule(_localctx, 6, limitsParser::RuleMaxDistance);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(limitsParser::NUMERIC);
    setState(46);
    match(limitsParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MinDistanceContext ------------------------------------------------------------------

limitsParser::MinDistanceContext::MinDistanceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::MinDistanceContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::MinDistanceContext::getRuleIndex() const {
  return limitsParser::RuleMinDistance;
}

void limitsParser::MinDistanceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMinDistance(this);
}

void limitsParser::MinDistanceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMinDistance(this);
}

limitsParser::MinDistanceContext* limitsParser::minDistance() {
  MinDistanceContext *_localctx = _tracker.createInstance<MinDistanceContext>(_ctx, getState());
  enterRule(_localctx, 8, limitsParser::RuleMinDistance);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(limitsParser::NUMERIC);
    setState(49);
    match(limitsParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DepContext ------------------------------------------------------------------

limitsParser::DepContext::DepContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::DepContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::DepContext::getRuleIndex() const {
  return limitsParser::RuleDep;
}

void limitsParser::DepContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDep(this);
}

void limitsParser::DepContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDep(this);
}

limitsParser::DepContext* limitsParser::dep() {
  DepContext *_localctx = _tracker.createInstance<DepContext>(_ctx, getState());
  enterRule(_localctx, 10, limitsParser::RuleDep);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(51);
    match(limitsParser::NUMERIC);
    setState(52);
    match(limitsParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WidthContext ------------------------------------------------------------------

limitsParser::WidthContext::WidthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::WidthContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::WidthContext::getRuleIndex() const {
  return limitsParser::RuleWidth;
}

void limitsParser::WidthContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWidth(this);
}

void limitsParser::WidthContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWidth(this);
}

limitsParser::WidthContext* limitsParser::width() {
  WidthContext *_localctx = _tracker.createInstance<WidthContext>(_ctx, getState());
  enterRule(_localctx, 12, limitsParser::RuleWidth);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(limitsParser::NUMERIC);
    setState(55);
    match(limitsParser::T__4);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllContext ------------------------------------------------------------------

limitsParser::AllContext::AllContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::AllContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::AllContext::getRuleIndex() const {
  return limitsParser::RuleAll;
}

void limitsParser::AllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAll(this);
}

void limitsParser::AllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAll(this);
}

limitsParser::AllContext* limitsParser::all() {
  AllContext *_localctx = _tracker.createInstance<AllContext>(_ctx, getState());
  enterRule(_localctx, 14, limitsParser::RuleAll);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(limitsParser::NUMERIC);
    setState(58);
    match(limitsParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OffsetContext ------------------------------------------------------------------

limitsParser::OffsetContext::OffsetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::OffsetContext::NOT() {
  return getToken(limitsParser::NOT, 0);
}


size_t limitsParser::OffsetContext::getRuleIndex() const {
  return limitsParser::RuleOffset;
}

void limitsParser::OffsetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOffset(this);
}

void limitsParser::OffsetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOffset(this);
}

limitsParser::OffsetContext* limitsParser::offset() {
  OffsetContext *_localctx = _tracker.createInstance<OffsetContext>(_ctx, getState());
  enterRule(_localctx, 16, limitsParser::RuleOffset);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == limitsParser::NOT) {
      setState(60);
      match(limitsParser::NOT);
    }
    setState(63);
    match(limitsParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegatedContext ------------------------------------------------------------------

limitsParser::NegatedContext::NegatedContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::NegatedContext::NOT() {
  return getToken(limitsParser::NOT, 0);
}


size_t limitsParser::NegatedContext::getRuleIndex() const {
  return limitsParser::RuleNegated;
}

void limitsParser::NegatedContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegated(this);
}

void limitsParser::NegatedContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegated(this);
}

limitsParser::NegatedContext* limitsParser::negated() {
  NegatedContext *_localctx = _tracker.createInstance<NegatedContext>(_ctx, getState());
  enterRule(_localctx, 18, limitsParser::RuleNegated);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(66);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == limitsParser::NOT) {
      setState(65);
      match(limitsParser::NOT);
    }
    setState(68);
    match(limitsParser::T__7);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EffortContext ------------------------------------------------------------------

limitsParser::EffortContext::EffortContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::EffortContext::NUMERIC() {
  return getToken(limitsParser::NUMERIC, 0);
}


size_t limitsParser::EffortContext::getRuleIndex() const {
  return limitsParser::RuleEffort;
}

void limitsParser::EffortContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEffort(this);
}

void limitsParser::EffortContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEffort(this);
}

limitsParser::EffortContext* limitsParser::effort() {
  EffortContext *_localctx = _tracker.createInstance<EffortContext>(_ctx, getState());
  enterRule(_localctx, 20, limitsParser::RuleEffort);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(limitsParser::NUMERIC);
    setState(71);
    match(limitsParser::T__8);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrategyContext ------------------------------------------------------------------

limitsParser::StrategyContext::StrategyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* limitsParser::StrategyContext::SEQ() {
  return getToken(limitsParser::SEQ, 0);
}

tree::TerminalNode* limitsParser::StrategyContext::RAN() {
  return getToken(limitsParser::RAN, 0);
}


size_t limitsParser::StrategyContext::getRuleIndex() const {
  return limitsParser::RuleStrategy;
}

void limitsParser::StrategyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStrategy(this);
}

void limitsParser::StrategyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<limitsListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStrategy(this);
}

limitsParser::StrategyContext* limitsParser::strategy() {
  StrategyContext *_localctx = _tracker.createInstance<StrategyContext>(_ctx, getState());
  enterRule(_localctx, 22, limitsParser::RuleStrategy);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(73);
    _la = _input->LA(1);
    if (!(_la == limitsParser::SEQ

    || _la == limitsParser::RAN)) {
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

void limitsParser::initialize() {
  ::antlr4::internal::call_once(limitsParserOnceFlag, limitsParserInitialize);
}
