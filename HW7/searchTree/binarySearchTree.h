#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <stdbool.h>

typedef struct Value Value;

typedef struct Key Key;

typedef struct Node Node;

typedef struct Tree Tree;

Tree *createTree(void);

void append(Tree *tree, int key, char *value);

char *getValue(Tree *tree, int key);

bool isAvailableKey(Tree *tree, int key);

bool deleteKey(Tree *tree, int key);

void deleteTree(Tree *tree);

#endif
