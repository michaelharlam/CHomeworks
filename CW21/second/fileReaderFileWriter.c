#include <stdbool.h>
#include <stdio.h>
#include "queue.h"


bool fileReaderFileWriter(const char *fileForReadPath, const char *fileForWritePath) {
    FILE* fileForRead = fopen(fileForReadPath, "r");
    if (fileForRead == NULL) {
        return false;
    }
    int a = 0;
    int b = 0;
    fscanf(fileForRead, "%d", &a);
    fscanf(fileForRead, "%d", &b);
    if (a > b) {
        fclose(fileForRead);
        return false;
    }

    Queue *lessThenA = NULL;
    bool isCreated = queueCreate(&lessThenA);
    if (!isCreated) {
        fclose(fileForRead);
        return false;
    }

    Queue *betweenAAndB = NULL;
    isCreated = queueCreate(&betweenAAndB);
    if (!isCreated) {
        fclose(fileForRead);
        queueDispose(lessThenA);
        return false;
    }

    Queue *biggerThenB = NULL;
    isCreated = queueCreate(&biggerThenB);
    if (!isCreated) {
        fclose(fileForRead);
        queueDispose(betweenAAndB);
        queueDispose(lessThenA);
        return false;
    }

    int newNumber = 0;
    bool isEnqueued = false;
    while (fscanf(fileForRead, "%d", &newNumber) != EOF) {
        if (newNumber > b) {
            isEnqueued = enqueue(biggerThenB, newNumber);
        } else if (newNumber < a) {
            isEnqueued = enqueue(lessThenA, newNumber);
        } else {
            isEnqueued = enqueue(betweenAAndB, newNumber);
        }
        if (!isEnqueued) {
            fclose(fileForRead);
            queueDispose(betweenAAndB);
            queueDispose(lessThenA);
            queueDispose(biggerThenB);
            return false;
        }
    }

    fclose(fileForRead);
    FILE* fileForWrite = fopen(fileForWritePath, "w");
    if (fileForWrite == NULL) {
        queueDispose(betweenAAndB);
        queueDispose(lessThenA);
        queueDispose(biggerThenB);
        return false;
    }

    int overwritingNumber = 0;
    bool isDequeued = false;
    while (!isEmpty(lessThenA)) {
        isDequeued = dequeue(lessThenA, &overwritingNumber);
        fprintf(fileForWrite, "%d\n", overwritingNumber);
        if (!isDequeued) {
            fclose(fileForWrite);
            queueDispose(betweenAAndB);
            queueDispose(lessThenA);
            queueDispose(biggerThenB);
            return false;
        }
    }
    fprintf(fileForWrite, "%d\n", a);
    while (!isEmpty(betweenAAndB)) {
        isDequeued = dequeue(betweenAAndB, &overwritingNumber);
        fprintf(fileForWrite, "%d\n", overwritingNumber);
        if (!isDequeued) {
            fclose(fileForWrite);
            queueDispose(betweenAAndB);
            queueDispose(lessThenA);
            queueDispose(biggerThenB);
            return false;
        }
    }
    fprintf(fileForWrite, "%d\n", b);
    while (!isEmpty(biggerThenB)) {
        isDequeued = dequeue(biggerThenB, &overwritingNumber);
        fprintf(fileForWrite, "%d\n", overwritingNumber);
        if (!isDequeued) {
            fclose(fileForWrite);
            queueDispose(betweenAAndB);
            queueDispose(lessThenA);
            queueDispose(biggerThenB);
            return false;
        }
    }

    fclose(fileForWrite);
    queueDispose(lessThenA);
    queueDispose(betweenAAndB);
    queueDispose(biggerThenB);
    return true;
}