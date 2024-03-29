
// Generated from spot.g4 by ANTLR 4.10.1

#include "spotLexer.h"

using namespace antlr4;

using namespace antlr4;

namespace {

struct SpotLexerStaticData final {
  SpotLexerStaticData(std::vector<std::string> ruleNames,
                      std::vector<std::string> channelNames,
                      std::vector<std::string> modeNames,
                      std::vector<std::string> literalNames,
                      std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  SpotLexerStaticData(const SpotLexerStaticData &) = delete;
  SpotLexerStaticData(SpotLexerStaticData &&) = delete;
  SpotLexerStaticData &operator=(const SpotLexerStaticData &) = delete;
  SpotLexerStaticData &operator=(SpotLexerStaticData &&) = delete;

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

std::once_flag spotlexerLexerOnceFlag;
SpotLexerStaticData *spotlexerLexerStaticData = nullptr;

void spotlexerLexerInitialize() {
  assert(spotlexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<SpotLexerStaticData>(
      std::vector<std::string>{"T__0",
                               "T__1",
                               "T__2",
                               "T__3",
                               "T__4",
                               "T__5",
                               "T__6",
                               "T__7",
                               "T__8",
                               "DT_AND",
                               "SEP",
                               "EVENTUALLY",
                               "ALWAYS",
                               "NEXT",
                               "UNTIL",
                               "RELEASE",
                               "DOTS",
                               "IMPL",
                               "IMPL2",
                               "IFF",
                               "XOR",
                               "BIND1",
                               "BIND2",
                               "SEREIMPL1",
                               "SEREIMPL2",
                               "ASS",
                               "DELAY",
                               "SCOL",
                               "COL",
                               "FIRST_MATCH",
                               "SIGN",
                               "LGPAREN",
                               "RGPAREN",
                               "LCPAREN",
                               "RCPAREN",
                               "LPAREN",
                               "RPAREN",
                               "VARIABLE",
                               "VALID_ID_START",
                               "VALID_ID_CHAR",
                               "NUMERIC",
                               "VERILOG_BINARY",
                               "GCC_BINARY",
                               "HEX",
                               "BOOLEAN",
                               "PLUS",
                               "MINUS",
                               "TIMES",
                               "DIV",
                               "GT",
                               "GE",
                               "LT",
                               "LE",
                               "EQ",
                               "NEQ",
                               "BAND",
                               "BOR",
                               "BXOR",
                               "NEG",
                               "LSHIFT",
                               "RSHIFT",
                               "AND",
                               "OR",
                               "NOT",
                               "WS"},
      std::vector<std::string>{"DEFAULT_TOKEN_CHANNEL", "HIDDEN"},
      std::vector<std::string>{"DEFAULT_MODE"},
      std::vector<std::string>{"",
                               "'P'",
                               "'..##'",
                               "'..#'",
                               "'..[->'",
                               "',bool>'",
                               "',logic('",
                               "','",
                               "')>'",
                               "',numeric('",
                               "'..&&..'",
                               "",
                               "'F'",
                               "'G'",
                               "'X'",
                               "'U'",
                               "'R'",
                               "'..'",
                               "'->'",
                               "'=>'",
                               "'<->'",
                               "'xor'",
                               "'[]->'",
                               "'[]=>'",
                               "'|->'",
                               "'|=>'",
                               "'='",
                               "'##'",
                               "';'",
                               "':'",
                               "'first_match'",
                               "",
                               "'{'",
                               "'}'",
                               "'['",
                               "']'",
                               "'('",
                               "')'",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "'+'",
                               "'-'",
                               "'*'",
                               "'/'",
                               "'>'",
                               "'>='",
                               "'<'",
                               "'<='",
                               "'=='",
                               "'!='",
                               "'&'",
                               "'|'",
                               "'^'",
                               "'~'",
                               "'<<'",
                               "'>>'",
                               "'&&'",
                               "'||'",
                               "'!'"},
      std::vector<std::string>{"",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "",
                               "DT_AND",
                               "SEP",
                               "EVENTUALLY",
                               "ALWAYS",
                               "NEXT",
                               "UNTIL",
                               "RELEASE",
                               "DOTS",
                               "IMPL",
                               "IMPL2",
                               "IFF",
                               "XOR",
                               "BIND1",
                               "BIND2",
                               "SEREIMPL1",
                               "SEREIMPL2",
                               "ASS",
                               "DELAY",
                               "SCOL",
                               "COL",
                               "FIRST_MATCH",
                               "SIGN",
                               "LGPAREN",
                               "RGPAREN",
                               "LCPAREN",
                               "RCPAREN",
                               "LPAREN",
                               "RPAREN",
                               "VARIABLE",
                               "NUMERIC",
                               "VERILOG_BINARY",
                               "GCC_BINARY",
                               "HEX",
                               "BOOLEAN",
                               "PLUS",
                               "MINUS",
                               "TIMES",
                               "DIV",
                               "GT",
                               "GE",
                               "LT",
                               "LE",
                               "EQ",
                               "NEQ",
                               "BAND",
                               "BOR",
                               "BXOR",
                               "NEG",
                               "LSHIFT",
                               "RSHIFT",
                               "AND",
                               "OR",
                               "NOT",
                               "WS"});
  static const int32_t serializedATNSegment[] = {
      4,   0,   63,  408, 6,   -1,  2,   0,   7,   0,   2,   1,   7,   1,   2,
      2,   7,   2,   2,   3,   7,   3,   2,   4,   7,   4,   2,   5,   7,   5,
      2,   6,   7,   6,   2,   7,   7,   7,   2,   8,   7,   8,   2,   9,   7,
      9,   2,   10,  7,   10,  2,   11,  7,   11,  2,   12,  7,   12,  2,   13,
      7,   13,  2,   14,  7,   14,  2,   15,  7,   15,  2,   16,  7,   16,  2,
      17,  7,   17,  2,   18,  7,   18,  2,   19,  7,   19,  2,   20,  7,   20,
      2,   21,  7,   21,  2,   22,  7,   22,  2,   23,  7,   23,  2,   24,  7,
      24,  2,   25,  7,   25,  2,   26,  7,   26,  2,   27,  7,   27,  2,   28,
      7,   28,  2,   29,  7,   29,  2,   30,  7,   30,  2,   31,  7,   31,  2,
      32,  7,   32,  2,   33,  7,   33,  2,   34,  7,   34,  2,   35,  7,   35,
      2,   36,  7,   36,  2,   37,  7,   37,  2,   38,  7,   38,  2,   39,  7,
      39,  2,   40,  7,   40,  2,   41,  7,   41,  2,   42,  7,   42,  2,   43,
      7,   43,  2,   44,  7,   44,  2,   45,  7,   45,  2,   46,  7,   46,  2,
      47,  7,   47,  2,   48,  7,   48,  2,   49,  7,   49,  2,   50,  7,   50,
      2,   51,  7,   51,  2,   52,  7,   52,  2,   53,  7,   53,  2,   54,  7,
      54,  2,   55,  7,   55,  2,   56,  7,   56,  2,   57,  7,   57,  2,   58,
      7,   58,  2,   59,  7,   59,  2,   60,  7,   60,  2,   61,  7,   61,  2,
      62,  7,   62,  2,   63,  7,   63,  2,   64,  7,   64,  1,   0,   1,   0,
      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   2,   1,
      2,   1,   2,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,   1,   3,
      1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,   4,   1,
      5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,   1,   5,
      1,   6,   1,   6,   1,   7,   1,   7,   1,   7,   1,   8,   1,   8,   1,
      8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,   1,   8,
      1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,   9,   1,
      10,  1,   10,  1,   10,  1,   10,  3,   10,  190, 8,   10,  1,   11,  1,
      11,  1,   12,  1,   12,  1,   13,  1,   13,  1,   14,  1,   14,  1,   15,
      1,   15,  1,   16,  1,   16,  1,   16,  1,   17,  1,   17,  1,   17,  1,
      18,  1,   18,  1,   18,  1,   19,  1,   19,  1,   19,  1,   19,  1,   20,
      1,   20,  1,   20,  1,   20,  1,   21,  1,   21,  1,   21,  1,   21,  1,
      21,  1,   22,  1,   22,  1,   22,  1,   22,  1,   22,  1,   23,  1,   23,
      1,   23,  1,   23,  1,   24,  1,   24,  1,   24,  1,   24,  1,   25,  1,
      25,  1,   26,  1,   26,  1,   26,  1,   27,  1,   27,  1,   28,  1,   28,
      1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   29,  1,
      29,  1,   29,  1,   29,  1,   29,  1,   29,  1,   30,  1,   30,  1,   31,
      1,   31,  1,   32,  1,   32,  1,   33,  1,   33,  1,   34,  1,   34,  1,
      35,  1,   35,  1,   36,  1,   36,  1,   37,  1,   37,  3,   37,  274, 8,
      37,  1,   37,  1,   37,  5,   37,  278, 8,   37,  10,  37,  12,  37,  281,
      9,   37,  1,   38,  1,   38,  3,   38,  285, 8,   38,  1,   38,  3,   38,
      288, 8,   38,  3,   38,  290, 8,   38,  1,   39,  1,   39,  1,   39,  3,
      39,  295, 8,   39,  1,   40,  3,   40,  298, 8,   40,  1,   40,  4,   40,
      301, 8,   40,  11,  40,  12,  40,  302, 1,   40,  1,   40,  4,   40,  307,
      8,   40,  11,  40,  12,  40,  308, 3,   40,  311, 8,   40,  1,   41,  1,
      41,  1,   41,  4,   41,  316, 8,   41,  11,  41,  12,  41,  317, 1,   42,
      1,   42,  1,   42,  1,   42,  4,   42,  324, 8,   42,  11,  42,  12,  42,
      325, 1,   43,  1,   43,  1,   43,  1,   43,  4,   43,  332, 8,   43,  11,
      43,  12,  43,  333, 1,   43,  1,   43,  1,   43,  1,   43,  4,   43,  340,
      8,   43,  11,  43,  12,  43,  341, 3,   43,  344, 8,   43,  1,   44,  1,
      44,  1,   44,  1,   44,  1,   44,  1,   44,  1,   44,  1,   44,  1,   44,
      1,   44,  1,   44,  3,   44,  357, 8,   44,  1,   45,  1,   45,  1,   46,
      1,   46,  1,   47,  1,   47,  1,   48,  1,   48,  1,   49,  1,   49,  1,
      50,  1,   50,  1,   50,  1,   51,  1,   51,  1,   52,  1,   52,  1,   52,
      1,   53,  1,   53,  1,   53,  1,   54,  1,   54,  1,   54,  1,   55,  1,
      55,  1,   56,  1,   56,  1,   57,  1,   57,  1,   58,  1,   58,  1,   59,
      1,   59,  1,   59,  1,   60,  1,   60,  1,   60,  1,   61,  1,   61,  1,
      61,  1,   62,  1,   62,  1,   62,  1,   63,  1,   63,  1,   64,  1,   64,
      1,   64,  1,   64,  0,   0,   65,  1,   1,   3,   2,   5,   3,   7,   4,
      9,   5,   11,  6,   13,  7,   15,  8,   17,  9,   19,  10,  21,  11,  23,
      12,  25,  13,  27,  14,  29,  15,  31,  16,  33,  17,  35,  18,  37,  19,
      39,  20,  41,  21,  43,  22,  45,  23,  47,  24,  49,  25,  51,  26,  53,
      27,  55,  28,  57,  29,  59,  30,  61,  31,  63,  32,  65,  33,  67,  34,
      69,  35,  71,  36,  73,  37,  75,  38,  77,  0,   79,  0,   81,  39,  83,
      40,  85,  41,  87,  42,  89,  43,  91,  44,  93,  45,  95,  46,  97,  47,
      99,  48,  101, 49,  103, 50,  105, 51,  107, 52,  109, 53,  111, 54,  113,
      55,  115, 56,  117, 57,  119, 58,  121, 59,  123, 60,  125, 61,  127, 62,
      129, 63,  1,   0,   7,   2,   0,   115, 115, 117, 117, 3,   0,   65,  90,
      95,  95,  97,  122, 5,   0,   65,  79,  81,  87,  89,  90,  95,  95,  97,
      122, 5,   0,   46,  46,  48,  57,  65,  90,  95,  95,  97,  122, 2,   0,
      48,  57,  97,  102, 2,   0,   48,  57,  65,  70,  3,   0,   9,   10,  13,
      13,  32,  32,  420, 0,   1,   1,   0,   0,   0,   0,   3,   1,   0,   0,
      0,   0,   5,   1,   0,   0,   0,   0,   7,   1,   0,   0,   0,   0,   9,
      1,   0,   0,   0,   0,   11,  1,   0,   0,   0,   0,   13,  1,   0,   0,
      0,   0,   15,  1,   0,   0,   0,   0,   17,  1,   0,   0,   0,   0,   19,
      1,   0,   0,   0,   0,   21,  1,   0,   0,   0,   0,   23,  1,   0,   0,
      0,   0,   25,  1,   0,   0,   0,   0,   27,  1,   0,   0,   0,   0,   29,
      1,   0,   0,   0,   0,   31,  1,   0,   0,   0,   0,   33,  1,   0,   0,
      0,   0,   35,  1,   0,   0,   0,   0,   37,  1,   0,   0,   0,   0,   39,
      1,   0,   0,   0,   0,   41,  1,   0,   0,   0,   0,   43,  1,   0,   0,
      0,   0,   45,  1,   0,   0,   0,   0,   47,  1,   0,   0,   0,   0,   49,
      1,   0,   0,   0,   0,   51,  1,   0,   0,   0,   0,   53,  1,   0,   0,
      0,   0,   55,  1,   0,   0,   0,   0,   57,  1,   0,   0,   0,   0,   59,
      1,   0,   0,   0,   0,   61,  1,   0,   0,   0,   0,   63,  1,   0,   0,
      0,   0,   65,  1,   0,   0,   0,   0,   67,  1,   0,   0,   0,   0,   69,
      1,   0,   0,   0,   0,   71,  1,   0,   0,   0,   0,   73,  1,   0,   0,
      0,   0,   75,  1,   0,   0,   0,   0,   81,  1,   0,   0,   0,   0,   83,
      1,   0,   0,   0,   0,   85,  1,   0,   0,   0,   0,   87,  1,   0,   0,
      0,   0,   89,  1,   0,   0,   0,   0,   91,  1,   0,   0,   0,   0,   93,
      1,   0,   0,   0,   0,   95,  1,   0,   0,   0,   0,   97,  1,   0,   0,
      0,   0,   99,  1,   0,   0,   0,   0,   101, 1,   0,   0,   0,   0,   103,
      1,   0,   0,   0,   0,   105, 1,   0,   0,   0,   0,   107, 1,   0,   0,
      0,   0,   109, 1,   0,   0,   0,   0,   111, 1,   0,   0,   0,   0,   113,
      1,   0,   0,   0,   0,   115, 1,   0,   0,   0,   0,   117, 1,   0,   0,
      0,   0,   119, 1,   0,   0,   0,   0,   121, 1,   0,   0,   0,   0,   123,
      1,   0,   0,   0,   0,   125, 1,   0,   0,   0,   0,   127, 1,   0,   0,
      0,   0,   129, 1,   0,   0,   0,   1,   131, 1,   0,   0,   0,   3,   133,
      1,   0,   0,   0,   5,   138, 1,   0,   0,   0,   7,   142, 1,   0,   0,
      0,   9,   148, 1,   0,   0,   0,   11,  155, 1,   0,   0,   0,   13,  163,
      1,   0,   0,   0,   15,  165, 1,   0,   0,   0,   17,  168, 1,   0,   0,
      0,   19,  178, 1,   0,   0,   0,   21,  189, 1,   0,   0,   0,   23,  191,
      1,   0,   0,   0,   25,  193, 1,   0,   0,   0,   27,  195, 1,   0,   0,
      0,   29,  197, 1,   0,   0,   0,   31,  199, 1,   0,   0,   0,   33,  201,
      1,   0,   0,   0,   35,  204, 1,   0,   0,   0,   37,  207, 1,   0,   0,
      0,   39,  210, 1,   0,   0,   0,   41,  214, 1,   0,   0,   0,   43,  218,
      1,   0,   0,   0,   45,  223, 1,   0,   0,   0,   47,  228, 1,   0,   0,
      0,   49,  232, 1,   0,   0,   0,   51,  236, 1,   0,   0,   0,   53,  238,
      1,   0,   0,   0,   55,  241, 1,   0,   0,   0,   57,  243, 1,   0,   0,
      0,   59,  245, 1,   0,   0,   0,   61,  257, 1,   0,   0,   0,   63,  259,
      1,   0,   0,   0,   65,  261, 1,   0,   0,   0,   67,  263, 1,   0,   0,
      0,   69,  265, 1,   0,   0,   0,   71,  267, 1,   0,   0,   0,   73,  269,
      1,   0,   0,   0,   75,  273, 1,   0,   0,   0,   77,  289, 1,   0,   0,
      0,   79,  294, 1,   0,   0,   0,   81,  297, 1,   0,   0,   0,   83,  312,
      1,   0,   0,   0,   85,  319, 1,   0,   0,   0,   87,  343, 1,   0,   0,
      0,   89,  356, 1,   0,   0,   0,   91,  358, 1,   0,   0,   0,   93,  360,
      1,   0,   0,   0,   95,  362, 1,   0,   0,   0,   97,  364, 1,   0,   0,
      0,   99,  366, 1,   0,   0,   0,   101, 368, 1,   0,   0,   0,   103, 371,
      1,   0,   0,   0,   105, 373, 1,   0,   0,   0,   107, 376, 1,   0,   0,
      0,   109, 379, 1,   0,   0,   0,   111, 382, 1,   0,   0,   0,   113, 384,
      1,   0,   0,   0,   115, 386, 1,   0,   0,   0,   117, 388, 1,   0,   0,
      0,   119, 390, 1,   0,   0,   0,   121, 393, 1,   0,   0,   0,   123, 396,
      1,   0,   0,   0,   125, 399, 1,   0,   0,   0,   127, 402, 1,   0,   0,
      0,   129, 404, 1,   0,   0,   0,   131, 132, 5,   80,  0,   0,   132, 2,
      1,   0,   0,   0,   133, 134, 5,   46,  0,   0,   134, 135, 5,   46,  0,
      0,   135, 136, 5,   35,  0,   0,   136, 137, 5,   35,  0,   0,   137, 4,
      1,   0,   0,   0,   138, 139, 5,   46,  0,   0,   139, 140, 5,   46,  0,
      0,   140, 141, 5,   35,  0,   0,   141, 6,   1,   0,   0,   0,   142, 143,
      5,   46,  0,   0,   143, 144, 5,   46,  0,   0,   144, 145, 5,   91,  0,
      0,   145, 146, 5,   45,  0,   0,   146, 147, 5,   62,  0,   0,   147, 8,
      1,   0,   0,   0,   148, 149, 5,   44,  0,   0,   149, 150, 5,   98,  0,
      0,   150, 151, 5,   111, 0,   0,   151, 152, 5,   111, 0,   0,   152, 153,
      5,   108, 0,   0,   153, 154, 5,   62,  0,   0,   154, 10,  1,   0,   0,
      0,   155, 156, 5,   44,  0,   0,   156, 157, 5,   108, 0,   0,   157, 158,
      5,   111, 0,   0,   158, 159, 5,   103, 0,   0,   159, 160, 5,   105, 0,
      0,   160, 161, 5,   99,  0,   0,   161, 162, 5,   40,  0,   0,   162, 12,
      1,   0,   0,   0,   163, 164, 5,   44,  0,   0,   164, 14,  1,   0,   0,
      0,   165, 166, 5,   41,  0,   0,   166, 167, 5,   62,  0,   0,   167, 16,
      1,   0,   0,   0,   168, 169, 5,   44,  0,   0,   169, 170, 5,   110, 0,
      0,   170, 171, 5,   117, 0,   0,   171, 172, 5,   109, 0,   0,   172, 173,
      5,   101, 0,   0,   173, 174, 5,   114, 0,   0,   174, 175, 5,   105, 0,
      0,   175, 176, 5,   99,  0,   0,   176, 177, 5,   40,  0,   0,   177, 18,
      1,   0,   0,   0,   178, 179, 5,   46,  0,   0,   179, 180, 5,   46,  0,
      0,   180, 181, 5,   38,  0,   0,   181, 182, 5,   38,  0,   0,   182, 183,
      5,   46,  0,   0,   183, 184, 5,   46,  0,   0,   184, 20,  1,   0,   0,
      0,   185, 186, 5,   64,  0,   0,   186, 190, 5,   58,  0,   0,   187, 188,
      5,   64,  0,   0,   188, 190, 5,   59,  0,   0,   189, 185, 1,   0,   0,
      0,   189, 187, 1,   0,   0,   0,   190, 22,  1,   0,   0,   0,   191, 192,
      5,   70,  0,   0,   192, 24,  1,   0,   0,   0,   193, 194, 5,   71,  0,
      0,   194, 26,  1,   0,   0,   0,   195, 196, 5,   88,  0,   0,   196, 28,
      1,   0,   0,   0,   197, 198, 5,   85,  0,   0,   198, 30,  1,   0,   0,
      0,   199, 200, 5,   82,  0,   0,   200, 32,  1,   0,   0,   0,   201, 202,
      5,   46,  0,   0,   202, 203, 5,   46,  0,   0,   203, 34,  1,   0,   0,
      0,   204, 205, 5,   45,  0,   0,   205, 206, 5,   62,  0,   0,   206, 36,
      1,   0,   0,   0,   207, 208, 5,   61,  0,   0,   208, 209, 5,   62,  0,
      0,   209, 38,  1,   0,   0,   0,   210, 211, 5,   60,  0,   0,   211, 212,
      5,   45,  0,   0,   212, 213, 5,   62,  0,   0,   213, 40,  1,   0,   0,
      0,   214, 215, 5,   120, 0,   0,   215, 216, 5,   111, 0,   0,   216, 217,
      5,   114, 0,   0,   217, 42,  1,   0,   0,   0,   218, 219, 5,   91,  0,
      0,   219, 220, 5,   93,  0,   0,   220, 221, 5,   45,  0,   0,   221, 222,
      5,   62,  0,   0,   222, 44,  1,   0,   0,   0,   223, 224, 5,   91,  0,
      0,   224, 225, 5,   93,  0,   0,   225, 226, 5,   61,  0,   0,   226, 227,
      5,   62,  0,   0,   227, 46,  1,   0,   0,   0,   228, 229, 5,   124, 0,
      0,   229, 230, 5,   45,  0,   0,   230, 231, 5,   62,  0,   0,   231, 48,
      1,   0,   0,   0,   232, 233, 5,   124, 0,   0,   233, 234, 5,   61,  0,
      0,   234, 235, 5,   62,  0,   0,   235, 50,  1,   0,   0,   0,   236, 237,
      5,   61,  0,   0,   237, 52,  1,   0,   0,   0,   238, 239, 5,   35,  0,
      0,   239, 240, 5,   35,  0,   0,   240, 54,  1,   0,   0,   0,   241, 242,
      5,   59,  0,   0,   242, 56,  1,   0,   0,   0,   243, 244, 5,   58,  0,
      0,   244, 58,  1,   0,   0,   0,   245, 246, 5,   102, 0,   0,   246, 247,
      5,   105, 0,   0,   247, 248, 5,   114, 0,   0,   248, 249, 5,   115, 0,
      0,   249, 250, 5,   116, 0,   0,   250, 251, 5,   95,  0,   0,   251, 252,
      5,   109, 0,   0,   252, 253, 5,   97,  0,   0,   253, 254, 5,   116, 0,
      0,   254, 255, 5,   99,  0,   0,   255, 256, 5,   104, 0,   0,   256, 60,
      1,   0,   0,   0,   257, 258, 7,   0,   0,   0,   258, 62,  1,   0,   0,
      0,   259, 260, 5,   123, 0,   0,   260, 64,  1,   0,   0,   0,   261, 262,
      5,   125, 0,   0,   262, 66,  1,   0,   0,   0,   263, 264, 5,   91,  0,
      0,   264, 68,  1,   0,   0,   0,   265, 266, 5,   93,  0,   0,   266, 70,
      1,   0,   0,   0,   267, 268, 5,   40,  0,   0,   268, 72,  1,   0,   0,
      0,   269, 270, 5,   41,  0,   0,   270, 74,  1,   0,   0,   0,   271, 272,
      5,   58,  0,   0,   272, 274, 5,   58,  0,   0,   273, 271, 1,   0,   0,
      0,   273, 274, 1,   0,   0,   0,   274, 275, 1,   0,   0,   0,   275, 279,
      3,   77,  38,  0,   276, 278, 3,   79,  39,  0,   277, 276, 1,   0,   0,
      0,   278, 281, 1,   0,   0,   0,   279, 277, 1,   0,   0,   0,   279, 280,
      1,   0,   0,   0,   280, 76,  1,   0,   0,   0,   281, 279, 1,   0,   0,
      0,   282, 284, 5,   80,  0,   0,   283, 285, 7,   1,   0,   0,   284, 283,
      1,   0,   0,   0,   285, 290, 1,   0,   0,   0,   286, 288, 7,   2,   0,
      0,   287, 286, 1,   0,   0,   0,   288, 290, 1,   0,   0,   0,   289, 282,
      1,   0,   0,   0,   289, 287, 1,   0,   0,   0,   290, 78,  1,   0,   0,
      0,   291, 295, 7,   3,   0,   0,   292, 293, 5,   58,  0,   0,   293, 295,
      5,   58,  0,   0,   294, 291, 1,   0,   0,   0,   294, 292, 1,   0,   0,
      0,   295, 80,  1,   0,   0,   0,   296, 298, 5,   45,  0,   0,   297, 296,
      1,   0,   0,   0,   297, 298, 1,   0,   0,   0,   298, 300, 1,   0,   0,
      0,   299, 301, 2,   48,  57,  0,   300, 299, 1,   0,   0,   0,   301, 302,
      1,   0,   0,   0,   302, 300, 1,   0,   0,   0,   302, 303, 1,   0,   0,
      0,   303, 310, 1,   0,   0,   0,   304, 306, 5,   46,  0,   0,   305, 307,
      2,   48,  57,  0,   306, 305, 1,   0,   0,   0,   307, 308, 1,   0,   0,
      0,   308, 306, 1,   0,   0,   0,   308, 309, 1,   0,   0,   0,   309, 311,
      1,   0,   0,   0,   310, 304, 1,   0,   0,   0,   310, 311, 1,   0,   0,
      0,   311, 82,  1,   0,   0,   0,   312, 313, 5,   39,  0,   0,   313, 315,
      5,   98,  0,   0,   314, 316, 2,   48,  49,  0,   315, 314, 1,   0,   0,
      0,   316, 317, 1,   0,   0,   0,   317, 315, 1,   0,   0,   0,   317, 318,
      1,   0,   0,   0,   318, 84,  1,   0,   0,   0,   319, 320, 5,   48,  0,
      0,   320, 321, 5,   98,  0,   0,   321, 323, 1,   0,   0,   0,   322, 324,
      2,   48,  49,  0,   323, 322, 1,   0,   0,   0,   324, 325, 1,   0,   0,
      0,   325, 323, 1,   0,   0,   0,   325, 326, 1,   0,   0,   0,   326, 86,
      1,   0,   0,   0,   327, 328, 5,   48,  0,   0,   328, 329, 5,   120, 0,
      0,   329, 331, 1,   0,   0,   0,   330, 332, 7,   4,   0,   0,   331, 330,
      1,   0,   0,   0,   332, 333, 1,   0,   0,   0,   333, 331, 1,   0,   0,
      0,   333, 334, 1,   0,   0,   0,   334, 344, 1,   0,   0,   0,   335, 336,
      5,   48,  0,   0,   336, 337, 5,   120, 0,   0,   337, 339, 1,   0,   0,
      0,   338, 340, 7,   5,   0,   0,   339, 338, 1,   0,   0,   0,   340, 341,
      1,   0,   0,   0,   341, 339, 1,   0,   0,   0,   341, 342, 1,   0,   0,
      0,   342, 344, 1,   0,   0,   0,   343, 327, 1,   0,   0,   0,   343, 335,
      1,   0,   0,   0,   344, 88,  1,   0,   0,   0,   345, 346, 5,   64,  0,
      0,   346, 347, 5,   116, 0,   0,   347, 348, 5,   114, 0,   0,   348, 349,
      5,   117, 0,   0,   349, 357, 5,   101, 0,   0,   350, 351, 5,   64,  0,
      0,   351, 352, 5,   102, 0,   0,   352, 353, 5,   97,  0,   0,   353, 354,
      5,   108, 0,   0,   354, 355, 5,   115, 0,   0,   355, 357, 5,   101, 0,
      0,   356, 345, 1,   0,   0,   0,   356, 350, 1,   0,   0,   0,   357, 90,
      1,   0,   0,   0,   358, 359, 5,   43,  0,   0,   359, 92,  1,   0,   0,
      0,   360, 361, 5,   45,  0,   0,   361, 94,  1,   0,   0,   0,   362, 363,
      5,   42,  0,   0,   363, 96,  1,   0,   0,   0,   364, 365, 5,   47,  0,
      0,   365, 98,  1,   0,   0,   0,   366, 367, 5,   62,  0,   0,   367, 100,
      1,   0,   0,   0,   368, 369, 5,   62,  0,   0,   369, 370, 5,   61,  0,
      0,   370, 102, 1,   0,   0,   0,   371, 372, 5,   60,  0,   0,   372, 104,
      1,   0,   0,   0,   373, 374, 5,   60,  0,   0,   374, 375, 5,   61,  0,
      0,   375, 106, 1,   0,   0,   0,   376, 377, 5,   61,  0,   0,   377, 378,
      5,   61,  0,   0,   378, 108, 1,   0,   0,   0,   379, 380, 5,   33,  0,
      0,   380, 381, 5,   61,  0,   0,   381, 110, 1,   0,   0,   0,   382, 383,
      5,   38,  0,   0,   383, 112, 1,   0,   0,   0,   384, 385, 5,   124, 0,
      0,   385, 114, 1,   0,   0,   0,   386, 387, 5,   94,  0,   0,   387, 116,
      1,   0,   0,   0,   388, 389, 5,   126, 0,   0,   389, 118, 1,   0,   0,
      0,   390, 391, 5,   60,  0,   0,   391, 392, 5,   60,  0,   0,   392, 120,
      1,   0,   0,   0,   393, 394, 5,   62,  0,   0,   394, 395, 5,   62,  0,
      0,   395, 122, 1,   0,   0,   0,   396, 397, 5,   38,  0,   0,   397, 398,
      5,   38,  0,   0,   398, 124, 1,   0,   0,   0,   399, 400, 5,   124, 0,
      0,   400, 401, 5,   124, 0,   0,   401, 126, 1,   0,   0,   0,   402, 403,
      5,   33,  0,   0,   403, 128, 1,   0,   0,   0,   404, 405, 7,   6,   0,
      0,   405, 406, 1,   0,   0,   0,   406, 407, 6,   64,  0,   0,   407, 130,
      1,   0,   0,   0,   20,  0,   189, 273, 279, 284, 287, 289, 294, 297, 302,
      308, 310, 317, 325, 331, 333, 339, 341, 343, 356, 1,   6,   0,   0};
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
  spotlexerLexerStaticData = staticData.release();
}

} // namespace

spotLexer::spotLexer(CharStream *input) : Lexer(input) {
  spotLexer::initialize();
  _interpreter =
      new atn::LexerATNSimulator(this, *spotlexerLexerStaticData->atn,
                                 spotlexerLexerStaticData->decisionToDFA,
                                 spotlexerLexerStaticData->sharedContextCache);
}

spotLexer::~spotLexer() { delete _interpreter; }

std::string spotLexer::getGrammarFileName() const { return "spot.g4"; }

const std::vector<std::string> &spotLexer::getRuleNames() const {
  return spotlexerLexerStaticData->ruleNames;
}

const std::vector<std::string> &spotLexer::getChannelNames() const {
  return spotlexerLexerStaticData->channelNames;
}

const std::vector<std::string> &spotLexer::getModeNames() const {
  return spotlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary &spotLexer::getVocabulary() const {
  return spotlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView spotLexer::getSerializedATN() const {
  return spotlexerLexerStaticData->serializedATN;
}

const atn::ATN &spotLexer::getATN() const {
  return *spotlexerLexerStaticData->atn;
}

void spotLexer::initialize() {
  std::call_once(spotlexerLexerOnceFlag, spotlexerLexerInitialize);
}
