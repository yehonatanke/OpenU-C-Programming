/**
 * @file hash_utility.h
 * @brief Header file containing utility functions for hashing and indexing words.
 *
 * This header file defines utility functions for computing hash values of strings,
 * adding words to an index along with line numbers, and checking the existence
 * of words in an array.
 */

#ifndef HASH_UTILITY_H
#define HASH_UTILITY_H

#include "globals.h"


/**
 * @brief Computes a hash value for a given string.
 *
 * This function computes a hash value for a given string using a simple
 * hash algorithm. The computed hash value is used to determine the index
 * in a hash table for storing the string or its associated data.
 *
 * @param str The input string for which the hash value is computed.
 *            This parameter must be a null-terminated C string.
 * @return The computed hash value as an unsigned integer.
 *
 * @note The hash value is computed using a basic hash algorithm that
 *       iterates over each character of the input string and combines
 *       them to produce a hash value. The algorithm is designed for
 *       simplicity and speed, but may not be suitable for all applications
 *       requiring strong collision resistance or cryptographic security.
 *       It uses the following formula:
 *       hash = ((hash << 5) + hash) + c, where 'hash' is the current
 *       hash value and 'c' is the ASCII value of the current character.
 *       The final hash value is then taken modulo the size of the hash table.
 *
 * @note The choice of the hash table size (HASH_SIZE) impacts the
 *       distribution of hash values across the table. It's recommended
 *       to choose a prime number for HASH_SIZE to minimize collisions.
 *
 * @warning This function assumes that the input string is a null-terminated
 *          C string. It does not perform any bounds checking, so it's the
 *          caller's responsibility to ensure that the string is properly
 *          null-terminated to avoid undefined behavior.
 */
unsigned int hash(const char *str);

/**
 * @brief Adds a word to the index along with its line number.
 *
 * This function adds a word to the index along with its line number. If the word already exists in the index,
 * the line number is appended to the existing word entry. If the word does not exist in the index, a new word entry
 * is created, and the line number is added to it.
 *
 * @param[in,out] index - Pointer to the array of word entries representing the index.
 * @param[in] word - The word to add to the index.
 * @param[in] line_number - The line number where the word appears.
 *
 * @complexity
 * Time Complexity: O(1) on average for adding a word to an existing entry, O(n) in the worst case for traversing the linked list.
 * - The function computes the hash value of the word, which has constant time complexity.
 * - It then checks if the word already exists in the index by traversing the linked list of word entries.
 * - If the word exists, the function adds the line number to the existing word entry in constant time.
 * - If the word does not exist, a new word entry is created, and the line number is added to it in constant time.
 * - In the worst case, if there are collisions resulting in a long linked list, the time complexity for adding a word is O(n), where n is the number of words in the index.
 */
void addWordToIndex(WordEntry *index, const char *word, int line_number);

/**
 * @brief Checks if a word exists in an array of words.
 *
 * This function checks if a word exists in an array of words.
 *
 * @param[in] array - Pointer to the array of words.
 * @param[in] size - The size of the array.
 * @param[in] word - The word to search for in the array.
 *
 * @return Boolean value indicating whether the word is present in the array.
 * - Returns TRUE if the word is found in the array.
 * - Returns FALSE if the word is not found in the array.
 *
 * @complexity
 * Time Complexity: O(n), where n is the size of the array.
 * - The function iterates over each element of the array and performs string comparison,
 *   resulting in linear time complexity proportional to the size of the array.
 */
bool isWordInArray(char **array, int size, const char *word);


#endif /**< HASH_UTILITY_H */
