#include "classes/temporal/Eventually.hh"
#include "visitors/ExpVisitor.hh"
#include "Trace.hh"

namespace expression {

Eventually::Eventually(TemporalExp *operand,
                             const std::pair<size_t, size_t> &interval, harm::Trace *trace)
    : _operand(operand), _interval(interval), _trace(trace){};

Eventually::~Eventually() {
    delete _operand;
}

Trinary Eventually::evaluate(size_t time) {

  if (time + _interval.first > _trace->getLength()) {
    return Trinary::U;
  }

  for (size_t i = time + _interval.first; i <= time + _interval.second; i++) {

    if (i == _trace->getLength()) {
      return Trinary::U;
    }

    if (_operand->evaluate(time) == Trinary::T) {
      return Trinary::T;
    }
  }
  return Trinary::F;
}

std::vector<TemporalExp *> Eventually::getItems() {
  return std::vector<TemporalExp *>({_operand});
}

size_t Eventually::size() { return 1; }

void Eventually::setInterval(const std::pair<size_t, size_t> &intv) {
  _interval = intv;
}

std::pair<size_t, size_t> Eventually::getInterval() { return _interval; }
void Eventually::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }

}; // namespace expression
