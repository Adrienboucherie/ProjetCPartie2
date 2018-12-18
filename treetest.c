#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "myLib/mylib.h"
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>

#define CONFIGFILE "tree.conf"
#define L 100

void handler(){

	

}

int main(int nbarg, char *args[])
{

	FILE *config; 
	FILE *configPID;					//Fichier de conf
	char configL[L]; 				//Ligne du fichier de conf
	char rootdir[L]; 				//Repertoire de base dans le fichier tree.conf
	char datafile[L];
	char pidfile[L];
	char v1[L], v2[L]; 				//Variables utilisées pour recuperer le repertoire de base
	Liste liste = NULL;				//Initialisation de la liste

	liste = malloc(sizeof(struct dirItem)); 			//Allocation de mémoire à la liste

	config = fopen(CONFIGFILE,"r");					//Ouvre le fichier tree.conf
	if(config == NULL){								//Si il est vide, retourne 1
		perror (CONFIGFILE);
		return 1;
	}

	while(fgets(configL,L-1,config)!=NULL){				//Tant qu'il y a du contenu dans tree.conf
  		if(configL[0] != '#'){							//Si la ligne ne commence pas par "#"
  			parse(configL, v1, v2);						//Sépare la variable de sa valeur
  			//printf("\"%s\" : \"%s\" \n", v1, v2);		//Affiche la variable : la valeur
  			if(strcmp(v1, rootdir)){
  				strcpy(rootdir, v2);
  			}
			if(strcmp(v1, datafile)){
				strcpy(datafile, v2);
			}
			if(strcmp(v1, pidfile)){
				strcpy(pidfile, v2);
			}
  		}
	}

	load_liste(rootdir, &liste);	//Charge la liste à partir du fichier de conf (recursif)

	
	char PID[L];
	configPID = fopen(pidfile,"w+");
	sprintf(PID, "%i", getpid());
	fputs(PID, configPID);
	printf("%s", PID);
	fclose(configPID);
	

	
	signal(SIGHUP, handler);
	for(;;);

	//printf("Chemin(s) vers %s \n", args[1]);
	search(args[1], liste); //Cherche l'argument placé dans l'appel du programme dans la liste (puis de façon recursive)

	return 0;
}