/**
 * @file globals.h
 * @brief Header file containing global definitions and structures.
 *
 * This header file defines global structures and enumerations used
 * throughout the program, including structures for linked list nodes
 * and word entries in the index, as well as an enumeration for boolean
 * values.
 */

#ifndef GLOBALS_H
#define GLOBALS_H

/**
 * @brief Structure to represent a node in a linked list.
 *
 * This structure represents a node in a linked list used for storing
 * line numbers associated with a word in the index.
 */
typedef struct ListNode {
    int line_number;       /**< The line number associated with the word. */
    struct ListNode *next; /**< Pointer to the next node in the linked list. */
} ListNode;

/**
 * @brief Structure to represent a word entry in the index.
 *
 * This structure represents an entry in the index, containing a word
 * and a linked list of line numbers where the word appears.
 */
typedef struct {
    char *word;      /**< Pointer to the word stored in the index entry. */
    ListNode *lines; /**< Pointer to the linked list of line numbers. */
} WordEntry;

/**
 * @enum bool
 * @brief Enumeration for boolean values.
 *
 * The boolean enumeration defines boolean values TRUE and FALSE, representing
 * TRUE and FALSE, respectively.
 *
 * @var bool::FALSE
 * Represents the boolean value FALSE (0).

 * @var bool::TRUE
 * Represents the boolean value TRUE (1).

 * @example
 * \code
 * bool isConditionMet = FALSE;
 * \endcode
 * // The `isConditionMet` variable is assigned the value `FALSE` to represent a FALSE condition.
 * bool isValid = TRUE;
 * // The `isValid` variable is assigned the value `TRUE` to represent a TRUE condition.
 * \endcode
 */
typedef enum {
    FALSE = 0, /**< Represents the boolean value FALSE (0). */
    TRUE = 1   /**< Represents the boolean value TRUE (1). */
} bool;


#endif /**< GLOBALS_H */
