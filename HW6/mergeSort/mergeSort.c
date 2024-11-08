#include <stdio.h>
#include <string.h>
#include "../list/list.h"


void mergeSort(List *list, int left, int right, int part) {
    if (left != right) {
        mergeSort(list, left, (left + right) / 2, part);
        mergeSort(list, (left + right) / 2 + 1, right, part);
    } else {
        return;
    }

    int mid = (left + right) / 2;
    int leftIndex = 0, rightIndex = mid;

    Node *leftNode;
    Node *midNode;

    int leftCounter = 0;
    for (Node *i = first(list); i != last(list); i = next(i)) {
        if (leftCounter == left) {
            leftNode = i;
            break;
        }
        leftCounter++;
    }

    int midCounter = 0;
    for (Node *i = first(list); i != last(list); i = next(i)) {
        if (midCounter == mid) {
            midNode = i;
            break;
        }
        midCounter++;
    }

    char *leftValue = getValue(list, leftNode, part);
    char *midValue = getValue(list, midNode, part);

    for (int i = 0; i < (right - mid); ++i) {
        while (strcmp(leftValue, midValue) <= 0) {
            leftNode = next(leftNode);
            leftValue = getValue(list, leftNode, part);
        }
        Node *tmpNode = removeFromList(list, midNode);
        insertBefore(list, leftNode, tmpNode);
    }
}

int main() {
    List *list = initList();
    append(list, "C", "3");
    append(list, "A", "1");
    append(list, "D", "4");
    append(list, "B", "2");
    mergeSort(list, 0, 3, 1);
    for (Node *i = first(list); i != last(list); i = next(i)) {
        printf("%s", getValue(list, i, 1));
    }
}