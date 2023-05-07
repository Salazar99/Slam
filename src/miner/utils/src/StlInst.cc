#include "StlInst.hh"

namespace harm {
StlInst::StlInst(expression::Proposition *prop,const std::string &name) : _prop(prop),_name(name){};

StlInst::~StlInst(){};

Trinary StlInst::evaluate(size_t time) {
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}


std::vector<TemporalExp *> StlInst::getItems(){
    assert(0);
    messageError("Cannot call getItems on a StlInst");
    return std::vector<TemporalExp *>();
}

size_t StlInst::size(){return 1;}

}; // namespace harm
