#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* 
 *David Seekatz				16das4 20037710
 *Sean Eylott				13se18 10141657
 *Simon Ungar        			14seau 10149546
 *Brooke Resendes   			13brr2 10141112
 */

/* This program capitalizes the first letter of every other word, starting from
the first word of each line.

It takes the filename to capitalize its test as a command-line argument.

The program updates the file with the capitalized test. 

Simon Ungar, November 20th, 2016. v1.1
*/
int main(int argc, char *argv[]) {
FILE *fp;
char string[255];
fp = fopen(argv[1], "r+");
long pos = ftell(fp);
while(fgets(string, 255, fp) != NULL) {
	int i;
	int len = strlen(string);
	int wordNum = 1;
	string[0] = toupper(string[0]);
	for (i=1 ; i < len ; i++) {
		if (isalpha(string[i]) && string[i-1] == ' '){
			// only first letters of a word
			if ((wordNum % 2) == 0) {
			string[i] = toupper(string[i]);
			}
			wordNum++;
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

