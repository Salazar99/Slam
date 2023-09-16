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
StlParserHandler::StlParserHandler(exharm::Trace *trace, exharm::DTLimits limits)
    : _abort(false), _trace(trace) {
  _template = new exharm::Template(trace, limits);
}

void StlParserHandler::exitFile(stlParser::FileContext *ctx) {
  auto teFormula = _tfStack.top();
  _tfStack.pop();
  _template->_impl = dynamic_cast<Implication *>(teFormula);
}

void StlParserHandler::exitImplication(stlParser::ImplicationContext *ctx) {

  if (ctx->tformula().size() == 1 && ctx->DT_ANDF() != nullptr) {
    //..F..
    TemporalExp *te = new TemporalAnd();
    TemporalExp *teformulaCon =
        new Eventually(_tfStack.top(), std::pair<size_t, size_t>(0, 0), _trace);
    _tfStack.pop();

    std::string ph = "dtAndF";
    _template->_dtOp =
        std::make_pair(ph, new exharm::DTAndF(dynamic_cast<TemporalAnd *>(te),
                                            _template, _template->_limits));
    _tfStack.push(new Implication(te, teformulaCon));
    return;
  } else if (ctx->tformula().size() == 2) {
    std::pair<size_t, size_t> intv = *(_intervals[_intervalNames.top()]);
    _intervalNames.pop();
    TemporalExp *teformulaCon = new Eventually(_tfStack.top(), intv, _trace);
    _tfStack.pop();

    TemporalExp *teFormulaAnt = _tfStack.top();
    _tfStack.pop();

    _tfStack.push(new Implication(teFormulaAnt, teformulaCon));
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

  if (ctx->tformula().size() == 2) {
    if (ctx->AND() != nullptr) {
      TemporalAnd *p = new TemporalAnd();
      p->addItem(_tfStack.top());
      _tfStack.pop();
      p->addItem(_tfStack.top());
      _tfStack.pop();
      _tfStack.push(p);

    } else if (ctx->OR() != nullptr) {
      TemporalOr *p = new TemporalOr();
      p->addItem(_tfStack.top());
      _tfStack.pop();
      p->addItem(_tfStack.top());
      _tfStack.pop();
      _tfStack.push(p);
    }

    return;
  }

  if (ctx->tformula().size() == 1) {
    if (ctx->STL_EVENTUALLY() != nullptr) {
      std::pair<size_t, size_t> intv = *(_intervals[_intervalNames.top()]);
      _intervalNames.pop();
      Eventually *p = new Eventually(_tfStack.top(), intv, _trace);
      _tfStack.pop();
      _tfStack.push(p);
    } else if (ctx->tformula().size() == 1 && ctx->NOT() != nullptr) {
      TemporalNot *p = new TemporalNot(_tfStack.top());
      _tfStack.pop();
      _tfStack.push(p);
    } else if (ctx->LPAREN() != nullptr && ctx->RPAREN() != nullptr) {
      //nothing to do
    }

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

    size_t rightval = std::stoi(rightb);
    size_t leftval = std::stoi(leftb);

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
