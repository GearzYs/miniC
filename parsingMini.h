#ifndef _ARBRE_H
#define _ARBRE_H

typedef struct arbre {
  char* val;
  struct arbre *fils[2];
} arbre;

arbre *createArbre(char* val, arbre *fils[]);
void afficherArbre(arbre *a);

#endif