#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "list.h"
#define SIZE_OF_LIST 100

typedef struct Node {
    const char *key;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct List {
    int size;
    Node *first;
    Node *last;
} List;

List* initList(void) {
    List *list = malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node* createNode(const char *key, const int value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->key = malloc(SIZE_OF_LIST *sizeof(const char));
    if (key == NULL) {
        free(node);
        return NULL;
    }
    node->value = value;
    node->key = strdup(key);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void append(List *list, const char *key, int value) {
    Node *newNode = createNode(key, value);
    if (newNode == NULL) {
        return;
    }
    newNode->right = NULL;
    newNode->left = list->last;
    if (list->last != NULL) {
        list->last->right = newNode;
    } else {
        list->first = newNode;
    }
    list->last = newNode;
    list->size++;
}

void removeFromList(List *list, Node *node) {
    if (node->left != NULL) {
        node->left->right = node->right;
    }
    if (node->right != NULL) {
        node->right->left = node->left;
    }
    list->size--;

    free(node);
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

void freeList(List *list) {
    Node *node = list->first;
    while (node != NULL) {
        Node *next = node->right;
        free(node);
        node = next;
    }
}

int getSize(List *list) {
    return list->size;
}

const char *getKey(Node *node) {
    return node->key;
}

int getValue(Node *node) {
    return node->value;
}

void changeValue(Node *node, int value) {
    node->value = value;
}