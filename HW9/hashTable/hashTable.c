#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include <stdbool.h>
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

int hashFunction(const char *key) {
    int hash = 0;
    int hashSize = 256;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = (hash + (int)key[i]) % hashSize;
    }
    return hash;
}

void printTable(HashTable *hashTable) {
    for (int i = 0; i < 256; ++i) {
        List *list = hashTable->table[i];
        if (getSize(list) != 0) {
            for (Node *j = first(list); j != NULL; j = next(j)) {
                printf("%d (%s, %d)\n", i, getKey(j), getValue(j));
            }
        }
    }
}

void appendToTable(HashTable **HashTable, const char *key, int value) {
    int hash = hashFunction(key);
    List *hashNode = (*HashTable)->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (strcmp(getKey(node), key) == 0) {
            value += getValue(node);
            changeValue(node, value);
            free(key);
            return;
        }
    }
    append(hashNode, key, value);
}

int getValueFromTable(HashTable *HashTable, const char *key) {
    int hash = hashFunction(key);
    List *hashNode = HashTable->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (strcmp(getKey(node), key) == 0) {
            return getValue(node);
        }
    }
    return 0;
}

void destroyHashTable(HashTable **HashTable) {
    for (int i = 0; i < 256; ++i) {
        List *hashNode = (*HashTable)->table[i];
        if (hashNode != NULL) {
            free(hashNode);
        }
    }
    free(*HashTable);
}

List **getTable(HashTable *HashTable) {
    return HashTable->table;
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