#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *number1, int *number2) {
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

void halfQSort(int array[], int length) {
    int firstElementIndex = 0;
    int counter = 0;

    do {
        counter = 0;
        for (int i = 0; i < length; ++i) {
            if ((array[i] < array[firstElementIndex]) && (i > firstElementIndex)) {
                swap(&array[i], &array[firstElementIndex]);
                firstElementIndex = i;
                ++counter;
            }
            if ((array[i] > array[firstElementIndex]) && (i < firstElementIndex)) {
                swap(&array[i], &array[firstElementIndex]);
                firstElementIndex = i;
                ++counter;
            }
        }
    } while (counter != 0);
}

bool test1(void) {
    int array[10] = {5, 1, 7, 2, 3, 8, 3, 90, 4};
    int firstElement = 5, element = 0, length = 10;
    halfQSort(array, length);
    while (array[element] != firstElement) {
        if (array[element] > firstElement) {
            printf("First test failed\n");
            return false;
        }
        ++element;
    }
    while (element < length) {
        if (array[element] < firstElement) {
            printf("First test failed\n");
            return false;
        }
        ++element;
    }
    return true;
}

int main(void) {
    if (test1()) {
        printf("Program is ready for work!\n");
        printf("Input the length of array:\n");
        int length = 0;
        scanf("%d", &length);
        int* array = malloc(length * sizeof(int));
        for (int i = 0; i < length; ++i) {
            array[i] = rand() % length;
        }
        printf("First element: %d\n", array[0]);
        halfQSort(array, length);
        for (int i = 0; i < length; ++i) {
            printf(" %d", array[i]);
        }
        free(array);
    }
}