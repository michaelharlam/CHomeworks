#include <stdio.h>

#include "fileReader.h"
#include "hashTable.h"
#include <stdlib.h>
#include <string.h>

int wordCounter(char *fileName) {
    hashTable *hashTable = createHashTable();
    char *text = malloc(sizeof(char) * 10000);
    int arrayLength = 0;

    bool isOpened = fileReader(text, &arrayLength, fileName);
    if (!isOpened) {
        printf("File could not be opened\n");
        return -1;
    }

    unsigned int index = 0;
    char letter = text[0];
    while (index < arrayLength) {
        char *word = malloc(sizeof(char) * 100);
        int wordLength = 0;
        letter = text[index];
        while (letter != ' ') {
        }
    }
}

int main(void) {
    hashTable *table = createHashTable();
    appendToTable(&table, "one", 1);
    appendToTable(&table, "two", 2);
    appendToTable(&table, "three", 3);
    appendToTable(&table, "four", 4);
    appendToTable(&table, "five", 5);
    //appendToTable(&table, "there", 90);
    printTable(table);
}