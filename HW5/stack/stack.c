#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct StackElement {
    char value;
    struct StackElement *next;
} StackElement;

typedef struct Stack {
    StackElement *head;
} Stack;

Stack *createStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack *stack, int value) {
    StackElement *element = malloc(sizeof(StackElement));
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

int pop(Stack *stack) {
    StackElement *tmp = stack->head;
    int value = tmp->value;
    stack->head = tmp->next;
    free(tmp);
    return value;
}

bool isEmpty(Stack *stack) {
    return stack->head == NULL;
}