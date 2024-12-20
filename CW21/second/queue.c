#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *back;
} Queue;

bool queueCreate(Queue **queue) {
    *queue = malloc(sizeof(Queue));
    if (*queue == NULL) {
        return false;
    }
    return true;
}

bool isEmpty(Queue *queue) {
    if (queue->front == NULL) {
        return true;
    }
    return false;
}

bool enqueue(Queue *queue, int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = NULL;

    if (isEmpty(queue)) {
        queue->front = node;
    } else {
        queue->back->next = node;
    }
    queue->back = node;

    return true;
}

bool dequeue(Queue *queue, int *value) {
    if (isEmpty(queue)) {
        return false;
    }

    *value = queue->front->value;

    Node *front = queue->front;

    queue->front = front->next;

    free(front);

    return true;
}

void queueDispose(Queue *queue) {
    while (!isEmpty(queue)) {
        int trash;
        dequeue(queue, &trash);
    }
    free(queue);
}