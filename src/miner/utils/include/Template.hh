

#pragma once

#include <algorithm>
#include <cstdarg>
#include <deque>
#include <mutex>
#include <numeric>
#include <regex>
#include <spot/tl/formula.hh>
#include <string>
#include <thread>
#include <unordered_map>

#include "Automaton.hh"
#include "DTAndF.hh"
#include "Location.hh"
#include "PermGenerator.hh"
#include "Semaphore.hh"
#include "Trace.hh"
#include "Trinary.hh"
#include "exp.hh"
#include "misc.hh"
#include "classes/atom/CachedAllNumeric.hh"

namespace hparser {
class StlParserHandler;
}

namespace harm {

/*! \class Template
    \brief Class representing an assertion template, the template can be
   instantiated by loading boolean propositions
*/
class Template {

public:
  /** \brief Constructor
   * \param templateFormula representation of a template as a PSL formula
   * \param max_length length of the trace
   */
  Template(harm::Trace *trace, DTLimits limits);

  /** \brief Copy Constructor
   */
  Template(const Template &original) = delete;

  ~Template();

  /** \brief loads propositions to instantiate the complete
   * \param props list of propositions to be used to instantiate the template
   * \param where location in which insert the propositions ( antecedent, consequent or both)
   */
  void loadPropositions(std::vector<Proposition *> &props,
                        harm::Location where);
  /** \brief evaluates the assertion generated by loading the propositions in the template
   * \param time trace instant on which to evaluate the assertion
   */
  Trinary evaluate(size_t time);
  /** \brief evaluates the offset assertion (ant->!con) generated by loading the propositions in the template
   * \param time trace instant on which to evaluate the assertion
   */
  Trinary evaluateOffset(size_t time);
  /** \brief evaluates only the antecedent of the assertion
   * \param time trace instant on which to evaluate 
   */
  Trinary evaluate_ant(size_t time);
  /** \brief evaluates only the antecedent ignoring the chaded values
   * \param time trace instant on which to evaluate 
   */
  Trinary evaluateAntNoChache(size_t time);
  /** \brief evaluates only the consequent of the assertion
   * \param time trace instant on which to evaluate 
   */
  Trinary evaluate_con(size_t time);
  /** \brief get the maximum depth from the root node
   * \param aut the automaton
   */
  int getDepth(Automaton *aut);

  /** \brief force the next evaluation of the antecedent to ignore cached values (and store new ones)
   */
  void setCacheAntFalse();
  /** \brief force the next evaluation of the consequent to ignore cached values (and store new ones)
   */
  void setCacheConFalse();

  /** \brief returns the template insantiated with the propositions
   */
  std::string getAssertion();
  /** \brief returns the template insantiated with the propositions (colored)
   */
  std::string getColoredAssertion();

  /** \brief returns the string representation of the template
   */
  std::string getTemplate();
  /** \brief returns the string representation of the template (colored)
   */
  std::string getColoredTemplate();

  /** \brief returns a typed string representation of the template
   */

  /** \brief returns a pointer to the decision tree operator
   */
  DTOperator *getDT();

  std::map<std::string, TemporalExp *> &get_aphToProp();
  std::map<std::string, TemporalExp *> &get_cphToProp();
  std::map<std::string, TemporalExp *> &get_acphToProp();

  /** \brief 
   * \param where ant or con
   */
  size_t getNumPlaceholders(harm::Location where);
  size_t getNumPlaceholders();

  /** \brief  generates a sequence of permutations for the current template,
   * each permutation is a set of propositions to be used to instantiate the
   * template
   * \param antP propositions for the antecedent
   * \param conP propositions for the consequent
   * \param antConP propositions for placeholders that are both in the antecedent and the consequent
   */
  void genPermutations(const std::vector<Proposition *> &antP,
                       const std::vector<Proposition *> &conP,
                       const std::vector<Proposition *> &antConP);

  /** \brief loads the next permutation in the template. This method must be
   * called after genPermutations.
   */
  bool nextPerm();
  /** \brief loads the n_th permutation in the template. This method must be
   * called after genPermutations.
   * \param the index of the permutation to load
   */
  void loadPerm(size_t n);
  /** \brief get the depth of the placeholder in the abtract syntax tree of the template formula
   * \param phToDepth a list that is filled by this method
   */
  void
  getPlaceholdersDepth(spot::formula f,
                       std::vector<std::pair<std::string, size_t>> &phToDepth);

  /** \brief get the depth of the propositions in the abtract syntax tree of the template formula
   */
  std::vector<Proposition *> getLoadedPropositions();

  /** \brief get the depth of the propositions of the antecedent in the abtract syntax tree of the template formula
   */
  std::vector<Proposition *> getLoadedPropositionsAnt();
  /** \brief get the depth of the propositions of the consequent in the abtract syntax tree of the template formula
   */
  std::vector<Proposition *> getLoadedPropositionsCon();

  /** \brief get the number of permutations generated */
  size_t nPermsGenerated() const;

  /** \brief returns true if the assertion holds on the input trace, false otherwise */
  bool assHoldsOnTrace(harm::Location update);
  /** \brief returns true if the assertion (offset) holds on the input trace, false otherwise */
  bool assHoldsOnTraceOffset(harm::Location update);
  /** \brief returns true if the assertion is vacuouse, false otherwise */
  bool isVacuous(harm::Location update);
  /** \brief returns true if the assertion is vacuouse (offset), false otherwise */
  bool isVacuousOffset(harm::Location update);

public:
  /** \brief fill the contingency table with the cached values
   * \param ct is a pointer to a suitable matrix
   */
  void fillContingency(size_t (&ct)[3][3], bool offset);

  void setL1Threads(size_t n);
  size_t getL1Threads();

  void setDTLimits(const DTLimits &l);

  /** \brief returns true if the dt algo must also consider the offset assertions
   */
  bool saveOffset();
  bool isFullyInstantiated();
  void printContingency();

  /** \brief check if this (fully instantied) template holds on the input trace, it prints the reason if it does not hold
   */
  void check();

  TemporalExp *getPropByToken(const std::string &token);
  Automaton *getAntecedentAutomaton();

  size_t gatherInterestingValue(size_t time, int depth, int width);

  std::vector<std::pair<expression::CachedAllNumeric::EvalRet, size_t>>
  gatherInterestingValue(CachedAllNumeric *cn, int depth, int width);

  void subPropInAssertion(Proposition *original, Proposition *newProp);

  TemporalExp *getImplication() { return _impl; }

  void transferPermutations(const Template &original) {

    _pg = original._pg;

    genPermutations(original._aProps, original._cProps, original._acProps);

    //if the original contains permutations we simply copy the permutation matrix to _pg
    if (original._pg._perms != nullptr) {
      _pg._perms = copy_matrix(original._pg._perms, original._pg._size.first,
                               original._pg._size.second);
    }
  }
  void setConsequentInterval(const std::pair<size_t, size_t> &interval) {
    dynamic_cast<Eventually *>(_impl->getItems()[1])->setInterval(interval);
  }
  std::pair<size_t, size_t> getConsequentInterval() {
    return dynamic_cast<Eventually *>(_impl->getItems()[1])->getInterval();
  }

private:
  /// used to generate the permutations
  PermGenerator _pg;

  /*utility fields to link the placeholders with the instantiated propositions,
   * note that if the placeholder is not instantiated, then the proposition
   * points to a nullptr
   */
  /// link of all placeholders to all instantiated propositions
  std::unordered_map<std::string, TemporalExp *> _tokenToProp;
  /// link of all user instantiated placeholders to their respective
  /// propositions
  std::unordered_map<std::string, TemporalExp *> _iToProp;
  /// links all the dt operators to their respective propositions
  std::pair<std::string, DTOperator *> _dtOp = {"", nullptr};

  ///_aphToProp + _cphToProp + _acphToProp == _phToProp
  std::map<std::string, TemporalExp *> _aphToProp;
  std::map<std::string, TemporalExp *> _cphToProp;
  std::map<std::string, TemporalExp *> _acphToProp;

  /* current proposition domains:
    the generator of permutations will use the following propositions to
    generate the permutations
    */
  ///used by the generator of permutations to generate the permutations
  std::vector<Proposition *> _aProps;
  std::vector<Proposition *> _cProps;
  std::vector<Proposition *> _acProps;

  ///Represents template implication
  Implication *_impl;

public:
  /// length of the trace
  size_t _max_length;

private:
  /// dt operator configuration
  DTLimits _limits;

public:
  /// pointer to the input trace
  harm::Trace *_trace;

private:
  bool _antInCache = false;
  bool _conInCache = false;

public:
  /// index to the current permutatian, -1 if no permutations are generated
  int _permIndex = -1;
  /// the template is an assertion that must be checked on the trace
  bool _check = 0;

private:
  /// available threads to implement level1 parallelism
  size_t _availThreads = 1;

  friend DTAndF;
  friend PermGenerator;
  friend hparser::StlParserHandler;
};
} // namespace harm
