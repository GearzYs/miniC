#include <stdio.h>
#include <stdlib.h>
#include "parsingMini.h"

arbre *createArbre(char* val, arbre *fils[]) {
  arbre *a = malloc(sizeof(arbre));
  a->val = val;
  int i;
  for (i = 0; i < 2; i++) {
    a->fils[i] = fils[i];
  }
  return a;
}

void afficherArbre(arbre *a) {
  int i;
  if (a == NULL) return;
  printf("%s", a->val);
  for (i = 0; i < 2; i++) {
    afficherArbre(a->fils[i]);
  }
}