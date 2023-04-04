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
  auto G_interval2 = _intervalNames.top();
    _intervalNames.pop();
  auto G_interval1 = _intervalNames.top();
  _intervalNames.pop();
  _subFormulas.pop();

  auto STL_G = Hstring("G[", Hstring::Stype::G,(expression::Proposition**) nullptr) + Hstring(G_interval1, Hstring::Stype::Intv, _intervals.at(G_interval1)) + Hstring(",", Hstring::Stype::G, (expression::Proposition**) nullptr) + Hstring(G_interval2, Hstring::Stype::G, _intervals.at(G_interval2)) + Hstring("]", Hstring::Stype::G,(expression::Proposition**) nullptr);

  _templateFormula = STL_G + Hstring("(", Hstring::Stype::G,(expression::Proposition**) nullptr) + formula +
                     Hstring(")", Hstring::Stype::G,(expression::Proposition**) nullptr);
  _errorMessages.clear();
}

void StlParserHandler::exitFormula(stlParser::FormulaContext *ctx) {
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    auto formulaCon = _subFormulas.top();
    _subFormulas.pop();
    auto formulaAnt = _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(formulaAnt + Hstring(" -> ", Hstring::Stype::Imp,(expression::Proposition**) nullptr) +
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
    _subFormulas.push(Hstring(ph, Hstring::Stype::Ph,(expression::Proposition**) _phToProp.at(ph)));
    return;
  }

  if (ctx->DT_AND() != nullptr) {
    messageErrorIf(dtCount > 0,
                   "More than one dt operator defined\n" + printErrorMessage());
    std::string ph = "dtAnd" + std::to_string(dtCount++);
    _subFormulas.push(Hstring(ph, Hstring::Stype::DTAnd,(expression::Proposition**) nullptr));
    return;
  }

  if (ctx->tformula().size() == 2 && ctx->AND() != nullptr) {
    Hstring newFormula =
        Hstring(" && ", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

   if (ctx->tformula().size() == 2 && ctx->OR() != nullptr) {
    Hstring newFormula =
        Hstring(" || ", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  //If we are exiting a tformula rule that gives STL_eventually operator
  if (ctx->tformula().size() == 1 && ctx->STL_EVENTUALLY() != nullptr) {
    //Get last interval member found, end of interval
    std::string interval2 = _intervalNames.top(); 
    _intervalNames.pop();
    //Get second interval member, beginning of inverval
    std::string interval1 = _intervalNames.top();
    _intervalNames.pop();

    //Since intervals are another type of placeholder, reuse same structure
    Hstring newFormula =
        Hstring(" F[", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + Hstring(interval1,Hstring::Stype::Intv, _intervals.at(interval1)) + Hstring(",", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + Hstring(interval2,Hstring::Stype::Intv, _intervals.at(interval2)) + Hstring("]", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    Hstring newFormula = Hstring("(", Hstring::Stype::Temp,(expression::Proposition**) nullptr) +
                         _subFormulas.top() +
                         Hstring(")", Hstring::Stype::Temp,(expression::Proposition**) nullptr);
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
    Hstring newFormula =
        Hstring("!", Hstring::Stype::Temp,(expression::Proposition**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}

void StlParserHandler::exitInterval(stlParser::IntervalContext * ctx){
  std::string intname = ctx->getText();
//if new interval placeholder, add it to the map 
 if(!_intervals.count(intname)){
        _intervals[intname] = nullptr;     
    }
//Add it to the queue to be able to construct the operators correctly
  _intervalNames.push(intname);
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
