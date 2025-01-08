#include <stdio.h>
#include <stdbool.h>

long fibonaссiNumbersRecursive(int lastNumber) {
    if (lastNumber <= 2) {
        return 1;
    }
    return fibonaссiNumbersRecursive(lastNumber - 1) + fibonaссiNumbersRecursive(lastNumber - 2);
}

long fibonacсiNumbersIterative(int lastNumber) {
    long first = 1;
    long second = 1;
    long result = 0;

    for (int i = 2; i < lastNumber; i++) {
        result = first + second;
        first = second;
        second = result;
    }

    return result;
}

bool testOfIterativeVersion1(void) {
    return fibonacсiNumbersIterative(7) == 13;
}

bool testOfIterativeVersion2(void) {
    return fibonacсiNumbersIterative(11) == 89;
}

bool testOfRecursiveVersion1(void) {
    return fibonaссiNumbersRecursive(7) == 13;
}

bool testOfRecursiveVersion2(void) {
    return fibonacсiNumbersIterative(11) == 89;
}

bool runTests(void) {
    bool valueOfRecursiveTest1 = testOfRecursiveVersion1();
    bool valueOfRecursiveTest2 = testOfRecursiveVersion2();
    bool valueOfIterativeTest1 = testOfIterativeVersion1();
    bool valueOfIterativeTest2 = testOfIterativeVersion2();
    if (valueOfIterativeTest1 && valueOfIterativeTest2 && valueOfRecursiveTest1 && valueOfRecursiveTest2) {
        return true;
    }
    if (!valueOfIterativeTest1) {
        printf("Test 1 of iterative version is failed\n");
    }
    if (!valueOfIterativeTest2) {
        printf("Test 2 of iterative version is failed\n");
    }
    if (!valueOfRecursiveTest1) {
        printf("Test 1 of recursive version is failed\n");
    }
    if (!valueOfRecursiveTest2) {
        printf("Test 2 of recursive version is failed\n");
    }
    return false;
}

int main(void) {
    if (!runTests()) {
        return -1;
    }

    printf("Iterative version:\n");
    for (int i = 2; i < 50; ++i) {
        printf("%ld\n", fibonacсiNumbersIterative(i));
    }

    printf("\nRecursive version:\n");
    for (int i = 2; i < 50; ++i) {
        printf("%ld\n", fibonaссiNumbersRecursive(i));
    }
    return 0;
}

// приблизительно с 38го числа (63245986) рекурсивная версия заметно медленнее, чем итеративная //
