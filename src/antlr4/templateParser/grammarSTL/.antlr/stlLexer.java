// Generated from /mnt/c/Users/danni/Desktop/Ex-harm/src/antlr4/templateParser/grammarSTL/stl.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class stlLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, DT_AND=3, STL_EVENTUALLY=4, STL_ALWAYS=5, RELEASE=6, IMPL=7, 
		SCOL=8, COL=9, COMMA=10, FIRST_MATCH=11;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "DT_AND", "STL_EVENTUALLY", "STL_ALWAYS", "RELEASE", 
			"IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'P'", "'X'", "'..&&..'", "'F'", "'G'", "'release'", "'->'", "';'", 
			"':'", "','", "'first_match'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, "DT_AND", "STL_EVENTUALLY", "STL_ALWAYS", "RELEASE", 
			"IMPL", "SCOL", "COL", "COMMA", "FIRST_MATCH"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\rE\b\1\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\3\2\3\2\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\6\3"+
		"\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3"+
		"\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\2\2\r\3\3\5\4\7\5"+
		"\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\3\2\2\2D\2\3\3\2\2\2\2\5\3\2\2"+
		"\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21"+
		"\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\3\31\3\2\2\2\5\33\3\2"+
		"\2\2\7\35\3\2\2\2\t$\3\2\2\2\13&\3\2\2\2\r(\3\2\2\2\17\60\3\2\2\2\21\63"+
		"\3\2\2\2\23\65\3\2\2\2\25\67\3\2\2\2\279\3\2\2\2\31\32\7R\2\2\32\4\3\2"+
		"\2\2\33\34\7Z\2\2\34\6\3\2\2\2\35\36\7\60\2\2\36\37\7\60\2\2\37 \7(\2"+
		"\2 !\7(\2\2!\"\7\60\2\2\"#\7\60\2\2#\b\3\2\2\2$%\7H\2\2%\n\3\2\2\2&\'"+
		"\7I\2\2\'\f\3\2\2\2()\7t\2\2)*\7g\2\2*+\7n\2\2+,\7g\2\2,-\7c\2\2-.\7u"+
		"\2\2./\7g\2\2/\16\3\2\2\2\60\61\7/\2\2\61\62\7@\2\2\62\20\3\2\2\2\63\64"+
		"\7=\2\2\64\22\3\2\2\2\65\66\7<\2\2\66\24\3\2\2\2\678\7.\2\28\26\3\2\2"+
		"\29:\7h\2\2:;\7k\2\2;<\7t\2\2<=\7u\2\2=>\7v\2\2>?\7a\2\2?@\7o\2\2@A\7"+
		"c\2\2AB\7v\2\2BC\7e\2\2CD\7j\2\2D\30\3\2\2\2\3\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}