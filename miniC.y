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
	liste_chaine_noeud* liste;
	NoeudType* typeu;
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
%type <id> binary_rel binary_comp binary_op expression variable affectation condition parm appel bloc saut selection iteration  instruction  liste_expressions liste_instructions liste_parms fonction  programme
%type <liste> liste_declarateurs liste_fonctions liste_declarations
%type <typeu> type  
%type <noeud> declaration declarateur 
// regarder type liste plus tard
//$$= c mieux quand c larbre du dot et pas l'arbre du sémantique
// arbre khalil liste fonctions et moi liste declarations
%%

programme	:	
		liste_declarations liste_fonctions  {$$= creerNoeud("coucou");addAllChild($$,$1);}
;
liste_declarations	:	
		liste_declarations declaration  {$$= addListeChaineNoeud($1,$2);}
	|				{$$= creerListeChaineNoeud(creerNoeud("coucou"));}
;
liste_fonctions	:	
		liste_fonctions fonction      {$$=$1;} 
|               fonction			{$$=$1;}
;
declaration	:	
		type liste_declarateurs ';' {$$ = creerNoeud("coucou"); $$=addAllChild($$,$2); $$=addTypeNoeud($$,$1);}
;
liste_declarateurs	:	
		liste_declarateurs ',' declarateur {$$= addListeChaineNoeud($1,$3);};
	|	declarateur  {$$ = creerListeChaineNoeud($1); }
;
declarateur	:	
		IDENTIFICATEUR   { $$ = creerNoeud($1);}
	|	declarateur '[' CONSTANTE ']'  {$$= addSize($1,$3);}
;
fonction	:	
		type IDENTIFICATEUR '(' liste_parms ')' '{' liste_declarations liste_instructions '}' {$$=$1;}
	|	EXTERN type IDENTIFICATEUR '(' liste_parms ')' ';' {$$=EXTERN;}
;
type	:	
		VOID {$$ = "void";} // voir comment faire avec syntaxe en C pour renvoyer le type d'une enum
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
	|	expression binary_comp expression {$$="0";}
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
		LT	{printf("marg" );$$ = "<"; }
	|	GT	{$$ = ">"; }
	|	GEQ	{$$ = ">="; }
	|	LEQ	{$$ = "<="; }
	|	EQ	{$$ = "=="; }
	|	NEQ	{$$ = "!="; }
;

%%

extern int yylineno;

int test() {
    // Création de l'AST
    noeud* root = creerNoeud("Root");
    printf("type root : %d\n", root->typeu); // 0 -> NULLTYPE
    // Ajout de nœuds enfants
    noeud* child1 = creerNoeud("Child1");
    noeud* child2 = creerNoeud("Child2");
    printf("Nombre d'enfants de root : %d\n", root->nb_fils);

	// Création de la liste chaînée de nœuds
	liste_chaine_noeud* liste = creerListeChaineNoeud(child1);
    liste = addListeChaineNoeud(liste, child2);
    
    // Ajout de tous les nœuds de la liste à un nœud parent
    root = addAllChild(root, liste);
	printf("Nombre d'enfants de root : %d\n", root->nb_fils);

    // Affichage de l'AST
    printf("Affichage de l'AST :\n");
    afficherNoeud(root);
    printf("\n");
    
    // Recherche d'un nœud
    char* valeurRecherchee = "Child1";
    noeud* resultatRecherche = rechercherNoeud(root, valeurRecherchee);
	printf("res : %s\n", resultatRecherche->val);
    if (resultatRecherche->val != NULL) {
        printf("Noeud avec la valeur \"%s\" trouvé.\n", valeurRecherchee);
    } else {
        printf("Noeud avec la valeur \"%s\" non trouvé.\n", valeurRecherchee);
    }
    
    // Libération de l'AST
    libererNoeud(root);
    
    return 0;
}


void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	//while (yyparse);
	test();
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


 deux stack , une poour declarations et une pour utilisation 
 si on ajoute une decla, on ajoute dans la stack decla et utilisation je mets une case vide
 si on ajoute une utilisation, on ajoute dans la stack utilisation et dans la stack decla je mets une case vide
 changer structure genre faire 2 pile différentes 
*/