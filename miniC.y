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
    printf("-----Stack-----\n");
    Symbol* current = stack->top;
    while (current != NULL) {
        printf("%s : ", current->name);
        if (current->type == INTEGER) {
            printf("%d\n", current->data.value);
        } else if (current->type == INTARRAY) {
            printf("{");
            for (int i = 0; i < current->size; i++) {
                printf("%d", current->data.array[i]);
                if (i < current->size - 1) {
                    printf(", ");
                }
            }
            printf("}\n");
        } else if (current->type == FUNCTION) {
            printf("FUNCTION\n");
        } else {
            printf("UNKNOWN TYPE\n");
        }
        current = current->next;
    }
    printf("---------------\n");
}

void test() {
    SymbolStack stack;
    initStack(&stack);

    // Ajout de symboles à la pile
    push(&stack, "x", 5, NULL, 0, NULL, INTEGER);
    push(&stack, "y", 0, (int[]){1,2,3}, 3, NULL, INTARRAY);
    /* push(&stack, "z", 0, NULL, 0, &test, FUNCTION); */

    // Affichage de la pile pour déboguer
    printf("Pile de symboles :\n");
    printStack(&stack);

    // Test de getSymbolType()
    Symbol* sym_x = lookup(&stack, "x");
    Symbol* sym_y = lookup(&stack, "y");
    /* Symbol* sym_z = lookup(&stack, "z"); */
    printf("Type de symbole x : %d\n", getTypeByName(&stack, "x")); // doit envoyer 0
	printf("Type de symbole y : %d\n", getTypeByName(&stack, "y")); // doit envoyer 1
	/* printf("Type de symbole z : %d\n", getTypeByName(&stack, "z")); */


	/* printf("y[0] de base = %d\n", lookup(&stack, "y")[0]);
	// Test de assign_array() on a soucis car il dit que cest pas un tab a mon avis
	// vu que l'enum envoie 0,1, 2 selon les types faut voir si c pas ca le soucis
	assign_array(&stack, "y", 0, 4);
	printf("y[0] après assignation = %d\n", lookup(&stack, "y")[0]); */


    // Dépilement des symboles de la pile
    Symbol symbol1 = pop(&stack);
    Symbol symbol2 = pop(&stack);
    printf("Symboles depilés : %s, %s\n", symbol1.name, symbol2.name);

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





/*
c ma save de teste touche pas 
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
	// on va teste de faire un changement de valeur de t 
	push(&stack, "t", 2, NULL, 0, NULL, INTEGER);
    // Affichage de la pile pour déboguer
    printf("Pile de symboles :\n");
    printStack(&stack);
    
    // Recherche de symboles dans la pile
	printf("Taille de b : %d\n", size_b);

    printf("x = %d\n", *lookup(&stack, "x"));
    printf("y[0] = %d\n", lookup(&stack, "y")[0]);
	// Modification de la valeur de y[1] à 10
    int* ptr_y1 = assign_array(&stack, "y", 1, 10);
    if (ptr_y1 != NULL) {
        printf("Nouvelle valeur de y[1] : %d\n", *ptr_y1);
    }
    printf("init z[0] = %d\n", lookup(&stack, "z")[0]);
	//on regarde la valeur de t
	printf("valeur initial de t = %d\n", *lookup(&stack, "t"));
	int new_t = 10;
	// avant de donner la nouvelle valeur de t on doit liberer l'ancienne valeur
	// on doit verif si le param est bien une vrai var int car meme si 
	// on met une char quand on appelle la fonction/
	// le code va convertir la valeur de la var char en int
	// a voir comment faire 
	//on change la valeur de t
	int* t = assign(&stack, "t", new_t);
	printf("new valeur de t = %d\n", *t);

    // Dépilement des symboles de la pile
    Symbol symbol1 = pop(&stack);
    printf("Symbole depile : %s\n", symbol1.name);
    Symbol symbol2 = pop(&stack);
    printf("Symbole depile : %s\n", symbol2.name);
    Symbol symbol3 = pop(&stack);
    printf("Symbole depile : %s\n", symbol3.name);
	Symbol symbol4 = pop(&stack);
	printf("Symbole depile : %s\n", symbol4.name);
    
    // Destruction de la pile
    freeStack(&stack);
}
*/