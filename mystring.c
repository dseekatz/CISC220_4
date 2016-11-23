#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"

char* safestrcat(char *a, char *b) {
	char *result = malloc(strlen(a)+strlen(b)+1);
	strcat(result,a);
	strcat(result,b);
	return result;
}

int substring(char *source, int from, int n, char *target) {
	if (source == NULL || (n+from) > strlen(source)) {
		fprintf(stderr,"Error!\n");
		return -1;
	}
	source += from;
	memmove(target, source,n);
	printf("%s\n", target);
	return 0;
}
