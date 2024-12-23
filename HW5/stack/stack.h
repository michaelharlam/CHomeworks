#ifndef STACK_H
#define STACK_H

typedef struct stackElement stackElement;

typedef struct Stack Stack;

Stack *createStack(void);

void push(Stack *stack, int value);

int pop(Stack *stack);

#endif //STACK_H
