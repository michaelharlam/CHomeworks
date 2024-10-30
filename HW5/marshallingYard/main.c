#include "../stack/stack.h"
#include <stdio.h>

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
    int i = 0, j = 0;

    while (postfix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            postfix[j] = infix[i];
            ++j;
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && pop(stack) != '(') {
                postfix[j] = pop(stack);
                ++j;
            }
        } else {
            while (!isEmpty(stack) && operationsPriority(infix[i]) <= operationsPriority(stack)) {
                postfix[j] = pop(stack);
                ++j;
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

int main(void) {
    char infix[100];
    char postfix[100];
    scanf("%s", infix);
    marshallingYard(infix, postfix);
    printf("%s\n", postfix);
}