#include <stdio.h>
#include <stdlib.h>

int incompleteQuotient(int dividend, int divider) {
    int counter = 0;
    int dividendSign = 1;
    int dividerSign = 1;
    int resultSign = 1;
    printf("Put the dividend and the divider:\n");

    if (dividend != abs(dividend)) {
        dividendSign *= -1;
        dividend *= -1;
    }
    if (divider != abs(divider)) {
        dividerSign *= -1;
        divider *= -1;
    }

    int cc = 0;

    while (dividend <= divider) {
        dividend -= divider;
        counter += 1;
    }

    if (dividendSign != dividerSign) {
        resultSign *= -1;
    }

    printf("Incomplete quotient = %d\nRemainder of division = %d", counter * resultSign, dividend);
}

int main(void) {
    int dividend = 1;
    int divider = 0;
    printf("Put the dividend and the divider:\n");
    int result = scanf("%d%d", &dividend, &divider);
    if (result != 2) {
        printf("Incorrect input\n");
        return 1;
    }

    incompleteQuotient(dividend, divider);
}