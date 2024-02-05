/**
 * @file mainmat.h
 * @brief Header file containing functions for initializing matrices and processing program functionality.
 *
 * This header file defines functions for initializing matrices to zero and processing the main functionality
 * of a matrix processing program, including handling user input in a loop until termination.
 *
 * @remark
 * This header file encapsulates the main functionality of a matrix processing program,
 * providing essential declarations for initializing matrices and handling user input.
 * It promotes modularity and maintainability within the system, supporting the development of versatile and efficient matrix operations.
 *
 * @note
 * - The functions in this header file contribute to the overall matrix processing program.
 *
 * @remark Key Features
 * - Initializing predefined matrices to zero.
 * - Processing the main functionality of the program with user input.
 *
 * @overview
 * - [Function]  matrices_initialization: Initializes predefined matrices to zero.
 * - [Function]  program_process: Processes the main functionality of the program, handling user input in a loop.
 *
 * @author Yehonatan Keypur
 */


#ifndef MAINMAT_H
#define MAINMAT_H

/**
 * @brief Initialize all matrices to zero in all cells.
 *
 * This function initializes all predefined matrices (MAT_A to MAT_F) to zero in all cells.
 *
 * @return void
 *
 * @var MAT_A to MAT_F - Predefined matrices.
 * @var zero - Array containing a single zero element.
 *
 * @overview
 * This function initializes all predefined matrices to zero in all cells by calling the read_mat function.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Create an array 'zero' containing a single zero element.
 * 2. Determine the size of the 'zero' array.
 * 3. Initialize each predefined matrix to zero by calling the read_mat function with the 'zero' array.
 *
 * @note
 * - The matrices are initialized using the read_mat function.
 *
 * @example
 * \code
 *   // Usage Example:
 *   matrices_initialization();
 * \endcode
 */
void matrices_initialization();

/**
 * @brief Process the main functionality of the program.
 *
 * This function initializes matrices, processes user input in a loop until a stop command
 * or the end of the file is encountered, and prompts the user for more input.
 *
 * @return void
 *
 * @var OPENING_MESSAGE - User-friendly opening message.
 * @var TRUE - Macro representing a boolean TRUE value.
 *
 * @overview
 * This function serves as the entry point for the main functionality of the program.
 * It initializes matrices, processes user input using the line_process and analyze_input functions
 * in a loop until a stop command or the end of the file is encountered, and prompts the user for more input.
 *
 * @algorithm
 * The function follows these steps:
 * 1. Print the opening message.
 * 2. Process the input in a loop until a stop command or the end of the file is encountered.
 * 3. Prompt the user for more input after each iteration.
 *
 * @see
 * - OPENING_MESSAGE
 * - TRUE
 * - matrices_initialization
 * - line_process
 * - analyze_input
 *
 * @example
 * \code
 *   // Usage Example:
 *   main();
 * \endcode
 */
 void program_process();

#endif /**< MAINMAT_H */