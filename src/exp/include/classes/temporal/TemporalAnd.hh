#pragma once

#include "TemporalExp.hh"

namespace expression {

class TemporalAnd : public TemporalExp {
public:
  TemporalAnd();
  TemporalAnd(TemporalExp *first);

  virtual ~TemporalAnd();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;

  virtual size_t size() override;

  void addItem(TemporalExp *prop);

  void addFront(TemporalExp *prop);

  void popItem();
  TemporalExp *popFront();

  Proposition *popLastItem();


  void removeItems();

  void acceptVisitor(ExpVisitor &vis) override;

private:
  std::vector<TemporalExp *> _items;
};

}; // namespace expression
