#pragma once

#include "TemporalExp.hh"

namespace harm {

class StlInst : public TemporalExp {
public:
  StlInst(expression::Proposition **prop);

  virtual ~StlInst();

  virtual Trinary evaluate(size_t time) override;

private:
  expression::Proposition **_prop;
};

}; // namespace harm
