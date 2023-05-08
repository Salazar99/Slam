#pragma once

#include "TemporalExp.hh"
namespace expression {

class Placeholder : public TemporalExp {
public:
  Placeholder(expression::Proposition *prop, const std::string &name);

  virtual ~Placeholder();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  void setProposition(expression::Proposition *p);

  expression::Proposition* getProposition(){
      return _prop;
  }

  std::string getName() { return _name; }

  void acceptVisitor(ExpVisitor &vis) override;

private:
  expression::Proposition *_prop = nullptr;
  std::string _name = "";
};

}; // namespace expression
