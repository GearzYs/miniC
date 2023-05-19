#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "parsingMini.h"

int COMPTEUR = 0;
noeud* creerNoeud(char* val) {
    noeud* n = malloc(sizeof(noeud));
    n->val = val;
    n->nb_fils = 0;
    return n;
}
noeud* addTypeNoeud(noeud* n, char* t) {
    if (strcmp(t, "int") == 0) {
        n->typeu = INTEGER;
    } else if (strcmp(t, "void") == 0) {
        n->typeu = VOIDE;
    } else if (strcmp(t, "array") == 0) {
        n->typeu = INTARRAY;
    } else if (strcmp(t, "function") == 0) {
        n->typeu = FUNCTION;
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
    if(child==NULL){
        return n;
    }
    n->nb_fils++;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 1] = child;
    return n;
}
noeud* appendChild2(noeud* n, noeud* child1, noeud* child2) {
    if (child1==NULL){
        return appendChild1(n,child2);
    }
    if(child2==NULL)
    {
        return appendChild1(n,child1);
    }
    n->nb_fils += 2;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 2] = child1;
    n->fils[n->nb_fils - 1] = child2;
    return n;
}
noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3) {
    if (child1==NULL){
        return appendChild2(n,child2,child3);
    }
    if(child2==NULL)
    {
        return appendChild2(n,child1,child3);
    }
    if(child3==NULL)
    {
        return appendChild2(n,child1,child2);
    }
    n->nb_fils += 3;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 3] = child1;
    n->fils[n->nb_fils - 2] = child2;
    n->fils[n->nb_fils - 1] = child3;
    return n;
}
noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4) {
    if (child1==NULL){
        return appendChild3(n,child2,child3,child4);
    }
    if(child2==NULL)
    {
        return appendChild3(n,child1,child3,child4);
    }
    if(child3==NULL)
    {
        return appendChild3(n,child1,child2,child4);
    }
    if(child4==NULL)
    {
        return appendChild3(n,child1,child2,child3);
    }
    n->nb_fils += 4;
    n->fils = realloc(n->fils, n->nb_fils * sizeof(noeud*));
    n->fils[n->nb_fils - 4] = child1;
    n->fils[n->nb_fils - 3] = child2;
    n->fils[n->nb_fils - 2] = child3;
    n->fils[n->nb_fils - 1] = child4;
    return n;
}

noeud* addAllChild(noeud* n, liste_noeud* f) {
    if (f == NULL) {
        return n;
    }
    if (n==NULL){
        return NULL;
    }
    for (int i = 0; i < f->nb_noeud; i++) {
        n = appendChild1(n, f->liste_noeud[i]);
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
        case VOIDE:
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

liste_noeud* creerListeNoeud(noeud* n){
  liste_noeud* f = malloc(sizeof(liste_noeud));
  if (n==NULL){
    return f;
  }
  f->nb_noeud = 1;
  f->liste_noeud = malloc(sizeof(noeud*));
  f->liste_noeud[0] = n;
  return f;
}

liste_noeud* addNoeud(liste_noeud* f, noeud* n){
    if (f == NULL) {
        f=creerListeNoeud(n);
        return f;
    }
    if (n == NULL) {
        return f;
    }
  f->nb_noeud++;
  f->liste_noeud = realloc(f->liste_noeud, f->nb_noeud * sizeof(noeud*));
  f->liste_noeud[f->nb_noeud - 1] = n;
  return f;
}

char* typeToString(NoeudType typeu){
    switch (typeu) {
        case INTEGER:
        return "int";
        break;
        case INTARRAY:
        return "int[]";
        break;
        case VOIDE:
        return "void";
        break;
    default:
        return "inconnu";
        break;
    }
}

int stringToType(char* type){
    if(strcmp(type, "int")==0){
        return INTEGER;
    }
    else if(strcmp(type, "int[]")==0){
        return INTARRAY;
    }
    else if(strcmp(type, "void")==0){
        return VOIDE;
    }
    else{
        return -1;
    }
}

void nodeType(FILE* f, noeud* n, int* COMPTEUR){
  if(n->type == APPELFONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=septagon];\n", *COMPTEUR, n->val);
  }
  else if(n->type == FONCTION){
    fprintf(f, "node_%d [label=\"%s\"shape=invtrapezium color=blue];\n", *COMPTEUR, n->val);
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

    if (strcmp(n->val, ".EMPTY.") != 0) {
        nodeType(fp, n, COMPTEUR);
        int noeud_courant = *COMPTEUR;
        (*COMPTEUR)++;

        for (int i = 0; i < n->nb_fils; i++) {
            if (n->fils[i] != NULL) {
                fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
            }
            arbreToDot(n->fils[i], COMPTEUR, fp);
        }
    } else {
        fprintf(fp, "node_%d [label=\"%s\"];\n", *COMPTEUR, n->val);
        int noeud_courant = *COMPTEUR;
        (*COMPTEUR)++;

        for (int i = 0; i < n->nb_fils; i++) {
            if (n->fils[i] != NULL) {
                fprintf(fp, "node_%d -> node_%d;\n", noeud_courant, *COMPTEUR);
                arbreToDot(n->fils[i], COMPTEUR, fp);
            }
        }
    }
}

void generateDotFile(liste_noeud* listfunc){
  FILE* f;
  f = fopen("arbre.dot", "a");
  fprintf(f, "digraph G {\n");
  printf("Génération du fichier dot\n");
  for (int i = 0; i < listfunc->nb_noeud; i++) {
    printf("Affichage de la fonction %d\n", i);
    if(listfunc->liste_noeud[i]!= NULL){
        afficherArbre(listfunc->liste_noeud[i]);
        arbreToDot(listfunc->liste_noeud[i], &COMPTEUR, f);
    }
  }
  fprintf(f, "}");}

void clearFile(){
  FILE *f = fopen("arbre.dot", "w");
  fclose(f);
}

//check sur les variables
bool verifierTypeNoeud(noeud* n, NoeudType typeAttendu) {
    return n->typeu == typeAttendu;
}

bool firstLetterIsString(noeud* n) {
    char premiereLettre = n->val[0];
    return isalpha(premiereLettre) != 0;
}

//lles sont de type entier ou tableau d’entiers à un nombre quelconque de dimensions
bool varTypeIsIntOrIntArray(noeud* n) {
    return verifierTypeNoeud(n, INTEGER) || verifierTypeNoeud(n, INTARRAY);
}

bool functionIsDeclared(noeud* n, char* nameFunction){
    noeud* res = rechercherNoeud(n, nameFunction);
    if (res == NULL) {
        printf("Erreur : la fonction '%s' n'est pas déclarée.\n", nameFunction);
        return false;
    }
    return true;
}

bool firstLetterFunctionIsString(char* nameFunction){
    char premiereLettre = nameFunction[0];
    if (!isalpha(premiereLettre)) {
        printf("Erreur de déclaration de fonction : le nom de la fonction '%s' ne commence pas par une lettre.\n", nameFunction);
        return false;
    }
    return true;
}

bool verifierNombreParametres(Fonction* fonctionAppelee, int nombreParametres) {
    if (fonctionAppelee->nbParametres != nombreParametres) {
        printf("Erreur : la fonction '%s' attend %d paramètres, mais %d ont été fournis.\n",
            fonctionAppelee->nom, fonctionAppelee->nbParametres, nombreParametres);
        return false;
    }
    return true;
}

bool verifierDeclarationFonction(Fonction* fonction) {
    // Vérification du type de la fonction
    printf("\nnom de la fonction : %s\n", fonction->nom);
    printf("type de la fonction : %d\n", fonction->typeRetour);
    printf("nb parametres de la fonction : %d\n", fonction->nbParametres);
    printf("type de parametres de la fonction : %d\n", fonction->parametres);
    if (firstLetterFunctionIsString(fonction->nom) == false) {
        return false;
    }
    printf("type de la fonction : %d\n", fonction->typeRetour);
    if (fonction->typeRetour != INTEGER && fonction->typeRetour != VOIDE) {
        printf("Erreur de déclaration de fonction : le type de la fonction '%s' est invalide.\n", fonction->nom);
        return false;
    }
    
    // Vérification des paramètres de la fonction
    for (int i = 0; i < fonction->nbParametres; i++) {
        Parametre parametre = fonction->parametres[i];
        
        // Vérification du nom du paramètre
        char premiereLettre = parametre.nom[0];
        if (!isalpha(premiereLettre)) {
            printf("Erreur de déclaration de fonction : le nom du paramètre '%s' de la fonction '%s' ne commence pas par une lettre.\n", parametre.nom, fonction->nom);
            return false;
        }
        
        // Vérification du type du paramètre
        if (parametre.type != INTEGER) {
            printf("Erreur de déclaration de fonction : le type du paramètre '%s' de la fonction '%s' n'est pas un entier.\n", parametre.nom, fonction->nom);
            return false;
        }
    }
    
    return true;
}


// check sur les identificateurs
bool checkIdentName(char* name){
    if (strcmp(name, "extern") == 0 || strcmp(name, "int") == 0 || strcmp(name, "void") == 0 || strcmp(name, "for") == 0 || strcmp(name, "while") == 0 || strcmp(name, "if") == 0 || strcmp(name, "then") == 0 || strcmp(name, "else") == 0 || strcmp(name, "switch") == 0 || strcmp(name, "case") == 0 || strcmp(name, "default") == 0 || strcmp(name, "break") == 0) {
        printf("Erreur : le nom '%s' est un mot clé réservé.\n", name);
        return false;
    }
    return true;
}

//declaration tableau
void ajouterDimensionTableau(noeud* tableau, int taille) {
    // Vérification si le nœud est de type tableau
    if (tableau->typeu != INTARRAY) {
        printf("Erreur : Le nœud n'est pas un tableau.\n");
        return;
    }
    // Vérification si le tableau n'a pas encore de dimensions
    if (tableau->tabDim == NULL) {
        // Allouer la structure TableauDimensions
        tableau->tabDim = (TableauDimensions*) malloc(sizeof(TableauDimensions));
        // Allouer le tableau de dimensions
        tableau->tabDim->dimensions = (int*) malloc(sizeof(int));
        // Initialiser le nombre de dimensions à 1
        tableau->tabDim->nb_dimensions = 1;
        // Ajouter la taille de la première dimension
        tableau->tabDim->dimensions[0] = taille;
    } else {
        // Récupérer le nombre de dimensions actuel
        int nbDimensionsActuel = tableau->tabDim->nb_dimensions;
        // Allouer un nouveau tableau de dimensions avec une taille augmentée de 1
        int* newDimensions = (int*) malloc((nbDimensionsActuel + 1) * sizeof(int));
        // Copier les dimensions actuelles dans le nouveau tableau
        memcpy(newDimensions, tableau->tabDim->dimensions, nbDimensionsActuel * sizeof(int));
        // Libérer l'ancien tableau de dimensions
        free(tableau->tabDim->dimensions);
        // Affecter le nouveau tableau de dimensions au nœud
        tableau->tabDim->dimensions = newDimensions;
        // Ajouter la taille de la nouvelle dimension à la fin du tableau
        tableau->tabDim->dimensions[nbDimensionsActuel] = taille;
        // Augmenter le nombre de dimensions
        tableau->tabDim->nb_dimensions++;
    }
}

noeud* declarerTableau(noeud* arbre, char* nomTableau, int taille, int dimensions) {
    if (arbre == NULL) {
        printf("Erreur : l'arbre est NULL.\n");
        return NULL;
    }
    if (nomTableau == NULL) {
        printf("Erreur : le nom du tableau est NULL.\n");
        return NULL;
    }
    if (taille <= 0) {
        printf("Erreur : la taille du tableau est invalide.\n");
        return NULL;
    }
    if (dimensions <= 0) {
        printf("Erreur : le nombre de dimensions du tableau est invalide.\n");
        return NULL;
    }
    if (checkIdentName(nomTableau) == false) {
        return NULL;
    }
    if (rechercherNoeud(arbre, nomTableau) != NULL) {
        printf("Erreur : le tableau '%s' est déjà déclaré.\n", nomTableau);
        return NULL;
    }

    // Création du nœud du tableau
    noeud* tableau = creerNoeud(nomTableau);
    tableau->typeu = INTARRAY;
    tableau->size_tab = taille; // Assigner la taille du tableau

    // Si le tableau a plusieurs dimensions
    if (dimensions > 1) {
        // Création du tableau de dimensions
        int* dimensionsArray = malloc(dimensions * sizeof(int));
        dimensionsArray[0] = taille;

        // Création de nœuds pour chaque dimension
        for (int i = 1; i < dimensions; i++) {
            // Création du nœud de dimension
            char nomDimension[15];
            sprintf(nomDimension, "dimension%d", i + 1);
            noeud* dimension = creerNoeud(nomDimension);
            dimension->typeu = INTEGER;
            dimension->val = malloc(10 * sizeof(char)); // Allocation mémoire pour la valeur
            sprintf(dimension->val, "%d", taille);

            // Ajout du nœud de dimension au tableau
            appendChild1(tableau, dimension);

            // Ajout de la taille de la dimension au tableau de dimensions
            dimensionsArray[i] = taille;
        }

        // Assigner le tableau de dimensions au tableau principal
        tableau->tabDim = malloc(sizeof(TableauDimensions));
        tableau->tabDim->dimensions = dimensionsArray;
        tableau->tabDim->nb_dimensions = dimensions;
    } else {
        // Cas où le tableau a une seule dimension
        tableau->tabDim = malloc(sizeof(TableauDimensions));
        tableau->tabDim->dimensions = malloc(sizeof(int));
        tableau->tabDim->dimensions[0] = taille;
        tableau->tabDim->nb_dimensions = dimensions;
    }

    // Ajout du nœud du tableau à l'arbre
    appendChild1(arbre, tableau);

    return arbre;
}