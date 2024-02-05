/**
 * @file error_utility.h
 * @brief Header file containing error constants and utility macros for a matrix processing program.
 *
 * This file defines constants for error messages and utility macros used in a matrix processing program for error handling.
 *
 * @remark
 * This header file contains error constants and utility macros for handling errors in a matrix processing program.
 * It provides essential tools for error detection and reporting during the execution of matrix commands.
 *
 * @note
 * The macros in this file facilitate the identification of common errors in user input related to matrix operations.
 * The error_handling function is used to print formatted error messages to the specified error log stream.
 *
 * @remark Key Features
 * - Macros for common error messages related to matrix processing.
 * - Utility macros for checking illegal comma usage, extraneous text, missing arguments, missing commas, and more.
 * - error_handling function to print formatted error messages.
 *
 * @overview
 * - [Macro] ERROR_LOG_STREAM - Specifies the error log stream (stderr by default).
 * - [Macro] MEMORY_ALLOCATION_ERR - Error message for memory allocation failure.
 * - [Macro] EOF_ERR - Error message for premature end of file encountered without a stop command.
 * - [Macro] COMMA_ERR - Error message for illegal comma usage.
 * - [Macro] EXT_TXT_ERR - Error message for extraneous text after the end of a command.
 * - [Macro] NO_ARGS_ERR - Error message for missing argument in a command.
 * - [Macro] NO_COMMA_ERR - Error message for missing comma in a command.
 * - [Macro] UNNECESSARY_COMMA_ERR - Error message for unnecessary consecutive commas in a command.
 * - [Macro] UNDEFINED_MAT_ERR - Error message for undefined matrix name in a command.
 * - [Macro] MISSING_ARG_ERR - Error message for missing argument in a command.
 * - [Macro] MISSING_SCALAR_ERR - Error message for missing scalar argument in a command.
 * - [Macro] ARG_IS_NOT_DOUBLE - Error message for an argument that is not a real number in a command.
 * - [Macro] ILLEGAL_COMMA(ch) - Macro to check for an illegal comma at the given character pointer.
 * - [Macro] EXTRANEOUS_TEXT(ch) - Macro to check for extraneous text at the given character pointer.
 * - [Macro] MISSING_ARGUMENT(ch) - Macro to check for a missing argument at the given character pointer.
 * - [Macro] MISSING_COMMA(ch) - Macro to check for a missing comma at the given character pointer.
 * - [Macro] MULTIPLE_CONSECUTIVE_COMMAS(ch) - Macro to check for multiple consecutive commas at the given character pointer.
 * - [Function] error_handling(const char *error) - Handles errors by printing a formatted error message to the error log stream.
 *
 * @author Yehonatan Keypur
 */

#ifndef ERROR_UTILITY_H
#define ERROR_UTILITY_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Error log stream for printing error messages.
 */
#define ERROR_LOG_STREAM stderr

/**
 * @brief Error message for memory allocation failure.
 */
#define MEMORY_ALLOCATION_ERR "Memory allocation failed"

/**
 * @brief Error message for premature end of file encountered without a stop command.
 */
#define EOF_ERR "Premature end of file encountered. Missing stop command to properly terminate the file processing"

/**
 * @brief Error message for illegal comma usage.
 */
#define COMMA_ERR "Illegal comma"

/**
 * @brief Error message for extraneous text after the end of a command.
 */
#define EXT_TXT_ERR "Extraneous text after end of command"

/**
 * @brief Error message for missing argument in a command.
 */
#define NO_ARGS_ERR "Missing argument"

/**
 * @brief Error message for missing comma in a command.
 */
#define NO_COMMA_ERR "Missing comma"

/**
 * @brief Error message for unnecessary consecutive commas in a command.
 */
#define UNNECESSARY_COMMA_ERR "Multiple consecutive commas"

/**
 * @brief Error message for undefined matrix name in a command.
 */
#define UNDEFINED_MAT_ERR "Undefined matrix name"

/**
 * @brief Error message for missing argument in a command.
 */
#define MISSING_ARG_ERR "Missing argument"

/**
 * @brief Error message for missing scalar argument in a command.
 */
#define MISSING_SCALAR_ERR "Argument is not a scalar"

/**
 * @brief Error message for an argument that is not a real number in a command.
 */
#define ARG_IS_NOT_DOUBLE "Argument is not a real number"

/**
 * @brief Checks for an illegal comma at the given character pointer.
 *
 * If the character pointed to by `ch` is a comma, it triggers the error
 * handling function (`COMMA_ERR`) and returns.
 *
 * @param ch The character pointer to check.
 */
 #define ILLEGAL_COMMA(ch) \
    if (*ch == ',') {\
        error_handling(COMMA_ERR); \
        return;\
    }

/**
 * @brief Checks for extraneous text at the given character pointer.
 *
 * If the character pointed to by `ch` is not the end of the string or a newline
 * character, it triggers the error handling function (`EXT_TXT_ERR`) and returns.
 *
 * @param ch The character pointer to check.
 */
#define EXTRANEOUS_TEXT(ch) \
    if (*ch && (*ch != '\n' && *ch != '\0')) {\
        error_handling(EXT_TXT_ERR); \
        return;\
    }

/**
 * @brief Checks for a missing argument at the given character pointer.
 *
 * If the character pointed to by `ch` is null, it triggers the error handling
 * function (`NO_ARGS_ERR`) and returns.
 *
 * @param ch The character pointer to check.
 */
#define MISSING_ARGUMENT(ch) \
    if (!(*ch)) {\
        error_handling(NO_ARGS_ERR); \
        return;\
    }

/**
 * @brief Checks for a missing comma at the given character pointer.
 *
 * If the character pointed to by `ch` is not a comma, it triggers the error
 * handling function (`NO_COMMA_ERR`) and returns.
 *
 * @param ch The character pointer to check.
 */
#define MISSING_COMMA(ch) \
    if (*ch != ',') {\
        error_handling(NO_COMMA_ERR); \
        return;\
    }

/**
 * @brief Checks for multiple consecutive commas at the given character pointer.
 *
 * If the character pointed to by `ch` is a comma, it triggers the error
 * handling function (`UNNECESSARY_COMMA_ERR`) and returns.
 *
 * @param ch The character pointer to check.
 */
#define MULTIPLE_CONSECUTIVE_COMMAS(ch) \
    if (*ch == ',') {\
        error_handling(UNNECESSARY_COMMA_ERR);\
        return;\
    }

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
void error_handling(const char *error);


#endif /**< ERROR_UTILITY_H */