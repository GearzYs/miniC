%{
#include <stdio.h> 
#include <stdlib.h>
extern int yylineno;
void yyerror (char *s);
void table_reset();
%}
%union {
	char* val;
	char *string;
	int integer;
}
%token <val> IDENTIFICATEUR CONSTANTE
%token VOID INT FOR WHILE IF ELSE SWITCH CASE DEFAULT
%token BREAK RETURN PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ NOT EXTERN

%left MUL DIV
%left PLUS MOINS

%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL

%start programme

%type <string> binary_comp binary_op binary_rel condition declarateur declaration fonction instruction iteration liste_declarations liste_declarateurs liste_expressions liste_fonctions liste_instructions liste_parms saut selection variable parm
%type <val> type expression
%type <integer> affectation appel bloc

%%
programme	:	
		liste_declarations liste_fonctions {printf("%s%s",$1,$2);}

liste_declarations	:	
		liste_declarations declaration {$$ = strcat($1,$2);}
	|
;
liste_fonctions	:	
		liste_fonctions fonction {$$ = strcat($1,$2);}
	|   fonction {$$ = $1;}
;
declaration	:	
		type liste_declarateurs ';' {$$ = strcat($1,strcat(";",$2));}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {$$ = strcat($1,strcat(",",$3));}
	|	declarateur {$$ = $1;}
;
declarateur	:	
		IDENTIFICATEUR {printf("declaration de %s", $1);}
	|	declarateur '[' CONSTANTE ']' {printf("declaration de %s", $3);}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {printf("fonction");}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {printf("extern");}
;
type	:	
		VOID {$$ = "VOID";}
	|	INT {$$ = "INT";}
;
liste_parms	:	
		liste_parms ',' parm {$$ = strcat($1,strcat(",",$3));}
	| 
;
parm	:	
		INT IDENTIFICATEUR {$$ = "INT"+$2;}
;
liste_instructions :	
		liste_instructions instruction {$$ = strcat($1,$2);}
		|
;
instruction	:	
		iteration {$$ = $1;}
	|	selection {$$ = $1;}
	|	saut {$$ = $1;}
	|	affectation ';' {$$ = $1;}
	|	bloc {$$ = $1;}
	|	appel {$$ = $1;}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction {$$ = "FOR";}
	|	WHILE '(' condition ')' instruction {$$ = "WHILE";}
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {$$ = "IF";}
	|	IF '(' condition ')' instruction ELSE instruction %prec ELSE {$$ = "IF";}
	|	SWITCH '(' expression ')' instruction {$$ = "SWITCH";}
	|	CASE CONSTANTE ':' instruction {$$ = "CASE";}
	|	DEFAULT ':' instruction {$$ = "DEFAULT";}
;
saut	:	
		BREAK ';' {$$ = "BREAK";}
	|	RETURN ';' {$$ = "RETURN";}
	|	RETURN expression ';' {$$ = $2;}

;
affectation	:	
		variable '=' expression {$$ = strcat($1,strcat("=",$3));}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$ = strcat("{",strcat($1,strcat($3,"}")));}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$ = strcat($1,strcat($3,")"));}
;
variable	:	
		IDENTIFICATEUR {$$ = $1;}
	|	variable '[' expression ']' {$$ = strcat($1,$3);}
;
expression	:	
		'(' expression ')' {$$ = $2;}
	|	expression binary_op expression %prec OP {$$ = strcat($1,strcat($2,$3));}
	|	MOINS expression {$$ = $2;}
	|	CONSTANTE {$$ = $1;}
	|	variable {$$ = $1;}
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = strcat($1,$3);}
;
liste_expressions	:	
		liste_expressions ',' expression {$$ = strcat($1,$3);}
	|
;
condition	:	
		NOT '(' condition ')' {printf("!%s",$3);$$ = $3;}
	|	condition binary_rel condition %prec REL {$$ = strcat($1,strcat($2,$3));}
	|	'(' condition ')' {$$ = $2;}
	|	expression binary_comp expression {$$ = strcat($1,strcat($2,$3));}
;
binary_op	:	
		PLUS {$$ = '+';}
	|   MOINS {$$ = '-';}
	|	MUL {$$ = '*';}
	|	DIV {$$ = '/';}
	|   LSHIFT {$$ = "<<";}
	|   RSHIFT {$$ = ">>";}
	|	BAND {$$ = '&';}
	|	BOR {$$ = '|';}
;
binary_rel	:	
		LAND {$$ = "&&";}
	|	LOR {$$ = "||";}
;
binary_comp	:	
		LT {$$ = '<';}
	|	GT {$$ = '>';}
	|	GEQ {$$ = ">=";}
	|	LEQ {$$ = "<=";}
	|	EQ {$$ = "==";}
	|	NEQ {$$ = "!=";}
;
%%

void yyerror(char *s){
     fprintf(stderr, " line %d: %s\n", yylineno, s);
     exit(1);
}

int yywrap() {
    return 1;
} 
int main(void) {
    while(yyparse());
}