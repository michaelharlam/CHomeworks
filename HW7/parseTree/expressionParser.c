#include "parseTree.h"
#include <stdbool.h>
#include "expressionParser.h"

bool isOperation(char value) {
    if (value == '+') {
        return true;
    } else if (value == '-') {
        return true;
    } else if (value == '*') {
        return true;
    } else if (value == '/') {
        return true;
    }
    return false;
}

bool isParenthesis(char value) {
    if (value == '(') {
        return true;
    } else if (value == ')') {
        return true;
    }
    return false;
}

int operationCalculator(char operation, int operand1, int operand2) {
    if (operation == '+') {
        return operand1 + operand2;
    }
    if (operation == '-') {
        return operand1 - operand2;
    }
    if (operation == '*') {
        return operand1 * operand2;
    }
    if (operation == '/') {
        return operand1 / operand2;
    }
}