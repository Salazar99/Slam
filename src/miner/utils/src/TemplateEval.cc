#include "Semaphore.hh"
#include "Template.hh"
#include "colors.hh"
#include "globals.hh"
#include "message.hh"
#include "minerUtils.hh"

#include <algorithm>
#include <math.h>
#include <mutex>
#include <sstream>
#include <sys/wait.h>
#include <thread>
#include <utility>

namespace slam {

Trinary Template::evaluate(size_t time) { return _impl->evaluate(time); }

Trinary Template::evaluate_ant(size_t time) {
  return _impl->evaluate_ant(time);
}

Trinary Template::evaluate_con(size_t time) {
  return _impl->evaluate_con(time);
}

float Template::evaluate_robustness(R_types robustness, size_t time){
  switch(robustness){
    case R_types::STANDARD:
      return _impl->evaluate_std_robustness(time).first;
    case R_types::CUMULATIVEPOS:
      return _impl->evaluate_cum_robustness(time).first;
    case R_types::CUMULATIVENEG:
      return _impl->evaluate_cum_robustness(time).second;
    case R_types::TROPICALPOS:
      return _impl->evaluate_tro_robustness(time).first;
    case R_types::TROPICALNEG:
      return _impl->evaluate_tro_robustness(time).second;
    default:
      messageError("Robustness type not supported");
      return NAN;
  }
}
bool Template::assHoldsOnTrace(slam::Location update) {
  switch (update) {
  case slam::Location::Ant:
    setCacheAntFalse();
    break;
  case slam::Location::Con:
    setCacheConFalse();
    break;
  case slam::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case slam::Location::None:
    break;
  default:
    messageError("Illegal use of Location operator");
    break;
  }

  for (size_t i = 0; i < _max_length; i++) {
    if (evaluate(i) == Trinary::F) {
      return false;
    }
  }
  return true;
}

bool Template::assHoldsOnTraceOffset(slam::Location update) {

  switch (update) {
  case slam::Location::Ant:
    setCacheAntFalse();
    break;
  case slam::Location::Con:
    setCacheConFalse();
    break;
  case slam::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case slam::Location::None:
    break;
  default:
    messageError("Illegal use of Location operator");
    break;
  }

  for (size_t i = 0; i < _max_length; i++) {
    //FIXME: evaluateOffset undefined
//    if (evaluateOffset(i) == Trinary::F) {
//      return false;
//    }
  }
  return true;
}

bool Template::isVacuous(slam::Location update) {
  switch (update) {
  case slam::Location::Ant:
    setCacheAntFalse();
    break;
  case slam::Location::Con:
    setCacheConFalse();
    break;
  case slam::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case slam::Location::None:
    break;
  default:
    messageError("Illegal use of Location operator");
    break;
  }

  //ant at least true once
  for (size_t i = 0; i < _max_length; i++) {
    if (evaluate_ant(i) == Trinary::T && evaluate(i) == Trinary::T) {
      goto nextCondition;
    }
  }
  return true;

nextCondition:;
  //con at least false once
  for (size_t i = 0; i < _max_length; i++) {
    if (evaluate_con(i) == Trinary::F) {
    return false;
    }
  }
  return true;
}
bool Template::isVacuousOffset(slam::Location update) {
  switch (update) {
  case slam::Location::Ant:
    setCacheAntFalse();
    break;
  case slam::Location::Con:
    setCacheConFalse();
    break;
  case slam::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case slam::Location::None:
    break;
  default:
    messageError("Illegal use of Location operator");
    break;
  }

  //ant at least true once
  for (size_t i = 0; i < _max_length; i++) {
    if (evaluate_ant(i) == Trinary::T && evaluate(i) == Trinary::F) {
      goto nextCondition;
    }
  }
  return true;

nextCondition:;
  //cons at least false once
  for (size_t i = 0; i < _max_length; i++) {
    if (evaluate_con(i) == Trinary::T) {
      return false;
    }
  }
  return true;
}
} // namespace slam
