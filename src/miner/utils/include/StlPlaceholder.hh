#pragma once

#include "TemporalExp.hh"
namespace harm {

class StlPlaceholder : public TemporalExp {
public:
  StlPlaceholder(expression::Proposition *prop, const std::string &name);

  virtual ~StlPlaceholder();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  void setProposition(expression::Proposition *p);

  expression::Proposition* getProposition(){
      return _prop;
  }

  std::string getName() { return _name; }

private:
  expression::Proposition *_prop = nullptr;
  std::string _name = "";
};

}; // namespace harm
