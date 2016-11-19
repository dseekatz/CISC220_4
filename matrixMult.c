#include<stdio.h>
#include<stdlib.h>

/* This program multiplies matrices together.  The user supplies the dimensions for two matrices,
 * as well as the values for each cell of the matrix.  The program then multiplies the matrices together
 * provided the dimensions and data are valid, and the user is propmpted to enter the information for
 * another matrix to be multiplied.
 */

/* Define a matrix structure to make passing arguments to functions more concise */
typedef struct {
	int *mptr;
	int rows;
	int cols;
} matrix;

/* This function displays a matrix */
void printMatrix(matrix *m) {
	int i, j;
	for (i = 0; i < m->rows; i++) {
		for (j = 0; j < m->cols; j++) {
			printf("%d\t", *(m->mptr));
			(m->mptr)++;
		} /* End for loop */
		printf("\n");
	} /* End for loop */
} /* End printMatrix */

/* This function populates a matrix with values inputted by the user */
void setMatrix(matrix *m) {
	int i;
	int status;
	for (i = 0; i < (m->rows)*(m->cols); i++) {
		status = scanf("%d", m->mptr);
		if (status == 0) {
			fprintf(stderr, "Invalid Input\n");
			exit(-1);
		} /* End conditional */
		(m->mptr)++;
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
	int *ptr1 = &matrix1[0][0];
	matrix m1 = {ptr1, row1, col1};
	printf("Input matrix 1 elements separated by spaces (there should be %d elements): ", row1*col1);
	setMatrix(&m1);
	int *ptr2 = &matrix2[0][0];
	matrix m2 = {ptr2, row2, col2};
	printf("Input matrix 2 elements separated by spaces (there should be %d elements): ", row2*col2);
	setMatrix(&m2);

	/* Print the matrices */
	m1.mptr = &matrix1[0][0];	/* Reset pointers */
	m2.mptr = &matrix2[0][0];
	printf("\nMatrix 1:\n");
	printMatrix(&m1);
	printf("\nMatrix 2:\n");
	printMatrix(&m2);
	m1.mptr = &matrix1[0][0];	/* Reset pointers */
	m2.mptr = &matrix2[0][0];

	/* Multiply the matrices */
	int matrix3[row1][col2];
	int *ptr3 = &matrix3[0][0];
	matrix m3 = {ptr3, row1, col2};
	int i, j, k;
	int sum = 0;
	printf("\nMultiplication Result:\n");
	for (i = 0; i < row1; i++) {
        	for (j = 0; j < col2; j++) {
			printf("Element [%d,%d] = ", i+1, j+1);
        		for (k = 0; k < row2; k++) {
				if (k == 0) {
					printf("%d*%d ", matrix1[i][k], matrix2[k][j]);
				} 
				else {
					printf("+ %d*%d ", matrix1[i][k], matrix2[k][j]);
				} /* End conditional */
				sum = sum + matrix1[i][k]*matrix2[k][j];
			} /* End for loop */
			printf("= %d\n", sum);
			matrix3[i][j] = sum;
			sum = 0;
		} /* End for loop */
	} /* End for loop */
	printf("\nFinal Output:\n");
	printMatrix(&m3);
	return 0;
} /* End main */

