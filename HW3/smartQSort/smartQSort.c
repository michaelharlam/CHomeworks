#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *number1, int *number2) {
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void insertionSort(int *array, int size) {
    int j = 0;
    for (int i = 0; i < size; ++i) {
        j = i - 1;
        while ((array[j] > array[i]) && (j >= 0)) {
            swap(&array[i], &array[j]);
            --j;
        }
    }
}

void quickSort(int *array, int size) {
    int left = 0;
    int right = size - 1;
    int middle = array[size / 2];

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

    if ((right + 1) > 10) {
        quickSort(array, right + 1);
    } else if (right > 0) {
        insertionSort(array, right + 1);
    }
    if ((size - left) > 10) {
        quickSort(&array[left], size - left);
    } else if (left < size) {
        insertionSort(&array[left], size - left);
    }
}

bool test(void) {
    int size = 1000;
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10000;
    }
    quickSort(array, size);
    for (int i = 0; i < (size - 1); ++i) {
        if (array[i] > array[i + 1]) {
            printf("Test failed\n");
            return false;
        }
    }
    free(array);
    return true;
}

int main(void) {
    if (test()) {
        printf("Program is ready for work!\n");
    }
}