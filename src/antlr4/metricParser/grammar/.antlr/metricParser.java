// Generated from /home/magister/Slam/src/antlr4/metricParser/grammar/metric.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class metricParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, SIGN=5, LGPAREN=6, RGPAREN=7, LCPAREN=8, 
		RCPAREN=9, LPAREN=10, RPAREN=11, VARIABLE=12, INDEX=13, NUMERIC=14, VERILOG_BINARY=15, 
		GCC_BINARY=16, HEX=17, BOOLEAN=18, PLUS=19, MINUS=20, TIMES=21, DIV=22, 
		GT=23, GE=24, LT=25, LE=26, EQ=27, NEQ=28, BAND=29, BOR=30, BXOR=31, NEG=32, 
		LSHIFT=33, RSHIFT=34, AND=35, OR=36, NOT=37, WS=38;
	public static final int
		RULE_file = 0, RULE_logic = 1, RULE_logicAtom = 2, RULE_logicConstant = 3, 
		RULE_logicVariable = 4, RULE_numeric = 5, RULE_numericAtom = 6, RULE_numericConstant = 7, 
		RULE_numericVariable = 8, RULE_variable = 9, RULE_relop = 10;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "logic", "logicAtom", "logicConstant", "logicVariable", "numeric", 
			"numericAtom", "numericConstant", "numericVariable", "variable", "relop"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "',logic('", "','", "')>'", "',numeric('", null, "'{'", "'}'", 
			"'['", "']'", "'('", "')'", null, null, null, null, null, null, null, 
			"'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", 
			"'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", "'!'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, "SIGN", "LGPAREN", "RGPAREN", "LCPAREN", 
			"RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "INDEX", "NUMERIC", "VERILOG_BINARY", 
			"GCC_BINARY", "HEX", "BOOLEAN", "PLUS", "MINUS", "TIMES", "DIV", "GT", 
			"GE", "LT", "LE", "EQ", "NEQ", "BAND", "BOR", "BXOR", "NEG", "LSHIFT", 
			"RSHIFT", "AND", "OR", "NOT", "WS"
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
	public String getGrammarFileName() { return "metric.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public metricParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FileContext extends ParserRuleContext {
		public NumericContext numeric() {
			return getRuleContext(NumericContext.class,0);
		}
		public TerminalNode EOF() { return getToken(metricParser.EOF, 0); }
		public FileContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_file; }
	}

	public final FileContext file() throws RecognitionException {
		FileContext _localctx = new FileContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_file);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			numeric(0);
			setState(23);
			match(EOF);
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
		public Token logop;
		public TerminalNode NEG() { return getToken(metricParser.NEG, 0); }
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public LogicAtomContext logicAtom() {
			return getRuleContext(LogicAtomContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(metricParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(metricParser.RPAREN, 0); }
		public TerminalNode LSHIFT() { return getToken(metricParser.LSHIFT, 0); }
		public TerminalNode RSHIFT() { return getToken(metricParser.RSHIFT, 0); }
		public TerminalNode BAND() { return getToken(metricParser.BAND, 0); }
		public TerminalNode BXOR() { return getToken(metricParser.BXOR, 0); }
		public TerminalNode BOR() { return getToken(metricParser.BOR, 0); }
		public LogicContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logic; }
	}

	public final LogicContext logic() throws RecognitionException {
		return logic(0);
	}

	private LogicContext logic(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicContext _localctx = new LogicContext(_ctx, _parentState);
		LogicContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_logic, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(33);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NEG:
				{
				setState(26);
				match(NEG);
				setState(27);
				logic(8);
				}
				break;
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
			case LT:
				{
				setState(28);
				logicAtom();
				}
				break;
			case LPAREN:
				{
				setState(29);
				match(LPAREN);
				setState(30);
				logic(0);
				setState(31);
				match(RPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(52);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(50);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(35);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(36);
						((LogicContext)_localctx).logop = match(LSHIFT);
						setState(37);
						logic(8);
						}
						break;
					case 2:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(38);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(39);
						((LogicContext)_localctx).logop = match(RSHIFT);
						setState(40);
						logic(7);
						}
						break;
					case 3:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(41);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(42);
						((LogicContext)_localctx).logop = match(BAND);
						setState(43);
						logic(6);
						}
						break;
					case 4:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(44);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(45);
						((LogicContext)_localctx).logop = match(BXOR);
						setState(46);
						logic(5);
						}
						break;
					case 5:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(47);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(48);
						((LogicContext)_localctx).logop = match(BOR);
						setState(49);
						logic(4);
						}
						break;
					}
					} 
				}
				setState(54);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
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
	}

	public final LogicAtomContext logicAtom() throws RecognitionException {
		LogicAtomContext _localctx = new LogicAtomContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_logicAtom);
		try {
			setState(57);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
				enterOuterAlt(_localctx, 1);
				{
				setState(55);
				logicConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(56);
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
		public TerminalNode VERILOG_BINARY() { return getToken(metricParser.VERILOG_BINARY, 0); }
		public TerminalNode GCC_BINARY() { return getToken(metricParser.GCC_BINARY, 0); }
		public TerminalNode NUMERIC() { return getToken(metricParser.NUMERIC, 0); }
		public TerminalNode HEX() { return getToken(metricParser.HEX, 0); }
		public LogicConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicConstant; }
	}

	public final LogicConstantContext logicConstant() throws RecognitionException {
		LogicConstantContext _localctx = new LogicConstantContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_logicConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(59);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 245760L) != 0)) ) {
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
		public TerminalNode LT() { return getToken(metricParser.LT, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode SIGN() { return getToken(metricParser.SIGN, 0); }
		public TerminalNode NUMERIC() { return getToken(metricParser.NUMERIC, 0); }
		public LogicVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicVariable; }
	}

	public final LogicVariableContext logicVariable() throws RecognitionException {
		LogicVariableContext _localctx = new LogicVariableContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_logicVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			match(LT);
			setState(62);
			variable();
			setState(63);
			match(T__0);
			setState(64);
			match(SIGN);
			setState(65);
			match(T__1);
			setState(66);
			match(NUMERIC);
			setState(67);
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
	public static class NumericContext extends ParserRuleContext {
		public Token artop;
		public NumericAtomContext numericAtom() {
			return getRuleContext(NumericAtomContext.class,0);
		}
		public LogicContext logic() {
			return getRuleContext(LogicContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(metricParser.LPAREN, 0); }
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode RPAREN() { return getToken(metricParser.RPAREN, 0); }
		public TerminalNode TIMES() { return getToken(metricParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(metricParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(metricParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(metricParser.MINUS, 0); }
		public NumericContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numeric; }
	}

	public final NumericContext numeric() throws RecognitionException {
		return numeric(0);
	}

	private NumericContext numeric(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		NumericContext _localctx = new NumericContext(_ctx, _parentState);
		NumericContext _prevctx = _localctx;
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_numeric, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(76);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				{
				setState(70);
				numericAtom();
				}
				break;
			case 2:
				{
				setState(71);
				logic(0);
				}
				break;
			case 3:
				{
				setState(72);
				match(LPAREN);
				setState(73);
				numeric(0);
				setState(74);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(86);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(84);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(78);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(79);
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
						setState(80);
						numeric(6);
						}
						break;
					case 2:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(81);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(82);
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
						setState(83);
						numeric(5);
						}
						break;
					}
					} 
				}
				setState(88);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
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
	}

	public final NumericAtomContext numericAtom() throws RecognitionException {
		NumericAtomContext _localctx = new NumericAtomContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_numericAtom);
		try {
			setState(91);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
				enterOuterAlt(_localctx, 1);
				{
				setState(89);
				numericConstant();
				}
				break;
			case LT:
				enterOuterAlt(_localctx, 2);
				{
				setState(90);
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
		public TerminalNode NUMERIC() { return getToken(metricParser.NUMERIC, 0); }
		public NumericConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericConstant; }
	}

	public final NumericConstantContext numericConstant() throws RecognitionException {
		NumericConstantContext _localctx = new NumericConstantContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_numericConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
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
		public TerminalNode LT() { return getToken(metricParser.LT, 0); }
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode NUMERIC() { return getToken(metricParser.NUMERIC, 0); }
		public NumericVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericVariable; }
	}

	public final NumericVariableContext numericVariable() throws RecognitionException {
		NumericVariableContext _localctx = new NumericVariableContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_numericVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(95);
			match(LT);
			setState(96);
			variable();
			setState(97);
			match(T__3);
			setState(98);
			match(NUMERIC);
			setState(99);
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
	public static class VariableContext extends ParserRuleContext {
		public TerminalNode VARIABLE() { return getToken(metricParser.VARIABLE, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_variable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(101);
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
		public TerminalNode GT() { return getToken(metricParser.GT, 0); }
		public TerminalNode GE() { return getToken(metricParser.GE, 0); }
		public TerminalNode LT() { return getToken(metricParser.LT, 0); }
		public TerminalNode LE() { return getToken(metricParser.LE, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(103);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 125829120L) != 0)) ) {
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
		case 1:
			return logic_sempred((LogicContext)_localctx, predIndex);
		case 5:
			return numeric_sempred((NumericContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean logic_sempred(LogicContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 7);
		case 1:
			return precpred(_ctx, 6);
		case 2:
			return precpred(_ctx, 5);
		case 3:
			return precpred(_ctx, 4);
		case 4:
			return precpred(_ctx, 3);
		}
		return true;
	}
	private boolean numeric_sempred(NumericContext _localctx, int predIndex) {
		switch (predIndex) {
		case 5:
			return precpred(_ctx, 5);
		case 6:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001&j\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002\u0002"+
		"\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002\u0005"+
		"\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002\b\u0007"+
		"\b\u0002\t\u0007\t\u0002\n\u0007\n\u0001\u0000\u0001\u0000\u0001\u0000"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0003\u0001\"\b\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0005\u00013\b\u0001\n\u0001\f\u00016\t\u0001\u0001\u0002"+
		"\u0001\u0002\u0003\u0002:\b\u0002\u0001\u0003\u0001\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0003\u0005M\b\u0005\u0001\u0005\u0001\u0005"+
		"\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0005\u0005U\b\u0005"+
		"\n\u0005\f\u0005X\t\u0005\u0001\u0006\u0001\u0006\u0003\u0006\\\b\u0006"+
		"\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\b\u0001\b\u0001\b\u0001"+
		"\b\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0000\u0002\u0002\n\u000b\u0000"+
		"\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0000\u0004\u0001\u0000"+
		"\u000e\u0011\u0001\u0000\u0015\u0016\u0001\u0000\u0013\u0014\u0001\u0000"+
		"\u0017\u001ak\u0000\u0016\u0001\u0000\u0000\u0000\u0002!\u0001\u0000\u0000"+
		"\u0000\u00049\u0001\u0000\u0000\u0000\u0006;\u0001\u0000\u0000\u0000\b"+
		"=\u0001\u0000\u0000\u0000\nL\u0001\u0000\u0000\u0000\f[\u0001\u0000\u0000"+
		"\u0000\u000e]\u0001\u0000\u0000\u0000\u0010_\u0001\u0000\u0000\u0000\u0012"+
		"e\u0001\u0000\u0000\u0000\u0014g\u0001\u0000\u0000\u0000\u0016\u0017\u0003"+
		"\n\u0005\u0000\u0017\u0018\u0005\u0000\u0000\u0001\u0018\u0001\u0001\u0000"+
		"\u0000\u0000\u0019\u001a\u0006\u0001\uffff\uffff\u0000\u001a\u001b\u0005"+
		" \u0000\u0000\u001b\"\u0003\u0002\u0001\b\u001c\"\u0003\u0004\u0002\u0000"+
		"\u001d\u001e\u0005\n\u0000\u0000\u001e\u001f\u0003\u0002\u0001\u0000\u001f"+
		" \u0005\u000b\u0000\u0000 \"\u0001\u0000\u0000\u0000!\u0019\u0001\u0000"+
		"\u0000\u0000!\u001c\u0001\u0000\u0000\u0000!\u001d\u0001\u0000\u0000\u0000"+
		"\"4\u0001\u0000\u0000\u0000#$\n\u0007\u0000\u0000$%\u0005!\u0000\u0000"+
		"%3\u0003\u0002\u0001\b&\'\n\u0006\u0000\u0000\'(\u0005\"\u0000\u0000("+
		"3\u0003\u0002\u0001\u0007)*\n\u0005\u0000\u0000*+\u0005\u001d\u0000\u0000"+
		"+3\u0003\u0002\u0001\u0006,-\n\u0004\u0000\u0000-.\u0005\u001f\u0000\u0000"+
		".3\u0003\u0002\u0001\u0005/0\n\u0003\u0000\u000001\u0005\u001e\u0000\u0000"+
		"13\u0003\u0002\u0001\u00042#\u0001\u0000\u0000\u00002&\u0001\u0000\u0000"+
		"\u00002)\u0001\u0000\u0000\u00002,\u0001\u0000\u0000\u00002/\u0001\u0000"+
		"\u0000\u000036\u0001\u0000\u0000\u000042\u0001\u0000\u0000\u000045\u0001"+
		"\u0000\u0000\u00005\u0003\u0001\u0000\u0000\u000064\u0001\u0000\u0000"+
		"\u00007:\u0003\u0006\u0003\u00008:\u0003\b\u0004\u000097\u0001\u0000\u0000"+
		"\u000098\u0001\u0000\u0000\u0000:\u0005\u0001\u0000\u0000\u0000;<\u0007"+
		"\u0000\u0000\u0000<\u0007\u0001\u0000\u0000\u0000=>\u0005\u0019\u0000"+
		"\u0000>?\u0003\u0012\t\u0000?@\u0005\u0001\u0000\u0000@A\u0005\u0005\u0000"+
		"\u0000AB\u0005\u0002\u0000\u0000BC\u0005\u000e\u0000\u0000CD\u0005\u0003"+
		"\u0000\u0000D\t\u0001\u0000\u0000\u0000EF\u0006\u0005\uffff\uffff\u0000"+
		"FM\u0003\f\u0006\u0000GM\u0003\u0002\u0001\u0000HI\u0005\n\u0000\u0000"+
		"IJ\u0003\n\u0005\u0000JK\u0005\u000b\u0000\u0000KM\u0001\u0000\u0000\u0000"+
		"LE\u0001\u0000\u0000\u0000LG\u0001\u0000\u0000\u0000LH\u0001\u0000\u0000"+
		"\u0000MV\u0001\u0000\u0000\u0000NO\n\u0005\u0000\u0000OP\u0007\u0001\u0000"+
		"\u0000PU\u0003\n\u0005\u0006QR\n\u0004\u0000\u0000RS\u0007\u0002\u0000"+
		"\u0000SU\u0003\n\u0005\u0005TN\u0001\u0000\u0000\u0000TQ\u0001\u0000\u0000"+
		"\u0000UX\u0001\u0000\u0000\u0000VT\u0001\u0000\u0000\u0000VW\u0001\u0000"+
		"\u0000\u0000W\u000b\u0001\u0000\u0000\u0000XV\u0001\u0000\u0000\u0000"+
		"Y\\\u0003\u000e\u0007\u0000Z\\\u0003\u0010\b\u0000[Y\u0001\u0000\u0000"+
		"\u0000[Z\u0001\u0000\u0000\u0000\\\r\u0001\u0000\u0000\u0000]^\u0005\u000e"+
		"\u0000\u0000^\u000f\u0001\u0000\u0000\u0000_`\u0005\u0019\u0000\u0000"+
		"`a\u0003\u0012\t\u0000ab\u0005\u0004\u0000\u0000bc\u0005\u000e\u0000\u0000"+
		"cd\u0005\u0003\u0000\u0000d\u0011\u0001\u0000\u0000\u0000ef\u0005\f\u0000"+
		"\u0000f\u0013\u0001\u0000\u0000\u0000gh\u0007\u0003\u0000\u0000h\u0015"+
		"\u0001\u0000\u0000\u0000\b!249LTV[";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}