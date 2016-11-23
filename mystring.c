#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

//safestrcat returns a new string containing string a followed by string b
char* safestrcat(char *a, char *b) {
	char *result = malloc(strlen(a)+strlen(b)+1);
	strcat(result,a);
	strcat(result,b);
	return result;
}

//substring gets a substring from within a string
int substring(char *source, int from, int n, char *target) {
	if (source == NULL || (n+from) > strlen(source)) {
		fprintf(stderr,"Error!\n");
		return -1; //Return -1 upon failure
	}
	source += from;
	memmove(target, source,n);
	printf("%s\n", target);
	return 0; //Return 0 upon success
}
