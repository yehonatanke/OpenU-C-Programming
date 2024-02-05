/**
 * @headerfile my_header.h
 * @brief Header File for Matrix Operations
 *
 * This header file provides essential declarations and functionalities for matrix operations.
 * It includes enums, structures, and functions crafted for precise interpretation and systematic handling
 * of various aspects intrinsic to matrix manipulation.
 *
 * @remark
 * This header file supports matrix addition, subtraction, multiplication, transpose,
 * scalar multiplication, and matrix input/output operations.
 * It is a fundamental component for applications requiring matrix manipulation capabilities.
 *
 * @note
 * This template includes enums, structures, and functions crafted for precise
 * interpretation and systematic handling of various aspects intrinsic to matrix manipulation.
 * It supports the development of a versatile and efficient set of declarations.
 *
 * @remark Key Features
 * - Matrix addition, subtraction, and multiplication operations.
 * - Matrix transpose and scalar multiplication functionalities.
 * - Input and output operations for matrices.
 *
 * @overview
 * - [Macro]  OPENING_MESSAGE - Displayed as a user-friendly opening message.
 * - [Struct] mat - Represents a matrix and contains necessary information.
 * - [Enum] CommandType - Defines types of matrix operations (ADD_MAT, SUB_MAT, MUL_MAT, etc.).
 * - [Function] void add_mat(mat *result, const mat *first, const mat *second) - Performs matrix addition.
 * - [Function] void sub_mat(mat *result, const mat *first, const mat *second) - Performs matrix subtraction.
 * - [Function] void mul_mat(mat *result, const mat *first, const mat *second) - Performs matrix multiplication.
 * - [Function] void trans_mat(mat *result, const mat *original) - Performs matrix transpose.
 * - [Function] void mul_scalar(mat *result, double scalar, const mat *original) - Performs scalar multiplication.
 * - [Function] void read_mat(mat *matrix, double values[], size_t numValues) - Reads matrix values from an array.
 * - [Function] void print_mat(const mat *matrix) - Prints the contents of a matrix.
 *
 * @author Yehonatan Keypur
 */

#ifndef PROCESS_INPUT_H
#define PROCESS_INPUT_H

#include "utility.h"

/**
 * @brief Get user input and handle end-of-file (EOF) condition.
 *
 * This function retrieves user input from the standard input (stdin) and handles
 * the end-of-file (EOF) condition by calling the appropriate function.
 *
 * @param[in,out] userInput - Array to store user input.
 * @note The userInput array should be pre-allocated with sufficient space.
 *
 * @return void
 *
 * @var OPENING_MESSAGE - User-friendly message displayed at the beginning.
 *
 * @overview
 * This function is responsible for obtaining user input and ensuring proper handling
 * in case of an end-of-file condition. It uses fgets to read input from stdin and
 * calls the handle_eof function if the end of the file is reached prematurely.
 * The input is then printed using the print_input function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Display the user-friendly opening message.
 * 2. Use fgets to read user input from stdin into the userInput array.
 * 3. If fgets returns NULL (end-of-file condition), call the handle_eof function.
 * 4. Print the user input using the print_input function.
 *
 * @note
 * - The userInput array should be pre-allocated with sufficient space to store the input.
 *
 * @see
 * - handle_eof()
 * - print_input()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[INPUT_MAX_LENGTH];
 *   get_input(userInput);
 * \endcode
 */
void get_input(char userInput[]);

/**
 * @brief Processes a line of user input.
 *
 * This function processes a line of user input by allocating memory, reading the line, and printing the input.
 *
 * @param[in,out] userInput - The character array to store the user input.
 *                            This parameter is dynamically allocated within the function.
 *
 * @return Boolean value indicating the success of processing the line.
 * - Returns TRUE if the line is successfully processed.
 * - Returns FALSE if there is an error or if the end of the file (EOF) is encountered during input.
 *
 * @overview
 * This function allocates initial memory for the user input using the `validated_memory_allocation` function.
 * It then calls the `get_line` function to read a line from standard input into the allocated memory.
 * If the line is successfully read, the function prints the input using the `print_input` function.
 * The function returns TRUE if the line is successfully processed, and FALSE if there is an error or if EOF is reached during input.
 *
 * @note
 * - Memory for the user input is dynamically allocated and resized as needed.
 * - If an EOF is encountered during input, the function returns FALSE, indicating an error or premature end of input.
 * - The `validated_memory_allocation` function is assumed to perform error handling and ensure successful memory allocation.
 *
 * @see
 * - get_line
 * - print_input
 * - validated_memory_allocation
 *
 * @example
 * \code
 *   // Usage Example:
 *   char *inputLine = NULL;
 *   if (line_process(inputLine)) {
 *       // Successfully processed the line, perform further actions.
 *   } else {
 *       // Error occurred or EOF encountered during input.
 *   }
 * \endcode
 */
bool line_process(char **userInput);

/**
 * @brief Reads a line from standard input.
 *
 * This function reads a line from the standard input and stores it in the provided character array `line`.
 *
 * @param[out] line - The character array to store the read line.
 *
 * @return Boolean value indicating the success of reading the line.
 * - Returns TRUE if the line is successfully read.
 * - Returns FALSE if there is an error or if the end of the file (EOF) is encountered.
 *
 * @overview
 * This function reads characters from the standard input until a newline character ('\n') is encountered or until the end of the file (EOF).
 * It dynamically allocates memory for the input line, doubling the capacity if the initial allocation is not sufficient.
 * The function returns TRUE if the line is successfully read, and FALSE if there is an error or if EOF is reached.
 *
 * @note
 * - If an EOF is encountered, the function performs error handling using the `error_handling` function and exits with status 0.
 * - Memory for the input line is dynamically allocated and resized as needed.
 * - If memory reallocation fails, the function calls `handle_memory_allocation_failure`.
 *
 * @see
 * - error_handling
 * - handle_memory_allocation_failure
 *
 * @example
 * \code
 *   // Usage Example:
 *   char *inputLine = NULL;
 *   if (get_line(inputLine)) {
 *       // Successfully read the line, process it accordingly.
 *   } else {
 *       // Error occurred or EOF encountered.
 *   }
 * \endcode
 */
bool get_line(char *line);

/**
 * @brief Analyzes and processes user input for matrix operations.
 *
 * This function analyzes the provided user input, classifies the command type, and performs the corresponding matrix operation.
 *
 * @param[in] userInput - The user input string to be analyzed and processed.
 *
 * @return void
 *
 * @overview
 * This function classifies the command type using the `first_Word_analysis` function.
 * It then checks for command validation, handles specific commands such as 'stop', and identifies the first matrix argument.
 * The function then moves the pointer to the beginning of the next word, checks for illegal comma usage, and handles specific matrix operations.
 * Error handling is performed for undefined commands, missing arguments, and undefined matrices.
 *
 * @note
 * - The function utilizes various macros (e.g., `MOVE_TO_NON_WHITE`, `MOVE_TO_NEXT_WORD`, `ILLEGAL_COMMA`, `MISSING_ARGUMENT`) for pointer movement and error checking.
 * - Matrix operations are handled by specific functions (e.g., `handle_print_mat`, `handle_trans_mat`, `handle_mul_scalar`, `handle_add_sub_mul`, `handle_read_mat`).
 *
 * @see
 * - first_Word_analysis
 * - whichMatrix
 * - handle_stop
 * - handle_print_mat
 * - handle_trans_mat
 * - handle_mul_scalar
 * - handle_add_sub_mul
 * - handle_read_mat
 *
 * @example
 * \code
 *   // Usage Example:
 *   char input[] = "print_mat MATRIX_A";
 *   analyze_input(input);
 *   // Executes the 'print_mat' command with the matrix 'MATRIX_A'.
 * \endcode
 */
void analyze_input(char *userInput);

/**
 * @brief Handle 'stop' command in user input.
 *
 * This function processes the 'stop' command in the user input, validates for extraneous
 * text, and ultimately stops the program.
 *
 * @param[in,out] userInput - User input containing the 'stop' command.
 * @note The userInput pointer should point to the 'stop' command in the input.
 *
 * @return void
 *
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the 'stop' command.
 *
 * @overview
 * This function is responsible for handling the 'stop' command in the user input.
 * It moves the userInput pointer to the next position (after the 'stop' command),
 * checks for extraneous text using the EXTRANEOUS_TEXT macro, and finally stops
 * the program by calling the stop function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Move the userInput pointer to the next position (after the 'stop' command).
 * 2. Check for extraneous text using the EXTRANEOUS_TEXT macro.
 * 3. Stop the program by calling the stop function.
 *
 * @note
 * - The userInput pointer should point to the 'stop' command in the input.
 *
 * @see
 * - EXTRANEOUS_TEXT
 * - stop()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   // Assume 'userInput' contains the 'stop' command.
 *   handle_stop(userInput);
 * \endcode
 */
void handle_stop(char *userInput);

/**
 * @brief Handle 'print_mat' command in user input.
 *
 * This function processes the 'print_mat' command in the user input,
 * validates for extraneous text, and prints the specified matrix.
 *
 * @param[in] userInput - User input containing the 'print_mat' command.
 * @param[in] firstMatrix - Pointer to the matrix to be printed.
 *
 * @return void
 *
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the 'print_mat' command.
 *
 * @overview
 * This function is responsible for handling the 'print_mat' command in the user input.
 * It checks for extraneous text using the EXTRANEOUS_TEXT macro and prints the specified matrix
 * by calling the print_mat function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Check for extraneous text using the EXTRANEOUS_TEXT macro.
 * 2. Print the specified matrix using the print_mat function.
 *
 * @note
 * - The userInput should contain the 'print_mat' command.
 * - The firstMatrix parameter is a pointer to the matrix to be printed.
 *
 * @see
 * - EXTRANEOUS_TEXT
 * - print_mat()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   mat *firstMatrix; // Assume firstMatrix is initialized.
 *   // Assume 'userInput' contains the 'print_mat' command.
 *   handle_print_mat(userInput, firstMatrix);
 * \endcode
 */
void handle_print_mat(const char *userInput, mat *firstMatrix);

/**
 * @brief Handle 'trans_mat' command in user input.
 *
 * This function processes the 'trans_mat' command in the user input,
 * validates for errors, and performs the transpose operation on matrices.
 *
 * @param[in,out] userInput - User input containing the 'trans_mat' command and arguments.
 * @param[in,out] firstMatrix - Pointer to the first matrix (input and output).
 * @note The userInput pointer should point to the 'trans_mat' command in the input.
 *
 * @return void
 *
 * @var MISSING_COMMA - Macro to check for a missing comma in the user input.
 * @var MOVE_TO_NON_WHITE - Macro to move the pointer to the next non-white character.
 * @var MULTIPLE_CONSECUTIVE_COMMAS - Macro to check for multiple consecutive commas in the user input.
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the end of the command.
 *
 * @overview
 * This function is responsible for handling the 'trans_mat' command in the user input.
 * It performs error checking, extracts the second matrix argument, and performs the matrix transpose
 * operation by calling the trans_mat function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 2. Move the pointer to the next non-white character using the MOVE_TO_NON_WHITE macro.
 * 3. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 4. Extract the second matrix argument using the whichMatrix function.
 * 5. Check if the second matrix argument is valid; if not, call error_handling and return.
 * 6. Move the pointer after the second matrix and perform error checking.
 * 7. Perform the matrix transpose using the trans_mat function.
 *
 * @note
 * - The userInput pointer should point to the 'trans_mat' command in the input.
 * - The firstMatrix parameter is both an input and output, representing the matrix to be transposed.
 *
 * @see
 * - MISSING_COMMA
 * - MOVE_TO_NON_WHITE
 * - MULTIPLE_CONSECUTIVE_COMMAS
 * - EXTRANEOUS_TEXT
 * - whichMatrix()
 * - trans_mat()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   mat *firstMatrix; // Assume firstMatrix is initialized.
 *   // Assume 'userInput' contains the 'trans_mat' command and arguments.
 *   handle_trans_mat(userInput, firstMatrix);
 * \endcode
 */
void handle_trans_mat(char *userInput, mat *firstMatrix);

/**
 * @brief Handle 'mul_scalar' command in user input.
 *
 * This function processes the 'mul_scalar' command in the user input,
 * validates for errors, and performs matrix multiplication by a scalar.
 *
 * @param[in,out] userInput - User input containing the 'mul_scalar' command and arguments.
 * @param[in] firstMat - Pointer to the first matrix.
 * @note The userInput pointer should point to the 'mul_scalar' command in the input.
 *
 * @return void
 *
 * @var MISSING_COMMA - Macro to check for a missing comma in the user input.
 * @var MOVE_TO_NON_WHITE - Macro to move the pointer to the next non-white character.
 * @var MULTIPLE_CONSECUTIVE_COMMAS - Macro to check for multiple consecutive commas in the user input.
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the end of the command.
 *
 * @overview
 * This function is responsible for handling the 'mul_scalar' command in the user input.
 * It performs error checking, extracts the scalar and the second matrix argument,
 * and performs matrix multiplication by a scalar using the mul_scalar function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Move the pointer to the next non-white character using the MOVE_TO_NON_WHITE macro.
 * 2. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 3. Increment the pointer to point after the comma and move to the next non-white character.
 * 4. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 5. Extract the scalar from the user input using strtod.
 * 6. Check if the scalar is missing using error_handling; if missing, return.
 * 7. Move the pointer after the scalar, perform error checking, and move to the next non-white character.
 * 8. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 9. Increment the pointer to point after the comma and move to the next non-white character.
 * 10. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 11. Extract the second matrix argument using the whichMatrix function.
 * 12. Check if the second matrix argument is valid; if not, call error_handling and return.
 * 13. Move the pointer after the second matrix and perform error checking.
 * 14. Perform matrix multiplication by a scalar using the mul_scalar function.
 *
 * @note
 * - The userInput pointer should point to the 'mul_scalar' command in the input.
 * - The firstMat parameter is the first matrix, and the scalar and second matrix are extracted from the input.
 *
 * @see
 * - MISSING_COMMA
 * - MOVE_TO_NON_WHITE
 * - MULTIPLE_CONSECUTIVE_COMMAS
 * - EXTRANEOUS_TEXT
 * - strtod()
 * - error_handling()
 * - whichMatrix()
 * - mul_scalar()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   mat *firstMat; // Assume firstMat is initialized.
 *   // Assume 'userInput' contains the 'mul_scalar' command and arguments.
 *   handle_mul_scalar(userInput, firstMat);
 * \endcode
 */
void handle_mul_scalar(char *userInput, mat *firstMat);

/**
 * @brief Handle matrix addition, subtraction, or multiplication command in user input.
 *
 * This function processes matrix addition, subtraction, or multiplication command in the user input,
 * validates for errors, and performs the corresponding matrix operation.
 *
 * @param[in,out] userInput - User input containing the matrix operation command and arguments.
 * @param[in,out] firstMat - Pointer to the first matrix (input and output).
 * @param[in] cmdType - CommandType indicating the type of matrix operation (ADD_MAT, SUB_MAT, or MUL_MAT).
 * @note The userInput pointer should point to the matrix operation command in the input.
 *
 * @return void
 *
 * @var MISSING_COMMA - Macro to check for a missing comma in the user input.
 * @var MOVE_TO_NON_WHITE - Macro to move the pointer to the next non-white character.
 * @var MULTIPLE_CONSECUTIVE_COMMAS - Macro to check for multiple consecutive commas in the user input.
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the end of the command.
 *
 * @overview
 * This function is responsible for handling matrix addition, subtraction, or multiplication commands
 * in the user input. It performs error checking, extracts the second and third matrix arguments,
 * and performs the corresponding matrix operation by calling the add_mat, sub_mat, or mul_mat function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 2. Move the pointer to the next non-white character using the MOVE_TO_NON_WHITE macro.
 * 3. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 4. Extract the second matrix argument using the whichMatrix function.
 * 5. Check if the second matrix argument is valid; if not, call error_handling and return.
 * 6. Move the pointer after the second matrix and perform error checking.
 * 7. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 8. Increment the pointer to point after the comma and move to the next non-white character.
 * 9. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 10. Extract the third matrix argument using the whichMatrix function.
 * 11. Check if the third matrix argument is valid; if not, call error_handling and return.
 * 12. Move the pointer after the third matrix and perform error checking.
 * 13. Perform the corresponding matrix operation (addition, subtraction, or multiplication)
 *     based on the cmdType using the add_mat, sub_mat, or mul_mat function.
 *
 * @note
 * - The userInput pointer should point to the matrix operation command in the input.
 * - The firstMat parameter is both an input and output, representing the result of the matrix operation.
 * - The cmdType parameter indicates the type of matrix operation (ADD_MAT, SUB_MAT, or MUL_MAT).
 *
 * @see
 * - MISSING_COMMA
 * - MOVE_TO_NON_WHITE
 * - MULTIPLE_CONSECUTIVE_COMMAS
 * - EXTRANEOUS_TEXT
 * - whichMatrix()
 * - add_mat()
 * - sub_mat()
 * - mul_mat()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   mat *firstMat; // Assume firstMat is initialized.
 *   // Assume 'userInput' contains the matrix operation command and arguments.
 *   CommandType cmdType = ADD_MAT; // Change to SUB_MAT or MUL_MAT as needed.
 *   handle_add_sub_mul(userInput, firstMat, cmdType);
 * \endcode
 */
void handle_add_sub_mul(char *userInput, mat *firstMat, CommandType cmdType);

/**
 * @brief Handle 'read_mat' command in user input.
 *
 * This function processes the 'read_mat' command in the user input,
 * validates for errors, and reads matrix values from the input.
 *
 * @param[in,out] userInput - User input containing the 'read_mat' command and matrix values.
 * @param[in,out] firstMat - Pointer to the matrix (output) where values will be stored.
 * @note The userInput pointer should point to the 'read_mat' command in the input.
 *
 * @return void
 *
 * @var MISSING_ARGUMENT - Macro to check for a missing argument in the user input.
 * @var MISSING_COMMA - Macro to check for a missing comma in the user input.
 * @var MOVE_TO_NON_WHITE - Macro to move the pointer to the next non-white character.
 * @var MULTIPLE_CONSECUTIVE_COMMAS - Macro to check for multiple consecutive commas in the user input.
 * @var EXTRANEOUS_TEXT - Macro to check for extraneous text after the end of the command.
 * @var IS_NOT_END_OF_COMMAND - Macro to check if the pointer is not pointing at the end of the command.
 * @var IS_END_OF_COMMAND - Macro to check if the pointer is pointing at the end of the command.
 *
 * @overview
 * This function is responsible for handling the 'read_mat' command in the user input.
 * It performs error checking, extracts matrix values, and reads the values into the specified matrix
 * using the read_mat function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Check for a missing argument in the user input using the MISSING_ARGUMENT macro.
 * 2. Check for a missing comma in the user input using the MISSING_COMMA macro.
 * 3. Increment the pointer to point after the comma and move to the next non-white character.
 * 4. Check for multiple consecutive commas using the MULTIPLE_CONSECUTIVE_COMMAS macro.
 * 5. Extract matrix values using strtod in a loop, with a maximum of 16 values.
 * 6. Check if conversion was successful using error_handling; if not, return.
 * 7. Move the pointer after each value and to the next non-white character.
 * 8. Check for the end of the command using the IS_END_OF_COMMAND macro; if not, continue the loop.
 * 9. Perform additional error checking for extraneous text, missing commas, or unnecessary commas.
 * 10. If the input is valid, call the read_mat function to store values in the specified matrix.
 *
 * @note
 * - The userInput pointer should point to the 'read_mat' command in the input.
 * - The firstMat parameter is the matrix where values will be stored.
 *
 * @see
 * - MISSING_ARGUMENT
 * - MISSING_COMMA
 * - MOVE_TO_NON_WHITE
 * - MULTIPLE_CONSECUTIVE_COMMAS
 * - EXTRANEOUS_TEXT
 * - IS_NOT_END_OF_COMMAND
 * - IS_END_OF_COMMAND
 * - strtod()
 * - error_handling()
 * - read_mat()
 *
 * @example
 * \code
 *   // Usage Example:
 *   char userInput[MAX_INPUT_LENGTH];
 *   mat *firstMat; // Assume firstMat is initialized.
 *   // Assume 'userInput' contains the 'read_mat' command and matrix values.
 *   handle_read_mat(userInput, firstMat);
 * \endcode
 */
void handle_read_mat(char *userInput, mat *firstMat);


#endif /**< PROCESS_INPUT_H */
