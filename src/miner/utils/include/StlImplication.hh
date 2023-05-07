#pragma once

#include "TemporalAnd.hh"
#include "TemporalExp.hh"
#include <vector>

namespace harm {

class StlImplication : public TemporalExp {

private:
  TemporalExp *_ant;
  TemporalExp *_con;

public:
  StlImplication(TemporalExp *ant, TemporalExp *con);

  virtual ~StlImplication();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  Trinary evaluate_ant(size_t time);

  Trinary evaluate_con(size_t time);
};
} //namespace harm
