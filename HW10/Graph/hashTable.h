#pragma once
#include "list.h"

typedef struct HashTable HashTable;

HashTable *createHashTable(void);

int hashFunction(int key);

void printTable(HashTable *hashTable, int countOfVertices);

void appendToTable(HashTable **hashTable, int key, int *value);

void addToTableValue(HashTable **HashTable, int key, int value);

int maxLengthOfList(HashTable *HashTable);

int *getValueFromTable(HashTable *HashTable, int key);

float averageLengthOfList(HashTable *HashTable);

float occupancyRate(HashTable *HashTable);