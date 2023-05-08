#include "classes/temporal/TemporalInst.hh"

namespace expression {
TemporalInst::TemporalInst(expression::Proposition *prop,const std::string &name) : _prop(prop),_name(name){};

TemporalInst::~TemporalInst(){};

Trinary TemporalInst::evaluate(size_t time) {
  return _prop->evaluate(time) ? Trinary::T : Trinary::F;
}


std::vector<TemporalExp *> TemporalInst::getItems(){
    assert(0);
    messageError("Cannot call getItems on a TemporalInst");
    return std::vector<TemporalExp *>();
}

size_t TemporalInst::size(){return 1;}

}; // namespace expression
