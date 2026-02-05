#include "classes/expression/Expression.hh"
#include "expUtils/cConversion.hh"
#include "message.hh"
#include "visitors/ExpVisitor.hh"
#include <bitset>
#include <climits>
#include <iostream>
#include <limits>

namespace expression {

//==== Call to Visitor's methods ===============================================
#define VISITOR_CALL(Operator, ET, OT)                                         \
  template <>                                                                  \
  void Expression<BinaryOperator::Operator, ET, OT>::acceptVisitor(            \
      ExpVisitor &vis) {                                                       \
    vis.visit(*this);                                                          \
  }

// proposition
VISITOR_CALL(AND, Proposition, Proposition)
VISITOR_CALL(OR, Proposition, Proposition)
VISITOR_CALL(XOR, Proposition, Proposition)
VISITOR_CALL(EQ, Proposition, Proposition)
VISITOR_CALL(NEQ, Proposition, Proposition)
VISITOR_CALL(NOT, Proposition, Proposition)

// numeric
VISITOR_CALL(SUM, NumericExpression, NumericExpression)
VISITOR_CALL(SUB, NumericExpression, NumericExpression)
VISITOR_CALL(MUL, NumericExpression, NumericExpression)
VISITOR_CALL(DIV, NumericExpression, NumericExpression)
VISITOR_CALL(EQ, NumericExpression, Proposition)
VISITOR_CALL(NEQ, NumericExpression, Proposition)
VISITOR_CALL(GT, NumericExpression, Proposition)
VISITOR_CALL(GE, NumericExpression, Proposition)
VISITOR_CALL(LT, NumericExpression, Proposition)
VISITOR_CALL(LE, NumericExpression, Proposition)

// logic
VISITOR_CALL(SUM, LogicExpression, LogicExpression)
VISITOR_CALL(SUB, LogicExpression, LogicExpression)
VISITOR_CALL(MUL, LogicExpression, LogicExpression)
VISITOR_CALL(DIV, LogicExpression, LogicExpression)
VISITOR_CALL(BAND, LogicExpression, LogicExpression)
VISITOR_CALL(BOR, LogicExpression, LogicExpression)
VISITOR_CALL(BXOR, LogicExpression, LogicExpression)
VISITOR_CALL(EQ, LogicExpression, Proposition)
VISITOR_CALL(NEQ, LogicExpression, Proposition)
VISITOR_CALL(GT, LogicExpression, Proposition)
VISITOR_CALL(GE, LogicExpression, Proposition)
VISITOR_CALL(LT, LogicExpression, Proposition)
VISITOR_CALL(LE, LogicExpression, Proposition)
VISITOR_CALL(NOT, LogicExpression, LogicExpression)
VISITOR_CALL(LS, LogicExpression, LogicExpression)
VISITOR_CALL(RS, LogicExpression, LogicExpression)
//------------------------------------------------------------------------------

//==== evaluate methods for propositions =======================================
template <>
bool Expression<BinaryOperator::AND, Proposition, Proposition>::evaluate(
    size_t time) {
  // messageErrorIf(_items.size() < 1, "size==" +
  // std::to_string(_items.size()));

  for (Proposition *prop : _items)
    if (!prop->evaluate(time))
      return false;

  return true;
}

template <>
bool Expression<BinaryOperator::OR, Proposition, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  for (Proposition *prop : _items)
    if (prop->evaluate(time))
      return true;

  return false;
}

template <>
bool Expression<BinaryOperator::XOR, Proposition, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  auto ret = _items[0]->evaluate(time);
  for (size_t i = 1; i < _items.size(); ++i)
    ret = ret ^ _items[i]->evaluate(time);

  return ret;
}

template <>
bool Expression<BinaryOperator::EQ, Proposition, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  return _items[0]->evaluate(time) == _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NEQ, Proposition, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  return _items[0]->evaluate(time) != _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NOT, Proposition, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 1, "size==" + std::to_string(_items.size()));

  return !_items[0]->evaluate(time);
}
//------------------------------------------------------------------------------
//==== evaluate methods for propositions =======================================
template <>
float Expression<BinaryOperator::AND, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
   messageErrorIf(_items.size() < 1, "size==" + std::to_string(_items.size()));
   messageErrorIf(_items.size() > 2, "size canno be >2, only expression of the form (a > num1) && (a < num2) are allowed");
  float rob = std::numeric_limits<float>::infinity();
  for (Proposition *prop : _items)
    rob = std::min(prop->evaluate_robustness(time), rob);
}

template <>
float Expression<BinaryOperator::OR, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
   messageError("Cannot call evaluate_robustness on binary OR expressions of type Proposition, Proposition");
   return 0.0f;
}

template <>
float Expression<BinaryOperator::XOR, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
    messageError("Cannot call evaluate_robustness on binary XOR expressions of type Proposition, Proposition");
    return 0.0f;
}

template <>
float Expression<BinaryOperator::EQ, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call evaluate_robustness on binary EQ expressions of type Proposition, Proposition");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::NEQ, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call evaluate_robustness on binary NEQ expressions of type Proposition, Proposition");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::NOT, Proposition, Proposition>::evaluate_robustness(
    size_t time) {
  messageErrorIf(_items.size() != 1, "size==" + std::to_string(_items.size()));

  return -(_items[0]->evaluate_robustness(time));
}
//------------------------------------------------------------------------------


//==== evaluate methods for numeric ============================================
template <>
Numeric
Expression<BinaryOperator::SUM, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  auto ret = _items[0]->evaluate(time);
  for (size_t i = 1; i < _items.size(); ++i)
    ret += _items[i]->evaluate(time);

  return ret;
}

template <>
Numeric
Expression<BinaryOperator::SUB, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  auto ret = _items[0]->evaluate(time);
  for (size_t i = 1; i < _items.size(); ++i)
    ret -= _items[i]->evaluate(time);

  return ret;
}

template <>
Numeric
Expression<BinaryOperator::MUL, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  auto ret = _items[0]->evaluate(time);
  for (size_t i = 1; i < _items.size(); ++i)
    ret *= _items[i]->evaluate(time);

  return ret;
}

template <>
Numeric
Expression<BinaryOperator::DIV, NumericExpression, NumericExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  auto ret = _items[0]->evaluate(time);
  for (size_t i = 1; i < _items.size(); ++i)
    ret /= _items[i]->evaluate(time);

  return ret;
}

template <>
bool Expression<BinaryOperator::EQ, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) == _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::NEQ, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) != _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GT, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) > _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::GE, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) >= _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LT, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) < _items[1]->evaluate(time);
}

template <>
bool Expression<BinaryOperator::LE, NumericExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  return _items[0]->evaluate(time) <= _items[1]->evaluate(time);
}
//------------------------------------------------------------------------------
//==== evaluate_robustness methods for numeric =================================
// Note: for EQ,NEQ,SUM,MUL,DIV we return an error, as their robustness measure is not defined and you should never have STL formulas with these operators. But for the moment we keep them here for the future.
template <>
float
Expression<BinaryOperator::SUM, NumericExpression, NumericExpression>::evaluate_robustness(
    size_t time) {
  messageError("Not supposed to call robustness for SUM operator");    
  return std::numeric_limits<float>::infinity();  
}

template <>
float
Expression<BinaryOperator::SUB, NumericExpression, NumericExpression>::evaluate_robustness(
    size_t time) {
  messageError("Not supposed to call robustness for SUB operator");  
  return std::numeric_limits<float>::infinity();  
}

template <>
float
Expression<BinaryOperator::MUL, NumericExpression, NumericExpression>::evaluate_robustness(
    size_t time) {
  messageError("Not supposed to call robustness for MUL operator");  
  return std::numeric_limits<float>::infinity();  
}

template <>
float
Expression<BinaryOperator::DIV, NumericExpression, NumericExpression>::evaluate_robustness(
    size_t time) {
  messageError("Not supposed to call robustness for DIV operator");    
  return std::numeric_limits<float>::infinity();  
}


template <>
float Expression<BinaryOperator::EQ, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
    messageErrorIf(_items.size() != 2, "Size ==" + std::to_string(_items.size()) + " , expected 2." );    
    if(_items[0]->evaluate(time) == _items[1]->evaluate(time)){
      return 0.0f;
    }else{
      return -(std::abs(static_cast<float>(_items[0]->evaluate(time) - _items[1]->evaluate(time))));
    }
    return std::numeric_limits<float>::infinity();  
}

template <>
float Expression<BinaryOperator::NEQ, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Not supposed to call robustness for NEQ operator");    
  return std::numeric_limits<float>::infinity();
}

template <>
float Expression<BinaryOperator::GT, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  Numeric e1 = _items[0]->evaluate(time);
  Numeric e2 = _items[1]->evaluate(time);
  // item1 > item2 
  if (e1 > e2) {
    return static_cast<float>(e1 - e2);
  } else {
    return static_cast<float>(e2 - e1) * -1.0f;
  }
}

template <>
float Expression<BinaryOperator::GE, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  Numeric e1 = _items[0]->evaluate(time);
  Numeric e2 = _items[1]->evaluate(time);
  
  if (e1 >= e2) {
    return static_cast<float>(e1 - e2);
  } else {
    return static_cast<float>(e2 - e1) * -1.0f;
  }
}

template <>
float Expression<BinaryOperator::LT, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
    Numeric e1 = _items[0]->evaluate(time);
    Numeric e2 = _items[1]->evaluate(time);
    
    if (e1 < e2) {
      return static_cast<float>(e2 - e1);
    } else {
      return static_cast<float>(e1 - e2) * -1.0f;
    }
}

template <>
float Expression<BinaryOperator::LE, NumericExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));
  Numeric e1 = _items[0]->evaluate(time);
  Numeric e2 = _items[1]->evaluate(time);
  
  if (e1 <= e2) {
    return static_cast<float>(e2 - e1);
  } else {
    return static_cast<float>(e1 - e2) * -1.0f;
  }
}

//------------------------------------------------------------------------------

//==== evaluate methods for logic ==============================================
template <>
ULogic
Expression<BinaryOperator::SUM, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) +
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) +
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::SUB, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) -
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) -
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::MUL, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) *
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) *
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::DIV, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) /
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) /
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::BAND, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) &
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) &
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::BOR, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) |
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) |
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::BXOR, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) ^
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) ^
           (ULogic)_items[1]->evaluate(time);
  }
}
template <>
bool Expression<BinaryOperator::EQ, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) ==
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) ==
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
bool Expression<BinaryOperator::NEQ, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) !=
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) !=
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
bool Expression<BinaryOperator::GT, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) >
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) >
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
bool Expression<BinaryOperator::GE, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) >=
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) >=
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
bool Expression<BinaryOperator::LT, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) <
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) <
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
bool Expression<BinaryOperator::LE, LogicExpression, Proposition>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) <=
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) <=
           (ULogic)_items[1]->evaluate(time);
  }
}

template <>
ULogic
Expression<BinaryOperator::NOT, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 1, "size==" + std::to_string(_items.size()));

  return ~_items[0]->evaluate(time);
}
template <>
ULogic
Expression<BinaryOperator::LS, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time)
           << (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time)
           << (ULogic)_items[1]->evaluate(time);
  }
}
template <>
ULogic
Expression<BinaryOperator::RS, LogicExpression, LogicExpression>::evaluate(
    size_t time) {
  messageErrorIf(_items.size() != 2, "size==" + std::to_string(_items.size()));

  if (applyCStandardConversion(_items[0]->getType(), _items[1]->getType())
          .first == VarType::SLogic) {
    return (SLogic)_items[0]->evaluate(time) >>
           (SLogic)_items[1]->evaluate(time);
  } else {
    return (ULogic)_items[0]->evaluate(time) >>
           (ULogic)_items[1]->evaluate(time);
  }
}
//------------------------------------------------------------------------------
//==== evaluate methods for logic ==============================================
template <>
float
Expression<BinaryOperator::SUM, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for SUM operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::SUB, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for SUB operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::MUL, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for MUL operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::DIV, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for DIV operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::BAND, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for BAND operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::BOR, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for BOR operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::BXOR, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for BXOR operator for LogicVars");
  return 0.0f;
}
template <>
float Expression<BinaryOperator::EQ, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for EQ operator for LogicVars");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::NEQ, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for NEQ operator for LogicVars");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::GT, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for GT operator for LogicVars");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::GE, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for GE operator for LogicVars");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::LT, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for LT operator for LogicVars");
  return 0.0f;
}

template <>
float Expression<BinaryOperator::LE, LogicExpression, Proposition>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for LE operator for LogicVars");
  return 0.0f;
}

template <>
float
Expression<BinaryOperator::NOT, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
    return -(_items[0]->evaluate_robustness(time));
}
template <>
float
Expression<BinaryOperator::LS, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for LS operator for LogicVars");
  return 0.0f;
}
template <>
float
Expression<BinaryOperator::RS, LogicExpression, LogicExpression>::evaluate_robustness(
    size_t time) {
  messageError("Cannot call robustness for RS operator for LogicVars");
  return 0.0f;
}
//------------------------------------------------------------------------------
} // namespace expression
