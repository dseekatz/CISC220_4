#include <stdio.h>
#include "mystring.h"

//Main function to initate the entirety of Question 2 for this assignment
int main() {
	char* string1;
	char target[255] = {0}; //null character to signify end of string
	string1 = safestrcat("Apple","pie");
	printf("%s\n", string1);
	
	substring("CISC220", 4,3, target);
	return 0;
}
