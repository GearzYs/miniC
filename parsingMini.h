#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud {
    char *val;             // Valeur du noeud
    struct noeud **fils;   // Tableau de pointeurs vers les fils
    int nb_fils;           // Nombre de fils
} noeud;

// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val, int nb_fils);

// Affichage récursif de l'arbre à partir d'un noeud donné
void afficherArbre(noeud* n);

#endif /* ARBRE_H */

void arbreToDot(noeud* n);
void nodeToDot(FILE *f, noeud* n);
void linkNodeDot(FILE *f, noeud* n);
void startFile();
void endFile();
void freeArbre();
void clearFile();