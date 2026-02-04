#pragma once

#include "TemporalAnd.hh"
#include "TemporalExp.hh"
#include "Rectifier.hh"
#include <vector>

namespace expression {

class Implication : public TemporalExp {

private:
  TemporalExp *_ant;
  TemporalExp *_con;

public:
  Implication() {}

  Implication(TemporalExp *ant, TemporalExp *con);

  virtual ~Implication();

  virtual Trinary evaluate(size_t time) override;

  // Robustness evaluation functions
  virtual std::pair<float, float> evaluate_std_robustness(size_t time);
  virtual std::pair<float, float> evaluate_cum_robustness(size_t time);
  virtual std::pair<float, float> evaluate_tro_robustness(size_t time);


  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  Trinary evaluate_ant(size_t time);

  Trinary evaluate_con(size_t time);

  void setAnt(TemporalExp *ant) { _ant = ant; }
  void setCon(TemporalExp *con) { _con = con; }

  void acceptVisitor(ExpVisitor &vis) override;
};
} //namespace expression
