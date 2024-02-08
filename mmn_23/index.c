#include <stdlib.h>
#include <string.h>

#include "index.h"
#include "utility.h"
#include "error_utility.h"
#include "constants.h"
#include "hash_utility.h"


int main(int argc, char *argv[]) {

    FILE *file;
    WordEntry index[HASH_SIZE];
    int i;

    /* Check if the correct arguments number is provided */
    if (argc != VALID_ARG_COUNT) {
        error_handling(INCORRECT_ARG_ERR, argv[0]);
        return EXIT_FAILURE;
    }

    /* Open the file */
    file = fopen(argv[1], "r");
    if (file == NULL) {
        error_handling(OPEN_FILE_ERR, argv[1]);
        return EXIT_FAILURE;
    }

    /* Initialize the hash table */
    FOR_RANGE(i, HASH_SIZE) {
        index[i].word = NULL;
        index[i].lines = NULL;
    }

    program_process(file, index);

    free_hash(index);

    /* Close the file */
    fclose(file);

    return EXIT_SUCCESS;
}

void program_process(FILE *file, WordEntry *index) {

    char line[MAX_LINE_LENGTH];
    char *sorted_words[HASH_SIZE]; /**< Array to store pointers to words for sorting */
    int num_words = 0;
    int line_count = 0;
    int i;

    /* Read the file line by line */
    while (fgets(line, sizeof(line), file)) {
        line_count++;

        /* Tokenize the line into words */
        char *token = strtok(line, SPACES);
        while (token != NULL) {
            /* Add the word to the index */
            addWordToIndex(index, token, line_count);

            /* Add the word to the array for sorting if it's not already present */
            if (!isWordInArray(sorted_words, num_words, token)) {
                sorted_words[num_words] = strdup(token);
                (num_words)++;
            }

            token = strtok(NULL, SPACES);
        }
    }

    /* Sort the array of words lexicographically */
    qsort(sorted_words, num_words, sizeof(char *), compare_strings);

    /* Print the sorted index */
    FOR_RANGE(i, num_words) {
        print_word_entry(index, sorted_words[i]);
    }
}





