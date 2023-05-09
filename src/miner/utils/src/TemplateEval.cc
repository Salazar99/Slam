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

namespace harm {

Trinary Template::evaluate(size_t time) { return _impl->evaluate(time); }

Trinary Template::evaluate_ant(size_t time) {
  return _impl->evaluate_ant(time);
}

Trinary Template::evaluate_con(size_t time) {
  return _impl->evaluate_con(time);
}

bool Template::assHoldsOnTrace(harm::Location update) {

  switch (update) {
  case harm::Location::Ant:
    setCacheAntFalse();
    break;
  case harm::Location::Con:
    setCacheConFalse();
    break;
  case harm::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case harm::Location::None:
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
bool Template::assHoldsOnTraceOffset(harm::Location update) {

  switch (update) {
  case harm::Location::Ant:
    setCacheAntFalse();
    break;
  case harm::Location::Con:
    setCacheConFalse();
    break;
  case harm::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case harm::Location::None:
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
bool Template::isVacuous(harm::Location update) {
  switch (update) {
  case harm::Location::Ant:
    setCacheAntFalse();
    break;
  case harm::Location::Con:
    setCacheConFalse();
    break;
  case harm::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case harm::Location::None:
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
bool Template::isVacuousOffset(harm::Location update) {
  switch (update) {
  case harm::Location::Ant:
    setCacheAntFalse();
    break;
  case harm::Location::Con:
    setCacheConFalse();
    break;
  case harm::Location::AntCon:
    setCacheAntFalse();
    setCacheConFalse();
    break;
  case harm::Location::None:
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
} // namespace harm
