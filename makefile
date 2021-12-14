.PHONY: clean all

all: stringProg

stringProg: main.o lib_string_parse.a
	gcc -Wall -g main.o lib_string_parse.a -o stringProg

main.o: main.c string_parse.h
	gcc -Wall -g -c main.c

lib_string_parse.a: string_parse.o
	ar -rcs lib_string_parse.a string_parse.o

string_parse.o: string_parse.c string_parse.h
	gcc -Wall -g -c string_parse.c

clean:
	rm -f *.o *.a stringProg
