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
StlParserHandler::StlParserHandler(harm::Trace *trace)
    : _abort(false), _trace(trace) {}

void StlParserHandler::exitFile(stlParser::FileContext *ctx) {
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

void StlParserHandler::exitFormula(stlParser::FormulaContext *ctx) {
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

void StlParserHandler::exitTformula(stlParser::TformulaContext *ctx) {

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

  //If we are exiting a tformula rule that gives STL_eventually operator
  if (ctx->tformula().size() == 3 && ctx->STL_EVENTUALLY() != nullptr) {

    //Get last interval member found, end of interval
    std::string interval2 = _intervals.top(); 
    _intervals.pop();
    //Get second interval member, beginning of inverval
    std::string interval1 = _intervals.top();
    _intervals.pop();

    //Since intervals are another type of placeholder, reuse same structure
    if(!_phToProp.count(interval1)){
        _phToProp[interval1] = new Proposition *(nullptr);      
    }
    if(!_phToProp.count(interval2)){
        _phToProp[interval2] = new Proposition *(nullptr);
    }
    
    Hstring newFormula =
        Hstring(" F[", Hstring::Stype::Temp) + Hstring(interval1,Hstring::Stype::Intv, _phToProp[interval1]) + Hstring(",", Hstring::Stype::Temp) + Hstring(interval2,Hstring::Stype::Intv, _phToProp[interval2]) + Hstring("]", Hstring::Stype::Temp) + _subFormulas.top();
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

void StlParserHandler::exitInterval(stlParser::IntervalContext * ctx){
  _intervals.push(ctx->getText());
}


std::string StlParserHandler::printErrorMessage() {
  std::stringstream ss;
  for (auto &msg : _errorMessages) {
    ss << msg << "\n";
  }
  return ss.str();
}

void StlParserHandler::visitErrorNode(__attribute__((unused))
                                       antlr4::tree::ErrorNode *node) {
  messageError("Antlr parse error: " + node->getText() + "\n" +
               printErrorMessage());
}
void StlParserHandler::addErrorMessage(const std::string &msg) {
  _errorMessages.push_back(msg);
}
Hstring &StlParserHandler::getTemplateFormula() { return _templateFormula; }

} // namespace hparser
