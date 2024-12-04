#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(const char *key, int value);

void insertAfter(List *list, Node* node, Node* newNode);

void insertBefore(List *list, Node *node, Node *newNode);

void insertInBeginning(List *list, Node *newNode);

void append(List *list, Node *newNode);

void appendCopy(List *list, Node *node);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

int getSize(List *list);

void freeList(List *list);

char *getKey(Node *node);

int getValue(Node *node);

#endif //LIST_H