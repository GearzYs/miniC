#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parsingMini.h"
#include <limits.h>
#include <ctype.h> 

int COMPTEUR = 0;
noeud* creerNoeud(char* val) {
    noeud* n = malloc(sizeof(noeud));
    n->val = strdup(val);  // Allouer une nouvelle mémoire et copier la valeur
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


// ajout a la suite les elts
// noeud* addChild(noeud* n, noeud* child) {
//     n->fils = realloc(n->fils, sizeof(noeud) * (n->nb_fils + 1));
//     n->fils[n->nb_fils] = child;
//     n->nb_fils++;
//     return n;
// }
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





// // Initialiser la pile de symboles
// void initStack(SymbolStack* stack) {
//     stack->top = NULL;
// }

// // Empiler un symbole sur la pile
// void push(SymbolStack* stack, char* name, int value, int* array, int size, void* function, SymbolType type) {
//     Symbol* symbol = malloc(sizeof(Symbol));
//     strcpy(symbol->name, name);
//     symbol->type = type;
//     if (type == INTEGER) {
//         symbol->data.value = value;
//         printf("Ajout de %s de type INT avec la valeur %d\n", name, value);
//     } else if (type == INTARRAY) {
//         symbol->data.array = array;
//         symbol->size = size; // ajout de la taille du tableau
//         printf("type du tableau %s: %d\n", name, type);
//         printf("Ajout de %s de type INT_ARRAY avec le tableau {", name);
//         for (int i = 0; i < size; i++) { // modification de la boucle pour parcourir le tableau en utilisant la taille
//             printf("%d", array[i]);
//             if (i != size - 1) {
//                 printf(", ");
//             }
//         }
//         printf("}\n");
//     } else if (type == FUNCTION) {
//         symbol->data.function = function;
//         printf("Ajout de %s de type FUNCTION\n", name);
//     } else {
//         printf("Type de symbole non pris en charge\n");
//         printf("Ajout de %s de type %d\n", name, type);
//     }
//     symbol->next = stack->top;
//     stack->top = symbol;
// }


// // Rechercher un symbole dans la pile
// int* lookup(SymbolStack* stack, char* name) {
//     Symbol* current = stack->top;
//     while (current != NULL) {
//         if (strcmp(current->name, name) == 0) {
//             if (current->type == INTEGER) {
//                return &(current->data.value);
//             } else if (current->type == INTARRAY) {
//                 return current->data.array;
//             } else if (current->type == FUNCTION) {
//                 printf("%s : FUNCTION\n", name);
//                 return NULL;
//             }
//         }
//         current = current->next;
//     }
//     printf("Symbole %s non defini\n", name);
//     return NULL;
// }

// // check type of symbol
// SymbolType getTypeByName(SymbolStack* stack, const char* name) {
//     Symbol* current = stack->top;
//     while (current != NULL) {
//         if (strcmp(current->name, name) == 0) {
//             if (current->type == INTEGER) {
//                 return INTEGER;
//             } else if (current->type == INTARRAY) {
//                 return INTARRAY;
//             } else if (current->type == FUNCTION) {
//                 return FUNCTION;
//             }
//         }
//         current = current->next;
//     }
//     return -1; // symbole non trouvé
// }


// // Dépiler un symbole de la pile
// Symbol pop(SymbolStack* stack) {
//     if (stack->top == NULL) {
//         fprintf(stderr, "La pile est vide.\n");
//         exit(1);
//     }
//     Symbol symbol = *(stack->top);
//     stack->top = stack->top->next;
//     return symbol;
// }

// // Affecter une expression à une variable
// int* assign(SymbolStack* stack, char* name, int value) {
//     int* var = lookup(stack, name); // recherche du symbole dans la pile
//     if (var == NULL) {
//         printf("Erreur : %s non defini\n", name);
//         return NULL;
//     }
//     if (*var == INTARRAY) {
//         printf("Erreur : %s est un tableau, vous ne pouvez pas lui affecter une valeur entière\n", name);
//         return NULL;
//     }
//     *var = value; // affectation de la valeur à la variable
//     return var;
// }

// // // Affecter une valeur à un élément d'un tableau
// // int* assign_array(SymbolStack* stack, char* name, int index, int value) {
// //     Symbol* symbol = lookup(stack, name);
// //     if (symbol == NULL) {
// //         printf("Erreur : %s non defini\n", name);
// //         return NULL;
// //     }
// //     if (symbol->type != INTARRAY) {
// //         printf("Erreur : %s n'est pas un tableau\n", name);
// //         return NULL;
// //     }
// //     if (symbol->data.array == NULL) {
// //         printf("Erreur : %s n'a pas ete alloue en tant que tableau\n", name);
// //         return NULL;
// //     }
// //     if (index < 0 || index >= symbol->size) {
// //         printf("Erreur : index %d en dehors des limites du tableau %s\n", index, name);
// //         return NULL;
// //     }
// //     symbol->data.array[index] = value;
// //     return &(symbol->data.array[index]);
// // }


// // Libérer la mémoire utilisée par la pile de symboles
// void freeStack(SymbolStack* stack) {
//     Symbol* current = stack->top;
//     while (current != NULL) {
//         Symbol* next = current->next;
//         free(current);
//         current = next;
//     }
//     stack->top = NULL;
// }