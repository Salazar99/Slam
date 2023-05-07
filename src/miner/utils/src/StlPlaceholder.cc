#include "StlPlaceholder.hh"

namespace harm {

StlPlaceholder::StlPlaceholder(expression::Proposition *prop,const std::string &name) : _prop(prop),_name(name){};
StlPlaceholder::~StlPlaceholder(){};

Trinary StlPlaceholder::evaluate(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}

std::vector<TemporalExp *> StlPlaceholder::getItems() {
    assert(0);
    messageError("Cannot call getItems on a placeholder");
    return std::vector<TemporalExp *>();
}

size_t StlPlaceholder::size() { return 0; }

void StlPlaceholder::setProposition(expression::Proposition *p) { _prop = p; }
}; // namespace harm
