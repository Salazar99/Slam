
// Generated from limits.g4 by ANTLR 4.12.0


#include "limitsLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct LimitsLexerStaticData final {
  LimitsLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  LimitsLexerStaticData(const LimitsLexerStaticData&) = delete;
  LimitsLexerStaticData(LimitsLexerStaticData&&) = delete;
  LimitsLexerStaticData& operator=(const LimitsLexerStaticData&) = delete;
  LimitsLexerStaticData& operator=(LimitsLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag limitslexerLexerOnceFlag;
LimitsLexerStaticData *limitslexerLexerStaticData = nullptr;

void limitslexerLexerInitialize() {
  assert(limitslexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<LimitsLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
      "SEQ", "RAN", "NOT", "NUMERIC", "WS"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,14,79,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,
  	6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,1,11,1,12,3,12,61,8,12,1,
  	12,4,12,64,8,12,11,12,12,12,65,1,12,1,12,4,12,70,8,12,11,12,12,12,71,
  	3,12,74,8,12,1,13,1,13,1,13,1,13,0,0,14,1,1,3,2,5,3,7,4,9,5,11,6,13,7,
  	15,8,17,9,19,10,21,11,23,12,25,13,27,14,1,0,1,3,0,9,10,13,13,32,32,82,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,1,29,1,0,0,0,3,31,1,0,0,0,5,36,
  	1,0,0,0,7,41,1,0,0,0,9,43,1,0,0,0,11,45,1,0,0,0,13,47,1,0,0,0,15,49,1,
  	0,0,0,17,51,1,0,0,0,19,53,1,0,0,0,21,55,1,0,0,0,23,57,1,0,0,0,25,60,1,
  	0,0,0,27,75,1,0,0,0,29,30,5,44,0,0,30,2,1,0,0,0,31,32,5,109,0,0,32,33,
  	5,97,0,0,33,34,5,120,0,0,34,35,5,100,0,0,35,4,1,0,0,0,36,37,5,109,0,0,
  	37,38,5,105,0,0,38,39,5,110,0,0,39,40,5,100,0,0,40,6,1,0,0,0,41,42,5,
  	68,0,0,42,8,1,0,0,0,43,44,5,87,0,0,44,10,1,0,0,0,45,46,5,65,0,0,46,12,
  	1,0,0,0,47,48,5,79,0,0,48,14,1,0,0,0,49,50,5,78,0,0,50,16,1,0,0,0,51,
  	52,5,69,0,0,52,18,1,0,0,0,53,54,5,83,0,0,54,20,1,0,0,0,55,56,5,82,0,0,
  	56,22,1,0,0,0,57,58,5,33,0,0,58,24,1,0,0,0,59,61,5,45,0,0,60,59,1,0,0,
  	0,60,61,1,0,0,0,61,63,1,0,0,0,62,64,2,48,57,0,63,62,1,0,0,0,64,65,1,0,
  	0,0,65,63,1,0,0,0,65,66,1,0,0,0,66,73,1,0,0,0,67,69,5,46,0,0,68,70,2,
  	48,57,0,69,68,1,0,0,0,70,71,1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,74,
  	1,0,0,0,73,67,1,0,0,0,73,74,1,0,0,0,74,26,1,0,0,0,75,76,7,0,0,0,76,77,
  	1,0,0,0,77,78,6,13,0,0,78,28,1,0,0,0,5,0,60,65,71,73,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  limitslexerLexerStaticData = staticData.release();
}

}

limitsLexer::limitsLexer(CharStream *input) : Lexer(input) {
  limitsLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *limitslexerLexerStaticData->atn, limitslexerLexerStaticData->decisionToDFA, limitslexerLexerStaticData->sharedContextCache);
}

limitsLexer::~limitsLexer() {
  delete _interpreter;
}

std::string limitsLexer::getGrammarFileName() const {
  return "limits.g4";
}

const std::vector<std::string>& limitsLexer::getRuleNames() const {
  return limitslexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& limitsLexer::getChannelNames() const {
  return limitslexerLexerStaticData->channelNames;
}

const std::vector<std::string>& limitsLexer::getModeNames() const {
  return limitslexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& limitsLexer::getVocabulary() const {
  return limitslexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView limitsLexer::getSerializedATN() const {
  return limitslexerLexerStaticData->serializedATN;
}

const atn::ATN& limitsLexer::getATN() const {
  return *limitslexerLexerStaticData->atn;
}




void limitsLexer::initialize() {
  ::antlr4::internal::call_once(limitslexerLexerOnceFlag, limitslexerLexerInitialize);
}
