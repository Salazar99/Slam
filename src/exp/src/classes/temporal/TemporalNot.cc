#include "classes/temporal/TemporalNot.hh"
#include "visitors/ExpVisitor.hh"
#include <limits>
#include <algorithm>

namespace expression {

TemporalNot::TemporalNot(TemporalExp *item) : _item(item){};

TemporalNot::~TemporalNot() { delete _item; };

Trinary TemporalNot::evaluate(size_t time) { return !_item->evaluate(time); }

std::pair<float, float> TemporalNot::evaluate_std_robustness(size_t time) {
  //rob(!A) = -rob(A)
  float val = -_item->evaluate_std_robustness(time).first;
  val = (val == 0.0f || val == -0.0f) ? 0.0f : val;
  return { val,
           0.0f };
}

std::pair<float, float> TemporalNot::evaluate_cum_robustness(size_t time) {
  std::pair<float, float> rob = {std::numeric_limits<float>::infinity(),
                                0.0f};
  //rob_pos(!A) = -rob_neg(A)
  //rob_neg(!A) = -rob_pos(A)
  return { Rectifier::process(RectifierType::Positive,-_item->evaluate_cum_robustness(time).second),
           Rectifier::process(RectifierType::Negative,-_item->evaluate_cum_robustness(time).first) };
}

std::pair<float, float> TemporalNot::evaluate_tro_robustness(size_t time) {
  std::pair<float, float> rob = {std::numeric_limits<float>::infinity(),
                                0.0f};
  //rob_pos(!A) = -rob_neg(A)
  //rob_neg(!A) = -rob_pos(A)
  return { Rectifier::process(RectifierType::Positive,-_item->evaluate_cum_robustness(time).second),
           Rectifier::process(RectifierType::Negative,-_item->evaluate_cum_robustness(time).first) };
}

std::vector<TemporalExp *> TemporalNot::getItems() {
  return std::vector<TemporalExp *>({_item});
};

TemporalExp *TemporalNot::getItem() { return _item; };

size_t TemporalNot::size() { return 1; }

void TemporalNot::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
