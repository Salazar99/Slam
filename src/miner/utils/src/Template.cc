#include "Template.hh"
#include "EdgeProposition.hh"
#include "colors.hh"
#include "fort.hpp"
#include "globals.hh"
#include "message.hh"
#include "minerUtils.hh"
#include "misc.hh"

#include <algorithm>
#include <deque>
#include <fstream>
#include <spot/tl/formula.hh>
#include <spot/tl/parse.hh>
#include <spot/tl/print.hh>
#include <spot/twaalgos/hoa.hh>
#include <spot/twaalgos/isdet.hh>
#include <spot/twaalgos/ltl2tgba_fm.hh>
#include <spot/twaalgos/minimize.hh>
#include <spot/twaalgos/postproc.hh>
#include <spot/twaalgos/sccfilter.hh>
#include <spot/twaalgos/stripacc.hh>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
namespace harm {

Template::Template(harm::Trace *trace, DTLimits limits) : _max_length(trace->getLength()), _limits(limits), _trace(trace) {

  build();
}

Template::Template(const Template &original) {
  _trace = original._trace;
  //for (auto &s : _templateFormula) {
  //  //we need to reinizializes/copy all the propositions in the templateFormula to the new copy of the template, two instances of the same template should not have overlapping memory
  //  if (s._te != nullptr) {
  //    if (s._t == Hstring::Stype::Inst) {
  //      Proposition *p =
  //          dynamic_cast<TemporalInst *>(*s._te)->getProposition();
  //      s._te = new TemporalExp *(new TemporalInst(
  //          p != nullptr ? new CachedProposition(copy(*p)) : nullptr,
  //          dynamic_cast<TemporalInst *>(*s._te)->getName()));
  //    } else if (s._t == Hstring::Stype::Ph) {
  //      Proposition *p =
  //          dynamic_cast<Placeholder *>(*s._te)->getProposition();
  //      s._te = new TemporalExp *(new Placeholder(
  //          p != nullptr ? new CachedProposition(copy(*p)) : nullptr,
  //          dynamic_cast<Placeholder *>(*s._te)->getName()));
  //    }
  //  }
  //}
  //_buildTemplateFormula = _templateFormula;
  _max_length = original._max_length;
  _limits = original._limits;
  _check = original._check;

  //rebuild the template
  build();

  _tokenToProp = original._tokenToProp;
  _tokenToIntv = original._tokenToIntv;
  _aphToProp = original._aphToProp;
  _acphToProp = original._acphToProp;
  _cphToProp = original._cphToProp;
  _iToProp = original._iToProp;
  _tokenToIntv = original._tokenToIntv;
  _dtOp = original._dtOp;
  _impl = original._impl;

  //shallow copy, need to configure and copy the data
  _pg = original._pg;

  genPermutations(original._aProps, original._cProps, original._acProps);

  //if the original contains permutations we simply copy the permutation matrix to _pg
  if (original._pg._perms != nullptr) {
    _pg._perms = copy_matrix(original._pg._perms, original._pg._size.first,
                             original._pg._size.second);
  }
}

Template::~Template() {

  delete _impl;

  delete[] _antCachedValues;
  delete[] _conCachedValues;

  for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
    delete[] _cachedValuesP[i];
  }
  delete[] _cachedValuesP;

//  if (_applyDynamicShift) {
//    delete[] _dynamicShiftCachedValues;
//    for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
//      delete[] _cachedDynShiftsP[i];
//    }
//    delete[] _cachedDynShiftsP;
//  }

  // inst props are used only in a specific template: must be deleted in all instances of a template
  for (auto &ph_pp : _iToProp) {
    delete ph_pp.second;
  }

  for (auto &ph_pp : _tokenToProp) {
    delete ph_pp.second;
  }
}

size_t Template::nPermsGenerated() const {
  return _pg._size.first;
  //return _cProps.size();
}

std::string Template::getAssertion() {
        return  "G(" + temp2String(*_impl, 1) + ")";
}
std::string Template::getColoredAssertion() {
        return  GLOB("G(") + temp2ColoredString(*_impl, 1) + GLOB(")");
}
std::string Template::getTemplate() {
        return  "G(" + temp2String(*_impl, 0) + ")";
}
std::string Template::getColoredTemplate() {
        return  GLOB("G(") + temp2ColoredString(*_impl, 0) + GLOB(")");
}

DTOperator *Template::getDT() { return _dtOp.second; }

std::map<std::string, TemporalExp *> &Template::get_aphToProp() {
  return _aphToProp;
}
std::map<std::string, TemporalExp *> &Template::get_cphToProp() {
  return _cphToProp;
}
std::map<std::string, TemporalExp *> &Template::get_acphToProp() {
  return _acphToProp;
}

std::string Template::getSpotFormula() {
    return "";
}

bool Template::nextPerm() {

  if (_iToProp.size() ==
      (_tokenToProp.size() - (_dtOp.second == nullptr ? 0 : 1))) {
    return false;
  }
  messageErrorIf(_permIndex < 0, "No permutations available!");
  if ((size_t)_permIndex >= _pg._size.first) {
    _permIndex = 0;
    return false;
  }
  //load the next permutation FIXME:  this could be heavily optimised by loading only the propositions changing from the previous permutation
  _conInCache = false;
  _antInCache = false;
  for (auto &e : _pg._phToIndex) {
    harm::Location where = _pg._phToLoc.at(e.first);
    // e.first is the string representation of a placeholder e.second is the column of the permutation's table _permIndex is the row of the permutation's table

    if (where == harm::Location::Ant) {
      //fill the placeholder with the correct proposition _pg._perms[_permIndex][e.second] contains the index of the proposition to be inserted
      //FIXME Completely broken due to Hstring modification
      //  (*_aphToProp.at(e.first)) = _aProps[_pg._perms[_permIndex][e.second]];
      //} else if (where == harm::Location::Con) {
      //  (*_cphToProp.at(e.first)) = _cProps[_pg._perms[_permIndex][e.second]];
      //} else {
      //  (*_acphToProp.at(e.first)) = _acProps[_pg._perms[_permIndex][e.second]];
    }
  }
  //go to the next permutation
  _permIndex++;
  return true;
}

void Template::loadPerm(size_t n) {
  if (getNumPlaceholders() == 0 && n != 0) {
    messageError("Perm not available!");
  }
  messageErrorIf(_permIndex < 0, "No permutations available!");
  if (n >= _pg._size.first) {
    messageError("Perm not available!");
  }

  // load the next permutation
  _conInCache = false;
  _antInCache = false;
  for (auto &e : _pg._phToIndex) {
    harm::Location where = _pg._phToLoc.at(e.first);
    //e.first is the string representation of a placeholder e.second is the column of the permutation's table _permIndex is the row of the permutation's table

    if (where == harm::Location::Ant) {
      //        messageError("");
      //feel the placeholder with the correct proposition _pg._perms[_permIndex][e.second] contains the index of the proposition to be inserted
      //FIXME Completely broken due to Hstring modification
      dynamic_cast<Placeholder *>(_aphToProp.at(e.first))
          ->setProposition(_aProps[_pg._perms[n][e.second]]);
    } else if (where == harm::Location::Con) {
      dynamic_cast<Placeholder *>(_cphToProp.at(e.first))
          ->setProposition(_cProps[_pg._perms[n][e.second]]);
      //      dynamic_cast<Placeholder *>(*_cphToProp.at(e.first)) ->setProposition(_cProps[n]);
    } else {
      //       messageError("");
      dynamic_cast<Placeholder *>(_acphToProp.at(e.first))
          ->setProposition(_acProps[_pg._perms[n][e.second]]);
    }
  }
  // return to the first permutation if we have reached the end of the
  // available permutations
}

size_t Template::getNumPlaceholders(harm::Location where) {
  if (where == harm::Location::Ant) {
    return _aphToProp.size();
  } else if (where == harm::Location::Con) {
    return _cphToProp.size();
  } else {
    return _acphToProp.size();
  }
}

size_t Template::getNumPlaceholders() {
  return _aphToProp.size() + _cphToProp.size() + _acphToProp.size();
}

void Template::loadPropositions(std::vector<Proposition *> &props,
                                harm::Location where) {

  // Check errors-----------------------------
  if (where == harm::Location::Ant) {
    messageErrorIf(_aphToProp.size() != props.size(),
                   "Expecting " + std::to_string(_aphToProp.size()) +
                       " propositions, " + std::to_string(props.size()) +
                       " given!");
  } else if (where == harm::Location::Con) {
    messageErrorIf(_cphToProp.size() != props.size(),
                   "Expecting " + std::to_string(_cphToProp.size()) +
                       " propositions, " + std::to_string(props.size()) +
                       " given!");
  } else {
    messageErrorIf(_acphToProp.size() != props.size(),
                   "Expecting " + std::to_string(_acphToProp.size()) +
                       " propositions, " + std::to_string(props.size()) +
                       " given!");
  }

  //-----------------------------------------

  // Warning: the given propositions are inserted following the alphabetic order of the placeholders
  size_t i = 0;
  if (where == harm::Location::Ant) {
    if (_applyDynamicShift) {
      _conInCache = false;
    }
    // the antecedent is modified: we need to recalculate
    _antInCache = false;
    // put the propositions in the antecedent's placeholders
    for (const auto &ph : _aphToProp) {
      dynamic_cast<Placeholder *>(ph.second)->setProposition(props[i++]);
    }
  } else if (where == harm::Location::Con) {

    for (const auto &ph : _cphToProp) {
      dynamic_cast<Placeholder *>(ph.second)->setProposition(props[i++]);
    }
    _conInCache = false;
  } else {
    for (const auto &ph : _acphToProp) {
      dynamic_cast<Placeholder *>(ph.second)->setProposition(props[i++]);
    }
    _conInCache = false;
    _antInCache = false;
  }
}

int Template::getDepth(Automaton *aut) {
  std::unordered_set<size_t> marked;
  int max = 0;
  maxDepth(max, aut->_root, 1, marked);
  return max;
}
void Template::maxDepth(int &max, Automaton::Node *cn, size_t currDepth,
                        std::unordered_set<size_t> &marked) {
  //if the automaton contains cycles, the depth is unknown (-1)

  marked.insert(cn->_id);
  for (auto i : cn->_outEdges) {
    if (max == -1) {
      return;
    } else if (i->_toNode->_type != -1) {
      max = currDepth > (size_t)max ? currDepth : max;
    } else if (marked.count(i->_toNode->_id)) {
      max = -1;
      return;
    } else {
      maxDepth(max, i->_toNode, ++currDepth, marked);
    }
  }
  marked.erase(cn->_id);
}

void Template::fillContingency(size_t (&ct)[3][3], bool offset) {

  // make sure the chaced values are initialized
  evaluate(0);

  if (offset) {
    //ant -> !con

    for (size_t time = 0; time < _max_length; time++) {
      size_t shift =
          time + (_applyDynamicShift ? _dynamicShiftCachedValues[time] : 0) +
          _constShift;
      auto ant = _antCachedValues[time];
      auto con = (shift >= _max_length) ? Trinary::U : _conCachedValues[shift];
      if (ant == Trinary::T && (!con) == Trinary::T) {
        ct[0][0]++;
      } else if (ant == Trinary::T && (!con) == Trinary::F) {
        assert(0);
        ct[0][1]++;
      } else if (ant == Trinary::T && (!con) == Trinary::U) {
        ct[0][2]++;
      } else if (ant == Trinary::F && (!con) == Trinary::T) {
        ct[1][0]++;
      } else if (ant == Trinary::F && (!con) == Trinary::F) {
        ct[1][1]++;
      } else if (ant == Trinary::F && (!con) == Trinary::U) {
        ct[1][2]++;
      } else if (ant == Trinary::U && (!con) == Trinary::T) {
        ct[2][0]++;
      } else if (ant == Trinary::U && (!con) == Trinary::F) {
        ct[2][1]++;
      } else if (ant == Trinary::U && (!con) == Trinary::U) {
        ct[2][2]++;
      }
    }
  } else {
    //ant -> con

    for (size_t time = 0; time < _max_length; time++) {
      size_t shift =
          time + (_applyDynamicShift ? _dynamicShiftCachedValues[time] : 0) +
          _constShift;
      auto ant = _antCachedValues[time];
      auto con = (shift >= _max_length) ? Trinary::U : _conCachedValues[shift];
      if (ant == Trinary::T && con == Trinary::T) {
        ct[0][0]++;
      } else if (ant == Trinary::T && con == Trinary::F) {
        ct[0][1]++;
      } else if (ant == Trinary::T && con == Trinary::U) {
        ct[0][2]++;
      } else if (ant == Trinary::F && con == Trinary::T) {
        ct[1][0]++;
      } else if (ant == Trinary::F && con == Trinary::F) {
        ct[1][1]++;
      } else if (ant == Trinary::F && con == Trinary::U) {
        ct[1][2]++;
      } else if (ant == Trinary::U && con == Trinary::T) {
        ct[2][0]++;
      } else if (ant == Trinary::U && con == Trinary::F) {
        ct[2][1]++;
      } else if (ant == Trinary::U && con == Trinary::U) {
        ct[2][2]++;
      }
    }
  }
}

void Template::setCacheAntFalse() { _antInCache = false; }

void Template::setCacheConFalse() { _conInCache = false; }

void Template::build() {

//  //allocate memory for truth values of the template on the trace note that due to parallelism, we allocate N times the required memory where N is the maximum number of threads at level 1 (l1Constants::MAX_THREADS)
//
//  //working memory: used by linearEval
  _cachedValuesP = new Trinary *[l1Constants::MAX_THREADS];

  for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
    _cachedValuesP[i] = new Trinary[_max_length];
    //init
    std::fill_n(_cachedValuesP[i], _max_length, Trinary::U);
  }
//
//  //final truth values memory: final result of linearEval
  _antCachedValues = new Trinary[_max_length];
  std::fill_n(_antCachedValues, _max_length, Trinary::U);
  _conCachedValues = new Trinary[_max_length];
  std::fill_n(_conCachedValues, _max_length, Trinary::U);
//
//  // clear utility variables
//  _tokenToProp.clear();
//  _tokenToIntv.clear();
//  _aphToProp.clear();
//  _acphToProp.clear();
//  _cphToProp.clear();
//  _iToProp.clear();
//  _tokenToIntv.clear();
//  _dtOp.first = "";
//  _dtOp.second = nullptr;
//  _constShift = 0;
//  _applyDynamicShift = 0;
//
//  // init the dt operators
//  for (auto &s : _templateFormula) {
//    if (s._t == Hstring::Stype::DTAndF) {
//      s._te = new TemporalExp *(new TemporalAnd());
//      break;
//    }
//  }
//
//  // retrieve the different parts of the assertion
//  auto hant = _templateFormula.getAnt();
//  auto himpl = _templateFormula.getImp();
//  auto hcon = _templateFormula.getCon();
//
//  //ant placeholders
//  std::unordered_set<std::string> antPhs;
//
//  // fill utility variables for the antecedent
//  for (size_t i = 0; i < hant.size(); i++) {
//    auto &e = hant[i];
//    if (e._t == Hstring::Stype::Ph) {
//      _tokenToProp[e._s] = e._te;
//      _aphToProp.insert({{e._s, e._te}});
//      antPhs.insert(e._s);
//    } else if (e._t == Hstring::Stype::Intv) {
//      _tokenToIntv.insert({e._s, e._intv});
//    } else if (e._t == Hstring::Stype::Inst) {
//      _tokenToProp[e._s] = e._te;
//      _iToProp[e._s] = e._te;
//    } else if (e._t == Hstring::Stype::DTAndF) {
//      _tokenToProp[e._s] = e._te;
//      _dtOp = std::make_pair(
//          e._s, new DTAndF(dynamic_cast<TemporalAnd *>(*e._te), this, _limits));
//    }
//  }
//
//  // fill utility variables for the consequent
//  for (size_t i = 0; i < hcon.size(); i++) {
//    auto &e = hcon[i];
//    if (e._t == Hstring::Stype::Ph) {
//      _tokenToProp[e._s] = e._te;
//      if (antPhs.count(e._s)) {
//        // if a placeholder is found in both the antecedent and consequent than it is of type 'ac'
//        _aphToProp.erase(e._s);
//        _acphToProp.insert({{e._s, e._te}});
//      } else {
//        _cphToProp.insert({{e._s, e._te}});
//      }
//    } else if (e._t == Hstring::Stype::Intv) {
//      _tokenToIntv[e._s] = e._intv;
//    } else if (e._t == Hstring::Stype::Inst) {
//      _tokenToProp[e._s] = e._te;
//      _iToProp[e._s] = e._te;
//    } else if (e._t == Hstring::Stype::DTAndF) {
//      messageError(
//          "Binary decision tree operator is not allowed in the consequent");
//    }
//  }
//
//  //retrieve the implication of the template
//  std::string imp = himpl._s;
//  // remove unwanted spaces in the string representation of the implication
//  imp.erase(remove_if(imp.begin(), imp.end(), isspace), imp.end());
//  // set the shifts according to the type of implication
//  if (imp == "->") {
//    _constShift = 0;
//    _applyDynamicShift = 0;
//  } else {
//    messageError("Unknown implication symbol: " + imp);
//  }
//
//  //  if (_applyDynamicShift) {
//  //    //allocate more memory to keep track of dynamic shitfs
//  //    _dynamicShiftCachedValues = new size_t[_max_length];
//  //    std::fill_n(_dynamicShiftCachedValues, _max_length, 0);
//  //    _cachedDynShiftsP = new size_t *[l1Constants::MAX_THREADS];
//  //
//  //    for (size_t i = 0; i < l1Constants::MAX_THREADS; i++) {
//  //      _cachedDynShiftsP[i] = new size_t[_max_length];
//  //      std::fill_n(_cachedDynShiftsP[i], _max_length, 0);
//  //    }
//  //  }
//
//  TemporalAnd *impant = nullptr;
//  for (size_t i = 0; i < hant.size(); i++) {
//    auto &s = hant[i];
//    if (s._t == Hstring::Stype::DTAndF) {
//      impant = dynamic_cast<TemporalAnd *>(*s._te);
//    }
//  }
//  TemporalAnd *conAnd = new TemporalAnd();
//  for (auto &cte : _cphToProp) {
//    conAnd->addItem(*cte.second);
//  }
//  TemporalExp *impcon =
//      new Eventually(conAnd, new std::pair<size_t, size_t>(0, 0), _trace);
//
//  //iter over hant to find each subformula
//  //bool isEventually = false;
//  //  std::stack<std::string> phIntv;
//
//  //  for (size_t i = 0; i < hant.size(); i++) {
//  //    auto &s = hant[i];
//  //    if (s._t == Hstring::Stype::Ph) {
//  //      if (isEventually) {
//  //        std::string intval = phIntv.top();
//  //        phIntv.pop();
//  //        impant->addItem(
//  //            new Eventually(*s._te, _tokenToIntv.at(intval), _trace));
//  //      } else {
//  //        impant->addItem(*s._te);
//  //      }
//  //      isEventually = false;
//  //    } else if (s._t == Hstring::Stype::Intv) {
//  //      phIntv.push(s._s);
//  //    } else if (s._t == Hstring::Stype::Inst) {
//  //      if (isEventually) {
//  //        std::string intval = phIntv.top();
//  //        phIntv.pop();
//  //        impant->addItem(
//  //            new Eventually(*s._te, _tokenToIntv.at(intval), _trace));
//  //      } else {
//  //        impant->addItem(*s._te);
//  //      }
//  //      isEventually = false;
//  //    } else if (s._t == Hstring::Stype::Temp && s._s == "F[")
//  //      isEventually = true;
//  //    else if (s._t == Hstring::Stype::DTAndF) {
//  //      impant->addItem(*s._te);
//  //    }
//  //  }
//  //
//  //  isEventually = false;
//  //
//  //  for (size_t i = 0; i < hcon.size(); i++) {
//  //    auto &s = hcon[i];
//  //    if (s._t == Hstring::Stype::Ph) {
//  //      if (isEventually) {
//  //        std::string intval = phIntv.top();
//  //        phIntv.pop();
//  //        impant->addItem(
//  //            new Eventually(*s._te, _tokenToIntv.at(intval), _trace));
//  //      } else {
//  //        impcon->addItem(*s._te);
//  //      }
//  //      isEventually = false;
//  //    } else if (s._t == Hstring::Stype::Intv) {
//  //      phIntv.push(s._s);
//  //    } else if (s._t == Hstring::Stype::Inst) {
//  //      if (isEventually) {
//  //        std::string intval = phIntv.top();
//  //        phIntv.pop();
//  //        impcon->addItem(
//  //            new Eventually(*s._te, _tokenToIntv.at(intval), _trace));
//  //      } else {
//  //        impcon->addItem(*s._te);
//  //      }
//  //      isEventually = false;
//  //    } else if (s._t == Hstring::Stype::Temp && s._s == "F[")
//  //      isEventually = true;
//  //    else if (s._t == Hstring::Stype::DTAndF)
//  //      messageError("DT operand is not allowed in the consequent");
//  //  }
//
//  _impl = new Implication(impant, impcon);
}

void Template::genPermutations(const std::vector<Proposition *> &antP,
                               const std::vector<Proposition *> &conP,
                               const std::vector<Proposition *> &antConP) {
  //fully instantiated : only one permutation
  if (getNumPlaceholders() == 0) {
    _pg._size.first = 1;
    _pg._size.second = 0;
    _permIndex = 0;
    return;
  }

  // save the domains of the permutations
  _aProps = antP;
  _cProps = conP;
  _acProps = antConP;

  messageErrorIf(_aProps.size() < _aphToProp.size(),
                 "Not enough 'a' propositions!");
  messageErrorIf(_cProps.size() < _cphToProp.size(),
                 "Not enough 'c' propositions!");
  messageErrorIf(_acProps.size() < _acphToProp.size(),
                 "Not enough 'ac' propositions!");

  //generate only if there are not any previously generated perms
  if (_pg._perms == nullptr) {
    _pg.genPermutations(_aProps.size(), _cProps.size(), _acProps.size(), this);
  }
  //set to the first perm
  _permIndex = 0;
}

std::string Template::findCauseInProposition(Proposition *ep, size_t time,
                                             bool goal) {
  std::string ret = "";
  if (dynamic_cast<PropositionAnd *>(ep) != nullptr) {
    auto operands = dynamic_cast<PropositionAnd *>(ep)->getItems();
    std::vector<Proposition *> opContinue;
    if (goal) {
      for (auto o : operands) {
        opContinue.push_back(o);
      }
    } else {
      for (auto o : operands) {
        if (!o->evaluate(time)) {
          opContinue.push_back(o);
        }
      }
    }

    ret += findCauseInProposition(opContinue[0], time, goal);
    for (size_t i = 1; i < opContinue.size(); i++) {
      ret += " && " + findCauseInProposition(opContinue[i], time, goal);
    }
    return ret;
  }

  if (dynamic_cast<PropositionOr *>(ep) != nullptr) {
    auto operands = dynamic_cast<PropositionOr *>(ep)->getItems();
    std::vector<Proposition *> opContinue;
    if (goal) {
      for (auto o : operands) {
        if (o->evaluate(time)) {
          opContinue.push_back(o);
        }
      }
    } else {
      for (auto o : operands) {
        opContinue.push_back(o);
      }
    }

    ret += findCauseInProposition(opContinue[0], time, goal);
    for (size_t i = 1; i < opContinue.size(); i++) {
      ret += " || " + findCauseInProposition(opContinue[i], time, goal);
    }
    return ret;
  }

  if (dynamic_cast<PropositionNot *>(ep) != nullptr) {
    auto operands = dynamic_cast<PropositionNot *>(ep)->getItems();
    ret += "!(" + findCauseInProposition(operands[0], time, !goal) + ")";
    return ret;
  }

  return prop2String(*ep);
}

std::string Template::findCauseInEdgeProposition(EdgeProposition *ep,
                                                 size_t time, bool goal,
                                                 bool expPlaceholders) {
  std::string ret = "";
  if (dynamic_cast<EdgeAnd *>(ep) != nullptr) {
    auto operands = ep->getOperands();
    std::vector<EdgeProposition *> opContinue;
    if (goal) {
      for (auto o : operands) {
        opContinue.push_back(o);
      }
    } else {
      for (auto o : operands) {
        if (!o->evaluate(time)) {
          opContinue.push_back(o);
        }
      }
    }

    ret +=
        findCauseInEdgeProposition(opContinue[0], time, goal, expPlaceholders);
    for (size_t i = 1; i < opContinue.size(); i++) {
      ret += " && " + findCauseInEdgeProposition(opContinue[i], time, goal,
                                                 expPlaceholders);
    }
    return ret;
  }

  if (dynamic_cast<EdgeOr *>(ep) != nullptr) {
    auto operands = ep->getOperands();
    std::vector<EdgeProposition *> opContinue;
    if (goal) {
      for (auto o : operands) {
        if (o->evaluate(time)) {
          opContinue.push_back(o);
        }
      }
    } else {
      for (auto o : operands) {
        opContinue.push_back(o);
      }
    }

    ret +=
        findCauseInEdgeProposition(opContinue[0], time, goal, expPlaceholders);
    for (size_t i = 1; i < opContinue.size(); i++) {
      ret += " || " + findCauseInEdgeProposition(opContinue[i], time, goal,
                                                 expPlaceholders);
    }
    return ret;
  }

  if (dynamic_cast<EdgeNot *>(ep) != nullptr) {
    auto operands = ep->getOperands();
    ret +=
        "!(" +
        findCauseInEdgeProposition(operands[0], time, !goal, expPlaceholders) +
        ")";
    return ret;
  }

  if (dynamic_cast<EdgePlaceholder *>(ep) != nullptr) {
    if (expPlaceholders) {
      Proposition *p = *dynamic_cast<EdgePlaceholder *>(ep)->_toProp;
      if (dynamic_cast<CachedProposition *>(p) != nullptr) {
        return findCauseInProposition(
            dynamic_cast<CachedProposition *>(p)->get(), time, goal);
      } else {
        return findCauseInProposition(p, time, goal);
      }
    } else {
      return dynamic_cast<EdgePlaceholder *>(ep)->_phName;
    }
  }

  return ep->toString();
}

//FIXME: completely broken, remove?
//std::unordered_map<std::string, size_t> Template::findCauseOfFailure() {
//  std::unordered_map<std::string, size_t> ret;
//  for (size_t i = 0; i < _max_length; i++) {
//    if (evaluate(i) == Trinary::F) {
//      if (_applyDynamicShift) {
//        ret[findCauseOfFailure(i + _dynamicShiftCachedValues[i] +
//                               _constShift)]++;
//      } else {
//        ret[findCauseOfFailure(i + _constShift)]++;
//      }
//    }
//  }
//  return ret;
//}
void Template::printContingency() {

  size_t ct[3][3] = {{0}};
  fillContingency(ct, 0);
  fort::utf8_table table;
  table.set_border_style(FT_NICE_STYLE);
  ft_set_cell_span(table.getTablePointer(), 0, 0, 4);
  table.column(1).set_cell_text_align(fort::text_align::center);
  table.column(2).set_cell_text_align(fort::text_align::center);
  table.column(3).set_cell_text_align(fort::text_align::center);
  table.column(4).set_cell_text_align(fort::text_align::center);

  table << fort::header << "Contingency" << fort::endr;

  table << ""
        << "CT"
        << "CF"
        << "CU" << fort::endr;
  ft_add_separator(table.getTablePointer());
  table << "AT" << ct[0][0] << ct[0][1] << ct[0][2] << fort::endr;
  ft_add_separator(table.getTablePointer());
  table << "AF" << ct[1][0] << ct[1][1] << ct[1][2] << fort::endr;
  ft_add_separator(table.getTablePointer());
  table << "AU" << ct[2][0] << ct[2][1] << ct[2][2] << fort::endr;
  std::cout << table.to_string() << std::endl;
}
void Template::check() {
  //FIXME
  //messageErrorIf(!isFullyInstantiated(),
  //               "Checking is available only for fully instantiated templates "
  //               "(assertions)!");
  std::cout << "==============================================================="
               "==========="
            << "\n";
  std::cout << getColoredAssertion() << "\n";
  setCacheAntFalse();
  setCacheConFalse();
  evaluate(0);
  size_t ct[3][3] = {{0}};
  fillContingency(ct, 0);
  if (!assHoldsOnTrace(harm::Location::AntCon)) {
    printContingency();
    //     FIXME:broken until findCauseOfFailure is restored
    //     auto cause = findCauseOfFailure();
    //  fort::utf8_table table;
    //  table << fort::header << "Cause of Failure"
    //        << "Impact" << fort::endr;
    //  std::vector<std::string> sorted;
    //  for (auto c : cause) {
    //    sorted.push_back(c.first);
    //  }
    //  std::sort(sorted.begin(), sorted.end(),
    //            [&cause](std::string &e1, std::string &e2) {
    //              return cause.at(e1) > cause.at(e2);
    //            });
    //  for (auto c : sorted) {
    //    table << c
    //          << to_string_with_precision(
    //                 ((double)cause.at(c) / (double)ct[0][1]) * 100, 2) +
    //                 "%\n"
    //          << fort::endr;
    //  }
    //  std::cout << table.to_string() << std::endl;
    std::cout << "Failing sub-traces:\n";
    for (size_t i = 0; i < _max_length; i++) {
      if (evaluate(i) == Trinary::F) {
        std::cout << "===================================="
                  << "\n";
        size_t shift = 0;
        if (_applyDynamicShift) {
          // evalAutomatonDyShift(i, _ant, shift);
        } else {
          // evalAutomaton(i, _ant);
        }

        shift += _constShift;

        //  evalAutomatonDyShift(shift, _con, shift);
        std::cout << "[" << i << "," << shift << "]"
                  << "\n";
        std::cout << _trace->printTrace(i, (shift - i) + 1) << "\n";
        std::cout << "===================================="
                  << "\n";
      }
    }
  } else {
    printContingency();
    std::cout << "OK!"
              << "\n";
  }
  if (_max_length < 30) {
    std::cout << "Ant: ";
    for (size_t i = 0; i < _max_length; i++) {
      //FIXME
      //      std::cout << evaluate_ant(i) << "(" << i << ")" << " ";
    }

    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Sft: ";
    if (_applyDynamicShift || _constShift > 0) {
      for (size_t i = 0; i < _max_length; i++) {
        std::cout << (!_applyDynamicShift ? 0 : _dynamicShiftCachedValues[i]) +
                         _constShift
                  << "(" << i << ")"
                  << " ";
      }
    }
    std::cout << "\n";
    std::cout << "\n";

    std::cout << "Con: ";
    for (size_t i = 0; i < _max_length; i++) {
      //FIXME
      //std::cout << evaluate_con(i) << "(" << i << ")" << " ";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Ass: ";
    for (size_t i = 0; i < _max_length; i++) {
      std::cout << evaluate(i) << "(" << i << ")"
                << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  std::cout << "==============================================================="
               "==========="
            << "\n";
}

void Template::getPlaceholdersDepth(
    spot::formula f, std::vector<std::pair<std::string, size_t>> &phToDepth) {
  static int depth = -1;
  depth++;
  if (f.is(spot::op::ap)) {
    phToDepth.emplace_back(f.ap_name(), depth);
  } else {
    for (size_t i = 0; i < f.size(); i++) {
      getPlaceholdersDepth(f[i], phToDepth);
    }
  }
  depth--;
}
/*
std::vector<Proposition *> Template::getLoadedPropositions() {
  std::vector<Proposition *> ret;
  for (auto &s : _templateFormula) {
    if (s._t == Hstring::Stype::Ph || s._t == Hstring::Stype::Inst) {
      assert(s._pp != nullptr);
      ret.push_back(*s._pp);
    }
  }
  if (_dtOp.second != nullptr) {
    if (_dtOp.second->isMultiDimensional()) {
      std::vector<TemporalExp *> items = _dtOp.second->unpack();
      ret.insert(ret.end(), items.begin(), items.end());
    } else {
      std::vector<TemporalExp *> items = _dtOp.second->getItems();
      ret.insert(ret.end(), items.begin(), items.end());
    }
  }
  return ret;
}
*/
/*
std::vector<Proposition *> Template::getLoadedPropositionsAnt() {
  std::vector<Proposition *> ret;
  for (auto &s : _templateFormula.getAnt()) {
    if (s._t == Hstring::Stype::Ph || s._t == Hstring::Stype::Inst) {
      assert(s._pp != nullptr);
      ret.push_back(*s._pp);
    }
  }
  if (_dtOp.second != nullptr) {
    //FIXME getLoadedProposition needs to be modified
    
    if (_dtOp.second->isMultiDimensional()) {
      std::vector<Proposition *> items = _dtOp.second->unpack();
      ret.insert(ret.end(), items.begin(), items.end());
    } else {
      std::vector<Proposition *> items = _dtOp.second->getItems();
      ret.insert(ret.end(), items.begin(), items.end());
    }
    
  }
  return ret;
}

std::vector<Proposition *> Template::getLoadedPropositionsCon() {
  std::vector<Proposition *> ret;
  for (auto &s : _templateFormula.getCon()) {
    if (s._t == Hstring::Stype::Ph || s._t == Hstring::Stype::Inst) {
      assert(s._pp != nullptr);
      ret.push_back(*s._pp);
    }
  }
  return ret;
}
void Template::setL1Threads(size_t n) {
  std::lock_guard<std::mutex> lock{_l1Guard};
  _availThreads = n;
}
size_t Template::getL1Threads() {
  std::lock_guard<std::mutex> lock{_l1Guard};
  return _availThreads;
}

void Template::setDTLimits(const DTLimits &l) { _limits = l; }
bool Template::saveOffset() { return _limits._saveOffset; }
bool Template::isFullyInstantiated() {
  return (getNumPlaceholders(harm::Location::Ant) +
          getNumPlaceholders(harm::Location::Con) +
          getNumPlaceholders(harm::Location::AntCon)) == 0 &&
         _dtOp.second == nullptr;
}
*/
TemporalExp *Template::getPropByToken(const std::string &token) {
  if (_tokenToProp.count(token)) {
    return _tokenToProp.at(token);
  }
  return nullptr;
}

void Template::subPropInAssertion(Proposition *original, Proposition *newProp) {
  //FIXME
  //bool found = 0;
  //for (auto ph : _tokenToProp) {
  //  if ((*ph.second) == original) {
  //    (*ph.second) = newProp;
  //    found = 1;
  //  }
  //}
  //messageErrorIf(!found, "Did not find proposition '" + prop2String(*original) +
  //                           "' in '" + getColoredAssertion() + "'");
}

std::string Template::printAutomaton(Automaton *aut) {
  Automaton::Node *root = aut->_root;
  std::deque<Automaton::Node *> fringe;
  std::unordered_set<Automaton::Node *> visited;
  std::string ret;

  // visit the automata starting from the initial state(BFS)
  fringe.push_front(root);
  visited.insert(root);

  while (!fringe.empty()) {
    // add to fringe all states reachable from this state
    // out edges can be added to fringe only once
    // add new states to fringe
    auto currState = fringe.back();
    fringe.pop_back();
    ret += "[" + std::to_string(currState->_id) + "," +
           std::to_string(currState->_type) + "]" + "\n";

    for (auto edge : currState->_outEdges) {
      ret += edge->_prop->toString() + "\n";
      if (visited.count(edge->_toNode) == 0) {
        // mark as visited
        visited.insert({edge->_toNode});
        fringe.push_back(edge->_toNode);
      } // visited.count
      ret += "\n";
    }
  }
  return ret;
}

} // namespace harm
