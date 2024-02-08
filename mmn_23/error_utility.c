#include <stdio.h>

#include "error_utility.h"


/* Handle and print an error message */
void error_handling(const char *error, const char *file_name) {

    fprintf(ERROR_LOG_STREAM, "[Error] [File: \" %s \"] %s\n", file_name, error);
}