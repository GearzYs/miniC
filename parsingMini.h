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