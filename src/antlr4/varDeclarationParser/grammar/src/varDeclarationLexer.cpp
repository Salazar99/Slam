
// Generated from varDeclaration.g4 by ANTLR 4.10.1

#include "varDeclarationLexer.h"

using namespace antlr4;

using namespace antlr4;

namespace {

struct VarDeclarationLexerStaticData final {
  VarDeclarationLexerStaticData(std::vector<std::string> ruleNames,
                                std::vector<std::string> channelNames,
                                std::vector<std::string> modeNames,
                                std::vector<std::string> literalNames,
                                std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  VarDeclarationLexerStaticData(const VarDeclarationLexerStaticData &) = delete;
  VarDeclarationLexerStaticData(VarDeclarationLexerStaticData &&) = delete;
  VarDeclarationLexerStaticData &
  operator=(const VarDeclarationLexerStaticData &) = delete;
  VarDeclarationLexerStaticData &
  operator=(VarDeclarationLexerStaticData &&) = delete;

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

std::once_flag vardeclarationlexerLexerOnceFlag;
VarDeclarationLexerStaticData *vardeclarationlexerLexerStaticData = nullptr;

void vardeclarationlexerLexerInitialize() {
  assert(vardeclarationlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<VarDeclarationLexerStaticData>(
      std::vector<std::string>{"T__0", "T__1", "T__2", "VARTYPE", "NAME",
                               "VALID_ID_START", "VALID_ID_CHAR", "NUMERIC",
                               "WS"},
      std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"},
      std::vector<std::string>{"DEFAULT_MODE"},
      std::vector<std::string>{"", "'['", "':'", "']'"},
      std::vector<std::string>{"", "", "", "", "VARTYPE", "NAME", "NUMERIC",
                               "WS"});
  static const int32_t serializedATNSegment[] = {
      4,   0,   7,   239, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,  2,
      2,   7,   2,   2,   3,   7,   3,   2,   4,   7,   4,   2,   5,   7,  5,
      2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   1,   0,  1,
      0,   1,   1,   1,   1,   1,   2,   1,   2,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,  1,
      3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,  3,
      1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   3,   3,  215,
      8,   3,   1,   4,   1,   4,   5,   4,   219, 8,   4,   10,  4,   12, 4,
      222, 9,   4,   1,   5,   3,   5,   225, 8,   5,   1,   6,   1,   6,  3,
      6,   229, 8,   6,   1,   7,   4,   7,   232, 8,   7,   11,  7,   12, 7,
      233, 1,   8,   1,   8,   1,   8,   1,   8,   0,   0,   9,   1,   1,  3,
      2,   5,   3,   7,   4,   9,   5,   11,  0,   13,  0,   15,  6,   17, 7,
      1,   0,   3,   3,   0,   65,  90,  95,  95,  97,  122, 2,   0,   46, 46,
      48,  57,  3,   0,   9,   10,  13,  13,  32,  32,  261, 0,   1,   1,  0,
      0,   0,   0,   3,   1,   0,   0,   0,   0,   5,   1,   0,   0,   0,  0,
      7,   1,   0,   0,   0,   0,   9,   1,   0,   0,   0,   0,   15,  1,  0,
      0,   0,   0,   17,  1,   0,   0,   0,   1,   19,  1,   0,   0,   0,  3,
      21,  1,   0,   0,   0,   5,   23,  1,   0,   0,   0,   7,   214, 1,  0,
      0,   0,   9,   216, 1,   0,   0,   0,   11,  224, 1,   0,   0,   0,  13,
      228, 1,   0,   0,   0,   15,  231, 1,   0,   0,   0,   17,  235, 1,  0,
      0,   0,   19,  20,  5,   91,  0,   0,   20,  2,   1,   0,   0,   0,  21,
      22,  5,   58,  0,   0,   22,  4,   1,   0,   0,   0,   23,  24,  5,  93,
      0,   0,   24,  6,   1,   0,   0,   0,   25,  26,  5,   98,  0,   0,  26,
      27,  5,   111, 0,   0,   27,  28,  5,   111, 0,   0,   28,  215, 5,  108,
      0,   0,   29,  30,  5,   117, 0,   0,   30,  31,  5,   110, 0,   0,  31,
      32,  5,   115, 0,   0,   32,  33,  5,   105, 0,   0,   33,  34,  5,  103,
      0,   0,   34,  35,  5,   110, 0,   0,   35,  36,  5,   101, 0,   0,  36,
      37,  5,   100, 0,   0,   37,  38,  5,   32,  0,   0,   38,  39,  5,  99,
      0,   0,   39,  40,  5,   104, 0,   0,   40,  41,  5,   97,  0,   0,  41,
      215, 5,   114, 0,   0,   42,  43,  5,   117, 0,   0,   43,  44,  5,  110,
      0,   0,   44,  45,  5,   115, 0,   0,   45,  46,  5,   105, 0,   0,  46,
      47,  5,   103, 0,   0,   47,  48,  5,   110, 0,   0,   48,  49,  5,  101,
      0,   0,   49,  50,  5,   100, 0,   0,   50,  51,  5,   32,  0,   0,  51,
      52,  5,   115, 0,   0,   52,  53,  5,   104, 0,   0,   53,  54,  5,  111,
      0,   0,   54,  55,  5,   114, 0,   0,   55,  215, 5,   116, 0,   0,  56,
      57,  5,   117, 0,   0,   57,  58,  5,   110, 0,   0,   58,  59,  5,  115,
      0,   0,   59,  60,  5,   105, 0,   0,   60,  61,  5,   103, 0,   0,  61,
      62,  5,   110, 0,   0,   62,  63,  5,   101, 0,   0,   63,  64,  5,  100,
      0,   0,   64,  65,  5,   32,  0,   0,   65,  66,  5,   105, 0,   0,  66,
      67,  5,   110, 0,   0,   67,  215, 5,   116, 0,   0,   68,  69,  5,  117,
      0,   0,   69,  70,  5,   110, 0,   0,   70,  71,  5,   115, 0,   0,  71,
      72,  5,   105, 0,   0,   72,  73,  5,   103, 0,   0,   73,  74,  5,  110,
      0,   0,   74,  75,  5,   101, 0,   0,   75,  76,  5,   100, 0,   0,  76,
      77,  5,   32,  0,   0,   77,  78,  5,   108, 0,   0,   78,  79,  5,  111,
      0,   0,   79,  80,  5,   110, 0,   0,   80,  81,  5,   103, 0,   0,  81,
      82,  5,   32,  0,   0,   82,  83,  5,   105, 0,   0,   83,  84,  5,  110,
      0,   0,   84,  215, 5,   116, 0,   0,   85,  86,  5,   99,  0,   0,  86,
      87,  5,   104, 0,   0,   87,  88,  5,   97,  0,   0,   88,  215, 5,  114,
      0,   0,   89,  90,  5,   115, 0,   0,   90,  91,  5,   104, 0,   0,  91,
      92,  5,   111, 0,   0,   92,  93,  5,   114, 0,   0,   93,  215, 5,  116,
      0,   0,   94,  95,  5,   105, 0,   0,   95,  96,  5,   110, 0,   0,  96,
      215, 5,   116, 0,   0,   97,  98,  5,   108, 0,   0,   98,  99,  5,  111,
      0,   0,   99,  100, 5,   110, 0,   0,   100, 101, 5,   103, 0,   0,  101,
      102, 5,   32,  0,   0,   102, 103, 5,   105, 0,   0,   103, 104, 5,  110,
      0,   0,   104, 215, 5,   116, 0,   0,   105, 106, 5,   102, 0,   0,  106,
      107, 5,   108, 0,   0,   107, 108, 5,   111, 0,   0,   108, 109, 5,  97,
      0,   0,   109, 215, 5,   116, 0,   0,   110, 111, 5,   100, 0,   0,  111,
      112, 5,   111, 0,   0,   112, 113, 5,   117, 0,   0,   113, 114, 5,  98,
      0,   0,   114, 115, 5,   108, 0,   0,   115, 215, 5,   101, 0,   0,  116,
      117, 5,   98,  0,   0,   117, 118, 5,   121, 0,   0,   118, 119, 5,  116,
      0,   0,   119, 215, 5,   101, 0,   0,   120, 121, 5,   115, 0,   0,  121,
      122, 5,   104, 0,   0,   122, 123, 5,   111, 0,   0,   123, 124, 5,  114,
      0,   0,   124, 125, 5,   116, 0,   0,   125, 126, 5,   105, 0,   0,  126,
      127, 5,   110, 0,   0,   127, 215, 5,   116, 0,   0,   128, 129, 5,  108,
      0,   0,   129, 130, 5,   111, 0,   0,   130, 131, 5,   110, 0,   0,  131,
      132, 5,   103, 0,   0,   132, 133, 5,   105, 0,   0,   133, 134, 5,  110,
      0,   0,   134, 215, 5,   116, 0,   0,   135, 136, 5,   98,  0,   0,  136,
      137, 5,   121, 0,   0,   137, 138, 5,   116, 0,   0,   138, 139, 5,  101,
      0,   0,   139, 140, 5,   32,  0,   0,   140, 141, 5,   117, 0,   0,  141,
      142, 5,   110, 0,   0,   142, 143, 5,   115, 0,   0,   143, 144, 5,  105,
      0,   0,   144, 145, 5,   103, 0,   0,   145, 146, 5,   110, 0,   0,  146,
      147, 5,   101, 0,   0,   147, 215, 5,   100, 0,   0,   148, 149, 5,  115,
      0,   0,   149, 150, 5,   104, 0,   0,   150, 151, 5,   111, 0,   0,  151,
      152, 5,   114, 0,   0,   152, 153, 5,   116, 0,   0,   153, 154, 5,  105,
      0,   0,   154, 155, 5,   110, 0,   0,   155, 156, 5,   116, 0,   0,  156,
      157, 5,   32,  0,   0,   157, 158, 5,   117, 0,   0,   158, 159, 5,  110,
      0,   0,   159, 160, 5,   115, 0,   0,   160, 161, 5,   105, 0,   0,  161,
      162, 5,   103, 0,   0,   162, 163, 5,   110, 0,   0,   163, 164, 5,  101,
      0,   0,   164, 215, 5,   100, 0,   0,   165, 166, 5,   108, 0,   0,  166,
      167, 5,   111, 0,   0,   167, 168, 5,   110, 0,   0,   168, 169, 5,  103,
      0,   0,   169, 170, 5,   105, 0,   0,   170, 171, 5,   110, 0,   0,  171,
      172, 5,   116, 0,   0,   172, 173, 5,   32,  0,   0,   173, 174, 5,  117,
      0,   0,   174, 175, 5,   110, 0,   0,   175, 176, 5,   115, 0,   0,  176,
      177, 5,   105, 0,   0,   177, 178, 5,   103, 0,   0,   178, 179, 5,  110,
      0,   0,   179, 180, 5,   101, 0,   0,   180, 215, 5,   100, 0,   0,  181,
      182, 5,   116, 0,   0,   182, 183, 5,   105, 0,   0,   183, 184, 5,  109,
      0,   0,   184, 215, 5,   101, 0,   0,   185, 186, 5,   115, 0,   0,  186,
      187, 5,   104, 0,   0,   187, 188, 5,   111, 0,   0,   188, 189, 5,  114,
      0,   0,   189, 190, 5,   116, 0,   0,   190, 191, 5,   114, 0,   0,  191,
      192, 5,   101, 0,   0,   192, 193, 5,   97,  0,   0,   193, 215, 5,  108,
      0,   0,   194, 195, 5,   114, 0,   0,   195, 196, 5,   101, 0,   0,  196,
      197, 5,   97,  0,   0,   197, 215, 5,   108, 0,   0,   198, 199, 5,  114,
      0,   0,   199, 200, 5,   101, 0,   0,   200, 215, 5,   103, 0,   0,  201,
      202, 5,   119, 0,   0,   202, 203, 5,   105, 0,   0,   203, 204, 5,  114,
      0,   0,   204, 215, 5,   101, 0,   0,   205, 206, 5,   108, 0,   0,  206,
      207, 5,   111, 0,   0,   207, 208, 5,   103, 0,   0,   208, 209, 5,  105,
      0,   0,   209, 210, 5,   99,  0,   0,   210, 211, 1,   0,   0,   0,  211,
      212, 5,   98,  0,   0,   212, 213, 5,   105, 0,   0,   213, 215, 5,  116,
      0,   0,   214, 25,  1,   0,   0,   0,   214, 29,  1,   0,   0,   0,  214,
      42,  1,   0,   0,   0,   214, 56,  1,   0,   0,   0,   214, 68,  1,  0,
      0,   0,   214, 85,  1,   0,   0,   0,   214, 89,  1,   0,   0,   0,  214,
      94,  1,   0,   0,   0,   214, 97,  1,   0,   0,   0,   214, 105, 1,  0,
      0,   0,   214, 110, 1,   0,   0,   0,   214, 116, 1,   0,   0,   0,  214,
      120, 1,   0,   0,   0,   214, 128, 1,   0,   0,   0,   214, 135, 1,  0,
      0,   0,   214, 148, 1,   0,   0,   0,   214, 165, 1,   0,   0,   0,  214,
      181, 1,   0,   0,   0,   214, 185, 1,   0,   0,   0,   214, 194, 1,  0,
      0,   0,   214, 198, 1,   0,   0,   0,   214, 201, 1,   0,   0,   0,  214,
      205, 1,   0,   0,   0,   215, 8,   1,   0,   0,   0,   216, 220, 3,  11,
      5,   0,   217, 219, 3,   13,  6,   0,   218, 217, 1,   0,   0,   0,  219,
      222, 1,   0,   0,   0,   220, 218, 1,   0,   0,   0,   220, 221, 1,  0,
      0,   0,   221, 10,  1,   0,   0,   0,   222, 220, 1,   0,   0,   0,  223,
      225, 7,   0,   0,   0,   224, 223, 1,   0,   0,   0,   225, 12,  1,  0,
      0,   0,   226, 229, 3,   11,  5,   0,   227, 229, 7,   1,   0,   0,  228,
      226, 1,   0,   0,   0,   228, 227, 1,   0,   0,   0,   229, 14,  1,  0,
      0,   0,   230, 232, 2,   48,  57,  0,   231, 230, 1,   0,   0,   0,  232,
      233, 1,   0,   0,   0,   233, 231, 1,   0,   0,   0,   233, 234, 1,  0,
      0,   0,   234, 16,  1,   0,   0,   0,   235, 236, 7,   2,   0,   0,  236,
      237, 1,   0,   0,   0,   237, 238, 6,   8,   0,   0,   238, 18,  1,  0,
      0,   0,   6,   0,   214, 220, 224, 228, 233, 1,   6,   0,   0};
  staticData->serializedATN = antlr4::atn::SerializedATNView(
      serializedATNSegment,
      sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) {
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i),
                                           i);
  }
  vardeclarationlexerLexerStaticData = staticData.release();
}

} // namespace

varDeclarationLexer::varDeclarationLexer(CharStream *input) : Lexer(input) {
  varDeclarationLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(
      this, *vardeclarationlexerLexerStaticData->atn,
      vardeclarationlexerLexerStaticData->decisionToDFA,
      vardeclarationlexerLexerStaticData->sharedContextCache);
}

varDeclarationLexer::~varDeclarationLexer() { delete _interpreter; }

std::string varDeclarationLexer::getGrammarFileName() const {
  return "varDeclaration.g4";
}

const std::vector<std::string> &varDeclarationLexer::getRuleNames() const {
  return vardeclarationlexerLexerStaticData->ruleNames;
}

const std::vector<std::string> &varDeclarationLexer::getChannelNames() const {
  return vardeclarationlexerLexerStaticData->channelNames;
}

const std::vector<std::string> &varDeclarationLexer::getModeNames() const {
  return vardeclarationlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary &varDeclarationLexer::getVocabulary() const {
  return vardeclarationlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView varDeclarationLexer::getSerializedATN() const {
  return vardeclarationlexerLexerStaticData->serializedATN;
}

const atn::ATN &varDeclarationLexer::getATN() const {
  return *vardeclarationlexerLexerStaticData->atn;
}

void varDeclarationLexer::initialize() {
  std::call_once(vardeclarationlexerLexerOnceFlag,
                 vardeclarationlexerLexerInitialize);
}
