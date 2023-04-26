#pragma once

#include "Trinary.hh"
#include "exp.hh"

namespace harm {
class TemporalExp {
public:
  virtual ~TemporalExp() {}

  virtual Trinary evaluate(size_t time) = 0;

  virtual std::vector<expression::Proposition *> getItems() = 0;

  virtual size_t size() = 0;
};
}; // namespace harm
