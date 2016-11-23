#Makefile
mystring.o: mystring.c mystring.h
	gcc -Wall -c calc.c
main.o: main.c
	 gcc -Wall -c main.c
main: main.o mystring.o
	gcc -Wall -o main main.o mystring.o
