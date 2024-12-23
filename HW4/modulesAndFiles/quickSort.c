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