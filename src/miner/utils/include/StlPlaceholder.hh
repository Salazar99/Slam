#pragma once

#include "TemporalExp.hh"

namespace harm {

class StlPlaceholder : public TemporalExp {
public:
  StlPlaceholder(expression::Proposition **prop);

  virtual ~StlPlaceholder();

  virtual Trinary evaluate(size_t time) override;

private:
  expression::Proposition **_prop;
};

}; // namespace harm
