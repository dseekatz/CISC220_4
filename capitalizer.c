#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/*this will be Question 3 of assignment 4.

We have to read in a text file,

then capitalize the first letter of every other word,
starting from the first word of each line

then we have to update the file, so that if we cat() the new file, it will 
print the capitalized file.

(don't create a new file)

going to use mode "r+" to read,write and then override on write

argv[1] is the first argument passed to our program

*/
int main(int argc, char *argv[]) {
FILE *fp;
char string[255];
fp = fopen(argv[1], "r+");
long pos = ftell(fp);
while(fgets(string, 255, fp) != NULL) {
	int i;
	int len = strlen(string);
	string[0] = toupper(string[0]);
	for (i=1 ; i < len ; i++) {
		if (isalpha(string[i]) && string[i-1] == ' '){
			// only first letters of a word
			string[i] = toupper(string[i]);
		}
	}
	fseek(fp, pos, SEEK_SET);
	fprintf(fp, "%s", string);
	fflush(fp);
	pos = ftell(fp);
}
fclose(fp);
return 0;
}








