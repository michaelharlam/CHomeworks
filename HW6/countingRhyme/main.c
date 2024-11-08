#include <stdio.h>

#include "list.h"

int countingRhyme(int n, int m) {
    List *list = initList();
    for (int i = 1; i <= n; ++i) {
        append(list, i);
    }

    Node *node = last(list);
    while (getSize(list) > 1) {
        for (int i = 0; i < m; ++i) {
            node = next(node);
        }
        Node *nextNode = next(node);
        removeFromList(list, node);
        node = nextNode;
    }

    return getValue(last(list));
}

int main() {
    printf("%d\n", countingRhyme(8, 3));
}