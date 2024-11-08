#pragma once

typedef struct Node Node;

typedef struct List List;

void append(List *list, int value);

List* initList(void);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *last(List *list);

int getValue(Node *node);

void freeList(List *list);

int getSize(List *list);