#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct List {
    Node *last;
    int size;
} List;

void append(List *list, int value) {
    Node *node = malloc(sizeof(Node));

    node->value = value;
    
    if (list->last == NULL) {
        list->last = node;
        node->left = node;
        node->right = node;
        list->size++;
        return;
    }

    Node *previous = list->last;
    Node *next = previous->right;
    previous->right = node;
    next->left = node;
    node->left = previous;
    node->right = next;
    list->last = node;
    list->size++;
}

List* initList(void) {
    List *list = malloc(sizeof(List));
    assert(list != NULL);
    list->last = NULL;
    list->size = 0;
    return list;
}

void removeFromList(List *list, Node *node) {
    node->left->right = node->right;
    node->right->left = node->left;
    if (list->last == node) {
        list->last = node->right;
    }
    list->size--;
    free(node);
}

Node *next(Node *node) {
    return node->right;
}

Node *last(List *list) {
    return list->last;
}

int getValue(Node *node) {
    return node->value;
}

void freeList(List *list) {
    Node *node = list->last;
    while (node != list->last) {
        Node *next = node->right;
        free(node);
        node = next;
    }
}

int getSize(List *list) {
    return list->size;
}