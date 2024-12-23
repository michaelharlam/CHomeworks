#pragma once
#include <stdio.h>

typedef struct Node Node;

Node *createNode(char *value);

Node* buildTree(FILE *file);

void printTree(Node *node);

int treeCount(Node *root);

void deleteTree(Node *root);