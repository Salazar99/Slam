// Generated from /home/magister/Slam/src/antlr4/templateParser/grammarSTL/stl.g4 by ANTLR 4.13.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast", "CheckReturnValue", "this-escape"})
public class stlLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.13.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, DT_ANDF=3, DT_ANDG=4, STL_EVENTUALLY=5, STL_ALWAYS=6, 
		RELEASE=7, IMPL=8, SCOL=9, COL=10, COMMA=11, FIRST_MATCH=12;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "DT_ANDF", "DT_ANDG", "STL_EVENTUALLY", "STL_ALWAYS", 
			"RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'P'", "'X'", null, null, "'F'", "'G'", "'release'", "'->'", "';'", 
			"':'", "','", "'first_match'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "DT_ANDF", "DT_ANDG", "STL_EVENTUALLY", "STL_ALWAYS", 
			"RELEASE", "IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH"
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


	public stlLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "stl.g4"; }

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
		"\u0004\u0000\fV\u0006\uffff\uffff\u0002\u0000\u0007\u0000\u0002\u0001"+
		"\u0007\u0001\u0002\u0002\u0007\u0002\u0002\u0003\u0007\u0003\u0002\u0004"+
		"\u0007\u0004\u0002\u0005\u0007\u0005\u0002\u0006\u0007\u0006\u0002\u0007"+
		"\u0007\u0007\u0002\b\u0007\b\u0002\t\u0007\t\u0002\n\u0007\n\u0002\u000b"+
		"\u0007\u000b\u0001\u0000\u0001\u0000\u0001\u0001\u0001\u0001\u0001\u0002"+
		"\u0003\u0002\u001f\b\u0002\u0001\u0002\u0001\u0002\u0001\u0002\u0001\u0002"+
		"\u0001\u0002\u0001\u0002\u0001\u0002\u0003\u0002(\b\u0002\u0001\u0003"+
		"\u0003\u0003+\b\u0003\u0001\u0003\u0001\u0003\u0001\u0003\u0001\u0003"+
		"\u0001\u0003\u0001\u0003\u0001\u0003\u0003\u00034\b\u0003\u0001\u0004"+
		"\u0001\u0004\u0001\u0005\u0001\u0005\u0001\u0006\u0001\u0006\u0001\u0006"+
		"\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0006\u0001\u0007"+
		"\u0001\u0007\u0001\u0007\u0001\b\u0001\b\u0001\t\u0001\t\u0001\n\u0001"+
		"\n\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b\u0001\u000b"+
		"\u0000\u0000\f\u0001\u0001\u0003\u0002\u0005\u0003\u0007\u0004\t\u0005"+
		"\u000b\u0006\r\u0007\u000f\b\u0011\t\u0013\n\u0015\u000b\u0017\f\u0001"+
		"\u0000\u0000Y\u0000\u0001\u0001\u0000\u0000\u0000\u0000\u0003\u0001\u0000"+
		"\u0000\u0000\u0000\u0005\u0001\u0000\u0000\u0000\u0000\u0007\u0001\u0000"+
		"\u0000\u0000\u0000\t\u0001\u0000\u0000\u0000\u0000\u000b\u0001\u0000\u0000"+
		"\u0000\u0000\r\u0001\u0000\u0000\u0000\u0000\u000f\u0001\u0000\u0000\u0000"+
		"\u0000\u0011\u0001\u0000\u0000\u0000\u0000\u0013\u0001\u0000\u0000\u0000"+
		"\u0000\u0015\u0001\u0000\u0000\u0000\u0000\u0017\u0001\u0000\u0000\u0000"+
		"\u0001\u0019\u0001\u0000\u0000\u0000\u0003\u001b\u0001\u0000\u0000\u0000"+
		"\u0005\u001e\u0001\u0000\u0000\u0000\u0007*\u0001\u0000\u0000\u0000\t"+
		"5\u0001\u0000\u0000\u0000\u000b7\u0001\u0000\u0000\u0000\r9\u0001\u0000"+
		"\u0000\u0000\u000fA\u0001\u0000\u0000\u0000\u0011D\u0001\u0000\u0000\u0000"+
		"\u0013F\u0001\u0000\u0000\u0000\u0015H\u0001\u0000\u0000\u0000\u0017J"+
		"\u0001\u0000\u0000\u0000\u0019\u001a\u0005P\u0000\u0000\u001a\u0002\u0001"+
		"\u0000\u0000\u0000\u001b\u001c\u0005X\u0000\u0000\u001c\u0004\u0001\u0000"+
		"\u0000\u0000\u001d\u001f\u0005(\u0000\u0000\u001e\u001d\u0001\u0000\u0000"+
		"\u0000\u001e\u001f\u0001\u0000\u0000\u0000\u001f \u0001\u0000\u0000\u0000"+
		" !\u0005.\u0000\u0000!\"\u0005.\u0000\u0000\"#\u0005F\u0000\u0000#$\u0005"+
		".\u0000\u0000$%\u0005.\u0000\u0000%\'\u0001\u0000\u0000\u0000&(\u0005"+
		")\u0000\u0000\'&\u0001\u0000\u0000\u0000\'(\u0001\u0000\u0000\u0000(\u0006"+
		"\u0001\u0000\u0000\u0000)+\u0005(\u0000\u0000*)\u0001\u0000\u0000\u0000"+
		"*+\u0001\u0000\u0000\u0000+,\u0001\u0000\u0000\u0000,-\u0005.\u0000\u0000"+
		"-.\u0005.\u0000\u0000./\u0005G\u0000\u0000/0\u0005.\u0000\u000001\u0005"+
		".\u0000\u000013\u0001\u0000\u0000\u000024\u0005)\u0000\u000032\u0001\u0000"+
		"\u0000\u000034\u0001\u0000\u0000\u00004\b\u0001\u0000\u0000\u000056\u0005"+
		"F\u0000\u00006\n\u0001\u0000\u0000\u000078\u0005G\u0000\u00008\f\u0001"+
		"\u0000\u0000\u00009:\u0005r\u0000\u0000:;\u0005e\u0000\u0000;<\u0005l"+
		"\u0000\u0000<=\u0005e\u0000\u0000=>\u0005a\u0000\u0000>?\u0005s\u0000"+
		"\u0000?@\u0005e\u0000\u0000@\u000e\u0001\u0000\u0000\u0000AB\u0005-\u0000"+
		"\u0000BC\u0005>\u0000\u0000C\u0010\u0001\u0000\u0000\u0000DE\u0005;\u0000"+
		"\u0000E\u0012\u0001\u0000\u0000\u0000FG\u0005:\u0000\u0000G\u0014\u0001"+
		"\u0000\u0000\u0000HI\u0005,\u0000\u0000I\u0016\u0001\u0000\u0000\u0000"+
		"JK\u0005f\u0000\u0000KL\u0005i\u0000\u0000LM\u0005r\u0000\u0000MN\u0005"+
		"s\u0000\u0000NO\u0005t\u0000\u0000OP\u0005_\u0000\u0000PQ\u0005m\u0000"+
		"\u0000QR\u0005a\u0000\u0000RS\u0005t\u0000\u0000ST\u0005c\u0000\u0000"+
		"TU\u0005h\u0000\u0000U\u0018\u0001\u0000\u0000\u0000\u0005\u0000\u001e"+
		"\'*3\u0000";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}