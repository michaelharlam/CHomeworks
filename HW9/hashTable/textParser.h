#ifndef TEXTPARSER_H
#define TEXTPARSER_H
#include "hashTable.h"

HashTable *textToTable(char *fileName);

void printCountOfWords(HashTable *hashTable);

#endif
