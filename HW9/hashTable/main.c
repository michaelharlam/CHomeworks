#include "hashTable.h"
#include "textParser.h"
#include "tests.h"
#include <stdio.h>

int main(void) {
    if (!runTests()) {
        return 1;
    }

    HashTable *hashTable = textToTable("test.txt");
    printCountOfWords(hashTable);
    printf("Максимальная длина списка: %d.\n", maxLengthOfList(hashTable));
    printf("Средняя длина списка: %f.\n", averageLengthOfList(hashTable));
    printf("Коэффициент заполняемости таблицы: %f.\n", occupancyRate(hashTable));
    destroyHashTable(&hashTable);
    return 0;
}