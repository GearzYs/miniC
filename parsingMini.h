#ifndef ARBRE_H
#define ARBRE_H

typedef enum {IF,BREAK,FONCTION,APPELFONCTION,ARGUMENT,RETURN} typeNoeud;

typedef struct noeud {
    char *val;             // Valeur du noeud
    struct noeud **fils;   // Tableau de pointeurs vers les fils noued[2]
    int nb_fils;           // Nombre de fils
    typeNoeud type;        // Type du noeud
} noeud;

typedef struct fonctions {
    int nb_fonctions;
    struct noeud **fonctions;
} fonctions;

// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val);

// Ajout d'un fils à un noeud
noeud* appendChild1(noeud* n, noeud* child) ;

// Ajout 2 fils à un noeud
noeud* appendChild2(noeud* n, noeud* child1, noeud* child2);

// Ajout 3 fils à un noeud
noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3);

// Ajout 4 fils à un noeud
noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4);

// Affichage récursif de l'arbre à partir d'un noeud donné
void afficherArbre(noeud* n);

// Création d'une liste de fonctions contenant des noeuds
fonctions* creerFonction(noeud* n);

// Ajout d'une fonction à la liste de fonctions
fonctions* addFonction(fonctions* f, noeud* n);

#endif /* ARBRE_H */

//Convertie une structure arbre en Dot
void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp);

//Génère un fichier .dot à partir d'un arbre
void generateDotFile(fonctions* n);

//Permet de changer la forme d'un noeud en fonction de son type
void nodeType(FILE* f, noeud* n, int* COMPTEUR);

//Vide le fichier .dot
void clearFile();