#include "StlParserHandler.hh"
#include "Template.hh"
#include "exp.hh"
#include "propositionParser.hh"
#include "propositionParsingUtils.hh"
#include <sstream>
#include <utility>

using namespace expression;

#define CHECK_ABORT                                                            \
  if (_abort)                                                                  \
    return;

namespace hparser {

void StlParserHandler::enterFile(__attribute__((unused))
                                 stlParser::FileContext *ctx) {
  _abort = false;
}
StlParserHandler::StlParserHandler(harm::Trace *trace, harm::DTLimits limits)
    : _abort(false), _trace(trace) {
  _template = new harm::Template(trace, limits);
}

void StlParserHandler::exitFile(stlParser::FileContext *ctx) {
  auto teFormula = _tfStack.top();
  _tfStack.pop();
  _template->_impl = dynamic_cast<Implication *>(teFormula);
}

void StlParserHandler::exitFormula(stlParser::FormulaContext *ctx) {
  if (ctx->tformula().size() == 2 && ctx->IMPL() != nullptr) {
    auto teformulaCon = _tfStack.top();
    _tfStack.pop();
    auto teformulaAnt = _tfStack.top();
    _tfStack.pop();
    _tfStack.push(new Implication(teformulaAnt, teformulaCon));
    return;
  }
}

void StlParserHandler::exitTformula(stlParser::TformulaContext *ctx) {

  if (ctx->boolean() != nullptr) {
    Proposition *p = parsePropositionAlreadyTyped(ctx->getText(), _trace);
    std::string pStr = prop2String(*p);

    std::string ph = "_inst_" + std::to_string(instCount++);
    _propStrToInst[pStr] = ph;
    expression::TemporalExp *te = new expression::TemporalInst(p, ph);
    _template->_iToProp[ph] = te;
    _template->_tokenToProp[ph] = te;
    _tfStack.push(te);

    return;
  }
  if (ctx->placeholder() != nullptr) {
    std::string ph = "P" + ctx->placeholder()->NUMERIC()->getText();
    messageErrorIf(_template->_tokenToProp.count(ph),
                   "Repeated Placeholder not allowed");

    TemporalExp *p = new expression::Placeholder(nullptr, ph);
    _template->_tokenToProp[ph] = p;
    _template->_cphToProp[ph] = p;

    _tfStack.push(p);

    return;
  }

  if (ctx->DT_ANDF() != nullptr) {
    messageErrorIf(dtCount > 0,
                   "More than one dt operator defined\n" + printErrorMessage());
    std::string ph = "dtAndF";
    dtCount++;
    TemporalExp *te = new TemporalAnd();
    _template->_dtOp =
        std::make_pair(ph, new harm::DTAndF(dynamic_cast<TemporalAnd *>(te),
                                            _template, _template->_limits));
    _tfStack.push(te);

    return;
  }

  if (ctx->tformula().size() == 2 && ctx->AND() != nullptr) {
    TemporalAnd *p = new TemporalAnd();
    p->addItem(_tfStack.top());
    _tfStack.pop();
    p->addItem(_tfStack.top());
    _tfStack.pop();
    _tfStack.push(p);

    return;
  }

  if (ctx->tformula().size() == 2 && ctx->OR() != nullptr) {
    return;
  }

  //If we are exiting a tformula rule that gives STL_eventually operator
  if (ctx->tformula().size() == 1 && ctx->STL_EVENTUALLY() != nullptr) {
    Eventually *p =
        new Eventually(_tfStack.top(), std::pair<size_t, size_t>(0, 0), _trace);
    _tfStack.pop();
    _tfStack.push(p);
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->LPAREN() != nullptr &&
      ctx->RPAREN() != nullptr) {
    return;
  }

  if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
    return;
  }
}

//Interval_placeholder COMMA Interval_placeholder
//NUMERIC COMMA NUMERIC
void StlParserHandler::exitInterval(stlParser::IntervalContext *ctx) {
  //Interval is made of 2 placeholders
  std::stack<std::string> intval;
  if (ctx->interval_placeholder().size() == 2) {
    for (auto boundary : ctx->interval_placeholder()) {
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
  else {
    for (auto boundary : ctx->NUMERIC()) {
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

    std::pair<size_t, size_t> *interval =
        new std::pair<size_t, size_t>(leftval, rightval);

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

} // namespace hparser
