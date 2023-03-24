typedef struct _arbre {
  char* val;
  struct _arbre *fils[1];
} arbre;



arbre *createArbre(char* val, arbre *fils[]);
void affiche(arbre *a);