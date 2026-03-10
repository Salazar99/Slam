
#include "DTAndG.hh"
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
//--DTAndG == ..F..---------------------------------------
DTAndG::DTAndG(TemporalAnd *p, Template *t, const DTLimits &limits)
    : _choices(p), _t(t) {
  _limits = limits;
  _limits._maxDepth = -1;
}

DTAndG::~DTAndG() {
  removeItems();
  delete _choices;
};
bool DTAndG::isMultiDimensional() { return 0; }
size_t DTAndG::getCurrentDepth() { return 0; }
bool DTAndG::canInsertAtDepth(int depth) {
  return _choices->size() < _limits._maxWidth;
}
bool DTAndG::isRandomConstructed() { return false; }
size_t DTAndG::getNChoices() { return _choices->size(); }
bool DTAndG::isTaken(size_t id, bool second, int depth) {
  return _leaves.count(id) && _leaves.at(id).first.second != nullptr;
}
void DTAndG::removeLeaf(size_t id, bool second, int depth) {
  _leaves.at(id).first.second = nullptr;
}
void DTAndG::addLeaf(Proposition *p, size_t id, bool second, int depth) {
  _leaves[id].first.second = p;
}

void DTAndG::removeItems() { _choices->removeItems(); _t->setConsequentInterval(std::make_pair(0,0)); }


void DTAndG::addItem(Proposition *p,  std::pair<std::pair<size_t, size_t>,std::pair<size_t, size_t>> interval,
                     int depth) {

  auto items = _choices->getItems();

  for (size_t i = 0; i < items.size(); i++) {
    auto e = dynamic_cast<Globally *>(items[i]);
    auto currInterval = e->getInterval();
    e->setInterval(std::make_pair(currInterval.first + interval.first.first,
                                  currInterval.second + interval.first.second));
  }

  //shift consequent interval
  auto currInterval = _t->getConsequentInterval();
  _t->setConsequentInterval(
      std::make_pair(currInterval.first + interval.second.first,
                     currInterval.second + interval.second.second));

  _choices->addFront(new Globally(new TemporalInst(p, ""),
                                    std::make_pair(currInterval.first + interval.first.first,
                                                   currInterval.second + interval.first.second), _t->_trace));

}
void DTAndG::popItem(int depth) {
  messageErrorIf(_choices->getItems().empty(),
                 "DTAndG::popItem: empty choices");

  auto items = _choices->getItems();
  //GET THE SHIFT OF THE CURRENT GLOBALLY
  auto shiftingInterval =
      items.size() > 1 ? dynamic_cast<Globally *>(items[1])->getInterval()
                       : _t->getConsequentInterval();

  if (items.size() > 1) {
    //All intervals need to be shifted by the SHIFT of the second item
    //Reset the interval of the second item
    dynamic_cast<Globally *>(items[1])->setInterval(std::make_pair(0, 0));
    //shift all other intervals (if the antecedent contains more than 2 items)
    for (size_t i = 2; i < items.size(); i++) {
      auto e = dynamic_cast<Globally *>(items[i]);
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
DTAndG::getItems() {
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;
  auto items = _choices->getItems();

  if (items.empty()) {
    return ret;
  }

  auto frontProp = dynamic_cast<TemporalInst *>(
                       dynamic_cast<Globally *>(items.front())->getOperand())
                       ->getProposition();
  messageErrorIf(frontProp == nullptr, "DTAndG::getItems: frontProp is null");

  ret.emplace_back(frontProp, _t->getConsequentInterval());

  for (size_t i = 1; i < items.size(); i++) {
    auto e = dynamic_cast<Globally *>(items[i]);
    auto p = dynamic_cast<TemporalInst *>(e->getOperand())->getProposition();
    ret.emplace_back(p, e->getInterval());
  }

  return ret;
}


std::vector<TemporalExp *> DTAndG::unpack() {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
};
std::vector<TemporalExp *> DTAndG::unpack(TemporalExp *pack) {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
};
std::vector<TemporalExp *> DTAndG::unpack(std::vector<TemporalExp *> &pack) {
  messageError("Can't unpack in unidimensional operator'");
  return std::vector<TemporalExp *>();
}

void DTAndG::clearPack(TemporalExp *pack) {
  messageError("Can't clear pack in unidimensional operator'");
}
bool DTAndG::isSolutionInconsequential(std::vector<TemporalExp *> &sol) {
  return 0;
}

void DTAndG::substitute(int depth, int width, expression::Proposition *&sub) {
  //  if (width == -1) {
  //    width = _choices->getItems().size() - 1;
  //  }
  //  expression::Proposition *tmp = _choices->getItems()[width];
  //  _choices->getItems()[width] = sub;
  //  sub = tmp;
}

const DTLimits &DTAndG::getLimits() { return _limits; }

std::vector<TemporalExp *> DTAndG::minimize(bool isOffset) {
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

std::pair<std::string, std::string> DTAndG::prettyPrint(bool offset) {

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

void DTAndG::loadSolution(
    const std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
        &sol) {

  auto items = sol;
  _t->setConsequentInterval(sol.front().second);
  _choices->addItem(new Globally(new TemporalInst(items[0].first, ""),
                                    std::make_pair(0, 0), _t->_trace));

  for (size_t i = 1; i < items.size(); i++) {
    _choices->addItem(new Globally(new TemporalInst(items[i].first, ""),
                                      items[i].second, _t->_trace));
  }
}
} // namespace slam
