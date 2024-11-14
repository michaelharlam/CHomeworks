#include <stdio.h>
#include <stdbool.h>
#include "list.h"

int countingRhyme(int n, int m) {
    if (m < 1) {
        return -1;
    }

    List *list = initList();
    for (int i = 1; i <= n; ++i) {
        append(list, i);
    }

    Node *node = next(last(list));
    while (getSize(list) > 1) {
        for (int i = 1; i < m; ++i) {
            node = next(node);
        }
        Node *nextNode = next(node);
        removeFromList(list, node);
        node = nextNode;
    }

    return getValue(last(list));
}

bool testWithPeriod0(void) {
    int resultTrue = -1;
    int realResult = countingRhyme(5, 0);
    if (resultTrue == realResult) {
        return true;
    }
    printf("Test with period 0 is failed.");
    return false;
}

bool testWithNormalPeriod(void) {
    int resultTrue = 7;
    int realResult = countingRhyme(8, 3);
    if (resultTrue == realResult) {
        return true;
    }
    printf("Test with period 3 is failed.");
    return false;
}

bool testWithPeriodBiggerThenCountOfNumbers(void) {
    int resultTrue = 4;
    int realResult = countingRhyme(5, 6);
    if (resultTrue == realResult) {
        return true;
    }
    printf("Test with period bigger then count of numbers is failed.");
    return false;
}

bool testCollector(void) {
    bool firstTest = testWithPeriod0();
    bool secondTest = testWithNormalPeriod();
    bool thirdTest = testWithPeriodBiggerThenCountOfNumbers();

    return firstTest && secondTest && thirdTest;
}l

int main(void) {
    if (!testCollector()) {
        return 1;
    }

    printf("Введите количество воинов: ");
    int n, m;
    scanf("%d", &n);
    printf("Введите номер воина, которого необходимо убить предыдущим сикариям: ");
    scanf("%d", &m);

    int result = countingRhyme(n, m);

    if (result == -1) {
        printf("Данные введены некорректно.");
        return 1;
    }

    printf("Воин с номером %d останется последним.\n", result);
    return 0;
}