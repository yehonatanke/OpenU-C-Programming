/**
 * @file mymat.h
 * @brief Header file containing structures and functions for matrix operations.
 *
 * This header file defines a 4x4 matrix structure and various functions for matrix operations,
 * including reading values into a matrix, printing the contents of a matrix, matrix addition,
 * matrix subtraction, matrix multiplication, scalar multiplication, matrix transposition, and program termination.
 *
 * @remark
 * This file encapsulates matrix operations, providing a structured representation of a 4x4 matrix
 * and functions to perform common operations such as reading, printing, addition, subtraction, multiplication,
 * scalar multiplication, transposition, and program termination.
 *
 * @note
 * - The matrix structure uses a 2D array ('data') to store its elements.
 * - The provided functions ensure proper handling of matrices and enhance the functionality of a matrix processing program.
 *
 * @see
 * - mat structure
 * - read_mat
 * - print_mat
 * - add_mat
 * - sub_mat
 * - mul_mat
 * - mul_scalar
 * - trans_mat
 * - stop
 *
 * @author Yehonatan Keypur
 */

#ifndef MYMAT_H
#define MYMAT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * @brief Structure representing a 4x4 matrix.
 *
 * This structure contains a 2D array 'data' to store the elements of a 4x4 matrix.
 *
 * @var data - 2D array to store the elements of the matrix.
 *
 * @overview
 * This structure defines a 4x4 matrix using a 2D array to store its elements.
 *
 * @note
 * - The elements of the matrix are stored in the 'data' array.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat myMatrix;
 *   // Accessing an element of the matrix:
 *   myMatrix.data[0][0] = 1.0;
 * \endcode
 */
typedef struct {
    double data[4][4];
} mat;


/**
 * @brief Reads values into a matrix.
 *
 * This function reads values from the input array `val` and inserts them into the matrix `matrix`.
 * If there are more than 16 values, the function will ignore the excess values.
 *
 * @param[in,out] matrix - The matrix to store the values.
 * @param[in] val - The array of values to read.
 * @param[in] size - The number of values in the array.
 *
 * @return void
 *
 * @overview
 * This function populates the matrix with values from the input array, ensuring a maximum of 16 values are considered.
 * It fills the matrix row by row, column by column, and pads with zeros if the array has fewer than 16 values.
 *
 * @note
 * - If the input array `val` has more than 16 values, the excess values are ignored.
 *
 * @example
 * \code
 *   // Usage Example:
 *   double values[10] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
 *   mat myMatrix;
 *   read_mat(&myMatrix, values, 10);
 * \endcode
 */
void read_mat(mat *matrix, const double *val, size_t size);

/**
 * @brief Print the contents of a matrix.
 *
 * This function prints the contents of a matrix, with an option to use scientific
 * notation if any element's absolute value is greater than 1000.0.
 *
 * @param[in] matrix - Pointer to the matrix to be printed.
 *
 * @return void
 *
 * @var NUM_OF_ROWS - The total number of rows in the matrix.
 * @var NUM_OF_COLUMNS - The total number of columns in the matrix.
 * @var FOR_RANGE - Macro for iterating over a range.
 * @var fabs - Function to get the absolute value of a floating-point number.
 *
 * @overview
 * This function iterates through each element of the matrix, checks if any element's
 * absolute value is greater than 1000.0, and sets a flag (useScientific) accordingly.
 * It then prints the matrix using the appropriate format (%10.2e for scientific notation
 * or %7.2f for regular notation).
 *
 * @algorithm
 * The function follows these steps:
 * 1. Check if scientific notation is needed by iterating through each element of the matrix.
 * 2. If any element's absolute value is greater than 1000.0, set the useScientific flag.
 * 3. Iterate through each row and column of the matrix and print each element with the
 *    appropriate format (%10.2e or %7.2f) based on the useScientific flag.
 * 4. Print a new line at the end of the matrix.
 *
 * @note
 * - The matrix parameter is a pointer to the matrix to be printed.
 *
 * @see
 * - NUM_OF_ROWS
 * - NUM_OF_COLUMNS
 * - FOR_RANGE
 * - fabs
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat exampleMatrix; // Assume exampleMatrix is initialized.
 *   print_mat(&exampleMatrix);
 * \endcode
 */
void print_mat(mat *matrix);

/**
 * @brief Add two matrices and store the result in a third matrix.
 *
 * This function adds two matrices (matrixA and matrixB) element-wise and stores the
 * result in another matrix (matrixC).
 *
 * @param[in] matrixA - Pointer to the first matrix.
 * @param[in] matrixB - Pointer to the second matrix.
 * @param[out] matrixC - Pointer to the matrix to store the result.
 *
 * @return void
 *
 * @var NUM_OF_ROWS - The total number of rows in the matrices.
 * @var NUM_OF_COLUMNS - The total number of columns in the matrices.
 * @var FOR_RANGE - Macro for iterating over a range.
 *
 * @overview
 * This function iterates through each element of matrixA and matrixB, adds the corresponding
 * elements, and stores the result in the corresponding element of matrixC.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Use nested loops to iterate through each element of matrixA and matrixB.
 * 2. Add the corresponding elements of matrixA and matrixB.
 * 3. Store the result in the corresponding element of matrixC.
 *
 * @note
 * - The matrixA and matrixB parameters are pointers to the matrices to be added.
 * - The matrixC parameter is a pointer to the matrix to store the result.
 *
 * @see
 * - NUM_OF_ROWS
 * - NUM_OF_COLUMNS
 * - FOR_RANGE
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat matrixA, matrixB, matrixC; // Assume matrixA and matrixB are initialized.
 *   add_mat(&matrixA, &matrixB, &matrixC);
 * \endcode
 */
void add_mat(mat *matrixA, mat *matrixB, mat *matrixC);

/**
 * @brief Subtracts one matrix from another.
 *
 * This function subtracts the matrix `matrixB` from `matrixA`, storing the result in the matrix `matrixC`.
 *
 * @param[in] matrixA - The matrix to subtract from.
 * @param[in] matrixB - The matrix to subtract.
 * @param[out] matrixC - The resulting matrix after subtraction.
 *
 * @return void
 *
 * @overview
 * This function performs element-wise subtraction of the values in matrixA and matrixB, storing the result in matrixC.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat matrixA, matrixB, resultMatrix;
 *   // ... (populate matrixA and matrixB)
 *   sub_mat(&matrixA, &matrixB, &resultMatrix);
 * \endcode
 */
void sub_mat(mat *matrixA, mat *matrixB, mat *matrixC);

/**
 * @brief Multiplies two matrices.
 *
 * This function multiplies the matrices `matrixA` and `matrixB`, storing the result in the matrix `matrixC`.
 *
 * @param[in] matrixA - The first matrix.
 * @param[in] matrixB - The second matrix.
 * @param[out] matrixC - The resulting matrix after multiplication.
 *
 * @return void
 *
 * @overview
 * This function performs matrix multiplication of matrixA and matrixB, storing the result in matrixC.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat matrixA, matrixB, resultMatrix;
 *   // ... (populate matrixA and matrixB)
 *   mul_mat(&matrixA, &matrixB, &resultMatrix);
 * \endcode
 */
void mul_mat(mat *matrixA, mat *matrixB, mat *matrixC);

/**
 * @brief Multiplies a matrix by a scalar.
 *
 * This function multiplies each element of the matrix `matrixA` by the scalar value, storing the result in the matrix `matrixB`.
 *
 * @param[in] matrixA - The matrix to be multiplied.
 * @param[in] scalar - The scalar value for multiplication.
 * @param[out] matrixB - The resulting matrix after scalar multiplication.
 *
 * @return void
 *
 * @overview
 * This function performs element-wise multiplication of the values in matrixA by the scalar, storing the result in matrixB.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat matrixA, resultMatrix;
 *   double scalar = 2.0;
 *   // ... (populate matrixA)
 *   mul_scalar(&matrixA, scalar, &resultMatrix);
 * \endcode
 */
void mul_scalar(mat *matrixA, double scalar, mat *matrixB);

/**
 * @brief Transposes a matrix.
 *
 * This function transposes the matrix `matrixA` and stores the result in the matrix `matrixB`.
 *
 * @param[in] matrixA - The matrix to be transposed.
 * @param[out] matrixB - The resulting transposed matrix.
 *
 * @return void
 *
 * @overview
 * This function swaps the rows and columns of matrixA, storing the transposed result in matrixB.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat matrixA, resultMatrix;
 *   // ... (populate matrixA)
 *   trans_mat(&matrixA, &resultMatrix);
 * \endcode
 */
void trans_mat(mat *matrixA, mat *matrixB);

/**
 * @brief Stops the program.
 *
 * This function prints an exit message and terminates the program.
 *
 * @return void
 *
 * @overview
 * This function prints an exit message and terminates the program with a status code of 0.
 *
 * @example
 * \code
 *   // Usage Example:
 *   stop();
 * \endcode
 */
void stop();

#endif