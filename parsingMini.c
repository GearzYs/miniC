#include <stdio.h>
#include <stdlib.h>
#include "parsingMini.h"

int COMPTEUR = 0;

noeud* creerNoeud(char* val, int nb_fils) {
    noeud* n = malloc(sizeof(noeud));
    n->val = val;
    n->nb_fils = nb_fils;
    n->fils = calloc(nb_fils, sizeof(noeud*));
    return n;
}

void afficherArbre(noeud* n) {
    if (n == NULL) {
        return;   // Cas de base : le noeud est vide
    }

    // Affichage de la valeur du noeud
    printf("%s", n->val);

    // Parcours des fils du noeud
    if (n->nb_fils == 0) {
      return;
    }
    printf("(");
    int i;
    for (i = 0; i < n->nb_fils; i++) {
        if (n->fils[i] != NULL) {
            afficherArbre(n->fils[i]);
            if (i < n->nb_fils - 1) {
                printf(",");
            }
        } else {
            return;
        }
    }
    printf(")\n");
}

void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp) {
    if (n == NULL) return;

    fprintf(fp, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
    int noeud_courant = *COMPTEUR;
    (*COMPTEUR)++;
    for (int i = 0; i < n->nb_fils; i++) {
        fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
        arbreToDot(n->fils[i], COMPTEUR, fp);
    }
}
void generateDotFile(noeud* n){
  FILE* f;
  f = fopen("arbre.dot", "a");
  arbreToDot(n, &COMPTEUR, f);
  fclose(f);
}

void startFile(){
  FILE *f = fopen("arbre.dot", "a");
  fprintf(f, "digraph G {\n");
  fclose(f);
}

void endFile(){
  FILE *f = fopen("arbre.dot", "a");
  fprintf(f, "}");
  fclose(f);
}

void clearFile(){
  FILE *f = fopen("arbre.dot", "w");
  fclose(f);
}