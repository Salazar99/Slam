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
  auto G_interval = _intervalNames.top();
  _intervalNames.pop();
  _subFormulas.pop();

  auto STL_G = Hstring("G[", Hstring::Stype::G,(harm::TemporalExp**) nullptr)+ Hstring(G_interval, Hstring::Stype::G, _intervals.at(G_interval)) + Hstring("]", Hstring::Stype::G,(harm::TemporalExp**) nullptr);

  _templateFormula = STL_G + Hstring("(", Hstring::Stype::G,(harm::TemporalExp**) nullptr) + formula +
                     Hstring(")", Hstring::Stype::G,(harm::TemporalExp**) nullptr);
  _errorMessages.clear();
}

void StlParserHandler::exitFormula(stlParser::FormulaContext *ctx) {
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    auto formulaCon = _subFormulas.top();
    _subFormulas.pop();
    auto formulaAnt = _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(formulaAnt + Hstring(" -> ", Hstring::Stype::Imp,(harm::TemporalExp**) nullptr) +
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
    //if (_useCache) {
    // _subFormulas.push(Hstring(_propStrToInst.at(pStr), Hstring::Stype::Inst,
    //                            new Proposition *(new CachedProposition(p))));
    //} else {

      _subFormulas.push(Hstring(_propStrToInst.at(pStr), Hstring::Stype::Inst,
                                new harm::StlInst *(p)));
    //}
    return;
  }
  if (ctx->placeholder() != nullptr) {
    std::string ph = "P" + ctx->placeholder()->NUMERIC()->getText();
    if (!_phToProp.count(ph)) {
      _phToProp[ph] = new harm::TemporalExp *(nullptr);
    }
    _subFormulas.push(Hstring(ph, Hstring::Stype::Ph,(harm::TemporalExp**) _phToProp.at(ph)));
    return;
  }

  if (ctx->DT_ANDF() != nullptr) {
    messageErrorIf(dtCount > 0,
                   "More than one dt operator defined\n" + printErrorMessage());
    std::string ph = "dtAndF" + std::to_string(dtCount++);
    _subFormulas.push(Hstring(ph, Hstring::Stype::DTAndF,(harm::TemporalExp**) nullptr));
    return;
  }

  if (ctx->tformula().size() == 2 && ctx->AND() != nullptr) {
    Hstring newFormula =
        Hstring(" && ", Hstring::Stype::Temp,(harm::TemporalExp **) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

   if (ctx->tformula().size() == 2 && ctx->OR() != nullptr) {
    Hstring newFormula =
        Hstring(" || ", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    newFormula = _subFormulas.top() + newFormula;
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  //If we are exiting a tformula rule that gives STL_eventually operator
  if (ctx->tformula().size() == 1 && ctx->STL_EVENTUALLY() != nullptr) {
    //Get last interval member found, end of interval
    std::string interval = _intervalNames.top(); 
    _intervalNames.pop();

    //Since intervals are another type of placeholder, reuse same structure
    Hstring newFormula =
        Hstring("F[", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr) + Hstring(interval,Hstring::Stype::Intv, _intervals.at(interval)) + Hstring("]", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    Hstring newFormula = Hstring("(", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr) +
                         _subFormulas.top() +
                         Hstring(")", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr);
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
    Hstring newFormula =
        Hstring("!", Hstring::Stype::Temp,(harm::TemporalExp**) nullptr) + _subFormulas.top();
    _subFormulas.pop();
    _subFormulas.push(newFormula);
    return;
  }
}

//Interval_placeholder COMMA Interval_placeholder
//NUMERIC COMMA NUMERIC 
//FIXME
void StlParserHandler::exitInterval(stlParser::IntervalContext * ctx){
  //Interval is made of 2 placeholders
  std::stack<std::string> intval;
  if(ctx->interval_placeholder().size() == 2){
    for(auto boundary : ctx->interval_placeholder()){
      std::string bound = "X" + boundary->NUMERIC()->getText();
      intval.push(bound);
    }
    std::string rightb = intval.top();
    intval.pop();
    std::string leftb = intval.top();
    intval.pop();

    std::string intervalname = leftb + "," + rightb;

    //std pair will be defined in the future
    _intervals[intervalname] = nullptr;
    _intervalNames.push(intervalname);
  }
  //Interval is defined
  else{
    for(auto boundary : ctx->NUMERIC()){
      std::string bound = boundary->getText();
      intval.push(bound);
    }
      //sstream magic to get size_t from numeric
      std::string rightb = intval.top();
      intval.pop();
      std::string leftb = intval.top();
      intval.pop();
      std::stringstream r(rightb);
      std::stringstream l(leftb);

      size_t rightval;
      size_t leftval;
      r >> rightval;
      l >> leftval;

      std::string intervalname = leftb + "," + rightb;

      std::pair<size_t,size_t> * interval = new std::pair<size_t,size_t>(leftval,rightval);

      _intervals[intervalname] = interval;
      _intervalNames.push(intervalname);
  }
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
