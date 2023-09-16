#include "classes/temporal/TemporalNot.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

TemporalNot::TemporalNot(TemporalExp *item) : _item(item){};

TemporalNot::~TemporalNot() { delete _item; };

Trinary TemporalNot::evaluate(size_t time) { return !_item->evaluate(time); }

std::vector<TemporalExp *> TemporalNot::getItems() {
  return std::vector<TemporalExp *>({_item});
};

TemporalExp *TemporalNot::getItem() { return _item; };

size_t TemporalNot::size() { return 1; }

void TemporalNot::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
