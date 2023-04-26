// Generated from stl.g4 by ANTLR 4.12.0
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class stlParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.12.0", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, DT_ANDF=7, STL_EVENTUALLY=8, 
		STL_ALWAYS=9, RELEASE=10, IMPL=11, SCOL=12, COL=13, COMMA=14, FIRST_MATCH=15, 
		SIGN=16, LGPAREN=17, RGPAREN=18, LCPAREN=19, RCPAREN=20, LPAREN=21, RPAREN=22, 
		VARIABLE=23, NUMERIC=24, VERILOG_BINARY=25, GCC_BINARY=26, HEX=27, BOOLEAN=28, 
		PLUS=29, MINUS=30, TIMES=31, DIV=32, GT=33, GE=34, LT=35, LE=36, EQ=37, 
		NEQ=38, BAND=39, BOR=40, BXOR=41, NEG=42, LSHIFT=43, RSHIFT=44, AND=45, 
		OR=46, NOT=47, WS=48;
	public static final int
		RULE_file = 0, RULE_formula = 1, RULE_tformula = 2, RULE_placeholder = 3, 
		RULE_interval_placeholder = 4, RULE_interval = 5, RULE_boolean = 6, RULE_booleanAtom = 7, 
		RULE_booleanConstant = 8, RULE_booleanVariable = 9, RULE_logic = 10, RULE_bitSelect = 11, 
		RULE_logicAtom = 12, RULE_logicConstant = 13, RULE_logicVariable = 14, 
		RULE_numeric = 15, RULE_numericAtom = 16, RULE_numericConstant = 17, RULE_numericVariable = 18, 
		RULE_variable = 19, RULE_relop = 20;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "formula", "tformula", "placeholder", "interval_placeholder", 
			"interval", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
			"logic", "bitSelect", "logicAtom", "logicConstant", "logicVariable", 
			"numeric", "numericAtom", "numericConstant", "numericVariable", "variable", 
			"relop"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'P'", "'X'", "',bool>'", "',logic('", "')>'", "',numeric('", "'..F..'", 
			"'F'", "'G'", "'release'", "'->'", "';'", "':'", "','", "'first_match'", 
			null, "'{'", "'}'", "'['", "']'", "'('", "')'", null, null, null, null, 
			null, null, "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", 
			"'=='", "'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", 
			"'!'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, "DT_ANDF", "STL_EVENTUALLY", 
			"STL_ALWAYS", "RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH", 
			"SIGN", "LGPAREN", "RGPAREN", "LCPAREN", "RCPAREN", "LPAREN", "RPAREN", 
			"VARIABLE", "NUMERIC", "VERILOG_BINARY", "GCC_BINARY", "HEX", "BOOLEAN", 
			"PLUS", "MINUS", "TIMES", "DIV", "GT", "GE", "LT", "LE", "EQ", "NEQ", 
			"BAND", "BOR", "BXOR", "NEG", "LSHIFT", "RSHIFT", "AND", "OR", "NOT", 
			"WS"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "stl.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public stlParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FileContext extends ParserRuleContext {
		public TerminalNode STL_ALWAYS() { return getToken(stlParser.STL_ALWAYS, 0); }
		public FormulaContext formula() {
			return getRuleContext(FormulaContext.class,0);
		}
		public TerminalNode EOF() { return getToken(stlParser.EOF, 0); }
		public TerminalNode LCPAREN() { return getToken(stlParser.LCPAREN, 0); }
		public IntervalContext interval() {
			return getRuleContext(IntervalContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(stlParser.RCPAREN, 0); }
		public TerminalNode LPAREN() { return getToken(stlParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(stlParser.RPAREN, 0); }
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterFile(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitFile(this);
		}
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		try {
			setState(55);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(42);
				match(STL_ALWAYS);
				setState(43);
				formula();
				setState(44);
				match(EOF);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(46);
				match(STL_ALWAYS);
				setState(47);
				match(LCPAREN);
				setState(48);
				interval();
				setState(49);
				match(RCPAREN);
				setState(50);
				match(LPAREN);
				setState(51);
				formula();
				setState(52);
				match(RPAREN);
				setState(53);
				match(EOF);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FormulaContext extends ParserRuleContext {
		public List<TformulaContext> tformula() {
			return getRuleContexts(TformulaContext.class);
		}
		public TformulaContext tformula(int i) {
			return getRuleContext(TformulaContext.class,i);
		}
		public TerminalNode IMPL() { return getToken(stlParser.IMPL, 0); }
		public FormulaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_formula; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterFormula(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitFormula(this);
		}
	}

	public final FormulaContext formula() throws RecognitionException {
		FormulaContext _localctx = new FormulaContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_formula);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(57);
			tformula(0);
			setState(58);
			match(IMPL);
			setState(59);
			tformula(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class TformulaContext extends ParserRuleContext {
		public BooleanContext boolean_() {
			return getRuleContext(BooleanContext.class,0);
		}
		public PlaceholderContext placeholder() {
			return getRuleContext(PlaceholderContext.class,0);
		}
		public TerminalNode DT_ANDF() { return getToken(stlParser.DT_ANDF, 0); }
		public TerminalNode LPAREN() { return getToken(stlParser.LPAREN, 0); }
		public List<TformulaContext> tformula() {
			return getRuleContexts(TformulaContext.class);
		}
		public TformulaContext tformula(int i) {
			return getRuleContext(TformulaContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(stlParser.RPAREN, 0); }
		public TerminalNode NOT() { return getToken(stlParser.NOT, 0); }
		public TerminalNode STL_EVENTUALLY() { return getToken(stlParser.STL_EVENTUALLY, 0); }
		public TerminalNode LCPAREN() { return getToken(stlParser.LCPAREN, 0); }
		public IntervalContext interval() {
			return getRuleContext(IntervalContext.class,0);
		}
		public TerminalNode RCPAREN() { return getToken(stlParser.RCPAREN, 0); }
		public TerminalNode AND() { return getToken(stlParser.AND, 0); }
		public TerminalNode OR() { return getToken(stlParser.OR, 0); }
		public TformulaContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tformula; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterTformula(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitTformula(this);
		}
	}

	public final TformulaContext tformula() throws RecognitionException {
		return tformula(0);
	}

	private TformulaContext tformula(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TformulaContext _localctx = new TformulaContext(_ctx, _parentState);
		TformulaContext _prevctx = _localctx;
		int _startState = 4;
		enterRecursionRule(_localctx, 4, RULE_tformula, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				{
				setState(62);
				boolean_(0);
				}
				break;
			case 2:
				{
				setState(63);
				placeholder();
				}
				break;
			case 3:
				{
				setState(64);
				match(DT_ANDF);
				}
				break;
			case 4:
				{
				setState(65);
				match(LPAREN);
				setState(66);
				tformula(0);
				setState(67);
				match(RPAREN);
				}
				break;
			case 5:
				{
				setState(69);
				match(NOT);
				setState(70);
				tformula(4);
				}
				break;
			case 6:
				{
				setState(71);
				match(STL_EVENTUALLY);
				setState(72);
				match(LCPAREN);
				setState(73);
				interval();
				setState(74);
				match(RCPAREN);
				setState(75);
				tformula(1);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(87);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(85);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,2,_ctx) ) {
					case 1:
						{
						_localctx = new TformulaContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_tformula);
						setState(79);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(80);
						match(AND);
						setState(81);
						tformula(4);
						}
						break;
					case 2:
						{
						_localctx = new TformulaContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_tformula);
						setState(82);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(83);
						match(OR);
						setState(84);
						tformula(3);
						}
						break;
					}
					} 
				}
				setState(89);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,3,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class PlaceholderContext extends ParserRuleContext {
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public PlaceholderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_placeholder; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterPlaceholder(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitPlaceholder(this);
		}
	}

	public final PlaceholderContext placeholder() throws RecognitionException {
		PlaceholderContext _localctx = new PlaceholderContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_placeholder);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(90);
			match(T__0);
			setState(91);
			match(NUMERIC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class Interval_placeholderContext extends ParserRuleContext {
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public Interval_placeholderContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interval_placeholder; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterInterval_placeholder(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitInterval_placeholder(this);
		}
	}

	public final Interval_placeholderContext interval_placeholder() throws RecognitionException {
		Interval_placeholderContext _localctx = new Interval_placeholderContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_interval_placeholder);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(T__1);
			setState(94);
			match(NUMERIC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class IntervalContext extends ParserRuleContext {
		public List<Interval_placeholderContext> interval_placeholder() {
			return getRuleContexts(Interval_placeholderContext.class);
		}
		public Interval_placeholderContext interval_placeholder(int i) {
			return getRuleContext(Interval_placeholderContext.class,i);
		}
		public TerminalNode COMMA() { return getToken(stlParser.COMMA, 0); }
		public List<TerminalNode> NUMERIC() { return getTokens(stlParser.NUMERIC); }
		public TerminalNode NUMERIC(int i) {
			return getToken(stlParser.NUMERIC, i);
		}
		public IntervalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_interval; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterInterval(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitInterval(this);
		}
	}

	public final IntervalContext interval() throws RecognitionException {
		IntervalContext _localctx = new IntervalContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_interval);
		try {
			setState(103);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case T__1:
				enterOuterAlt(_localctx, 1);
				{
				setState(96);
				interval_placeholder();
				setState(97);
				match(COMMA);
				setState(98);
				interval_placeholder();
				}
				break;
			case NUMERIC:
				enterOuterAlt(_localctx, 2);
				{
				setState(100);
				match(NUMERIC);
				setState(101);
				match(COMMA);
				setState(102);
				match(NUMERIC);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanContext extends ParserRuleContext {
		public Token booleanop;
		public TerminalNode NOT() { return getToken(stlParser.NOT, 0); }
		public List<BooleanContext> boolean_() {
			return getRuleContexts(BooleanContext.class);
		}
		public BooleanContext boolean_(int i) {
			return getRuleContext(BooleanContext.class,i);
		}
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public RelopContext relop() {
			return getRuleContext(RelopContext.class,0);
		}
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode EQ() { return getToken(stlParser.EQ, 0); }
		public TerminalNode NEQ() { return getToken(stlParser.NEQ, 0); }
		public BooleanAtomContext booleanAtom() {
			return getRuleContext(BooleanAtomContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(stlParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(stlParser.RPAREN, 0); }
		public TerminalNode AND() { return getToken(stlParser.AND, 0); }
		public TerminalNode OR() { return getToken(stlParser.OR, 0); }
		public BooleanContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterBoolean(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitBoolean(this);
		}
	}

	public final BooleanContext boolean_() throws RecognitionException {
		return boolean_(0);
	}

	private BooleanContext boolean_(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		BooleanContext _localctx = new BooleanContext(_ctx, _parentState);
		BooleanContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_boolean, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(139);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
			case 1:
				{
				setState(106);
				match(NOT);
				setState(107);
				boolean_(15);
				}
				break;
			case 2:
				{
				setState(108);
				logic(0);
				setState(109);
				relop();
				setState(110);
				logic(0);
				}
				break;
			case 3:
				{
				setState(112);
				numeric(0);
				setState(113);
				relop();
				setState(114);
				numeric(0);
				}
				break;
			case 4:
				{
				setState(116);
				logic(0);
				setState(117);
				match(EQ);
				setState(118);
				logic(0);
				}
				break;
			case 5:
				{
				setState(120);
				numeric(0);
				setState(121);
				match(EQ);
				setState(122);
				numeric(0);
				}
				break;
			case 6:
				{
				setState(124);
				logic(0);
				setState(125);
				match(NEQ);
				setState(126);
				logic(0);
				}
				break;
			case 7:
				{
				setState(128);
				numeric(0);
				setState(129);
				match(NEQ);
				setState(130);
				numeric(0);
				}
				break;
			case 8:
				{
				setState(132);
				booleanAtom();
				}
				break;
			case 9:
				{
				setState(133);
				logic(0);
				}
				break;
			case 10:
				{
				setState(134);
				numeric(0);
				}
				break;
			case 11:
				{
				setState(135);
				match(LPAREN);
				setState(136);
				boolean_(0);
				setState(137);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(155);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(153);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
					case 1:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(141);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(142);
						match(EQ);
						setState(143);
						boolean_(11);
						}
						break;
					case 2:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(144);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(145);
						match(NEQ);
						setState(146);
						boolean_(8);
						}
						break;
					case 3:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(147);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(148);
						((BooleanContext)_localctx).booleanop = match(AND);
						setState(149);
						boolean_(7);
						}
						break;
					case 4:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(150);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(151);
						((BooleanContext)_localctx).booleanop = match(OR);
						setState(152);
						boolean_(6);
						}
						break;
					}
					} 
				}
				setState(157);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,7,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanAtomContext extends ParserRuleContext {
		public BooleanConstantContext booleanConstant() {
			return getRuleContext(BooleanConstantContext.class,0);
		}
		public BooleanVariableContext booleanVariable() {
			return getRuleContext(BooleanVariableContext.class,0);
		}
		public BooleanAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanAtom; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterBooleanAtom(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitBooleanAtom(this);
		}
	}

	public final BooleanAtomContext booleanAtom() throws RecognitionException {
		BooleanAtomContext _localctx = new BooleanAtomContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_booleanAtom);
		try {
			setState(160);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
				enterOuterAlt(_localctx, 1);
				{
				setState(158);
				booleanConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(159);
				booleanVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanConstantContext extends ParserRuleContext {
		public TerminalNode BOOLEAN() { return getToken(stlParser.BOOLEAN, 0); }
		public BooleanConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanConstant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterBooleanConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitBooleanConstant(this);
		}
	}

	public final BooleanConstantContext booleanConstant() throws RecognitionException {
		BooleanConstantContext _localctx = new BooleanConstantContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_booleanConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(162);
			match(BOOLEAN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BooleanVariableContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(stlParser.LT, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public BooleanVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanVariable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterBooleanVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitBooleanVariable(this);
		}
	}

	public final BooleanVariableContext booleanVariable() throws RecognitionException {
		BooleanVariableContext _localctx = new BooleanVariableContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_booleanVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			match(LT);
			setState(165);
			variable();
			setState(166);
			match(T__2);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LogicContext extends ParserRuleContext {
		public Token artop;
		public Token logop;
		public TerminalNode NEG() { return getToken(stlParser.NEG, 0); }
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public LogicAtomContext logicAtom() {
			return getRuleContext(LogicAtomContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(stlParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(stlParser.RPAREN, 0); }
		public TerminalNode TIMES() { return getToken(stlParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(stlParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(stlParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(stlParser.MINUS, 0); }
		public TerminalNode LSHIFT() { return getToken(stlParser.LSHIFT, 0); }
		public TerminalNode RSHIFT() { return getToken(stlParser.RSHIFT, 0); }
		public TerminalNode BAND() { return getToken(stlParser.BAND, 0); }
		public TerminalNode BXOR() { return getToken(stlParser.BXOR, 0); }
		public TerminalNode BOR() { return getToken(stlParser.BOR, 0); }
		public BitSelectContext bitSelect() {
			return getRuleContext(BitSelectContext.class,0);
		}
		public LogicContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterLogic(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitLogic(this);
		}
	}

	public final LogicContext logic() throws RecognitionException {
		return logic(0);
	}

	private LogicContext logic(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicContext _localctx = new LogicContext(_ctx, _parentState);
		LogicContext _prevctx = _localctx;
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_logic, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(176);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NEG:
				{
				setState(169);
				match(NEG);
				setState(170);
				logic(11);
				}
				break;
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
			case LT:
				{
				setState(171);
				logicAtom();
				}
				break;
			case LPAREN:
				{
				setState(172);
				match(LPAREN);
				setState(173);
				logic(0);
				setState(174);
				match(RPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(203);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(201);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
					case 1:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(178);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(179);
						((LogicContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==TIMES || _la==DIV) ) {
							((LogicContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(180);
						logic(10);
						}
						break;
					case 2:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(181);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(182);
						((LogicContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((LogicContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(183);
						logic(9);
						}
						break;
					case 3:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(184);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(185);
						((LogicContext)_localctx).logop = match(LSHIFT);
						setState(186);
						logic(8);
						}
						break;
					case 4:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(187);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(188);
						((LogicContext)_localctx).logop = match(RSHIFT);
						setState(189);
						logic(7);
						}
						break;
					case 5:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(190);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(191);
						((LogicContext)_localctx).logop = match(BAND);
						setState(192);
						logic(6);
						}
						break;
					case 6:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(193);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(194);
						((LogicContext)_localctx).logop = match(BXOR);
						setState(195);
						logic(5);
						}
						break;
					case 7:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(196);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(197);
						((LogicContext)_localctx).logop = match(BOR);
						setState(198);
						logic(4);
						}
						break;
					case 8:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(199);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(200);
						bitSelect();
						}
						break;
					}
					} 
				}
				setState(205);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class BitSelectContext extends ParserRuleContext {
		public TerminalNode LCPAREN() { return getToken(stlParser.LCPAREN, 0); }
		public List<TerminalNode> NUMERIC() { return getTokens(stlParser.NUMERIC); }
		public TerminalNode NUMERIC(int i) {
			return getToken(stlParser.NUMERIC, i);
		}
		public TerminalNode RCPAREN() { return getToken(stlParser.RCPAREN, 0); }
		public TerminalNode COL() { return getToken(stlParser.COL, 0); }
		public BitSelectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bitSelect; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterBitSelect(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitBitSelect(this);
		}
	}

	public final BitSelectContext bitSelect() throws RecognitionException {
		BitSelectContext _localctx = new BitSelectContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_bitSelect);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(206);
			match(LCPAREN);
			setState(207);
			match(NUMERIC);
			setState(210);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==COL) {
				{
				setState(208);
				match(COL);
				setState(209);
				match(NUMERIC);
				}
			}

			setState(212);
			match(RCPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LogicAtomContext extends ParserRuleContext {
		public LogicConstantContext logicConstant() {
			return getRuleContext(LogicConstantContext.class,0);
		}
		public LogicVariableContext logicVariable() {
			return getRuleContext(LogicVariableContext.class,0);
		}
		public LogicAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicAtom; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterLogicAtom(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitLogicAtom(this);
		}
	}

	public final LogicAtomContext logicAtom() throws RecognitionException {
		LogicAtomContext _localctx = new LogicAtomContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_logicAtom);
		try {
			setState(216);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
				enterOuterAlt(_localctx, 1);
				{
				setState(214);
				logicConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(215);
				logicVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LogicConstantContext extends ParserRuleContext {
		public TerminalNode VERILOG_BINARY() { return getToken(stlParser.VERILOG_BINARY, 0); }
		public TerminalNode GCC_BINARY() { return getToken(stlParser.GCC_BINARY, 0); }
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public TerminalNode HEX() { return getToken(stlParser.HEX, 0); }
		public LogicConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicConstant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterLogicConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitLogicConstant(this);
		}
	}

	public final LogicConstantContext logicConstant() throws RecognitionException {
		LogicConstantContext _localctx = new LogicConstantContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_logicConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(218);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 251658240L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class LogicVariableContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(stlParser.LT, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode SIGN() { return getToken(stlParser.SIGN, 0); }
		public TerminalNode COMMA() { return getToken(stlParser.COMMA, 0); }
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public LogicVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicVariable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterLogicVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitLogicVariable(this);
		}
	}

	public final LogicVariableContext logicVariable() throws RecognitionException {
		LogicVariableContext _localctx = new LogicVariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_logicVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(220);
			match(LT);
			setState(221);
			variable();
			setState(222);
			match(T__3);
			setState(223);
			match(SIGN);
			setState(224);
			match(COMMA);
			setState(225);
			match(NUMERIC);
			setState(226);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumericContext extends ParserRuleContext {
		public Token artop;
		public NumericAtomContext numericAtom() {
			return getRuleContext(NumericAtomContext.class,0);
		}
		public LogicContext logic() {
			return getRuleContext(LogicContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(stlParser.LPAREN, 0); }
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(stlParser.RPAREN, 0); }
		public TerminalNode TIMES() { return getToken(stlParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(stlParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(stlParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(stlParser.MINUS, 0); }
		public NumericContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterNumeric(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitNumeric(this);
		}
	}

	public final NumericContext numeric() throws RecognitionException {
		return numeric(0);
	}

	private NumericContext numeric(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		NumericContext _localctx = new NumericContext(_ctx, _parentState);
		NumericContext _prevctx = _localctx;
		int _startState = 30;
		enterRecursionRule(_localctx, 30, RULE_numeric, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(235);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				setState(229);
				numericAtom();
				}
				break;
			case 2:
				{
				setState(230);
				logic(0);
				}
				break;
			case 3:
				{
				setState(231);
				match(LPAREN);
				setState(232);
				numeric(0);
				setState(233);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(245);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(243);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
					case 1:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(237);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(238);
						((NumericContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==TIMES || _la==DIV) ) {
							((NumericContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(239);
						numeric(6);
						}
						break;
					case 2:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(240);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(241);
						((NumericContext)_localctx).artop = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==PLUS || _la==MINUS) ) {
							((NumericContext)_localctx).artop = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(242);
						numeric(5);
						}
						break;
					}
					} 
				}
				setState(247);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumericAtomContext extends ParserRuleContext {
		public NumericConstantContext numericConstant() {
			return getRuleContext(NumericConstantContext.class,0);
		}
		public NumericVariableContext numericVariable() {
			return getRuleContext(NumericVariableContext.class,0);
		}
		public NumericAtomContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericAtom; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterNumericAtom(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitNumericAtom(this);
		}
	}

	public final NumericAtomContext numericAtom() throws RecognitionException {
		NumericAtomContext _localctx = new NumericAtomContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_numericAtom);
		try {
			setState(250);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
				enterOuterAlt(_localctx, 1);
				{
				setState(248);
				numericConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(249);
				numericVariable();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumericConstantContext extends ParserRuleContext {
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public NumericConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericConstant; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterNumericConstant(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitNumericConstant(this);
		}
	}

	public final NumericConstantContext numericConstant() throws RecognitionException {
		NumericConstantContext _localctx = new NumericConstantContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_numericConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(252);
			match(NUMERIC);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class NumericVariableContext extends ParserRuleContext {
		public TerminalNode LT() { return getToken(stlParser.LT, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode NUMERIC() { return getToken(stlParser.NUMERIC, 0); }
		public NumericVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericVariable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterNumericVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitNumericVariable(this);
		}
	}

	public final NumericVariableContext numericVariable() throws RecognitionException {
		NumericVariableContext _localctx = new NumericVariableContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_numericVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(254);
			match(LT);
			setState(255);
			variable();
			setState(256);
			match(T__5);
			setState(257);
			match(NUMERIC);
			setState(258);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class VariableContext extends ParserRuleContext {
		public TerminalNode VARIABLE() { return getToken(stlParser.VARIABLE, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterVariable(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitVariable(this);
		}
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_variable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(260);
			match(VARIABLE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	@SuppressWarnings("CheckReturnValue")
	public static class RelopContext extends ParserRuleContext {
		public TerminalNode GT() { return getToken(stlParser.GT, 0); }
		public TerminalNode GE() { return getToken(stlParser.GE, 0); }
		public TerminalNode LT() { return getToken(stlParser.LT, 0); }
		public TerminalNode LE() { return getToken(stlParser.LE, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).enterRelop(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof stlListener ) ((stlListener)listener).exitRelop(this);
		}
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(262);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 128849018880L) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 2:
			return tformula_sempred((TformulaContext)_localctx, predIndex);
		case 6:
			return boolean_sempred((BooleanContext)_localctx, predIndex);
		case 10:
			return logic_sempred((LogicContext)_localctx, predIndex);
		case 15:
			return numeric_sempred((NumericContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean tformula_sempred(TformulaContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 3);
		case 1:
			return precpred(_ctx, 2);
		}
		return true;
	}
	private boolean boolean_sempred(BooleanContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 10);
		case 3:
			return precpred(_ctx, 7);
		case 4:
			return precpred(_ctx, 6);
		case 5:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean logic_sempred(LogicContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 9);
		case 7:
			return precpred(_ctx, 8);
		case 8:
			return precpred(_ctx, 7);
		case 9:
			return precpred(_ctx, 6);
		case 10:
			return precpred(_ctx, 5);
		case 11:
			return precpred(_ctx, 4);
		case 12:
			return precpred(_ctx, 3);
		case 13:
			return precpred(_ctx, 10);
		}
		return true;
	}
	private boolean numeric_sempred(NumericContext _localctx, int predIndex) {
		switch (predIndex) {
		case 14:
			return precpred(_ctx, 5);
		case 15:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u00010\u0109\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0002\u0010\u0007\u0010\u0002\u0011\u0007\u0011\u0002\u0012\u0007\u0012"+
		"\u0002\u0013\u0007\u0013\u0002\u0014\u0007\u0014\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0000\u0003\u0000"+
		"8\b\u0000\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002N\b\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0005\u0002"+
		"V\b\u0002\n\u0002\f\u0002Y\t\u0002\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0003\u0005h\b\u0005"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006\u008c\b\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0005\u0006\u009a\b\u0006\n\u0006\f\u0006\u009d\t\u0006\u0001\u0007\u0001"+
		"\u0007\u0003\u0007\u00a1\b\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001"+
		"\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0003\n\u00b1\b\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00ca"+
		"\b\n\n\n\f\n\u00cd\t\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0003\u000b\u00d3\b\u000b\u0001\u000b\u0001\u000b\u0001\f\u0001\f\u0003"+
		"\f\u00d9\b\f\u0001\r\u0001\r\u0001\u000e\u0001\u000e\u0001\u000e\u0001"+
		"\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000e\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0003"+
		"\u000f\u00ec\b\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001\u000f\u0001"+
		"\u000f\u0001\u000f\u0005\u000f\u00f4\b\u000f\n\u000f\f\u000f\u00f7\t\u000f"+
		"\u0001\u0010\u0001\u0010\u0003\u0010\u00fb\b\u0010\u0001\u0011\u0001\u0011"+
		"\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012\u0001\u0012"+
		"\u0001\u0013\u0001\u0013\u0001\u0014\u0001\u0014\u0001\u0014\u0000\u0004"+
		"\u0004\f\u0014\u001e\u0015\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012"+
		"\u0014\u0016\u0018\u001a\u001c\u001e \"$&(\u0000\u0004\u0001\u0000\u001f"+
		" \u0001\u0000\u001d\u001e\u0001\u0000\u0018\u001b\u0001\u0000!$\u011c"+
		"\u00007\u0001\u0000\u0000\u0000\u00029\u0001\u0000\u0000\u0000\u0004M"+
		"\u0001\u0000\u0000\u0000\u0006Z\u0001\u0000\u0000\u0000\b]\u0001\u0000"+
		"\u0000\u0000\ng\u0001\u0000\u0000\u0000\f\u008b\u0001\u0000\u0000\u0000"+
		"\u000e\u00a0\u0001\u0000\u0000\u0000\u0010\u00a2\u0001\u0000\u0000\u0000"+
		"\u0012\u00a4\u0001\u0000\u0000\u0000\u0014\u00b0\u0001\u0000\u0000\u0000"+
		"\u0016\u00ce\u0001\u0000\u0000\u0000\u0018\u00d8\u0001\u0000\u0000\u0000"+
		"\u001a\u00da\u0001\u0000\u0000\u0000\u001c\u00dc\u0001\u0000\u0000\u0000"+
		"\u001e\u00eb\u0001\u0000\u0000\u0000 \u00fa\u0001\u0000\u0000\u0000\""+
		"\u00fc\u0001\u0000\u0000\u0000$\u00fe\u0001\u0000\u0000\u0000&\u0104\u0001"+
		"\u0000\u0000\u0000(\u0106\u0001\u0000\u0000\u0000*+\u0005\t\u0000\u0000"+
		"+,\u0003\u0002\u0001\u0000,-\u0005\u0000\u0000\u0001-8\u0001\u0000\u0000"+
		"\u0000./\u0005\t\u0000\u0000/0\u0005\u0013\u0000\u000001\u0003\n\u0005"+
		"\u000012\u0005\u0014\u0000\u000023\u0005\u0015\u0000\u000034\u0003\u0002"+
		"\u0001\u000045\u0005\u0016\u0000\u000056\u0005\u0000\u0000\u000168\u0001"+
		"\u0000\u0000\u00007*\u0001\u0000\u0000\u00007.\u0001\u0000\u0000\u0000"+
		"8\u0001\u0001\u0000\u0000\u00009:\u0003\u0004\u0002\u0000:;\u0005\u000b"+
		"\u0000\u0000;<\u0003\u0004\u0002\u0000<\u0003\u0001\u0000\u0000\u0000"+
		"=>\u0006\u0002\uffff\uffff\u0000>N\u0003\f\u0006\u0000?N\u0003\u0006\u0003"+
		"\u0000@N\u0005\u0007\u0000\u0000AB\u0005\u0015\u0000\u0000BC\u0003\u0004"+
		"\u0002\u0000CD\u0005\u0016\u0000\u0000DN\u0001\u0000\u0000\u0000EF\u0005"+
		"/\u0000\u0000FN\u0003\u0004\u0002\u0004GH\u0005\b\u0000\u0000HI\u0005"+
		"\u0013\u0000\u0000IJ\u0003\n\u0005\u0000JK\u0005\u0014\u0000\u0000KL\u0003"+
		"\u0004\u0002\u0001LN\u0001\u0000\u0000\u0000M=\u0001\u0000\u0000\u0000"+
		"M?\u0001\u0000\u0000\u0000M@\u0001\u0000\u0000\u0000MA\u0001\u0000\u0000"+
		"\u0000ME\u0001\u0000\u0000\u0000MG\u0001\u0000\u0000\u0000NW\u0001\u0000"+
		"\u0000\u0000OP\n\u0003\u0000\u0000PQ\u0005-\u0000\u0000QV\u0003\u0004"+
		"\u0002\u0004RS\n\u0002\u0000\u0000ST\u0005.\u0000\u0000TV\u0003\u0004"+
		"\u0002\u0003UO\u0001\u0000\u0000\u0000UR\u0001\u0000\u0000\u0000VY\u0001"+
		"\u0000\u0000\u0000WU\u0001\u0000\u0000\u0000WX\u0001\u0000\u0000\u0000"+
		"X\u0005\u0001\u0000\u0000\u0000YW\u0001\u0000\u0000\u0000Z[\u0005\u0001"+
		"\u0000\u0000[\\\u0005\u0018\u0000\u0000\\\u0007\u0001\u0000\u0000\u0000"+
		"]^\u0005\u0002\u0000\u0000^_\u0005\u0018\u0000\u0000_\t\u0001\u0000\u0000"+
		"\u0000`a\u0003\b\u0004\u0000ab\u0005\u000e\u0000\u0000bc\u0003\b\u0004"+
		"\u0000ch\u0001\u0000\u0000\u0000de\u0005\u0018\u0000\u0000ef\u0005\u000e"+
		"\u0000\u0000fh\u0005\u0018\u0000\u0000g`\u0001\u0000\u0000\u0000gd\u0001"+
		"\u0000\u0000\u0000h\u000b\u0001\u0000\u0000\u0000ij\u0006\u0006\uffff"+
		"\uffff\u0000jk\u0005/\u0000\u0000k\u008c\u0003\f\u0006\u000flm\u0003\u0014"+
		"\n\u0000mn\u0003(\u0014\u0000no\u0003\u0014\n\u0000o\u008c\u0001\u0000"+
		"\u0000\u0000pq\u0003\u001e\u000f\u0000qr\u0003(\u0014\u0000rs\u0003\u001e"+
		"\u000f\u0000s\u008c\u0001\u0000\u0000\u0000tu\u0003\u0014\n\u0000uv\u0005"+
		"%\u0000\u0000vw\u0003\u0014\n\u0000w\u008c\u0001\u0000\u0000\u0000xy\u0003"+
		"\u001e\u000f\u0000yz\u0005%\u0000\u0000z{\u0003\u001e\u000f\u0000{\u008c"+
		"\u0001\u0000\u0000\u0000|}\u0003\u0014\n\u0000}~\u0005&\u0000\u0000~\u007f"+
		"\u0003\u0014\n\u0000\u007f\u008c\u0001\u0000\u0000\u0000\u0080\u0081\u0003"+
		"\u001e\u000f\u0000\u0081\u0082\u0005&\u0000\u0000\u0082\u0083\u0003\u001e"+
		"\u000f\u0000\u0083\u008c\u0001\u0000\u0000\u0000\u0084\u008c\u0003\u000e"+
		"\u0007\u0000\u0085\u008c\u0003\u0014\n\u0000\u0086\u008c\u0003\u001e\u000f"+
		"\u0000\u0087\u0088\u0005\u0015\u0000\u0000\u0088\u0089\u0003\f\u0006\u0000"+
		"\u0089\u008a\u0005\u0016\u0000\u0000\u008a\u008c\u0001\u0000\u0000\u0000"+
		"\u008bi\u0001\u0000\u0000\u0000\u008bl\u0001\u0000\u0000\u0000\u008bp"+
		"\u0001\u0000\u0000\u0000\u008bt\u0001\u0000\u0000\u0000\u008bx\u0001\u0000"+
		"\u0000\u0000\u008b|\u0001\u0000\u0000\u0000\u008b\u0080\u0001\u0000\u0000"+
		"\u0000\u008b\u0084\u0001\u0000\u0000\u0000\u008b\u0085\u0001\u0000\u0000"+
		"\u0000\u008b\u0086\u0001\u0000\u0000\u0000\u008b\u0087\u0001\u0000\u0000"+
		"\u0000\u008c\u009b\u0001\u0000\u0000\u0000\u008d\u008e\n\n\u0000\u0000"+
		"\u008e\u008f\u0005%\u0000\u0000\u008f\u009a\u0003\f\u0006\u000b\u0090"+
		"\u0091\n\u0007\u0000\u0000\u0091\u0092\u0005&\u0000\u0000\u0092\u009a"+
		"\u0003\f\u0006\b\u0093\u0094\n\u0006\u0000\u0000\u0094\u0095\u0005-\u0000"+
		"\u0000\u0095\u009a\u0003\f\u0006\u0007\u0096\u0097\n\u0005\u0000\u0000"+
		"\u0097\u0098\u0005.\u0000\u0000\u0098\u009a\u0003\f\u0006\u0006\u0099"+
		"\u008d\u0001\u0000\u0000\u0000\u0099\u0090\u0001\u0000\u0000\u0000\u0099"+
		"\u0093\u0001\u0000\u0000\u0000\u0099\u0096\u0001\u0000\u0000\u0000\u009a"+
		"\u009d\u0001\u0000\u0000\u0000\u009b\u0099\u0001\u0000\u0000\u0000\u009b"+
		"\u009c\u0001\u0000\u0000\u0000\u009c\r\u0001\u0000\u0000\u0000\u009d\u009b"+
		"\u0001\u0000\u0000\u0000\u009e\u00a1\u0003\u0010\b\u0000\u009f\u00a1\u0003"+
		"\u0012\t\u0000\u00a0\u009e\u0001\u0000\u0000\u0000\u00a0\u009f\u0001\u0000"+
		"\u0000\u0000\u00a1\u000f\u0001\u0000\u0000\u0000\u00a2\u00a3\u0005\u001c"+
		"\u0000\u0000\u00a3\u0011\u0001\u0000\u0000\u0000\u00a4\u00a5\u0005#\u0000"+
		"\u0000\u00a5\u00a6\u0003&\u0013\u0000\u00a6\u00a7\u0005\u0003\u0000\u0000"+
		"\u00a7\u0013\u0001\u0000\u0000\u0000\u00a8\u00a9\u0006\n\uffff\uffff\u0000"+
		"\u00a9\u00aa\u0005*\u0000\u0000\u00aa\u00b1\u0003\u0014\n\u000b\u00ab"+
		"\u00b1\u0003\u0018\f\u0000\u00ac\u00ad\u0005\u0015\u0000\u0000\u00ad\u00ae"+
		"\u0003\u0014\n\u0000\u00ae\u00af\u0005\u0016\u0000\u0000\u00af\u00b1\u0001"+
		"\u0000\u0000\u0000\u00b0\u00a8\u0001\u0000\u0000\u0000\u00b0\u00ab\u0001"+
		"\u0000\u0000\u0000\u00b0\u00ac\u0001\u0000\u0000\u0000\u00b1\u00cb\u0001"+
		"\u0000\u0000\u0000\u00b2\u00b3\n\t\u0000\u0000\u00b3\u00b4\u0007\u0000"+
		"\u0000\u0000\u00b4\u00ca\u0003\u0014\n\n\u00b5\u00b6\n\b\u0000\u0000\u00b6"+
		"\u00b7\u0007\u0001\u0000\u0000\u00b7\u00ca\u0003\u0014\n\t\u00b8\u00b9"+
		"\n\u0007\u0000\u0000\u00b9\u00ba\u0005+\u0000\u0000\u00ba\u00ca\u0003"+
		"\u0014\n\b\u00bb\u00bc\n\u0006\u0000\u0000\u00bc\u00bd\u0005,\u0000\u0000"+
		"\u00bd\u00ca\u0003\u0014\n\u0007\u00be\u00bf\n\u0005\u0000\u0000\u00bf"+
		"\u00c0\u0005\'\u0000\u0000\u00c0\u00ca\u0003\u0014\n\u0006\u00c1\u00c2"+
		"\n\u0004\u0000\u0000\u00c2\u00c3\u0005)\u0000\u0000\u00c3\u00ca\u0003"+
		"\u0014\n\u0005\u00c4\u00c5\n\u0003\u0000\u0000\u00c5\u00c6\u0005(\u0000"+
		"\u0000\u00c6\u00ca\u0003\u0014\n\u0004\u00c7\u00c8\n\n\u0000\u0000\u00c8"+
		"\u00ca\u0003\u0016\u000b\u0000\u00c9\u00b2\u0001\u0000\u0000\u0000\u00c9"+
		"\u00b5\u0001\u0000\u0000\u0000\u00c9\u00b8\u0001\u0000\u0000\u0000\u00c9"+
		"\u00bb\u0001\u0000\u0000\u0000\u00c9\u00be\u0001\u0000\u0000\u0000\u00c9"+
		"\u00c1\u0001\u0000\u0000\u0000\u00c9\u00c4\u0001\u0000\u0000\u0000\u00c9"+
		"\u00c7\u0001\u0000\u0000\u0000\u00ca\u00cd\u0001\u0000\u0000\u0000\u00cb"+
		"\u00c9\u0001\u0000\u0000\u0000\u00cb\u00cc\u0001\u0000\u0000\u0000\u00cc"+
		"\u0015\u0001\u0000\u0000\u0000\u00cd\u00cb\u0001\u0000\u0000\u0000\u00ce"+
		"\u00cf\u0005\u0013\u0000\u0000\u00cf\u00d2\u0005\u0018\u0000\u0000\u00d0"+
		"\u00d1\u0005\r\u0000\u0000\u00d1\u00d3\u0005\u0018\u0000\u0000\u00d2\u00d0"+
		"\u0001\u0000\u0000\u0000\u00d2\u00d3\u0001\u0000\u0000\u0000\u00d3\u00d4"+
		"\u0001\u0000\u0000\u0000\u00d4\u00d5\u0005\u0014\u0000\u0000\u00d5\u0017"+
		"\u0001\u0000\u0000\u0000\u00d6\u00d9\u0003\u001a\r\u0000\u00d7\u00d9\u0003"+
		"\u001c\u000e\u0000\u00d8\u00d6\u0001\u0000\u0000\u0000\u00d8\u00d7\u0001"+
		"\u0000\u0000\u0000\u00d9\u0019\u0001\u0000\u0000\u0000\u00da\u00db\u0007"+
		"\u0002\u0000\u0000\u00db\u001b\u0001\u0000\u0000\u0000\u00dc\u00dd\u0005"+
		"#\u0000\u0000\u00dd\u00de\u0003&\u0013\u0000\u00de\u00df\u0005\u0004\u0000"+
		"\u0000\u00df\u00e0\u0005\u0010\u0000\u0000\u00e0\u00e1\u0005\u000e\u0000"+
		"\u0000\u00e1\u00e2\u0005\u0018\u0000\u0000\u00e2\u00e3\u0005\u0005\u0000"+
		"\u0000\u00e3\u001d\u0001\u0000\u0000\u0000\u00e4\u00e5\u0006\u000f\uffff"+
		"\uffff\u0000\u00e5\u00ec\u0003 \u0010\u0000\u00e6\u00ec\u0003\u0014\n"+
		"\u0000\u00e7\u00e8\u0005\u0015\u0000\u0000\u00e8\u00e9\u0003\u001e\u000f"+
		"\u0000\u00e9\u00ea\u0005\u0016\u0000\u0000\u00ea\u00ec\u0001\u0000\u0000"+
		"\u0000\u00eb\u00e4\u0001\u0000\u0000\u0000\u00eb\u00e6\u0001\u0000\u0000"+
		"\u0000\u00eb\u00e7\u0001\u0000\u0000\u0000\u00ec\u00f5\u0001\u0000\u0000"+
		"\u0000\u00ed\u00ee\n\u0005\u0000\u0000\u00ee\u00ef\u0007\u0000\u0000\u0000"+
		"\u00ef\u00f4\u0003\u001e\u000f\u0006\u00f0\u00f1\n\u0004\u0000\u0000\u00f1"+
		"\u00f2\u0007\u0001\u0000\u0000\u00f2\u00f4\u0003\u001e\u000f\u0005\u00f3"+
		"\u00ed\u0001\u0000\u0000\u0000\u00f3\u00f0\u0001\u0000\u0000\u0000\u00f4"+
		"\u00f7\u0001\u0000\u0000\u0000\u00f5\u00f3\u0001\u0000\u0000\u0000\u00f5"+
		"\u00f6\u0001\u0000\u0000\u0000\u00f6\u001f\u0001\u0000\u0000\u0000\u00f7"+
		"\u00f5\u0001\u0000\u0000\u0000\u00f8\u00fb\u0003\"\u0011\u0000\u00f9\u00fb"+
		"\u0003$\u0012\u0000\u00fa\u00f8\u0001\u0000\u0000\u0000\u00fa\u00f9\u0001"+
		"\u0000\u0000\u0000\u00fb!\u0001\u0000\u0000\u0000\u00fc\u00fd\u0005\u0018"+
		"\u0000\u0000\u00fd#\u0001\u0000\u0000\u0000\u00fe\u00ff\u0005#\u0000\u0000"+
		"\u00ff\u0100\u0003&\u0013\u0000\u0100\u0101\u0005\u0006\u0000\u0000\u0101"+
		"\u0102\u0005\u0018\u0000\u0000\u0102\u0103\u0005\u0005\u0000\u0000\u0103"+
		"%\u0001\u0000\u0000\u0000\u0104\u0105\u0005\u0017\u0000\u0000\u0105\'"+
		"\u0001\u0000\u0000\u0000\u0106\u0107\u0007\u0003\u0000\u0000\u0107)\u0001"+
		"\u0000\u0000\u0000\u00127MUWg\u008b\u0099\u009b\u00a0\u00b0\u00c9\u00cb"+
		"\u00d2\u00d8\u00eb\u00f3\u00f5\u00fa";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}