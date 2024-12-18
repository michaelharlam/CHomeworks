#pragma once

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(int key, int **value);

void append(List *list, int key, int *value);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

int getSize(List *list);

void freeList(List *list);

int getKey(Node *node);

int *getValue(Node *node);

void changeValue(Node *node, int *value);

void addOneToValue(Node *node, int index);