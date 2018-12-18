#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>

int parse(const char *src, char *v1, char *v2){

	if(sscanf(src, "%[A-z:/.0-9] = %[A-z:/.0-9]", v1, v2) == 2){
		return 0;
	} else {
		return 1;
	}
}