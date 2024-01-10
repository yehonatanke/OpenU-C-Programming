/**
 * @headerfile constants.h
 * @brief Header file containing constants for managing names.
 *
 * This header file defines constants used in managing a list of names, including the maximum number of names (NUM_OF_NAMES)
 * and the maximum length of each name (MAX_NAME_LENGTH).
 *
 * @remark
 * This file provides essential constants for setting the limits on the number and length of names in the program.
 * It is intended to be included in conjunction with other files that manage names, such as "get_name_util.h" and "get_name_util.c."
 *
 * @remark Key Constants
 * - [Macro] NUM_OF_NAMES - The maximum number of names in the list.
 * - [Macro] MAX_NAME_LENGTH - The maximum length of each name in the list.
 *
 * @author Yehonatan Keypur
 * @date 01/2024
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NUM_OF_NAMES 30    /**< The maximum nameList */
#define MAX_NAME_LENGTH 20 /**< The name length */

#endif /**< CONSTANTS_H */
