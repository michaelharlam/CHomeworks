#pragma once
#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

typedef struct List List;

List* initList(void);

Node* createNode(int data);

void insertAfter(List *list, Node* node, Node* newNode);

void insertBefore(List *list, Node *node, Node *newNode);

void insertInBeginning(List *list, Node *newNode);

void append(List *list, Node *newNode);

void appendCopy(List *list, Node *node);

void removeFromList(List *list, Node *node);

Node *next(Node *node);

Node *first(List *list);

Node *last(List *list);

int getValue(Node *node);

int getSize(List *list);

void freeList(List *list);

#endif //LIST_H