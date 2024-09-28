#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double simplePower(int base, int exp) {
    int iterationsExp = fabs(exp) - 1;

    if (exp == 0) {
        return 1;
    }
    if (base == 1) {
        return 1;
    }

    for (int i = 0; i < iterationsExp; ++i) {
        base *= base;
    }

    if (exp < 0) {
        return 1 / (double)base;
    } else {
        return base;
    }
}

double fastPower(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (exp < 0) {
        return 1/fastPower(base, -exp);
    }
    if ((exp % 2) == 1) {
        return fastPower(base, exp - 1) * base;
    } else {
        int intermediateResult = fastPower(base, exp / 2);
        return intermediateResult * intermediateResult;
    }
}

bool simplePowerTest1(void) {
    if  (fabs(simplePower(2, -10) - (1/(double)1024)) < 0.01) {
        return true;
    }
    return false;
}

bool simplePowerTest2(void) {
    if (fabs(simplePower(2, 10) - 1024.0) < 0.01) {
        return true;
    }
    return false;
}

bool fastPowerTest1(void) {
    if (fabs(fastPower(2, 10) - 1024.0) < 0.01) {
        return true;
    }
    return false;
}

bool fastPowerTest2(void) {
    if (fabs(fastPower(2, -10) - (1/(double)1024)) < 0.01) {
        return true;
    }
    return false;
}

bool test(void) {
    bool valueOfSimplePowerTest1 = simplePowerTest1(), valueOfSimplePowerTest2 = simplePowerTest2();
    bool valueOfFastPowerTest1 = fastPowerTest1(), valueOfFastPowerTest2 = fastPowerTest2();
    if (valueOfSimplePowerTest1 && valueOfSimplePowerTest2 && valueOfFastPowerTest1 && valueOfFastPowerTest2) {
        return true;
    } else if (!valueOfSimplePowerTest1) {
        printf("Test 1 of simple power func failed\n");
    } else if (!valueOfSimplePowerTest2) {
        printf("Test 2 of simple power func failed\n");
    } else if (!valueOfFastPowerTest1) {
        printf("Test 1 of fast power func failed\n");
    } else {
        printf("Test 2 of fast power func failed\n");
    }
    return false;
}

int main(void) {
    if (test) {
        printf("Program is ready for work!");*
    }
}