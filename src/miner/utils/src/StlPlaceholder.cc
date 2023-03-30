#include "StlPlaceholder.hh"

namespace harm {

StlPlaceholder::StlPlaceholder(expression::Proposition **prop) : _prop(prop){};
StlPlaceholder::~StlPlaceholder(){};

Trinary StlPlaceholder::evaluate(size_t time) {
  return (*_prop)->evaluate(time) ? Trinary::T : Trinary::F;
}

}; // namespace harm
