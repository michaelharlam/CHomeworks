#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct StackElement StackElement;

typedef struct Stack Stack;

Stack *createStack(void);

void push(Stack *stack, int value);

int pop(Stack *stack);

bool isEmpty(Stack *stack);

#endif //STACK_H
