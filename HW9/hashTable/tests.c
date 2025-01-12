#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "hashTable.h"
#include "readFile.h"

#define SIZE_OF_HASH_TABLE 256

bool testOfAppendAndGetValueFromHashTable(void) {
    HashTable *hashTable = createHashTable(SIZE_OF_HASH_TABLE);

    appendToTable(&hashTable, "hello", 2);
    appendToTable(&hashTable, "lehlo", 3);
    appendToTable(&hashTable, "yyy", 4);

    bool result = false;
    if ((getValueFromTable(hashTable, "hello") == 2) && (getValueFromTable(hashTable, "lehlo") == 3) && (getValueFromTable(hashTable, "yyy") == 4)) {
        result = true;
    }

    destroyHashTable(&hashTable);
    return result;
}

bool testOfReadFile(void) {
    char trueResult[30] = "Test of; file, ?reader: !txt.";
    int trueLength = strlen(trueResult);
    char *result = malloc(sizeof(char) * 100);
    int length = 0;
    bool isOpened = readFile(result, &length, "testOfFileReader.txt");
    bool isEqualStrings = strcmp(trueResult, result) == 0;
    bool isEqualLength = trueLength == length;
    free(result);
    bool isWorking = isOpened && isEqualStrings && isEqualLength;
    if (!isWorking) {
        printf("Test of the fileReader is failed.");
        return false;
    }
    return true;
}

bool runTests(void) {
    return testOfReadFile() && testOfAppendAndGetValueFromHashTable();
}