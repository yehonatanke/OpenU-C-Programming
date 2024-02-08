/**
 * @file index.h
 * @brief Header file containing functions for processing files and building an index.
 *
 * This header file declares a function for processing a file, building an index,
 * and printing the sorted index.
 */

#ifndef INDEX_H
#define INDEX_H

#include "globals.h"

#include <stdio.h>

/**
 * @brief Processes the program by reading a file, building an index, and printing the sorted index.
 *
 * This function processes the program by reading a file line by line, tokenizing each line into words,
 * adding each word to the index with its corresponding line number, and adding unique words to an array for sorting.
 * After reading the entire file, the function sorts the array of words lexicographically and prints the occurrences
 * of each word in the index.
 *
 * @param[in] file - Pointer to the file to be processed.
 * @param[in,out] index - Pointer to the array of word entries representing the index.
 *
 * @complexity
 * Time Complexity: O(n * m * log m), where n is the number of lines in the file, and m is the average number of words per line.
 * - The function reads each line of the file and tokenizes it into words, resulting in linear time complexity proportional to the number of lines (n) and the average number of words per line (m).
 * - For each word, the function adds it to the index and checks if it's already present in the array for sorting, resulting in logarithmic time complexity for sorting the array of words (m * log m).
 * - Overall, the time complexity is dominated by sorting the array of words, resulting in O(n * m * log m) time complexity.
 */
void program_process(FILE *file, WordEntry *index);


#endif /**< INDEX_H */
