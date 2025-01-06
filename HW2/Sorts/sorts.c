#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void swap(int *number1, int *number2) {
    if (number1 == number2) {
      return;
    }
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

int max(int array[], int length) {
    int maximum = array[0];

    for (int i = 0; i < length; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

void bubbleSort(int array[], int length) {
    int counter = 0;

    do {
        counter = 0;
        for (int i = 0; i < (length - 1); ++i) {
            if (array[i] > array[i + 1]) {
                swap(&array[i], &array[i + 1]);
                ++counter;
            }
        }
    } while (counter != 0);
}

int countingSort(int array[], int length) {
    int maximum = max(array, length);
    int counter = 0;
    int *numberedArray = calloc(maximum, sizeof(int));
    if (numberedArray == NULL) {
        printf("Memory allocation failed for numberedArray\n");
        return 1;
    }

    int *resultArray = calloc(length, sizeof(int));
    if (resultArray == NULL) {
        printf("Memory allocation failed for numberedArray\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        ++numberedArray[array[i]];
    }

    for (int i = 0; i <= maximum; ++i) {
        for (int j = 0; j < numberedArray[i]; ++j) {
            resultArray[j + counter] = i;
            ++counter;
        }
    }

    for (int i = 0; i < length; ++i) {
        array[i] = resultArray[i];
    }

    free(numberedArray);
    free(resultArray);
    return 0;
}

bool testOfBubbleSort(void) {
    int array[5] = {8, 5, 3, 2, 4};
    int finalArray[5] = {2, 3, 4, 5, 8};
    bubbleSort(array, 5);
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        if (array[i] == finalArray[i]) {
            counter++;
        }
    }

    if (counter != 5) {
        printf("Test of bubble sort is failed");
        return false;
    }
    return true;
}

bool testOfCountingSort(void) {
    int array[5] = {8, 5, 3, 2, 4};
    int finalArray[5] = {2, 3, 4, 5, 8};
    int errorCodeOfCountingSort = countingSort(array, 5);
    if (errorCodeOfCountingSort != 0) {
        printf("Error of memory allocation in test of counting sort");
        return false;
    }
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        if (array[i] == finalArray[i]) {
            counter++;
        }
    }

    if (counter != 5) {
        printf("Test of counting sort is failed");
        return false;
    }
    return true;
}

bool runTests(void) {
    return testOfBubbleSort() && testOfCountingSort();
}

int main() {
    if (!runTests()) {
        return -1;
    }

    clock_t startBubbleSort, endBubbleSort, startCountingSort, endCountingSort;
    int length = 100000;
    int *array = malloc(length * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed for array\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        array[i] = rand() % length;
    }

    startBubbleSort = clock();
    bubbleSort(array, length);
    endBubbleSort = clock();
    printf("Bubble Sort: %lf seconds\n", (double)(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC);

    for (int i = 0; i < length; ++i) {
        array[i] = rand() % length;
    }

    startCountingSort = clock();
    int errorCodeOfCountingSort = countingSort(array, length);
    if (errorCodeOfCountingSort != 0) {
        free(array);
        return 1;
    }
    endCountingSort = clock();
    printf("Counting Sort: %lf seconds\n", (double)(endCountingSort - startCountingSort) / CLOCKS_PER_SEC);

    free(array);
    return 0;
}
