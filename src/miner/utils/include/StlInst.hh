#pragma once

#include "TemporalExp.hh"

namespace harm {

class StlInst : public TemporalExp {
public:
  StlInst(expression::Proposition *prop,const std::string &name);

  virtual ~StlInst();

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

}; // namespace harm
