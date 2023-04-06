#include "StlEventually.hh"

namespace harm {

StlEventually::StlEventually(TemporalExp *operand, std::pair<size_t ** , size_t **> interval) : _operand(operand),_interval(interval){};

StlEventually::~StlEventually() {}

Trinary StlEventually::evaluate(size_t time) {
  if (time < **(_interval.first))
    return Trinary::F;
  else if (time > **(_interval.second))
    return Trinary::U;
  else
    return _operand->evaluate(time);
}

void StlEventually::setInterval(std::pair<size_t **, size_t **> intv) {
  _interval = intv;
}

}; // namespace harm
