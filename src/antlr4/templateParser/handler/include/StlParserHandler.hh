#pragma once

#include "Hstring.hh"
#include "Trace.hh"
#include "exp.hh"
#include "stlBaseListener.hh"

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
  explicit stlParserHandler(harm::Trace *trace);

  ~StlParserHandler() override = default;

  Hstring &getTemplateFormula();
  void addErrorMessage(const std::string &msg);

  bool _useCache = 1;

private:
  bool _abort;

  std::stack<Hstring> _subFormulas;
  std::stack<std::String> _intervals;
  harm::Trace *_trace;
  Hstring _templateFormula;
  std::unordered_map<std::string, expression::Proposition **> _phToProp;
  std::unordered_map<std::string, std::string> _propStrToInst;
  size_t dtCount = 0;
  size_t instCount = 0;
  std::vector<std::string> _errorMessages;
  std::string printErrorMessage();

  void enterFile(spotParser::FileContext *ctx) override;
  void exitFile(spotParser::FileContext *ctx) override;
  virtual void exitFormula(spotParser::FormulaContext *ctx) override;
  virtual void visitErrorNode(antlr4::tree::ErrorNode *node) override;
  virtual void exitTformula(spotParser::TformulaContext *ctx) override;
  };

} // namespace hparser
