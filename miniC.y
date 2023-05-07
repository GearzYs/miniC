%{
#include <stdio.h> 
#include <stdlib.h>
#include "parsingMini.h"

extern int chars;

void yyerror (char *s);
%}

%union{
	int val;
	char* id;
	noeud *noeud;
}
 

%token VOID INT 
%token PLUS MOINS MUL DIV LSHIFT RSHIFT BAND BOR LAND LOR LT GT 
%token GEQ LEQ EQ NEQ
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

%token <id> WHILE FOR IF NOT IDENTIFICATEUR CONSTANTE BREAK RETURN DEFAULT CASE SWITCH EXTERN
%type <id> binary_rel binary_comp binary_op programme
%type <noeud> condition selection saut iteration instruction bloc appel liste_instructions affectation expression liste_declarations fonction liste_fonctions declaration liste_declarateurs declarateur liste_expressions type variable liste_parms parm
%%

programme	:	
		liste_declarations liste_fonctions  {afficherArbre($1);}
;
liste_declarations	:	
		liste_declarations declaration  {$$=creerNoeud("LISTE_DECLARATIONS",1);
											$$ = appendChild1($$,$2);}
	|				{$$= creerNoeud("LISTE_DECLARATIONS",0);}
;
liste_fonctions	:	
		liste_fonctions fonction      {$$= creerNoeud("LISTE_FONCTIONS",0);
										$$ = appendChild2($$,$1,$2);} 
|               fonction			{$$= creerNoeud("LISTE_FONCTIONS",0);
										$$ = appendChild1($$,$1);}
;
declaration	:	
		type liste_declarateurs ';' {$$= creerNoeud("DECLARATION",1);
										$$ = appendChild1($$,$2);}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {$$= creerNoeud("LISTE_DECLARATEURS",0);
											$$ = appendChild2($$,$1,$3);}
	|	declarateur  {$$ = creerNoeud("LISTE_DECLARATEURS",0);
					$$ = appendChild1($$,$1);}
;
declarateur	:	
		IDENTIFICATEUR   { $$ = creerNoeud($1,0);}
	|	declarateur '[' CONSTANTE ']'  {$$= creerNoeud("[]",2);
										noeud* constante = creerNoeud($3,0);
										$$ = appendChild1($$,constante);}  
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {$$= creerNoeud($2,3);
																								$$->type = FONCTION;
																								$$ = appendChild3($$,$1,$4,$7);
																								$$ = appendChild1($$,$8);}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {$$= creerNoeud("EXTERN",1);
															$$ = appendChild1($$,$2);}
;
type	:	
		VOID {$$ = creerNoeud("void",0);}
	|	INT {$$ = creerNoeud("int",0);}
;

liste_parms	:	
		liste_parms ',' parm {$$= creerNoeud("LISTE_PARMS",2);
								$$ = appendChild2($$,$1,$3);}
	|	parm {$$= $1;}
	|	{$$= creerNoeud("PARAM VIDE",0);}
;

parm	:	 
		INT IDENTIFICATEUR  {$$ = creerNoeud($2,0);}
;

liste_instructions :	
		liste_instructions instruction {$$=$1;afficherArbre($2);}
	|				{$$= creerNoeud("LISTE_INSTRUCTIONS",0);}
;
instruction	:	
		iteration {$$=$1;}
	|	selection {$$=$1;}
	|	saut {$$=$1;}
	|	affectation ';' {$$=$1;}
	|	bloc {$$=$1;}
	|	appel {$$=$1;}
;
iteration	:	
		FOR '(' affectation ';' condition ';' affectation ')' instruction 	{$$= creerNoeud("for",4);
																			$$ = appendChild4($$,$3,$5,$7,$9);}
	|	WHILE '(' condition ')' instruction {$$= creerNoeud("while",2);
											$$ = appendChild2($$,$3,$5);}
	|   error '\n' {yyerror("reenter last");
                        yyerrok; };
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {$$= creerNoeud("if",2);
													$$ = appendChild2($$,$3,$5);}
	|	IF '(' condition ')' instruction ELSE instruction {$$= creerNoeud("if",3);
															$$ = appendChild3($$,$3,$5,$7);}
	|	SWITCH '(' expression ')' instruction {$$= creerNoeud("switch",2);
												$$ = appendChild2($$,$3,$5);}
	|	CASE CONSTANTE ':' instruction {$$= creerNoeud("case",2);
										noeud* constante = creerNoeud($2,0);
										$$ = appendChild2($$,constante,$4);}
	|	DEFAULT ':' instruction {$$= creerNoeud("default",1);
								$$ = appendChild1($$,$3);}
;
saut	:	
		BREAK ';' {$$= creerNoeud("break",0); }
	|	RETURN ';' {$$= creerNoeud("return",0);}
	|	RETURN expression ';' {$$= creerNoeud("return",1);
							$$ = appendChild1($$,$2);}
;
affectation	:	 
		variable '=' expression   {$$ = creerNoeud(":=",2);
									$$ = appendChild2($$,$1,$3);}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$= creerNoeud("BLOC",2);
														$$ = appendChild2($$,$2,$3);}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$= creerNoeud($1,0);
														$$->type = APPELFONCTION;}
;
variable	:	
		IDENTIFICATEUR  {$$ = creerNoeud($1,0);}
	|	variable '[' expression ']' {$$ = creerNoeud("[]",2);
									$$ = appendChild1($$,$3);}
;
expression	:	
		'(' expression ')'	{$$ = $2;}                      
	|	expression binary_op expression %prec OP	{$$= creerNoeud($2,2);
													$$ = appendChild2($$,$1,$3);}
	|	MOINS expression	{$$ = creerNoeud("MOINS",1);
							$$ = appendChild1($$,$2);}                                   
	|	CONSTANTE       {$$= creerNoeud($1,0);}                                                  							
	|	variable	 {$$ = $1;}                                 
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = creerNoeud($1,0);
													$$->type = APPELFONCTION;
													$$ = appendChild1($$,$3);}                                  
;

liste_expressions	:	
		liste_expressions ',' expression {$$= creerNoeud("LISTE_EXPRESSIONS",0);
											$$ = appendChild2($$,$1,$3);}
	|	expression {$$= $1;}
	|   {$$= creerNoeud(" ",0);}
;

condition	:	
		NOT '(' condition ')' {$$ = creerNoeud("NOT",1);
								$$ = appendChild1($$,$3);}
	|	condition binary_rel condition %prec REL {
										$$ = creerNoeud($2,2);
										$$ = appendChild2($$,$1,$3);
	}
	|	'(' condition ')' {$$ = $2;}
	|	expression binary_comp expression {
										$$ = creerNoeud($2,2);
										$$ = appendChild2($$,$1,$3);
	}
;
binary_op	:	
		PLUS  {$$ = "+"; }
	|   MOINS	{$$ = "-"; }
	|	MUL	{$$ = "*"; }
	|	DIV	{$$ = "/"; }
	|   LSHIFT	{$$ = "<<"; }
	|   RSHIFT	{$$ = ">>"; }
	|	BAND	{$$ = "&="; }
	|	BOR	{$$ = "|="; }
;
binary_rel	:	
		LAND {$$ = "&&"; }
	|	LOR	{$$ = "||"; }
;
binary_comp	:	
		LT	{$$ = "<"; }
	|	GT	{$$ = ">"; }
	|	GEQ	{$$ = ">="; }
	|	LEQ	{$$ = "<="; }
	|	EQ	{$$ = "=="; }
	|	NEQ	{$$ = "!="; }
;

%%

extern int yylineno;

void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	clearFile();
	startFile();
	while(yyparse());
	endFile();
}