grammar stl;
import proposition;

file : STL_ALWAYS LPAREN implication RPAREN EOF
| STL_ALWAYS LCPAREN interval RCPAREN LPAREN implication RPAREN EOF
;


implication :
 DT_ANDF IMPL STL_EVENTUALLY LCPAREN interval RCPAREN tformula |
 tformula IMPL STL_EVENTUALLY LCPAREN interval RCPAREN tformula
;

tformula: boolean | placeholder
	| LPAREN tformula RPAREN 
	| NOT tformula 
	| tformula AND tformula 
	| tformula OR tformula 
    | STL_EVENTUALLY LCPAREN interval RCPAREN tformula
	;

placeholder: 'P' NUMERIC ;

interval_placeholder: 'X' NUMERIC;

interval: interval_placeholder COMMA interval_placeholder 
        | NUMERIC COMMA NUMERIC
        ;


DT_ANDF
    : '('? '..F..' ')'?
    ;

STL_EVENTUALLY: 'F'; 

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

COMMA 
    : ','
    ;

FIRST_MATCH
	:
'first_match'
	;
	
