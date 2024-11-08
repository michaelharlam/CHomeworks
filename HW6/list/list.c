#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

typedef struct Node {
    char name[100];
    char telephoneNumber[100];
    struct Node *left;
    struct Node *right;
} Node;

typedef struct List {
    size_t size;
    Node *first;
    Node *last;
} List;

List* initList(void) {
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node* createNode(char *name, char *telephoneNumber) {
    Node *node = malloc(sizeof(Node));
    strcpy(node->telephoneNumber, telephoneNumber);
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

size_t insertAfter(List *list, Node *node, Node *newNode) {
    newNode->right = node->right;
    newNode->left = node;
    node->right = newNode;
    list->size++;
    return list->size;
}

size_t insertBefore(List *list, Node *node, Node *newNode) {
    newNode->left = node->left;
    newNode->right = node;
    node->left = newNode;
    list->size++;
    return list->size;
}

size_t insertInBeginning(List *list, char *name, char *telephoneNumber) {
    Node *newNode = createNode(name, telephoneNumber);
    newNode->right = list->first;
    newNode->left = NULL;
    list->first = newNode;
    list->size++;
    return list->size;
}

size_t append(List *list, char *name, char *telephoneNumber) {
    Node *newNode = createNode(name, telephoneNumber);
    newNode->right = NULL;
    newNode->left = list->last;
    list->last = newNode;
    list->size++;
    return list->size;
}

Node* removeFromList(List *list, Node *node) {
    node->left->right = node->right;
    node->right->left = node->left;
    list->size--;
    return node;
}

Node *next(Node *node) {
    return node->right;
}

Node *first(List *list) {
    return list->first;
}

Node *last(List *list) {
    return list->last;
}

char *getValue(List *list, Node *node, int part) {
    if (part == 0) {
        return node->name;
    } else if (part == 1) {
        return node->telephoneNumber;
    }
}