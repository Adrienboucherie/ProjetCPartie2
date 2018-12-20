#include "mylib/mylib.h"


    char searchedfile[L];
    char nomDatafile[L];
    char nomPidfile[L];
    char pidTreeloadString[L];
    FILE *config = NULL;
    FILE *fichierDatafile = NULL;
    FILE *fichierPidFile = NULL;
    int pidTreeload;

int main(int argc, char const *argv[]){
       


    
        config = fopen(FICHIER_CONFIG, "r");

      
            
            while (strcmp((fgets(nomDatafile,10,config)), "datafile=") != 0); 
            fgets(nomDatafile,L,config);                
            nomDatafile[strlen(nomDatafile)-1] = 0 ;    

            fseek(config, 0, SEEK_SET);     //se positionne dans le fichier            
            while (strcmp((fgets(nomPidfile,9,config)), "pidfile=") != 0); 
            fgets(nomPidfile,L,config);                 
            nomPidfile[strlen(nomPidfile)-1] = 0 ; 
            fclose(config);


        fichierDatafile = fopen(nomDatafile,"w+");

        
            strcpy(searchedfile, argv[1]);          //On récupère le fichier qu'on veut rechercher
            fputs(searchedfile,fichierDatafile);    //On met ce fichier dans /tmp/treeload.data
            fclose(fichierDatafile);



        fichierPidFile = fopen(nomPidfile,"r");
        
        if (fichierPidFile==NULL)
        {
            perror(nomPidfile) ;
        }
        else
        {   
            fgets(pidTreeloadString, L, fichierPidFile);    
            pidTreeload = atoi(pidTreeloadString);          //On converti le
            kill(pidTreeload, SIGHUP);                      //On envoie le signal SIGHUP à treeload
        }

        return 0;
    }
