#pragma once

#include <stdbool.h>

typedef struct Value Value;

typedef struct Key Key;

typedef struct Tree Tree;

Tree *createTree(void);

//function of appending an element
void append(Tree *tree, const char *key, const char *value);

const char *getValue(Tree *tree, const char *key);

bool isAvailableKey(Tree *tree, const char *key);

void deleteKey(Tree **tree, const char *key);

void deleteTree(Tree **tree);