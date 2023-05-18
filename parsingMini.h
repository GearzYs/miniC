#include <stdbool.h>
typedef enum {
    IF,
    BREAK,
    FONCTION,
    APPELFONCTION,  
    ARGUMENT,
    RETURN
} typeNoeud;

typedef enum {
    NULLTYPE,
    INTEGER,
    INTARRAY,
    FUNCTION,
    VOIDE
} NoeudType;

typedef struct noeud {
    char *val;                 // Valeur du noeud
    struct noeud **fils;       // Tableau de pointeurs vers les fils
    typeNoeud type;            // Type du noeud
    int size_tab;              // Taille du tableau de fils
    int nb_fils;               // Nombre de fils
    NoeudType typeu;           // Type du noeud
    struct Fonction *fonction;  // Référence à la fonction associée (le cas échéant)
} noeud;

typedef struct liste_noeud {
    int nb_noeud;
    struct noeud **liste_noeud;
} liste_noeud;

typedef struct liste_chaine_noeud {
    noeud *n;
    struct liste_chaine_noeud *next;
} liste_chaine_noeud;

// pour stocker info su param et type
typedef struct {
    char* nom;
    NoeudType type;
} Parametre;

// pour stocker info sur fonction
typedef struct {
    char* nom;
    NoeudType typeRetour;
    Parametre* parametres;
    int nbParametres;
    int nb_fonctions;
} Fonction;

liste_chaine_noeud* creerListeChaineNoeud(noeud* n);

liste_chaine_noeud* addListeChaineNoeud(liste_chaine_noeud* l, noeud* n);


noeud* addTypeNoeud(noeud* n, char* t);

void libererNoeud(noeud* n);


void afficherNoeud(noeud* n);


noeud* rechercherNoeud(noeud* n, char* valeur);


// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val);

// Ajout d'une taille à un noeud
noeud* addSize(noeud* n, int size);


noeud* addChild(noeud* n, noeud* child);


noeud* addAllChild(noeud* n, liste_chaine_noeud* l);

// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val);

// Ajout d'un fils à un noeud
noeud* appendChild1(noeud* n, noeud* child) ;

// Ajout 2 fils à un noeud
noeud* appendChild2(noeud* n, noeud* child1, noeud* child2);

// Ajout 3 fils à un noeud
noeud* appendChild3(noeud* n, noeud* child1, noeud* child2, noeud* child3);

// Ajout 4 fils à un noeud
noeud* appendChild4(noeud* n, noeud* child1, noeud* child2, noeud* child3, noeud* child4);

// Affichage récursif de l'arbre à partir d'un noeud donné
void afficherArbre(noeud* n);

// Création d'une liste de fonctions contenant des noeuds
liste_noeud* creerListeNoeud(noeud* n);

// Ajout d'une fonction à la liste de fonctions
liste_noeud* addNoeud(liste_noeud* f, noeud* n);

//Convertie une structure arbre en Dot
void arbreToDot(noeud* n, int* COMPTEUR, FILE* fp);

//Génère un fichier .dot à partir d'un arbre
void generateDotFile(liste_noeud* n);

//Permet de changer la forme d'un noeud en fonction de son type
void nodeType(FILE* f, noeud* n, int* COMPTEUR);

//Vide le fichier .dot
void clearFile();

//Vérifie si un noeud est de type attendu(pour une var c'est int)
bool verifierTypeNoeud(noeud* n, NoeudType typeAttendu);

// verif si premiere lettre est une string
bool firstLetterIsString(noeud* n);

// verif si var est un int ou un int[]
bool varTypeIsIntOrIntArray(noeud* n);

// verif si fonction est déclarée
bool functionIsDeclared(noeud* n, char* nameFunction);

// verif global sur fonction 
bool verifierDeclarationFonction(Fonction* fonction);

