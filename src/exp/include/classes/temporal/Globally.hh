#pragma once

#include "TemporalExp.hh"

namespace slam {
class Trace;
}

namespace expression {

// Class representing the globally operator in temporal logic. INSIDE THE ASSERTION, not in front
class Globally : public TemporalExp {
public:
  Globally(TemporalExp *operand, const std::pair<size_t, size_t> &interval, const std::pair<size_t, size_t> &shift,
             slam::Trace *trace);

  Globally(const Globally &original) {
      _trace=original._trace;
      _interval=original._interval;
      _shift=original._shift;
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

  std::pair<size_t, size_t> getShift();


  void acceptVisitor(ExpVisitor &vis) override;

private:
  TemporalExp *_operand;
  //temporal interval of the operator
  std::pair<size_t, size_t> _interval;
  //shift applied to the already instantiated interval 
  std::pair<size_t, size_t> _shift;
  slam::Trace *_trace;
};

}; // namespace expression
