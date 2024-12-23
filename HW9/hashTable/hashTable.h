#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "list.h"

typedef struct HashTable HashTable;

HashTable *createHashTable(void);

int hashFunction(const char *key);

void printTable(HashTable *hashTable);

void appendToTable(HashTable **hashTable, const char *key, int value);

int getValueFromTable(HashTable *hashTable, const char *key);

List **getTable(HashTable *HashTable);

void destroyHashTable(HashTable **hashTable);

int maxLengthOfList(HashTable *HashTable);

float averageLengthOfList(HashTable *HashTable);

float occupancyRate(HashTable *HashTable);

#endif
