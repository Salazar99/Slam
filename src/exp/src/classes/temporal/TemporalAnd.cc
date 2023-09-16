#include "classes/temporal/TemporalAnd.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

TemporalAnd::TemporalAnd(TemporalExp *first) { _items.push_back(first); };
TemporalAnd::TemporalAnd(){};

TemporalAnd::~TemporalAnd(){

    for (auto item : _items) {
        delete item;
    }

};

Trinary TemporalAnd::evaluate(size_t time) {
  //if one element is F, all AND is false
  for (auto t : _items) {
    if (t->evaluate(time) == Trinary::F)
      return Trinary::F;
    else if (t->evaluate(time) == Trinary::U)
      return Trinary::U;
  }
  return Trinary::T;
}

void TemporalAnd::addItem(TemporalExp *prop) {
  _items.push_back(prop);
}

void TemporalAnd::addFront(TemporalExp *prop) {
    _items.insert(_items.begin(), prop);
}
TemporalExp* TemporalAnd::popFront() {
    auto item = _items.front();
    _items.erase(_items.begin());
    return item;
}

std::vector<TemporalExp *> TemporalAnd::getItems() { return _items; };

//std::vector<expression::Proposition *> TemporalAnd::getPropositions() {
//  std::vector<expression::Proposition *> ret;
//
//  for (auto texp : _items) {
//    std::vector<expression::Proposition *> p = texp->getItems();
//    ret.insert(ret.end(), p.begin(), p.end());
//  }
//
//  return ret;
//};

size_t TemporalAnd::size() { return _items.size(); }

void TemporalAnd::popItem() { _items.pop_back(); }

Proposition * TemporalAnd::popLastItem(){
  auto inst = dynamic_cast<TemporalInst *>(_items.back());
  auto prop = inst->getProposition();
  _items.pop_back();
  return prop;
}


void TemporalAnd::removeItems() { _items.clear(); }

void TemporalAnd::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
