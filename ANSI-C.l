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
"break"                 { /* A completer */ }
"case"                  { /* A completer */ }
"const"                 { /* A completer */ }
"default"               { /* A completer */ }
"else"                  { /* A completer */ }
"extern"                { /* A completer */ }
"for"                   { /* A completer */ }
"if"                    { /* A completer */ }
"int"                   { /* A completer */ }
"return"                { /* A completer */ }
"sizeof"                { /* A completer */ }
"switch"                { /* A completer */ }
"void"                  { /* A completer */ }
"while"                 { /* A completer */ }

{L}({L}|{D})*           { /* A completer */ }

0[xX]{H}+{IS}?          { /* A completer */ }
0{D}+{IS}?              { /* A completer */ }
{D}+{IS}?               { /* A completer */ }
L?'(\\.|[^\\'])+'       { /* A completer */ }

{D}+{E}{FS}?            { /* A completer */ }

L?\"(\\.|[^\\"])*\"     { /* A completer */ }

">>"                    { /* A completer */ }
"<<"                    { /* A completer */ }
"&&"                    { /* A completer */ }
"||"                    { /* A completer */ }
"<="                    { /* A completer */ }
">="                    { /* A completer */ }
"=="                    { /* A completer */ }
"!="                    { /* A completer */ }
"/*"                    { /* A completer */ }
"*/"                    { /* A completer */ }
'>'                     { /* A completer */ }
'<'                     { /* A completer */ }
'+'                     { /* A completer */ }
'-'                     { /* A completer */ }
'*'                     { /* A completer */ }
'/'                     { /* A completer */ }
'&'                     { /* A completer */ }
'|'                     { /* A completer */ }
'!'                     { /* A completer */ }

[ \t\v\n\f]             { /* A completer */ }
.                       { return yytext[0]; }
%%

