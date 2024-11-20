#pragma once
#ifndef PARSETREE_H
#define PARSETREE_H
#include <stdbool.h>

typedef struct Node Node;

typedef struct Tree Tree;

Node *createNode(char *value);

Tree *createTree();

Node* buildTree(FILE *file);

#endif //PARSETREE_H
