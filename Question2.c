//Question2
//i) Write a function char* safestrcat(char *a, char *b) 
#include<string.h>
#include<stdio.h>

//Returns a new string containing the string in a followed by the string in b
char *safestrcat(char *a, char *b) {
	char *x[255];
	x = strcat(a,b);
	return x; //return the new string x 
}

//main function
int main() {
	printf("%s\n", *safestrcat (char *a, char *b));
}
	
