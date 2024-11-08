#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(char *name, char *telephoneNumber);

size_t insertAfter(List *list, Node* node, Node* newNode);

size_t insertBefore(List *list, Node *node, Node *newNode);

size_t insertInBeginning(List *list, char *name, char *telephoneNumber);

size_t append(List *list, char *name, char *telephoneNumber);

Node* removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

char *getValue(List *list, Node *node, int part);

#endif //LIST_H
