#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

double simplePower(int base, int exp) {
    int iterationsExp = abs(exp) - 1;

    if (exp == 0) {
        return 1;
    }
    if (base == 1) {
        return 1;
    }

    int result = 1;
    for (int i = 0; i <= iterationsExp; ++i) {
        result *= base;
    }

    if (exp < 0) {
        return 1 / (double)result;
    }
    return result;
}

double fastPower(int base, int exp) {
    if (exp == 0) {
        return 1;
    }

    if (exp < 0) {
        return 1 / fastPower(base, -exp);
    }

    if ((exp % 2) == 1) {
        return fastPower(base, exp - 1) * base;
    }

    int intermediateResult = fastPower(base, exp / 2);
    return intermediateResult * intermediateResult;
}

bool simplePowerTest1(void) {
    return fabs(simplePower(2, -10) - (1 / (double)1024)) < 0.01;
}

bool simplePowerTest2(void) {
    return fabs(simplePower(2, 10) - 1024.0) < 0.01;
}

bool fastPowerTest1(void) {
    return fabs(fastPower(2, 10) - 1024.0) < 0.01;
}

bool fastPowerTest2(void) {
    return fabs(fastPower(2, -10) - (1 / (double)1024)) < 0.01;
}

bool runTests(void) {
    bool valueOfSimplePowerTest1 = simplePowerTest1(), valueOfSimplePowerTest2 = simplePowerTest2();
    bool valueOfFastPowerTest1 = fastPowerTest1(), valueOfFastPowerTest2 = fastPowerTest2();
    if (valueOfSimplePowerTest1 && valueOfSimplePowerTest2 && valueOfFastPowerTest1 && valueOfFastPowerTest2) {
        return true;
    }

    if (!valueOfSimplePowerTest1) {
        printf("Test 1 of simple power func failed\n");
    }
    if (!valueOfSimplePowerTest2) {
        printf("Test 2 of simple power func failed\n");
    }
    if (!valueOfFastPowerTest1) {
        printf("Test 1 of fast power func failed\n");
    }
    if (!valueOfFastPowerTest2) {
        printf("Test 2 of fast power func failed\n");
    }
    return false;
}

int main(void) {
    if (!runTests()) {
        return -1;
    }
    printf("Program is ready for work!\n");
}