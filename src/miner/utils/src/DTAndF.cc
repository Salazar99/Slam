
#include "DTAndF.hh"
#include "DTUtils.hh"
#include "ProgressBar.hpp"
#include "Template.hh"
#include "message.hh"
#include "minerUtils.hh"
#include <string>
#include <unordered_set>
#include <utility>

namespace harm {
//--DTAndF == ..F..---------------------------------------
DTAndF::DTAndF(TemporalAnd *p, Template *t, const DTLimits &limits)
    : _choices(p), _t(t) {
  _limits = limits;
  _limits._maxDepth = -1;
}

DTAndF::~DTAndF() {
  removeItems();
  delete _choices;
};
bool DTAndF::isMultiDimensional() { return 0; }
size_t DTAndF::getCurrentDepth() { return 0; }
bool DTAndF::canInsertAtDepth(int depth) {
  return _choices->size() < _limits._maxWidth;
}
bool DTAndF::isRandomConstructed() { return false; }
size_t DTAndF::getNChoices() { return _choices->size(); }
bool DTAndF::isTaken(size_t id, bool second, int depth) {
  if (second) {
    return _leaves.count(id) && _leaves.at(id).first!=nullptr;
  } else {
    return _leaves.count(id) && _leaves.at(id).first != nullptr;
  }
}
void DTAndF::removeLeaf(size_t id, int depth) {
  //_leaves.at(id).second = nullptr;
  _leaves.at(id).first = nullptr;
}
void DTAndF::addLeaf(Proposition *p, std::pair<size_t, size_t> intv, size_t id, bool second, int depth) {
  //if (second) {
  //  _leaves[id].second = intv;
  //} else {
  //  _leaves[id].first = p;
  //}
    _leaves[id].first = p;
    _leaves[id].second = intv;
}

void DTAndF::removeItems() { _choices->removeItems(); }

void DTAndF::addItem(Proposition *p, std::pair<size_t, size_t> interval,
                     int depth) {
  expression::TemporalExp *Fprop =
      new Eventually(new TemporalInst(p, ""), interval, _t->_trace);
  _choices->addItem(Fprop);
}

void DTAndF::popItem(int depth) { _choices->popItem(); }

std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
DTAndF::getItems() {
std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>ret;
for (auto &ti : _choices->getItems()) {
    
    ret.push_back(std::make_pair(
                dynamic_cast<TemporalInst*>((dynamic_cast<Eventually*>(ti)->getOperand()))->getProposition(),
                dynamic_cast<Eventually*>(ti)->getInterval()
                ));
}
  return ret;
}

std::vector<TemporalExp *> DTAndF::unpack() {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
};
std::vector<TemporalExp *> DTAndF::unpack(TemporalExp *pack) {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
};
std::vector<TemporalExp *> DTAndF::unpack(std::vector<TemporalExp *> &pack) {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
}

void DTAndF::clearPack(TemporalExp *pack) {
  messageError("Can't clear pack in unidimensional operator'");
}
bool DTAndF::isSolutionInconsequential(std::vector<TemporalExp *> &sol) {
  return 0;
}

void DTAndF::substitute(int depth, int width, expression::Proposition *&sub) {
//  if (width == -1) {
//    width = _choices->getItems().size() - 1;
//  }
//  expression::Proposition *tmp = _choices->getItems()[width];
//  _choices->getItems()[width] = sub;
//  sub = tmp;
}

const DTLimits &DTAndF::getLimits() { return _limits; }

std::vector<TemporalExp *> DTAndF::minimize(bool isOffset) {
  //
  //  std::vector<std::vector<size_t>> c;
  //  std::vector<expression::Proposition *> original = _choices->getItems();
  //  for (size_t i = 1; i <= original.size(); i++) {
  //    c.clear();
  //    comb(original.size(), i, c);
  //    for (auto &comb : c) {
  //      _choices->removeItems();
  //      for (auto &e : comb) {
  //        _choices->addItem(original[e]);
  //      }
  //      // check if this combination works
  //      if (isOffset) {
  //        if (_t->assHoldsOnTraceOffset(harm::Location::Ant)) {
  //          // we found a minimal solution
  //          goto end;
  //        }
  //      } else {
  //        if (_t->assHoldsOnTrace(harm::Location::Ant)) {
  //          goto end;
  //        }
  //      }
  //    }
  //  }
  //end:;
  std::vector<TemporalExp *> ret;
  //  for (auto p : _choices->getItems()) {
  //    ret.push_back(p);
  //  }
  //  _choices->removeItems();
  //  for (auto p : original) {
  //    _choices->addItem(p);
  //  }
  //  //FIXME
  //  //sortPropositions(ret);
  return ret;
}

std::pair<std::string, std::string> DTAndF::prettyPrint(bool offset) {

//  auto ant = _t->_templateFormula.getAnt();
//  auto imp = _t->_templateFormula.getImp();
//  auto con = _t->_templateFormula.getCon();
//
//  if (offset) {
//    //negate the consequent
//    con = Hstring("!(", Hstring::Stype::Temp, (expression::TemporalExp **)nullptr) +
//          con +
//          Hstring(")", Hstring::Stype::Temp, (expression::TemporalExp **)nullptr);
//  }
//
//  //compose the reduced template
//  auto reducedTemplate =
//      Hstring("G[", Hstring::Stype::G, (expression::TemporalExp **)nullptr) +
//      Hstring("X1,X2", Hstring::Stype::Intv,
//              (std::pair<size_t, size_t> *)nullptr) +
//      Hstring("]", Hstring::Stype::G, (expression::TemporalExp **)nullptr) +
//      Hstring("(", Hstring::Stype::G, (expression::TemporalExp **)nullptr) + ant +
//      imp + con +
//      Hstring(")", Hstring::Stype::G, (expression::TemporalExp **)nullptr);
//  return std::make_pair(reducedTemplate.toString(1),
//                        reducedTemplate.toColoredString(1));
}
} // namespace harm
