#include "../stack/stack.h"
#include <stdbool.h>
#include <stdio.h>

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

int main(void) {
    int result = postfixCalculator("75*56*-", 7);
    printf("%d\n", result);
}
