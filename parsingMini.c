#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsingMini.h"
#include <limits.h>

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



// Initialiser la pile de symboles
void initStack(SymbolStack* stack) {
    stack->top = NULL;
}

// Empiler un symbole sur la pile
void push(SymbolStack* stack, char* name, int value, int* array, int size, void* function, SymbolType type) {
    Symbol* symbol = malloc(sizeof(Symbol));
    strcpy(symbol->name, name);
    symbol->type = type;
    if (type == INTEGER) {
        symbol->data.value = value;
        printf("Ajout de %s de type INT avec la valeur %d\n", name, value);
    } else if (type == INTARRAY) {
        symbol->data.array = array;
        symbol->size = size; // ajout de la taille du tableau
        printf("Ajout de %s de type INT_ARRAY avec le tableau {", name);
        for (int i = 0; i < size; i++) { // modification de la boucle pour parcourir le tableau en utilisant la taille
            printf("%d", array[i]);
            if (i != size - 1) {
                printf(", ");
            }
        }
        printf("}\n");
    } else if (type == FUNCTION) {
        symbol->data.function = function;
        printf("Ajout de %s de type FUNCTION\n", name);
    } else {
        printf("Type de symbole non pris en charge\n");
        printf("Ajout de %s de type %d\n", name, type);
    }
    symbol->next = stack->top;
    stack->top = symbol;
}


// Rechercher un symbole dans la pile
int* lookup(SymbolStack* stack, char* name) {
    Symbol* current = stack->top;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (current->type == INTEGER) {
               return &(current->data.value);
            } else if (current->type == INTARRAY) {
                return current;
            } else if (current->type == FUNCTION) {
                printf("%s : FUNCTION\n", name);
                return NULL;
            }
        }
        current = current->next;
    }
    printf("Symbole %s non defini\n", name);
    return NULL;
}




// Dépiler un symbole de la pile
Symbol pop(SymbolStack* stack) {
    if (stack->top == NULL) {
        fprintf(stderr, "La pile est vide.\n");
        exit(1);
    }
    Symbol symbol = *(stack->top);
    stack->top = stack->top->next;
    free(symbol.next);
    return symbol;
}

// Libérer la mémoire utilisée par la pile de symboles
void freeStack(SymbolStack* stack) {
    Symbol* current = stack->top;
    while (current != NULL) {
        Symbol* next = current->next;
        free(current);
        current = next;
    }
    stack->top = NULL;
}