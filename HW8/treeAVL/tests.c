#include "treeAVL.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool testOfAppendAndAvailability(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");
    append(map, "025", "ddd");
    append(map, "075", "eee");
    append(map, "125", "fff");
    append(map, "175", "ggg");

    bool availability = isAvailableKey(map, "100") && isAvailableKey(map, "050") && isAvailableKey(map, "175");
    bool absenceOfAvailability = isAvailableKey(map, "015") && isAvailableKey(map, "390");

    deleteTree(&map);
    return availability && !absenceOfAvailability;
}

bool testOfAppendAndDelete(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");
    append(map, "025", "ddd");
    append(map, "075", "eee");
    append(map, "125", "fff");
    append(map, "175", "ggg");

    deleteKey(&map, "075");
    bool availabilityAfterDeleteOfNodeWithoutChildren = isAvailableKey(map, "075");

    deleteKey(&map, "150");
    bool availabilityAfterDeleteOfNodeWithOneChild = isAvailableKey(map, "150");

    deleteKey(&map, "100");
    bool availabilityAfterDeleteOfRoot = isAvailableKey(map, "100");

    deleteKey(&map, "003");

    deleteTree(&map);
    return !availabilityAfterDeleteOfNodeWithoutChildren && !availabilityAfterDeleteOfNodeWithOneChild && !availabilityAfterDeleteOfRoot;
}

bool testOfGettingValue(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");

    char *valueWithKey100 = getValue(map, "100");
    char *valueWithKey50 = getValue(map, "050");
    char *valueWithKey150 = getValue(map, "150");

    bool equalityOfValueWithKey100 = strcmp(valueWithKey100, "aaa") == 0;
    bool equalityOfValueWithKey50 = strcmp(valueWithKey50, "bbb") == 0;
    bool equalityOfValueWithKey150 = strcmp(valueWithKey150, "ccc") == 0;

    deleteTree(&map);
    return equalityOfValueWithKey50 && equalityOfValueWithKey150 && equalityOfValueWithKey100;
}

char *intUnder10MillionsToString(int number) {
    char *result = calloc(0, 7 * sizeof(char));
    result[0] = (char)(number / 1000000);
    result[1] = (char)(number % 1000000 / 100000);
    result[2] = (char)(number % 100000 / 10000);
    result[3] = (char)(number % 10000 / 1000);
    result[4] = (char)(number % 1000 / 100);
    result[5] = (char)(number % 100 / 10);
    result[6] = (char)(number % 10);
    return result;
}

bool testWithManyElements(void) {
    Tree *map = createTree();
    for (int i = 0; i < 10000000; i++) {
        char *number = intUnder10MillionsToString(i);
        append(map, number, "jjj");
    }
    int realHeight = getHeightOfTree(map);
    deleteTree(&map);
    return realHeight < 30;
}

bool runTests(void) {
    bool result = testOfAppendAndAvailability() && testOfAppendAndDelete() && testOfGettingValue() && testWithManyElements();
    return result;
}