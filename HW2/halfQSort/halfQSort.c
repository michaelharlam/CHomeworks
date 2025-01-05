#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *number1, int *number2) {
    if (number1 == number2) {
        return;
    }
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

void halfQSort(int *array, int size) {
    int left = 0;
    int right = size - 1;
    int middle = array[0];

    swap(&array[0], &array[size / 2]);

    do {
        while (array[left] < middle) {
            ++left;
        }
        while (array[right] > middle) {
            --right;
        }
        if (left <= right) {
            swap(&array[left], &array[right]);
            ++left;
            --right;
        }
    } while (left <= right);
}

int userInput(void) {
    printf("Program is ready for work!\n");
    printf("Input the length of array:\n");
    int length = 0;
    scanf("%d", &length);
    int *array = malloc(length * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error!\n");
        return 1;
    }
    for (int i = 0; i < length; ++i) {
        array[i] = rand() % length;
    }
    printf("First element: %d\n", array[0]);
    halfQSort(array, length);
    for (int i = 0; i < length; ++i) {
        printf(" %d", array[i]);
    }
    free(array);
    return 0;
}

bool testOfHalfQSort(void) {
    int array[10] = {5, 1, 7, 2, 3, 8, 3, 90, 4};
    int firstElement = 5;
    int element = 0;
    int length = 10;

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
    if (!testOfHalfQSort()) {
        return -1;
    }

    return userInput();
}