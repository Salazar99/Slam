#pragma once

#include "TemporalAnd.hh"
#include "TemporalExp.hh"
#include <vector>

namespace expression {

class Implication : public TemporalExp {

private:
  TemporalExp *_ant;
  TemporalExp *_con;

public:
  Implication(TemporalExp *ant, TemporalExp *con);

  virtual ~Implication();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  Trinary evaluate_ant(size_t time);

  Trinary evaluate_con(size_t time);
};
} //namespace expression
