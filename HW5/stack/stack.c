#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stackElement {
    char value;
    struct stackElement *next;
} stackElement;

typedef struct Stack {
    stackElement *head;
} Stack;

Stack *createStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    stackElement *element = malloc(sizeof(stackElement));
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

int pop(Stack *stack) {
    stackElement *tmp = stack->head;
    int value = tmp->value;
    stack->head = tmp->next;
    free(tmp);
    return value;
}

bool isEmpty(Stack *stack) {
    return stack->head == NULL;
}