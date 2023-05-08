#pragma once

#include "TemporalExp.hh"

namespace expression {

class TemporalInst : public TemporalExp {
public:
  TemporalInst(expression::Proposition *prop,const std::string &name);

  virtual ~TemporalInst();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;
  
  virtual size_t size() override;
  std::string getName() { return _name; }

  expression::Proposition* getProposition(){
      return _prop;
  }

private:
  expression::Proposition *_prop;
  std::string _name = "";
};

}; // namespace expression
