#include "StlEventually.hh"

namespace harm {

StlEventually::StlEventually(TemporalExp *operand,
                             std::pair<size_t , size_t > *interval, Trace * trace)
    : _operand(operand), _interval(interval), _trace(trace){};

StlEventually::~StlEventually() {}

Trinary StlEventually::evaluate(size_t time) {

  if (time + _interval->first > _trace->getLength()) {
    return Trinary::U;
  }

  for (size_t i = time + _interval->first; i <= time + _interval->second;
       i++) {

    if (i == _trace->getLength()) {
      return Trinary::U;
    }

    if (_operand->evaluate(time) == Trinary::T) {
      return Trinary::T;
    }
  }
  return Trinary::F;
}

std::vector<expression::Proposition *> StlEventually::getItems(){
  return _operand->getItems();
}

size_t StlEventually::size(){return 1;}

void StlEventually::setInterval(std::pair<size_t, size_t> * intv) {
  _interval = intv;
}

std::pair<size_t,size_t> * StlEventually::getInterval(){return _interval;}

}; // namespace harm
