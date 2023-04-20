grammar stl;
import proposition;

file : STL_ALWAYS formula EOF
| STL_ALWAYS LCPAREN interval RCPAREN LPAREN formula RPAREN EOF
;


formula : tformula IMPL tformula;

tformula: boolean | placeholder | DT_AND
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


DT_AND
    : '..&&..'
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
	