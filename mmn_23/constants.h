/**
 * @file constants.h
 * @brief Header file containing constants used throughout the program.
 *
 * This header file defines various constants used in the program,
 * such as maximum line length, hash table size, valid argument count,
 * and whitespace characters.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * @brief Maximum length of a line in the input file.
 *
 * This constant defines the maximum length of a line that can be read from
 * the input file. Lines longer than this length will be truncated.
 */
#define MAX_LINE_LENGTH 1024

/**
 * @brief Size of the hash table.
 *
 * This constant defines the size of the hash table used for indexing words.
 * It determines the number of buckets in the hash table, impacting the
 * distribution of hash values across the table.
 */
#define HASH_SIZE 100

/**
 * @brief Expected count of command-line arguments.
 *
 * This constant defines the expected count of command-line arguments
 * when running the program. It is used for input validation.
 */
#define VALID_ARG_COUNT 2

/**
 * @brief String containing whitespace characters.
 *
 * This constant defines a string containing whitespace characters, including
 * space (' '), tab ('\t'), and newline ('\n'). It is used for tokenizing input.
 */
#define SPACES " \t\n"

/**
 * @brief Macro for representing the newline character.
 *
 * The NEW_LINE macro represents the newline character ('\n'). It can be used
 * to improve code readability and maintainability by abstracting away the specific
 * character used for representing a new line in the code.
 *
 * @note Usage Example:
 * \code
 * printf("This is a line of text.%s", NEW_LINE);
 * // The NEW_LINE macro is used to add a newline character to the end of the string.
 * \endcode
 */
#define NEW_LINE "\n"


#endif /**< CONSTANTS_H */
