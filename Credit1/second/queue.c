#include <stdlib.h>
#include "stack.h"


typedef struct Queue {
    Stack *pushStack;
    Stack *popStack;
} Queue;

Queue* createQueue(void) {
    Queue* queue = malloc(sizeof(Queue));
    queue->pushStack = createStack();
    queue->popStack = createStack();
    return queue;
}

void enqueue(Queue* queue, int data) {
    push(queue->pushStack, data);
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->popStack)) {
        while (!isEmpty(queue->pushStack)) {
            push(queue->popStack, pop(queue->pushStack));
        }
    }
    return pop(queue->popStack);
}

void destroyQueue(Queue* queue) {
    destroyStack(queue->pushStack);
    destroyStack(queue->popStack);
    free(queue);
}