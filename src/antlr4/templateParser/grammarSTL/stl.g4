grammar stl;
import proposition;

file : STL_ALWAYS formula EOF
| STL_ALWAYS LPAREN formula RPAREN EOF;



formula : tantecendent IMPL tconsequent;

tantecendent : EVENTUALLY LCPAREN NUMERIC RCPAREN tformula | tantecendent AND tantecendent;

tconsequent : EVENTUALLY LCPAREN NUMERIC RCPAREN placeholder;

tformula: boolean | placeholder | AND
	| LPAREN tformula RPAREN 
	| NOT tformula 
	| tformula AND tformula 
	| tformula OR tformula 
	;

placeholder: 'P' NUMERIC ;

EVENTUALLY: 'F';

STL_ALWAYS
    : 'G'
    ;

RELEASE
    : 'release'
    ;

IMPL
    : '->'
    ;

SCOL
    : ';'
    ;

COL
    : ':'
    ;

FIRST_MATCH
	:
'first_match'
	;
	
