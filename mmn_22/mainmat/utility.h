/**
 * @file utility.h
 * @brief Header file containing utility macros and functions for a matrix processing program.
 *
 * This file defines macros and functions providing utility features used in a matrix processing program,
 * such as moving pointers, analyzing commands, and handling memory allocation.
 *
 * @remark
 * This header file serves as a collection of utility features essential for efficient matrix processing.
 * It includes macros for pointer manipulation, command analysis, and functions for handling memory allocation.
 *
 * @note
 * The utility macros and functions in this file are designed to enhance the functionality of matrix processing,
 * offering tools for efficient command parsing, matrix operations, and dynamic memory management.
 *
 * @remark Key Features
 * - Macros for moving pointers to non-white characters and the next word in a string.
 * - Macros for checking the end of a command, non-end of a command, and index not at the end of a line.
 * - Macros for obtaining matrix pointers and handling memory allocation errors.
 * - Functions for analyzing the first word of a command, retrieving matrix pointers, and getting scalar values.
 * - Functions for copying matrices, handling memory allocation failures, and printing input details.
 *
 * @overview
 * - [Macro] GET_MATRIX(index) - Retrieves a matrix pointer based on the provided index.
 * - [Macro] IS_END_OF_COMMAND(ptr) - Checks if the pointer has reached the end of a command.
 * - [Macro] IS_NOT_END_OF_COMMAND(ptr) - Checks if the pointer has not reached the end of a command.
 * - [Macro] INDEX_NOT_AT_END_OF_LINE(ptr, index) - Checks if the indexed position is not at the end of a line.
 * - [Macro] MOVE_TO_NON_WHITE(string) - Moves the pointer to the next non-white character in a string.
 * - [Macro] FOR_RANGE(index, upperBound) - Macro for iterating over a range of indices.
 * - [Macro] MOVE_TO_NEXT_WORD(ptr) - Moves the pointer to the next word in a string.
 * - [Macro] MOVE_AFTER_MAT(ptr) - Moves the pointer to the position after a matrix name in a command.
 * - [Function] first_Word_analysis(char *strPtr) - Analyzes the first word of a command and returns the corresponding command type.
 * - [Function] whichMatrix(char *ptr) - Returns a pointer to the matrix with the given name.
 * - [Function] validated_memory_allocation(size_t size) - Allocates memory with error checking.
 * - [Function] handle_memory_allocation_failure(void) - Prints the error message for memory allocation failures and exits.
 * - [Function] handle_eof(void) - Handles end-of-file conditions during input processing.
 * - [Function] print_input(const char *userInput) - Prints the details of the user input.
 *
 * @author Yehonatan Keypur
 */

#ifndef UTILITY_H
#define UTILITY_H


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "globals.h"
#include "mymat.h"


/**
 * @brief Retrieves a matrix from an array of matrices based on the given index.
 *
 * This macro takes an index and returns the corresponding matrix from the array
 * of matrices. It assumes that the array of matrices is named 'matrices'.
 *
 * @param index The index of the matrix to retrieve.
 * @return The matrix at the specified index.
 */
#define GET_MATRIX(index) (matrices[index])

/**
 * @brief Checks if the character pointer points to the end of a command (null terminator or newline character).
 *
 * This macro evaluates whether the character pointed to by 'ptr' indicates the end of a command
 * by checking for a null terminator or a newline character.
 *
 * @param ptr The character pointer to check.
 * @return Returns true if the pointer is at the end of a command, otherwise false.
 */
#define IS_END_OF_COMMAND(ptr) \
    ((*ptr == '\0') || (*ptr == '\n'))

/**
 * @brief Checks if the character pointer does not point to the end of a command (not null terminator and not newline character).
 *
 * This macro evaluates whether the character pointed to by 'ptr' does not indicate the end of a command
 * by checking for a non-null terminator and a non-newline character.
 *
 * @param ptr The character pointer to check.
 * @return Returns true if the pointer is not at the end of a command, otherwise false.
 */
#define IS_NOT_END_OF_COMMAND(ptr) \
    ((*ptr != '\0') && (*ptr != '\n'))

/**
 * @brief Checks if the character at the specified index in the string is not at the end of a line (not null terminator and not newline character).
 *
 * This macro evaluates whether the character at the specified index in the string does not indicate the end of a line
 * by checking for a non-null terminator and a non-newline character.
 *
 * @param ptr The character array or pointer to the string.
 * @param index The index to check within the string.
 * @return Returns true if the character at the specified index is not at the end of a line, otherwise false.
 */
#define INDEX_NOT_AT_END_OF_LINE(ptr, index) \
    ((ptr[index] != '\0') && (ptr[index] != '\n'))

/**
 * @brief Macro to move the pointer to the next non-white character in a string.
 *
 * The MOVE_TO_NON_WHITE macro is designed to be used in a for-loop structure to advance
 * the pointer to the next position in the string where the character isn't a white space.
 * The macro iterates through the string until a non-white character is encountered.
 *
 * @param string The string to traverse.
 *
 * @note Example:
 * \code
 * char assemblyLine[MAX_LINE_LENGTH];
 * int index = 0;
 * MOVE_TO_NON_WHITE(assemblyLine);
 * // The assemblyLine is now positioned at the next non-white character in the string.
 * \endcode
 */
#define MOVE_TO_NON_WHITE(string) \
    for (; *string && isspace(*string); string++) \
        ; /**< Increment the string pointer to move to the next non-white-space character */

/**
 * @brief Macro for a simple for-loop iterating over a range of values.
 *
 * This macro facilitates the creation of a basic for-loop that iterates over a specified range of values.
 * It initializes the given index to 0 and continues the loop as long as the index is less than the specified upper bound.
 * It increments the index after each iteration.
 *
 * @param index The loop variable representing the current iteration.
 * @param upperBound The upper limit (exclusive) for the loop iterations.
 */
#define FOR_RANGE(index, upperBound) \
    for(index = 0; index < upperBound; index++)

/**
 * @brief Macro to move a pointer to the next word in a string.
 *
 * This macro advances the given pointer to the next word in the string. It skips
 * any leading whitespace characters and positions the pointer at the start of the
 * next word. The macro modifies the original pointer in-place.
 *
 * @param ptr - Pointer to the current position in the string.
 *
 * @example
 * \code
 * const char *inputString = "   Hello World!   ";
 * const char *ptr = inputString;
 * MOVE_TO_NEXT_WORD(ptr);
 * // Now ptr points to the start of the next word ("Hello").
 * \endcode
 */
#define MOVE_TO_NEXT_WORD(ptr) \
    do { \
        while (*ptr && isspace(*ptr)) { \
            ++ptr; \
        } \
        while (*ptr && !isspace(*ptr)) { \
            ++ptr; \
        } \
    } while (0);

/**
 * @brief Macro to move the character pointer to the position after a matrix name.
 *
 * This macro advances the character pointer 'ptr' by a fixed distance, where 'MAX_MAT_NAME'
 * represents the maximum length of a matrix name. It is designed to be used after parsing
 * or processing a matrix name, allowing the pointer to move to the position after the name.
 *
 * @param ptr The character pointer to be moved.
 */
#define MOVE_AFTER_MAT(ptr) \
    ((ptr) += MAX_MAT_NAME);

/**
 * @brief Analyze the first word of a string to determine the command type.
 *
 * This function analyzes the first word of a string to determine the command type.
 * It compares the first word with each of the command names and returns the corresponding
 * command type. If no match is found, NONE_FUNC is returned.
 *
 * @param[in] strPtr - Pointer to the input string.
 *
 * @return CommandType - CommandType enum representing the analyzed command type.
 *
 * @var INDEX_NOT_AT_END_OF_LINE - Macro to check if the index is not at the end of the line.
 * @var FUNC_COUNT - The total number of command functions.
 * @var funcNames - Array containing the names of command functions.
 * @var CommandType - Enum type representing command types.
 * @var NONE_FUNC - Enum value representing no matching command type.
 *
 * @overview
 * This function iterates through the characters of the first word in the input string,
 * counts the number of characters, and compares it with each command name. If a match is
 * found, the corresponding command type is returned; otherwise, NONE_FUNC is returned.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Iterate through the characters of the first word, counting the number of characters.
 * 2. Compare the first word with each command name using strncmp and strlen.
 * 3. If a match is found, return the corresponding command type.
 * 4. If no match is found, return NONE_FUNC.
 *
 * @note
 * - The strPtr parameter is a pointer to the input string.
 * - The command types and corresponding command names are defined in the CommandType enum type
 *   and funcNames array, respectively.
 *
 * @see
 * - INDEX_NOT_AT_END_OF_LINE
 * - FUNC_COUNT
 * - funcNames
 * - CommandType
 * - NONE_FUNC
 *
 * @example
 * \code
 *   // Usage Example:
 *   char *inputString = "commandArgument1 argument2";
 *   CommandType result = first_Word_analysis(inputString);
 *   if (result != NONE_FUNC) {
 *       // Valid command type found.
 *   } else {
 *       // No matching command type found.
 *   }
 * \endcode
 */
CommandType first_Word_analysis(char *strPtr);

/**
 * @brief Get a pointer to the matrix based on the provided string.
 *
 * This function determines the matrix identifier using the getMatrix function,
 * and returns a pointer to the corresponding matrix. If no matching matrix is found,
 * NULL is returned.
 *
 * @param[in] ptr - Pointer to the string representing the matrix.
 *
 * @return mat* - Pointer to the matrix if a match is found, NULL otherwise.
 *
 * @var Matrix - Enum type representing matrix identifiers.
 * @var getMatrix - Function to retrieve the matrix identifier based on the provided string.
 * @var MATRIX_A - Enum value representing Matrix A.
 * @var MATRIX_B - Enum value representing Matrix B.
 * @var MATRIX_C - Enum value representing Matrix C.
 * @var MATRIX_D - Enum value representing Matrix D.
 * @var MATRIX_E - Enum value representing Matrix E.
 * @var MATRIX_F - Enum value representing Matrix F.
 * @var NONE_MATRIX - Enum value representing no matching matrix.
 * @var MAT_A - Pointer to Matrix A.
 * @var MAT_B - Pointer to Matrix B.
 * @var MAT_C - Pointer to Matrix C.
 * @var MAT_D - Pointer to Matrix D.
 * @var MAT_E - Pointer to Matrix E.
 * @var MAT_F - Pointer to Matrix F.
 *
 * @overview
 * This function uses the getMatrix function to determine the matrix identifier
 * based on the provided string. It then returns a pointer to the corresponding matrix
 * or NULL if no matching matrix is found.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Use the getMatrix function to obtain the matrix identifier.
 * 2. Use a switch statement to return a pointer to the corresponding matrix based on the identifier.
 * 3. If no matching matrix is found, return NULL.
 *
 * @note
 * - The ptr parameter is a pointer to the string representing the matrix.
 * - The matrix identifiers and corresponding matrix pointers are defined in the Matrix enum type
 *   and mat structures, respectively.
 *
 * @example
 * \code
 *   // Usage Example:
 *   char *matrixString = "Matrix_A";
 *   mat *resultMatrix = whichMatrix(matrixString);
 *   if (resultMatrix != NULL) {
 *       // Valid matrix pointer found.
 *   } else {
 *       // No matching matrix found.
 *   }
 * \endcode
 */
mat *whichMatrix(char *ptr);

/**
 * @brief Retrieve the matrix identifier based on the provided string.
 *
 * This function searches for a matrix identifier in the list of predefined matrices,
 * comparing it with the provided string. If a match is found, the corresponding matrix
 * identifier is returned; otherwise, NONE_MATRIX is returned.
 *
 * @param[in] ptr - Pointer to the string representing the matrix.
 *
 * @return Matrix - Matrix identifier if a match is found, NONE_MATRIX otherwise.
 *
 * @var FOR_RANGE - Macro for iterating over a range.
 * @var NUM_OF_MATRICES - The total number of predefined matrices.
 * @var GET_MATRIX - Macro to get the string representation of a matrix by index.
 * @var MAX_MAT_NAME - Maximum length of the matrix name.
 * @var Matrix - Enum type representing matrix identifiers.
 * @var NONE_MATRIX - Enum value representing no matching matrix.
 *
 * @overview
 * This function iterates through the range of predefined matrices and compares the
 * provided string with the string representations of each matrix. If a match is found,
 * the corresponding matrix identifier is returned; otherwise, NONE_MATRIX is returned.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Iterate through the range of predefined matrices using the FOR_RANGE macro.
 * 2. Compare the provided string with the string representation of each matrix
 *    using the strncmp function.
 * 3. If a match is found, return the corresponding matrix identifier.
 * 4. If no match is found, return NONE_MATRIX.
 *
 * @note
 * - The ptr parameter is a pointer to the string representing the matrix.
 * - The matrix identifiers are defined in the Matrix enum type.
 *
 * @see
 * - FOR_RANGE
 * - NUM_OF_MATRICES
 * - GET_MATRIX
 * - MAX_MAT_NAME
 * - Matrix
 * - NONE_MATRIX
 *
 * @example
 * \code
 *   // Usage Example:
 *   char *matrixString = "Matrix_A";
 *   Matrix result = getMatrix(matrixString);
 *   if (result != NONE_MATRIX) {
 *       // Valid matrix identifier found.
 *   } else {
 *       // No matching matrix found.
 *   }
 * \endcode
 */
Matrix getMatrix(char *ptr);

/**
 * @brief Parse a string for a scalar value and return the result.
 *
 * This function parses a string to extract a scalar value, considering signs, digits,
 * and decimal places. It returns the result through the returnVal pointer and
 * returns TRUE if successful, FALSE otherwise.
 *
 * @param[in] strPtr - Pointer to the input string containing the scalar value.
 * @param[out] returnVal - Pointer to store the extracted scalar value.
 *
 * @return bool - TRUE if parsing is successful, FALSE otherwise.
 *
 * @var TRUE - Macro representing a boolean TRUE value.
 * @var FALSE - Macro representing a boolean FALSE value.
 *
 * @overview
 * This function parses the input string for a scalar value, taking into account signs,
 * digits, and decimal places. It skips leading whitespace and checks for valid numeric
 * characters, returning the result through the returnVal pointer. It returns TRUE if
 * the parsing is successful and FALSE otherwise.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Skip leading whitespace in the input string.
 * 2. Check if the first character is a digit or a sign, and handle signs appropriately.
 * 3. Detect leading zeros, which indicate an invalid octal number or an invalid input.
 * 4. Parse the string for digits and decimal places, updating the result accordingly.
 * 5. Adjust the result for fractional numbers.
 * 6. Store the final result in the returnVal pointer.
 * 7. Return TRUE if parsing is successful, FALSE otherwise.
 *
 * @note
 * - The strPtr parameter is a pointer to the input string containing the scalar value.
 * - The returnVal parameter is a pointer to store the extracted scalar value.
 *
 * @see
 * - TRUE
 * - FALSE
 *
 * @example
 * \code
 *   // Usage Example:
 *   const char *inputString = "123.45";
 *   double result;
 *   if (getScalar(inputString, &result)) {
 *       // Parsing successful, use the result.
 *   } else {
 *       // Parsing failed, handle the error.
 *   }
 * \endcode
 */
bool getScalar(const char *strPtr, double *returnVal);

/**
 * @brief Copy the contents of one matrix to another.
 *
 * This function copies the contents of the source matrix to the destination matrix.
 *
 * @param[in] srcMatrix - Pointer to the source matrix.
 * @param[out] destMatrix - Pointer to the destination matrix.
 *
 * @return void
 *
 * @overview
 * This function iterates through each element of the source matrix and copies it to
 * the corresponding element in the destination matrix. It provides a simple and direct
 * way to duplicate the contents of one matrix into another.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Use nested loops to iterate through each element of the source matrix.
 * 2. Copy the value of each element to the corresponding position in the destination matrix.
 *
 * @note
 * - The srcMatrix parameter is a pointer to the source matrix.
 * - The destMatrix parameter is a pointer to the destination matrix.
 *
 * @example
 * \code
 *   // Usage Example:
 *   mat sourceMatrix, destinationMatrix;
 *   // Assume sourceMatrix is initialized.
 *   copy_mat(&sourceMatrix, &destinationMatrix);
 * \endcode
 */

void copy_mat(mat *srcMatrix, mat *destMatrix);

/**
 * @brief Prints the error message for memory allocation failures and exits.
 *
 * This function prints the error message "Memory allocation failed" and exits the program with a failure code.
 *
 * @note Usage Example:
 * \code
 * int *ptr = (int *)malloc(sizeof(int) * 10);
 * if (ptr == NULL) {
 *     handle_memory_allocation_failure();
 * }
 * \endcode
 */
void handle_memory_allocation_failure(void);

/**
 * @brief Allocates memory with error checking.
 *
 * This function dynamically allocates memory using malloc and checks if the allocation was successful.
 * In case of failure, it invokes the handle_memory_allocation_failure function to print an error message
 * and exit the program with a failure code.
 *
 * @param size The size of the memory block to allocate.
 * @return A pointer to the allocated memory block.
 *
 * @note Memory Management:
 * The caller is responsible for freeing the memory allocated by this function
 * using the free function.
 *
 * @note Usage Example:
 * \code
 * int *array = (int *)validated_memory_allocation(sizeof(int) * 10);
 * // Use array as needed
 * free(array); // Remember to free the allocated memory
 * \endcode
 */
void *validated_memory_allocation(size_t size);

/**
 * @brief Handles end-of-file conditions during input processing.
 *
 * This function is an essential part of the matrix processing program, invoked when encountering
 * an end-of-file (EOF) condition during the processing of user input. It prints an error message
 * indicating the premature end of the file and the absence of a stop command to terminate file
 * processing properly. After printing the error message, the function exits the program with a
 * failure code.
 *
 * @remark
 * This function plays a crucial role in ensuring proper file processing and error handling,
 * preventing unexpected termination due to premature EOF conditions.
 *
 * @see
 * - error_handling(const char *error) - Used to print the corresponding error message.
 */
void handle_eof(void);

/**
 * @brief Prints the details of the user input.
 *
 * This function serves as a utility to display information about the user's command or input string.
 * It takes a pointer to the user input string and prints the details to the standard output.
 * The printed message includes the label "The input is:" followed by the provided input string.
 *
 * @param userInput Pointer to the user input string.
 *
 * @note
 * - The function uses the printf function to print the input details in a formatted manner.
 * - Example usage:
 *   \code
 *   const char *command = "transpose(matrix)";
 *   print_input(command);
 *   // Output: The input is: transpose(matrix)
 *   \endcode
 *
 * @see
 * - printf() - Used to print the input details.
 */
void print_input(const char *userInput);


#endif /**< UTILITY_H */