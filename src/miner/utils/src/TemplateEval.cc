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

struct LinkedEntry {
  LinkedEntry(size_t id) : _id(id), _nextEntry(nullptr) {
    // not todo
  }
  LinkedEntry() : _id(-1), _nextEntry(nullptr) {}
  size_t _id;
  LinkedEntry *_nextEntry;
};
struct LinkedInterface {
  LinkedInterface() : _head(nullptr), _tail(nullptr) {}

public:
  LinkedEntry *_head;
  LinkedEntry *_tail;
};

#define printl 0
inline void printList(size_t n_size, size_t c_size,
                      std::vector<std::pair<size_t, LinkedInterface>> &curr,
                      std::vector<std::pair<size_t, LinkedInterface>> &next,
                      const std::string msg) {
  std::cout << msg << "\n";
  std::cout << "Next:"
            << "\n";
  for (size_t i = 0; i < n_size; i++) {
    if (next[i].second._head == nullptr) {
      continue;
    }
    LinkedEntry *it = next[i].second._head;
    std::cout << "State " << next[i].first << "\n\t";
    while (it != nullptr) {
      std::cout << it->_id << " ";
      it = it->_nextEntry;
    }
    std::cout << "\n";
  }
  std::cout << "\n";
  std::cout << "Curr:"
            << "\n";
  for (size_t i = 0; i < c_size; i++) {
    if (curr[i].second._head == nullptr) {
      continue;
    }
    LinkedEntry *it = curr[i].second._head;
    std::cout << "State " << curr[i].first << "\n\t";
    while (it != nullptr) {
      std::cout << it->_id << " ";
      it = it->_nextEntry;
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}
template <bool Dynamic>
void Template::joinData(Trinary *cachedValues, Range traceRange,
                        const Range &threadsRange) {
  size_t threadIndex = threadsRange._start;
  size_t pad = traceRange._length / threadsRange._length;
  for (size_t timeIndex = traceRange._start;
       timeIndex < traceRange._start + traceRange._length; timeIndex++) {

    // increment index unless it is already the last thread
    threadIndex =
        timeIndex == (traceRange._start +
                      ((threadIndex - threadsRange._start + 1) * pad)) &&
                (threadIndex != threadsRange._start + threadsRange._length - 1)
            ? threadIndex + 1
            : threadIndex;

    cachedValues[timeIndex] = _cachedValuesP[threadIndex][timeIndex];
    if constexpr (Dynamic) {
      _dynamicShiftCachedValues[timeIndex] =
          _cachedDynShiftsP[threadIndex][timeIndex];
    }
  }
}

Trinary Template::evaluate(size_t time) { return _impl->evaluate(time); }

Trinary Template::evaluate_ant(size_t time){
  return _impl->evaluate_ant(time);
}

Trinary Template::evaluate_con(size_t time){
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
    //if (evaluateOffset(i) == Trinary::F) {
    //  return false;
    //}
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
        //FIXME
    if (/*evaluate_ant(i) == Trinary::T &&*/ evaluate(i) == Trinary::T) {
      goto nextCondition;
    }
  }
  return true;

nextCondition:;
  //con at least false once
  //FIXME: evaluate_con is undefined
  for (size_t i = 0; i < _max_length; i++) {
//    if (evaluate_con(i) == Trinary::F) {
      return false;
//    }
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
  //FIXME: evaluate_ant is undefined
  for (size_t i = 0; i < _max_length; i++) {
    //    if (evaluate_ant(i) == Trinary::T && evaluate(i) == Trinary::F) {
    goto nextCondition;
  }
  //  }
  return true;

nextCondition:;
  //cons at least false once
  for (size_t i = 0; i < _max_length; i++) {
        //FIXME
//    if (evaluate_con(i) == Trinary::T) {
//      return false;
//    }
  }
  return true;
}
} // namespace harm
