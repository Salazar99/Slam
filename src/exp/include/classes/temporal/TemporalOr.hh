#pragma once

#include "TemporalExp.hh"

namespace expression {

class TemporalOr : public TemporalExp {

public:

  TemporalOr();
  TemporalOr(TemporalExp *first);

  virtual ~TemporalOr();

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
