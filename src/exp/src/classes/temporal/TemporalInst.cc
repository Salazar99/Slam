#include "classes/temporal/TemporalInst.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {
TemporalInst::TemporalInst(expression::Proposition *prop,
                           const std::string &name)
    : _prop(prop), _name(name){};

TemporalInst::~TemporalInst(){};

Trinary TemporalInst::evaluate(size_t time) {
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}

std::pair<float, float> TemporalInst::evaluate_std_robustness(size_t time){return {_prop->evaluate_robustness(time),0.0f};}

std::pair<float, float> TemporalInst::evaluate_cum_robustness(size_t time){return {Rectifier::process(RectifierType::Positive, _prop->evaluate_robustness(time)), Rectifier::process(RectifierType::Negative, _prop->evaluate_robustness(time))};}

std::pair<float, float> TemporalInst::evaluate_tro_robustness(size_t time){return {Rectifier::process(RectifierType::Positive, _prop->evaluate_robustness(time)), Rectifier::process(RectifierType::Negative, _prop->evaluate_robustness(time))};}

std::vector<TemporalExp *> TemporalInst::getItems() {
  assert(0);
  messageError("Cannot call getItems on a TemporalInst");
  return std::vector<TemporalExp *>();
}

size_t TemporalInst::size() { return 1; }

void TemporalInst::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
