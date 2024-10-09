#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *number1, int *number2) {
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void shellSort(int *array, int size) {
    for (int step = size / 2 + 1; step > 0; step /= 2) {
        int j = 0;
        for (int i = step; i < size; ++i) {
            j = i - step;
            while ((array[j] > array[i]) && (j >= 0)) {
                swap(&array[i], &array[j]);
                j -= step;
            }
        }
    }
}

bool test1(void) {
    int size = 1000;
    int *array = malloc(sizeof(int) * size);
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10000;
    }
    shellSort(array, size);
    for (int i = 0; i < size; ++i) {
        if (array[i] > array[i + 1]) {
            printf("Test failed\n");
            free(array);
            return false;
        }
    }
    free(array);
    return true;
}

void test2(void) {
    int size = 6;
    int array[6] = {2, 4, 3, 5, 1, 2};
    shellSort(array, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
}

int main(void) {
    test2();
}