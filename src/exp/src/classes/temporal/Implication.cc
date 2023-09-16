#include "classes/temporal/Implication.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

Implication::Implication(TemporalExp *ant, TemporalExp *con)
    : _ant(ant), _con(con){};

Implication::~Implication(){
    delete _ant;
    delete _con;

};

Trinary Implication::evaluate(size_t time) {
  if (_ant->evaluate(time) == Trinary::T)
    return _con->evaluate(time);
  else if (_ant->evaluate(time) == Trinary::U)
    return Trinary::U;
  else
    return Trinary::T;
}

std::vector<TemporalExp *> Implication::getItems() {
  return std::vector<TemporalExp *>({_ant, _con});
}

size_t Implication::size() { return 2; }

Trinary Implication::evaluate_ant(size_t time) { return _ant->evaluate(time); }

Trinary Implication::evaluate_con(size_t time) { return _con->evaluate(time); }
void Implication::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }

}; // namespace expression
