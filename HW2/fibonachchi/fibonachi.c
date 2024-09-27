#include <stdio.h>

int fibonachiNumbersRecurive(int lastNumber) {
    if (lastNumber <= 2) {
        return 1;
    }
    return fibonachiNumbersRecurive(lastNumber - 1) + fibonachiNumbersRecurive(lastNumber - 2);
}

int fibonachiNumbersIterative(int lastNumber) {
    int number[10000] = {1, 1};

    for (int i = 2; i < lastNumber; i++) {
        number[i] = number[i - 1] + number[i - 2];
    }

    return number[lastNumber - 1];
}

void test1(void) {
    if (fibonachiNumbersIterative(7) == 13) {
        printf("Iterative test 1 complited\n");
    } else {
        printf("Iterative test 1 failed\n");
    }
}

void test2(void) {
    if (fibonachiNumbersIterative(11) == 89) {
        printf("Iterative test 2 complited\n");
    } else {
        printf("Iterative test 2 failed\n");
    }
}

void test3(void) {
    if (fibonachiNumbersRecurive(7) == 13) {
        printf("Recursive test 1 complited\n");
    } else {
        printf("Recursive test 1 failed\n");
    }
}

void test4(void) {
    if (fibonachiNumbersIterative(11) == 89) {
        printf("Recursive test 2 complited\n");
    } else {
        printf("Recursive test 2 failed\n");
    }
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