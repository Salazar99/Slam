#include"StlInst.hh"


namespace harm{
    StlInst::StlInst(Proposition ** prop):_prop(prop){};

    Trinary StlInst::evaluate(size_t time){
        bool ret = (*_prop)->evaluate(time);
        if(ret) 
            return Trinary::T;
        else    
            return Trinary::F;
    }

};