#pragma once

#include "TemporalExp.hh"
#include <vector>

namespace harm {

class StlImplication : public TemporalExp {

private:
  std::vector<TemporalExp *> _ant;
  std::vector<TemporalExp *> _con;

public:
  StlImplication(const std::vector<TemporalExp *> &ant,
                 const std::vector<TemporalExp *> &con);

  virtual ~StlImplication();

  virtual Trinary evaluate(size_t time) override;
};
} //namespace harm
