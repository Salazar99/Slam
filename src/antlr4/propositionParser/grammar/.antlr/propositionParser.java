// Generated from /home/magister/Slam/src/antlr4/propositionParser/grammar/proposition.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue"})
public class propositionParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, SIGN=8, DER=9, 
		LCPAREN=10, RCPAREN=11, LPAREN=12, RPAREN=13, VARIABLE=14, NUMERIC=15, 
		VERILOG_BINARY=16, GCC_BINARY=17, HEX=18, BOOLEAN=19, PLUS=20, MINUS=21, 
		TIMES=22, DIV=23, GT=24, GE=25, LT=26, LE=27, EQ=28, NEQ=29, BAND=30, 
		BOR=31, BXOR=32, NEG=33, LSHIFT=34, RSHIFT=35, AND=36, OR=37, NOT=38, 
		WS=39;
	public static final int
		RULE_file = 0, RULE_boolean = 1, RULE_booleanAtom = 2, RULE_booleanConstant = 3, 
		RULE_booleanVariable = 4, RULE_logic = 5, RULE_bitSelect = 6, RULE_logicAtom = 7, 
		RULE_logicConstant = 8, RULE_logicVariable = 9, RULE_numeric = 10, RULE_numericAtom = 11, 
		RULE_numericConstant = 12, RULE_numericVariable = 13, RULE_variable = 14, 
		RULE_relop = 15;
	private static String[] makeRuleNames() {
		return new String[] {
			"file", "boolean", "booleanAtom", "booleanConstant", "booleanVariable", 
			"logic", "bitSelect", "logicAtom", "logicConstant", "logicVariable", 
			"numeric", "numericAtom", "numericConstant", "numericVariable", "variable", 
			"relop"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'{'", "',bool}'", "','", "':'", "',logic_'", "'}'", "',numeric'", 
			null, "'@'", "'['", "']'", "'('", "')'", null, null, null, null, null, 
			null, "'+'", "'-'", "'*'", "'/'", "'>'", "'>='", "'<'", "'<='", "'=='", 
			"'!='", "'&'", "'|'", "'^'", "'~'", "'<<'", "'>>'", "'&&'", "'||'", "'!'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, "SIGN", "DER", "LCPAREN", 
			"RCPAREN", "LPAREN", "RPAREN", "VARIABLE", "NUMERIC", "VERILOG_BINARY", 
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
	public String getGrammarFileName() { return "proposition.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public propositionParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@SuppressWarnings("CheckReturnValue")
	public static class FileContext extends ParserRuleContext {
		public BooleanContext boolean_() {
			return getRuleContext(BooleanContext.class,0);
		}
		public TerminalNode EOF() { return getToken(propositionParser.EOF, 0); }
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
			setState(32);
			boolean_(0);
			setState(33);
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
	public static class BooleanContext extends ParserRuleContext {
		public Token booleanop;
		public TerminalNode NOT() { return getToken(propositionParser.NOT, 0); }
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
		public TerminalNode EQ() { return getToken(propositionParser.EQ, 0); }
		public TerminalNode NEQ() { return getToken(propositionParser.NEQ, 0); }
		public BooleanAtomContext booleanAtom() {
			return getRuleContext(BooleanAtomContext.class,0);
		}
		public TerminalNode LPAREN() { return getToken(propositionParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(propositionParser.RPAREN, 0); }
		public TerminalNode AND() { return getToken(propositionParser.AND, 0); }
		public TerminalNode OR() { return getToken(propositionParser.OR, 0); }
		public BooleanContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_boolean; }
	}

	public final BooleanContext boolean_() throws RecognitionException {
		return boolean_(0);
	}

	private BooleanContext boolean_(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		BooleanContext _localctx = new BooleanContext(_ctx, _parentState);
		BooleanContext _prevctx = _localctx;
		int _startState = 2;
		enterRecursionRule(_localctx, 2, RULE_boolean, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(69);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
			case 1:
				{
				setState(36);
				match(NOT);
				setState(37);
				boolean_(15);
				}
				break;
			case 2:
				{
				setState(38);
				logic(0);
				setState(39);
				relop();
				setState(40);
				logic(0);
				}
				break;
			case 3:
				{
				setState(42);
				numeric(0);
				setState(43);
				relop();
				setState(44);
				numeric(0);
				}
				break;
			case 4:
				{
				setState(46);
				logic(0);
				setState(47);
				match(EQ);
				setState(48);
				logic(0);
				}
				break;
			case 5:
				{
				setState(50);
				numeric(0);
				setState(51);
				match(EQ);
				setState(52);
				numeric(0);
				}
				break;
			case 6:
				{
				setState(54);
				logic(0);
				setState(55);
				match(NEQ);
				setState(56);
				logic(0);
				}
				break;
			case 7:
				{
				setState(58);
				numeric(0);
				setState(59);
				match(NEQ);
				setState(60);
				numeric(0);
				}
				break;
			case 8:
				{
				setState(62);
				booleanAtom();
				}
				break;
			case 9:
				{
				setState(63);
				logic(0);
				}
				break;
			case 10:
				{
				setState(64);
				numeric(0);
				}
				break;
			case 11:
				{
				setState(65);
				match(LPAREN);
				setState(66);
				boolean_(0);
				setState(67);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(85);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(83);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
					case 1:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(71);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(72);
						match(EQ);
						setState(73);
						boolean_(11);
						}
						break;
					case 2:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(74);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(75);
						match(NEQ);
						setState(76);
						boolean_(8);
						}
						break;
					case 3:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(77);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(78);
						((BooleanContext)_localctx).booleanop = match(AND);
						setState(79);
						boolean_(7);
						}
						break;
					case 4:
						{
						_localctx = new BooleanContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_boolean);
						setState(80);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(81);
						((BooleanContext)_localctx).booleanop = match(OR);
						setState(82);
						boolean_(6);
						}
						break;
					}
					} 
				}
				setState(87);
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
	}

	public final BooleanAtomContext booleanAtom() throws RecognitionException {
		BooleanAtomContext _localctx = new BooleanAtomContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_booleanAtom);
		try {
			setState(90);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOLEAN:
				enterOuterAlt(_localctx, 1);
				{
				setState(88);
				booleanConstant();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 2);
				{
				setState(89);
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
		public TerminalNode BOOLEAN() { return getToken(propositionParser.BOOLEAN, 0); }
		public BooleanConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanConstant; }
	}

	public final BooleanConstantContext booleanConstant() throws RecognitionException {
		BooleanConstantContext _localctx = new BooleanConstantContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_booleanConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(92);
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
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public BooleanVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_booleanVariable; }
	}

	public final BooleanVariableContext booleanVariable() throws RecognitionException {
		BooleanVariableContext _localctx = new BooleanVariableContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_booleanVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(94);
			match(T__0);
			setState(95);
			variable();
			setState(96);
			match(T__1);
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
		public TerminalNode NEG() { return getToken(propositionParser.NEG, 0); }
		public List<LogicContext> logic() {
			return getRuleContexts(LogicContext.class);
		}
		public LogicContext logic(int i) {
			return getRuleContext(LogicContext.class,i);
		}
		public TerminalNode DER() { return getToken(propositionParser.DER, 0); }
		public TerminalNode LPAREN() { return getToken(propositionParser.LPAREN, 0); }
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public TerminalNode RPAREN() { return getToken(propositionParser.RPAREN, 0); }
		public LogicAtomContext logicAtom() {
			return getRuleContext(LogicAtomContext.class,0);
		}
		public TerminalNode TIMES() { return getToken(propositionParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(propositionParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(propositionParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(propositionParser.MINUS, 0); }
		public TerminalNode LSHIFT() { return getToken(propositionParser.LSHIFT, 0); }
		public TerminalNode RSHIFT() { return getToken(propositionParser.RSHIFT, 0); }
		public TerminalNode BAND() { return getToken(propositionParser.BAND, 0); }
		public TerminalNode BXOR() { return getToken(propositionParser.BXOR, 0); }
		public TerminalNode BOR() { return getToken(propositionParser.BOR, 0); }
		public BitSelectContext bitSelect() {
			return getRuleContext(BitSelectContext.class,0);
		}
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
		int _startState = 10;
		enterRecursionRule(_localctx, 10, RULE_logic, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NEG:
				{
				setState(99);
				match(NEG);
				setState(100);
				logic(12);
				}
				break;
			case DER:
				{
				setState(101);
				match(DER);
				setState(102);
				match(LPAREN);
				setState(103);
				logic(0);
				setState(104);
				match(T__2);
				setState(105);
				match(NUMERIC);
				setState(106);
				match(RPAREN);
				}
				break;
			case T__0:
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
				{
				setState(108);
				logicAtom();
				}
				break;
			case LPAREN:
				{
				setState(109);
				match(LPAREN);
				setState(110);
				logic(0);
				setState(111);
				match(RPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(140);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,6,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(138);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
					case 1:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(115);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(116);
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
						setState(117);
						logic(10);
						}
						break;
					case 2:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(118);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(119);
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
						setState(120);
						logic(9);
						}
						break;
					case 3:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(121);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(122);
						((LogicContext)_localctx).logop = match(LSHIFT);
						setState(123);
						logic(8);
						}
						break;
					case 4:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(124);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(125);
						((LogicContext)_localctx).logop = match(RSHIFT);
						setState(126);
						logic(7);
						}
						break;
					case 5:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(127);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(128);
						((LogicContext)_localctx).logop = match(BAND);
						setState(129);
						logic(6);
						}
						break;
					case 6:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(130);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(131);
						((LogicContext)_localctx).logop = match(BXOR);
						setState(132);
						logic(5);
						}
						break;
					case 7:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(133);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(134);
						((LogicContext)_localctx).logop = match(BOR);
						setState(135);
						logic(4);
						}
						break;
					case 8:
						{
						_localctx = new LogicContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_logic);
						setState(136);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(137);
						bitSelect();
						}
						break;
					}
					} 
				}
				setState(142);
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
	public static class BitSelectContext extends ParserRuleContext {
		public TerminalNode LCPAREN() { return getToken(propositionParser.LCPAREN, 0); }
		public List<TerminalNode> NUMERIC() { return getTokens(propositionParser.NUMERIC); }
		public TerminalNode NUMERIC(int i) {
			return getToken(propositionParser.NUMERIC, i);
		}
		public TerminalNode RCPAREN() { return getToken(propositionParser.RCPAREN, 0); }
		public BitSelectContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_bitSelect; }
	}

	public final BitSelectContext bitSelect() throws RecognitionException {
		BitSelectContext _localctx = new BitSelectContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_bitSelect);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(143);
			match(LCPAREN);
			setState(144);
			match(NUMERIC);
			setState(147);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==T__3) {
				{
				setState(145);
				match(T__3);
				setState(146);
				match(NUMERIC);
				}
			}

			setState(149);
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
	}

	public final LogicAtomContext logicAtom() throws RecognitionException {
		LogicAtomContext _localctx = new LogicAtomContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_logicAtom);
		try {
			setState(153);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
			case VERILOG_BINARY:
			case GCC_BINARY:
			case HEX:
				enterOuterAlt(_localctx, 1);
				{
				setState(151);
				logicConstant();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 2);
				{
				setState(152);
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
		public TerminalNode VERILOG_BINARY() { return getToken(propositionParser.VERILOG_BINARY, 0); }
		public TerminalNode GCC_BINARY() { return getToken(propositionParser.GCC_BINARY, 0); }
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public TerminalNode HEX() { return getToken(propositionParser.HEX, 0); }
		public LogicConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicConstant; }
	}

	public final LogicConstantContext logicConstant() throws RecognitionException {
		LogicConstantContext _localctx = new LogicConstantContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_logicConstant);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(155);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & 491520L) != 0)) ) {
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
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode SIGN() { return getToken(propositionParser.SIGN, 0); }
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public LogicVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicVariable; }
	}

	public final LogicVariableContext logicVariable() throws RecognitionException {
		LogicVariableContext _localctx = new LogicVariableContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_logicVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(157);
			match(T__0);
			setState(158);
			variable();
			setState(159);
			match(T__4);
			setState(160);
			match(SIGN);
			setState(161);
			match(NUMERIC);
			setState(162);
			match(T__5);
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
		public TerminalNode DER() { return getToken(propositionParser.DER, 0); }
		public TerminalNode LPAREN() { return getToken(propositionParser.LPAREN, 0); }
		public List<NumericContext> numeric() {
			return getRuleContexts(NumericContext.class);
		}
		public NumericContext numeric(int i) {
			return getRuleContext(NumericContext.class,i);
		}
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public TerminalNode RPAREN() { return getToken(propositionParser.RPAREN, 0); }
		public NumericAtomContext numericAtom() {
			return getRuleContext(NumericAtomContext.class,0);
		}
		public LogicContext logic() {
			return getRuleContext(LogicContext.class,0);
		}
		public TerminalNode TIMES() { return getToken(propositionParser.TIMES, 0); }
		public TerminalNode DIV() { return getToken(propositionParser.DIV, 0); }
		public TerminalNode PLUS() { return getToken(propositionParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(propositionParser.MINUS, 0); }
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
		int _startState = 20;
		enterRecursionRule(_localctx, 20, RULE_numeric, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(178);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				{
				setState(165);
				match(DER);
				setState(166);
				match(LPAREN);
				setState(167);
				numeric(0);
				setState(168);
				match(T__2);
				setState(169);
				match(NUMERIC);
				setState(170);
				match(RPAREN);
				}
				break;
			case 2:
				{
				setState(172);
				numericAtom();
				}
				break;
			case 3:
				{
				setState(173);
				logic(0);
				}
				break;
			case 4:
				{
				setState(174);
				match(LPAREN);
				setState(175);
				numeric(0);
				setState(176);
				match(RPAREN);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(188);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,11,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(186);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
					case 1:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(180);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(181);
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
						setState(182);
						numeric(6);
						}
						break;
					case 2:
						{
						_localctx = new NumericContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_numeric);
						setState(183);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(184);
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
						setState(185);
						numeric(5);
						}
						break;
					}
					} 
				}
				setState(190);
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
		enterRule(_localctx, 22, RULE_numericAtom);
		try {
			setState(193);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUMERIC:
				enterOuterAlt(_localctx, 1);
				{
				setState(191);
				numericConstant();
				}
				break;
			case T__0:
				enterOuterAlt(_localctx, 2);
				{
				setState(192);
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
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public NumericConstantContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericConstant; }
	}

	public final NumericConstantContext numericConstant() throws RecognitionException {
		NumericConstantContext _localctx = new NumericConstantContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_numericConstant);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(195);
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
		public VariableContext variable() {
			return getRuleContext(VariableContext.class,0);
		}
		public TerminalNode NUMERIC() { return getToken(propositionParser.NUMERIC, 0); }
		public NumericVariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_numericVariable; }
	}

	public final NumericVariableContext numericVariable() throws RecognitionException {
		NumericVariableContext _localctx = new NumericVariableContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_numericVariable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(197);
			match(T__0);
			setState(198);
			variable();
			setState(199);
			match(T__6);
			setState(200);
			match(NUMERIC);
			setState(201);
			match(T__5);
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
		public TerminalNode VARIABLE() { return getToken(propositionParser.VARIABLE, 0); }
		public VariableContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_variable; }
	}

	public final VariableContext variable() throws RecognitionException {
		VariableContext _localctx = new VariableContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_variable);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(203);
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
		public TerminalNode GT() { return getToken(propositionParser.GT, 0); }
		public TerminalNode GE() { return getToken(propositionParser.GE, 0); }
		public TerminalNode LT() { return getToken(propositionParser.LT, 0); }
		public TerminalNode LE() { return getToken(propositionParser.LE, 0); }
		public RelopContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relop; }
	}

	public final RelopContext relop() throws RecognitionException {
		RelopContext _localctx = new RelopContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_relop);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(205);
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

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 1:
			return boolean_sempred((BooleanContext)_localctx, predIndex);
		case 5:
			return logic_sempred((LogicContext)_localctx, predIndex);
		case 10:
			return numeric_sempred((NumericContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean boolean_sempred(BooleanContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 10);
		case 1:
			return precpred(_ctx, 7);
		case 2:
			return precpred(_ctx, 6);
		case 3:
			return precpred(_ctx, 5);
		}
		return true;
	}
	private boolean logic_sempred(LogicContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 9);
		case 5:
			return precpred(_ctx, 8);
		case 6:
			return precpred(_ctx, 7);
		case 7:
			return precpred(_ctx, 6);
		case 8:
			return precpred(_ctx, 5);
		case 9:
			return precpred(_ctx, 4);
		case 10:
			return precpred(_ctx, 3);
		case 11:
			return precpred(_ctx, 11);
		}
		return true;
	}
	private boolean numeric_sempred(NumericContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 5);
		case 13:
			return precpred(_ctx, 4);
		}
		return true;
	}

	public static final String _serializedATN =
		"\u0004\u0001\'\u00d0\u0002\u0000\u0007\u0000\u0002\u0001\u0007\u0001\u0002"+
		"\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004\u0007\u0004\u0002"+
		"\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007\u0007\u0007\u0002"+
		"\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b\u0007\u000b\u0002"+
		"\f\u0007\f\u0002\r\u0007\r\u0002\u000e\u0007\u000e\u0002\u000f\u0007\u000f"+
		"\u0001\u0000\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0003\u0001F\b\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001\u0001"+
		"\u0001\u0001\u0001\u0001\u0001\u0001\u0005\u0001T\b\u0001\n\u0001\f\u0001"+
		"W\t\u0001\u0001\u0002\u0001\u0002\u0003\u0002[\b\u0002\u0001\u0003\u0001"+
		"\u0003\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0004\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0003\u0005r\b\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001\u0005\u0001"+
		"\u0005\u0001\u0005\u0001\u0005\u0005\u0005\u008b\b\u0005\n\u0005\f\u0005"+
		"\u008e\t\u0005\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0003\u0006"+
		"\u0094\b\u0006\u0001\u0006\u0001\u0006\u0001\u0007\u0001\u0007\u0003\u0007"+
		"\u009a\b\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\t\u0001\t\u0001\t"+
		"\u0001\t\u0001\t\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001"+
		"\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0003\n\u00b3"+
		"\b\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0001\n\u0005\n\u00bb\b\n"+
		"\n\n\f\n\u00be\t\n\u0001\u000b\u0001\u000b\u0003\u000b\u00c2\b\u000b\u0001"+
		"\f\u0001\f\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\r\u0001\u000e"+
		"\u0001\u000e\u0001\u000f\u0001\u000f\u0001\u000f\u0000\u0003\u0002\n\u0014"+
		"\u0010\u0000\u0002\u0004\u0006\b\n\f\u000e\u0010\u0012\u0014\u0016\u0018"+
		"\u001a\u001c\u001e\u0000\u0004\u0001\u0000\u0016\u0017\u0001\u0000\u0014"+
		"\u0015\u0001\u0000\u000f\u0012\u0001\u0000\u0018\u001b\u00e1\u0000 \u0001"+
		"\u0000\u0000\u0000\u0002E\u0001\u0000\u0000\u0000\u0004Z\u0001\u0000\u0000"+
		"\u0000\u0006\\\u0001\u0000\u0000\u0000\b^\u0001\u0000\u0000\u0000\nq\u0001"+
		"\u0000\u0000\u0000\f\u008f\u0001\u0000\u0000\u0000\u000e\u0099\u0001\u0000"+
		"\u0000\u0000\u0010\u009b\u0001\u0000\u0000\u0000\u0012\u009d\u0001\u0000"+
		"\u0000\u0000\u0014\u00b2\u0001\u0000\u0000\u0000\u0016\u00c1\u0001\u0000"+
		"\u0000\u0000\u0018\u00c3\u0001\u0000\u0000\u0000\u001a\u00c5\u0001\u0000"+
		"\u0000\u0000\u001c\u00cb\u0001\u0000\u0000\u0000\u001e\u00cd\u0001\u0000"+
		"\u0000\u0000 !\u0003\u0002\u0001\u0000!\"\u0005\u0000\u0000\u0001\"\u0001"+
		"\u0001\u0000\u0000\u0000#$\u0006\u0001\uffff\uffff\u0000$%\u0005&\u0000"+
		"\u0000%F\u0003\u0002\u0001\u000f&\'\u0003\n\u0005\u0000\'(\u0003\u001e"+
		"\u000f\u0000()\u0003\n\u0005\u0000)F\u0001\u0000\u0000\u0000*+\u0003\u0014"+
		"\n\u0000+,\u0003\u001e\u000f\u0000,-\u0003\u0014\n\u0000-F\u0001\u0000"+
		"\u0000\u0000./\u0003\n\u0005\u0000/0\u0005\u001c\u0000\u000001\u0003\n"+
		"\u0005\u00001F\u0001\u0000\u0000\u000023\u0003\u0014\n\u000034\u0005\u001c"+
		"\u0000\u000045\u0003\u0014\n\u00005F\u0001\u0000\u0000\u000067\u0003\n"+
		"\u0005\u000078\u0005\u001d\u0000\u000089\u0003\n\u0005\u00009F\u0001\u0000"+
		"\u0000\u0000:;\u0003\u0014\n\u0000;<\u0005\u001d\u0000\u0000<=\u0003\u0014"+
		"\n\u0000=F\u0001\u0000\u0000\u0000>F\u0003\u0004\u0002\u0000?F\u0003\n"+
		"\u0005\u0000@F\u0003\u0014\n\u0000AB\u0005\f\u0000\u0000BC\u0003\u0002"+
		"\u0001\u0000CD\u0005\r\u0000\u0000DF\u0001\u0000\u0000\u0000E#\u0001\u0000"+
		"\u0000\u0000E&\u0001\u0000\u0000\u0000E*\u0001\u0000\u0000\u0000E.\u0001"+
		"\u0000\u0000\u0000E2\u0001\u0000\u0000\u0000E6\u0001\u0000\u0000\u0000"+
		"E:\u0001\u0000\u0000\u0000E>\u0001\u0000\u0000\u0000E?\u0001\u0000\u0000"+
		"\u0000E@\u0001\u0000\u0000\u0000EA\u0001\u0000\u0000\u0000FU\u0001\u0000"+
		"\u0000\u0000GH\n\n\u0000\u0000HI\u0005\u001c\u0000\u0000IT\u0003\u0002"+
		"\u0001\u000bJK\n\u0007\u0000\u0000KL\u0005\u001d\u0000\u0000LT\u0003\u0002"+
		"\u0001\bMN\n\u0006\u0000\u0000NO\u0005$\u0000\u0000OT\u0003\u0002\u0001"+
		"\u0007PQ\n\u0005\u0000\u0000QR\u0005%\u0000\u0000RT\u0003\u0002\u0001"+
		"\u0006SG\u0001\u0000\u0000\u0000SJ\u0001\u0000\u0000\u0000SM\u0001\u0000"+
		"\u0000\u0000SP\u0001\u0000\u0000\u0000TW\u0001\u0000\u0000\u0000US\u0001"+
		"\u0000\u0000\u0000UV\u0001\u0000\u0000\u0000V\u0003\u0001\u0000\u0000"+
		"\u0000WU\u0001\u0000\u0000\u0000X[\u0003\u0006\u0003\u0000Y[\u0003\b\u0004"+
		"\u0000ZX\u0001\u0000\u0000\u0000ZY\u0001\u0000\u0000\u0000[\u0005\u0001"+
		"\u0000\u0000\u0000\\]\u0005\u0013\u0000\u0000]\u0007\u0001\u0000\u0000"+
		"\u0000^_\u0005\u0001\u0000\u0000_`\u0003\u001c\u000e\u0000`a\u0005\u0002"+
		"\u0000\u0000a\t\u0001\u0000\u0000\u0000bc\u0006\u0005\uffff\uffff\u0000"+
		"cd\u0005!\u0000\u0000dr\u0003\n\u0005\fef\u0005\t\u0000\u0000fg\u0005"+
		"\f\u0000\u0000gh\u0003\n\u0005\u0000hi\u0005\u0003\u0000\u0000ij\u0005"+
		"\u000f\u0000\u0000jk\u0005\r\u0000\u0000kr\u0001\u0000\u0000\u0000lr\u0003"+
		"\u000e\u0007\u0000mn\u0005\f\u0000\u0000no\u0003\n\u0005\u0000op\u0005"+
		"\r\u0000\u0000pr\u0001\u0000\u0000\u0000qb\u0001\u0000\u0000\u0000qe\u0001"+
		"\u0000\u0000\u0000ql\u0001\u0000\u0000\u0000qm\u0001\u0000\u0000\u0000"+
		"r\u008c\u0001\u0000\u0000\u0000st\n\t\u0000\u0000tu\u0007\u0000\u0000"+
		"\u0000u\u008b\u0003\n\u0005\nvw\n\b\u0000\u0000wx\u0007\u0001\u0000\u0000"+
		"x\u008b\u0003\n\u0005\tyz\n\u0007\u0000\u0000z{\u0005\"\u0000\u0000{\u008b"+
		"\u0003\n\u0005\b|}\n\u0006\u0000\u0000}~\u0005#\u0000\u0000~\u008b\u0003"+
		"\n\u0005\u0007\u007f\u0080\n\u0005\u0000\u0000\u0080\u0081\u0005\u001e"+
		"\u0000\u0000\u0081\u008b\u0003\n\u0005\u0006\u0082\u0083\n\u0004\u0000"+
		"\u0000\u0083\u0084\u0005 \u0000\u0000\u0084\u008b\u0003\n\u0005\u0005"+
		"\u0085\u0086\n\u0003\u0000\u0000\u0086\u0087\u0005\u001f\u0000\u0000\u0087"+
		"\u008b\u0003\n\u0005\u0004\u0088\u0089\n\u000b\u0000\u0000\u0089\u008b"+
		"\u0003\f\u0006\u0000\u008as\u0001\u0000\u0000\u0000\u008av\u0001\u0000"+
		"\u0000\u0000\u008ay\u0001\u0000\u0000\u0000\u008a|\u0001\u0000\u0000\u0000"+
		"\u008a\u007f\u0001\u0000\u0000\u0000\u008a\u0082\u0001\u0000\u0000\u0000"+
		"\u008a\u0085\u0001\u0000\u0000\u0000\u008a\u0088\u0001\u0000\u0000\u0000"+
		"\u008b\u008e\u0001\u0000\u0000\u0000\u008c\u008a\u0001\u0000\u0000\u0000"+
		"\u008c\u008d\u0001\u0000\u0000\u0000\u008d\u000b\u0001\u0000\u0000\u0000"+
		"\u008e\u008c\u0001\u0000\u0000\u0000\u008f\u0090\u0005\n\u0000\u0000\u0090"+
		"\u0093\u0005\u000f\u0000\u0000\u0091\u0092\u0005\u0004\u0000\u0000\u0092"+
		"\u0094\u0005\u000f\u0000\u0000\u0093\u0091\u0001\u0000\u0000\u0000\u0093"+
		"\u0094\u0001\u0000\u0000\u0000\u0094\u0095\u0001\u0000\u0000\u0000\u0095"+
		"\u0096\u0005\u000b\u0000\u0000\u0096\r\u0001\u0000\u0000\u0000\u0097\u009a"+
		"\u0003\u0010\b\u0000\u0098\u009a\u0003\u0012\t\u0000\u0099\u0097\u0001"+
		"\u0000\u0000\u0000\u0099\u0098\u0001\u0000\u0000\u0000\u009a\u000f\u0001"+
		"\u0000\u0000\u0000\u009b\u009c\u0007\u0002\u0000\u0000\u009c\u0011\u0001"+
		"\u0000\u0000\u0000\u009d\u009e\u0005\u0001\u0000\u0000\u009e\u009f\u0003"+
		"\u001c\u000e\u0000\u009f\u00a0\u0005\u0005\u0000\u0000\u00a0\u00a1\u0005"+
		"\b\u0000\u0000\u00a1\u00a2\u0005\u000f\u0000\u0000\u00a2\u00a3\u0005\u0006"+
		"\u0000\u0000\u00a3\u0013\u0001\u0000\u0000\u0000\u00a4\u00a5\u0006\n\uffff"+
		"\uffff\u0000\u00a5\u00a6\u0005\t\u0000\u0000\u00a6\u00a7\u0005\f\u0000"+
		"\u0000\u00a7\u00a8\u0003\u0014\n\u0000\u00a8\u00a9\u0005\u0003\u0000\u0000"+
		"\u00a9\u00aa\u0005\u000f\u0000\u0000\u00aa\u00ab\u0005\r\u0000\u0000\u00ab"+
		"\u00b3\u0001\u0000\u0000\u0000\u00ac\u00b3\u0003\u0016\u000b\u0000\u00ad"+
		"\u00b3\u0003\n\u0005\u0000\u00ae\u00af\u0005\f\u0000\u0000\u00af\u00b0"+
		"\u0003\u0014\n\u0000\u00b0\u00b1\u0005\r\u0000\u0000\u00b1\u00b3\u0001"+
		"\u0000\u0000\u0000\u00b2\u00a4\u0001\u0000\u0000\u0000\u00b2\u00ac\u0001"+
		"\u0000\u0000\u0000\u00b2\u00ad\u0001\u0000\u0000\u0000\u00b2\u00ae\u0001"+
		"\u0000\u0000\u0000\u00b3\u00bc\u0001\u0000\u0000\u0000\u00b4\u00b5\n\u0005"+
		"\u0000\u0000\u00b5\u00b6\u0007\u0000\u0000\u0000\u00b6\u00bb\u0003\u0014"+
		"\n\u0006\u00b7\u00b8\n\u0004\u0000\u0000\u00b8\u00b9\u0007\u0001\u0000"+
		"\u0000\u00b9\u00bb\u0003\u0014\n\u0005\u00ba\u00b4\u0001\u0000\u0000\u0000"+
		"\u00ba\u00b7\u0001\u0000\u0000\u0000\u00bb\u00be\u0001\u0000\u0000\u0000"+
		"\u00bc\u00ba\u0001\u0000\u0000\u0000\u00bc\u00bd\u0001\u0000\u0000\u0000"+
		"\u00bd\u0015\u0001\u0000\u0000\u0000\u00be\u00bc\u0001\u0000\u0000\u0000"+
		"\u00bf\u00c2\u0003\u0018\f\u0000\u00c0\u00c2\u0003\u001a\r\u0000\u00c1"+
		"\u00bf\u0001\u0000\u0000\u0000\u00c1\u00c0\u0001\u0000\u0000\u0000\u00c2"+
		"\u0017\u0001\u0000\u0000\u0000\u00c3\u00c4\u0005\u000f\u0000\u0000\u00c4"+
		"\u0019\u0001\u0000\u0000\u0000\u00c5\u00c6\u0005\u0001\u0000\u0000\u00c6"+
		"\u00c7\u0003\u001c\u000e\u0000\u00c7\u00c8\u0005\u0007\u0000\u0000\u00c8"+
		"\u00c9\u0005\u000f\u0000\u0000\u00c9\u00ca\u0005\u0006\u0000\u0000\u00ca"+
		"\u001b\u0001\u0000\u0000\u0000\u00cb\u00cc\u0005\u000e\u0000\u0000\u00cc"+
		"\u001d\u0001\u0000\u0000\u0000\u00cd\u00ce\u0007\u0003\u0000\u0000\u00ce"+
		"\u001f\u0001\u0000\u0000\u0000\rESUZq\u008a\u008c\u0093\u0099\u00b2\u00ba"+
		"\u00bc\u00c1";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}