#pragma once
#include <stdbool.h>

typedef struct Node Node;

typedef struct Stack Stack;

Stack *createStack(void);

Node *createNode(int data);

bool isEmpty(Stack *stack);

void push(Stack *stack, int data);

int pop(Stack *stack);

void destroyStack(Stack *stack);