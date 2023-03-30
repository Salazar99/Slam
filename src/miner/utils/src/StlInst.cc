#include"StlInst.hh"


namespace harm{
    StlInst::StlInst(Proposition ** prop):_prop(prop){};

    Trinary StlInst::evaluate(size_t time){
        return _prop->evaluate(time);
}

};