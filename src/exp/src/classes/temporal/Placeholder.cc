#include "classes/temporal/Placeholder.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

Placeholder::Placeholder(expression::Proposition *prop,const std::string &name) : _prop(prop),_name(name){};
Placeholder::~Placeholder(){};

Trinary Placeholder::evaluate(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}

std::pair<float, float> Placeholder::evaluate_std_robustness(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  /*TODO: I need to understand how the atomic propositions works to implement a robustness calculation
  Something like:
  float val_pos = Rectified::process(RectifierType::POSITIVE,_prop->evaluate_robustness(time));
  float val_neg = Rectified::process(RectifierType::NEGATIVE,_prop->evaluate_robustness(time));
  std::make_pair(val_pos,val_neg);
  */
  float val = _prop->evaluate_robustness(time);
  return {val,0.0f};
}

std::pair<float, float> Placeholder::evaluate_cum_robustness(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  /*TODO: I need to understand how the atomic propositions works to implement a robustness calculation
  Something like:
  float val_pos = Rectified::process(RectifierType::POSITIVE,_prop->evaluate_robustness(time));
  float val_neg = Rectified::process(RectifierType::NEGATIVE,_prop->evaluate_robustness(time));
  std::make_pair(val_pos,val_neg);
  */
  float val_pos = Rectifier::process(RectifierType::Positive,_prop->evaluate_robustness(time));
  float val_neg = Rectifier::process(RectifierType::Negative,_prop->evaluate_robustness(time));
  return {val_pos,val_neg};
}

std::pair<float, float> Placeholder::evaluate_tro_robustness(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  /*TODO: I need to understand how the atomic propositions works to implement a robustness calculation
  Something like:
  float val_pos = Rectifier::process(RectifierType::Positive,_prop->evaluate_robustness(time));
  float val_neg = Rectifier::process(RectifierType::Negative,_prop->evaluate_robustness(time));
  std::make_pair(val_pos,val_neg);
  */
  float val_pos = Rectifier::process(RectifierType::Positive,_prop->evaluate_robustness(time));
  float val_neg = Rectifier::process(RectifierType::Negative,_prop->evaluate_robustness(time));
  return {val_pos,val_neg};
}

std::vector<TemporalExp *> Placeholder::getItems() {
    assert(0);
    messageError("Cannot call getItems on a placeholder");
    return std::vector<TemporalExp *>();
}

size_t Placeholder::size() { return 0; }

void Placeholder::setProposition(expression::Proposition *p) { _prop = p; }

void Placeholder::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
