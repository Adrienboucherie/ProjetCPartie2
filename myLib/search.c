#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>

struct dirItem{
	char nom[90000];
	char chemin[90000];
	struct dirItem *dirContent;
	struct dirItem *suivant;
};

typedef struct dirItem * Liste;

void search(char *args, Liste liste){

    while(liste != NULL){

        if(!strcmp(liste->nom, args)){
            printf("%s \n", liste->chemin);
        }

        if(liste->dirContent != NULL){
            search(args, liste->dirContent);
        }
        

        liste = liste->suivant;
	} 

}
