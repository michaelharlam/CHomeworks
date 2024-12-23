#include <stdio.h>


void swap(int *number1, int *number2) {
    if (number1 == number2) {
        return;
    }
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}


int main(void) {
    int number1 = 1, number2 = 2;
    printf("Put the numbers\n");
    int resultOfScanf = scanf("%d%d", &number1, &number2);
    if (resultOfScanf != 2) {
        printf("Wrong input\n");
        return 1;
    }
    swap(&number1, &number2);
    printf("a = %d, b = %d\n", number1, number2);
}