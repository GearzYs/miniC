%option noyywrap
D                       [0-9]
L                       [a-zA-Z_]

%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
"break"                 { printf("BREAK "); return BREAK; }
"case"                  { printf("CASE "); return CASE; }
"default"               { printf("DEFAULT "); return DEFAULT; }
"else"                  { printf("ELSE "); return ELSE; }
"extern"                { printf("EXTERN "); return EXTERN; }
"for"                   { printf("FOR "); return FOR; }
"if"                    { printf("IF "); return IF; }
"int"                   { printf("INT "); return INT; }
"return"                { printf("RETURN "); return RETURN; }
"switch"                { printf("SWITCH "); return SWITCH; }
"void"                  { printf("VOID "); return VOID; }
"while"                 { printf("WHILE "); return WHILE; }

{L}({L}|{D})*           {printf("ID %s",yytext); return IDENTIFICATEUR;}
{D}+                    {printf("CONSTANTE %s",yytext); return CONSTANTE;}

"&"                     { printf("& "); return BAND;}
"|"                     { printf("| "); return BOR;}
">>"                    { printf(">> "); return RSHIFT;}
"<<"                    { printf("<< "); return LSHIFT;}
"&&"                    { printf("&& "); return LAND;}
"||"                    { printf("|| "); return LOR;}
"<="                    { printf("<= "); return LEQ;}
">="                    { printf(">= "); return GEQ;}
"=="                    { printf("== "); return EQ;}
"!="                    { printf("!= "); return NEQ;}
">"                     { printf("> "); return GT;}
"<"                     { printf("< "); return LT;}
"!"                     { printf("! "); return NOT;}

"+"                     { printf("+ "); return PLUS;}
"-"                     { printf("- "); return MOINS;}
"*"                     { printf("* "); return MUL;}
"/"                     { printf("/ "); return DIV;}

"{"|"}"|"("|")"|"["|"]" { printf("%c",yytext[0]); return yytext[0]; }
";"|":"|","|"="         { printf("%c",yytext[0]); return yytext[0]; } 

(\/\/.*)|(\/\*)(.|\r|\n)*?(\*\/)  {int counter = 0;
                                    for (int i=0; i<strlen(yytext); i++){
                                        if (yytext[i] == '\n'){
                                        counter += 1;
                                        }
                                    }
                                    yylineno+=counter;
                                    }

\n                        {  yylineno++;}
[ \t\v\f]                {  }
.                       {printf("ERREUR LEXICALE");}
%%
