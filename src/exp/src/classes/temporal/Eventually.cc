#include "classes/temporal/Eventually.hh"
#include "visitors/ExpVisitor.hh"
#include "Trace.hh"
#include <limits>
#include <algorithm>

namespace expression {

Eventually::Eventually(TemporalExp *operand,
                             const std::pair<size_t, size_t> &interval, slam::Trace *trace)
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

    if (_operand->evaluate(i) == Trinary::T) {
      return Trinary::T;
    }
  }
  return Trinary::F;
}

std::pair<float, float> Eventually::evaluate_std_robustness(size_t time){
  if (time + _interval.first > _trace->getLength()) {
    return {0.0f,0.0f};
  }
  std::pair<float, float> rob = {0.0f,0.0f};
  //rob(FA) = max(t in I) rob(A)
  for (size_t i = time + _interval.first; i <= time + _interval.second; i++) {
    std::pair<float, float> curr_rob = _operand->evaluate_std_robustness(i);  
    rob.first = std::max(curr_rob.first, rob.first);
  }
  rob.first = (rob.first == 0.0f || rob.first == -0.0f) ? 0.0f : rob.first;
  return rob;
}

std::pair<float, float> Eventually::evaluate_cum_robustness(size_t time){
  if (time + _interval.first > _trace->getLength()) {
    return {0.0f,0.0f};
  }
  std::pair<float, float> rob = {0.0f,0.0f};
  //rob(FA) = max(t in I) rob(A)
  for (size_t i = time + _interval.first; i <= time + _interval.second; i++) {
    std::pair<float, float> curr_rob = _operand->evaluate_cum_robustness(i);  
    rob.first = Rectifier::process(RectifierType::Positive, (curr_rob.first + rob.first));
    rob.second = Rectifier::process(RectifierType::Negative, (curr_rob.second + rob.second));
  }
  return rob;
}

std::pair<float, float> Eventually::evaluate_tro_robustness(size_t time){
  if (time + _interval.first > _trace->getLength()) {
    return {0.0f,0.0f};
  }
  std::pair<float, float> rob = {0.0f,0.0f};
  //rob(FA) = max(t in I) rob(A)
  for (size_t i = time + _interval.first; i <= time + _interval.second; i++) {
    std::pair<float, float> curr_rob = _operand->evaluate_tro_robustness(i);  
    rob.first = Rectifier::process(RectifierType::Positive, (curr_rob.first + rob.first));
    rob.second = Rectifier::process(RectifierType::Negative, (curr_rob.second + rob.second));
  }
  return rob;
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
