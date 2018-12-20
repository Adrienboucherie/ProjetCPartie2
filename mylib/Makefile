%: %.c mylib.h
	gcc -Wall -c  $@

libmylib.a : search.o load.o compare_chemins.o ajout_chemin.o affiche_arborescence.o
	ar -rs $@ $^
