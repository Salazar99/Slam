#include"StlPlaceholder.hh"

namespace harm{

StlPlaceholder::StlPlacegolder(Proposition ** prop): _prop(prop){};

Trinary StlPlaceholder::evaluate(size_t time){
    return _prop->evaluate(time);
}

};