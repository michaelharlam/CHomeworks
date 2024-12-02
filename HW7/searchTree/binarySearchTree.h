#pragma once

#include <stdbool.h>

typedef struct Value Value;

typedef struct Key Key;

typedef struct Tree Tree;

Tree *createTree(void);

void append(Tree *tree, int key, char *value);

char *getValue(Tree *tree, int key);

bool isAvailableKey(Tree *tree, int key);

bool deleteKey(Tree *tree, int key);

void deleteTree(Tree **tree);