#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct hashTable hashTable;

hashTable *createHashTable(void);

int hashFunction(const char *key);

void printTable(hashTable *hashTable);

void appendToTable(hashTable **hashTable, const char *key, int value);

#endif
