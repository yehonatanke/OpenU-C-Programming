/**
 * @file globals.h
 * @brief Header file containing global constants, enums, and declarations.
 *
 * This header file defines global constants such as maximum matrix name length,
 * the number of supported functions, and the number of matrices.
 * It also includes enumerations for boolean values, command types, and matrices.
 *
 * @remark
 * This header file centralizes global constants and enumerations used throughout the program,
 * promoting consistency and ease of maintenance.
 *
 * @note
 * - The boolean enumeration provides TRUE and FALSE values.
 * - The CommandType enumeration lists supported command types.
 * - The Matrix enumeration lists predefined matrices.
 *
 * @see
 * - MAX_MAT_NAME
 * - FUNC_COUNT
 * - NUM_OF_MATRICES
 * - bool enumeration
 * - CommandType enumeration
 * - Matrix enumeration
 */

#ifndef GLOBALS_H
#define GLOBALS_H

#define MAX_MAT_NAME 5 /**< Maximum length of matrix names. */

#define FUNC_COUNT 8 /**< Number of supported functions. */

#define NUM_OF_MATRICES 6 /**< Number of predefined matrices. */



/**
 * @enum bool
 * @brief Enumeration for boolean values.
 *
 * The boolean enumeration defines boolean values TRUE and FALSE, representing
 * TRUE and FALSE, respectively.
 *
 * @var bool::FALSE
 * Represents the boolean value FALSE (0).

 * @var bool::TRUE
 * Represents the boolean value TRUE (1).

 * @example
 * \code
 * bool isConditionMet = FALSE;
 * \endcode
 * // The `isConditionMet` variable is assigned the value `FALSE` to represent a FALSE condition.
 * bool isValid = TRUE;
 * // The `isValid` variable is assigned the value `TRUE` to represent a TRUE condition.
 * \endcode
 */
typedef enum {
    FALSE = 0, /**< Represents the boolean value FALSE (0). */
    TRUE = 1   /**< Represents the boolean value TRUE (1). */
} bool;

/**
 * @enum CommandType
 * @brief Enumeration for supported command types.
 *
 * The CommandType enumeration lists the supported command types for matrix processing functions.
 *
 * @var CommandType::READ_MAT
 * Represents the command type for reading a matrix.

 * @var CommandType::PRINT_MAT
 * Represents the command type for printing a matrix.

 * @var CommandType::ADD_MAT
 * Represents the command type for adding matrices.

 * @var CommandType::SUB_MAT
 * Represents the command type for subtracting matrices.

 * @var CommandType::MUL_MAT
 * Represents the command type for multiplying matrices.

 * @var CommandType::MUL_SCALAR
 * Represents the command type for scalar multiplication.

 * @var CommandType::TRANS_MAT
 * Represents the command type for transposing a matrix.

 * @var CommandType::STOP
 * Represents the command type for stopping the program.

 * @var CommandType::NONE_FUNC
 * Represents the absence of a specific function register.
 *
 * @example
 * \code
 * CommandType command = READ_MAT;
 * \endcode
 * // The `command` variable is assigned the value `READ_MAT` to represent a read matrix command.
 * \endcode
 */
typedef enum {
    READ_MAT,
    PRINT_MAT,
    ADD_MAT,
    SUB_MAT,
    MUL_MAT,
    MUL_SCALAR,
    TRANS_MAT,
    STOP,
    NONE_FUNC = -1 /**< Represents the absence of a specific register */
} CommandType;

/**
 * @enum Matrix
 * @brief Enumeration for predefined matrices.
 *
 * The Matrix enumeration lists the predefined matrices used in the program.
 *
 * @var Matrix::MATRIX_A
 * Represents the matrix with the name "MAT_A".

 * @var Matrix::MATRIX_B
 * Represents the matrix with the name "MAT_B".

 * @var Matrix::MATRIX_C
 * Represents the matrix with the name "MAT_C".

 * @var Matrix::MATRIX_D
 * Represents the matrix with the name "MAT_D".

 * @var Matrix::MATRIX_E
 * Represents the matrix with the name "MAT_E".

 * @var Matrix::MATRIX_F
 * Represents the matrix with the name "MAT_F".

 * @var Matrix::NONE_MATRIX
 * Represents the absence of a specific matrix register.
 *
 * @example
 * \code
 * Matrix currentMatrix = MATRIX_A;
 * \endcode
 * // The `currentMatrix` variable is assigned the value `MATRIX_A` to represent the "MAT_A" matrix.
 * \endcode
 */
typedef enum {
    MATRIX_A,
    MATRIX_B,
    MATRIX_C,
    MATRIX_D,
    MATRIX_E,
    MATRIX_F,
    NONE_MATRIX = -1
} Matrix;

/* List of function names */
extern const char *funcNames[]; /**< List of function names. */

extern const char *matrices[]; /**< List of matrix names. */

#endif /**< GLOBALS_H */