grammar stl;
import proposition;

file : STL_ALWAYS formula EOF
| STL_ALWAYS LCPAREN interval COMMA interval RCPAREN LPAREN formula RPAREN EOF
;


formula : tformula IMPL tformula;

tformula: boolean | placeholder | DT_AND
	| LPAREN tformula RPAREN 
	| NOT tformula 
	| tformula AND tformula 
	| tformula OR tformula 
    | STL_EVENTUALLY LCPAREN interval COMMA interval RCPAREN tformula
	;

placeholder: 'P' NUMERIC ;

interval: 'X' NUMERIC 
        | boolean
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
	