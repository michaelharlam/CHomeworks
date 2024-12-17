#pragma once

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(int key, int **data);

void append(List *list, int key, int **value);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

void freeList(List *list);

int getSize(List *list);

int getKey(Node *node);

int *getData(Node *node);

void changeData(Node *node, int **data);