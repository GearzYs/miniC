#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// #ifndef ARBRE_H
// #define ARBRE_H

typedef enum {
    NULLTYPEU,
    IF,
    BREAK,
    FONCTION,
    APPELFONCTION,
    RETURN
} typeNoeud;

typedef enum {
    NULLTYPE,
    INTEGER,
    INTARRAY,
    FUNCTION,
    VOID
} NoeudType;

typedef struct noeud {
    char *val;             // Valeur du noeud
    struct noeud **fils;   // Tableau de pointeurs vers les fils
    typeNoeud type;        // Type du noeud
    int size_tab;         // Taille du tableau de fils
    int nb_fils;           // Nombre de fils
    NoeudType typeu;      // Type du noeud
} noeud;

typedef struct liste_chaine_noeud {
    noeud *n;
    struct liste_chaine_noeud *next;
} liste_chaine_noeud;

liste_chaine_noeud* creerListeChaineNoeud(noeud* n);
liste_chaine_noeud* addListeChaineNoeud(liste_chaine_noeud* l, noeud* n);


// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val);

// Ajout d'une taille à un noeud
noeud* addSize(noeud* n, int size);

noeud* addChild(noeud* n, noeud* child);
noeud* addAllChild(noeud* n, liste_chaine_noeud* l);

// Ajout d'un fils à un noeud
noeud* appendChild1(noeud* n, noeud* child) ;

// Ajout 2 fils à un noeud
noeud* appendChild2(noeud* n, noeud* child1, noeud* child2);

// Ajout 3 fils à un noeud
noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3);

// Ajout 4 fils à un noeud
noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4);

noeud* addTypeNoeud(noeud* n, char* t);
void libererNoeud(noeud* n);
void afficherNoeud(noeud* n);
noeud* rechercherNoeud(noeud* n, char* valeur);



// // ############################################################################## //
// // ############################################################################## //
// // def symbol_h //
// #ifndef SYMBOL_H
// #define SYMBOL_H

// typedef enum {
//     INTEGER,
//     INTARRAY,
//     FUNCTION
// } SymbolType;

// typedef struct Symbol {
//     char name[20];
//     SymbolType type;
//     union {
//         int value;
//         int* array;
//         void* function;
//     } data;
//     int size; 
//     struct Symbol* next;
// } Symbol;

// // contient un pointeur vers le sommet de la pile, qui est le dernier symbole ajouté à la pile
// typedef struct SymbolStack {
//     Symbol* top;
// } SymbolStack;

// void initStack(SymbolStack* stack);
// void push(SymbolStack* stack, char* name, int value, int* array, int size, void* function, SymbolType type);
// int* lookup(SymbolStack* stack, char* name);
// SymbolType getTypeByName(SymbolStack* stack, const char* name);
// Symbol pop(SymbolStack* stack);
// // Affecter une expression à une variable
// int* assign(SymbolStack* stack, char* name, int value);
// int* assign_array(SymbolStack* stack, char* name, int index, int value);
// void freeStack(SymbolStack* stack);
// #endif /* SYMBOL_H */

