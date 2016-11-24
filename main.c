#include <stdio.h>
#include "mystring.h"

/* David Seekatz				16das4 20037710
 *Sean Eylott				13se18 10141657
 *Simon Ungar        			14seau 10149546
 *Brooke Resendes   			13brr2 10141112
 */

//Main function to initate the entirety of Question 2 for this assignment
int main() {
	char* string1;
	char target[255] = {0}; //null character to signify end of string
	string1 = safestrcat("Apple","pie");
	printf("%s\n", string1);
	
	substring("CISC220", 4,3, target);
	return 0;
}
