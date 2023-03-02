D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"


/* Ne g�re pas les commentaires. A rajouter */
/* Supprimer les lignes dont vous n'avez pas besoin. */

%}

%%
"break"                 { return BREAK; }
"case"                  { return CASE; }
"default"               { return DEFAULT; }
"else"                  { return ELSE; }
"extern"                { return EXTERN; }
"for"                   { return FOR; }
"if"                    { return IF; }
"int"                   { return INT; }
"return"                { return RETURN; }
"switch"                { return SWITCH; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

{L}({L}|{D})*           { /* A completer */ }

0[xX]{H}+{IS}?          { /* A completer */ }
0{D}+{IS}?              { /* A completer */ }
{D}+{IS}?               { /* A completer */ }
L?'(\\.|[^\\'])+'       { /* A completer */ }

{D}+{E}{FS}?            { /* A completer */ }

L?\"(\\.|[^\\"])*\"     { /* A completer */ }


"&="                    { return BAND;}
"|="                    { return BOR;}
">>"                    { return RSHIFT;}
"<<"                    { return LSHIFT;}
"&&"                    { return LAND;}
"||"                    { return LOR;}
"<="                    { return LEQ;}
">="                    { return GEQ;}
"=="                    { return EQ;}
"!="                    { return NEQ;}
">"                     { return GT;}
"<"                     { return LT;}
"!"                     { return NOT;} 

"+"                     { return PLUS;}
"-"                     { return MOINS;}
"*"                     { return MUL;}
"/"                     { return DIV;}

[ \t\v\n\f]             { /* A completer */ }
.                       { return yytext[0]; }
%%