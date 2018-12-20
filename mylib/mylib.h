#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define FICHIER_CONFIG "tree.conf"
#define L 60

// DEFINITION DE LA STRUCTURE POUR ENREGISTRER L'ARBORESCENCE : UNE LISTE CHAINEE
struct adresse_de_fichier
{
    char chemin[256];
    struct adresse_de_fichier * suiv;
};

typedef struct adresse_de_fichier * arborescence;


// PROTOTYPES DES PROCEDURES UTILISEES
void ajout_chemin (char chemin_a_ajouter[], arborescence *arbo);
void load(char cheminDossier[], arborescence *arbo);
void affiche_arborescence(arborescence arbo);
void compare_chemins(char nom_du_fichier_a_tester[], char chemin_a_tester[], int *compteurDeCorres);
void search(char nom_du_fichier_a_trouve[], arborescence arbo);
