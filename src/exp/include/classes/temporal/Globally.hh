#pragma once

#include "TemporalExp.hh"

namespace slam {
class Trace;
}

namespace expression {

// Class representing the globally operator in temporal logic. INSIDE THE ASSERTION, not in front
class Globally : public TemporalExp {
public:
  Globally(TemporalExp *operand, const std::pair<size_t, size_t> &interval,
             slam::Trace *trace);

  Globally(const Globally &original) {
      _trace=original._trace;
      _interval=original._interval;
      _operand=original._operand;
  }

  Globally() {}

  virtual ~Globally();

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
  slam::Trace *_trace;
};

}; // namespace expression
