#include "mylib.h"

// VERIFIE SI UN CHEMIN SE TERMINE (i.e. APRES LE DERNIER "/") PAR UN NOM DONNE
void compare_chemins(char nom_du_fichier_a_tester[], char chemin_a_tester[], int *compteurDeCorres) {

    // '/' est le caractère qui définit la fin du chemin
    const char separation = '/';

    char *ret;
    char chemin_relatif[256] = "/";

    // on coupe le chemin à tester après le dernier "/" : il nous reste la fin du chemin, soit "/nom_du_fichier"
    ret = strrchr(chemin_a_tester, separation);

    // on écrit le nom du fichier à tester sous la forme "/nom_du_fichier_à_tester"
    strcat(chemin_relatif, nom_du_fichier_a_tester);

    // on teste si "/nom_du_fichier" = "/nom_du_fichier_à_tester"
    // Si c'est le cas, on affiche le chemin complet
    if (strcmp(chemin_relatif, ret) == 0)
    {
        (*compteurDeCorres) ++;
        //printf("%d\n", *i);
        printf("%s\n", chemin_a_tester );
    }
}