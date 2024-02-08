#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utility.h"
#include "constants.h"
#include "error_utility.h"
#include "hash_utility.h"


/* Compares a word with a word entry in an index using a hash value */
bool word_compare(const WordEntry *index, const char *word, unsigned int hash_value) {

    return (strcmp(index[hash_value].word, word) == 0) ? TRUE : FALSE;
}

/* Prints the occurrences of a word in the index */
void print_word_entry(WordEntry *index, const char *word) {

    unsigned int hash_value = hash(word);
    ListNode *curr = index[hash_value].lines;

    printf("%s - appears in line", word);
    while (curr != NULL) {
        printf(" %d", curr->line_number);
        curr = curr->next;
    }
    printf(NEW_LINE);
}

/* Compares two strings */
int compare_strings(const void *a, const void *b) {

    return strcmp(*(const char **) a, *(const char **) b);
}

/* Frees memory allocated for a hash */
void free_hash(const WordEntry *index) {

    ListNode *curr;
    int i;

    FOR_RANGE(i, HASH_SIZE) {

        curr = index[i].lines;

        while (curr != NULL) {
            ListNode *temp = curr;
            curr = curr->next;
            free(temp);
        }

        free(index[i].word);
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