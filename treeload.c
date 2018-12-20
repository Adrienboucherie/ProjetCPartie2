#include "mylib/mylib.h"


FILE *config = NULL;
FILE *DATAFILE = NULL;
FILE *PIDFILE = NULL;
arborescence Liste = NULL;


void handler()
{	
	char DATA[L];
	char DIR_SEARCHED[L];


	config = fopen(FICHIER_CONFIG, "r");

	
		while (strcmp((fgets(DATA,10,config)), "datafile=") != 0); 
		fgets(DATA,L,config); 				
		DATA[strlen(DATA)-1] = 0 ; 	
	

	fclose(config);


		DATAFILE = fopen(DATA, "r");	
		fgets(DIR_SEARCHED,L,DATAFILE);   //On récupère le fichier a chercher qui se situe dans /tmp/treeload.data
		search(DIR_SEARCHED, Liste); 
		fclose(DATAFILE);
}



int main(int argc, char  *argv[])
{	
	char rootdir[L];
	char PID[L];
	char pidTreeload[L];



	config = fopen(FICHIER_CONFIG, "r");

	if (config==NULL)
	{
		perror(FICHIER_CONFIG) ;
		return 1 ;
	}
	else
	{	
		
		while (strcmp((fgets(rootdir,9,config)), "rootdir=") != 0);
		fgets(rootdir,L,config); 				
		rootdir[strlen(rootdir)-1] = 0 ; 		

		fseek(config, 0, SEEK_SET); 			

        while (strcmp((fgets(PID,9,config)), "pidfile=") != 0); 
        fgets(PID,L,config); 			
        PID[strlen(PID)-1] = 0 ; 	




			load(rootdir, &Liste); // On charge les infos a partir de /var/ dans une liste chainée
		


		

	   	PIDFILE = fopen(PID,"w+");

	    if(PIDFILE==NULL)
	    {
	        perror(PID); 
	    }
	    else
	    {
		    sprintf(pidTreeload, "%d", getpid());	//On récupère le PID 
		    fputs(pidTreeload,PIDFILE);		// on écrit le pid dans /tmp/treeload.pid
	    }

	    fclose(PIDFILE);



	  	signal(SIGHUP, handler);  //On attend le signal
		for(;;); 				  //On fait une boucle infinie pour que le programme ne s'arrête pas et qu'on puisse envoyer plusieurs signaux
	}

	fclose(config);

return 0;

}