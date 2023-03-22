#include "StlParserHandler.hh"
#include "propositionParser.hh"
#include "propositionParsingUtils.hh"
#include <sstream>

using namespace expression;

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace hparser {

void StlParserHandler::enterFile(__attribute__((unused))
                                  stlParser::FileContext *ctx) {
  _abort = false;
}
stlParserHandler::stlParserHandler(harm::Trace *trace)
    : _abort(false), _trace(trace) {}

void stlParserHandler::exitFile(stlParser::FileContext *ctx) {
  auto formula = _subFormulas.top();
  auto G_interval2 = _intervals.top();
  auto G_interval1 = _intervals.top();
  _subFormulas.pop();
  _intervals.pop();
  _intervals.pop();

  auto STL_G = Hstring("G[", Hstring::Stype::G) + Hstring(G_interval1, Hstring::Stype::G) + Hstring(",", Hstring::Stype::G) + Hstring(G_interval2, Hstring::Stype::G) + Hstring("]", Hstring::Stype::G);

  _templateFormula = STL_G + Hstring("(", Hstring::Stype::G) + formula +
                     Hstring(")", Hstring::Stype::G);
  _errorMessages.clear();
}

void stlParserHandler::exitFormula(stlParser::FormulaContext *ctx) {
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    auto formulaCon = _subFormulas.top();
    _subFormulas.pop();
    auto formulaAnt = _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(formulaAnt + Hstring(" -> ", Hstring::Stype::Imp) +
                      formulaCon);
    return;
  }
}

void stlParserHandler::exitTformula(stlParser::TformulaContext *ctx) {

  if (ctx->boolean() != nullptr) {
    Proposition *p = parsePropositionAlreadyTyped(ctx->getText(), _trace);
    std::string pStr = prop2String(*p);
    if (!_propStrToInst.count(pStr)) {
      std::string ph = "_inst_" + std::to_string(instCount++);
      _propStrToInst[pStr] = ph;
    }
    if (_useCache) {
      _subFormulas.push(Hstring(_propStrToInst.at(pStr), Hstring::Stype::Inst,
                                new Proposition *(new CachedProposition(p))));
    } else {

      _subFormulas.push(Hstring(_propStrToInst.at(pStr), Hstring::Stype::Inst,
                                new Proposition *(p)));
    }
    return;
  }
  if (ctx->placeholder() != nullptr) {
    std::string ph = "P" + ctx->placeholder()->NUMERIC()->getText();
    if (!_phToProp.count(ph)) {
      _phToProp[ph] = new Proposition *(nullptr);
    }
    _subFormulas.push(Hstring(ph, Hstring::Stype::Ph, _phToProp.at(ph)));
    return;
  }
  if (ctx->interval() != nullptr){
    std::string intv = ctx->interval()->getText();
    _intervals.push(intv);
    return;
  }

  if (ctx->DT_AND() != nullptr) {
    messageErrorIf(dtCount > 0,
                   "More than one dt operator defined\n" + printErrorMessage());
    std::string ph = "dtAnd" + std::to_string(dtCount++);
    _subFormulas.push(Hstring(ph, Hstring::Stype::DTAnd, nullptr));
    return;
  }

  if (ctx->tformula().size() == 2 && ctx->AND() != nullptr) {
    Hstring newFormula =
        Hstring(" && ", Hstring::Stype::Temp) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

   if (ctx->tformula().size() == 2 && ctx->OR() != nullptr) {
    Hstring newFormula =
        Hstring(" || ", Hstring::Stype::Temp) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 3 && ctx->STL_EVENTUALLY() != nullptr) {
    Hstring newFormula = _subFormulas.top();
    Hstring interval2 = _intervals.top();
    Hstring interval1 = _intervals.top();
    _subFormulas.pop();
    _intervals.pop();
    _intervals.pop();
    newFormula =
        _subFormulas.top() + Hstring(" F[", Hstring::Stype::Temp) + Hstring(interval1,Hstring::Stype::Temp) + Hstring(",", Hstring::Stype::Temp) + Hstring(interval2,Hstring::Stype::Temp) + Hstring("]", Hstring::Stype::Temp) + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    Hstring newFormula = Hstring("(", Hstring::Stype::Temp) +
                         _subFormulas.top() +
                         Hstring(")", Hstring::Stype::Temp);
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
    Hstring newFormula =
        Hstring("!", Hstring::Stype::Temp) + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}


std::string stlParserHandler::printErrorMessage() {
  std::stringstream ss;
  for (auto &msg : _errorMessages) {
    ss << msg << "\n";
  }
  return ss.str();
}

void stlParserHandler::visitErrorNode(__attribute__((unused))
                                       antlr4::tree::ErrorNode *node) {
  messageError("Antlr parse error: " + node->getText() + "\n" +
               printErrorMessage());
}
void stlParserHandler::addErrorMessage(const std::string &msg) {
  _errorMessages.push_back(msg);
}
Hstring &stlParserHandler::getTemplateFormula() { return _templateFormula; }

} // namespace hparser
