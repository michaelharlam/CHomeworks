#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue Queue;

Queue *initQueue(void);

void enQueue(Queue *queue, int value);

int deQueue(Queue *queue);

void freeQueue(Queue *queue);

void printQueue(Queue *queue);

#endif //QUEUE_H
