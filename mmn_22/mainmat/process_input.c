#include "process_input.h"
#include "constants.h"
#include "error_utility.h"
#include "message_utility.h"


/* Extern the matrices */
extern mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;

/* Get user input */
void get_input(char userInput[]) {

    /* Open with a user-friendly message */
    printf(OPENING_MESSAGE);

    /* If there's no line, the program reached the end of the file before receiving stop command */
    if (fgets(userInput, INPUT_MAX_LENGTH, stdin) == NULL) {
        handle_eof();
    }

    /* Print the input */
    print_input(userInput);
}

/* Process a line of user input */
bool line_process(char **userInput) {

    /* Allocate initial memory for user input */
    *userInput = (char *) validated_memory_allocation(sizeof(char *) * (size_t) INIT_LINE_SIZE);

    /* Check if successfully read a line using get_line function */
    if (get_line(*userInput)) {

        /* Check if the line is only with spaces */
        if (IS_END_OF_COMMAND(*userInput)) {
            printf(EMPTY_LINE);
        }
        else {
            /* Print the input using the print_input function */
            print_input(*userInput);
        }

        /* Return TRUE if the line was successfully processed */
        return TRUE;
    }

    /* Return FALSE if unable to read a line */
    return FALSE;
}

/* Reads a line from standard input */
bool get_line(char *line) {

    int ch, i;                                   /**< Character and index variables  */
    char *tempLine;                              /**< Temporary variable for memory allocation */
    size_t lineLength = (size_t) INIT_LINE_SIZE; /**< Get the initial length of the input line */

    /* Iterate through characters until a newline character is encountered */
    for(i = 0 ; (ch = fgetc(stdin)) != '\n' ; i++) {


        /* Handle EOF error */
        if (ch == EOF) {
            error_handling(EOF_ERR);
            free(line); /**< Deallocate the memory pointed to by the pointer */
            exit(0);
        }

        line[i] = (char) ch;

        /* Double the line length if the current index is at the end */
        if (i == lineLength - 1) {

            lineLength *= 2;
            tempLine = (char *) realloc(line, (lineLength + 1) * sizeof(char));

            /* Check for memory allocation failure */
            if (tempLine == NULL) {
                handle_memory_allocation_failure();
            }
            else {
                /* Update the line pointer and reset the temporary pointer */
                line = tempLine;
                tempLine = NULL;
            }
        }
    }

    /* Return TRUE if the last character is the null terminator, FALSE otherwise */
    return line[i] == '\0' ? TRUE : FALSE;
}

/* Analyzes and processes user input for matrix operations */
void analyze_input(char *userInput) {

    CommandType cmdType; /**< Indicator that represents the line command */
    mat *firstMat;       /* A pointer to the first matrix argument */

    MOVE_TO_NON_WHITE(userInput)

    if (IS_END_OF_COMMAND(userInput)) {
        return;
    }

    /* Command classification */
    cmdType = first_Word_analysis(userInput);

    /* Check for command validation */
    if (cmdType == NONE_FUNC) {
        error_handling(UNDEFINED_CMD);
        free(userInput); /**< Deallocate the memory pointed to by the pointer */
        return;
    }

    /* Moving the pointer to the beginning of the next word */
    MOVE_TO_NEXT_WORD(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Check for illegal comma */
    ILLEGAL_COMMA(userInput)

    /* Check for stop command */
    if (cmdType == STOP) {
        handle_stop(userInput);
    }

    /* Check for missing argument */
    MISSING_ARGUMENT(userInput)

    /* Get the first matrix */
    firstMat = whichMatrix(userInput);

    /* There should be a matrix in this point */
    if (firstMat == NULL) {
        error_handling(UNDEFINED_MAT_ERR);
        return;
    }

    /* Move the pointer after the matrix */
    MOVE_AFTER_MAT(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Pointer is now after the first matrix and spaces, so it should point at the first char after mat */
    switch (cmdType) {

        case PRINT_MAT: /**< Handle 'print_mat' command */
            handle_print_mat(userInput, firstMat);
            break;

        case TRANS_MAT: /**< Handle 'trans_mat' command */
            handle_trans_mat(userInput, firstMat);
            break;

        case MUL_SCALAR: /**< Handle 'mul_scalar' command */
            handle_mul_scalar(userInput, firstMat);
            break;

        case ADD_MAT: /**< Handle 'add_mat' command */
        case SUB_MAT: /**< Handle 'sub_mat' command */
        case MUL_MAT: /**< Handle 'mul_mat' command */
            handle_add_sub_mul(userInput, firstMat, cmdType);
            break;

        case READ_MAT: /**< Handle 'read_mat' command */
            handle_read_mat(userInput, firstMat);
            break;

        default:break; /**< Intentionally ignored, as they are handled elsewhere */
    }
}

/* Handle 'stop' command in user input */
void handle_stop(char *userInput) {

    /* Errors check */
    userInput++; /**< Move the pointer to the next position (after the 'stop' command) */
    EXTRANEOUS_TEXT(userInput) /**< Check for extraneous text after the end of the command */

    stop(); /**< Stop the program */
}

/* Handle 'print_mat' command in user input */
void handle_print_mat(const char *userInput, mat *firstMatrix) {

    /* Error checking */
    EXTRANEOUS_TEXT(userInput)

    /* The input is valid, therefore, print the matrix */
    print_mat(firstMatrix);
}

/* Handle 'trans_mat' command in user input */
void handle_trans_mat(char *userInput, mat *firstMatrix) {

    mat *secondMatrix; /**< The second matrix argument */

    /* Error checking */
    MISSING_COMMA(userInput)

    /* Increment the pointer to point after the comma */
    userInput++;
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    MULTIPLE_CONSECUTIVE_COMMAS(userInput)

    secondMatrix = whichMatrix(userInput);

    /* Checks if the second argument is valid */
    if (secondMatrix == NULL) {
        error_handling(MISSING_ARG_ERR);
        return;
    }

    /* Move the pointer after the matrix */
    MOVE_AFTER_MAT(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    EXTRANEOUS_TEXT(userInput)

    /* Perform the matrix transpose */
    trans_mat(firstMatrix, secondMatrix);
}

/* Handle 'mul_scalar' command in user input */
void handle_mul_scalar(char *userInput, mat *firstMat) {

    mat *secondMatrix; /* The second matrix argument */
    double scalar;
    char *endPtr = NULL;

    /* Error checking */
    MOVE_TO_NON_WHITE(userInput)
    MISSING_COMMA(userInput)

    /* Increment the pointer to point after the comma */
    userInput++;
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    MULTIPLE_CONSECUTIVE_COMMAS(userInput)

    endPtr = userInput;

    /* Get the scalar */
    scalar = strtod(userInput, &endPtr);

    if (userInput == endPtr) {
        error_handling(MISSING_SCALAR_ERR);
        return;
    }

    /* Set the pointer after the scalar */
    userInput = endPtr;

    /* Error checking */
    MOVE_TO_NON_WHITE(userInput)
    MISSING_COMMA(userInput)
    userInput++;
    MOVE_TO_NON_WHITE(userInput)
    MULTIPLE_CONSECUTIVE_COMMAS(userInput)

    /* Get the second matrix */
    secondMatrix = whichMatrix(userInput);

    /* There should be a matrix in this point */
    if (secondMatrix == NULL) {
        error_handling(MISSING_ARG_ERR);
        return;
    }

    /* Move the pointer to the next position */
    MOVE_AFTER_MAT(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    EXTRANEOUS_TEXT(userInput)

    mul_scalar(firstMat, scalar, secondMatrix);
}

/* Handle matrix addition, subtraction, or multiplication command in user input */
void handle_add_sub_mul(char *userInput, mat *firstMat, CommandType cmdType) {

    mat *secondMatrix; /* The second matrix argument */
    mat *thirdMatrix;  /* The third matrix argument */

    /* Error checking */
    MISSING_COMMA(userInput)

    /* Increment the pointer to point after the comma */
    userInput++;
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    MULTIPLE_CONSECUTIVE_COMMAS(userInput)

    /* Get the second matrix */
    secondMatrix = whichMatrix(userInput);

    /* There should be a matrix in this point */
    if (secondMatrix == NULL) {
        error_handling(MISSING_ARG_ERR);
        return;
    }

    /* Move the pointer to the next position */
    MOVE_AFTER_MAT(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    MISSING_COMMA(userInput)

    /* Increment the pointer to point after the comma */
    userInput++;
    MOVE_TO_NON_WHITE(userInput)

    /* Get the third matrix */
    thirdMatrix = whichMatrix(userInput);

    /* There should be a matrix in this point */
    if (thirdMatrix == NULL) {
        error_handling(MISSING_ARG_ERR);
        return;
    }

    /* Move the pointer to the next position */
    MOVE_AFTER_MAT(userInput)
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    EXTRANEOUS_TEXT(userInput)

    /* The input is valid, therefore, activate the corresponding function */
    switch (cmdType) {
        case ADD_MAT:add_mat(firstMat, secondMatrix, thirdMatrix);
            break;
        case SUB_MAT:sub_mat(firstMat, secondMatrix, thirdMatrix);
            break;
        case MUL_MAT:mul_mat(firstMat, secondMatrix, thirdMatrix);
            break;
        default:break; /**< Intentionally ignored, as they are handled elsewhere */
    }
}

/* Handle 'read_mat' command in user input */
void handle_read_mat(char *userInput, mat *firstMat) {

    int i = 0;                 /** Counter for the loop */
    double values[16] = {0};   /**< Array to store the input values */
    char *endPtr;              /**< A pointer for 'strtod' function */
    char tempChar;             /** Temporary variable for error checking */
    size_t numOfVal;           /** The number of input values */

    /* Error checking */
    MISSING_ARGUMENT(userInput)
    MISSING_COMMA(userInput)

    /* Increment the pointer to point after the comma */
    userInput++;
    MOVE_TO_NON_WHITE(userInput)

    /* Error checking */
    MULTIPLE_CONSECUTIVE_COMMAS(userInput)
    MISSING_ARGUMENT(userInput)

    endPtr = userInput;
    /* Loop to extract numbers */
    while (IS_NOT_END_OF_COMMAND(userInput)) {

        if (i < 16) {
            values[i] = strtod(userInput, &endPtr);
            i++;
        }
        else {
            strtod(userInput, &endPtr);
        }

        /* Check if conversion was successful */
        if (userInput == endPtr) {
            error_handling(ARG_IS_NOT_DOUBLE);
            return;
        }

        /* Move the pointer to the next position */
        userInput = endPtr;

        MOVE_TO_NON_WHITE(userInput)

        if IS_END_OF_COMMAND(userInput) {
            break;
        }

        /* Check if indicator pointing to the last char and not pointing at a number */
        if IS_NOT_END_OF_COMMAND(userInput) {

            /* Store the current character */
            tempChar = *userInput;

            /* Move the pointer to the next non-white character */
            userInput++;
            MOVE_TO_NON_WHITE(userInput)

            /* Check if reach the end of the command */
            if (IS_END_OF_COMMAND(userInput) && (tempChar != '\n' && tempChar != '\0')) {

                /* Reach here if there is an extraneous text after an end of command */
                error_handling(EXT_TXT_ERR);
                return;
            }
            else if (tempChar != ',') { /**< True if didn't reach end of command */

                /* Reach here if there is a missing comma */
                error_handling(NO_COMMA_ERR);
                return;
            }
            else if (*userInput && *userInput == ',') { /**< True if didn't reach end of command */

                /* Reach here if there are too many commas */
                error_handling(UNNECESSARY_COMMA_ERR);
                return;
            }
        }
    }

    /* Error checking */
    if (IS_NOT_END_OF_COMMAND(userInput)) {
        MISSING_COMMA(userInput)
    }

    /* Get the number of values */
    numOfVal = sizeof(values) / sizeof(values[0]);

    /* If reach here, the input is valid */
    read_mat(firstMat, values, numOfVal);
}