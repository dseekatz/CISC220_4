#include<stdio.h>
#include<stdin.h>

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
char buff[255];

fp = fopen(argv[1], "r+");
fgets(buff, 255, fp);
}


