#pragma once

typedef struct {
    char value;
    int frequency;
} NodeValue;

typedef struct Node Node;

Node *createNode(NodeValue value);

void addLeftChild(Node *node, Node *child);

void addRightChild(Node *node, Node *child);

Node *getLeftChild(Node *node);

Node *getRightChild(Node *node);

NodeValue getValue(Node *node);

void setValue(Node *node, NodeValue value);

void disposeNode(Node *node);
