#include "visitors/CopyVisitor.hh"

//------------------------------------------------------------------------------
#define LEAF_NODE(LEAF, DEST)                                                  \
  void CopyVisitor::visit(LEAF &o) { DEST = new LEAF(o); }

#define EXPRESSION(OPERATOR, OPERAND, RESULT)                                  \
  void CopyVisitor::visit(OPERATOR &o) {                                       \
    auto *copy = new OPERATOR();                                               \
    auto type = o.getType();                                                   \
    copy->setType(type.first, type.second);                                    \
    auto &items = o.getItems();                                                \
    for (auto *item : items) {                                                 \
      item->acceptVisitor(*this);                                              \
      copy->addItem(OPERAND);                                                  \
    }                                                                          \
    RESULT = copy;                                                             \
  }
//------------------------------------------------------------------------------

namespace expression {

CopyVisitor::CopyVisitor()
    : ExpVisitor(), _proposition(nullptr), _numeric(nullptr), _logic(nullptr) {
  // ntd
}

CopyVisitor::~CopyVisitor() { delete _proposition; }

Proposition *CopyVisitor::get() {
  Proposition *ret = _proposition;
  _proposition = nullptr;
  return ret;
}
LogicExpression *CopyVisitor::getLogic() {
  LogicExpression *ret = _logic;
  _logic = nullptr;
  return ret;
}
NumericExpression *CopyVisitor::getNumeric() {
  NumericExpression *ret = _numeric;
  _numeric = nullptr;
  return ret;
}

// proposition
LEAF_NODE(BooleanConstant, _proposition)
LEAF_NODE(BooleanVariable, _proposition)
EXPRESSION(PropositionAnd, _proposition, _proposition)
EXPRESSION(PropositionOr, _proposition, _proposition)
EXPRESSION(PropositionXor, _proposition, _proposition)
EXPRESSION(PropositionEq, _proposition, _proposition)
EXPRESSION(PropositionNeq, _proposition, _proposition)
EXPRESSION(PropositionNot, _proposition, _proposition)

void CopyVisitor::visit(LogicToBool &o) {
  o.getItem().acceptVisitor(*this);
  _proposition = new LogicToBool(_logic);
}

// numeric
LEAF_NODE(NumericConstant, _numeric)
LEAF_NODE(NumericVariable, _numeric)
EXPRESSION(NumericSum, _numeric, _numeric)
EXPRESSION(NumericSub, _numeric, _numeric)
EXPRESSION(NumericMul, _numeric, _numeric)
EXPRESSION(NumericDiv, _numeric, _numeric)
EXPRESSION(NumericEq, _numeric, _proposition)
EXPRESSION(NumericNeq, _numeric, _proposition)
EXPRESSION(NumericLess, _numeric, _proposition)
EXPRESSION(NumericLessEq, _numeric, _proposition)
EXPRESSION(NumericGreater, _numeric, _proposition)
EXPRESSION(NumericGreaterEq, _numeric, _proposition)

void CopyVisitor::visit(LogicToNumeric &o) {
  o.getItem().acceptVisitor(*this);
  _numeric = new LogicToNumeric(_logic);
}

// logic
LEAF_NODE(LogicConstant, _logic)
LEAF_NODE(LogicVariable, _logic)
EXPRESSION(LogicSum, _logic, _logic)
EXPRESSION(LogicSub, _logic, _logic)
EXPRESSION(LogicMul, _logic, _logic)
EXPRESSION(LogicDiv, _logic, _logic)
EXPRESSION(LogicBAnd, _logic, _logic)
EXPRESSION(LogicBOr, _logic, _logic)
EXPRESSION(LogicBXor, _logic, _logic)
EXPRESSION(LogicNot, _logic, _logic)
EXPRESSION(LogicEq, _logic, _proposition)
EXPRESSION(LogicNeq, _logic, _proposition)
EXPRESSION(LogicLess, _logic, _proposition)
EXPRESSION(LogicLessEq, _logic, _proposition)
EXPRESSION(LogicGreater, _logic, _proposition)
EXPRESSION(LogicGreaterEq, _logic, _proposition)
EXPRESSION(LogicRShift, _logic, _logic)
EXPRESSION(LogicLShift, _logic, _logic)

void CopyVisitor::visit(LogicBitSelector &o) {
  o.getItem().acceptVisitor(*this);
  _logic = new LogicBitSelector(_logic, o.getUpperBound(), o.getLowerBound());
}
void CopyVisitor::visit(NumericToBool &o) {
  o.getItem().acceptVisitor(*this);
  _proposition = new NumericToBool(_numeric);
}

//temporal
void CopyVisitor::visit(Placeholder &o) {
  auto *copy = new Placeholder();
  if (o.getProposition() != nullptr) {
    o.getProposition()->acceptVisitor(*this);
    copy->setProposition(_proposition);
  }
  _te = copy;
}

void CopyVisitor::visit(TemporalInst &o) {
  auto *copy = new TemporalInst();
  if (o.getProposition() != nullptr) {
    o.getProposition()->acceptVisitor(*this);
    copy->setProposition(_proposition);
  }
  _te = copy;
}

void CopyVisitor::visit(TemporalAnd &o) {
  auto *copy = new TemporalAnd();
  auto items = o.getItems();
  for (auto *item : items) {
    item->acceptVisitor(*this);
    copy->addItem(_te);
  }
  _te = copy;
}

void CopyVisitor::visit(Implication &o) {
  auto *copy = new Implication();
  auto items = o.getItems();

  //ant
  items[0]->acceptVisitor(*this);
  copy->setAnt(_te);
  //con
  items[1]->acceptVisitor(*this);
  copy->setCon(_te);

  _te = copy;
}

void CopyVisitor::visit(Eventually &o) {
  auto item = o.getOperand();
  auto *copy = new Eventually(o);
  item->acceptVisitor(*this);
  copy->setOperand(_te);
  _te = copy;
}

} // namespace expression
