#include <stdio.h>
#include "parseTree.h"

int main(void) {
    FILE *file = fopen("test.txt", "r");
    Node* treeRoot = buildTree(file);
    printf("0");
}