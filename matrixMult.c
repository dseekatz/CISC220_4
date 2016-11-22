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

/* Sets the dimensions for a single matrix */
void getDims(int *row, int *col) {
	scanf("%d %d", row, col);
} /* End getDims */

/* Checks the dimensions for a matrix and checks if they are valid for matrix multiplication.  If they
 * are not valid, the user is notified and prompted to re-enter the matrix dimensions.
 */
void checkDims(int *colFirst, int *rowSecond, int *colSecond) {
	while (*colFirst != *rowSecond) {
		fprintf(stderr,"Dimensions Mismatch\n");
		printf("Please re-enter the dimensions for the second matrix. The number of rows should be %d: ", *colFirst);
		scanf("%d %d",rowSecond,colSecond);
	} /* End while loop */
}

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
	m->mptr=(m->mptr) - i * j;	/* Reset Pointer */
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
	m->mptr=(m->mptr) - i;	/* Reset pointer */
} /* End setMatrix */

/* This function multiplies two matrices and stores the result in a third matrix (provided as a parameter) */
void multiply(matrix *m1, matrix *m2, matrix *m3) {
	int i, j, k;
	int sum = 0;
	
	/* This part seems silly, but I don't know how to avoid it since I can't pass a 2D array of
	 * unspecified size as a parameter.  In this block of code I create two new arrays
	 * that are exact copies of the arrays pointed at by the m1 and m2 matrix structures. I do
	 * this so that the elemnts of those arrays are easy to access when doing the actual multiplication.
	 */
	int matrix1[m1->rows][m1->cols];
	for (i = 0; i < m1->rows; i++) {
		for (j = 0; j < m1->cols; j++) {
			matrix1[i][j] = *(m1->mptr);
			(m1->mptr)++;
		} /* End for loop */
	} /* End for loop */
	m1->mptr=(m1->mptr) - i * j;	/* Reset Pointer */
	int matrix2[m2->rows][m2->cols];
	for (i = 0; i < m2->rows; i++) {
		for (j = 0; j < m2->cols; j++) {
			matrix2[i][j] = *(m2->mptr);
			(m2->mptr)++;
		} /* End for loop */
	} /* End for loop */
	m2->mptr=(m2->mptr) - i * j;	/* Reset Pointer */

	/* Back to regularly scheduled matrix multiplication */
	for (i = 0; i < m1->rows; i++) {
        	for (j = 0; j < m2->cols; j++) {
			printf("Element [%d,%d] = ", i+1, j+1);
        		for (k = 0; k < m2->rows; k++) {
				if (k == 0) {
					printf("%d*%d ", matrix1[i][k], matrix2[k][j]);
				} 
				else {
					printf("+ %d*%d ", matrix1[i][k], matrix2[k][j]);
				} /* End conditional */
				sum = sum + matrix1[i][k]*matrix2[k][j];
			} /* End for loop */
			printf("= %d\n", sum);
			*(m3->mptr) = sum;
			(m3->mptr)++;
			sum = 0;
		} /* End for loop */
	} /* End for loop */
	m3->mptr=(m3->mptr) - i * j;	/* Reset Pointer */
} /* End multiply */

int main() {
	/* Get the dimensions of the matrices */
	int row1, col1, row2, col2;
	printf("Insert matrix 1 dimensions separated by a space: ");
	getDims(&row1, &col1);
	printf("Insert matrix 2 dimensions separated by a space: ");
	getDims(&row2, &col2);
	checkDims(&col1, &row2, &col2);
	
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
	printf("\nMatrix 1:\n");
	printMatrix(&m1);
	printf("\nMatrix 2:\n");
	printMatrix(&m2);

	/* Multiply the matrices */
	int matrix3[row1][col2];
	int *ptr3 = &matrix3[0][0];
	matrix m3 = {ptr3, row1, col2};
	printf("\nMultiplication Result:\n");
	multiply(&m1, &m2, &m3);
	printf("\nOutput:\n");
	printMatrix(&m3);

	/* Prompt the user for a new matrix to be multiplied with the result */
	int row4, col4;
	printf("\nInsert new matrix dimensions separated by a space: ");
	getDims(&row4, &col4);
	checkDims(&col2, &row4, &col4);

	/* Get the new matrix elements */
	int matrix4[row4][col4];
	int *ptr4 = &matrix4[0][0];
	matrix m4 = {ptr4, row4, col4};
	printf("Input new matrix elements separated by spaces (there should be %d elements): ", row4*col4);
	setMatrix(&m4);

	/* Multiply the new matrix with the previous result */
	int matrix5[row1][col4];
	int *ptr5 = &matrix5[0][0];
	matrix m5 = {ptr5, row1, col4};
	printf("\nMultiplication Result:\n");
	multiply(&m3, &m4, &m5);
	printf("\nFinal Output:\n");
	printMatrix(&m5);
	return 0;
} /* End main */
