#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int binaryToDecimal(char *number, int length) {
    int decimal = 0;
    for (int i = length - 1; i >= 0; --i) {
        decimal += (number[length - i - 1] - '0') * (int)pow(2, i);
    }
    return decimal;
}

bool testWithOrdinaryDigits(void) {
    int trueResult = 5;
    int result = binaryToDecimal("101", 3);
    if (result != trueResult) {
        printf("Test case failed on testWithOrdinaryDigits()\n");
        return false;
    }
    return true;
}

bool testWithBigNumberOfOnes(void) {
    int trueResult = 2097151;
    int result = binaryToDecimal("111111111111111111111", 21);
    if (result != trueResult) {
        printf("Test case failed on testWithBigNumberOfOnes()\n");
        return false;
    }
    return true;
}

bool testWith8Bits(void) {
    int trueResult = 6;
    int result = binaryToDecimal("00000110", 8);
    if (result != trueResult) {
        printf("Test case failed on testWith8Bits()\n");
        return false;
    }
    return true;
}

bool runTests(void) {
    return testWithOrdinaryDigits() && testWithBigNumberOfOnes() && testWith8Bits();
}

int main(void) {
    printf("Введите длину строки: ");
    int length = 0;
    scanf("%d", &length);
    printf("Введите число в двоичной системе счисления: ");
    char *number = malloc(length * sizeof(char));
    scanf("%s", number);
    length = binaryToDecimal(number, length);
    printf("Число в десятичной системе счисления: %d\n", length);
    free(number);
}