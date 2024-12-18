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

int maxLengthOfList(HashTable *HashTable) {
    int maxLength = 0;
    for (int i = 0; i < 256; ++i) {
        List *list = HashTable->table[i];
        if (getSize(list) > maxLength) {
            maxLength = getSize(list);
        }
    }
    return maxLength;
}

float averageLengthOfList(HashTable *HashTable) {
    int sumOfLengths = 0;
    int countOfNotEmptyLists = 0;
    for (int i = 0; i < 256; ++i) {
        List *list = HashTable->table[i];
        if (getSize(list) != 0) {
            ++countOfNotEmptyLists;
            sumOfLengths += getSize(list);
        }
    }
    return (float)sumOfLengths / (float)countOfNotEmptyLists;
}

float occupancyRate(HashTable *HashTable) {
    int countOfElements = 0;
    for (int i = 0; i < 256; ++i) {
        List *list = HashTable->table[i];
        countOfElements += getSize(list);
    }
    return (float)countOfElements / (float)256;
}