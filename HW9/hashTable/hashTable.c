#include <stdlib.h>
#include "list.h"
#include <stdio.h>
#include "string.h"

typedef struct HashTable {
    List **table;
    unsigned int size;
} HashTable;

HashTable *createHashTable(unsigned int size) {
    HashTable *hashTable = malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        return NULL;
    }

    hashTable->size = size;

    hashTable->table = malloc(hashTable->size * sizeof(List*));
    if (hashTable->table == NULL) {
        free(hashTable);
        return NULL;
    }

    for (int i = 0; i < hashTable->size; ++i) {
        hashTable->table[i] = initList();
        if (hashTable->table[i] == NULL) {
            for (int j = 0; j < i; ++j) {
                free(hashTable->table[i]);
            }
            free(hashTable);
            return NULL;
        }
    }

    return hashTable;
}

unsigned int hashFunction(const char *key, unsigned int hashSize) {
    unsigned int hash = 0;
    for (int i = 0; key[i] != '\0'; ++i) {
        hash = (hash + (unsigned int)key[i]) % hashSize;
    }
    return hash;
}

void printTable(HashTable *hashTable) {
    for (unsigned int i = 0; i < hashTable->size; ++i) {
        List *list = hashTable->table[i];
        if (getSize(list) != 0) {
            for (Node *j = first(list); j != NULL; j = next(j)) {
                printf("%d (%s, %d)\n", i, getKey(j), getValue(j));
            }
        }
    }
}

void appendToTable(HashTable **HashTable, const char *key, int value) {
    unsigned int hash = hashFunction(key, (*HashTable)->size);
    List *hashNode = (*HashTable)->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (strcmp(getKey(node), key) == 0) {
            value += getValue(node);
            changeValue(node, value);
            return;
        }
    }
    append(hashNode, key, value);
}

int getValueFromTable(HashTable *HashTable, const char *key) {
    unsigned int hash = hashFunction(key, HashTable->size);
    List *hashNode = HashTable->table[hash];
    for (Node *node = first(hashNode); node != NULL; node = next(node)) {
        if (strcmp(getKey(node), key) == 0) {
            return getValue(node);
        }
    }
    return 0;
}

void destroyHashTable(HashTable **HashTable) {
    for (unsigned int i = 0; i < (*HashTable)->size; ++i) {
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

unsigned int maxLengthOfList(HashTable *HashTable) {
    unsigned int maxLength = 0;
    for (unsigned int i = 0; i < HashTable->size; ++i) {
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
    for (unsigned int i = 0; i < HashTable->size; ++i) {
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
    for (unsigned int i = 0; i < HashTable->size; ++i) {
        List *list = HashTable->table[i];
        countOfElements += getSize(list);
    }

    return (float)countOfElements / (float)(HashTable->size);
}