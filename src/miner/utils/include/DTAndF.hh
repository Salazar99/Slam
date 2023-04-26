#pragma once
#include "DTOperator.hh"
#include "TemporalAnd.hh"

namespace harm {
/*! \class DTAndF
    \brief Decision tree operator class for ..F.., see base class for the description of the methods
*/
class DTAndF : public DTOperator {
public:
  DTAndF(TemporalAnd *p, Template *t, const DTLimits &limits);

  virtual ~DTAndF();
  virtual bool isMultiDimensional() override;
  virtual size_t getCurrentDepth() override;
  virtual bool canInsertAtDepth(int depth) override;
  virtual bool isRandomConstructed() override;
  virtual size_t getNChoices() override;
  virtual bool isTaken(size_t id, bool second, int depth) override;
  virtual void removeLeaf(size_t id, int depth) override;
  virtual void addLeaf(Proposition *p,std::pair<size_t,size_t> *intv ,size_t id, int depth) override;
  virtual void removeItems() override;
  virtual void addItem(Proposition *p, std::pair<size_t,size_t> * interval, int depth) override;
  virtual void popItem(int depth) override;
  virtual std::vector<Proposition *> getItems() override;

  virtual std::vector<TemporalExp *> minimize(bool isOffset) override;
  virtual std::vector<TemporalExp *> unpack() override;
  virtual std::vector<TemporalExp *> unpack(TemporalExp *pack) override;
  virtual std::vector<TemporalExp *> unpack(std::vector<TemporalExp *> &pack) override;

  virtual void clearPack(TemporalExp *pack) override;
  virtual std::pair<std::string, std::string> prettyPrint(bool offset) override;
  virtual bool isSolutionInconsequential(std::vector<TemporalExp *> &sol) override;
  virtual void substitute(int depth, int width, expression::Proposition *&sub) override;
  virtual const DTLimits &getLimits() override;

private:
  ///List of operands
  TemporalAnd *_choices;
  ///Pointer to the Template using this operator
  Template *_t;
  DecTreeVariables _leaves;
};
}
