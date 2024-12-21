#include "stack.h"
#include "queue.h"
#include <stdbool.h>
#include <stdio.h>


bool pushAndPopTestWithStack(void) {
    Stack *stack = createStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    bool first = pop(stack) == 40;
    bool second = pop(stack) == 30;
    bool third = pop(stack) == 20;
    bool fourth = pop(stack) == 10;
    destroyStack(stack);
    if (first && second && third && fourth) {
        return true;
    }
    printf("Test case failed on pushAndPopTestWithStack()\n");
    return false;
}

bool isEmptyTestWithStack(void) {
    Stack *stack = createStack();
    bool first = isEmpty(stack);
    push(stack, 10);
    bool second = isEmpty(stack);
    push(stack, 20);
    pop(stack);
    bool third = isEmpty(stack);
    pop(stack);
    bool fourth = isEmpty(stack);
    destroyStack(stack);
    if (first && !second && !third && fourth) {
        return true;
    }
    printf("Test case failed on isEmptyTestWithStack()\n");
    return false;
}

bool enqueueAndDequeueTestWithQueue(void) {
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    bool first = dequeue(queue) == 10;
    bool second = dequeue(queue) == 20;
    bool third = dequeue(queue) == 30;
    destroyQueue(queue);
    if (first && second && third) {
        return true;
    }
    printf("Test case failed on dequeueAndDequeueWithQueue()\n");
    return false;
}

bool runTests(void) {
    return pushAndPopTestWithStack() && isEmptyTestWithStack() && enqueueAndDequeueTestWithQueue();
}