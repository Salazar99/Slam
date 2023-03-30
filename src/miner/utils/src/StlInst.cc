#include "StlInst.hh"

namespace harm {
StlInst::StlInst(expression::Proposition **prop) : _prop(prop){};

StlInst::~StlInst(){};

Trinary StlInst::evaluate(size_t time) {
  return (*_prop)->evaluate(time) ? Trinary::T : Trinary::F;
}

}; // namespace harm
