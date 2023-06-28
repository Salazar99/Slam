#include "classes/temporal/TemporalOr.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

TemporalOr::TemporalOr(TemporalExp *first) { _items.push_back(first); };
TemporalOr::TemporalOr(){};

TemporalOr::~TemporalOr(){

    for (auto item : _items) {
        delete item;
    }

};

Trinary TemporalOr::evaluate(size_t time) {
  //if one element is T, all OR is true
  for (auto t : _items) {
    if (t->evaluate(time) == Trinary::T)
      return Trinary::T;
    else if (t->evaluate(time) == Trinary::U)
      return Trinary::U;
  }

  return Trinary::F;
}

void TemporalOr::addItem(TemporalExp *prop) {
  _items.push_back(prop);
}

void TemporalOr::addFront(TemporalExp *prop) {
    _items.insert(_items.begin(), prop);
}
TemporalExp* TemporalOr::popFront() {
    auto item = _items.front();
    _items.erase(_items.begin());
    return item;
}

std::vector<TemporalExp *> TemporalOr::getItems() { return _items; };


size_t TemporalOr::size() { return _items.size(); }

void TemporalOr::popItem() { _items.pop_back(); }

Proposition * TemporalOr::popLastItem(){
  auto inst = dynamic_cast<TemporalInst *>(_items.back());
  auto prop = inst->getProposition();
  _items.pop_back();
  return prop;
}


void TemporalOr::removeItems() { _items.clear(); }

void TemporalOr::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
