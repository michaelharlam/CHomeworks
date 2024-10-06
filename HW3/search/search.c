#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *number1, int *number2) {
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
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

    if (right > 0) {
        quickSort(array, right + 1);
    }
    if (left < size) {
        quickSort(&array[left], size - left);
    }
}

bool binarySearch(int array[], int size, int value) {
    int middle = size / 2;
    while (array[middle] != value) {
        if (array[middle] == value) {
            return true;
        } else if (array[middle] > value) {
            middle /= 2;
        } else {
            middle += middle / 4;
        }
    }
    return false;
}

bool test1(void) {
    int array[10] = {2, 4, 1, 5, 2, 6, 7, 8, 5, 9};
    quickSort(array, 10);
    return binarySearch(array, 10, 1);
}

bool test2(void) {
    int array[10] = {9, 99, 5, 6, -77, 44, 56, 77, 44, 89};
    quickSort(array, 10);
    return binarySearch(array, 10, 77);
}

bool test(void) {
    bool test1Attempt = test1(), test2Attempt = test2();

    if (test1Attempt && test2Attempt) {
        return true;
    }
    if (!test1Attempt) {
        printf("First test failed\n");
    }
    if (!test2Attempt) {
        printf("Second test failed\n");
    }

    return false;
}

int main(void) {
    if (test()) {
        printf("Program is ready for work!\n");

        int n = 0, k = 0;
        scanf("%d %d", &n, &k);

        int *array = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            array[i] = rand() % 100;
        }

        int *numbers = (int*)malloc(k * sizeof(int));
        for (int i = 0; i < k; ++i) {
            numbers[i] = rand() % 100;
        }
        heapSort(array, n);

        for (int i = 0; i < k; ++i) {
            if (binarySearch(array, n, numbers[i])) {
                printf("%d in array", i + 1);
            } else {
                printf("%d not in array", i + 1);
            }
        }
    }
}