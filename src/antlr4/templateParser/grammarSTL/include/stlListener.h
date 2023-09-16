
// Generated from stl.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "stlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by stlParser.
 */
class  stlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(stlParser::FileContext *ctx) = 0;
  virtual void exitFile(stlParser::FileContext *ctx) = 0;

  virtual void enterImplication(stlParser::ImplicationContext *ctx) = 0;
  virtual void exitImplication(stlParser::ImplicationContext *ctx) = 0;

  virtual void enterTformula(stlParser::TformulaContext *ctx) = 0;
  virtual void exitTformula(stlParser::TformulaContext *ctx) = 0;

  virtual void enterPlaceholder(stlParser::PlaceholderContext *ctx) = 0;
  virtual void exitPlaceholder(stlParser::PlaceholderContext *ctx) = 0;

  virtual void enterInterval_placeholder(stlParser::Interval_placeholderContext *ctx) = 0;
  virtual void exitInterval_placeholder(stlParser::Interval_placeholderContext *ctx) = 0;

  virtual void enterInterval(stlParser::IntervalContext *ctx) = 0;
  virtual void exitInterval(stlParser::IntervalContext *ctx) = 0;

  virtual void enterBoolean(stlParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(stlParser::BooleanContext *ctx) = 0;

  virtual void enterBooleanAtom(stlParser::BooleanAtomContext *ctx) = 0;
  virtual void exitBooleanAtom(stlParser::BooleanAtomContext *ctx) = 0;

  virtual void enterBooleanConstant(stlParser::BooleanConstantContext *ctx) = 0;
  virtual void exitBooleanConstant(stlParser::BooleanConstantContext *ctx) = 0;

  virtual void enterBooleanVariable(stlParser::BooleanVariableContext *ctx) = 0;
  virtual void exitBooleanVariable(stlParser::BooleanVariableContext *ctx) = 0;

  virtual void enterLogic(stlParser::LogicContext *ctx) = 0;
  virtual void exitLogic(stlParser::LogicContext *ctx) = 0;

  virtual void enterBitSelect(stlParser::BitSelectContext *ctx) = 0;
  virtual void exitBitSelect(stlParser::BitSelectContext *ctx) = 0;

  virtual void enterLogicAtom(stlParser::LogicAtomContext *ctx) = 0;
  virtual void exitLogicAtom(stlParser::LogicAtomContext *ctx) = 0;

  virtual void enterLogicConstant(stlParser::LogicConstantContext *ctx) = 0;
  virtual void exitLogicConstant(stlParser::LogicConstantContext *ctx) = 0;

  virtual void enterLogicVariable(stlParser::LogicVariableContext *ctx) = 0;
  virtual void exitLogicVariable(stlParser::LogicVariableContext *ctx) = 0;

  virtual void enterNumeric(stlParser::NumericContext *ctx) = 0;
  virtual void exitNumeric(stlParser::NumericContext *ctx) = 0;

  virtual void enterNumericAtom(stlParser::NumericAtomContext *ctx) = 0;
  virtual void exitNumericAtom(stlParser::NumericAtomContext *ctx) = 0;

  virtual void enterNumericConstant(stlParser::NumericConstantContext *ctx) = 0;
  virtual void exitNumericConstant(stlParser::NumericConstantContext *ctx) = 0;

  virtual void enterNumericVariable(stlParser::NumericVariableContext *ctx) = 0;
  virtual void exitNumericVariable(stlParser::NumericVariableContext *ctx) = 0;

  virtual void enterVariable(stlParser::VariableContext *ctx) = 0;
  virtual void exitVariable(stlParser::VariableContext *ctx) = 0;

  virtual void enterRelop(stlParser::RelopContext *ctx) = 0;
  virtual void exitRelop(stlParser::RelopContext *ctx) = 0;


};

