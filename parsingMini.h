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
    AFFECTATION,
    VOIDE
} NoeudType;

typedef struct liste_noeud {
    int nb_noeud;
    struct noeud **liste_noeud; // tableau de pointeurs vers les noeuds
} liste_noeud;

typedef struct {
    char* nom;
    NoeudType type;
} Parametre;

// pour stocker info sur fonction
typedef struct {
    char* nom;
    NoeudType typeRetour;
    liste_noeud* declaration;
    Parametre **parametres; // tableau de pointeurs vers les parametres
    int nbParametres;
} fonction;

typedef struct {
    int* dimensions;
    int nb_dimensions;
} TableauDimensions;

typedef struct tableSymbole { 
    char* name;
    TableauDimensions* tabDim;
    int tailleTab;
    NoeudType typeu;           // Type du noeud
    fonction *fonction;  // Référence à la fonction associée (le cas échéant)
    int line;
} tableSymbole;

typedef struct noeud {
    char *val;                 // Valeur du noeud
    struct noeud **fils;       // Tableau de pointeurs vers les fils
    int nb_fils;               // Nombre de fils
    typeNoeud type;            // Type du noeud DOT
    tableSymbole *tableSymbole;  // Référence au symbole associé (le cas échéant)
} noeud;

// pour stocker info su param et type


noeud* addTypeNoeud(noeud* n, char* t);

// Convertie un type en string
char* typeToString(NoeudType typeu);

// Libère la mémoire allouée à un noeud
void libererNoeud(noeud* n);

// Affiche le noeud
void afficherNoeud(noeud* n);

// Convertie un string en type
int stringToType(char* type);

// Recherche une valeur dans un noeud
noeud* rechercherNoeud(noeud* n, char* valeur);

// Création d'un nouveau noeud avec une valeur et un nombre de fils donnés
noeud* creerNoeud(char* val);

// Ajout d'une taille à un noeud
noeud* addSize(noeud* n, int size);

// Ajout d'un fils à un noeud
noeud* addChild(noeud* n, noeud* child);

// Ajout des fils d'une liste de noeuds à un noeud
noeud* addAllChild(noeud* n, liste_noeud* f);

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
bool verifierDeclarationFonction(fonction* fonction);

//compare le nombre de parametres de la fonction appelée avec le nombre de parametres de la fonction déclarée
bool verifierNombreParametres(fonction* fonctionAppelee, int nombreParametres);

// check si ident ne porte pas le nom d'un mot clé
bool checkIdentName(char* name);

// ajoute une dimension et sa taille à un tableau
void ajouterDimensionTableau(noeud* tableau, int taille);

// declare un tableau
noeud* declarerTableau(noeud* arbre, char* nomTableau, int taille, int dimensions);

// declare une nouvelle fonction
noeud* newFunction(noeud* n, char* nameFunction, noeud* typeFunction, liste_noeud* parametres, int line);

// declare une nouvelle variable
noeud* newVariable(char* name, int line);

// verif si var est un int ou un int[] et es declarer
void verifierDeclarations(noeud* listeDeclarations);
//verif si fonction est déclarée
void verifierFonctions(noeud* listeFonctions);

// regarde si une fonction est déclarée dans le noeud
noeud* rechercherFonction(noeud* noeudCourant, const char* nomFonction);

// check si cest un bloc
 void checkInBlock(noeud* n);
// verif global sur les fonctions
void verifierFonctions(noeud* prog);