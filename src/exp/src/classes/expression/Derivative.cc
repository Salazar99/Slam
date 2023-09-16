#include "classes/atom/Atom.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

template <>
void Derivative<LogicExpression, LogicExpression>::acceptVisitor(
    ExpVisitor &vis) {
  vis.visit(*this);
}
template <>
void Derivative<NumericExpression, NumericExpression>::acceptVisitor(
    ExpVisitor &vis) {
  vis.visit(*this);
}

template <>
ULogic Derivative<LogicExpression, LogicExpression>::evaluate(size_t time) {
  if (time + _shift >= _max_time) {
    return _e->evaluate(time);
  }

  return _e->evaluate(time + _shift) - _e->evaluate(time);
}

template <>
Numeric
Derivative<NumericExpression, NumericExpression>::evaluate(size_t time) {
  if (time + _shift >= _max_time) {
    return _e->evaluate(time);
  }

  return _e->evaluate(time + _shift) - _e->evaluate(time);
}

} // namespace expression
