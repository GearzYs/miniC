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
	liste_noeud *liste_noeud;
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
%type <id> binary_rel binary_comp binary_op 
%type <noeud> condition selection saut iteration programme instruction bloc appel affectation expression liste_declarations fonction declaration liste_declarateurs declarateur type variable parm
%type <liste_noeud> liste_fonctions liste_instructions liste_parms liste_expressions
%%

programme	:	
		liste_declarations liste_fonctions  {$$= creerNoeud("PROGRAMME");generateDotFile($2);}
;
liste_declarations	:	
		liste_declarations declaration  {}
	|				{}
;
liste_fonctions	:	
		liste_fonctions fonction      {$$ = addNoeud($1,$2);afficherArbre($2);} 
|      			fonction			{$$= creerListeNoeud($1);afficherArbre($1);}
;
declaration	:	
		type liste_declarateurs ';' {if(strcmp($1->val,"int")==0){
										$$ = $2 ;
									} else{
										yyerror("Error : Declaration of a non-handled type.");
									}}
;
liste_declarateurs	:
		liste_declarateurs ',' declarateur {$$= $1;}
	|	declarateur  {$$ = $1;printf("liste_declarateurs\n");}
;
declarateur	:	
		IDENTIFICATEUR   {}
	|	declarateur '[' CONSTANTE ']'  {}  
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' bloc {char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"%s, %s",$2,$1->val);
																								$$= creerNoeud(funcname);
																								$$->type = FONCTION;
																								if ($4->nb_noeud > 0){
																								for(int i = 0; i < $4->nb_noeud; i++){
																										$$ = appendChild1($$,$4->liste_noeud[i]);
																									}
																								}
																								$$ = appendChild1($$,$6);
																								}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {char* funcname = (char * ) malloc(20 * sizeof(char));
																								sprintf(funcname,"EXTERN %s, %s",$3,$2->val);
																								$$= creerNoeud(funcname);
																								$$->type = FONCTION;
																								if ($5->nb_noeud > 0) {
																									for(int i = 0; i < $5->nb_noeud; i++){
																										$$ = appendChild1($$,$5->liste_noeud[i]);
																									}
																								}}
;
type	:	
		VOID {$$ = creerNoeud("void");}
	|	INT {$$ = creerNoeud("int");}
;

liste_parms	:	
		liste_parms ',' parm {$$=addNoeud($1,$3);printf("parms\n");}
	|	parm {$$=creerListeNoeud($1);printf("liste_parms\n");}
	|	{liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		$$ = f;printf("test\n");}
;

parm	:	 
		INT IDENTIFICATEUR  {$$ = creerNoeud("INT");
							$$ = appendChild1($$,creerNoeud($2));}
;

liste_instructions :	
		liste_instructions instruction {printf("%s",$1) ;if ($2!=NULL) {$$=addNoeud($1,$2);}}
	|	{$$=NULL;}
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
		FOR '(' affectation ';' condition ';' affectation ')' instruction 	{$$= creerNoeud("FOR");
																			$$ = appendChild4($$,$3,$5,$7,$9);}
	|	WHILE '(' condition ')' instruction {$$= creerNoeud("WHILE");
											$$ = appendChild2($$,$3,$5);}
	|   error '\n' {yyerror("reenter last");
                        yyerrok; };
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {$$= creerNoeud("IF");
													$$->type = IF;
													$$ = appendChild2($$,$3,$5);}
	|	IF '(' condition ')' instruction ELSE instruction {$$= creerNoeud("IF");
															$$ = appendChild3($$,$3,$5,$7);}
	|	SWITCH '(' expression ')' instruction {$$= creerNoeud("SWITCH");
												$$ = appendChild2($$,$3,$5);}
	|	CASE CONSTANTE ':' instruction {$$= creerNoeud("CASE");
										noeud* constante = creerNoeud($2);
										$$ = appendChild2($$,constante,$4);}
	|	DEFAULT ':' instruction {$$= creerNoeud("default");
								$$ = appendChild1($$,$3);}
;
saut	:	
		BREAK ';' {$$= creerNoeud("BREAK"); 
					$$->type = BREAK;}
	|	RETURN ';' {$$= creerNoeud("RETURN");
					$$->type = RETURN;}
	|	RETURN expression ';' {$$= creerNoeud("RETURN");
							$$->type = RETURN;
							$$ = appendChild1($$,$2);}
;
affectation	:	 
		variable '=' expression   {$$ = creerNoeud(":=");
									$3->type = ARGUMENT;
									$$ = appendChild2($$,$1,$3);}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$= creerNoeud("BLOC");
														printf("Fils : %d\n",$$->nb_fils);
														printf("nb noeud : %d\n",$3->nb_noeud);
														if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															if ($3->liste_noeud[i]!=NULL){
															$$ = appendChild1($$,$3->liste_noeud[i]);
															printf("Nombre de fils de %d : %d\n",i,$3->liste_noeud[i]->nb_fils);
														}
														}
														}
}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$= creerNoeud($1);
														$$->type = APPELFONCTION;
														if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															if ($3->liste_noeud[i]!=NULL){
															$3->liste_noeud[i]->type = ARGUMENT;
															printf("appel\n");
															$$ = appendChild1($$,$3->liste_noeud[i]);
															}
														}
													}}
;
variable	:	
		IDENTIFICATEUR  {$$ = creerNoeud($1);}
	|	variable '[' expression ']' {$$ = creerNoeud("TAB");
									$$ = appendChild2($$,$1,$3);}
;
expression	:	
		'(' expression ')'	{$$ = $2;}                      
	|	expression binary_op expression %prec OP	{$$= creerNoeud($2);
													$$ = appendChild2($$,$1,$3);}
	|	MOINS expression	{$$ = creerNoeud("-");
							$$ = appendChild1($$,$2);}                                   
	|	CONSTANTE       {$$= creerNoeud($1);}                                                  							
	|	variable	 {$$ = $1;}                                 
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = creerNoeud($1);
													$$->type = APPELFONCTION;
													if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															$$ = appendChild1($$,$3->liste_noeud[i]);
														}
													}}                                  
;

liste_expressions	:	
		liste_expressions ',' expression {$$=addNoeud($1,$3);}
	|	expression {$$=creerListeNoeud($1);}
	|   {liste_noeud* f = malloc(sizeof(liste_noeud));
			f->nb_noeud = 0;
		$$ = f;}
;

condition	:	
		NOT '(' condition ')' {$$ = creerNoeud("NOT");
								$$ = appendChild1($$,$3);}
	|	condition binary_rel condition %prec REL {
										$$ = creerNoeud($2);
										$$ = appendChild2($$,$1,$3);
	}
	|	'(' condition ')' {$$ = $2;}
	|	expression binary_comp expression {
										$$ = creerNoeud($2);
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
	while(yyparse());
}