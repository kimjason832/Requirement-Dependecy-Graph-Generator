# default target
all: main

# target name to compile and link all files
main: main.o parse.o dependency.o
	gcc main.o parse.o dependency.o -std=c11 -Wall -o main

# target for main
main.o: main.c parse.h dependency.h
	gcc main.c -c -std=c11 -Wall -o main.o

# target for parse
parse.o: parse.c parse.h dependency.h
	gcc parse.c -c -std=c11 -Wall -o parse.o 

# target for dependency
dependency.o: dependency.c dependency.h
	gcc dependency.c -c -std=c11 -Wall -o dependency.o

# clean/remove all compiled files
clean:
	rm -f main
	rm -f *.o