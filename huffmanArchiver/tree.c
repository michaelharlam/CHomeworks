#include "tree.h"

#include <stdlib.h>

typedef struct Node {
    NodeValue value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *createNode(NodeValue value) {
    Node *node = calloc(1, sizeof(Node));
    node->value = value;
    return node;
}

void addLeftChild(Node *node, Node *child) {
    node->leftChild = child;
}

void addRightChild(Node *node, Node *child) {
    node->rightChild = child;
}

Node *getLeftChild(Node *node) {
    return node->leftChild;
}

Node *getRightChild(Node *node) {
    return node->rightChild;
}

NodeValue getValue(Node *node) {
    return node->value;
}

void setValue(Node *node, NodeValue value) {
    node->value = value;
}

void disposeNode(Node *node) {
    if (node == NULL) {
        return;
    }

    disposeNode(node->leftChild);
    disposeNode(node->rightChild);
    free(node);
}