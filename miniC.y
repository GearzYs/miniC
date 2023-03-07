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
%left PLUS MOINS
%left MUL DIV
%left LSHIFT RSHIFT
%left BOR BAND
%left LAND LOR
%nonassoc THEN
%nonassoc ELSE
%left OP
%left REL
%start programme
%%
programme	:	
		liste_declarations liste_fonctions;
liste_declarations	:	
		liste_declarations declaration 
	|	
;
liste_fonctions	:	
		liste_fonctions fonction
|               fonction
;
declaration	:	
		type liste_declarateurs ';'
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur
	|	declarateur
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
		VOID {printf("type : void");}
	|	INT {printf("type : int");}
;
liste_parms	:	
		liste_parms ',' parm {printf("liste_parms");}
	|	
;
parm	:	
		INT IDENTIFICATEUR {printf("parametre : int %s", $2);}
;
liste_instructions :	
		liste_instructions instruction {printf("liste_instructions");}
	|
;
instruction	:	
		iteration
	|	selection
	|	saut
	|	affectation ';'
	|	bloc
	|	appel
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction {printf("for");}
	|	WHILE '(' condition ')' instruction {printf("while");}
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {printf("if");}
	|	IF '(' condition ')' instruction ELSE instruction %prec ELSE {printf("if else");}
	|	SWITCH '(' expression ')' instruction {printf("switch");}
	|	CASE CONSTANTE ':' instruction {printf("case");}
	|	DEFAULT ':' instruction {printf("default");}
;
saut	:	
		BREAK ';' {printf("break");}
	|	RETURN ';' {printf("return");}
	|	RETURN expression ';' {printf("return expression");}

;
affectation	:	
		variable '=' expression {printf("affectation");}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {printf("bloc");}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {printf("appel de %s", $1);}
;
variable	:	
		IDENTIFICATEUR {printf("variable : %s", $1);}
	|	variable '[' expression ']' {printf("variable");}
;
expression	:	
		'(' expression ')'
	|	expression binary_op expression %prec OP {printf("OP");}
	|	MOINS expression {printf("MOINS");}
	|	CONSTANTE {printf("expression : %d", $1);}
	|	variable {printf("expression : variable");}
	|	IDENTIFICATEUR '(' liste_expressions ')' {printf("expression : %s", $1);}
;
liste_expressions	:	
		liste_expressions ',' expression {printf("liste_expressions");}
	|
;
condition	:	
		NOT '(' condition ')' {printf("condition : NOT");}
	|	condition binary_rel condition %prec REL {printf("condition : REL");}
	|	'(' condition ')' {printf("condition");}
	|	expression binary_comp expression {printf("res comp");}
;
binary_op	:	
		PLUS {printf("binary_op : PLUS");}
	|       MOINS {(printf("binary_op : MOINS"));}
	|	MUL {printf("binary_op : MUL");}
	|	DIV {printf("binary_op : DIV");}
	|       LSHIFT {printf("binary_op : LSHIFT");}
	|       RSHIFT {printf("binary_op : RSHIFT");}
	|	BAND {printf("binary_op : BAND");}
	|	BOR {printf("binary_op : BOR");}
;
binary_rel	:	
		LAND {printf("binary_rel : LAND");}
	|	LOR {printf("binary_rel : LOR");}
;
binary_comp	:	
		LT {printf("binary_comp : LT");}
	|	GT {printf("binary_comp : GT");}
	|	GEQ {printf("binary_comp : GEQ");}
	|	LEQ {printf("binary_comp : LEQ");}
	|	EQ {printf("binary_comp : EQ");}
	|	NEQ {printf("binary_comp : NEQ");}
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