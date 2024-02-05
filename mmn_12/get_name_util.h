/**
 * @headerfile get_name_util.h
 * @brief Header file for utility functions managing a list of names.
 *
 * This header file defines utility functions for generating, checking duplicates, printing, and manipulating a list of names.
 * It also includes a macro for convenient iteration over a specified range.
 *
 * @note
 * This file should be included along with "constants.h" to create a cohesive system for managing names in a program.
 *
 * @remark Key Features
 * - [Macro] FOR_RANGE - Convenient iteration macro over a specified range.
 * - [External Declaration] nameList - Two-dimensional array for storing names.
 * - [Enumeration] bool - Boolean values enumeration (TRUE, FALSE).
 * - [char *] get_name() - Generates a random name from the list.
 * - [bool] is_duplicate() - Checks if a new name is a duplicate within a specified range in the name list.
 * - [void] print_list() - Prints all the names in the list.
 * - [void] remove_newline_char() - Removes the newline character from a name if present.
 * - [void] initialize_random_seed() - Initializes the random seed for generating random names.
 *
 * @author yehonatanke
 */

#ifndef GET_NAME_UTIL_H
#define GET_NAME_UTIL_H

#include "constants.h"


/**
 * @brief Macro for iterating over a range with a specified upper bound.
 *
 * This macro provides a convenient way to create a loop for iterating over a range of indices
 * with a specified upper bound. It is designed to simplify the syntax of for loops for index-based
 * iterations.
 *
 * @param[in,out] index - The loop variable representing the current index.
 * @param[in] upperBound - The upper bound for the iteration range.
 */
#define FOR_RANGE(index, upperBound) \
    for(index = 0; index < upperBound; index++)

/**
 * @brief External declaration for the name list.
 *
 * The name list is represented as a two-dimensional character array, where each row contains a
 * name, and the maximum length of each name is defined by MAX_NAME_LENGTH.
 */
extern char nameList[NUM_OF_NAMES][MAX_NAME_LENGTH + 1];

/**
 * @enum bool
 * @brief Enumeration for boolean values.
 *
 * The boolean enumeration defines boolean values TRUE and FALSE, representing
 * true and false, respectively.
 *
 * @var bool::FALSE
 * Represents the boolean value FALSE (0).

 * @var bool::TRUE
 * Represents the boolean value TRUE (1).

 * @example
 * \code
 * bool isConditionMet = FALSE;
 * \endcode
 * // The `isConditionMet` variable is assigned the value `FALSE` to represent a false condition.
 * bool isValid = TRUE;
 * // The `isValid` variable is assigned the value `TRUE` to represent a true condition.
 * \endcode
 */
typedef enum {
    FALSE = 0, /**< Represents the boolean value FALSE (0). */
    TRUE = 1   /**< Represents the boolean value TRUE (1). */
}
bool;

/**
 * @brief Generates a random name from the list.
 *
 * This function generates a random name by selecting one from a predefined list of names.
 *
 * @return A pointer to the generated random name.
 */
char *get_name(void);

/**
 * @brief Checks if a new name is a duplicate within a specified range in the name list.
 *
 * This function compares a new name with preceding names in the list to determine if it is a duplicate.
 * It checks for duplicates within the range from the current index to the beginning of the list.
 *
 * @param[in] newName - The new name to be checked for duplication.
 * @param[in] index - The current index of the name in the list.
 * @return TRUE if the new name is a duplicate within the specified range, FALSE otherwise.
 */

bool is_duplicate(const char *newName, int index);

/**
 * @brief Prints all the names in the list.
 *
 * This function prints all the names in the predefined list to the standard output.
 */
void print_list(void);

/**
 * @brief Removes the newline character from a name, if present.
 *
 * This function removes the newline character from the end of a name, if it is present.
 *
 * @param[in] index - The index of the name in the list to process.
 */
void remove_newline_char(int index);

/**
 * @brief Initializes the random seed for generating random names.
 *
 * This function initializes the random seed based on the current time, ensuring different random names on each run.
 */
void initialize_random_seed(void);


#endif /**< GET_NAME_UTIL_H */
