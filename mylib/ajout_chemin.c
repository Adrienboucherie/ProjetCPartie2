#include "mylib.h"

// POUR EMPILER LE CHEMIN D'UN FICHIER
void ajout_chemin (char chemin_a_ajouter[], arborescence *arbo)
{
    arborescence arbo_temp;
    (arbo_temp) = malloc(sizeof(struct adresse_de_fichier));

    strcpy(arbo_temp->chemin, chemin_a_ajouter);

    (arbo_temp)->suiv = *arbo;

    *arbo = arbo_temp;
}