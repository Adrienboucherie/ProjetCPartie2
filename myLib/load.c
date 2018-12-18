#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

struct dirItem{
	char nom[90000];
	char chemin[90000];
	struct dirItem *dirContent;
	struct dirItem *suivant;
};

typedef struct dirItem * Liste;

void load_liste(char *chemin, Liste *liste){

	DIR *dir;
  	struct dirent *ent;

	Liste pt1 = malloc(sizeof(struct dirItem));
	Liste pt2 = malloc(sizeof(struct dirItem));
	Liste suivpt = malloc(sizeof(struct dirItem));
	
	int premier = 0;

  	dir = opendir(chemin);

    if (dir==NULL){
        printf("ERREUR LORS DE L'OUVERTURE DE %s (%s)\n", chemin, strerror(errno)); 
        return;
    }

  	while((ent=readdir(dir)) != NULL){//Tant que dir n'est pas null
		  
    	if(strcmp(".", ent->d_name) && strcmp("..", ent->d_name)){

			if(premier == 0){ //Pour le premier passage
				
				strcpy((*liste)->nom, ent->d_name);
    			sprintf((*liste)->chemin, "%s/%s", chemin, (*liste)->nom);
				(*liste)->dirContent = NULL;
				(*liste)->suivant = NULL;
				pt1 = *liste;
				premier = 1;
			} else { //Passages suivants
				suivpt = malloc(sizeof(struct dirItem));
				
				strcpy(suivpt->nom, ent->d_name);
    			sprintf(suivpt->chemin, "%s/%s", chemin, suivpt->nom);
				suivpt->suivant = NULL;
				suivpt->dirContent = NULL;
				pt1->suivant = suivpt;
				pt1 = suivpt;
			}

			if(ent->d_type & DT_DIR){ //Si c'est un dossier
				pt2 = malloc(sizeof(struct dirItem));
				load_liste(pt1->chemin, &pt2); //On charge
				if(strcmp(pt2->nom, "")){
					pt1->dirContent = pt2;
				}
			}
    	}
  	}
  	closedir(dir);
}
