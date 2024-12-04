#include "queue.h"


int main(void) {
    Queue *queue = initQueue();
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    enQueue(queue, 40);
    enQueue(queue, 50);
    enQueue(queue, 60);
    enQueue(queue, 70);
    enQueue(queue, 80);
    enQueue(queue, 90);
    enQueue(queue, 100);
    printQueue(queue);
    deQueue(queue);
    printQueue(queue);
    deQueue(queue);
    printQueue(queue);
    enQueue(queue, 110);
    printQueue(queue);
    enQueue(queue, 120);
    printQueue(queue);
    enQueue(queue, 130);
    printQueue(queue);
    enQueue(queue, 140);
    printQueue(queue);
}