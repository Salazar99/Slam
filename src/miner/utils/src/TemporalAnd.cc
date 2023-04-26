#include "TemporalAnd.hh"

namespace harm {

TemporalAnd::TemporalAnd(TemporalExp * first){
  _items.push_back(first);
};
TemporalAnd::TemporalAnd(){};

TemporalAnd::~TemporalAnd(){};

Trinary TemporalAnd::evaluate(size_t time) {
  //if one element is F, all AND is false
  for(auto t : _items){
    if(t->evaluate(time) == Trinary::T)
      return Trinary::F;
    else if(t->evaluate(time) == Trinary::U)
      return Trinary::U;
  }
  return Trinary::T;
}

void TemporalAnd::addItem(TemporalExp * prop){
  //first element of the and is empty, can insert prop
  _items.push_back(prop);
}

std::vector<expression::Proposition *> TemporalAnd::getItems(){
  std::vector<expression::Proposition *> ret;
    for(auto texp : _items){
      std::vector<expression::Proposition *> p = texp->getItems();
      ret.insert(ret.end(),p.begin(), p.end());
    }
  
    return ret;
  };

size_t TemporalAnd::size(){return _items.size();}

void TemporalAnd::popItem(){
  //FIXME need a popItem?
}

void TemporalAnd::removeItems(){
  //FIXME need a removeItems?
}

}; // namespace harm
