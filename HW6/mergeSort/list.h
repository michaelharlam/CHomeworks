#pragma once

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(char *name, char *telephoneNumber);

void append(List *list, Node *node);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

char *getValue(Node *node, int part);

int getSize(List *list);

void freeList(List *list);