#include <stdio.h>

#include "error_utility.h"


/* Handle and print an error message */
void error_handling(const char *error) {

    fprintf(ERROR_LOG_STREAM, "[Error] [%s]\n", error);
}