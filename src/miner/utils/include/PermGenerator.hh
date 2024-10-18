#pragma once

#include "Location.hh"
#include "minerUtils.hh"

#include <cstdarg>
#include <deque>
#include <numeric>
#include <regex>
#include <string>
#include <unordered_map>

namespace slam {

using Matrix = std::vector<std::vector<size_t>>;
using Row = std::vector<size_t>;
/*! \class PermGenerator
    \brief Class to generate permutations of proposition for the placeholders
*/
class PermGenerator {

public:
  PermGenerator() = default;

  ~PermGenerator();

  void genPermutations(size_t antP, size_t conP, size_t antConP,Template *temp);

private:
  enum class PermOperator { Mul, Bin, Com, Ph };
  struct PermUnit {
    PermOperator _op;
    std::pair<size_t, size_t> _dim;
    std::vector<PermUnit *> _children;
  };

  bool compare(expression::TemporalExp* f1, expression::TemporalExp* f2);
  Matrix visitPermUnit(PermGenerator::PermUnit *pu);
  PermGenerator::PermUnit *
  generatePermUnit(expression::TemporalExp* templ, std::unordered_set<std::string> &foundPH);
  PermGenerator::PermUnit *generatePermUnit(expression::TemporalExp* templ);
  void printPermUnit(PermGenerator::PermUnit *pu);
  void deletePermUnit(PermGenerator::PermUnit *pu);

  size_t _cProps;
  size_t _acProps;
  size_t _aProps;
  std::unordered_map<std::string, size_t> _mPhs;
  std::unordered_map<std::string, size_t> _rphToIndex;

public:
  int **_perms = nullptr;
  std::pair<size_t, size_t> _size;
  std::unordered_map<std::string, size_t> _phToIndex;
  std::unordered_map<std::string, slam::Location> _phToLoc;
};
} // namespace slam
