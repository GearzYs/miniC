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
	|	declarateur  {$$ = $1;}
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
																								$$ = appendChild1($$,$6);}
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
		$$ = f;}
;

parm	:	 
		INT IDENTIFICATEUR  {$$ = creerNoeud("INT");
							$$ = appendChild1($$,creerNoeud($2));}
;

liste_instructions :	
		liste_instructions instruction {$$=addNoeud($1,$2);}
	|	instruction				{$$=creerListeNoeud($1);}
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
														$$ = appendChild1($$,$2);
														int lenList = (sizeof($3->liste_noeud)/sizeof($3->liste_noeud[0]));
														printf("lenList : %d\n",lenList);
														if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															$$ = appendChild1($$,$3->liste_noeud[i]);
														}
																												printf("TEEEEST\n");
	}}
;
appel	:	
		IDENTIFICATEUR '(' liste_expressions ')' ';' {$$= creerNoeud($1);
														$$->type = APPELFONCTION;
														if ($3->nb_noeud > 0){
														for(int i = 0; i < $3->nb_noeud; i++){
															$3->liste_noeud[i]->type = ARGUMENT;
															$$ = appendChild1($$,$3->liste_noeud[i]);
														}
													}}
;
variable	:	
		IDENTIFICATEUR  {$$ = creerNoeud($1);}
	|	variable '[' expression ']' {$$ = creerNoeud("[]");
									$$ = appendChild1($$,$3);}
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

void testVerifierTypeNoeud() {
    // Création d'un nœud avec le type attendu
    noeud* n = creerNoeud("test");
    bool b = firstLetterIsString(n);
    printf("firstLetterIsString (test) : %s\n", b ? "true" : "false");
	
    // Test avec un nom de fonction commençant par une lettre
    Fonction* fonction1 = malloc(sizeof(Fonction));
    fonction1->nom = "addition";
    fonction1->typeRetour = INTEGER;
    fonction1->parametres = NULL;
    fonction1->nbParametres = 0;
    bool res1 = verifierDeclarationFonction(fonction1);
    printf("verifierDeclarationFonction (addition) : %s\n", res1 ? "true" : "false");
    
    // Test avec un nom de fonction ne commençant pas par une lettre
    Fonction* fonction2 = malloc(sizeof(Fonction));
    fonction2->nom = "_1division";
    fonction2->typeRetour = VOIDE;
    fonction2->parametres = NULL;
    fonction2->nbParametres = 0;
    bool res2 = verifierDeclarationFonction(fonction2);
    printf("verifierDeclarationFonction (1division) : %s\n", res2 ? "true" : "false");

	// Test nombre de paramètres d'une fonction
	/* Fonction* fonction = malloc(sizeof(Fonction));
	fonction->nom = "maFonction";
	fonction->typeRetour = INTEGER;
	fonction->nbParametres = 2;
	fonction->parametres = malloc(fonction->nbParametres * sizeof(Parametre));

	// Premier paramètre
	fonction->parametres[0].nom = "param1";
	fonction->parametres[0].type = INTEGER;

	// Deuxième paramètre
	fonction->parametres[1].nom = "param2";
	fonction->parametres[1].type = INTARRAY; */
	
	// Supposons que nous avons une fonction appelée "maFonction" qui attend 2 paramètres
	/* printf("\n\n");
	printf("Tester si nombre de param fournis correspond au nombre de param attendus.\n");
	printf("nom fonction tester : %s\n", fonction->nom);
	printf("nombre param attendus : %d\n", fonction->nbParametres);
	printf("param 1 : %s\n", fonction->parametres[0].nom);
	printf("type param 1 : %d\n", fonction->parametres[0].type);
	printf("param 2 : %s\n", fonction->parametres[1].nom);
	printf("type param 2 : %d\n", fonction->parametres[1].type);
	int nombreParametresFournis = 4; // Exemple avec un nombre incorrect de paramètres
	printf("valeur var test pour nb param différents : %d\n", nombreParametresFournis);
	bool estValide = verifierNombreParametres(fonction, nombreParametresFournis);
	if (estValide) {
		printf("Le nombre de paramètres est correct.\n");
	} else {
		printf("Le nombre de paramètres est incorrect.\n");
	}
	 */
	// Test si un identificateur est un mot clé réservé
	printf("\nTest si un ident porte le nom d'un mot clé ou pas\n");
	char* identificateur = "for";
	bool estMotCle = checkIdentName(identificateur);
	if (!estMotCle) {
		printf("Erreur : l'identificateur '%s' est un mot clé réservé.\n", identificateur);
	} else {
		printf("L'identificateur '%s' n'est pas un mot clé réservé.\n", identificateur);
	}

	// Test de la fonction ajouterDimensionTableau
    printf("\nTest de la fonction ajouterDimensionTableau\n");
    char* arbre = "arbre1";
	noeud* arb = creerNoeud(arbre);
    arb = declarerTableau(arb, "tableau1", 2, 2);
	printf("Affichage de l'arbre après ajout d'un tableau : \n");
	printf("\n\n");
	if (arb != NULL) {
		noeud* fils1 = arb->fils[0];
		printf("fils1 : %s\n", fils1->val);
		printf("type fils1 : %d\n", fils1->typeu);
		printf("taille arbre1 : %d\n", fils1->size_tab);
		printf("nb dimensions arbre1 : %d\n", fils1->tabDim->nb_dimensions);
	} else {
		printf("Erreur : l'arbre est NULL.\n");
	}
	
	//afficherNoeud(arb);
    // Libération de la mémoire
    libererNoeud(n);
    free(fonction1);
    free(fonction2);
}



void yyerror(char *s){
	 fprintf(stderr, " line %d: %s\n", yylineno, s);
	 exit(1);
}

int yywrap() {
	return 1;
}

int main(void) {
	testVerifierTypeNoeud();
	/* clearFile();
	while(yyparse()); */
}