#include <stdio.h>
#include <stdlib.h>
#include "parsingMini.h"

int NODE_ID = 0;

noeud* creerNoeud(char* val, int nb_fils) {
    noeud* n = malloc(sizeof(noeud));
    n->val = val;
    n->nb_fils = nb_fils;
    n->fils = calloc(nb_fils, sizeof(noeud*));
    return n;
}

int getNodeId(){
  int id = NODE_ID;
  NODE_ID++;
  return id;
}

int getNbFeuilles(noeud* n){
  if (n == NULL) {
      return 0;   // Cas de base : le noeud est vide
  }
  int nbFeuilles = n->nb_fils;
  int i;
  for (i=0; i < n->nb_fils; i++) {
    if (n->fils[i]->nb_fils != 0){
      nbFeuilles += getNbFeuilles(n->fils[i]);
    }
  }
  return nbFeuilles;
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

void nodeToDot(FILE *f, noeud* n){
  if (n == NULL) {
      return;   // Cas de base : le noeud est vide
  }
  fprintf(f, "\tnode_%d [shape=ellipse label=\"%s\"];\n", getNodeId(), n->val);
  int i;
  for (i=0; i < n->nb_fils; i++) {
    if (n->fils[i] != NULL) {
      if (n->fils[i]->nb_fils == 0){
        fprintf(f, "\tnode_%d [shape=ellipse label=\"%s\"];\n", getNodeId(), n->fils[i]->val);
      }
      else {
        nodeToDot(f, n->fils[i]);
      }
    }
  }
}

void linkNodeDot(FILE *f, noeud* n){
  if (n == NULL) {
      return;   // Cas de base : le noeud est vide
  }
  int id = NODE_ID;
  fprintf(f, "\tnode_%d -> node_%d;\n", id, getNodeId());
  int i;
  for (i=0; i < n->nb_fils; i++) {
    if (n->fils[i] != NULL) {
      if (n->fils[i]->nb_fils == 0){
        fprintf(f, "\tnode_%d -> node_%d;\n", id, getNodeId());
      }
      else {
        fprintf(f, "\tnode_%d -> node_%d;\n", id, id+i);
        linkNodeDot(f, n->fils[i]);
      }
    }
  }
}

void linkNodeTemp(FILE *f, noeud* n){
  NODE_ID = NODE_ID - getNbFeuilles(n)-1;
  linkNodeDot(f, n);
  NODE_ID = NODE_ID + getNbFeuilles(n)+1;
}

void arbreToDot(noeud* n){
  FILE *f = fopen("arbre.dot", "a");
  nodeToDot(f, n);
  linkNodeTemp(f, n);
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

void freeArbre(){
  noeud* n = creerNoeud("A", 3);
  n->fils[0] = creerNoeud("B", 2);
  n->fils[1] = creerNoeud("C", 2);
  n->fils[2] = creerNoeud("D", 0);
  n->fils[0]->fils[0] = creerNoeud("E", 0);
  n->fils[0]->fils[1] = creerNoeud("F", 0);
  n->fils[1]->fils[0] = creerNoeud("G", 0);
  n->fils[1]->fils[1] = creerNoeud("H", 0);
  afficherArbre(n);
  printf("nbFeuilles : %d\n", getNbFeuilles(n));
  arbreToDot(n);
}