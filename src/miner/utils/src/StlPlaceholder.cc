#include "StlPlaceholder.hh"

namespace harm {

StlPlaceholder::StlPlaceholder(expression::Proposition *prop) : _prop(prop){};
StlPlaceholder::~StlPlaceholder(){};

Trinary StlPlaceholder::evaluate(size_t time) {
  messageErrorIf(_prop == nullptr, "Placeholder is empty");
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}

std::vector<expression::Proposition *> StlPlaceholder::getItems() {
  std::vector<expression::Proposition *> ret;
  ret.push_back(_prop);
  return ret;
}

size_t StlPlaceholder::size() { return 1; }

void StlPlaceholder::setProposition(expression::Proposition *p) { _prop = p; }
}; // namespace harm
