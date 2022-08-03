
// Generated from metric.g4 by ANTLR 4.10.1


#include "metricLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct MetricLexerStaticData final {
  MetricLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MetricLexerStaticData(const MetricLexerStaticData&) = delete;
  MetricLexerStaticData(MetricLexerStaticData&&) = delete;
  MetricLexerStaticData& operator=(const MetricLexerStaticData&) = delete;
  MetricLexerStaticData& operator=(MetricLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag metriclexerLexerOnceFlag;
MetricLexerStaticData *metriclexerLexerStaticData = nullptr;

void metriclexerLexerInitialize() {
  assert(metriclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<MetricLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", 
      "RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "INDEX", "VALID_ID_START", 
      "VALID_ID_CHAR", "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "HEX", 
      "BOOLEAN", "PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", 
      "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", 
      "OR", "NOT", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "',logic('", "','", "')>'", "',numeric('", "", "'{'", "'}'", "'['", 
      "']'", "'('", "')'", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", 
      "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'&'", "'|'", 
      "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", "'!'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", 
      "LPAREN", "RPAREN", "VARIABLE", "INDEX", "NUMERIC", "VERILOG_BINARY", 
      "GCC_BINARY", "HEX", "BOOLEAN", "PLUS", "MINUS", "TIMES", "DIV", "GT", 
      "GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "LSHIFT", 
      "RSHIFT", "AND", "OR", "NOT", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,38,259,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,1,0,1,0,1,0,1,0,1,0,1,0,
  	1,0,1,0,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,5,11,
  	121,8,11,10,11,12,11,124,9,11,1,11,3,11,127,8,11,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,3,12,139,8,12,1,13,3,13,142,8,13,1,14,1,
  	14,3,14,146,8,14,1,15,3,15,149,8,15,1,15,4,15,152,8,15,11,15,12,15,153,
  	1,15,1,15,4,15,158,8,15,11,15,12,15,159,3,15,162,8,15,1,16,1,16,1,16,
  	4,16,167,8,16,11,16,12,16,168,1,17,1,17,1,17,1,17,4,17,175,8,17,11,17,
  	12,17,176,1,18,1,18,1,18,1,18,4,18,183,8,18,11,18,12,18,184,1,18,1,18,
  	1,18,1,18,4,18,191,8,18,11,18,12,18,192,3,18,195,8,18,1,19,1,19,1,19,
  	1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,208,8,19,1,20,1,20,1,21,
  	1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,
  	1,27,1,28,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,31,1,31,1,32,1,32,1,33,
  	1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,37,1,37,1,37,1,38,
  	1,38,1,39,1,39,1,39,1,39,0,0,40,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,
  	9,19,10,21,11,23,12,25,13,27,0,29,0,31,14,33,15,35,16,37,17,39,18,41,
  	19,43,20,45,21,47,22,49,23,51,24,53,25,55,26,57,27,59,28,61,29,63,30,
  	65,31,67,32,69,33,71,34,73,35,75,36,77,37,79,38,1,0,6,2,0,115,115,117,
  	117,3,0,65,90,95,95,97,122,2,0,46,46,48,57,2,0,48,57,97,102,2,0,48,57,
  	65,70,3,0,9,10,13,13,32,32,270,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,
  	7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,
  	0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,31,1,0,0,0,
  	0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,
  	1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,
  	0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,
  	0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,
  	1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,1,81,1,0,0,0,3,89,1,0,0,0,5,91,1,0,
  	0,0,7,94,1,0,0,0,9,104,1,0,0,0,11,106,1,0,0,0,13,108,1,0,0,0,15,110,1,
  	0,0,0,17,112,1,0,0,0,19,114,1,0,0,0,21,116,1,0,0,0,23,118,1,0,0,0,25,
  	138,1,0,0,0,27,141,1,0,0,0,29,145,1,0,0,0,31,148,1,0,0,0,33,163,1,0,0,
  	0,35,170,1,0,0,0,37,194,1,0,0,0,39,207,1,0,0,0,41,209,1,0,0,0,43,211,
  	1,0,0,0,45,213,1,0,0,0,47,215,1,0,0,0,49,217,1,0,0,0,51,219,1,0,0,0,53,
  	222,1,0,0,0,55,224,1,0,0,0,57,227,1,0,0,0,59,230,1,0,0,0,61,233,1,0,0,
  	0,63,235,1,0,0,0,65,237,1,0,0,0,67,239,1,0,0,0,69,241,1,0,0,0,71,244,
  	1,0,0,0,73,247,1,0,0,0,75,250,1,0,0,0,77,253,1,0,0,0,79,255,1,0,0,0,81,
  	82,5,44,0,0,82,83,5,108,0,0,83,84,5,111,0,0,84,85,5,103,0,0,85,86,5,105,
  	0,0,86,87,5,99,0,0,87,88,5,40,0,0,88,2,1,0,0,0,89,90,5,44,0,0,90,4,1,
  	0,0,0,91,92,5,41,0,0,92,93,5,62,0,0,93,6,1,0,0,0,94,95,5,44,0,0,95,96,
  	5,110,0,0,96,97,5,117,0,0,97,98,5,109,0,0,98,99,5,101,0,0,99,100,5,114,
  	0,0,100,101,5,105,0,0,101,102,5,99,0,0,102,103,5,40,0,0,103,8,1,0,0,0,
  	104,105,7,0,0,0,105,10,1,0,0,0,106,107,5,123,0,0,107,12,1,0,0,0,108,109,
  	5,125,0,0,109,14,1,0,0,0,110,111,5,91,0,0,111,16,1,0,0,0,112,113,5,93,
  	0,0,113,18,1,0,0,0,114,115,5,40,0,0,115,20,1,0,0,0,116,117,5,41,0,0,117,
  	22,1,0,0,0,118,122,3,27,13,0,119,121,3,29,14,0,120,119,1,0,0,0,121,124,
  	1,0,0,0,122,120,1,0,0,0,122,123,1,0,0,0,123,126,1,0,0,0,124,122,1,0,0,
  	0,125,127,3,25,12,0,126,125,1,0,0,0,126,127,1,0,0,0,127,24,1,0,0,0,128,
  	129,5,91,0,0,129,130,3,31,15,0,130,131,5,58,0,0,131,132,3,31,15,0,132,
  	133,5,93,0,0,133,139,1,0,0,0,134,135,5,91,0,0,135,136,3,31,15,0,136,137,
  	5,93,0,0,137,139,1,0,0,0,138,128,1,0,0,0,138,134,1,0,0,0,139,26,1,0,0,
  	0,140,142,7,1,0,0,141,140,1,0,0,0,142,28,1,0,0,0,143,146,3,27,13,0,144,
  	146,7,2,0,0,145,143,1,0,0,0,145,144,1,0,0,0,146,30,1,0,0,0,147,149,5,
  	45,0,0,148,147,1,0,0,0,148,149,1,0,0,0,149,151,1,0,0,0,150,152,2,48,57,
  	0,151,150,1,0,0,0,152,153,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,
  	161,1,0,0,0,155,157,5,46,0,0,156,158,2,48,57,0,157,156,1,0,0,0,158,159,
  	1,0,0,0,159,157,1,0,0,0,159,160,1,0,0,0,160,162,1,0,0,0,161,155,1,0,0,
  	0,161,162,1,0,0,0,162,32,1,0,0,0,163,164,5,39,0,0,164,166,5,98,0,0,165,
  	167,2,48,49,0,166,165,1,0,0,0,167,168,1,0,0,0,168,166,1,0,0,0,168,169,
  	1,0,0,0,169,34,1,0,0,0,170,171,5,48,0,0,171,172,5,98,0,0,172,174,1,0,
  	0,0,173,175,2,48,49,0,174,173,1,0,0,0,175,176,1,0,0,0,176,174,1,0,0,0,
  	176,177,1,0,0,0,177,36,1,0,0,0,178,179,5,48,0,0,179,180,5,120,0,0,180,
  	182,1,0,0,0,181,183,7,3,0,0,182,181,1,0,0,0,183,184,1,0,0,0,184,182,1,
  	0,0,0,184,185,1,0,0,0,185,195,1,0,0,0,186,187,5,48,0,0,187,188,5,120,
  	0,0,188,190,1,0,0,0,189,191,7,4,0,0,190,189,1,0,0,0,191,192,1,0,0,0,192,
  	190,1,0,0,0,192,193,1,0,0,0,193,195,1,0,0,0,194,178,1,0,0,0,194,186,1,
  	0,0,0,195,38,1,0,0,0,196,197,5,64,0,0,197,198,5,116,0,0,198,199,5,114,
  	0,0,199,200,5,117,0,0,200,208,5,101,0,0,201,202,5,64,0,0,202,203,5,102,
  	0,0,203,204,5,97,0,0,204,205,5,108,0,0,205,206,5,115,0,0,206,208,5,101,
  	0,0,207,196,1,0,0,0,207,201,1,0,0,0,208,40,1,0,0,0,209,210,5,43,0,0,210,
  	42,1,0,0,0,211,212,5,45,0,0,212,44,1,0,0,0,213,214,5,42,0,0,214,46,1,
  	0,0,0,215,216,5,47,0,0,216,48,1,0,0,0,217,218,5,62,0,0,218,50,1,0,0,0,
  	219,220,5,62,0,0,220,221,5,61,0,0,221,52,1,0,0,0,222,223,5,60,0,0,223,
  	54,1,0,0,0,224,225,5,60,0,0,225,226,5,61,0,0,226,56,1,0,0,0,227,228,5,
  	61,0,0,228,229,5,61,0,0,229,58,1,0,0,0,230,231,5,33,0,0,231,232,5,61,
  	0,0,232,60,1,0,0,0,233,234,5,38,0,0,234,62,1,0,0,0,235,236,5,124,0,0,
  	236,64,1,0,0,0,237,238,5,94,0,0,238,66,1,0,0,0,239,240,5,126,0,0,240,
  	68,1,0,0,0,241,242,5,60,0,0,242,243,5,60,0,0,243,70,1,0,0,0,244,245,5,
  	62,0,0,245,246,5,62,0,0,246,72,1,0,0,0,247,248,5,38,0,0,248,249,5,38,
  	0,0,249,74,1,0,0,0,250,251,5,124,0,0,251,252,5,124,0,0,252,76,1,0,0,0,
  	253,254,5,33,0,0,254,78,1,0,0,0,255,256,7,5,0,0,256,257,1,0,0,0,257,258,
  	6,39,0,0,258,80,1,0,0,0,18,0,122,126,138,141,145,148,153,159,161,168,
  	176,182,184,190,192,194,207,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  metriclexerLexerStaticData = staticData.release();
}

}

metricLexer::metricLexer(CharStream *input) : Lexer(input) {
  metricLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *metriclexerLexerStaticData->atn, metriclexerLexerStaticData->decisionToDFA, metriclexerLexerStaticData->sharedContextCache);
}

metricLexer::~metricLexer() {
  delete _interpreter;
}

std::string metricLexer::getGrammarFileName() const {
  return "metric.g4";
}

const std::vector<std::string>& metricLexer::getRuleNames() const {
  return metriclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& metricLexer::getChannelNames() const {
  return metriclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& metricLexer::getModeNames() const {
  return metriclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& metricLexer::getVocabulary() const {
  return metriclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView metricLexer::getSerializedATN() const {
  return metriclexerLexerStaticData->serializedATN;
}

const atn::ATN& metricLexer::getATN() const {
  return *metriclexerLexerStaticData->atn;
}




void metricLexer::initialize() {
  std::call_once(metriclexerLexerOnceFlag, metriclexerLexerInitialize);
}
