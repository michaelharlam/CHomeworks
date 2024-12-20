#include "queue.h"
#include <stdbool.h>
#include <stdio.h>

bool test(void) {
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
    deQueue(queue);
    deQueue(queue);
    enQueue(queue, 110);
    enQueue(queue, 120);
    enQueue(queue, 130);
    int testArrayOfResult[11] = {30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130};
    int deleted = 0;
    bool isMatches = true;
    for (int i = 0; i < 11; i++) {
        deleted = deQueue(queue);
        if (testArrayOfResult[i] == deleted) {
            printf("%d: true\n", i);
        } else {
            printf("%d: false\n", i);
            isMatches = false;
        }
    }
    return isMatches;
}

int main(void) {
    if (!test()) {
        return 1;
    }
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