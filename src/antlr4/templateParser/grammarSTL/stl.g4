grammar stl;
import proposition;

file : STL_ALWAYS formula EOF
| STL_ALWAYS LPAREN formula RPAREN EOF;



formula : tantecendent IMPL tconsequent;

tantecendent : F LCPAREN NUMERIC RCPAREN tformula | tantecendent && tantecendent;

tconsequent : F LCPAREN NUMERIC RCPAREN placeholder;

tformula: boolean | placeholder | DT_AND
	| LPAREN tformula RPAREN 
	| NOT tformula 
	| tformula AND tformula 
	| tformula OR tformula 
	| tformula XOR tformula 
	;

placeholder: 'P' NUMERIC ;

EVENTUALLY
    : 'eventually'
    ;
STL_ALWAYS
    : 'always'
    ;
NEXT
    : 'nexttime'
    ;
UNTIL
    : 'until'
    ;

RELEASE
    : 'release'
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
	
