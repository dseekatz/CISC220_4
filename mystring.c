#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mystring.h"
/* This program concatenates two parameters, returning the new string, in the safestrcat function
 and removes a desired substring from a parameter in the substring function.

Sean Eylott 10141657
*/


//safestrcat returns the concatenated version of the two parameters, a and b, in a new
// variable called result.

char* safestrcat(char *a, char *b) {
	char *result = malloc(strlen(a)+strlen(b)+1);
	strcat(result,a);
	strcat(result,b);
	return result;
} // End safestrcat


/* substring takes a string source and returns a substring, stored in target.
The substring is specified using from(the starting index) and n(the number of characters
 to be copied in substring). The substring is then stored in target.
0 is returned on success and -1 on failure.
 substring checks if source is empty, or if the wished index is larger than the length of
 source. If an error occurs, Error is outputted to the user and -1 is returned.
*/

int substring(char *source, int from, int n, char *target) {
	if (source == NULL || (n+from) > strlen(source)) {
		fprintf(stderr,"Error!\n");
		return -1;
	} // End if statement
	source += from;
	memmove(target, source,n);
	printf("%s\n", target);
	return 0;
} // End substring
