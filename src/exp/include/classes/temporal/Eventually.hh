#pragma once

#include "TemporalExp.hh"

namespace harm {
class Trace;
}

namespace expression {

class Eventually : public TemporalExp {
public:
  Eventually(TemporalExp *operand, const std::pair<size_t, size_t> &interval,
             harm::Trace *trace);

  Eventually(const Eventually &original) {
      _trace=original._trace;
      _interval=original._interval;
      _operand=original._operand;
  }

  Eventually() {}

  virtual ~Eventually();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  TemporalExp *getOperand() { return _operand; }
  void setOperand(TemporalExp *op) { _operand = op; }

  virtual size_t size() override;

  void setInterval(const std::pair<size_t, size_t> &intv);

  std::pair<size_t, size_t> getInterval();

  void acceptVisitor(ExpVisitor &vis) override;

private:
  TemporalExp *_operand;
  std::pair<size_t, size_t> _interval;
  harm::Trace *_trace;
};

}; // namespace expression
