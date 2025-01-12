#include <stdio.h>
#include "readFile.h"
#include "hashTable.h"
#include "list.h"
#include <stdlib.h>

#define SIZE_OF_HASH_TABLE 256

HashTable *textToTable(char *fileName) {
    HashTable *hashTable = createHashTable(SIZE_OF_HASH_TABLE);
    char *text = malloc(sizeof(char) * 10000);
    int arrayLength = 0;

    bool isOpened = readFile(text, &arrayLength, fileName);
    if (!isOpened) {
        printf("File could not be opened\n");
        free(text);
        return NULL;
    }

    unsigned int index = 0;
    char letter = '\0';
    unsigned int wordLength = 0;
    while (index < arrayLength) {
        char *word = calloc('\0', sizeof(char) * 100);
        letter = text[index];
        while ((letter != ' ') && (letter != '\n')) {
            if (letter != '.' && letter != ':' && letter != ';' && letter != ',' && letter != '!' && letter != '?') {
                word[wordLength] = letter;
                wordLength++;
            }
            ++index;
            letter = text[index];
        }
        index++;
        wordLength = 0;
        appendToTable(&hashTable, word, 1);
    }

    free(text);
    return hashTable;
}

void printCountOfWords(HashTable *hashTable) {
    List **arrayOfListsWIthElements = getTable(hashTable);
    int value = 0;
    for (int i = 0; i < 256; ++i) {
        List *list = arrayOfListsWIthElements[i];
        if (getSize(list) != 0) {
            for (Node *node = first(list); node != NULL; node = next(node)) {
                value = getValue(node);
                if (((value % 10) == 2) || ((value % 10) == 3) || ((value % 10) == 4)) {
                    printf("Слово '%s' повторяется в тексте %d раза.\n", getKey(node), value);
                } else {
                    printf("Слово '%s' повторяется в тексте %d раз.\n", getKey(node), value);
                }
            }
        }
    }
}