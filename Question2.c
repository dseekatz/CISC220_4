//Question2
//i) Write a function char* safestrcat(char *a, char *b) 
#include<string.h>
#include<stdio.h>

//main function
int main() {
	printf("%s\n", *safestrcat());
}

//Returns a new string containing the string in a followed by the string in b
//does it automatically return?
char* safestrcat(char *a, char *b) {
	char buf[255];
	char str *x = strcat(a,b);
	return x; //return the new string x 
}	
