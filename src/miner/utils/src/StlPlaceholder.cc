#include"StlPlaceholder.hh"

namespace harm{

StlPlaceholder::StlPlaceholder(Proposition ** prop): _prop(prop){};

Trinary StlPlaceholder::evaluate(size_t time){
    bool ret = (*_prop)->evaluate(time);
    if(ret) 
        return Trinary::T;
    else    
        return Trinary::F;
}

};