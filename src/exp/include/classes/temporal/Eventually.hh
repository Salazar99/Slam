#pragma once

#include "TemporalExp.hh"

namespace harm {
class Trace;
}

namespace expression {

class Eventually : public TemporalExp {
public:
  Eventually(TemporalExp *operand, std::pair<size_t, size_t> *interval,
             harm::Trace *trace);

  virtual ~Eventually();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  TemporalExp *getOperand() { return _operand; }

  virtual size_t size() override;

  void setInterval(std::pair<size_t, size_t> *intv);

  std::pair<size_t, size_t> *getInterval();

  void acceptVisitor(ExpVisitor &vis) override;

private:
  TemporalExp *_operand;
  std::pair<size_t, size_t> *_interval;
  harm::Trace *_trace;
};

}; // namespace expression
