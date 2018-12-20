#include "mylib.h"

// FONCTION LOAD QUI CHARGE L'ARBORESCENCE DANS UNE LISTE CHAINEE
void load(char cheminFichier[], arborescence *arbo)
{
    char chemin[4096];
    struct dirent *lecture;
    DIR *rep;

    rep = opendir(cheminFichier);
    //printf("%s\n", cheminDossier );
    
    if (rep == NULL)
    {
       // perror("Erreur ");
       // printf("Impossible de charger le fichier %s\n\n", cheminFichier); //permet de repérer si un fichier ne peut pas être parcouru par l'utilisateur
    }
    else
    {
        ajout_chemin(cheminFichier, &(*arbo));

        while ((lecture = readdir(rep))!=NULL)
        {
            if (lecture->d_type == DT_DIR) // Si c'est un dossier, on rentre dedans pour charger l'arbo
            {
                if (strcmp(lecture->d_name, ".")!=0 && strcmp(lecture->d_name, "..")!=0)
                { 
                    strcpy(chemin, cheminFichier);
                    if (strcmp(cheminFichier, "/")!=0) strcat(chemin,"/"); // pour ne pas recopier / si on part du répertoire racine
                    strcat(chemin, lecture->d_name);

                    load(chemin, &(*arbo));
                }
            }
            else
            {   
                strcpy(chemin, cheminFichier);
                strcat(chemin,"/");
                strcat(chemin, lecture->d_name);
                ajout_chemin(chemin, &(*arbo));
            }
        }
    }
    closedir(rep);
}
