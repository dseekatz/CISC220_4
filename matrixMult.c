#include<stdio.h>
#include<stdlib.h>

/* This program multiplies matrices together.  The user supplies the dimensions for two matrices,
 * as well as the values for each cell of the matrix.  The program then multiplies the matrices together
 * provided the dimensions and data are valid, and the user is propmpted to enter the information for
 * another matrix to be multiplied.
 */

void printMatrix(int *mptr, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d\t", *mptr);
			mptr++;
		} /* End for loop */
		printf("\n");
	} /* End for loop */
} /* End printMatrix */

void setMatrix(int *mptr, int rows, int cols) {
	int i;
	int status;
	for (i = 0; i < rows*cols; i++) {
		status = scanf("%d", mptr);
		if (status == 0) {
			fprintf(stderr, "Invalid Input\n");
			exit(-1);
		} /* End conditional */
		mptr++;
	} /* End for loop */
} /* End setMatrix */

int main() {
	/* Get the dimensions of the matrices */
	printf("Insert matrix 1 dimensions separated by a space: ");
	int row1;
	int col1;
	scanf("%d %d",&row1,&col1);
	printf("Insert matrix 2 dimensions separated by a space: ");
	int row2;
	int col2;
	scanf("%d %d",&row2,&col2);
	while (col1 != row2) {
		fprintf(stderr,"Dimensions Mismatch\n");
		printf("Please re-enter the dimensions for matrix 2. The number of rows should be %d: ", col1);
		scanf("%d %d",&row2,&col2);
	} /* End while loop */
	
	/* Get the matrix elements and check that they are valid */
	int matrix1[row1][col1];
	int matrix2[row2][col2];
	int *ptr = &matrix1[0][0];
	printf("Input matrix 1 elements separated by spaces (there should be %d elements): ", row1*col1);
	setMatrix(ptr, row1, col1);
	ptr = &matrix2[0][0];
	printf("Input matrix 2 elements separated by spaces (there should be %d elements): ", row2*col2);
	setMatrix(ptr, row2, col2);

	/* Print the matrices */
	printf("\nMatrix 1:\n");
	printMatrix(&matrix1[0][0], row1, col1);
	printf("\nMatrix 2:\n");
	printMatrix(&matrix2[0][0], row2, col2);
	return 0;
} /* End main */
