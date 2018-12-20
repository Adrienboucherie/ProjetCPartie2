#include "mylib.h"

// POUR CHERCHER LE CHEMIN D'UN FICHIER DONNE EN PROMPT
void search(char nom_du_fichier_a_trouve[], arborescence arbo){

int compteurDeCorres=0;

	if (arbo != NULL){
		while (arbo->suiv != NULL){ // on s'arrête à l'avant dernier (dernier maillon = maillon père)
            compare_chemins(nom_du_fichier_a_trouve, arbo->chemin, &compteurDeCorres);
            arbo = arbo->suiv;
	    }
	}

	if (compteurDeCorres==0)
    	printf("Pas de chemin pour '%s'\n\n", nom_du_fichier_a_trouve );
    
    
}