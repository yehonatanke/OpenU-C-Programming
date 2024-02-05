#include "mainmat.h"
#include "utility.h"
#include "process_input.h"
#include "message_utility.h"


mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;

int main() {

    matrices_initialization();
    program_process();

    return 0;
}

/* Process the main functionality of the program */
void program_process() {

    char *userInput = NULL;

    /* Open with a user-friendly message */
    printf(OPENING_MESSAGE);

    /* Process the input until a stop command or the end of the file */
    while (TRUE) {

        line_process(&userInput); /**< get the input line */
        analyze_input(userInput); /**< handle the line the user entered */

        printf("\nPlease enter a command.\n");
    }
}

/* Initialize all matrices to 0 in all cells */
void matrices_initialization() {

    double zero[] = {0};
    int size = sizeof(zero) / sizeof(zero[0]);

    read_mat(&MAT_A, zero, size);
    read_mat(&MAT_B, zero, size);
    read_mat(&MAT_C, zero, size);
    read_mat(&MAT_D, zero, size);
    read_mat(&MAT_E, zero, size);
    read_mat(&MAT_F, zero, size);
}

