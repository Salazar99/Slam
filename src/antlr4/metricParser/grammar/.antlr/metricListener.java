// Generated from /home/magister/Slam/src/antlr4/metricParser/grammar/metric.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link metricParser}.
 */
public interface metricListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link metricParser#file}.
	 * @param ctx the parse tree
	 */
	void enterFile(metricParser.FileContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#file}.
	 * @param ctx the parse tree
	 */
	void exitFile(metricParser.FileContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#logic}.
	 * @param ctx the parse tree
	 */
	void enterLogic(metricParser.LogicContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#logic}.
	 * @param ctx the parse tree
	 */
	void exitLogic(metricParser.LogicContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#logicAtom}.
	 * @param ctx the parse tree
	 */
	void enterLogicAtom(metricParser.LogicAtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#logicAtom}.
	 * @param ctx the parse tree
	 */
	void exitLogicAtom(metricParser.LogicAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#logicConstant}.
	 * @param ctx the parse tree
	 */
	void enterLogicConstant(metricParser.LogicConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#logicConstant}.
	 * @param ctx the parse tree
	 */
	void exitLogicConstant(metricParser.LogicConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#logicVariable}.
	 * @param ctx the parse tree
	 */
	void enterLogicVariable(metricParser.LogicVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#logicVariable}.
	 * @param ctx the parse tree
	 */
	void exitLogicVariable(metricParser.LogicVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#numeric}.
	 * @param ctx the parse tree
	 */
	void enterNumeric(metricParser.NumericContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#numeric}.
	 * @param ctx the parse tree
	 */
	void exitNumeric(metricParser.NumericContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#numericAtom}.
	 * @param ctx the parse tree
	 */
	void enterNumericAtom(metricParser.NumericAtomContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#numericAtom}.
	 * @param ctx the parse tree
	 */
	void exitNumericAtom(metricParser.NumericAtomContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#numericConstant}.
	 * @param ctx the parse tree
	 */
	void enterNumericConstant(metricParser.NumericConstantContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#numericConstant}.
	 * @param ctx the parse tree
	 */
	void exitNumericConstant(metricParser.NumericConstantContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#numericVariable}.
	 * @param ctx the parse tree
	 */
	void enterNumericVariable(metricParser.NumericVariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#numericVariable}.
	 * @param ctx the parse tree
	 */
	void exitNumericVariable(metricParser.NumericVariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#variable}.
	 * @param ctx the parse tree
	 */
	void enterVariable(metricParser.VariableContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#variable}.
	 * @param ctx the parse tree
	 */
	void exitVariable(metricParser.VariableContext ctx);
	/**
	 * Enter a parse tree produced by {@link metricParser#relop}.
	 * @param ctx the parse tree
	 */
	void enterRelop(metricParser.RelopContext ctx);
	/**
	 * Exit a parse tree produced by {@link metricParser#relop}.
	 * @param ctx the parse tree
	 */
	void exitRelop(metricParser.RelopContext ctx);
}