#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void swap(int *number1, int *number2) {
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

void heapify(int array[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && array[l] > array[largest]) {
        largest = l;
    }

    if (r < n && array[r] > array[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, n, largest);
    }
}


void heapSort(int array[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(array, n, i);

    for (int i= n - 1; i >= 0; --i) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

int mostCommonElement(int array[], int length) {
    int counter = 0, maximum = 0;
    int element = array[0];
    int mostCommon = array[0];

    heapSort(array, length);

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

bool test1(void) {
    int array[5] = {1, 4, 4, 2, 5};
    int mostCommon = 4;
    int result = mostCommonElement(array, 5);
    if (result == mostCommon) {
        return true;
    }
    return false;
}

bool test2(void) {
    int array[19] = {1, 4, 4, 2, 5, 6, 4, 5, 0, 5, 8, 9, 8, 9, 86, 5, 34, 1, 0};
    int mostCommon = 5;
    int result = mostCommonElement(array, 19);
    if (result == mostCommon) {
        return true;
    }
    return false;
}

bool test(void) {
    bool test1Attempt = test1();
    bool test2Attempt = test2();
    if (test1Attempt && test2Attempt) {
        return true;
    }
    if (!test1Attempt) {
        printf("The first test is failed\n");
    }
    if (!test2Attempt) {
        printf("The second test is failed\n");
    }
    return false;
}

int main(void) {
    if (test()) {
        printf("Program is ready for work!\n");
        printf("Input the length of array: ");

        int length = 0;
        int result = 0;

        scanf("%d", &length);
        int *array = malloc(length * sizeof(int));

        for (int i = 0; i < length; ++i) {
            array[i] = rand() % length;
        }

        result = mostCommonElement(array, length);
        printf("The most common element is: %d\n", result);
        free(array);
    }
}