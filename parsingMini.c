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
    n->tableSymbole = malloc(sizeof(tableSymbole));
    n->tableSymbole->tailleTab = 0;
    n->tableSymbole->fonction = malloc(sizeof(fonction));
    n->tableSymbole->tabDim = NULL;
    n->tableSymbole->typeu = NULLTYPE;
    n->tableSymbole->name = NULL;
    return n;
}
noeud* addTypeNoeud(noeud* n, char* t) {
    if (strcmp(t, "int") == 0) {
        n->tableSymbole->typeu = INTEGER;
    } else if (strcmp(t, "void") == 0) {
        n->tableSymbole->typeu = VOIDE;
    } else if (strcmp(t, "array") == 0) {
        n->tableSymbole->typeu = INTARRAY;
    } else if (strcmp(t, "function") == 0) {
        n->tableSymbole->typeu = FUNCTION;
    }
    return n;
}

noeud* addSize(noeud* n, int size) {
    n->tableSymbole->tailleTab = size;
    return n;
}

noeud* addChild(noeud* parent, noeud* child) {
    parent->nb_fils++;
    parent->fils = realloc(parent->fils, parent->nb_fils * sizeof(noeud*));
    parent->fils[parent->nb_fils - 1] = child;
    parent->tableSymbole->tailleTab = parent->nb_fils;
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
    
    for (int i = 0; i < n->tableSymbole->tailleTab; i++) {
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
    
    switch (n->tableSymbole->typeu) {
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

    if (strcmp(n->tableSymbole->name, valeur) == 0) {
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

liste_noeud* addNoeudList(liste_noeud* a, liste_noeud* b) {
    if (a == NULL) {
        return b;
    }
    if (b == NULL) {
        return a;
    }
    liste_noeud* res = creerListeNoeud(NULL);
    res->nb_noeud = a->nb_noeud + b->nb_noeud;
    res->liste_noeud = malloc(res->nb_noeud * sizeof(noeud*));
    for (int i = 0; i < a->nb_noeud; i++) {
        res->liste_noeud[i] = a->liste_noeud[i];
    }
    for (int i = 0; i < b->nb_noeud; i++) {
        res->liste_noeud[i + a->nb_noeud] = b->liste_noeud[i];
    }
    return res;
}

liste_noeud* rechercherNoeudListe(noeud* n,char* valeur){
    if (n == NULL) {
        return NULL;
    }
    liste_noeud* res = creerListeNoeud(NULL);
    if (strcmp(n->tableSymbole->name, valeur) == 0) {
        res = addNoeud(res, n);
    }
    for (int i = 0; i < n->nb_fils; i++) {
        liste_noeud* res2 = rechercherNoeudListe(n->fils[i], valeur);
        if (res2 != NULL) {
            res = addNoeudList(res, res2);
        }
    }
    return res;
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
    if(listfunc->liste_noeud[i]!= NULL && strncmp(listfunc->liste_noeud[i]->val, "EXTERN",6) != 0){
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
    return n->tableSymbole->typeu == typeAttendu;
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

noeud* newFunction(noeud* n, char* nameFunction, noeud* typeFunction, liste_noeud* parametres, int line) {
    n->type = FONCTION;
    if (parametres->liste_noeud[0]==NULL){
        printf("parametres null\n");
    }
    n->tableSymbole->typeu = FUNCTION;
    n->tableSymbole->name = nameFunction;
    n->tableSymbole->line = line;
    n->tableSymbole->fonction->typeRetour = stringToType(typeFunction->val); // ici j'ai mis dans typeRetour le type de la fonction
    if (parametres == NULL) {
        n->tableSymbole->fonction->nbParametres = 0;
        n->tableSymbole->fonction->parametres = NULL;
    }
    else{
        n->tableSymbole->fonction->nbParametres = parametres->nb_noeud;
        n->tableSymbole->fonction->parametres = malloc(sizeof(Parametre*) * parametres->nb_noeud);
        n->tableSymbole->fonction->parametres[0] = malloc(sizeof(Parametre));
        n->tableSymbole->fonction->parametres[0]->type = parametres->liste_noeud[0]->tableSymbole->typeu;
    }
    n->tableSymbole->fonction->nom = nameFunction;
    for (int i = 0; i < n->tableSymbole->fonction->nbParametres; i++) {
        n->tableSymbole->fonction->parametres[i] = malloc(sizeof(Parametre));
        n->tableSymbole->fonction->parametres[i]->type = parametres->liste_noeud[i]->tableSymbole->typeu;
        n->tableSymbole->fonction->parametres[i]->nom = parametres->liste_noeud[i]->val; 
    }
    return n;
}

noeud* newVariable(char* name, int line) {
    noeud* var = creerNoeud(name);
    var->tableSymbole->name = name;
    var->tableSymbole->typeu = INTEGER;
    var->tableSymbole->line = line;
    return var;
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
    if (tableau->tableSymbole->typeu != INTARRAY) {
        printf("Erreur : Le nœud n'est pas un tableau.\n");
        return;
    }
    // Vérification si le tableau n'a pas encore de dimensions
    if (tableau->tableSymbole->tabDim == NULL) {
        // Allouer la structure TableauDimensions
        tableau->tableSymbole->tabDim = (TableauDimensions*) malloc(sizeof(TableauDimensions));
        // Allouer le tableau de dimensions
        tableau->tableSymbole->tabDim->dimensions = (int*) malloc(sizeof(int));
        // Initialiser le nombre de dimensions à 1
        tableau->tableSymbole->tabDim->nb_dimensions = 1;
        // Ajouter la taille de la première dimension
        tableau->tableSymbole->tabDim->dimensions[0] = taille;
    } else {
        // Récupérer le nombre de dimensions actuel
        int nbDimensionsActuel = tableau->tableSymbole->tabDim->nb_dimensions;
        // Allouer un nouveau tableau de dimensions avec une taille augmentée de 1
        int* newDimensions = (int*) malloc((nbDimensionsActuel + 1) * sizeof(int));
        // Copier les dimensions actuelles dans le nouveau tableau
        memcpy(newDimensions, tableau->tableSymbole->tabDim->dimensions, nbDimensionsActuel * sizeof(int));
        // Libérer l'ancien tableau de dimensions
        free(tableau->tableSymbole->tabDim->dimensions);
        // Affecter le nouveau tableau de dimensions au nœud
        tableau->tableSymbole->tabDim->dimensions = newDimensions;
        // Ajouter la taille de la nouvelle dimension à la fin du tableau
        tableau->tableSymbole->tabDim->dimensions[nbDimensionsActuel] = taille;
        // Augmenter le nombre de dimensions
        tableau->tableSymbole->tabDim->nb_dimensions++;
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
    tableau->tableSymbole->typeu = INTARRAY;
    tableau->tableSymbole->tailleTab = taille; // Assigner la taille du tableau

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
            dimension->tableSymbole->typeu = INTEGER;
            dimension->val = malloc(10 * sizeof(char)); // Allocation mémoire pour la valeur
            sprintf(dimension->val, "%d", taille);

            // Ajout du nœud de dimension au tableau
            appendChild1(tableau, dimension);

            // Ajout de la taille de la dimension au tableau de dimensions
            dimensionsArray[i] = taille;
        }

        // Assigner le tableau de dimensions au tableau principal
        tableau->tableSymbole->tabDim = malloc(sizeof(TableauDimensions));
        tableau->tableSymbole->tabDim->dimensions = dimensionsArray;
        tableau->tableSymbole->tabDim->nb_dimensions = dimensions;
    } else {
        // Cas où le tableau a une seule dimension
        tableau->tableSymbole->tabDim= malloc(sizeof(TableauDimensions));
        tableau->tableSymbole->tabDim->dimensions = malloc(sizeof(int));
        tableau->tableSymbole->tabDim->dimensions[0] = taille;
        tableau->tableSymbole->tabDim->nb_dimensions = dimensions;
    }

    // Ajout du nœud du tableau à l'arbre
    appendChild1(arbre, tableau);

    return arbre;
}


liste_error* addNewError(liste_error* liste, char* message, int line) {
    error* newError = malloc(sizeof(error));
    newError->message = message;
    newError->line = line;
    if (liste==NULL){
        liste = malloc(sizeof(liste_error));
        liste->nb_error = 1;
        liste->liste_error = malloc(sizeof(error*));
        liste->liste_error[0] = newError;
        return liste;
    }
    liste->nb_error++;
    liste->liste_error = realloc(liste->liste_error, liste->nb_error * sizeof(error*));
    liste->liste_error[liste->nb_error - 1] = newError;
    return liste;
}

liste_error* addNewListError(liste_error* error1, liste_error* error2){
    if (error1 == NULL) {
        return error2;
    }
    if (error2 == NULL) {
        return error1;
    }
    liste_error* newList = malloc(sizeof(liste_error));
    newList->nb_error = error1->nb_error + error2->nb_error;
    newList->liste_error = malloc(newList->nb_error * sizeof(error*));
    for (int i = 0; i < error1->nb_error; i++) {
        newList->liste_error[i] = error1->liste_error[i];
    }
    for (int i = 0; i < error2->nb_error; i++) {
        newList->liste_error[i + error1->nb_error] = error2->liste_error[i];
    }
    return newList;
}

void afficherError(error* error){
    if (error == NULL)
    {
        printf("Erreur : l'erreur est NULL.\n");
    }
    
    printf("Erreur : ligne %d -> %s\n", error->line, error->message);
}

bool afficherErrors(liste_error* liste){
    if (liste == NULL) {
        return false;
    }
    printf("Nombre d'erreur(s) : %d\n", liste->nb_error);
    for (int i = 0; i < liste->nb_error; i++) {
        afficherError(liste->liste_error[i]);
    }
    return true;
}

 liste_error* checkInBlock(noeud* n, noeud* arbreGlobal, liste_error* listeError){
    if (n == NULL) {
        printf("Erreur : l'arbre est NULL.\n");
        return NULL;
    }
    if (strcmp(n->val, "BLOC") == 0) {
        if (n->type==GLOBAL){
        listeError = verifierDeclarations(n,NULL,listeError);
        }
        else{
        listeError =verifierDeclarations(n,arbreGlobal,listeError);
        }
    }
    else{   
        for (int i = 0; i < n->nb_fils; i++) {
        if (n->fils[i] != NULL) {
            listeError=checkInBlock(n->fils[i],arbreGlobal,listeError);
        }
    }
    }
    return listeError;
}

liste_error* verifierDeclarations(noeud* prog, noeud* arbreGlobal, liste_error* listeError) {
    noeud* arbreDeclaration = creerNoeud("arbreDeclaration");
    liste_noeud* liste;
    if (arbreGlobal == NULL) {
        liste = prog->tableSymbole->fonction->declaration;
    }
    else{
        liste = addNoeudList(arbreGlobal->tableSymbole->fonction->declaration,prog->tableSymbole->fonction->declaration);
    }
    arbreDeclaration=addAllChild(arbreDeclaration, liste);
    for (int i = 0; i < arbreDeclaration->nb_fils; i++) {
        for (int k = 0; k < arbreDeclaration->fils[i]->nb_fils; k++) {
            if (arbreDeclaration->fils[i]->fils[k]==NULL){
                continue;
            }
            noeud* declaration = arbreDeclaration->fils[i]->fils[k];
            // Vérifier si la déclaration est unique
            char* nomVariable = declaration->tableSymbole->name;
            for (int j = 0; j < arbreDeclaration->nb_fils; j++) {
                for (int l=0;l<arbreDeclaration->fils[j]->nb_fils;l++){
                    if (i==j && k==l){
                        continue;
                    }
                    if (arbreDeclaration->fils[j]->fils[l]==NULL){
                        continue;
                    }
                    if (strcmp(nomVariable, arbreDeclaration->fils[j]->fils[l]->tableSymbole->name) == 0) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la variable '%s' est déjà déclarée.", nomVariable);
                        message = realloc(message, strlen(message) * sizeof(char));
                        listeError = addNewError(listeError, message, arbreDeclaration->fils[j]->fils[l]->tableSymbole->line);
                        arbreDeclaration->fils[j]->fils[l]=NULL;
                        break;
                    }
                }
            }
        // Vérifier le type de la variable
        NoeudType typeVariable = declaration->tableSymbole->typeu;
        if (typeVariable != INTEGER && typeVariable != INTARRAY) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "le type de la variable '%s' est incorrect", nomVariable);
            message = realloc(message, strlen(message) * sizeof(char));
            listeError = addNewError(listeError, message, declaration->tableSymbole->line);
        }
        }
    }
    return listeError;
}

bool verifierNombreParametres(fonction* fonctionAppelee, int nombreParametres) {
    if (fonctionAppelee->nbParametres != nombreParametres) {
        printf("Erreur : la fonction '%s' attend %d paramètres, mais %d ont été fournis.\n",
            fonctionAppelee->nom, fonctionAppelee->nbParametres, nombreParametres);
        return false;
    }
    return true;
}


noeud* rechercherFonction(noeud* noeudCourant, const char* nomFonction) {
    if (noeudCourant == NULL) {
        return NULL;
    }

    if (noeudCourant->type == FONCTION && strcmp(noeudCourant->tableSymbole->name, nomFonction) == 0) {
        return noeudCourant;
    }

    for (int i = 0; i < noeudCourant->nb_fils; i++) {
        noeud* resultat = rechercherFonction(noeudCourant->fils[i], nomFonction);
        if (resultat != NULL) {
            return resultat;
        }
    }

    return NULL;
}

liste_error* verifierDeclarationFonction(noeud* n, liste_error* liste) {
    afficherArbre(n);
    
    for (int i = 0; i < n->nb_fils; i++) {
        if (n->fils[i] == NULL) {
            continue;
        }
        noeud* fonction = n->fils[i];
        char* nomFonction = fonction->tableSymbole->name;
        // Vérifier si la fonction est unique
        for (int j = 0; j < n->nb_fils; j++) {
            if (n->fils[j] == NULL) {
                continue;
            }
            if (i == j) {
                continue;
            }
            printf("nomFonction : %s\n", nomFonction);
            noeud* autreFonction = n->fils[j];
            if (strcmp(nomFonction, autreFonction->tableSymbole->name) == 0) {
                char* message = malloc(100 * sizeof(char));
                sprintf(message, "la fonction '%s' est déjà déclarée.", nomFonction);
                message = realloc(message, strlen(message) * sizeof(char));
                liste = addNewError(liste, message, autreFonction->tableSymbole->line);
                n->fils[j]=NULL;
                break;
            }
        }
        
        // Vérifier le type de retour de la fonction
        /*si il n'y a pas de return => la fonction doit être void
        si le return n'a pas de fils => la fonction doit être void
        sinon, si le fils de return est une fonction => verifier type de la fonction return si c'est pareil que la fonction en train d'être analysé
        sinon => int*/ 
        NoeudType typeRetour = fonction->tableSymbole->fonction->typeRetour;
        if (typeRetour == INTEGER){
            for (int z=0 ; z<fonction->nb_fils; z++){
                printf("nb_fils : %d\n", fonction->nb_fils);
                if (fonction->fils[z]->type==RETURN){
                    printf("RETUUURN\n");
                    if (fonction->fils[z]->nb_fils==0){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                    }
                    else if (fonction->fils[z]->fils[0]->type==APPELFONCTION){
                        char* nomFonctionReturn = fonction->fils[z]->fils[0]->val;
                        noeud* fonctionReturn = rechercherFonction(n, nomFonctionReturn);
                        for (int k=0; k<fonctionReturn->nb_fils; k++){
                            if (fonctionReturn->fils[k]->type==RETURN){
                                if (fonctionReturn->fils[k]->nb_fils==0){
                                    char* message = malloc(100 * sizeof(char));
                                    sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                                    message = realloc(message, strlen(message) * sizeof(char));
                                    liste = addNewError(liste, message, fonction->tableSymbole->line);
                                }
                                else if (fonctionReturn->fils[k]->fils[0]->tableSymbole->typeu!=INTEGER){
                                    char* message = malloc(100 * sizeof(char));
                                    sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                                    message = realloc(message, strlen(message) * sizeof(char));
                                    liste = addNewError(liste, message, fonction->tableSymbole->line);
                                }
                            }
                        }
                    }
                    else if (fonction->fils[z]->fils[0]->tableSymbole->typeu!=INTEGER){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                    }
                } 
            }
        } else if (typeRetour == VOIDE){
            for (int z=0 ; z<fonction->nb_fils; z++){
                if (fonction->fils[z]->type==RETURN){
                    if (fonction->fils[z]->nb_fils==0){
                        continue;
                    }
                    else if (fonction->fils[z]->fils[0]->type==APPELFONCTION){
                        char* nomFonctionReturn = fonction->fils[z]->fils[0]->val;
                        noeud* fonctionReturn = rechercherFonction(n, nomFonctionReturn);
                        for (int k=0; k<fonctionReturn->nb_fils; k++){
                            if (fonctionReturn->fils[k]->type==RETURN){
                                if (fonctionReturn->fils[k]->nb_fils==0){
                                    continue;
                                }
                                else if (fonctionReturn->fils[k]->fils[0]->tableSymbole->typeu!=VOIDE){
                                    char* message = malloc(100 * sizeof(char));
                                    sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                                    message = realloc(message, strlen(message) * sizeof(char));
                                    liste = addNewError(liste, message, fonction->tableSymbole->line);
                                }
                            }
                        }
                    }
                    else if (fonction->fils[z]->fils[0]->tableSymbole->typeu!=VOIDE){
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "le type de retour de la fonction '%s' est incorrect", nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                    }
                } 
            }
        }
        
        // Vérifier les paramètres de la fonction
        int nbParametres = fonction->tableSymbole->fonction->nbParametres;
        Parametre** parametres = fonction->tableSymbole->fonction->parametres;
        for (int j = 0; j < nbParametres; j++) {
            Parametre* parametre = parametres[j];
            if (parametre->type == APPELFONCTION) {
                char* nomParametre = parametre->nom;
                noeud* fonctionAppel = rechercherFonction(n, nomParametre);
                if (fonctionAppel == NULL) {
                    char* message = malloc(100 * sizeof(char));
                    sprintf(message, "la fonction '%s' utilisée comme paramètre dans la fonction '%s' n'est pas déclarée", nomParametre, nomFonction);
                    message = realloc(message, strlen(message) * sizeof(char));
                    liste = addNewError(liste, message, fonction->tableSymbole->line);
                } else {
                    int nbParametresAttendus = fonctionAppel->tableSymbole->fonction->nbParametres;
                    if (nbParametres != nbParametresAttendus) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "la fonction '%s' utilisée comme paramètre dans la fonction'%s' attend %d paramètres, mais %d paramètres ont été fournis dans la fonction '%s'", nomParametre, nbParametresAttendus, nbParametres, nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                        }
                        // Vérifier le type de retour de la fonction appelée
                        NoeudType typeRetourFonction = fonctionAppel->tableSymbole->fonction->typeRetour;
                        if (typeRetourFonction != INTEGER) {
                        char* message = malloc(100 * sizeof(char));
                        sprintf(message, "le type de retour de la fonction '%s' utilisée comme paramètre dans la fonction '%s' est incorrect", nomParametre, nomFonction);
                        message = realloc(message, strlen(message) * sizeof(char));
                        liste = addNewError(liste, message, fonction->tableSymbole->line);
                    }
                }
            }
        }
    }
    return liste;
}



/* bool verifierDeclarationFonction(fonction* fonction, liste_error* listeError) {
    // Vérification du type de la fonction
    printf("nom de la fonction : %s\n", fonction->nom);
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
        
        // Vérification du nom du paramètre
        char premiereLettre = fonction->parametres[i]->nom[0];
        if (!isalpha(premiereLettre)) {
            char* message = malloc(100 * sizeof(char));
            sprintf(message, "Erreur de déclaration de fonction : le nom du paramètre '%s' de la fonction '%s' ne commence pas par une lettre.\n", fonction->parametres[i]->nom, fonction->nom);
            message = realloc(message, strlen(message) * sizeof(char));
            return false;
        }
        
        // Vérification du type du paramètre
        if (fonction->parametres[i]->type != INTEGER) {
            printf("Erreur de déclaration de fonction : le type du paramètre '%s' de la fonction '%s' n'est pas un entier.\n", fonction->parametres[i]->nom, fonction->nom);
            return false;
        }
    }
    
    return true;
} */

void verifierFonctions(noeud* prog) {
    noeud* listeFonctions = prog->fils[1];
    int nbFils = listeFonctions->nb_fils;
    for (int i = 0; i < nbFils; i++) {
        noeud* fonction = listeFonctions->fils[i];
        // Vérifier si la fonction est unique
        char* nomFonction = fonction->tableSymbole->name;
        for (int j = 0; j < i; j++) {
            if (strcmp(nomFonction, listeFonctions->fils[j]->tableSymbole->name) == 0) {
                printf("Erreur : la fonction '%s' est déclarée plusieurs fois.\n", nomFonction);
                break;
            }
        }

        // Vérifier le type de la fonction
        NoeudType typeFonction = fonction->tableSymbole->fonction->typeRetour;
        if (typeFonction != INTEGER && typeFonction != VOIDE) {
            printf("Erreur : le type de la fonction '%s' est incorrect.\n", nomFonction);
        }

        // Vérifier les paramètres de la fonction
        int nbParametres = fonction->tableSymbole->fonction->nbParametres;
        for (int j = 0; j < nbParametres; j++) {
            Parametre* parametre = fonction->tableSymbole->fonction->parametres[j];
            // Vérifier le type du paramètre
            // Vérifier si le paramètre est de type APPELFONCTION
            if (parametre->type == APPELFONCTION) {
                // Récupérer la fonction appelée
                char* nomFonctionAppelee = parametre->nom;
                noeud* fonctionAppelee = rechercherFonction(prog, nomFonctionAppelee);
                if (fonctionAppelee == NULL) {
                    printf("Erreur : la fonction '%s' appelée dans le paramètre '%s' de la fonction '%s' n'existe pas.\n", nomFonctionAppelee, parametre->nom, nomFonction);
                } else {
                    // Vérifier le nombre de paramètres attendu
                    int nbParametresAttendus = fonctionAppelee->tableSymbole->fonction->nbParametres;
                    if (nbParametres != nbParametresAttendus) {
                        printf("Erreur : la fonction '%s' appelée dans le paramètre '%s' de la fonction '%s' ne prend pas le bon nombre de paramètres.\n", nomFonctionAppelee, parametre->nom, nomFonction);
                    }
                }
            }
            if (parametre->type != INTEGER) {
                printf("Erreur : le type du paramètre '%s' de la fonction '%s' est incorrect.\n", parametre->nom, nomFonction);
            }
        }
    }
}


void verifierAffectations(noeud* bloc) {
    for (int i = 0; i < bloc->nb_fils; i++){
        noeud* instruction = bloc->fils[i];
        if (instruction->type == AFFECTATION) {
            noeud* variable = instruction->fils[0];
            noeud* valeur = instruction->fils[1];

            char* nomVariable = variable->val;
            noeud* declaration = rechercherNoeud(bloc, nomVariable);

            if (declaration == NULL) {
                printf("Erreur : la variable '%s' n'est pas déclarée dans le bloc.\n", nomVariable);
            } else {
                if (valeur->type== APPELFONCTION) {
                    noeud* fonction = rechercherFonction(bloc, valeur->val);
                    if (fonction != NULL) {
                        NoeudType typeRetour = fonction->tableSymbole->fonction->typeRetour;
                        if (typeRetour != INTEGER) {
                            printf("Erreur : la fonction '%s' ne retourne pas un type INT.\n", valeur->val);
                        }
                    } else {
                        printf("Erreur : la fonction '%s' n'est pas déclarée dans le bloc.\n", valeur->val);
                    }
                } else {
                    NoeudType typeValeur = valeur->tableSymbole->typeu;
                    if (typeValeur != INTEGER) {
                        printf("Erreur : la variable '%s' doit être affectée avec une valeur de type INT.\n", nomVariable);
                    }
                }
            }
        }
    }
}
