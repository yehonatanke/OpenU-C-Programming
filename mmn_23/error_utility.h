/**
 * @file error_utility.h
 * @brief Header file containing error handling utilities.
 *
 * This header file defines macros and functions for handling errors
 * and printing error messages to the error log stream.
 */

#ifndef ERROR_UTILITY_H
#define ERROR_UTILITY_H

/**
 * @brief Error log stream for printing error messages.
 */
#define ERROR_LOG_STREAM stderr

/**
 * @brief Error message for failing to open a file.
 */
#define OPEN_FILE_ERR "Could not open file."

/**
 * @brief Error message for incorrect argument usage.
 */
#define INCORRECT_ARG_ERR "Invalid usage. File name not specified."

/**
 * @brief Error message for memory allocation failure.
 */
#define MEMORY_ALLOCATION_ERR "Memory allocation failed"

/**
 * @brief Handles errors by printing a formatted error message to the error log stream.
 *
 * This function takes an error message as input and prints it in a formatted way
 * to the error log stream (specified by ERROR_LOG_STREAM). The error message should
 * provide information about the encountered error.
 *
 * @param error A pointer to a string containing the error message.
 *
 * @note
 * - The format of the error message should be specified to aid in debugging.
 */
void error_handling(const char *error, const char *file_name);


#endif /**< ERROR_UTILITY_H */
