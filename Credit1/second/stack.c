#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Stack {
    Node *top;
    int size;
} Stack;

Stack *createStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

Node *createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

bool isEmpty(Stack *stack) {
    return stack->size == 0;
}

void push(Stack *stack, int data) {
    Node *node = createNode(data);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int pop(Stack *stack) {
    int data = stack->top->data;
    Node *node = stack->top;
    stack->top = node->next;
    stack->size--;
    free(node);
    return data;
}

void destroyStack(Stack *stack) {
    while (stack->top != NULL) {
        Node *node = stack->top;
        stack->top = node->next;
        free(node);
    }
    free(stack);
}