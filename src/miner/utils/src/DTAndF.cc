
#include "DTAndF.hh"
#include "DTUtils.hh"
#include "ProgressBar.hpp"
#include "Template.hh"
#include "message.hh"
#include "minerUtils.hh"
#include <algorithm>
#include <string>
#include <unordered_set>
#include <utility>

namespace slam {
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
  return _leaves.count(id) && _leaves.at(id).first.second != nullptr;
}
void DTAndF::removeLeaf(size_t id, bool second, int depth) {
  _leaves.at(id).first.second = nullptr;
}
void DTAndF::addLeaf(Proposition *p, size_t id, bool second, int depth) {
  _leaves[id].first.second = p;
}

void DTAndF::removeItems() { _choices->removeItems(); _t->setConsequentInterval(std::pair(0,0)); }


void DTAndF::addItem(Proposition *p, std::pair<size_t, size_t> interval,
                     int depth) {

  auto items = _choices->getItems();

  for (size_t i = 0; i < items.size(); i++) {
    auto e = dynamic_cast<Eventually *>(items[i]);
    auto currInterval = e->getInterval();
    e->setInterval(std::make_pair(currInterval.first + interval.first,
                                  currInterval.second + interval.second));
  }

  //shift consequent interval
  auto currInterval = _t->getConsequentInterval();
  _t->setConsequentInterval(
      std::make_pair(currInterval.first + interval.first,
                     currInterval.second + interval.second));

  _choices->addFront(new Eventually(new TemporalInst(p, ""),
                                    std::make_pair(0, 0), _t->_trace));

}
void DTAndF::popItem(int depth) {
  messageErrorIf(_choices->getItems().empty(),
                 "DTAndF::popItem: empty choices");

  auto items = _choices->getItems();
  auto shiftingInterval =
      items.size() > 1 ? dynamic_cast<Eventually *>(items[1])->getInterval()
                       : _t->getConsequentInterval();

  if (items.size() > 1) {
    //All intervals need to be shifted by the interval of the second item
    //Reset the interval of the second item
    dynamic_cast<Eventually *>(items[1])->setInterval(std::make_pair(0, 0));
    //shift all other intervals (if the antecedent contains more than 2 items)
    for (size_t i = 2; i < items.size(); i++) {
      auto e = dynamic_cast<Eventually *>(items[i]);
      auto currInterval = e->getInterval();
      e->setInterval(
          std::make_pair(currInterval.first - shiftingInterval.first,
                         currInterval.second - shiftingInterval.second));
    }
  }

  //shift consequent interval
  auto currInterval = _t->getConsequentInterval();
  _t->setConsequentInterval(
      std::make_pair(currInterval.first - shiftingInterval.first,
                     currInterval.second - shiftingInterval.second));

  delete _choices->popFront();
}

std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
DTAndF::getItems() {
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;
  auto items = _choices->getItems();

  if (items.empty()) {
    return ret;
  }

  auto frontProp = dynamic_cast<TemporalInst *>(
                       dynamic_cast<Eventually *>(items.front())->getOperand())
                       ->getProposition();
  messageErrorIf(frontProp == nullptr, "DTAndF::getItems: frontProp is null");

  ret.emplace_back(frontProp, _t->getConsequentInterval());

  for (size_t i = 1; i < items.size(); i++) {
    auto e = dynamic_cast<Eventually *>(items[i]);
    auto p = dynamic_cast<TemporalInst *>(e->getOperand())->getProposition();
    ret.emplace_back(p, e->getInterval());
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
  //        if (_t->assHoldsOnTraceOffset(slam::Location::Ant)) {
  //          // we found a minimal solution
  //          goto end;
  //        }
  //      } else {
  //        if (_t->assHoldsOnTrace(slam::Location::Ant)) {
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
  return std::make_pair("", "");
}

void DTAndF::loadSolution(
    const std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
        &sol) {

  auto items = sol;
  _t->setConsequentInterval(sol.front().second);
  _choices->addItem(new Eventually(new TemporalInst(items[0].first, ""),
                                    std::make_pair(0, 0), _t->_trace));

  for (size_t i = 1; i < items.size(); i++) {
    _choices->addItem(new Eventually(new TemporalInst(items[i].first, ""),
                                      items[i].second, _t->_trace));
  }
}
} // namespace slam
