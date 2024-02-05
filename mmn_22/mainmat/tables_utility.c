/**
 * @file function_matrices.c
 * @brief source file containing arrays of function and matrix names for a matrix processing program.
 *
 * This source file defines arrays containing function names and matrix names used in a matrix processing program.
 * The function names array includes names for functions like reading matrices, printing matrices, arithmetic operations,
 * and program termination. The matrices array includes names for different matrices (e.g., MAT_A, MAT_B).
 */

/* List of the function names */
const char *funcNames[] =
        {"read_mat",
         "print_mat",
         "add_mat",
         "sub_mat",
         "mul_mat",
         "mul_scalar",
         "trans_mat",
         "stop"
        };

/* List of the matrix names */
const char *matrices[] =
        {"MAT_A",
         "MAT_B",
         "MAT_C",
         "MAT_D",
         "MAT_E",
         "MAT_F"
        };