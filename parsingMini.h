#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ARBRE_H
#define ARBRE_H

typedef enum {IF,BREAK,FONCTION,APPELFONCTION,RETURN} typeNoeud;

typedef struct noeud {
    char *val;             // Valeur du noeud
    struct noeud **fils;   // Tableau de pointeurs vers les fils
    int nb_fils;           // Nombre de fils
    typeNoeud type;        // Type du noeud

} noeud;

// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val, int nb_fils);

// Affichage récursif de l'arbre à partir d'un noeud donné
void afficherArbre(noeud* n);

#endif /* ARBRE_H */

//Convertie une structure arbre en Dot
void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp);

//Génère un fichier .dot à partir d'un arbre
void generateDotFile(noeud* n);

//Permet de changer la forme d'un noeud en fonction de son type
void nodeType(FILE* f, noeud* n, int* COMPTEUR);

//Commence le fichier .dot
void startFile();

//Termine le fichier .dot
void endFile();

//Vide le fichier .dot
void clearFile();


// ############################################################################## //
// ############################################################################## //
// def symbol_h //
#ifndef SYMBOL_H
#define SYMBOL_H

typedef enum {
    INTEGER,
    INTARRAY,
    FUNCTION
} SymbolType;

typedef struct Symbol {
    char name[20];
    SymbolType type;
    union {
        int value;
        int* array;
        void* function;
    } data;
    int size; 
    struct Symbol* next;
} Symbol;

// contient un pointeur vers le sommet de la pile, qui est le dernier symbole ajouté à la pile
typedef struct SymbolStack {
    Symbol* top;
} SymbolStack;

void initStack(SymbolStack* stack);
void push(SymbolStack* stack, char* name, int value, int* array, int size, void* function, SymbolType type);
int* lookup(SymbolStack* stack, char* name);
SymbolType getTypeByName(SymbolStack* stack, const char* name);
Symbol pop(SymbolStack* stack);
// Affecter une expression à une variable
int* assign(SymbolStack* stack, char* name, int value);
int* assign_array(SymbolStack* stack, char* name, int index, int value);
void freeStack(SymbolStack* stack);
#endif /* SYMBOL_H */

