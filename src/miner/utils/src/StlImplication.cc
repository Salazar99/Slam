#include "StlImplication.hh"

namespace harm {

StlImplication::StlImplication( TemporalAnd * ant,
                                TemporalAnd * con)
    : _ant(ant), _con(con) {};

StlImplication::~StlImplication(){};

//!A V B
Trinary StlImplication::evaluate(size_t time) {
  if(_ant->evaluate(time) == Trinary::T)
    return _con->evaluate(time);
  else if(_ant->evaluate(time) == Trinary::U)
    return Trinary::U;
  else
    return Trinary::T;
}

std::vector<expression::Proposition *> StlImplication::getItems(){
  std::vector<expression::Proposition *> ret;
  ret = _ant->getItems();
  ret.insert(ret.end(),(_con->getItems()).begin(), (_con->getItems()).end());
  return ret;
}  

size_t StlImplication::size(){return _ant->size() + _con->size();}

Trinary StlImplication::evaluate_ant(size_t time){
  return _ant->evaluate(time);
}
  
Trinary StlImplication::evaluate_con(size_t time){
  return _con->evaluate(time);
}


}; // namespace harm
