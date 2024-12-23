#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#define SIZE_OF_LIST 100

typedef struct Node {
    char *name;
    char *telephoneNumber;
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

Node* createNode(char *name, char *telephoneNumber) {
    Node *node = malloc(sizeof(Node));
    node->name = malloc(SIZE_OF_LIST * sizeof(char));
    if (name == NULL) {
        return NULL;
    }
    node->telephoneNumber = malloc(SIZE_OF_LIST * sizeof(char));
    if (telephoneNumber == NULL) {
        return NULL;
    }
    strcpy(node->telephoneNumber, telephoneNumber);
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void append(List *list, Node *node) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return;
    }
    newNode->telephoneNumber = node->telephoneNumber;
    newNode->name = node->name;
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

char *getValue(Node *node, int part) {
    if (part == 0) {
        return node->name;
    }
    if (part == 1) {
        return node->telephoneNumber;
    }
}

void freeList(List *list) {
    Node *node = list->first;
    while (node != NULL) {
        Node *next = node->right;
        free(node);
        node = next;
    }
    free(list);
}

int getSize(List *list) {
    return list->size;
}