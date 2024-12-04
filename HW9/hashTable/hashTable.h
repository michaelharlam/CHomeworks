#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "list.h"

typedef struct HashTable HashTable;

HashTable *createHashTable(void);

int hashFunction(const char *key);

void printTable(HashTable *hashTable);

void appendToTable(HashTable **hashTable, const char *key, int value);

List **getTable(HashTable *HashTable);

int maxLengthOfList(HashTable *HashTable);

float averageLengthOfList(HashTable *HashTable);

float occupancyRate(HashTable *HashTable);

#endif
