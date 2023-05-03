#pragma once

#include "TemporalExp.hh"

namespace harm {

class StlPlaceholder : public TemporalExp {
public:
  StlPlaceholder(expression::Proposition *prop);

  virtual ~StlPlaceholder();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<expression::Proposition *> getItems() override;

  virtual size_t size() override;

  void setProposition(expression::Proposition *p);

private:
  expression::Proposition *_prop=nullptr;
};

}; // namespace harm
