#pragma once

#include "DTLimits.hh"
#include "DTUtils.hh"
#include "exp.hh"

#include <map>
#include <pthread.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace harm {

class Template;
class Automaton;

using namespace expression;
using DecTreeVariables =
    std::map<size_t, std::pair<
      std::pair<Proposition *,Proposition *>, 
      std::pair<size_t,size_t>>
      >;

/*! \class DTOperator
    \brief Class representing a decision tree operator
*/
class DTOperator {
public:
  virtual ~DTOperator() {}
  /** \brief Add an operand
   * \param Proposition the proposition representing the operand
   * \param depth the temporal depth in the dt operator where to insert the operand
   */
  virtual void addItem(Proposition *p, std::pair<size_t,size_t> interval, int depth) = 0;
  /** \brief Removes an operands at depth 'depth'
   */
  virtual void popItem(int depth) = 0;
  /** \brief Removes all operands
   */
  virtual void removeItems() = 0;

  /** \brief Minimize the number of dt operators
   */
  virtual std::vector<TemporalExp *> minimize(bool isOffset) = 0;
  /** \brief Return the operands of a multidimensional operator as a list of propositions
   */
  virtual std::vector<TemporalExp *> unpack() = 0;
  /** \brief Return the propositions contained in the input operand of a multidimensional operator
   */
  virtual std::vector<TemporalExp *> unpack(TemporalExp *pack) = 0;
  /** \brief Return the propositions contained in the input operands of a multidimensional operator
   */
  virtual std::vector<TemporalExp *> unpack(std::vector<TemporalExp *> &pack) = 0;
  /** \brief Remove the items in an operand of a  a multidimensional operator
   */
  virtual void clearPack(TemporalExp *pack) = 0;

  /** \brief Add a leaf of the decision tree
   * \param Proposition the proposition related to the leaf
   * \param id Id of the leaf
   * \param second if true the proposition is negated
   * \param depth depth of the leaf
   */
  virtual void addLeaf(Proposition *p, std::pair<size_t,size_t> intv, size_t id, bool second, int depth) = 0;
  /** \brief Remove a leaf of the decision tree
   * \param id Id of the leaf
   * \param intv interval of validity for the proposition
   * \param second select part to add 
   * \param depth depth of the leaf
   */
  virtual void removeLeaf(size_t id, int depth) = 0;
  /** \brief Returns true if it is possible to insert a new operand at depth 'depth'
   */
  virtual bool canInsertAtDepth(int depth) = 0;
  /** \brief substitute an operand with proposition 'sub'
   */
  virtual void substitute(int depth, int width, expression::Proposition*& sub) = 0;
  /** \brief Returns true if there is already a leaf with the given features
   */
  virtual bool isTaken(size_t id, bool second, int depth) = 0;

  /** \brief Returns true if the operator can be constructed in an unordered fashion
   */
  virtual bool isRandomConstructed() = 0;
  virtual bool isMultiDimensional() = 0;
  virtual bool isSolutionInconsequential(std::vector<TemporalExp *> &sol) = 0;

  virtual std::vector<std::pair<Proposition *, std::pair<size_t, size_t>>> getItems() = 0;
  /** \brief Returns the current number of choices in the decision tree
   */
  virtual size_t getNChoices() = 0;
  virtual size_t getCurrentDepth() = 0;
  virtual const DTLimits &getLimits() = 0;
  virtual std::pair<std::string, std::string> prettyPrint(bool offset) = 0;

protected:
  ///dt configuration
  DTLimits _limits;
};

}
