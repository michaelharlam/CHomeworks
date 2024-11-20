#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parseTree.h"

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

void expressionParser(char *expression) {
    int length = strlen(expression);
    char *elementOfExpression = malloc(sizeof(char) * 10);
    char *arrayWithElementsOfExpression = malloc(length * sizeof(elementOfExpression));
    int counterOfNumbers = 0;
    int number = 0;
    for (int i = 0; i < length; i++) {
        if (expression[i] == ' ') {
            counterOfNumbers = 0;;
            continue;
        }
        if (!isParenthesis(expression[i]) && !isOperation(expression[i])) {
            counterOfNumbers++;
            elementOfExpression[counterOfNumbers] = expression[i];

        }

    }
}