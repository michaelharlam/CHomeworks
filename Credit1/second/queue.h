#pragma once

typedef struct Queue Queue;

Queue* createQueue(void);

void enqueue(Queue* queue, int data);

int dequeue(Queue* queue);

void destroyQueue(Queue* queue)