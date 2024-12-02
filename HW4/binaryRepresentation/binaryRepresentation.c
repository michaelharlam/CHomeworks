#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool* binaryRepresentation(int number) {
    bool* arrayBoolNumber = malloc(sizeof(bool) * 8);
    int bit = 0b10000000;
    for (int i = 0; i < 8; ++i) {
        arrayBoolNumber[i] = (number & bit) ? true : false;
        bit >>= 1;
    }
    return arrayBoolNumber;
}

bool* binarySum(bool *number1, bool *number2) {
    bool* result = malloc(sizeof(bool) * 8);
    bool cache = false;
    for (int i = 8 - 1; i >= 0; --i) {
        result[i] = (number1[i] || number2[i] || cache) && (number1[i] ^ number2[i] ^ cache);
        cache = (number1[i] && number2[i]) || (number1[i] && cache) || (number2[i] && cache);
    }
    return result;
}

void binaryPrint(bool *number) {
    for (int i = 0; i < 8; ++i) {
        printf(number[i] ? "1" : "0");
    }
    printf("\n");
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

int decimalRepresentation(bool *number) {
    int result = 0;
    for (int i = 8 - 1; i >= 0; --i) {
        if (number[8 - i - 1]) {
            result += (int)fastPower(2, i);
        }
    }
    return result;
}

bool testForBinaryRepresentation(void) {
    int number = 78;
    bool* result = binaryRepresentation(number);
    bool expected[8] = {false, true, false, false, true, true, true, false};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Тест для бинарного представления числа провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForBinarySum1(void) {
    bool number1[8] = {false, false, false, false, false, false, false, false};
    bool number2[8] = {false, false, false, false, false, false, false, false};
    bool* result = binarySum(number1, number2);
    bool expected[8] = {false, false, false, false, false, false, false, false};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Первый тест для бинарной суммы провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForBinarySum2(void) {
    bool number1[8] = {false, false, false, false, false, false, false, true};
    bool number2[8] = {false, false, false, false, false, false, false, false};
    bool* result = binarySum(number1, number2);
    bool expected[8] = {false, false, false, false, false, false, false, true};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Второй тест для бинарной суммы провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForBinarySum3(void) {
    bool number1[8] = {false, false, false, false, false, false, false, true};
    bool number2[8] = {false, false, false, false, false, false, false, true};
    bool* result = binarySum(number1, number2);
    bool expected[8] = {false, false, false, false, false, false, true, false};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Трейти тест для бинарной суммы провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForBinarySum4(void) {
    bool number1[8] = {false, false, false, false, false, false, true, true};
    bool number2[8] = {false, false, false, false, false, false, false, true};
    bool* result = binarySum(number1, number2);
    bool expected[8] = {false, false, false, false, false, true, false, false};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Четвертый тест для бинарной суммы провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForBinarySum5(void) {
    bool number1[8] = {false, false, false, false, false, false, true, true};
    bool number2[8] = {false, false, false, false, false, false, true, true};
    bool* result = binarySum(number1, number2);
    bool expected[8] = {false, false, false, false, false, true, true, false};
    for (int i = 0; i < 8; ++i) {
        if (result[i] != expected[i]) {
            free(result);
            printf("Пятый тест для бинарной суммы провален.\n");
            return false;
        }
    }
    free(result);
    return true;
}

bool testForDecimalRepresentation(void) {
    bool number1[8] = {false, false, false, false, true, false, false, true};
    int result = decimalRepresentation(number1);
    if (result == 9) {
        return true;
    }
    printf("Тест для десятичного представления провален.\n");
    return false;
}

bool test(void) {
    bool test1 = testForBinaryRepresentation();
    bool test2 = testForBinarySum1();
    bool test3 = testForBinarySum2();
    bool test4 = testForBinarySum3();
    bool test5 = testForBinarySum4();
    bool test6 = testForBinarySum5();
    bool test7 = testForDecimalRepresentation();

    if (test1 && test2 && test3 && test4 && test5 && test6 && test7) {
        return true;
    }
    return false;
}

int main(void) {
    if (!test()) {
        return 1;
    }

    int number1InDecimalSystem = 0, number2InDecimalSystem = 0;

    printf("Вас приветствует восьмибитный сумматор!\n\n");
    printf("Введите два числа в десятичной системе счисления через пробел.\n");

    scanf("%d %d", &number1InDecimalSystem, &number2InDecimalSystem);

    bool* number1InBinarySystem = binaryRepresentation(number1InDecimalSystem);
    bool* number2InBinarySystem = binaryRepresentation(number2InDecimalSystem);

    printf("Первое число в двоичной системе: ");
    binaryPrint(number1InBinarySystem);

    printf("Второе число в двоичной системе: ");
    binaryPrint(number2InBinarySystem);

    bool* resultInBinSystem = binarySum(number1InBinarySystem, number2InBinarySystem);
    printf("Сумма в двоичной системе: ");
    binaryPrint(resultInBinSystem);

    int resultInDecSystem = decimalRepresentation(resultInBinSystem);
    printf("Сумма в десятичной системе: %d", resultInDecSystem);

    free(number1InBinarySystem);
    free(number2InBinarySystem);
    free(resultInBinSystem);
}