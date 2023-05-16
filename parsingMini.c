#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsingMini.h"

int COMPTEUR = 0;

noeud* creerNoeud(char* val) {
    noeud* n = malloc(sizeof(noeud));
    n->val = val;
    return n;
}

noeud* appendChild1(noeud* n, noeud* child) {
    n->nb_fils++;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 1] = child;
    return n;
}

noeud* appendChild2(noeud* n, noeud* child1, noeud* child2) {
    n->nb_fils += 2;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 2] = child1;
    n->fils[n->nb_fils - 1] = child2;
    return n;
}

noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3) {
    n->nb_fils += 3;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 3] = child1;
    n->fils[n->nb_fils - 2] = child2;
    n->fils[n->nb_fils - 1] = child3;
    return n;
}

noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4) {
    n->nb_fils += 4;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 4] = child1;
    n->fils[n->nb_fils - 3] = child2;
    n->fils[n->nb_fils - 2] = child3;
    n->fils[n->nb_fils - 1] = child4;
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
        if (n->nb_fils > 0) {
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

void nodeType(FILE* f, noeud* n, int* COMPTEUR){
  if(n->type == APPELFONCTION){
    printf("APPELFONCTION\n");
  }
  else if(n->type == FONCTION){
    printf("FONCTION\n");
  }
  else if(strcmp(n->val,"BREAK")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=box];\n", *COMPTEUR, "BREAK");
  }
  else if(strcmp(n->val,"IF")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=diamond];\n", *COMPTEUR, "IF");
  }
  else if(strcmp(n->val,"RETURN")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=trapezium color=blue];\n", *COMPTEUR, "RETURN");
  }
  else {
    fprintf(f, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
  }
}

void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp) {
    if (n == NULL) return;

    nodeType(fp, n, COMPTEUR);
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
  fprintf(f, "digraph G {\n");
  printf("Génération du fichier dot\n");
  arbreToDot(n, &COMPTEUR, f);
  fprintf(f, "}");}

void clearFile(){
  FILE *f = fopen("arbre.dot", "w");
  fclose(f);
}