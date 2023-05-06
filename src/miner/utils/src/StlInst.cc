#include "StlInst.hh"

namespace harm {
StlInst::StlInst(expression::Proposition *prop) : _prop(prop){};

StlInst::~StlInst(){};

Trinary StlInst::evaluate(size_t time) {
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}


std::vector<expression::Proposition *> StlInst::getItems(){
  std::vector<expression::Proposition *> ret;
  ret.push_back(_prop);
  return ret;
}

size_t StlInst::size(){return 1;}

}; // namespace harm
