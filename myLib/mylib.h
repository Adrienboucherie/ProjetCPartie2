#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>

//load.c

struct dirItem{
	char nom[90000];
	char chemin[90000];
	struct dirItem *dirContent;
	struct dirItem *suivant;
};

typedef struct dirItem * Liste;

void load_liste(char *, Liste *);

//parse.c

int parse(const char *, char *, char *);

//search.c

void search(char *, Liste);