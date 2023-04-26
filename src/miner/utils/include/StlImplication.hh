#pragma once

#include "TemporalExp.hh"
#include "TemporalAnd.hh"
#include <vector>

namespace harm {

class StlImplication : public TemporalExp {

private:
  TemporalAnd * _ant;
  TemporalAnd * _con;

public:
  StlImplication( TemporalAnd * ant,
                  TemporalAnd * con);

  virtual ~StlImplication();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<expression::Proposition *> getItems() override;

  virtual size_t size() override;

  Trinary evaluate_ant(size_t time);
  
  Trinary evaluate_con(size_t time);
};
} //namespace harm
