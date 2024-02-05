#include "utility.h"
#include "constants.h"
#include "message_utility.h"


/* Reads values into a matrix */
void read_mat(mat *matrix, const double *val, size_t size) {

    int i = 0;
    int row, col;

    /* If there are more than 16 values, the function will ignore the excess values */
    size = size > 16 ? 16 : size;

    /* Insert values */
    FOR_RANGE(row, size) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            if (i < size) {
                matrix->data[row][col] = val[i];
                i++;
            }
            else if (i < 16) {
                matrix->data[row][col] = 0;
                i++;
            }
            else {
                break;
            }
        }
    }
}

/* Prints a matrix */
void print_mat(mat *matrix) {

    int row, col;
    bool useScientific = FALSE; /**< Flag to determine if scientific notation is needed */

    /* Check if scientific notation is needed */
    FOR_RANGE(row, NUM_OF_ROWS) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            if (fabs(matrix->data[row][col]) > 1000.0) {
                useScientific = TRUE;
                break;
            }
        }
        if (useScientific) {
            break;
        }
    }

    FOR_RANGE(row, NUM_OF_ROWS) {
        printf("\n");
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            if (useScientific) {
                printf("%10.2e\t", matrix->data[row][col]);
            }
            else {
                printf("%7.2f\t", matrix->data[row][col]);
            }
        }
    }
    printf("\n"); /* New line at the end of the matrix */
}

/* Add two matrices */
void add_mat(mat *matrixA, mat *matrixB, mat *matrixC) {

    int row, col;

    FOR_RANGE(row, NUM_OF_ROWS) {

        FOR_RANGE(col, NUM_OF_COLUMNS) {
            matrixC->data[row][col] = matrixA->data[row][col] + matrixB->data[row][col];
        }
    }
}

/* Subtracts one matrix from another */
void sub_mat(mat *matrixA, mat *matrixB, mat *matrixC) {

    int row, col;

    FOR_RANGE(row, NUM_OF_ROWS) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            matrixC->data[row][col] = matrixA->data[row][col] - matrixB->data[row][col];
        }
    }
}

/* Multiplies two matrices */
void mul_mat(mat *matrixA, mat *matrixB, mat *matrixC) {

    mat temp_mat = {0};
    int row, col, k;

    FOR_RANGE(row, NUM_OF_ROWS) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {

            /* Initialize matrixC[row][col] to 0 before accumulating the result */
            temp_mat.data[row][col] = 0;

            /* Calculates the dot product of the row from matrixA and the column from matrixB */
            FOR_RANGE(k, 4) {

                temp_mat.data[row][col] += matrixA->data[row][k] * matrixB->data[k][col];
            }
        }
    }
    copy_mat(&temp_mat, matrixC);
}

/* Multiplies a matrix by a scalar */
void mul_scalar(mat *matrixA, double scalar, mat *matrixB) {

    int row, col;

    FOR_RANGE(row, NUM_OF_ROWS) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            matrixB->data[row][col] = matrixA->data[row][col] * scalar;
        }
    }
}

/* Transposes a matrix */
void trans_mat(mat *matrixA, mat *matrixB) {

    int row, col;
    mat temp_mat = {0};

    FOR_RANGE(row, NUM_OF_ROWS) {
        FOR_RANGE(col, NUM_OF_COLUMNS) {
            temp_mat.data[row][col] = matrixA->data[col][row];
        }
    }
    copy_mat(&temp_mat, matrixB);
}

/* Stops the program */
void stop() {

    printf(EXIT_MESSAGE);
    exit(0);
}

