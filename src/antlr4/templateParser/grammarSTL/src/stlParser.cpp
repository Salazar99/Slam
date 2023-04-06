
// Generated from stl.g4 by ANTLR 4.12.0


#include "stlListener.h"

#include "stlParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct StlParserStaticData final {
  StlParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  StlParserStaticData(const StlParserStaticData&) = delete;
  StlParserStaticData(StlParserStaticData&&) = delete;
  StlParserStaticData& operator=(const StlParserStaticData&) = delete;
  StlParserStaticData& operator=(StlParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag stlParserOnceFlag;
StlParserStaticData *stlParserStaticData = nullptr;

void stlParserInitialize() {
  assert(stlParserStaticData == nullptr);
  auto staticData = std::make_unique<StlParserStaticData>(
    std::vector<std::string>{
      "file", "formula", "tformula", "placeholder", "interval", "boolean", 
      "booleanAtom", "booleanConstant", "booleanVariable", "logic", "bitSelect", 
      "logicAtom", "logicConstant", "logicVariable", "numeric", "numericAtom", 
      "numericConstant", "numericVariable", "variable", "relop"
    },
    std::vector<std::string>{
      "", "'P'", "'X'", "',bool>'", "',logic('", "')>'", "',numeric('", 
      "'..&&..'", "'F'", "'G'", "'release'", "'->'", "';'", "':'", "','", 
      "'first_match'", "", "'{'", "'}'", "'['", "']'", "'('", "')'", "", 
      "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", 
      "'<='", "'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", 
      "'&&'", "'||'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "DT_AND", "STL_EVENTUALLY", "STL_ALWAYS", 
      "RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH", "SIGN", 
      "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", 
      "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "HEX", "BOOLEAN", "PLUS", 
      "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", 
      "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,48,260,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,1,0,1,0,1,0,
  	1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,56,8,0,1,1,1,1,1,1,1,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,3,2,80,8,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,88,8,2,10,2,12,2,91,9,2,1,
  	3,1,3,1,3,1,4,1,4,1,4,3,4,99,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,135,8,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,5,1,5,1,5,1,5,1,5,5,5,149,8,5,10,5,12,5,152,9,5,1,6,1,6,3,6,156,8,6,
  	1,7,1,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,3,9,172,8,9,1,
  	9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,1,9,5,9,197,8,9,10,9,12,9,200,9,9,1,10,1,10,1,10,1,10,
  	3,10,206,8,10,1,10,1,10,1,11,1,11,3,11,212,8,11,1,12,1,12,1,13,1,13,1,
  	13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,231,
  	8,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,239,8,14,10,14,12,14,242,9,14,
  	1,15,1,15,3,15,246,8,15,1,16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,18,
  	1,18,1,19,1,19,1,19,0,4,4,10,18,28,20,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,0,4,1,0,31,32,1,0,29,30,1,0,24,27,1,0,33,36,280,
  	0,55,1,0,0,0,2,57,1,0,0,0,4,79,1,0,0,0,6,92,1,0,0,0,8,98,1,0,0,0,10,134,
  	1,0,0,0,12,155,1,0,0,0,14,157,1,0,0,0,16,159,1,0,0,0,18,171,1,0,0,0,20,
  	201,1,0,0,0,22,211,1,0,0,0,24,213,1,0,0,0,26,215,1,0,0,0,28,230,1,0,0,
  	0,30,245,1,0,0,0,32,247,1,0,0,0,34,249,1,0,0,0,36,255,1,0,0,0,38,257,
  	1,0,0,0,40,41,5,9,0,0,41,42,3,2,1,0,42,43,5,0,0,1,43,56,1,0,0,0,44,45,
  	5,9,0,0,45,46,5,19,0,0,46,47,3,8,4,0,47,48,5,14,0,0,48,49,3,8,4,0,49,
  	50,5,20,0,0,50,51,5,21,0,0,51,52,3,2,1,0,52,53,5,22,0,0,53,54,5,0,0,1,
  	54,56,1,0,0,0,55,40,1,0,0,0,55,44,1,0,0,0,56,1,1,0,0,0,57,58,3,4,2,0,
  	58,59,5,11,0,0,59,60,3,4,2,0,60,3,1,0,0,0,61,62,6,2,-1,0,62,80,3,10,5,
  	0,63,80,3,6,3,0,64,80,5,7,0,0,65,66,5,21,0,0,66,67,3,4,2,0,67,68,5,22,
  	0,0,68,80,1,0,0,0,69,70,5,47,0,0,70,80,3,4,2,4,71,72,5,8,0,0,72,73,5,
  	19,0,0,73,74,3,8,4,0,74,75,5,14,0,0,75,76,3,8,4,0,76,77,5,20,0,0,77,78,
  	3,4,2,1,78,80,1,0,0,0,79,61,1,0,0,0,79,63,1,0,0,0,79,64,1,0,0,0,79,65,
  	1,0,0,0,79,69,1,0,0,0,79,71,1,0,0,0,80,89,1,0,0,0,81,82,10,3,0,0,82,83,
  	5,45,0,0,83,88,3,4,2,4,84,85,10,2,0,0,85,86,5,46,0,0,86,88,3,4,2,3,87,
  	81,1,0,0,0,87,84,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,0,90,
  	5,1,0,0,0,91,89,1,0,0,0,92,93,5,1,0,0,93,94,5,24,0,0,94,7,1,0,0,0,95,
  	96,5,2,0,0,96,99,5,24,0,0,97,99,3,10,5,0,98,95,1,0,0,0,98,97,1,0,0,0,
  	99,9,1,0,0,0,100,101,6,5,-1,0,101,102,5,47,0,0,102,135,3,10,5,15,103,
  	104,3,18,9,0,104,105,3,38,19,0,105,106,3,18,9,0,106,135,1,0,0,0,107,108,
  	3,28,14,0,108,109,3,38,19,0,109,110,3,28,14,0,110,135,1,0,0,0,111,112,
  	3,18,9,0,112,113,5,37,0,0,113,114,3,18,9,0,114,135,1,0,0,0,115,116,3,
  	28,14,0,116,117,5,37,0,0,117,118,3,28,14,0,118,135,1,0,0,0,119,120,3,
  	18,9,0,120,121,5,38,0,0,121,122,3,18,9,0,122,135,1,0,0,0,123,124,3,28,
  	14,0,124,125,5,38,0,0,125,126,3,28,14,0,126,135,1,0,0,0,127,135,3,12,
  	6,0,128,135,3,18,9,0,129,135,3,28,14,0,130,131,5,21,0,0,131,132,3,10,
  	5,0,132,133,5,22,0,0,133,135,1,0,0,0,134,100,1,0,0,0,134,103,1,0,0,0,
  	134,107,1,0,0,0,134,111,1,0,0,0,134,115,1,0,0,0,134,119,1,0,0,0,134,123,
  	1,0,0,0,134,127,1,0,0,0,134,128,1,0,0,0,134,129,1,0,0,0,134,130,1,0,0,
  	0,135,150,1,0,0,0,136,137,10,10,0,0,137,138,5,37,0,0,138,149,3,10,5,11,
  	139,140,10,7,0,0,140,141,5,38,0,0,141,149,3,10,5,8,142,143,10,6,0,0,143,
  	144,5,45,0,0,144,149,3,10,5,7,145,146,10,5,0,0,146,147,5,46,0,0,147,149,
  	3,10,5,6,148,136,1,0,0,0,148,139,1,0,0,0,148,142,1,0,0,0,148,145,1,0,
  	0,0,149,152,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,11,1,0,0,0,152,
  	150,1,0,0,0,153,156,3,14,7,0,154,156,3,16,8,0,155,153,1,0,0,0,155,154,
  	1,0,0,0,156,13,1,0,0,0,157,158,5,28,0,0,158,15,1,0,0,0,159,160,5,35,0,
  	0,160,161,3,36,18,0,161,162,5,3,0,0,162,17,1,0,0,0,163,164,6,9,-1,0,164,
  	165,5,42,0,0,165,172,3,18,9,11,166,172,3,22,11,0,167,168,5,21,0,0,168,
  	169,3,18,9,0,169,170,5,22,0,0,170,172,1,0,0,0,171,163,1,0,0,0,171,166,
  	1,0,0,0,171,167,1,0,0,0,172,198,1,0,0,0,173,174,10,9,0,0,174,175,7,0,
  	0,0,175,197,3,18,9,10,176,177,10,8,0,0,177,178,7,1,0,0,178,197,3,18,9,
  	9,179,180,10,7,0,0,180,181,5,43,0,0,181,197,3,18,9,8,182,183,10,6,0,0,
  	183,184,5,44,0,0,184,197,3,18,9,7,185,186,10,5,0,0,186,187,5,39,0,0,187,
  	197,3,18,9,6,188,189,10,4,0,0,189,190,5,41,0,0,190,197,3,18,9,5,191,192,
  	10,3,0,0,192,193,5,40,0,0,193,197,3,18,9,4,194,195,10,10,0,0,195,197,
  	3,20,10,0,196,173,1,0,0,0,196,176,1,0,0,0,196,179,1,0,0,0,196,182,1,0,
  	0,0,196,185,1,0,0,0,196,188,1,0,0,0,196,191,1,0,0,0,196,194,1,0,0,0,197,
  	200,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,19,1,0,0,0,200,198,1,
  	0,0,0,201,202,5,19,0,0,202,205,5,24,0,0,203,204,5,13,0,0,204,206,5,24,
  	0,0,205,203,1,0,0,0,205,206,1,0,0,0,206,207,1,0,0,0,207,208,5,20,0,0,
  	208,21,1,0,0,0,209,212,3,24,12,0,210,212,3,26,13,0,211,209,1,0,0,0,211,
  	210,1,0,0,0,212,23,1,0,0,0,213,214,7,2,0,0,214,25,1,0,0,0,215,216,5,35,
  	0,0,216,217,3,36,18,0,217,218,5,4,0,0,218,219,5,16,0,0,219,220,5,14,0,
  	0,220,221,5,24,0,0,221,222,5,5,0,0,222,27,1,0,0,0,223,224,6,14,-1,0,224,
  	231,3,30,15,0,225,231,3,18,9,0,226,227,5,21,0,0,227,228,3,28,14,0,228,
  	229,5,22,0,0,229,231,1,0,0,0,230,223,1,0,0,0,230,225,1,0,0,0,230,226,
  	1,0,0,0,231,240,1,0,0,0,232,233,10,5,0,0,233,234,7,0,0,0,234,239,3,28,
  	14,6,235,236,10,4,0,0,236,237,7,1,0,0,237,239,3,28,14,5,238,232,1,0,0,
  	0,238,235,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,1,0,0,0,241,
  	29,1,0,0,0,242,240,1,0,0,0,243,246,3,32,16,0,244,246,3,34,17,0,245,243,
  	1,0,0,0,245,244,1,0,0,0,246,31,1,0,0,0,247,248,5,24,0,0,248,33,1,0,0,
  	0,249,250,5,35,0,0,250,251,3,36,18,0,251,252,5,6,0,0,252,253,5,24,0,0,
  	253,254,5,5,0,0,254,35,1,0,0,0,255,256,5,23,0,0,256,37,1,0,0,0,257,258,
  	7,3,0,0,258,39,1,0,0,0,18,55,79,87,89,98,134,148,150,155,171,196,198,
  	205,211,230,238,240,245
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  stlParserStaticData = staticData.release();
}

}

stlParser::stlParser(TokenStream *input) : stlParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

stlParser::stlParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  stlParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *stlParserStaticData->atn, stlParserStaticData->decisionToDFA, stlParserStaticData->sharedContextCache, options);
}

stlParser::~stlParser() {
  delete _interpreter;
}

const atn::ATN& stlParser::getATN() const {
  return *stlParserStaticData->atn;
}

std::string stlParser::getGrammarFileName() const {
  return "stl.g4";
}

const std::vector<std::string>& stlParser::getRuleNames() const {
  return stlParserStaticData->ruleNames;
}

const dfa::Vocabulary& stlParser::getVocabulary() const {
  return stlParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView stlParser::getSerializedATN() const {
  return stlParserStaticData->serializedATN;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

    default:
      break;
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

        default:
          break;
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
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

stlParser::BooleanContext* stlParser::IntervalContext::boolean() {
  return getRuleContext<stlParser::BooleanContext>(0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(98);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(95);
        match(stlParser::T__1);
        setState(96);
        match(stlParser::NUMERIC);
        break;
      }

      case stlParser::LPAREN:
      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX:
      case stlParser::BOOLEAN:
      case stlParser::LT:
      case stlParser::NEG:
      case stlParser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(97);
        boolean(0);
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

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(134);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(101);
      match(stlParser::NOT);
      setState(102);
      boolean(15);
      break;
    }

    case 2: {
      setState(103);
      logic(0);
      setState(104);
      relop();
      setState(105);
      logic(0);
      break;
    }

    case 3: {
      setState(107);
      numeric(0);
      setState(108);
      relop();
      setState(109);
      numeric(0);
      break;
    }

    case 4: {
      setState(111);
      logic(0);
      setState(112);
      match(stlParser::EQ);
      setState(113);
      logic(0);
      break;
    }

    case 5: {
      setState(115);
      numeric(0);
      setState(116);
      match(stlParser::EQ);
      setState(117);
      numeric(0);
      break;
    }

    case 6: {
      setState(119);
      logic(0);
      setState(120);
      match(stlParser::NEQ);
      setState(121);
      logic(0);
      break;
    }

    case 7: {
      setState(123);
      numeric(0);
      setState(124);
      match(stlParser::NEQ);
      setState(125);
      numeric(0);
      break;
    }

    case 8: {
      setState(127);
      booleanAtom();
      break;
    }

    case 9: {
      setState(128);
      logic(0);
      break;
    }

    case 10: {
      setState(129);
      numeric(0);
      break;
    }

    case 11: {
      setState(130);
      match(stlParser::LPAREN);
      setState(131);
      boolean(0);
      setState(132);
      match(stlParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(150);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(148);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(136);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(137);
          match(stlParser::EQ);
          setState(138);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(139);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(140);
          match(stlParser::NEQ);
          setState(141);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(142);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(143);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(stlParser::AND);
          setState(144);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(145);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(146);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(stlParser::OR);
          setState(147);
          boolean(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(155);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(153);
        booleanConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(154);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(159);
    match(stlParser::LT);
    setState(160);
    variable();
    setState(161);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(171);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NEG: {
        setState(164);
        match(stlParser::NEG);
        setState(165);
        logic(11);
        break;
      }

      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX:
      case stlParser::LT: {
        setState(166);
        logicAtom();
        break;
      }

      case stlParser::LPAREN: {
        setState(167);
        match(stlParser::LPAREN);
        setState(168);
        logic(0);
        setState(169);
        match(stlParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(198);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(196);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(173);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(174);
          antlrcpp::downCast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::TIMES

          || _la == stlParser::DIV)) {
            antlrcpp::downCast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(175);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(176);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(177);
          antlrcpp::downCast<LogicContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::PLUS

          || _la == stlParser::MINUS)) {
            antlrcpp::downCast<LogicContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(178);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(179);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(180);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::LSHIFT);
          setState(181);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(182);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(183);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::RSHIFT);
          setState(184);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(185);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(186);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BAND);
          setState(187);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(188);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(189);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BXOR);
          setState(190);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(191);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(192);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BOR);
          setState(193);
          logic(4);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(194);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(195);
          bitSelect();
          break;
        }

        default:
          break;
        } 
      }
      setState(200);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(stlParser::LCPAREN);
    setState(202);
    match(stlParser::NUMERIC);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == stlParser::COL) {
      setState(203);
      match(stlParser::COL);
      setState(204);
      match(stlParser::NUMERIC);
    }
    setState(207);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(211);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(209);
        logicConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(210);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 251658240) != 0))) {
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(215);
    match(stlParser::LT);
    setState(216);
    variable();
    setState(217);
    match(stlParser::T__3);
    setState(218);
    match(stlParser::SIGN);
    setState(219);
    match(stlParser::COMMA);
    setState(220);
    match(stlParser::NUMERIC);
    setState(221);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(230);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(224);
      numericAtom();
      break;
    }

    case 2: {
      setState(225);
      logic(0);
      break;
    }

    case 3: {
      setState(226);
      match(stlParser::LPAREN);
      setState(227);
      numeric(0);
      setState(228);
      match(stlParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(238);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(232);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(233);
          antlrcpp::downCast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::TIMES

          || _la == stlParser::DIV)) {
            antlrcpp::downCast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(234);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(235);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(236);
          antlrcpp::downCast<NumericContext *>(_localctx)->artop = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == stlParser::PLUS

          || _la == stlParser::MINUS)) {
            antlrcpp::downCast<NumericContext *>(_localctx)->artop = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(237);
          numeric(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(243);
        numericConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(244);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(247);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(stlParser::LT);
    setState(250);
    variable();
    setState(251);
    match(stlParser::T__5);
    setState(252);
    match(stlParser::NUMERIC);
    setState(253);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 128849018880) != 0))) {
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
    case 2: return tformulaSempred(antlrcpp::downCast<TformulaContext *>(context), predicateIndex);
    case 5: return booleanSempred(antlrcpp::downCast<BooleanContext *>(context), predicateIndex);
    case 9: return logicSempred(antlrcpp::downCast<LogicContext *>(context), predicateIndex);
    case 14: return numericSempred(antlrcpp::downCast<NumericContext *>(context), predicateIndex);

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

void stlParser::initialize() {
  ::antlr4::internal::call_once(stlParserOnceFlag, stlParserInitialize);
}
