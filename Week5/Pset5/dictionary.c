// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int counter = 0;
// Number of buckets in hash table
const unsigned int N = 25;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    char wordtemp[LENGTH + 1];

    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
      wordtemp[i] = tolower(word[i]);
    }
    if (n < LENGTH)
    {
        wordtemp[n] = '\n';
    }
    else
    {
        wordtemp[n] = '\0';
    }

    int hash_number = hash(wordtemp);
    // set cursor to start of appropriate lined list
    node *cursor = table[hash_number];

    // traverse list
    while (cursor != NULL)
    {

        // check node's word to see if it is target word, ignoring case

        if (strcmp(wordtemp, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;

}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    char first_letter = word[0];

    int char_number = first_letter - 97;

    return char_number;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char word_read[LENGTH + 1];

    while (fgets(word_read, LENGTH + 1, file) != NULL)
    {

        counter++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        if ((int)word_read[0] < 97)
        {
            continue;
        }
        strcpy(n->word, word_read);
        n->next = NULL;

        int hash_number = hash(n->word);

        if (table[hash_number] == NULL)
        {
            table[hash_number] = n;
        }
        else
        {
            n->next = table[hash_number]->next;
            table[hash_number]->next = n;
        }
    }

    return true;

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // dictionary size counter
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *head = NULL;
    node *cursor = head;
    // freeing linked lists
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
    return true;
}
