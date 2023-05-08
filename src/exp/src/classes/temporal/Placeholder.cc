#include "classes/temporal/Placeholder.hh"

namespace expression {

Placeholder::Placeholder(expression::Proposition *prop,const std::string &name) : _prop(prop),_name(name){};
Placeholder::~Placeholder(){};

Trinary Placeholder::evaluate(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}

std::vector<TemporalExp *> Placeholder::getItems() {
    assert(0);
    messageError("Cannot call getItems on a placeholder");
    return std::vector<TemporalExp *>();
}

size_t Placeholder::size() { return 0; }

void Placeholder::setProposition(expression::Proposition *p) { _prop = p; }
}; // namespace expression
