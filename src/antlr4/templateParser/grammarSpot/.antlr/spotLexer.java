// Generated from /mnt/c/Users/danni/Desktop/Ex-harm/src/antlr4/templateParser/grammarSpot/spot.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class spotLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, DT_AND=7, SEP=8, EVENTUALLY=9, 
		ALWAYS=10, NEXT=11, UNTIL=12, RELEASE=13, DOTS=14, IMPL=15, IMPL2=16, 
		IFF=17, XOR=18, BIND1=19, BIND2=20, SEREIMPL1=21, SEREIMPL2=22, ASS=23, 
		DELAY=24, SCOL=25, COL=26, FIRST_MATCH=27;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "DT_AND", "SEP", "EVENTUALLY", 
			"ALWAYS", "NEXT", "UNTIL", "RELEASE", "DOTS", "IMPL", "IMPL2", "IFF", 
			"XOR", "BIND1", "BIND2", "SEREIMPL1", "SEREIMPL2", "ASS", "DELAY", "SCOL", 
			"COL", "FIRST_MATCH"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'P'", "'..##'", "'..#'", "'&'", "'..[->'", "']'", "'..&&..'", 
			null, "'F'", "'G'", "'X'", "'U'", "'R'", "'..'", "'->'", "'=>'", "'<->'", 
			"'xor'", "'[]->'", "'[]=>'", "'|->'", "'|=>'", "'='", "'##'", "';'", 
			"':'", "'first_match'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, "DT_AND", "SEP", "EVENTUALLY", 
			"ALWAYS", "NEXT", "UNTIL", "RELEASE", "DOTS", "IMPL", "IMPL2", "IFF", 
			"XOR", "BIND1", "BIND2", "SEREIMPL1", "SEREIMPL2", "ASS", "DELAY", "SCOL", 
			"COL", "FIRST_MATCH"
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


	public spotLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "spot.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\35\u009d\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3"+
		"\4\3\4\3\4\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\b\3\b\3\b\3\b\3\b"+
		"\3\b\3\b\3\t\3\t\3\t\3\t\5\tZ\n\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3"+
		"\16\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\22\3"+
		"\22\3\23\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\3"+
		"\25\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\30\3\30\3\31\3\31\3\31\3"+
		"\32\3\32\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3"+
		"\34\3\34\2\2\35\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31"+
		"\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65"+
		"\34\67\35\3\2\2\2\u009d\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2"+
		"\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2"+
		"\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3"+
		"\2\2\2\39\3\2\2\2\5;\3\2\2\2\7@\3\2\2\2\tD\3\2\2\2\13F\3\2\2\2\rL\3\2"+
		"\2\2\17N\3\2\2\2\21Y\3\2\2\2\23[\3\2\2\2\25]\3\2\2\2\27_\3\2\2\2\31a\3"+
		"\2\2\2\33c\3\2\2\2\35e\3\2\2\2\37h\3\2\2\2!k\3\2\2\2#n\3\2\2\2%r\3\2\2"+
		"\2\'v\3\2\2\2){\3\2\2\2+\u0080\3\2\2\2-\u0084\3\2\2\2/\u0088\3\2\2\2\61"+
		"\u008a\3\2\2\2\63\u008d\3\2\2\2\65\u008f\3\2\2\2\67\u0091\3\2\2\29:\7"+
		"R\2\2:\4\3\2\2\2;<\7\60\2\2<=\7\60\2\2=>\7%\2\2>?\7%\2\2?\6\3\2\2\2@A"+
		"\7\60\2\2AB\7\60\2\2BC\7%\2\2C\b\3\2\2\2DE\7(\2\2E\n\3\2\2\2FG\7\60\2"+
		"\2GH\7\60\2\2HI\7]\2\2IJ\7/\2\2JK\7@\2\2K\f\3\2\2\2LM\7_\2\2M\16\3\2\2"+
		"\2NO\7\60\2\2OP\7\60\2\2PQ\7(\2\2QR\7(\2\2RS\7\60\2\2ST\7\60\2\2T\20\3"+
		"\2\2\2UV\7B\2\2VZ\7<\2\2WX\7B\2\2XZ\7=\2\2YU\3\2\2\2YW\3\2\2\2Z\22\3\2"+
		"\2\2[\\\7H\2\2\\\24\3\2\2\2]^\7I\2\2^\26\3\2\2\2_`\7Z\2\2`\30\3\2\2\2"+
		"ab\7W\2\2b\32\3\2\2\2cd\7T\2\2d\34\3\2\2\2ef\7\60\2\2fg\7\60\2\2g\36\3"+
		"\2\2\2hi\7/\2\2ij\7@\2\2j \3\2\2\2kl\7?\2\2lm\7@\2\2m\"\3\2\2\2no\7>\2"+
		"\2op\7/\2\2pq\7@\2\2q$\3\2\2\2rs\7z\2\2st\7q\2\2tu\7t\2\2u&\3\2\2\2vw"+
		"\7]\2\2wx\7_\2\2xy\7/\2\2yz\7@\2\2z(\3\2\2\2{|\7]\2\2|}\7_\2\2}~\7?\2"+
		"\2~\177\7@\2\2\177*\3\2\2\2\u0080\u0081\7~\2\2\u0081\u0082\7/\2\2\u0082"+
		"\u0083\7@\2\2\u0083,\3\2\2\2\u0084\u0085\7~\2\2\u0085\u0086\7?\2\2\u0086"+
		"\u0087\7@\2\2\u0087.\3\2\2\2\u0088\u0089\7?\2\2\u0089\60\3\2\2\2\u008a"+
		"\u008b\7%\2\2\u008b\u008c\7%\2\2\u008c\62\3\2\2\2\u008d\u008e\7=\2\2\u008e"+
		"\64\3\2\2\2\u008f\u0090\7<\2\2\u0090\66\3\2\2\2\u0091\u0092\7h\2\2\u0092"+
		"\u0093\7k\2\2\u0093\u0094\7t\2\2\u0094\u0095\7u\2\2\u0095\u0096\7v\2\2"+
		"\u0096\u0097\7a\2\2\u0097\u0098\7o\2\2\u0098\u0099\7c\2\2\u0099\u009a"+
		"\7v\2\2\u009a\u009b\7e\2\2\u009b\u009c\7j\2\2\u009c8\3\2\2\2\4\2Y\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}