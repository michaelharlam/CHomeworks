#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include "string.h"

typedef struct HashTable {
    List **table;
} HashTable;

HashTable *createHashTable(void) {
    HashTable *hashTable = malloc(sizeof(HashTable));
    hashTable->table = malloc(256 * sizeof(List*));
    for (int i = 0; i < 256; ++i) {
        hashTable->table[i] = initList();
    }
    return hashTable;
}

int hashFunction(int key) {
    int hashSize = 256;
    return key % hashSize;
}

void printTable(HashTable *hashTable, int countOfVertices) {
    for (int i = 0; i < 256; ++i) {
        List *list = hashTable->table[i];
        if (getSize(list) != 0) {
            for (Node *j = first(list); j != NULL; j = next(j)) {
                printf("Государство со столицей %d: ", getKey(j));
                int *cities = getValue(j);
                for (int k = 0; k < countOfVertices; k++) {
                    printf("%d ", cities[k]);
                }
                printf("\n");
            }
        }
    }
}

void appendToTable(HashTable **HashTable, int key, int *value) {
    int hash = hashFunction(key);
    List *hashNode = (*HashTable)->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (getKey(node) == key) {
            changeValue(node, value);
            return;
        }
    }
    append(hashNode, key, value);
}

void addToTableValue(HashTable **HashTable, int key, int value) {
    int hash = hashFunction(key);
    List *hashNode = (*HashTable)->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (getKey(node) == key) {
            addOneToValue(node, value);
            return;
        }
    }
}

int *getValueFromTable(HashTable *HashTable, int key) {
    int hash = hashFunction(key);
    List *hashNode = HashTable->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (getKey(node) == key) {
            return getValue(node);
        }
    }
    return 0;
}

void destroyHashTable(HashTable **HashTable) {
    for (int i = 0; i < 256; ++i) {
        List *hashNode = (*HashTable)->table[i];
        for (Node *node = first(hashNode); node != NULL; node = next(node)) {
            Node *nextNode = next(node);
            free(nextNode);
        }
        free(hashNode);
    }
    free(*HashTable);
}