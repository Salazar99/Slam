
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
    return _leaves.count(id) && _leaves.at(id).first.second != nullptr;
  } else {
    return _leaves.count(id) && _leaves.at(id).first.second != nullptr;
  }
}
void DTAndF::removeLeaf(size_t id, int depth) {
  _leaves.at(id).first.first = nullptr;
  _leaves.at(id).first.second = nullptr;
}
void DTAndF::addLeaf(Proposition *p, std::pair<size_t, size_t> intv, size_t id,
                     bool second, int depth) {
  if (second) {
    _leaves[id].first.second = p;
  } else {
    _leaves[id].first.first = p;
  }
  _leaves[id].second = intv;
}

void DTAndF::removeItems() { _choices->removeItems(); }

void DTAndF::addItem(Proposition *p, std::pair<size_t, size_t> interval,
                     int depth) {
  if (_choices->size() != 0) {
    //need to: add new prop as Inst, make olt Inst into Eventually, modify all intervals
    //Pop and get the previous TemporalInst added, which is at the back of the _choices's items
    Proposition * lastItem = _choices->popLastItem();
    std::cout<< "lastProp: " << prop2String(*lastItem) <<std::endl;
    //lastItem is added as an Eventually
    expression::TemporalExp *Fprop =
        new Eventually(new TemporalInst(lastItem, ""), std::make_pair(0,0), _t->_trace);
    _choices->addItem(Fprop);
    //new proposition is added as a TemporalInst
    expression::TemporalExp *Iprop = new TemporalInst(p, "");
    _choices->addItem(Iprop);

    //Update consequent interval
    std::pair<size_t, size_t> consequent_intv = _t->getConsequentInterval();
    consequent_intv.first += interval.first;
    consequent_intv.second += interval.second;
    _t->setConsequentInterval(consequent_intv);
    //Update Fprops intervals
    _choices->updateIntervals(interval, true);
  } else {
    expression::TemporalExp *Fprop = new TemporalInst(p, "");
    _t->setConsequentInterval(interval);
    _choices->addItem(Fprop);
  }
}

void DTAndF::popItem(int depth) {
  //delete _choices->getItems().back();
  _choices->popItem();
  //Get and pop last Eventually
  if(_choices->size() != 0){
    Eventually * lastF = dynamic_cast<Eventually *>(_choices->getItems().back());
    _choices->popItem();
    //get interval to subtract from others
    std::pair<size_t,size_t> sub_intv = lastF->getInterval();
    //get con interval
    std::pair<size_t, size_t> consequent_intv = _t->getConsequentInterval();
    consequent_intv.first -= sub_intv.first;
    consequent_intv.second -= sub_intv.second;
    _t->setConsequentInterval(consequent_intv);
    //get new TemporalInst to add to items
    TemporalInst * newInst = dynamic_cast<TemporalInst *>(lastF->getOperand());
    _choices->addItem(newInst); 
    //Update intervals of choices
    _choices->updateIntervals(sub_intv,false);
    //Free memory
    //delete lastF;
  }
}

std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
DTAndF::getItems() {
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> ret;

  //interval of last prop = interval of last Eventually in the formula
  if (_choices->size() != 1){
    ret.push_back(
        std::make_pair(dynamic_cast<TemporalInst *>(_choices->getItems().back())->getProposition(),
                       dynamic_cast<Eventually*>(_choices->getItems()[_choices->size()-2])->getInterval()));
  }else{
    ret.push_back(
        std::make_pair(dynamic_cast<TemporalInst *>(_choices->getItems().back())->getProposition(),
                       _t->getConsequentInterval()));
  }
  //starting from the last eventually
  //FIXME: dangerous because size_t cannot contain negative numbers, so if i goes below 0 its value is undefined
  for (size_t i = 0 ; i < _choices->size()-1 ; i++) {
    auto ti = _choices->getItems()[i];
    if(i == 0){
    //last eventually before consequent
      auto con_intv = _t->getConsequentInterval();
      auto ti_intv = dynamic_cast<Eventually *>(ti)->getInterval();
      //interval = (interval of con - interval of this Eventually)
      con_intv.first -= ti_intv.first;
      con_intv.second -= ti_intv.second; 
      ret.push_back(
          std::make_pair(dynamic_cast<TemporalInst *>(
                             (dynamic_cast<Eventually *>(ti)->getOperand()))
                             ->getProposition(),con_intv)
                         );
    }else{
      auto nti = _choices->getItems()[i-1];
      auto nti_intv = dynamic_cast<Eventually *>(nti)->getInterval();
      auto ti_intv = dynamic_cast<Eventually *>(ti)->getInterval();
      //Interval = interval of next Eventually - interval of this eventually
      nti_intv.first -= ti_intv.first;
      nti_intv.second -= ti_intv.second;
      ret.push_back(
          std::make_pair(dynamic_cast<TemporalInst *>(
                             (dynamic_cast<Eventually *>(ti)->getOperand()))
                             ->getProposition(),nti_intv)
                         );
    }
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
