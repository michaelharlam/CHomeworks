#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "list.h"

typedef struct Node {
    int data;
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
    assert(list != NULL);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node* createNode(int data) {
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insertAfter(List *list, Node *node, Node *newNode) {
    newNode->right = node->right;
    newNode->left = node;
    if (node->right != NULL) {
        node->right->left = newNode;
    }
    node->right = newNode;
    list->size++;
}

void insertBefore(List *list, Node *node, Node *newNode) {
    newNode->left = node->left;
    newNode->right = node;
    if (node->left != NULL) {
        node->left->right = newNode;
    }
    node->left = newNode;
    list->size++;
}

void insertInBeginning(List *list, Node *newNode) {
    newNode->right = list->first;
    newNode->left = NULL;

    if (list->first != NULL) {
        list->first->left = newNode;
    } else {
        list->last = newNode;
    }

    list->first = newNode;
    list->size++;
}

void append(List *list, Node *newNode) {
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

void appendCopy(List *list, Node *node) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = node->data;
    newNode->left = NULL;
    newNode->right = NULL;
    append(list, newNode);
}

void removeFromList(List *list, Node *node) {
    if (node->left != NULL) {
        node->left->right = node->right;
    } else {
        list->first = node->right;
    }
    if (node->right != NULL) {
        node->right->left = node->left;
    } else {
        list->last = node->left;
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

int getValue(Node *node) {
    return node->data;
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