#pragma once

#include "Hstring.hh"
#include "Trace.hh"
#include "exp.hh"
#include "stlBaseListener.h"
#include "stlLexer.h"
#include "StlInst.hh"

#include <cmath>
#include <stack>
#include <string>
#include <unordered_map>

namespace harm {
class Template;
}
namespace hparser {

class StlParserHandler : public stlBaseListener {

public:
  explicit StlParserHandler(harm::Trace *trace);

  ~StlParserHandler() override = default;

  Hstring &getTemplateFormula();
  void addErrorMessage(const std::string &msg);

  bool _useCache = 1;

private:
  bool _abort;

  std::stack<Hstring> _subFormulas;
  std::stack<std::string> _intervalNames;
  std::unordered_map<std::string, std::pair<size_t, size_t> *> _intervals;
  harm::Trace *_trace;
  Hstring _templateFormula;
  std::unordered_map<std::string, harm::TemporalExp **> _phToProp;
  std::unordered_map<std::string, std::string> _propStrToInst;
  size_t dtCount = 0;
  size_t instCount = 0;
  std::vector<std::string> _errorMessages;
  std::string printErrorMessage();

  void enterFile(stlParser::FileContext *ctx) override;
  void exitFile(stlParser::FileContext *ctx) override;
  virtual void exitFormula(stlParser::FormulaContext *ctx) override;
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override;
  virtual void exitTformula(stlParser::TformulaContext *ctx) override;
  virtual void exitInterval(stlParser::IntervalContext * ctx) override;
  };

} // namespace hparser
