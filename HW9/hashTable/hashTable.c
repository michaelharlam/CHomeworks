#include <stdlib.h>
#include "list.h"
#include <stdio.h>

typedef struct hashTable {
    List **table;
} hashTable;

hashTable *createHashTable(void) {
    hashTable *hashTable = malloc(sizeof(hashTable));
    hashTable->table = malloc(256 * sizeof(List*));
    for (int i = 0; i < 256; ++i) {
        hashTable->table[i] = initList();
    }
    return hashTable;
}

int hashFunction(const char *key) {
    int hash = 0;
    int hashSize = 256;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = (hash + (int)key[i]) % hashSize;
    }
    return hash;
}

void printTable(hashTable *hashTable) {
    for (int i = 0; i < 256; ++i) {
        List *list = hashTable->table[i];
        if (getSize(list) != 0) {
            for (Node *j = first(list); j == last(list); j = next(j)) { //пофиксить условие в ебучем цикле
                printf("%d (%s, %d)\n", i, getKey(j), getValue(j));
            }
        }
    }
}

void appendToTable(hashTable **hashTable, const char *key, int value) {
    int hash = hashFunction(key);
    List *hashNode = (*hashTable)->table[hash];
    append(hashNode, createNode(key, value));
}