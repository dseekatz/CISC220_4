//Question2
//i) Write a function char* safestrcat(char *a, char *b) 
#include<string.h>
#include<stdio.h>

//Returns a new string containing the string in a followed by the string in b
char *safestrcat(char *a, char *b) {
	char *x; 
	x = strcat(a,b);
	return x; //return the new string x 
}

//creating a parameter for the substring??
int substring(char *source, int from, int n, char *target) {
	int i = 0;
	int length = 0;
	char target[255];
	printf("Please input a string\n");
	gets(source); //gets string input

	printf("Please enter the starting index of the substring\n");
	gets(from); //gets starting index

	if (strstr(source)) = NULL { //If the string is empty return -1
		return(-1);

	while (i < length) {
		target[i] = source[from+i,n-1];//idk lol
		return(0);
		i++; //increment i
}
	printf("The substring is \"$s\"\n", target);
}


//main function
int main() {
	printf("%d\n", *safestrcat); //1 error: it is saying there is an error with %s, cant figure it out
}
	
