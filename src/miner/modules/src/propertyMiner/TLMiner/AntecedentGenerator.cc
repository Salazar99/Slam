#include "AntecedentGenerator.hh"
#include "DTOperator.hh"
#include "KDE.hh"
#include "supportMethods.hh"

#include <algorithm>
#include <climits>
#include <cmath>
#include <float.h>
#include <ios>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <utility>

#define numLeavesOffset 1000000

#if printTree
std::mutex printTreeMutex;
std::string replaceAll(std::string str, const std::string &from,
                       const std::string &to) {
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
    str.replace(start_pos, from.length(), to);
    start_pos +=
        to.length(); // Handles case where 'to' is a substring of 'from'
  }
  return str;
}
#endif

namespace exharm {

namespace {
namespace MT /* multi-thread methods */ {

// the result of the decision-tree algorithm
struct Result_DC {
  size_t occProposition; // how many times is the proposition satisfied?
  size_t occGoal; // how many times are the goal and the proposition satisfied?
};

Result_DC mean_MT(Template *t) {
  //std::cout << t->getAssertion() << "\n";
  Result_DC res{0, 0};

  t->setCacheAntFalse();

  for (size_t i = 0; i < t->_max_length; i++) {

    if (t->evaluate_ant(i) != Trinary::T) {
      continue;
    }
    if (t->evaluate(i) == Trinary::T) {
      ++res.occGoal;
      ++res.occProposition;
    } else if (t->evaluate(i) == Trinary::F) {
      res.occProposition++;
    }
  }

  //  debug
  //  std::cout << t->getColoredAssertion() << "\n";
  //  for (size_t i = 0; i < t->_max_length; i++) {
  //    std::cout << t->evaluate_ant(i) << " ";
  //  }
  //  std::cout << "\n";
  //  for (size_t i = 0; i < t->_max_length; i++) {
  //    std::cout << t->evaluate_con(i) << " ";
  //  }
  //  std::cout << "\n";
  //
  //
  //  std::cout << "----------------------"
  //            << "\n";
  return res;
}

} // namespace MT
} // namespace

AntecedentGenerator::AntecedentGenerator()
    : maxPropositions(0), onSets(), offSets(), saveOffset(true) {
  // ntd
}

void AntecedentGenerator::makeAntecedents(
    Template *t, DecTreeVariables &dcVariables,
    NumericDecTreeExp &numericCandidates,
    std::vector<Proposition *> &genProps) {

  knownSolutions.clear();

  std::set<size_t> unusedVars;
  for (size_t i = 0; i < dcVariables.size(); ++i)
    unusedVars.insert(i);

  std::set<size_t> unusedNumerics;
  for (size_t i = 0; i < numericCandidates.size(); ++i) {
    unusedNumerics.insert(i);
  }

  MT::Result_DC res = MT::mean_MT(t);

  double initialEntropy =
      getConditionalEntropy(res.occProposition, res.occGoal, t->_max_length);
  //  debug
  //    std::cout << "initial entropy " << initialEntropy << "\n";
  //    std::cout << "initial res.occProposition: " << res.occProposition <<
  //    "\n"; std::cout << "initial res.occGoal: " << res.occGoal << "\n";

#if printTree
  tree.str(std::string(""));
  tree.precision(2);
  foundAss.str(std::string(""));
  nStateToAss.clear();
  nStates = 0;
#endif

  _runDecisionTree(unusedVars, dcVariables, unusedNumerics, numericCandidates,
                   t, genProps, initialEntropy);

#if printTree
  printTreeMutex.lock();
  std::ofstream fs("tree.dot", ios_base::app);
  fs << "digraph G {"
     << "\n";
  fs << "label=\"" << t->getAssertion() << "\"\n\n\n";
  fs << "labelloc=\"t\"\n";
  fs << tree.str() << "\n";
  fs << foundAss.str() << "\n";
  for (auto &ass : nStateToAss) {
    fs << "a" << ass.first << "[shape=box, color=\"green4\" label=\"{"
       << ass.second << "}\""
       << "]\n";
  }
  fs << "}"
     << "\n";
  fs.close();
  printTreeMutex.unlock();
#endif
}

inline void AntecedentGenerator::findCandidates(
    size_t candidate, DecTreeVariables &dcVariables, Template *t,
    std::vector<DiscoveredLeaf> &discLeaves, std::vector<CandidateDec> &igs,
    int depth, double currEntropy) {
  //  // debug
  //  // std::cout << "RIG: " << RIG << "\n";
  //  // std::cout << "_condEnt: " << condEnt << "\n";
  //  // std::cout <<"\t\t\t\t\t\t"
  //
  //  // the 2 propositions of X
  //  std::vector<Proposition *> propPtr;
  //  DTOperator *template_dt = t->getDT();
  //  propPtr.push_back(dcVariables[candidate].first.first);
  //  propPtr.push_back(dcVariables[candidate].first.second);
  //
  //  // for each proposition that belongs to a unused variable
  //  for (size_t propI = 0;
  //       propI < (template_dt->getLimits()._useNegatedProps ? 2 : 1); ++propI) {
  //
  //    if (template_dt->isTaken(candidate, 0, depth))
  //      continue;
  //
  //    Proposition *prop = propPtr[propI];
  //    //retrieve intervals for this prop through clustering
  //    //std::vector<std::pair<size_t,size_t>> prop_intv = gatherIntervalsFromTemp(prop, t, depth, genProps);
  //
  //    //      debug
  //    // std::cout << "-------------"F
  //    //          << "\n";
  //    // std::cout << t->getColoredAssertion() << "\n";
  //    // std::cout << "Candidate(" << depth << "): " << prop2String(*prop) <<
  //    // "\n";
  //
  //    // add the new proposition of a unused variable in the current
  //    // antecedent
  //    std::pair<size_t, size_t> intv = std::pair<size_t, size_t>({0, 0});
  //    template_dt->addItem(prop, intv, depth);
  //
  //    // ignore this prop if the template contains a known solution
  //    /*
  //      if ((template_dt->isRandomConstructed() ||
  //           template_dt->isMultiDimensional()) &&
  //          isKnownSolution(template_dt->getItems(), template_dt, 1)) {
  //        template_dt->popItem(depth);
  //        continue;
  //      }
  //    */
  //    MT::Result_DC res = MT::mean_MT(t);
  //
  //    // is the new antecedent at least once satisfied? (avoid vacuity)
  //
  //    if (res.occProposition > 0) {
  //      //      debug
  //      //      std::cout << "-------->" << prop2String(*prop) << "\n";
  //
  //      if (res.occGoal == 0 || res.occGoal == res.occProposition) {
  //
  //        template_dt->addLeaf(prop, candidate, propI, depth);
  //        discLeaves.push_back(DiscoveredLeaf(candidate, propI, depth));
  //
  //        storeSolution(t, res.occGoal == 0);
  //      } else {
  //        double condEnt = getConditionalEntropy(res.occProposition, res.occGoal,
  //                                               t->_max_length);
  //        double IG = currEntropy - condEnt;
  //        //        debug
  //        //        if (IG<0) {
  //        //         std::cout <<"********************************>"<<
  //        //         currEntropy<<" - "<< condEnt<<" = "<<IG <<"\n";
  //        //        }
  //        //igs.emplace_back(candidate, IG, depth, propPtr[0], 0, condEnt);
  //        igs.emplace_back(candidate, IG, depth, propPtr[propI], propI, condEnt);
  //      }
  //    }
  //
  //    template_dt->popItem(depth);
  //  }
  //  // debug
  //  // std::cout << "RIG: " << RIG << "\n";
  //  // std::cout << "_condEnt: " << condEnt << "\n";
  //  // std::cout <<"\t\t\t\t\t\t"
  //  // <<__func__<<"<---------"<<t->getColoredAssertion() << "\n";
}

inline std::vector<std::pair<CachedAllNumeric::EvalRet, size_t>>
AntecedentGenerator::gatherInterestingValues(Template *t, CachedAllNumeric *cn,
                                             int depth) {
  //FIXME: antecedentGenerator::gatherInterestingValue does absolutely nothing at the moment
  //everything is done at template side
  auto ret = t->gatherInterestingValue(cn, depth, -1);
  //  std::cout << "Numeric: " << allNum2String(*cn) << std::endl;

  //  for(auto &pair : ret){
  //    std::cout <<"("<<pair.first._d << "," << pair.second <<") " ;
  //  }

  // std::cout << "\n";
  return ret;
}

inline std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>>
AntecedentGenerator::gatherPropositionsFromNumerics(
    CachedAllNumeric *cn, Template *t, int depth,
    std::vector<Proposition *> &genProps) {

  // 1. Gather IV
  std::vector<std::pair<CachedAllNumeric::EvalRet, size_t>> ivs =
      gatherInterestingValues(t, cn, depth);
  // 2. Generation of propositions
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> propsWintv;
  if (!ivs.empty()) {
    propsWintv = genPropsThroughClustering(ivs, cn, t->_max_length);
  }
  // keep track of generated props to know what to delete
  for (auto &item : propsWintv)
    genProps.push_back(item.first);

  // 3. Selection of best candidates

  return propsWintv;
}

inline void AntecedentGenerator::findCandidatesNumeric(
    size_t candidate, NumericDecTreeExp &dcVariables, Template *t,
    std::vector<DiscoveredLeaf> &discLeaves, std::vector<CandidateDec> &igs,
    int depth, std::vector<Proposition *> &genProps, double currEntropy) {

  DTOperator *template_dt = t->getDT();

  if (template_dt->isTaken(candidate + numLeavesOffset, 0, depth)) {
    //std::cout << allNum2String(*dcVariables.at(candidate)) << " is taken "
    //          << t->getColoredAssertion() << " cannot continue"
    //          << "\n";
    return;
  }

  //std::cout << "DT size: "<<template_dt->getNChoices()  <<std::endl;

  // retrieve the propositions (props)
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> props =
      gatherPropositionsFromNumerics(dcVariables.at(candidate), t, depth,
                                     genProps);

  for (auto prop : props) {

    bool taken = 0;

    //std::cout << "Checking: " << prop2String(*prop.first)
    //          << "Interval: " << prop.second.first << " , "
    //          << prop.second.second << std::endl;

    // add the new proposition of a unused variable in the current
    // antecedent

    template_dt->addItem(prop.first, prop.second, depth);

          //std::cout << "Checking:"
          //          << "\n";
          //std::cout << "\t\t\t" << prop2String(*prop.first)
          //          << "Interval: " << prop.second.first << " , "
          //          << prop.second.second << std::endl;
          //std::cout << "\t\t\t" << t->getAssertion() << "\n";

    // ignore this prop if the template contains a known solution
    /*
    if ((template_dt->isRandomConstructed() ||
         template_dt->isMultiDimensional()) &&
        isKnownSolution(template_dt->getItems(), template_dt, 1)) {
      template_dt->popItem(depth);
      continue;
    }
    */
    MT::Result_DC res = MT::mean_MT(t);

    // is the new antecedent at least once satisfied? (avoid vacuity)
    if (res.occProposition > 0) {

      //          std::cout << "-------->" <<prop2String(*prop)<< "\n";
      //          std::cout << " res.occGoal: " <<  res.occGoal << "\n";
      //          std::cout << " res.occProposition " <<  res.occProposition <<
      //          "\n";
      if (res.occGoal == 0 || res.occGoal == res.occProposition) {
        taken = 1;
        discLeaves.push_back(
            DiscoveredLeaf(candidate + numLeavesOffset, 0, depth));

        storeSolution(t, res.occGoal == 0);
      } else {
        double condEnt = getConditionalEntropy(res.occProposition, res.occGoal,
                                               t->_max_length);
        double IG = currEntropy - condEnt;
        //        debug
        //if (IG<0) {
        // std::cout <<"********************************>"<<
        // currEntropy<<" - "<< condEnt<<" = "<<IG <<"\n";
        //}

        if (!taken) {
          //std::cout << "\t\t\t....Continue (" << IG << "): \n";
          igs.emplace_back(candidate + numLeavesOffset, IG, depth, prop.first,
                           prop.second, 0, condEnt);
        }
      }
    }
    template_dt->popItem(depth);
  }
}
bool AntecedentGenerator::isKnownSolution(
    const std::vector<Proposition *> &items, DTOperator *template_dt,
    bool checkOnly) {
  /*
  std::stringstream ss;
  if (template_dt->isMultiDimensional()) {
    for (auto &pack : items) {
      for (auto &p : template_dt->unpack(pack)) {
        ss << p << "$";
      }
      ss << "$";
    }
  } else {
    for (auto &p : items) {
      ss << p << "$";
    }
  }

  if (knownSolutions.count(ss.str())) {
    return true;
  }
  if (!checkOnly) {
    knownSolutions.insert(ss.str());
  }

  */
  return false;
}
void AntecedentGenerator::_runDecisionTree(
    std::set<size_t> &unusedVars, DecTreeVariables &dcVariables,
    std::set<size_t> &unusedNumerics, NumericDecTreeExp &numericCandidates,
    Template *t, std::vector<Proposition *> &genProps, double currEntropy) {

  DTOperator *template_dt = t->getDT();

  std::vector<DiscoveredLeaf> discLeaves;
  // getting the relative information gain (RIG) for each unused variable X
  // RIG (Y|X) = (H(Y) - H(Y|X)) / H(Y)
  auto candidate = unusedVars.begin();
  auto candidateNumeric = unusedNumerics.begin();

  std::vector<CandidateDec> igs;

  //std::cout << "----->" << t->getColoredAssertion() << "\n";

  if (template_dt->getNChoices() < template_dt->getLimits()._maxAll) {
    for (; candidate != unusedVars.end() ||
           candidateNumeric != unusedNumerics.end();) {
      if (template_dt->canInsertAtDepth(-1)) {
        if (candidate != unusedVars.end())
          findCandidates(*candidate, dcVariables, t, discLeaves, igs, -1,
                         currEntropy);

        if (candidateNumeric != unusedNumerics.end()) {
          findCandidatesNumeric(*candidateNumeric, numericCandidates, t,
                                discLeaves, igs, -1, genProps, currEntropy);
        }
      }

      if (candidate != unusedVars.end())
        candidate++;

      if (candidateNumeric != unusedNumerics.end())
        candidateNumeric++;

    } // for
  }

  std::sort(begin(igs), end(igs),
            [](const CandidateDec &e1, const CandidateDec &e2) {
              return e1._ig > e2._ig;
            });

  size_t keep = 0;
  //erase all but one candidate if the range is negative
  if (igs.size() > 1 && template_dt->getLimits()._dtRange < 0.f) {
    keep = 1;
  } else {
    keep = std::ceil(igs.size() * template_dt->getLimits()._dtRange);
  }

  if (!igs.empty() && begin(igs) + keep < end(igs)) {
    igs.erase(begin(igs) + keep, end(igs));
  }
  //    std::cout << "---------start--------"
  //              << "\n";
  //    for (size_t i = 0; i < igs.size(); i++) {
  //      std::cout << "\t\t" << i << ")\t" << igs[i]._depth << "\t"
  //                << prop2String(*dcVariables[igs[i]._id].first) << "\t"
  //                << igs[i]._ig << "\n";
  //    }
  //    std::cout << "--------end-----------"
  //              << "\n";

#if printTree
  size_t currState = nStates;
#endif
  for (const auto &c_ig : igs) {
    //if (!(c_ig._intv[0].first.first == 3 && c_ig._intv[0].first.second == 5)) {
    //  continue;
    //}

    messageErrorIf(c_ig._props.size() > 1, "");

    Proposition *prop = c_ig._props[0].first;
    auto intv = c_ig._intv[0].first;
    size_t pos = c_ig._props[0].second;

    template_dt->addItem(prop, intv, c_ig._depth);
    template_dt->addLeaf(prop, c_ig._id, pos, c_ig._depth);
    discLeaves.push_back(DiscoveredLeaf(c_ig._id, pos, c_ig._depth));

#if printTree
    tree << currState << " -> " << ++nStates << "[label= \""
         << prop2String(*prop) << " \\["
         << (c_ig._depth == -1 ? template_dt->getCurrentDepth() : c_ig._depth)
         << ", "
         //             << t->getAssertion() << " \\[" <<
         //             (c_ig._depth==-1?template_dt->getCurrentDepth():
         //             c_ig._depth) << ", "
         << c_ig._ig << "\\]"
         << "\"];\n";
#endif

    _runDecisionTree(unusedVars, dcVariables, unusedNumerics, numericCandidates,
                     t, genProps, c_ig._entropy);
    template_dt->popItem(c_ig._depth);
    template_dt->removeLeaf(c_ig._id, pos, c_ig._depth);
  } // for igs

}

void AntecedentGenerator::storeSolution(Template *t, bool isOffset) {

  if (isOffset && !saveOffset) {
    return;
  }

  DTOperator *template_dt = t->getDT();

  // Let's save the current propositions
  //std::vector<Proposition *> items = template_dt->minimize(isOffset);
  std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> items =
      template_dt->getItems();

  messageErrorIf(items.empty(), "Solution is empry");
/*
  if (isKnownSolution(items, template_dt)) {
    if (template_dt->isMultiDimensional()) {
      // delete the minimized container propositions
      for (auto p : items) {
        template_dt->clearPack(p);
        delete p;
      }
    }
    return;
  }

  if (template_dt->isSolutionInconsequential(items)) {
    return;
  }
*/
#if printTree
  if (!nStateToAss.count(nStates)) {
    foundAss << nStates << "->a" << nStates << "[color=\"green4\"];\n";
    nStateToAss[nStates];
  }
  std::string ass = t->getAssertion();
  ass = replaceAll(ass, "}", "\\}");
  ass = replaceAll(ass, "{", "\\{");
#endif

  if (!isOffset) {
#if printTree
    ass = replaceAll(ass, ">", "\\>");
    nStateToAss.at(nStates) = nStateToAss.at(nStates) + ass + "\\n";
#endif

    onSets.push_back(items);
  } else {
#if printTree
    ass = replaceAll(ass, "-> ", "-> !(");
    ass = replaceAll(ass, "=> ", "=> !(");
    ass.push_back(')');
    ass = replaceAll(ass, ">", "\\>");
    nStateToAss.at(nStates) = nStateToAss.at(nStates) + ass + "\\n";
#endif

    offSets.push_back(items);
  }
}

} // namespace exharm
