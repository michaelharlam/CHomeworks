#include <stdio.h>
#include <assert.h>
#include <math.h>

int incompleteQuotient(int numerator, int denominator) {
    int dividend = 1, divider = 0, counter = 0;
    int dividendSign = 1, dividerSign = 1, resultSign = 1;
    printf("Put the dividend and the divider:\n");
    int result = scanf("%d%d", &dividend, &divider);
    assert(result == 2);

    if (dividend != fabs(dividend)) {
        dividendSign *= -1;
        dividend *= -1;
    }
    if (divider != fabs(divider)) {
        dividerSign *= -1;
        divider *= -1;
    }

    while (dividend >= divider) {
        dividend -= divider;
        counter += 1;
    }

    if (dividendSign != dividerSign) {
        resultSign *= -1;
    }

    printf("Incomplete quotient = %d\nRemainder of division = %d", counter * resultSign, dividend);
}

int main(void) {
    int dividend = 1, divider = 0, counter = 0;
    int dividendSign = 1, dividerSign = 1, resultSign = 1;
    printf("Put the dividend and the divider:\n");
    int result = scanf("%d%d", &dividend, &divider);
    assert(result == 2);

    if (dividend != fabs(dividend)) {
        dividendSign *= -1;
        dividend *= -1;
    }
    if (divider != fabs(divider)) {
        dividerSign *= -1;
        divider *= -1;
    }

    while (dividend >= divider) {
        dividend -= divider;
        counter += 1;
    }

    if (dividendSign != dividerSign) {
        resultSign *= -1;
    }

    printf("Incomplete quotient = %d\nRemainder of division = %d", counter * resultSign, dividend);
}