#include <stdlib.h>
#include <stdio.h>

typedef struct Queue {
    int head;
    int tail;
    int *arrayOfElements;
    int sizeOfArray;
    int countOfElements;
} Queue;

Queue *initQueue(void) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    int *arrayOfElements = calloc(0, sizeof(int) * 10);
    queue->arrayOfElements = arrayOfElements;
    queue->head = 0;
    queue->tail = -1;
    queue->sizeOfArray = 10;
    queue->countOfElements = 0;
    return queue;
}

void enQueue(Queue *queue, int value) {
    if (queue->countOfElements == queue->sizeOfArray) {
        if ((queue->tail) < (queue->head)) {
            int *bufferArray = calloc(0, sizeof(int) * (queue->tail + 1));
            for (int i = 0; i <= (queue->tail); ++i) {
                bufferArray[i] = queue->arrayOfElements[i];
            }
            for (int i = queue->tail + 1; i < (queue->sizeOfArray); ++i) {
                queue->arrayOfElements[i - (queue->tail + 1)] = queue->arrayOfElements[i];
            }
            for (int i = 0; i <= (queue->tail); ++i) {
                queue->arrayOfElements[i + queue->sizeOfArray - (queue->tail + 1)] = bufferArray[i];
            }
            free(bufferArray);
            queue->head = 0;
            queue->tail = queue->sizeOfArray - 1;
        }
        queue->arrayOfElements = realloc(queue->arrayOfElements, sizeof(int) * queue->sizeOfArray * 2);
        queue->sizeOfArray *= 2;
    } else if (queue->tail == (queue->sizeOfArray - 1)) {
        queue->tail = 0;
    } else {
        queue->tail++;
    }
    queue->arrayOfElements[queue->tail] = value;
    queue->countOfElements++;
}

int deQueue(Queue *queue) {
    if (queue->countOfElements == 0) {
        return 0;
    }
    int head = queue->arrayOfElements[queue->head];
    queue->arrayOfElements[queue->head] = 0;
    queue->countOfElements--;
    if (queue->head == (queue->sizeOfArray - 1)) {
        queue->head = 0;
    } else {
        queue->head++;
    }
    return head;
}

void printQueue(Queue *queue) {
    printf("head: %d\ntail: %d\nsizeOfArray: %d\ncountOfElements: %d\n", queue->head, queue->tail, queue->sizeOfArray, queue->countOfElements);
    for (int i = 0; i < queue->sizeOfArray; ++i) {
        printf("%d: %d ", i, queue->arrayOfElements[i]);
    }
    printf("\n");
}

void freeQueue(Queue *queue) {
    free(queue->arrayOfElements);
    free(queue);
}