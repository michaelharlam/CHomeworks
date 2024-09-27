#include <stdio.h>
#include <math.h>

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
        return 1 / (float)base;
    } else {
        return base;
    }
}

int fastPower(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if ((exp % 2) == 1) {
        return fastPower(base, exp - 1) * base;
    } else {
        int intermediateResult = fastPower(base, exp / 2);
        return intermediateResult * intermediateResult;
    }
}

void test1(void) {
    if (simplePower(2, 10) == 1024.0) {
        printf("simplePower(2, 10) test passed\n");
    } else {
        printf("simplePower(2, 10) test failed\n");
    }
}

void test2(void) {
    if (simplePower(2, -10) == (1/(float)1024.0)) {
        printf("simplePower(2, -10) test passed\n");
    } else {
        printf("simplePower(2, -10) test failed\n");
    }
}

void test3(void) {
    if (fastPower(2, 10) == 1024) {
        printf("fastPower(2, 10) test passed\n");
    } else {
        printf("fastPower(2, 10) test failed\n");
    }
}

void test4(void) {
    if (fastPower(2, -10) == -1024) {
        printf("fastPower(2, 10) test passed\n");
    } else {
        printf("fastPower(2, 10) test failed\n");
    }
    float result = fastPower(2, -10);
    printf("%f\n", result);
}

void test(void) {
    test1();
    test2();
    test3();
    test4();
}

int main(void) {
    test();
}