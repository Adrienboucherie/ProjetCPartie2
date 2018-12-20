#include "mylib.h"

// POUR PARCOURIR ET AFFICHER LA LISTE CHAINEE
void affiche_arborescence(arborescence arbo)
{
//arborescence arbo_temp = arbo;

    while (arbo != NULL){
        printf("%s\n", arbo->chemin);
        arbo = arbo->suiv;
    }
}
