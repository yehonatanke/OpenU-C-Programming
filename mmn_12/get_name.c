/**
 * @file get_name.c
 * @brief Main source file for managing names and demonstrating utility functions.
 *
 * This source file contains the main function that initializes the random seed, reads names from the input,
 * checks for duplicates, prints the input list, and calls the get_name function to generate random names.
 *
 * @remark Key Features
 * - Initialization of the random seed for generating random names.
 * - Input of 30 names, with removal of newline characters and duplicate checking.
 * - Printing of the input list.
 * - Calling the get_name function to generate and print 10 different random names.
 *
 * @author Yehonatan Keypur
 * @date 01/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "get_name_util.h"


int main() {

    int i; /**< Loop variable */

    /* Initialize the random seed once in the program */
    initialize_random_seed();

    printf("Please enter 30 names.\n");

    /* A loop that reads the names from the input and initializes the name list */
    FOR_RANGE (i, NUM_OF_NAMES) {

        scanf("%s", nameList[i]);

        remove_newline_char(i);

        /* Check for name duplication */
        if (is_duplicate(nameList[i], i)) { /**< True if there has been a duplication */

            fprintf(stderr, "\nError: Program terminated due to duplicate name entry.\n");
            exit(1); /**< non-zero exit code to indicate an error */
        }
    }

    /* Print the input */
    print_list();

    printf("\n\nCalling get_name function 10 times:\n");

    /* Returning 10 different random names */
    FOR_RANGE (i, 10) {
        printf("Random name #%d: %s\n", i + 1, get_name());
    }

    return 0;
}
