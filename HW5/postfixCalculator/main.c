#include "../stack/stack.h"
#include <stdbool.h>

bool operationCheck(char *symbol) {
    switch (symbol) {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        default:
            return false;
    }
}

//пофиксить деление
int calculate(char *number1, char *number2, char *operation) {
    int int_number1 = (int)number1;
    int int_number2 = (int)number2;
    switch (operation) {
        case '+':
            return int_number1 + int_number2;
        case '-':
            return int_number1 - int_number2;
        case '*':
            return int_number1 * int_number2;
        case '/':
            return int_number1 / int_number2;
    }
}

int postfixCalculator(char *expression, int stringLength) {
    Stack *stackWithResults = createStack();
    for (int i = 0; i < stringLength; i++) {
        if (!operationCheck(expression[i]) && !operationCheck(expression[i + 1])) {
            push(stackWithResult, )
        }
    }
}

int main() {}