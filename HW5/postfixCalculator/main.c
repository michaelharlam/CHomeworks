#include "../stack/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool operationCheck(char symbol) {
    switch (symbol) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

//пофиксить деление
int calculate(int number1, int number2, char operation) {
    switch (operation) {
        case '+':
            return number1 + number2;
        case '-':
            return number1 - number2;
        case '*':
            return number1 * number2;
        case '/':
            return number1 / number2;
    }
}

int charToInt(char character) {
    return character - '0';
}

int postfixCalculator(char *expression, int stringLength) {
    Stack *stackWithResults = createStack();
    for (int i = 0; i < stringLength; i++) {
        if (operationCheck(expression[i])) {
            int number2 = pop(stackWithResults);
            int number1 = pop(stackWithResults);
            push(stackWithResults, calculate(number1, number2, expression[i]));
        } else {
            push(stackWithResults, charToInt(expression[i]));
        }
    }
    return pop(stackWithResults);
}

bool testForCalculator(void) {
    int result = postfixCalculator("75*56*-", 7);
    if (result == 5) {
        return true;
    }
    printf("Test failed.");
    return false;
}

int main(void) {
    if (!testForCalculator()) {
        return 1;
    }

    printf("Введите выражение в постфиксной форме: ");
    char expression[100] = { '\0' };
    int scanfResult = scanf("%s", expression);
    if (scanfResult != 1) {
        printf("Invalid input.");
        return 1;
    }

    int result = postfixCalculator(expression, strlen(expression));
    printf("%d\n", result);
}
