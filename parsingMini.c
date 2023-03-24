#include <stdio.h>
#include "parsingMini.h"
#include "y.tab.h"

arbre *createArbre(char* val, arbre *fils[]) {
  arbre *a = malloc(sizeof(arbre));
  a->val = val;
  int i;
  for (i = 0; i < 5; i++) {
    a->fils[i] = fils[i];
  }
  return a;
}

void affiche(arbre *a) {
  int i;
  if (a == NULL) return;
  printf("%s", a->val);
  for (i = 0; i < 5; i++) {
    affiche(a->fils[i]);
  }
}