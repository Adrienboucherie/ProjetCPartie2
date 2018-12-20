all : treeload treesearch

treesearch : treesearch.c mylib/libmylib.a
	gcc -Wall -o $@ $@.c -lreadline -Lmylib -lmylib

treeload : treeload.c mylib/libmylib.a
	gcc -Wall -o $@ $@.c -lreadline -Lmylib -lmylib