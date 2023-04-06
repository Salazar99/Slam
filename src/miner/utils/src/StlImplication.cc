#include "StlImplication.hh"

namespace harm {

StlImplication::StlImplication(const std::vector<TemporalExp *> &ant,
                               const std::vector<TemporalExp *> &con)
    : _ant(ant), _con(con) {}

StlImplication::~StlImplication(){};

Trinary StlImplication::evaluate(size_t time) {
  for (auto p : _ant) {
    //A subformula of the _ant is F -> the entire antecedent is F -> implication is true regardless of the con
    if (p->evaluate(time) == Trinary::F)
      return Trinary::T;
  }

  //if we are here, ant is T
  for (auto p : _con) {
    //ant = T and con = F -> impl is false
    if (p->evaluate(time) == Trinary::F)
      return Trinary::F;
  }
  //ant is T and con is T -> impl is T
  return Trinary::T;
}


Trinary StlImplication::evaluate_ant(size_t time){
  for (auto p : _ant) {
    //A subformula of the _ant is F, the entire _ant is F
    if (p->evaluate(time) == Trinary::F)
      return Trinary::F;
  }
  //all _subformulas are T, then all _ant is T
  return Trinary::T;
}
  
Trinary StlImplication::evaluate_con(size_t time){
  for (auto p : _con) {
    //a subformula of _con is F, then all _con is F
    if (p->evaluate(time) == Trinary::F)
      return Trinary::F;
  }
  //al subformulas are T, then _con is T
  return Trinary::T;
}


}; // namespace harm
