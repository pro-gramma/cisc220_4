mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c

main.o: main.c
	gcc -Wall -c main.c

copier: mystring.o main.o
	gcc -Wall -o copier mystring.o main.o