#include "classes/temporal/Globally.hh"
#include "visitors/ExpVisitor.hh"
#include "Trace.hh"

namespace expression {

Globally::Globally(TemporalExp *operand,
                             const std::pair<size_t, size_t> &interval, const std::pair<size_t, size_t> &shift, slam::Trace *trace)
    : _operand(operand), _interval(interval), _shift(shift), _trace(trace){};

Globally::~Globally() {
    delete _operand;
}

Trinary Globally::evaluate(size_t time) {
  // If the interval goes beyond the trace, we cannot evaluate it, so we return Unknown
  if (time + _interval.first > _trace->getLength()) {
    return Trinary::U;
  }

  for (size_t i = time + _interval.first; i <= time + _interval.second; i++) {
    // If we are at the end of the trace, we cannot evaluate it, so we return Unknown
    if (i == _trace->getLength()) {
      return Trinary::U;
    }
    // If the operand is false at any point in the interval, the whole formula is false
    if (_operand->evaluate(i) == Trinary::F) {
      return Trinary::F;
    }
  }
  // If the operand is true at all points in the interval, the whole formula is true
  return Trinary::T;
}

std::vector<TemporalExp *> Globally::getItems() {
  return std::vector<TemporalExp *>({_operand});
}

size_t Globally::size() { return 1; }

void Globally::setInterval(const std::pair<size_t, size_t> &intv) {
  _interval = intv;
}

std::pair<size_t, size_t> Globally::getInterval() { return _interval; }

std::pair<size_t, size_t> Globally::getShift() { return _shift; }

void Globally::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }

}; // namespace expression
