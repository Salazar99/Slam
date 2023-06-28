#pragma once

#include "TemporalExp.hh"

namespace expression {

class TemporalNot : public TemporalExp {
public:
  TemporalNot(TemporalExp *item);

  virtual ~TemporalNot();

  virtual Trinary evaluate(size_t time) override;

  virtual std::vector<TemporalExp *> getItems() override;
  virtual size_t size() override;

  TemporalExp * getItem() ;


  void addItem(TemporalExp *prop);


  void acceptVisitor(ExpVisitor &vis) override;

private:
  TemporalExp * _item;
};

}; // namespace expression
