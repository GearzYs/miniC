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
noeud* addTypeNoeud(noeud* n, char* t) {
    if (strcmp(t, "int") == 0) {
        n->type = INTEGER;
    } else if (strcmp(t, "void") == 0) {
        n->type = VOID;
    } else if (strcmp(t, "array") == 0) {
        n->type = INTARRAY;
    } else if (strcmp(t, "function") == 0) {
        n->type = FUNCTION;
    }
    return n;
}
noeud* addSize(noeud* n, int size) {
    n->size_tab = size;
    return n;
}

noeud* addChild(noeud* parent, noeud* child) {
    parent->nb_fils++;
    parent->fils = realloc(parent->fils, parent->nb_fils * sizeof(noeud*));
    parent->fils[parent->nb_fils - 1] = child;
    parent->size_tab = parent->nb_fils;
    return parent;
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
liste_chaine_noeud* creerListeChaineNoeud(noeud* n) {
    liste_chaine_noeud* l = malloc(sizeof(liste_chaine_noeud));
    l->n = n;
    l->next = NULL;
    return l;
}

liste_chaine_noeud* addListeChaineNoeud(liste_chaine_noeud* l, noeud* n) {
    liste_chaine_noeud* new = malloc(sizeof(liste_chaine_noeud));
    new->n = n;
    new->next = NULL;
    liste_chaine_noeud* current = l;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new;
    return l;
}

noeud* addAllChild(noeud* n, liste_chaine_noeud* l) {
    liste_chaine_noeud* current = l;
    while (current != NULL) {
        n = addChild(n, current->n);
        current = current->next;
    }
    return n;
}

void libererNoeud(noeud* n) {
    if (n == NULL) {
        return;
    }
    
    for (int i = 0; i < n->size_tab; i++) {
        libererNoeud(n->fils[i]);
    }
    
    free(n->fils);
    free(n);
}

void afficherNoeud(noeud* n) {
    if (n == NULL) {
        return;
    }
    
    printf("Valeur du noeud : %s\n", n->val);
    
    switch (n->typeu) {
        case INTEGER:
            printf("Type du noeud : INTEGER\n");
            break;
        case INTARRAY:
            printf("Type du noeud : INTARRAY\n");
            break;
        case FUNCTION:
            printf("Type du noeud : FUNCTION\n");
            break;
        case VOID:
            printf("Type du noeud : VOID\n");
            break;
        default:
            printf("Type du noeud : Inconnu\n");
            break;
    }
    
    printf("Nombre de fils : %d\n", n->nb_fils);
    
    for (int i = 0; i < n->nb_fils; i++) {
        printf("Fils %d :\n", i);
        afficherNoeud(n->fils[i]);
    }
}



noeud* rechercherNoeud(noeud* n, char* valeur) {
    if (n == NULL) {
        return NULL;
    }
    printf("recherche dans %s\n", n->val);
    printf("nb fils : %d\n", n->nb_fils);
    printf("Recherche de %s\n", valeur);

    if (strcmp(n->val, valeur) == 0) {
        printf("trouvé\n");
        return n;
    }
    printf("nb fils : %d\n", n->nb_fils);
    printf("pas trouvé\n");
    for (int i = 0; i < n->nb_fils; i++) {
        printf("margauxx : %d\n", i);
        noeud* res = rechercherNoeud(n->fils[i], valeur);
        if (res != NULL) {
            return res;
        }
    }
    
    return NULL;
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

fonctions* addFonction(fonctions* f, noeud* n){
  f->nb_fonctions++;
  f->fonctions = realloc(f->fonctions, f->nb_fonctions * sizeof(noeud*));
  f->fonctions[f->nb_fonctions - 1] = n;
  return f;
}

fonctions* creerFonction(noeud* n){
  fonctions* f = malloc(sizeof(fonctions));
  f->nb_fonctions = 1;
  f->fonctions = malloc(sizeof(noeud*));
  f->fonctions[0] = n;
  return f;
}

void nodeType(FILE* f, noeud* n, int* COMPTEUR){
  if(n->type == APPELFONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=septagon];\n", *COMPTEUR, n->val);
  }
  else if(n->type == FONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=invtrapezium color=blue];\n", *COMPTEUR, n->val);
  }
  else if(n->type == ARGUMENT){
    fprintf(f, "node_%d [label=\"%s\"shape=triangle style=dotted];\n", *COMPTEUR, n->val);
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
  else if(strcmp(n->val,"EXTERN")==0){
    fprintf(f, "node_%d [label=\"%s\"shape=trapezium color=blue];\n", *COMPTEUR, "EXTERN");
  }
  else{
    fprintf(f, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
  }
}

void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp) {
    if (n == NULL) return;

    nodeType(fp, n, COMPTEUR);
    int noeud_courant = *COMPTEUR;
    (*COMPTEUR)++;
    for (int i = 0; i < n->nb_fils; i++) {
            //if (n->fils[i]!=NULL && (strcmp(n->fils[i]->val, ".EMPTY.")!=0) && (strcmp(n->val, ".EMPTY.")!=0)){
        if (n->fils[i]!=NULL){
          fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
          arbreToDot(n->fils[i], COMPTEUR, fp);
        }
    }
}
void generateDotFile(fonctions* listfunc){
  FILE* f;
  f = fopen("arbre.dot", "a");
  fprintf(f, "digraph G {\n");
  printf("Génération du fichier dot\n");
  for (int i = 0; i < listfunc->nb_fonctions; i++) {
    printf("Affichage de la fonction %d\n", i);
    afficherArbre(listfunc->fonctions[i]);
    arbreToDot(listfunc->fonctions[i], &COMPTEUR, f);
  }
  fprintf(f, "}");}

void clearFile(){
  FILE *f = fopen("arbre.dot", "w");
  fclose(f);
}