#include "classes/temporal/Implication.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

Implication::Implication(TemporalExp *ant, TemporalExp *con)
    : _ant(ant), _con(con){};

Implication::~Implication(){
    delete _ant;
    delete _con;

};

Trinary Implication::evaluate(size_t time) {
  if (_ant->evaluate(time) == Trinary::T)
    return _con->evaluate(time);
  else if (_ant->evaluate(time) == Trinary::U)
    return Trinary::U;
  else
    return Trinary::T;
}

std::pair<float, float> Implication::evaluate_std_robustness(size_t time) {
  std::pair<float, float> ant_rob = _ant->evaluate_std_robustness(time);
  std::pair<float, float> con_rob = _con->evaluate_std_robustness(time);
  float rob = (std::max(-ant_rob.first, con_rob.first));
  return {rob, 0};
}

std::pair<float, float> Implication::evaluate_cum_robustness(size_t time) {
  std::pair<float, float> ant_rob = _ant->evaluate_cum_robustness(time);
  std::pair<float, float> con_rob = _con->evaluate_cum_robustness(time);
  //rob_pos(!A V B) = max(rob_pos(!A),rob_pos(B)) = max(-rob_neg(A),rob_pos(B))  
  float rob_pos = Rectifier::process(RectifierType::Positive, std::max(-ant_rob.second, con_rob.first));
  
  //rob_neg(!A V B) = max(rob_neg(!A),rob_neg(B)) = max(-rob_pos(A),rob_neg(B))  
  float rob_neg = Rectifier::process(RectifierType::Negative, std::max(-ant_rob.first, con_rob.second));
  
  return {rob_pos, rob_neg};
}

std::pair<float, float> Implication::evaluate_tro_robustness(size_t time) {
  std::pair<float, float> ant_rob = _ant->evaluate_tro_robustness(time);
  std::pair<float, float> con_rob = _con->evaluate_tro_robustness(time);

  //rob_pos(!A V B) = +(rob_pos(!A),rob_pos(B)) = +(-rob_neg(A),rob_pos(B))  
  float rob_pos = Rectifier::process(RectifierType::Positive, (-ant_rob.second + con_rob.first));
  
  //rob_neg(!A V B) = +(rob_neg(!A),rob_neg(B)) = +(-rob_pos(A),rob_neg(B))  
  float rob_neg = Rectifier::process(RectifierType::Negative, (-ant_rob.first + con_rob.second));
  
  return {rob_pos, rob_neg};

}


std::vector<TemporalExp *> Implication::getItems() {
  return std::vector<TemporalExp *>({_ant, _con});
}

size_t Implication::size() { return 2; }

Trinary Implication::evaluate_ant(size_t time) { return _ant->evaluate(time); }

Trinary Implication::evaluate_con(size_t time) { return _con->evaluate(time); }
void Implication::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }

}; // namespace expression
