#include "utility.h"
#include "error_utility.h"


extern mat MAT_A, MAT_B, MAT_C, MAT_D, MAT_E, MAT_F;

/* Analyze the first word of a string to determine the command type */
CommandType first_Word_analysis(char *strPtr) {

    int charCount = 0;
    int i = 0;

    /* Counting the number of characters of the input's first word */
    while (INDEX_NOT_AT_END_OF_LINE(strPtr, i) && !isspace((unsigned char) strPtr[i])) {
        charCount++;
        i++;
    }

    /* Compare the first word with each of the command names */
    FOR_RANGE(i, FUNC_COUNT) {
        if (strlen(funcNames[i]) == charCount && !strncmp(funcNames[i], strPtr, charCount))
            return i;
    }

    return NONE_FUNC; /**< The command name is not valid */
}

/* Get a pointer to the matrix based on the provided string */
mat *whichMatrix(char *ptr) {

    Matrix result = getMatrix(ptr);

    switch (result) {
        case MATRIX_A:return &MAT_A;
        case MATRIX_B:return &MAT_B;
        case MATRIX_C:return &MAT_C;
        case MATRIX_D:return &MAT_D;
        case MATRIX_E:return &MAT_E;
        case MATRIX_F:return &MAT_F;
        case NONE_MATRIX:return NULL;
    }

    return NULL;
}

/* Retrieve the matrix identifier based on the provided string */
Matrix getMatrix(char *ptr) {

    int i;

    FOR_RANGE(i, NUM_OF_MATRICES) {
        if (strncmp(ptr, GET_MATRIX(i), MAX_MAT_NAME) == 0)
            return (Matrix) i;
    }

    return NONE_MATRIX;
}

/* Get the number that the pointer points to. Return 0 if there isn't such a number */
bool getScalar(const char *strPtr, double *returnVal) {

    /* Initialize variables to accumulate the number */
    double result = 0.0;
    int decimalPlaces = 0;
    bool isFractional = FALSE;
    int sign = 1;

    /* Skip leading whitespace */
    while (isspace(*strPtr)) {
        strPtr++;
    }

    /* Check if the first character is a digit or a sign */
    if (!(isdigit(*strPtr) || *strPtr == '-' || *strPtr == '+')) {
        return FALSE;
    }

    /* Detect if the input has leading zeros, indicating an octal number or for cases where the input is not a valid number */
    if (*strPtr == '0' || *strPtr == '\0') {
        return FALSE;
    }

    /* Check for a possible minus or plus sign  */
    if (*strPtr == '-') {
        sign = -1;
        strPtr++;

        /* Check if the negative sign is followed by a digit */
        if (!isdigit(*strPtr)) {
            return FALSE;
        }
    }
    else if (*strPtr || *strPtr == '+') {
        strPtr++;

        /* Check if the positive sign is followed by a digit */
        if (!isdigit(*strPtr)) {
            return FALSE;
        }
    }

    while (*strPtr && (isdigit(*strPtr) || *strPtr == '.')) {
        if (*strPtr == '.') {
            isFractional = TRUE;
        }
        else {
            if (isFractional) {
                decimalPlaces++;
            }
            result = result * 10 + (*strPtr - '0');
        }
        strPtr++;
    }

    /* Adjust the result if it's a fractional number */
    if (isFractional) {
        while (decimalPlaces > 0) {
            result /= 10.0;
            decimalPlaces--;
        }
    }

    *returnVal = (result *= sign);

    return TRUE;
}

/* Copy the contents of one matrix to another */
void copy_mat(mat *srcMatrix, mat *destMatrix) {

    int row, col;
    for(row = 0 ; row < 4 ; row++) {
        for(col = 0 ; col < 4 ; col++) {
            destMatrix->data[row][col] = srcMatrix->data[row][col];
        }
    }
}

/* Prints error message for memory allocation failures and exits */
void handle_memory_allocation_failure(void) {

    fprintf(stderr, MEMORY_ALLOCATION_ERR);
    exit(EXIT_FAILURE);
}

/* Allocates memory with error checking */
void *validated_memory_allocation(size_t size) {

    void *ptr = malloc(size);

    if (ptr == NULL) {
        handle_memory_allocation_failure();
    }
    return ptr;
}

/* Handles end-of-file conditions */
void handle_eof(void) {

    error_handling(EOF_ERR);
    exit(EXIT_FAILURE);
}

/* Prints the details of the user input */
void print_input(const char *userInput) {

    printf("The input is: %s\n", userInput);
}