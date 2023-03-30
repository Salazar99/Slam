
// Generated from stl.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "stlListener.h"


/**
 * This class provides an empty implementation of stlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  stlBaseListener : public stlListener {
public:

  virtual void enterFile(stlParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(stlParser::FileContext * /*ctx*/) override { }

  virtual void enterFormula(stlParser::FormulaContext * /*ctx*/) override { }
  virtual void exitFormula(stlParser::FormulaContext * /*ctx*/) override { }

  virtual void enterTformula(stlParser::TformulaContext * /*ctx*/) override { }
  virtual void exitTformula(stlParser::TformulaContext * /*ctx*/) override { }

  virtual void enterPlaceholder(stlParser::PlaceholderContext * /*ctx*/) override { }
  virtual void exitPlaceholder(stlParser::PlaceholderContext * /*ctx*/) override { }

  virtual void enterInterval(stlParser::IntervalContext * /*ctx*/) override { }
  virtual void exitInterval(stlParser::IntervalContext * /*ctx*/) override { }

  virtual void enterBoolean(stlParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(stlParser::BooleanContext * /*ctx*/) override { }

  virtual void enterBooleanAtom(stlParser::BooleanAtomContext * /*ctx*/) override { }
  virtual void exitBooleanAtom(stlParser::BooleanAtomContext * /*ctx*/) override { }

  virtual void enterBooleanConstant(stlParser::BooleanConstantContext * /*ctx*/) override { }
  virtual void exitBooleanConstant(stlParser::BooleanConstantContext * /*ctx*/) override { }

  virtual void enterBooleanVariable(stlParser::BooleanVariableContext * /*ctx*/) override { }
  virtual void exitBooleanVariable(stlParser::BooleanVariableContext * /*ctx*/) override { }

  virtual void enterLogic(stlParser::LogicContext * /*ctx*/) override { }
  virtual void exitLogic(stlParser::LogicContext * /*ctx*/) override { }

  virtual void enterBitSelect(stlParser::BitSelectContext * /*ctx*/) override { }
  virtual void exitBitSelect(stlParser::BitSelectContext * /*ctx*/) override { }

  virtual void enterLogicAtom(stlParser::LogicAtomContext * /*ctx*/) override { }
  virtual void exitLogicAtom(stlParser::LogicAtomContext * /*ctx*/) override { }

  virtual void enterLogicConstant(stlParser::LogicConstantContext * /*ctx*/) override { }
  virtual void exitLogicConstant(stlParser::LogicConstantContext * /*ctx*/) override { }

  virtual void enterLogicVariable(stlParser::LogicVariableContext * /*ctx*/) override { }
  virtual void exitLogicVariable(stlParser::LogicVariableContext * /*ctx*/) override { }

  virtual void enterNumeric(stlParser::NumericContext * /*ctx*/) override { }
  virtual void exitNumeric(stlParser::NumericContext * /*ctx*/) override { }

  virtual void enterNumericAtom(stlParser::NumericAtomContext * /*ctx*/) override { }
  virtual void exitNumericAtom(stlParser::NumericAtomContext * /*ctx*/) override { }

  virtual void enterNumericConstant(stlParser::NumericConstantContext * /*ctx*/) override { }
  virtual void exitNumericConstant(stlParser::NumericConstantContext * /*ctx*/) override { }

  virtual void enterNumericVariable(stlParser::NumericVariableContext * /*ctx*/) override { }
  virtual void exitNumericVariable(stlParser::NumericVariableContext * /*ctx*/) override { }

  virtual void enterVariable(stlParser::VariableContext * /*ctx*/) override { }
  virtual void exitVariable(stlParser::VariableContext * /*ctx*/) override { }

  virtual void enterRelop(stlParser::RelopContext * /*ctx*/) override { }
  virtual void exitRelop(stlParser::RelopContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

