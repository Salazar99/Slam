#include "classes/temporal/TemporalAnd.hh"
#include "visitors/ExpVisitor.hh"

namespace expression {

TemporalAnd::TemporalAnd(TemporalExp *first) { _items.push_back(first); };
TemporalAnd::TemporalAnd(){};

TemporalAnd::~TemporalAnd(){};

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
  //first element of the and is empty, can insert prop
  _items.push_back(prop);
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

void TemporalAnd::removeItems() { _items.clear(); }

void TemporalAnd::acceptVisitor(ExpVisitor &vis) { vis.visit(*this); }
}; // namespace expression
