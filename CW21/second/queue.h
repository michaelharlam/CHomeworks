#pragma once

#include <stdbool.h>

typedef struct Queue Queue;

bool queueCreate(Queue **queue);

bool enqueue(Queue *queue, int value);

bool dequeue(Queue *queue, int *value);

bool isEmpty(Queue *queue);

void queueDispose(Queue *queue);