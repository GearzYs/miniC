%{
#include <stdio.h> 
#include <stdlib.h>
#include "parsingMini.h"
#include <string.h>
#include <stdbool.h>

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
%type <id> binary_rel binary_comp binary_op type expression variable affectation condition parm appel bloc saut selection iteration liste_declarateurs declarateur instruction declaration liste_expressions liste_instructions liste_parms fonction liste_fonctions liste_declarations programme

%%

programme	:	
		liste_declarations liste_fonctions  {}
;
liste_declarations	:	
		liste_declarations declaration  {$$=$2;}
	|				{$$=" ";}
;
liste_fonctions	:	
		liste_fonctions fonction      {$$=$1;} 
|               fonction			{$$=$1;}
;
declaration	:	
		type liste_declarateurs ';' {$$ = $2;}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {$$=$1;}
	|	declarateur  {$$ = $1; }
;
declarateur	:	
		IDENTIFICATEUR   { $$ = $1;}
	|	declarateur '[' CONSTANTE ']'  {$$="0";}  
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {$$=$1;}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {$$=EXTERN;}
;
type	:	
		VOID {$$ = "void";}
	|	INT {$$ = "int";}
;

liste_parms	:	
		liste_parms ',' parm {$$=$3;}
	|	parm {$$=$1;}
	|	{$$=" ";}
;

parm	:	 
		INT IDENTIFICATEUR  {$$ = $2;}
;

liste_instructions :	
		liste_instructions instruction {$$=$2;}
	|				{$$=" ";}
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
		FOR '(' affectation ';' condition ';' affectation ')' instruction 	{$$=FOR;}
	|	WHILE '(' condition ')' instruction {$$= WHILE;}
	|   error '\n' {yyerror("reenter last");
                        yyerrok; };
;
selection	:	
		IF '(' condition ')' instruction %prec THEN {$$=IF;}
	|	IF '(' condition ')' instruction ELSE instruction {$$=ELSE;}
	|	SWITCH '(' expression ')' instruction {$$=SWITCH;}
	|	CASE CONSTANTE ':' instruction {$$=CASE;}
	|	DEFAULT ':' instruction {$$=DEFAULT;}
;
saut	:	
		BREAK ';' {$$=BREAK;}
	|	RETURN ';' {$$=RETURN;}
	|	RETURN expression ';' {$$=RETURN;}
;
affectation	:	 
		variable '=' expression   {$$ = $3;}
;
bloc	:	
		'{' liste_declarations liste_instructions '}' {$$="0";}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$=$1;}
;
variable	:	
		IDENTIFICATEUR  {$$ = $1;}
	|	variable '[' expression ']' {$$ ="0";/* $$ = $1[$3] ;*/}
;
expression	:	
		'(' expression ')'	{$$ = $2;}                      
	|	expression binary_op expression %prec OP	{$$="0";}
	|	MOINS expression	{$$ = $2;}                                   
	|	CONSTANTE       {$$=$1;}                                                  							
	|	variable	 {$$ = $1;}                                 
	|	IDENTIFICATEUR '(' liste_expressions ')' {$$ = $1;}                                  
;

liste_expressions	:	
		liste_expressions ',' expression {$$=$1;}
	|	expression {$$=$1;}
	|   {$$=" ";}
;

condition	:	
		NOT '(' condition ')' {$$ = $3;}
	|	condition binary_rel condition %prec REL {$$="0";}
	|	'(' condition ')' {$$ = $2;}
	|	expression binary_comp expression {$$ = $1;
	noeud *n = creerNoeud("IF",1);
	noeud *n1 = creerNoeud($2,2);
	n1->fils[0] = creerNoeud($1,0);
	n1->fils[1] = creerNoeud($3,0);
	n->fils[0] = n1;
	afficherArbre(n);
	generateDotFile(n);
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

void printStack(SymbolStack* stack) {
    Symbol* current = stack->top;
    while (current != NULL) {
        printf("Nom : %s, Type : %d\n", current->name, current->type);
        current = current->next;
    }
} 
void test() {
    SymbolStack stack;
    initStack(&stack);
    int a = 5;
    int b[] = {1, 2, 3};
    int c[] = {4, 5, 6};
    int size_b = sizeof(b)/sizeof(b[0]);
	int size_c = sizeof(c)/sizeof(c[0]);

	// Ajout de symboles à la pile
	push(&stack, "x", a, NULL, 0, NULL, INTEGER);
	push(&stack, "y", 0, b, size_b, NULL, INTARRAY);
	push(&stack, "z", 0, c, size_c, NULL, INTARRAY);
    // Affichage de la pile pour déboguer
    printf("Pile de symboles :\n");
    printStack(&stack);
    
    // Recherche de symboles dans la pile
    printf("x = %d\n", *lookup(&stack, "x"));
    printf("y[0] = %d\n", lookup(&stack, "y")[0]);
    printf("y[1] = %d\n", lookup(&stack, "y")[1]);
    printf("y[2] = %d\n", lookup(&stack, "y")[2]);
    printf("z[0] = %d\n", lookup(&stack, "z")[0]);
    printf("z[1] = %d\n", lookup(&stack, "z")[1]);
    printf("z[2] = %d\n", lookup(&stack, "z")[2]);

    // Dépilement des symboles de la pile
    Symbol symbol1 = pop(&stack);
    printf("Symbole depile : %s\n", symbol1.name);
    Symbol symbol2 = pop(&stack);
    printf("Symbole depile : %s\n", symbol2.name);
    Symbol symbol3 = pop(&stack);
    printf("Symbole depile : %s\n", symbol3.name);
    
    // Destruction de la pile
    freeStack(&stack);
}


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
	test();
	endFile();
}