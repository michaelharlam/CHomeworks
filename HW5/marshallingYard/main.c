#include "../stack/stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int operationsPriority(char operator) {
    switch (operator) {
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void marshallingYard(char *infix, char *postfix) {
    Stack *stack = createStack();
    int i = 0;
    int j = 0;

    while (infix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j] = infix[i];
            ++j;
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack)) {
                char element = pop(stack);
                if (element == '(') {
                    break;
                }
                postfix[j] = element;
                ++j;
            }
        } else {
            if ((!isEmpty(stack)) && (strcmp(postfix, "") != 0)) {
                char operator = pop(stack);
                push(stack, operator);
                while (!isEmpty(stack) && operationsPriority(infix[i]) <= operationsPriority(operator)) {
                    postfix[j] = pop(stack);
                    ++j;
                    if (isEmpty(stack)) {
                        break;
                    }
                    operator = pop(stack);
                    push(stack, operator);
                }
            }
            push(stack, infix[i]);
        }
        ++i;
    }
    while (!isEmpty(stack)) {
        postfix[j] = pop(stack);
        ++j;
    }
    postfix[j] = '\0';
}

bool testForMarshallingYard(void) {
    char postfix[8] = { '\0' };
    marshallingYard("*+567", postfix);
    if (strcmp(postfix, "56+7*") == 0) {
        return true;
    }
    printf("Test for marshalling Yard is failed.\n");
    return false;
}

int main(void) {
    if (!testForMarshallingYard()) {
        return 1;
    }

    char infix[100] = { '\0' };
    char postfix[100] = { '\0' };
    printf("Вас приветствует сортировочная станция!\n\nВведите выражение в инфиксной форме без пробелов: ");
    scanf("%s", infix);
    marshallingYard(infix, postfix);
    printf("Выражение в постфиксной форме: ");
    printf("%s\n", postfix);
}