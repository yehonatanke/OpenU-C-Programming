#include <string.h>

#include "hash_utility.h"
#include "utility.h"
#include "constants.h"


/* Computes a hash value for a given string */
unsigned int hash(const char *str) {

    /* Initialize the hash value to a prime number */
    unsigned int hash = 5381;
    int c;

    /* Iterate over each character of the input string */
    while ((c = (int) *str++)) {
        /* Update the hash value using the formula: hash * 33 + c */
        hash = ((hash << 5) + hash) + c;
    }

    /* Take the hash value modulo the size of the hash table */
    return hash % HASH_SIZE;
}

/* Adds a word to the index along with its line number */
void addWordToIndex(WordEntry *index, const char *word, int line_number) {

    ListNode *new_node;
    bool word_exist;
    /* Compute the hash value for the word */
    unsigned int hash_value = hash(word);

    /* Check if the word is already in the index */
    ListNode *curr = index[hash_value].lines;

    while (curr != NULL) {

        word_exist = word_compare(index, word, hash_value);

        if (word_exist) {

            /* Add the line number to the existing word entry */
            new_node = (ListNode *) validated_memory_allocation(sizeof(ListNode));

            new_node->line_number = line_number;
            new_node->next = curr->next;
            curr->next = new_node;
            return;
        }
        curr = curr->next;
    }

    /* Word not found in the index, add it */
    index[hash_value].word = strdup(word);
    new_node = (ListNode *) validated_memory_allocation(sizeof(ListNode));

    new_node->line_number = line_number;
    new_node->next = NULL;
    index[hash_value].lines = new_node;
}

/* Checks if a word exists in an array of words */
bool isWordInArray(char **array, int size, const char *word) {

    int i;

    FOR_RANGE(i, size) {
        if (strcmp(array[i], word) == 0) {
            return TRUE; /**< Word found in the array */
        }
    }
    return FALSE; /**< Word not found in the array */
}
