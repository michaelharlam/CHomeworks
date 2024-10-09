#include <stdio.h>
#include <stdbool.h>

long fibonaссiNumbersRecursive(int lastNumber) {
    if (lastNumber <= 2) {
        return 1;
    }
    return fibonaссiNumbersRecursive(lastNumber - 1) + fibonaссiNumbersRecursive(lastNumber - 2);
}

long fibonacсiNumbersIterative(int lastNumber) {
    long number[10000] = {1, 1};

    for (int i = 2; i < lastNumber; i++) {
        number[i] = number[i - 1] + number[i - 2];
    }

    return number[lastNumber - 1];
}

bool iterativeTest1(void) {
    if (fibonacсiNumbersIterative(7) == 13) {
        return true;
    }
    return false;
}

bool iterativeTest2(void) {
    if (fibonacсiNumbersIterative(11) == 89) {
        return true;
    }
    return false;
}

bool recursiveTest1(void) {
    if (fibonaссiNumbersRecursive(7) == 13) {
        return true;
    }
    return false;
}

bool recursiveTest2(void) {
    if (fibonacсiNumbersIterative(11) == 89) {
        return true;
    }
    return false;
}

bool test(void) {
    bool valueOfRecursiveTest1 = recursiveTest1(), valueOfRecursiveTest2 = recursiveTest2();
    bool valueOfIterativeTest1 = iterativeTest1(), valueOfIterativeTest2 = iterativeTest2();
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
    if (test()) {
        printf("Iterative version:\n");
        for (int i = 2; i < 50; ++i) {
            printf("%ld\n", fibonacсiNumbersIterative(i));
        }

        printf("\nRecursive version:\n");
        for (int i = 2; i < 50; ++i) {
            printf("%ld\n", fibonaссiNumbersRecursive(i));
        }
    }
}

// приблизительно с 38го числа (63245986) рекурсивная версия заметно медленнее, чем итеративная //