#include "StlImplication.hh"

namespace harm {

StlImplication::StlImplication(TemporalExp *ant, TemporalExp *con)
    : _ant(ant), _con(con){};

StlImplication::~StlImplication(){};

Trinary StlImplication::evaluate(size_t time) {
  if (_ant->evaluate(time) == Trinary::T)
    return _con->evaluate(time);
  else if (_ant->evaluate(time) == Trinary::U)
    return Trinary::U;
  else
    return Trinary::T;
}

std::vector<TemporalExp *> StlImplication::getItems() {
  return std::vector<TemporalExp *>({_ant, _con});
}

size_t StlImplication::size() { return 2; }

Trinary StlImplication::evaluate_ant(size_t time) {
  return _ant->evaluate(time);
}

Trinary StlImplication::evaluate_con(size_t time) {
  return _con->evaluate(time);
}

}; // namespace harm
