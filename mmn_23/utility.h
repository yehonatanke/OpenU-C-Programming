/**
 * @file utility.h
 * @brief Header file containing utility functions for processing data and memory management.
 *
 * This header file provides utility functions for processing data, including string comparison,
 * printing word occurrences, and sorting strings. It also includes functions for memory management,
 * such as memory allocation with error checking and freeing allocated memory.
 */

#ifndef UTILITY_H
#define UTILITY_H

#include "globals.h"

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
 * @brief Compares a word with a word entry in an index using a hash value.
 *
 * This function compares a word with the word entry at a specified index in an index array,
 * based on the provided hash value.
 *
 * @param[in] index - The array of word entries.
 * @param[in] word - The word to compare.
 * @param[in] hash_value - The hash value used to access the word entry in the index.
 *
 * @return Boolean value indicating whether the word matches the word entry.
 * - Returns TRUE if the word matches the word entry.
 * - Returns FALSE if the word does not match the word entry.
 *
 * @complexity
 * Time Complexity: O(1)
 * - The function performs a single comparison operation using strcmp, which has constant time complexity.
 */
bool word_compare(const WordEntry *index, const char *word, unsigned int hash_value);

/**
 * @brief Prints the occurrences of a word in the index.
 *
 * This function prints the line numbers where a word appears in the index.
 *
 * @param[in] index - The array of word entries.
 * @param[in] word - The word to print occurrences for.
 *
 * @complexity
 * Time Complexity: O(k), where k is the number of occurrences of the word.
 * - The function traverses the linked list of line numbers for the word and prints each line number,
 *   resulting in linear time complexity proportional to the number of occurrences of the word.
 */
void print_word_entry(WordEntry *index, const char *word) ;

/**
 * @brief Compares two strings for use in qsort.
 *
 * This function compares two strings for use in the qsort function.
 *
 * @param[in] a - Pointer to the first string.
 * @param[in] b - Pointer to the second string.
 *
 * @return Integer value indicating the comparison result.
 * - Returns a negative value if the first string is less than the second.
 * - Returns zero if the strings are equal.
 * - Returns a positive value if the first string is greater than the second.
 *
 * @complexity
 * Time Complexity: O(n * log n), where n is the length of the strings.
 * - The function performs string comparison using strcmp, which has linear time complexity.
 * - However, the function is typically used as a comparison function for qsort, which has an average time complexity
 *   of O(n * log n) for sorting n elements.
 */
int compare_strings(const void *a, const void *b);

/**
 * @brief Frees memory allocated for a hash index.
 *
 * This function frees memory allocated for a hash index, including word entries and linked list nodes.
 *
 * @param[in] index - The array of word entries representing the hash index.
 *
 * @complexity
 * Time Complexity: O(n + m), where n is the number of word entries and m is the total number of linked list nodes.
 * - The function iterates over each word entry in the index, freeing the associated word and linked list nodes,
 *   resulting in linear time complexity proportional to the number of word entries and the total number of linked list nodes.
 */
void free_hash(const WordEntry *index);

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

#endif /**< UTILITY_H */
