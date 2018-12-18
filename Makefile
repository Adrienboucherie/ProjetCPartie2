	# règle implicite
%: %.c
	gcc -Wall -o $@ $@.c

	# règles spécifiques
treetest: treetest.c
	gcc -Wall -o $@ $@.c -lreadline -LmyLib -lmylib

treeload: treeload.c
	gcc -Wall -o $@ $@.c -lreadline -LmyLib -lmylib

treesearch: treesearch.c
		gcc -Wall -o $@ $@.c -lreadline -LmyLib -lmylib