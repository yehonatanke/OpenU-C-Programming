/**
 * @file get_name_util.c
 * @brief Source file containing utility functions for managing a list of names.
 *
 * This source file implements utility functions for generating, checking duplicates, printing, and manipulating a list of names.
 * It includes functions for generating a random name, checking for name duplication, printing the list, removing newline characters,
 * and initializing the random seed.
 *
 * @remark
 * This file complements the header file "get_name_util.h" and provides the actual implementation of the declared functions.
 * It includes necessary header files, defines the name list, and implements functions for name management.
 *
 * @remark Key Features
 * - Generation of random names from a predefined list.
 * - Checking for name duplication within the list.
 * - Printing all names in the list.
 * - Removing newline characters from names.
 * - Initialization of the random seed for generating random names.
 *
 * @author Yehonatan Keypur
 * @date 01/2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "get_name_util.h"
#include "constants.h"


/* The name list */
char nameList[NUM_OF_NAMES][MAX_NAME_LENGTH + 1];

/* Generates a random name from the list */
char *get_name(void) {

    int randomIndex = rand() % NUM_OF_NAMES;

    return nameList[randomIndex];
}

/* Checks name duplication */
bool is_duplicate(const char *newName, int index) {

    /* A condition for the first name of the list */
    if (index == 0)
        return FALSE;

    do {
        if (strcasecmp(nameList[index - 1], newName) == 0) { /**< Argument is (index-1) to avoid comparing a name to itself */

            /* If this condition is true, then the name already exists in the list */
            return TRUE;
        }
        index--;
    } while (0 < index);

    /* There isn't such a name in the list, therefore, return FALSE */
    return FALSE;
}

/* Print all the names in the list */
void print_list(void) {

    int i; /**< Loop variable */

    printf("\nThe input names received by the program are:");

    FOR_RANGE(i, NUM_OF_NAMES) {

        printf("\nInput name #%d: %s", i + 1, nameList[i]);
    }
}

/* Remove the newline character, if presents */
void remove_newline_char(int index) {

    size_t length; /**< The name's length */

    /* Set 'length' to the name's length */
    length = strlen(nameList[index]);

    /* Check if the last character is a newline character */
    if (length > 0 && nameList[index][length - 1] == '\n') {

        /* Set the null-terminator instead of the newline character */
        nameList[index][length - 1] = '\0';
    }
}

/* Initializes the random seed */
void initialize_random_seed(void) { srand((unsigned int) time(NULL)); }
