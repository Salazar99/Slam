
// Generated from stl.g4 by ANTLR 4.10.1


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

std::once_flag stlParserOnceFlag;
StlParserStaticData *stlParserStaticData = nullptr;

void stlParserInitialize() {
  assert(stlParserStaticData == nullptr);
  auto staticData = std::make_unique<StlParserStaticData>(
    std::vector<std::string>{
      "file", "implication", "tformula", "placeholder", "interval_placeholder", 
      "interval", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
      "logic", "bitSelect", "logicAtom", "logicConstant", "logicVariable", 
      "numeric", "numericAtom", "numericConstant", "numericVariable", "variable", 
      "relop"
    },
    std::vector<std::string>{
      "", "'P'", "'X'", "',bool>'", "',logic('", "')>'", "',numeric('", 
      "", "'F'", "'G'", "'release'", "'->'", "';'", "':'", "','", "'first_match'", 
      "", "'{'", "'}'", "'['", "']'", "'('", "')'", "", "", "", "", "", 
      "", "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", 
      "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", 
      "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "DT_ANDF", "STL_EVENTUALLY", "STL_ALWAYS", 
      "RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH", "SIGN", 
      "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", 
      "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "HEX", "BOOLEAN", "PLUS", 
      "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", "BAND", 
      "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,48,280,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,1,0,1,
  	0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,58,8,0,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,76,8,
  	1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,93,
  	8,2,1,2,1,2,1,2,1,2,1,2,1,2,5,2,101,8,2,10,2,12,2,104,9,2,1,3,1,3,1,3,
  	1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,119,8,5,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,
  	1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,155,8,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,5,6,169,8,6,10,6,12,6,172,9,6,1,
  	7,1,7,3,7,176,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,3,10,192,8,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,
  	10,5,10,217,8,10,10,10,12,10,220,9,10,1,11,1,11,1,11,1,11,3,11,226,8,
  	11,1,11,1,11,1,12,1,12,3,12,232,8,12,1,13,1,13,1,14,1,14,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,251,8,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,5,15,259,8,15,10,15,12,15,262,9,15,1,16,1,
  	16,3,16,266,8,16,1,17,1,17,1,18,1,18,1,18,1,18,1,18,1,18,1,19,1,19,1,
  	20,1,20,1,20,0,4,4,12,20,30,21,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,0,4,1,0,31,32,1,0,29,30,1,0,24,27,1,0,33,36,299,0,57,
  	1,0,0,0,2,75,1,0,0,0,4,92,1,0,0,0,6,105,1,0,0,0,8,108,1,0,0,0,10,118,
  	1,0,0,0,12,154,1,0,0,0,14,175,1,0,0,0,16,177,1,0,0,0,18,179,1,0,0,0,20,
  	191,1,0,0,0,22,221,1,0,0,0,24,231,1,0,0,0,26,233,1,0,0,0,28,235,1,0,0,
  	0,30,250,1,0,0,0,32,265,1,0,0,0,34,267,1,0,0,0,36,269,1,0,0,0,38,275,
  	1,0,0,0,40,277,1,0,0,0,42,43,5,9,0,0,43,44,5,21,0,0,44,45,3,2,1,0,45,
  	46,5,22,0,0,46,47,5,0,0,1,47,58,1,0,0,0,48,49,5,9,0,0,49,50,5,19,0,0,
  	50,51,3,10,5,0,51,52,5,20,0,0,52,53,5,21,0,0,53,54,3,2,1,0,54,55,5,22,
  	0,0,55,56,5,0,0,1,56,58,1,0,0,0,57,42,1,0,0,0,57,48,1,0,0,0,58,1,1,0,
  	0,0,59,60,5,7,0,0,60,61,5,11,0,0,61,62,5,8,0,0,62,63,5,19,0,0,63,64,3,
  	10,5,0,64,65,5,20,0,0,65,66,3,4,2,0,66,76,1,0,0,0,67,68,3,4,2,0,68,69,
  	5,11,0,0,69,70,5,8,0,0,70,71,5,19,0,0,71,72,3,10,5,0,72,73,5,20,0,0,73,
  	74,3,4,2,0,74,76,1,0,0,0,75,59,1,0,0,0,75,67,1,0,0,0,76,3,1,0,0,0,77,
  	78,6,2,-1,0,78,93,3,12,6,0,79,93,3,6,3,0,80,81,5,21,0,0,81,82,3,4,2,0,
  	82,83,5,22,0,0,83,93,1,0,0,0,84,85,5,47,0,0,85,93,3,4,2,4,86,87,5,8,0,
  	0,87,88,5,19,0,0,88,89,3,10,5,0,89,90,5,20,0,0,90,91,3,4,2,1,91,93,1,
  	0,0,0,92,77,1,0,0,0,92,79,1,0,0,0,92,80,1,0,0,0,92,84,1,0,0,0,92,86,1,
  	0,0,0,93,102,1,0,0,0,94,95,10,3,0,0,95,96,5,45,0,0,96,101,3,4,2,4,97,
  	98,10,2,0,0,98,99,5,46,0,0,99,101,3,4,2,3,100,94,1,0,0,0,100,97,1,0,0,
  	0,101,104,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,5,1,0,0,0,104,102,
  	1,0,0,0,105,106,5,1,0,0,106,107,5,24,0,0,107,7,1,0,0,0,108,109,5,2,0,
  	0,109,110,5,24,0,0,110,9,1,0,0,0,111,112,3,8,4,0,112,113,5,14,0,0,113,
  	114,3,8,4,0,114,119,1,0,0,0,115,116,5,24,0,0,116,117,5,14,0,0,117,119,
  	5,24,0,0,118,111,1,0,0,0,118,115,1,0,0,0,119,11,1,0,0,0,120,121,6,6,-1,
  	0,121,122,5,47,0,0,122,155,3,12,6,15,123,124,3,20,10,0,124,125,3,40,20,
  	0,125,126,3,20,10,0,126,155,1,0,0,0,127,128,3,30,15,0,128,129,3,40,20,
  	0,129,130,3,30,15,0,130,155,1,0,0,0,131,132,3,20,10,0,132,133,5,37,0,
  	0,133,134,3,20,10,0,134,155,1,0,0,0,135,136,3,30,15,0,136,137,5,37,0,
  	0,137,138,3,30,15,0,138,155,1,0,0,0,139,140,3,20,10,0,140,141,5,38,0,
  	0,141,142,3,20,10,0,142,155,1,0,0,0,143,144,3,30,15,0,144,145,5,38,0,
  	0,145,146,3,30,15,0,146,155,1,0,0,0,147,155,3,14,7,0,148,155,3,20,10,
  	0,149,155,3,30,15,0,150,151,5,21,0,0,151,152,3,12,6,0,152,153,5,22,0,
  	0,153,155,1,0,0,0,154,120,1,0,0,0,154,123,1,0,0,0,154,127,1,0,0,0,154,
  	131,1,0,0,0,154,135,1,0,0,0,154,139,1,0,0,0,154,143,1,0,0,0,154,147,1,
  	0,0,0,154,148,1,0,0,0,154,149,1,0,0,0,154,150,1,0,0,0,155,170,1,0,0,0,
  	156,157,10,10,0,0,157,158,5,37,0,0,158,169,3,12,6,11,159,160,10,7,0,0,
  	160,161,5,38,0,0,161,169,3,12,6,8,162,163,10,6,0,0,163,164,5,45,0,0,164,
  	169,3,12,6,7,165,166,10,5,0,0,166,167,5,46,0,0,167,169,3,12,6,6,168,156,
  	1,0,0,0,168,159,1,0,0,0,168,162,1,0,0,0,168,165,1,0,0,0,169,172,1,0,0,
  	0,170,168,1,0,0,0,170,171,1,0,0,0,171,13,1,0,0,0,172,170,1,0,0,0,173,
  	176,3,16,8,0,174,176,3,18,9,0,175,173,1,0,0,0,175,174,1,0,0,0,176,15,
  	1,0,0,0,177,178,5,28,0,0,178,17,1,0,0,0,179,180,5,35,0,0,180,181,3,38,
  	19,0,181,182,5,3,0,0,182,19,1,0,0,0,183,184,6,10,-1,0,184,185,5,42,0,
  	0,185,192,3,20,10,11,186,192,3,24,12,0,187,188,5,21,0,0,188,189,3,20,
  	10,0,189,190,5,22,0,0,190,192,1,0,0,0,191,183,1,0,0,0,191,186,1,0,0,0,
  	191,187,1,0,0,0,192,218,1,0,0,0,193,194,10,9,0,0,194,195,7,0,0,0,195,
  	217,3,20,10,10,196,197,10,8,0,0,197,198,7,1,0,0,198,217,3,20,10,9,199,
  	200,10,7,0,0,200,201,5,43,0,0,201,217,3,20,10,8,202,203,10,6,0,0,203,
  	204,5,44,0,0,204,217,3,20,10,7,205,206,10,5,0,0,206,207,5,39,0,0,207,
  	217,3,20,10,6,208,209,10,4,0,0,209,210,5,41,0,0,210,217,3,20,10,5,211,
  	212,10,3,0,0,212,213,5,40,0,0,213,217,3,20,10,4,214,215,10,10,0,0,215,
  	217,3,22,11,0,216,193,1,0,0,0,216,196,1,0,0,0,216,199,1,0,0,0,216,202,
  	1,0,0,0,216,205,1,0,0,0,216,208,1,0,0,0,216,211,1,0,0,0,216,214,1,0,0,
  	0,217,220,1,0,0,0,218,216,1,0,0,0,218,219,1,0,0,0,219,21,1,0,0,0,220,
  	218,1,0,0,0,221,222,5,19,0,0,222,225,5,24,0,0,223,224,5,13,0,0,224,226,
  	5,24,0,0,225,223,1,0,0,0,225,226,1,0,0,0,226,227,1,0,0,0,227,228,5,20,
  	0,0,228,23,1,0,0,0,229,232,3,26,13,0,230,232,3,28,14,0,231,229,1,0,0,
  	0,231,230,1,0,0,0,232,25,1,0,0,0,233,234,7,2,0,0,234,27,1,0,0,0,235,236,
  	5,35,0,0,236,237,3,38,19,0,237,238,5,4,0,0,238,239,5,16,0,0,239,240,5,
  	14,0,0,240,241,5,24,0,0,241,242,5,5,0,0,242,29,1,0,0,0,243,244,6,15,-1,
  	0,244,251,3,32,16,0,245,251,3,20,10,0,246,247,5,21,0,0,247,248,3,30,15,
  	0,248,249,5,22,0,0,249,251,1,0,0,0,250,243,1,0,0,0,250,245,1,0,0,0,250,
  	246,1,0,0,0,251,260,1,0,0,0,252,253,10,5,0,0,253,254,7,0,0,0,254,259,
  	3,30,15,6,255,256,10,4,0,0,256,257,7,1,0,0,257,259,3,30,15,5,258,252,
  	1,0,0,0,258,255,1,0,0,0,259,262,1,0,0,0,260,258,1,0,0,0,260,261,1,0,0,
  	0,261,31,1,0,0,0,262,260,1,0,0,0,263,266,3,34,17,0,264,266,3,36,18,0,
  	265,263,1,0,0,0,265,264,1,0,0,0,266,33,1,0,0,0,267,268,5,24,0,0,268,35,
  	1,0,0,0,269,270,5,35,0,0,270,271,3,38,19,0,271,272,5,6,0,0,272,273,5,
  	24,0,0,273,274,5,5,0,0,274,37,1,0,0,0,275,276,5,23,0,0,276,39,1,0,0,0,
  	277,278,7,3,0,0,278,41,1,0,0,0,19,57,75,92,100,102,118,154,168,170,175,
  	191,216,218,225,231,250,258,260,265
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

tree::TerminalNode* stlParser::FileContext::LPAREN() {
  return getToken(stlParser::LPAREN, 0);
}

stlParser::ImplicationContext* stlParser::FileContext::implication() {
  return getRuleContext<stlParser::ImplicationContext>(0);
}

tree::TerminalNode* stlParser::FileContext::RPAREN() {
  return getToken(stlParser::RPAREN, 0);
}

tree::TerminalNode* stlParser::FileContext::EOF() {
  return getToken(stlParser::EOF, 0);
}

tree::TerminalNode* stlParser::FileContext::LCPAREN() {
  return getToken(stlParser::LCPAREN, 0);
}

stlParser::IntervalContext* stlParser::FileContext::interval() {
  return getRuleContext<stlParser::IntervalContext>(0);
}

tree::TerminalNode* stlParser::FileContext::RCPAREN() {
  return getToken(stlParser::RCPAREN, 0);
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
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(42);
      match(stlParser::STL_ALWAYS);
      setState(43);
      match(stlParser::LPAREN);
      setState(44);
      implication();
      setState(45);
      match(stlParser::RPAREN);
      setState(46);
      match(stlParser::EOF);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(48);
      match(stlParser::STL_ALWAYS);
      setState(49);
      match(stlParser::LCPAREN);
      setState(50);
      interval();
      setState(51);
      match(stlParser::RCPAREN);
      setState(52);
      match(stlParser::LPAREN);
      setState(53);
      implication();
      setState(54);
      match(stlParser::RPAREN);
      setState(55);
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

//----------------- ImplicationContext ------------------------------------------------------------------

stlParser::ImplicationContext::ImplicationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::ImplicationContext::DT_ANDF() {
  return getToken(stlParser::DT_ANDF, 0);
}

tree::TerminalNode* stlParser::ImplicationContext::IMPL() {
  return getToken(stlParser::IMPL, 0);
}

tree::TerminalNode* stlParser::ImplicationContext::STL_EVENTUALLY() {
  return getToken(stlParser::STL_EVENTUALLY, 0);
}

tree::TerminalNode* stlParser::ImplicationContext::LCPAREN() {
  return getToken(stlParser::LCPAREN, 0);
}

stlParser::IntervalContext* stlParser::ImplicationContext::interval() {
  return getRuleContext<stlParser::IntervalContext>(0);
}

tree::TerminalNode* stlParser::ImplicationContext::RCPAREN() {
  return getToken(stlParser::RCPAREN, 0);
}

std::vector<stlParser::TformulaContext *> stlParser::ImplicationContext::tformula() {
  return getRuleContexts<stlParser::TformulaContext>();
}

stlParser::TformulaContext* stlParser::ImplicationContext::tformula(size_t i) {
  return getRuleContext<stlParser::TformulaContext>(i);
}


size_t stlParser::ImplicationContext::getRuleIndex() const {
  return stlParser::RuleImplication;
}

void stlParser::ImplicationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImplication(this);
}

void stlParser::ImplicationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImplication(this);
}

stlParser::ImplicationContext* stlParser::implication() {
  ImplicationContext *_localctx = _tracker.createInstance<ImplicationContext>(_ctx, getState());
  enterRule(_localctx, 2, stlParser::RuleImplication);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::DT_ANDF: {
        enterOuterAlt(_localctx, 1);
        setState(59);
        match(stlParser::DT_ANDF);
        setState(60);
        match(stlParser::IMPL);
        setState(61);
        match(stlParser::STL_EVENTUALLY);
        setState(62);
        match(stlParser::LCPAREN);
        setState(63);
        interval();
        setState(64);
        match(stlParser::RCPAREN);
        setState(65);
        tformula(0);
        break;
      }

      case stlParser::T__0:
      case stlParser::STL_EVENTUALLY:
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
        setState(67);
        tformula(0);
        setState(68);
        match(stlParser::IMPL);
        setState(69);
        match(stlParser::STL_EVENTUALLY);
        setState(70);
        match(stlParser::LCPAREN);
        setState(71);
        interval();
        setState(72);
        match(stlParser::RCPAREN);
        setState(73);
        tformula(0);
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

stlParser::IntervalContext* stlParser::TformulaContext::interval() {
  return getRuleContext<stlParser::IntervalContext>(0);
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
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      setState(78);
      boolean(0);
      break;
    }

    case 2: {
      setState(79);
      placeholder();
      break;
    }

    case 3: {
      setState(80);
      match(stlParser::LPAREN);
      setState(81);
      tformula(0);
      setState(82);
      match(stlParser::RPAREN);
      break;
    }

    case 4: {
      setState(84);
      match(stlParser::NOT);
      setState(85);
      tformula(4);
      break;
    }

    case 5: {
      setState(86);
      match(stlParser::STL_EVENTUALLY);
      setState(87);
      match(stlParser::LCPAREN);
      setState(88);
      interval();
      setState(89);
      match(stlParser::RCPAREN);
      setState(90);
      tformula(1);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(102);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(100);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(94);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(95);
          match(stlParser::AND);
          setState(96);
          tformula(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<TformulaContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleTformula);
          setState(97);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(98);
          match(stlParser::OR);
          setState(99);
          tformula(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(104);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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
    setState(105);
    match(stlParser::T__0);
    setState(106);
    match(stlParser::NUMERIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Interval_placeholderContext ------------------------------------------------------------------

stlParser::Interval_placeholderContext::Interval_placeholderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* stlParser::Interval_placeholderContext::NUMERIC() {
  return getToken(stlParser::NUMERIC, 0);
}


size_t stlParser::Interval_placeholderContext::getRuleIndex() const {
  return stlParser::RuleInterval_placeholder;
}

void stlParser::Interval_placeholderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterval_placeholder(this);
}

void stlParser::Interval_placeholderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<stlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterval_placeholder(this);
}

stlParser::Interval_placeholderContext* stlParser::interval_placeholder() {
  Interval_placeholderContext *_localctx = _tracker.createInstance<Interval_placeholderContext>(_ctx, getState());
  enterRule(_localctx, 8, stlParser::RuleInterval_placeholder);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(stlParser::T__1);
    setState(109);
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

std::vector<stlParser::Interval_placeholderContext *> stlParser::IntervalContext::interval_placeholder() {
  return getRuleContexts<stlParser::Interval_placeholderContext>();
}

stlParser::Interval_placeholderContext* stlParser::IntervalContext::interval_placeholder(size_t i) {
  return getRuleContext<stlParser::Interval_placeholderContext>(i);
}

tree::TerminalNode* stlParser::IntervalContext::COMMA() {
  return getToken(stlParser::COMMA, 0);
}

std::vector<tree::TerminalNode *> stlParser::IntervalContext::NUMERIC() {
  return getTokens(stlParser::NUMERIC);
}

tree::TerminalNode* stlParser::IntervalContext::NUMERIC(size_t i) {
  return getToken(stlParser::NUMERIC, i);
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
  enterRule(_localctx, 10, stlParser::RuleInterval);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(118);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::T__1: {
        enterOuterAlt(_localctx, 1);
        setState(111);
        interval_placeholder();
        setState(112);
        match(stlParser::COMMA);
        setState(113);
        interval_placeholder();
        break;
      }

      case stlParser::NUMERIC: {
        enterOuterAlt(_localctx, 2);
        setState(115);
        match(stlParser::NUMERIC);
        setState(116);
        match(stlParser::COMMA);
        setState(117);
        match(stlParser::NUMERIC);
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
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, stlParser::RuleBoolean, precedence);

    

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
    setState(154);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(121);
      match(stlParser::NOT);
      setState(122);
      boolean(15);
      break;
    }

    case 2: {
      setState(123);
      logic(0);
      setState(124);
      relop();
      setState(125);
      logic(0);
      break;
    }

    case 3: {
      setState(127);
      numeric(0);
      setState(128);
      relop();
      setState(129);
      numeric(0);
      break;
    }

    case 4: {
      setState(131);
      logic(0);
      setState(132);
      match(stlParser::EQ);
      setState(133);
      logic(0);
      break;
    }

    case 5: {
      setState(135);
      numeric(0);
      setState(136);
      match(stlParser::EQ);
      setState(137);
      numeric(0);
      break;
    }

    case 6: {
      setState(139);
      logic(0);
      setState(140);
      match(stlParser::NEQ);
      setState(141);
      logic(0);
      break;
    }

    case 7: {
      setState(143);
      numeric(0);
      setState(144);
      match(stlParser::NEQ);
      setState(145);
      numeric(0);
      break;
    }

    case 8: {
      setState(147);
      booleanAtom();
      break;
    }

    case 9: {
      setState(148);
      logic(0);
      break;
    }

    case 10: {
      setState(149);
      numeric(0);
      break;
    }

    case 11: {
      setState(150);
      match(stlParser::LPAREN);
      setState(151);
      boolean(0);
      setState(152);
      match(stlParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(170);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(168);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(156);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(157);
          match(stlParser::EQ);
          setState(158);
          boolean(11);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(159);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(160);
          match(stlParser::NEQ);
          setState(161);
          boolean(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(162);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(163);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(stlParser::AND);
          setState(164);
          boolean(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<BooleanContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleBoolean);
          setState(165);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(166);
          antlrcpp::downCast<BooleanContext *>(_localctx)->booleanop = match(stlParser::OR);
          setState(167);
          boolean(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(172);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
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
  enterRule(_localctx, 14, stlParser::RuleBooleanAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(175);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::BOOLEAN: {
        enterOuterAlt(_localctx, 1);
        setState(173);
        booleanConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(174);
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
  enterRule(_localctx, 16, stlParser::RuleBooleanConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(177);
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
  enterRule(_localctx, 18, stlParser::RuleBooleanVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    match(stlParser::LT);
    setState(180);
    variable();
    setState(181);
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
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, stlParser::RuleLogic, precedence);

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
    setState(191);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NEG: {
        setState(184);
        match(stlParser::NEG);
        setState(185);
        logic(11);
        break;
      }

      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX:
      case stlParser::LT: {
        setState(186);
        logicAtom();
        break;
      }

      case stlParser::LPAREN: {
        setState(187);
        match(stlParser::LPAREN);
        setState(188);
        logic(0);
        setState(189);
        match(stlParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(193);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(194);
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
          setState(195);
          logic(10);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(196);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(197);
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
          setState(198);
          logic(9);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(199);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(200);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::LSHIFT);
          setState(201);
          logic(8);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(202);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(203);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::RSHIFT);
          setState(204);
          logic(7);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(205);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(206);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BAND);
          setState(207);
          logic(6);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(208);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(209);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BXOR);
          setState(210);
          logic(5);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(211);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(212);
          antlrcpp::downCast<LogicContext *>(_localctx)->logop = match(stlParser::BOR);
          setState(213);
          logic(4);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<LogicContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogic);
          setState(214);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(215);
          bitSelect();
          break;
        }

        default:
          break;
        } 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
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
  enterRule(_localctx, 22, stlParser::RuleBitSelect);
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
    setState(221);
    match(stlParser::LCPAREN);
    setState(222);
    match(stlParser::NUMERIC);
    setState(225);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == stlParser::COL) {
      setState(223);
      match(stlParser::COL);
      setState(224);
      match(stlParser::NUMERIC);
    }
    setState(227);
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
  enterRule(_localctx, 24, stlParser::RuleLogicAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC:
      case stlParser::VERILOG_BINARY:
      case stlParser::GCC_BINARY:
      case stlParser::HEX: {
        enterOuterAlt(_localctx, 1);
        setState(229);
        logicConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(230);
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
  enterRule(_localctx, 26, stlParser::RuleLogicConstant);
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
    setState(233);
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
  enterRule(_localctx, 28, stlParser::RuleLogicVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(stlParser::LT);
    setState(236);
    variable();
    setState(237);
    match(stlParser::T__3);
    setState(238);
    match(stlParser::SIGN);
    setState(239);
    match(stlParser::COMMA);
    setState(240);
    match(stlParser::NUMERIC);
    setState(241);
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
  size_t startState = 30;
  enterRecursionRule(_localctx, 30, stlParser::RuleNumeric, precedence);

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
    setState(250);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(244);
      numericAtom();
      break;
    }

    case 2: {
      setState(245);
      logic(0);
      break;
    }

    case 3: {
      setState(246);
      match(stlParser::LPAREN);
      setState(247);
      numeric(0);
      setState(248);
      match(stlParser::RPAREN);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(260);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(258);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(252);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(253);
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
          setState(254);
          numeric(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumericContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumeric);
          setState(255);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(256);
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
          setState(257);
          numeric(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(262);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
  enterRule(_localctx, 32, stlParser::RuleNumericAtom);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case stlParser::NUMERIC: {
        enterOuterAlt(_localctx, 1);
        setState(263);
        numericConstant();
        break;
      }

      case stlParser::LT: {
        enterOuterAlt(_localctx, 2);
        setState(264);
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
  enterRule(_localctx, 34, stlParser::RuleNumericConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
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
  enterRule(_localctx, 36, stlParser::RuleNumericVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    match(stlParser::LT);
    setState(270);
    variable();
    setState(271);
    match(stlParser::T__5);
    setState(272);
    match(stlParser::NUMERIC);
    setState(273);
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
  enterRule(_localctx, 38, stlParser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
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
  enterRule(_localctx, 40, stlParser::RuleRelop);
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
    setState(277);
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
    case 2: return tformulaSempred(antlrcpp::downCast<TformulaContext *>(context), predicateIndex);
    case 6: return booleanSempred(antlrcpp::downCast<BooleanContext *>(context), predicateIndex);
    case 10: return logicSempred(antlrcpp::downCast<LogicContext *>(context), predicateIndex);
    case 15: return numericSempred(antlrcpp::downCast<NumericContext *>(context), predicateIndex);

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
  std::call_once(stlParserOnceFlag, stlParserInitialize);
}
