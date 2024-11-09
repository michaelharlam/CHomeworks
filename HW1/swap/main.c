#include <stdio.h>
#include <assert.h>

void swap(int *number1, int *number2) {
    if (*number1 == *number2) {
        return;
    }
    *number1 ^= *number2;
    *number2 ^= *number1;
    *number1 ^= *number2;
}

int main(void) {
    int number1 = 1, number2 = 2;
    printf("Put the numbers\n");
    int result = scanf("%d%d", &number1, &number2);
    assert(result == 2);
    swap(&number1, &number2);
    printf("a = %d, b = %d\n", number1, number2);
}