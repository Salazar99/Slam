// Generated from stl.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link stlParser}.
 */
public interface stlListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link stlParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(stlParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(stlParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#formula}.
	 * @param ctx the parse tree
	 */
	void enterFormula(stlParser.FormulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#formula}.
	 * @param ctx the parse tree
	 */
	void exitFormula(stlParser.FormulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#tformula}.
	 * @param ctx the parse tree
	 */
	void enterTformula(stlParser.TformulaContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#tformula}.
	 * @param ctx the parse tree
	 */
	void exitTformula(stlParser.TformulaContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#placeholder}.
	 * @param ctx the parse tree
	 */
	void enterPlaceholder(stlParser.PlaceholderContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#placeholder}.
	 * @param ctx the parse tree
	 */
	void exitPlaceholder(stlParser.PlaceholderContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#interval_placeholder}.
	 * @param ctx the parse tree
	 */
	void enterInterval_placeholder(stlParser.Interval_placeholderContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#interval_placeholder}.
	 * @param ctx the parse tree
	 */
	void exitInterval_placeholder(stlParser.Interval_placeholderContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#interval}.
	 * @param ctx the parse tree
	 */
	void enterInterval(stlParser.IntervalContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#interval}.
	 * @param ctx the parse tree
	 */
	void exitInterval(stlParser.IntervalContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#boolean}.
	 * @param ctx the parse tree
	 */
	void enterBoolean(stlParser.BooleanContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#boolean}.
	 * @param ctx the parse tree
	 */
	void exitBoolean(stlParser.BooleanContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#booleanAtom}.
	 * @param ctx the parse tree
	 */
	void enterBooleanAtom(stlParser.BooleanAtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#booleanAtom}.
	 * @param ctx the parse tree
	 */
	void exitBooleanAtom(stlParser.BooleanAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#booleanConstant}.
	 * @param ctx the parse tree
	 */
	void enterBooleanConstant(stlParser.BooleanConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#booleanConstant}.
	 * @param ctx the parse tree
	 */
	void exitBooleanConstant(stlParser.BooleanConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#booleanVariable}.
	 * @param ctx the parse tree
	 */
	void enterBooleanVariable(stlParser.BooleanVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#booleanVariable}.
	 * @param ctx the parse tree
	 */
	void exitBooleanVariable(stlParser.BooleanVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#logic}.
	 * @param ctx the parse tree
	 */
	void enterLogic(stlParser.LogicContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#logic}.
	 * @param ctx the parse tree
	 */
	void exitLogic(stlParser.LogicContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#bitSelect}.
	 * @param ctx the parse tree
	 */
	void enterBitSelect(stlParser.BitSelectContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#bitSelect}.
	 * @param ctx the parse tree
	 */
	void exitBitSelect(stlParser.BitSelectContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#logicAtom}.
	 * @param ctx the parse tree
	 */
	void enterLogicAtom(stlParser.LogicAtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#logicAtom}.
	 * @param ctx the parse tree
	 */
	void exitLogicAtom(stlParser.LogicAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#logicConstant}.
	 * @param ctx the parse tree
	 */
	void enterLogicConstant(stlParser.LogicConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#logicConstant}.
	 * @param ctx the parse tree
	 */
	void exitLogicConstant(stlParser.LogicConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#logicVariable}.
	 * @param ctx the parse tree
	 */
	void enterLogicVariable(stlParser.LogicVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#logicVariable}.
	 * @param ctx the parse tree
	 */
	void exitLogicVariable(stlParser.LogicVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#numeric}.
	 * @param ctx the parse tree
	 */
	void enterNumeric(stlParser.NumericContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#numeric}.
	 * @param ctx the parse tree
	 */
	void exitNumeric(stlParser.NumericContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#numericAtom}.
	 * @param ctx the parse tree
	 */
	void enterNumericAtom(stlParser.NumericAtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#numericAtom}.
	 * @param ctx the parse tree
	 */
	void exitNumericAtom(stlParser.NumericAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#numericConstant}.
	 * @param ctx the parse tree
	 */
	void enterNumericConstant(stlParser.NumericConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#numericConstant}.
	 * @param ctx the parse tree
	 */
	void exitNumericConstant(stlParser.NumericConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#numericVariable}.
	 * @param ctx the parse tree
	 */
	void enterNumericVariable(stlParser.NumericVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#numericVariable}.
	 * @param ctx the parse tree
	 */
	void exitNumericVariable(stlParser.NumericVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(stlParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(stlParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link stlParser#relop}.
	 * @param ctx the parse tree
	 */
	void enterRelop(stlParser.RelopContext ctx);
	/**
	 * Exit a parse tree produced by {@link stlParser#relop}.
	 * @param ctx the parse tree
	 */
	void exitRelop(stlParser.RelopContext ctx);
}