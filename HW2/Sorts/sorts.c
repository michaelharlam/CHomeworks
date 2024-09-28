#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *number1, int *number2) {
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
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

double max(int array[], int length) {
    double maximum = -INFINITY;

    for (int i = 0; i < length; ++i) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

void countingSort(int array[], int length) {
    int* numberedArray;
    int* resultArray;
    int maximum = (int)max(array, length), counter = 0;

    numberedArray = (int*)malloc(maximum * sizeof(int));
    resultArray = (int*)malloc(length * sizeof(int));

    for (int i = 0; i <= maximum; ++i) {
        numberedArray[i] = 0;
    }

    for (int i = 0; i < length; ++i) {
        resultArray[i] = 0;
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
}

bool bubbleTest() {
    int array[5] = {8, 5, 3, 2, 4};
    int finalArray[5] = {2, 3, 4, 5, 8};
    bubbleSort(array, 5);
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        if (array[i] == finalArray[i]) {
            ++counter;
        }
    }
    if (counter == 5) {
        return true;
    } else {
        return false;
    }
}

bool countingTest() {
    int array[5] = {8, 5, 3, 2, 4};
    int finalArray[5] = {2, 3, 4, 5, 8};
    countingSort(array, 5);
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        if (array[i] == finalArray[i]) {
            ++counter;
        }
    }
    if (counter == 5) {
        return true;
    } else {
        return false;
    }
}

int main() {
    if (bubbleTest() && countingTest()) {
        clock_t startBubbleSort, endBubbleSort, startCountingSort, endCountingSort;
        int* array;
        int length = 100000;
        array = (int*)malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i) {
            array[i] = rand() % length;
        }

        startBubbleSort = clock();
        bubbleSort(array, length);
        endBubbleSort = clock();
        printf("Bubble Sort: %lf seconds\n", (double)(endBubbleSort - startBubbleSort) / CLOCKS_PER_SEC);

        free(array);

        array = (int*)malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i) {
            array[i] = rand() % length;
        }

        startCountingSort = clock();
        countingSort(array, length);
        endCountingSort = clock();
        printf("Counting Sort: %lf seconds\n", (double)(endCountingSort - startCountingSort) / CLOCKS_PER_SEC);

        free(array);
    } else {
        printf("Tests failed");
    }
}
