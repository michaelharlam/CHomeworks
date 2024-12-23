#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(const char *key, int value);

void append(List *list, const char *key, int value);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

int getSize(List *list);

void freeList(List *list);

const char *getKey(Node *node);

int getValue(Node *node);

void changeValue(Node *node, int value);

#endif //LIST_H