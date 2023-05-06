#pragma once

#include "TemporalExp.hh"

namespace harm {

class TemporalAnd : public TemporalExp {
public:
  TemporalAnd();
  TemporalAnd(TemporalExp *first);

  virtual ~TemporalAnd();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<expression::Proposition *> getItems() override;

  std::vector<TemporalExp *> getTempItems();

  virtual size_t size() override;

  void addItem(TemporalExp * prop);

  void popItem();

  void removeItems();

private:
  std::vector<TemporalExp *> _items;
 
};

}; // namespace harm
