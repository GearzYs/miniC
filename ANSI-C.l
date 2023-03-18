%option noyywrap
D                       [0-9]
L                       [a-zA-Z_]
H                       [a-fA-F0-9]
E                       [Ee][+-]?{D}+
FS                      (f|F|l|L)
IS                      (u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
"break"                 { printf("break"); return BREAK; }
"case"                  { printf("case"); return CASE; }
"default"               { printf("default"); return DEFAULT; }
"else"                  { printf("else"); return ELSE; }
"extern"                { printf("extern"); return EXTERN; }
"for"                   { printf("for"); return FOR; }
"if"                    { printf("if"); return IF; }
"int"                   { printf("int"); return INT; }
"return"                { printf("return"); return RETURN; }
"switch"                { printf("switch"); return SWITCH; }
"void"                  { printf("void"); return VOID; }
"while"                 { printf("while"); return WHILE; }

{L}({L}|{D})*           {printf("ID %s",yytext); return IDENTIFICATEUR;}
0[xX]{H}+{IS}?          {printf("CONSTANTE %s",yytext); return CONSTANTE;}
0{D}+{IS}?              {printf("CONSTANTE %s",yytext); return CONSTANTE;}
{D}+{IS}?               {printf("CONSTANTE %s",yytext); return CONSTANTE;}
{D}+{E}{FS}?            {printf("CONSTANTE %s",yytext); return CONSTANTE;}

"&"                     { printf("&"); return BAND;}
"|"                     { printf("|"); return BOR;}
">>"                    { printf(">>"); return RSHIFT;}
"<<"                    { printf("<<"); return LSHIFT;}
"&&"                    { printf("&&"); return LAND;}
"||"                    { printf("||"); return LOR;}
"<="                    { printf("<="); return LEQ;}
">="                    { printf(">="); return GEQ;}
"=="                    { printf("=="); return EQ;}
"!="                    { printf("!="); return NEQ;}
">"                     { printf(">"); return GT;}
"<"                     { printf("<"); return LT;}
"!"                     { printf("!"); return NOT;}

"+"                     { printf("+"); return PLUS;}
"-"                     { printf("-"); return MOINS;}
"*"                     { printf("*"); return MUL;}
"/"                     { printf("/"); return DIV;}

"{"|"}"|"("|");"|"["|"]" { printf("%c",yytext[0]); }
";"|":"|","|"="         { printf("%c",yytext[0]); }

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
.                       { return yytext[0]; }
%%
