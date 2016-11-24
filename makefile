#Makefile

#Compile each c and h program by itself to obtain object codes
mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c
main.o: main.c; gcc -Wall -c main.c
copier: main.o mystring.o
	gcc -Wall -o copier mystring.o main.o #link them together by combining all the object code from all of the source file
