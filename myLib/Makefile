%: %.c mylib.h
	gcc -c $<

libmylib.a: load.o search.o parse.o
	ar -rs $@ $^
