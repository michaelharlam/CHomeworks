#include "quickSort.h"
#include "fileReader.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int mostCommonElement(int array[], int length) {
    int counter = 0, maximum = 0;
    int element = array[0];
    int mostCommon = array[0];

    quickSort(array, length - 1);

    for (int i = 0; i < length; ++i) {
        if (element == array[i]) {
            ++counter;
        } else {
            if (counter > maximum) {
                maximum = counter;
                mostCommon = element;
            }
            counter = 1;
            element = array[i];
        }
    }

    return mostCommon;
}

bool testForQuickSort(void) {
    int size = 1000;
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10000;
    }
    quickSort(array, size);
    for (int i = 0; i < (size - 1); ++i) {
        if (array[i] > array[i + 1]) {
            printf("The test for quick sort is failed\n");
            return false;
        }
    }
    free(array);
    return true;
}


bool testForMostCommonElement1(void) {
    int array[5] = {1, 4, 1, 2, 5};
    int mostCommon = 1;
    int result = mostCommonElement(array, 5);
    if (result == mostCommon) {
        return true;
    }
    printf("The first test for most common element is failed\n");
    return false;
}

bool testForMostCommonElement2(void) {
    int array[19] = {1, 4, 4, 2, 5, 6, 4, 5, 0, 5, 8, 9, 8, 9, 86, 5, 34, 1, 0};
    int mostCommon = 5;
    int result = mostCommonElement(array, 19);
    if (result == mostCommon) {
        return true;
    }
    printf("The second test for most common element is failed\n");
    return false;
}

bool testForFileReader(void) {
    int checkArray[5] = {1, 2, 3, 4, 5};
    char fileName[10] = "test.txt\0";
    int arrayLength = 5;
    int* array = malloc(sizeof(int) * arrayLength);

    bool fileOpening = fileReader(array, arrayLength, fileName);
    if (!fileOpening) {
        free(array);
        return false;
    };

    for (int i = 0; i < arrayLength; ++i) {
        if (array[i] != checkArray[i]) {
            printf("The test for file reader is failed\n");
            free(array);
            return false;
        }
    }
    free(array);
    return true;
}

bool test(void) {
    return testForQuickSort() && testForMostCommonElement1() && testForMostCommonElement2() && testForFileReader();
}

int main(void) {
    if (!test()) {
        return 1;
    }

    printf("Program is ready for work!\n");

    int arrayLength = 72;
    int result = 0;

    int* array = malloc(arrayLength * sizeof(int));
    char fileName[11] = "array.txt\0";
    bool fileOpening = fileReader(array, arrayLength, fileName);
    if (!fileOpening) {
        return 1;
    };

    result = mostCommonElement(array, arrayLength);
    printf("The most common element: %d\n", result);
    free(array);
}