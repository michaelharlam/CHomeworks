#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "list.h"

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
    assert(list != NULL);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node* createNode(char *name, char *telephoneNumber) {
    Node *node = malloc(sizeof(Node));
    node->name = calloc(100, sizeof(char));
    if (name == NULL) {
        printf("wtf ");
    }
    node->telephoneNumber = calloc(100, sizeof(char));
    if (telephoneNumber == NULL) {
        printf("wtf2 ");
    }
    strcpy(node->telephoneNumber, telephoneNumber);
    strcpy(node->name, name);
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*void insertAfter(List *list, Node *node, Node *newNode) {
    newNode->right = node->right;
    newNode->left = node;
    node->right = newNode;
    list->size++;
}*/

void insertAfter(List *list, Node *node, Node *newNode) {
    newNode->right = node->right;
    newNode->left = node;
    if (node->right != NULL) {
        node->right->left = newNode; // Добавляем ссылку на новый узел для правого узла
    }
    node->right = newNode;
    list->size++;
}

/*void insertBefore(List *list, Node *node, Node *newNode) {
    newNode->left = node->left;
    newNode->right = node;
    node->left = newNode;
    list->size++;
}*/

void insertBefore(List *list, Node *node, Node *newNode) {
    newNode->left = node->left;
    newNode->right = node;
    if (node->left != NULL) {
        node->left->right = newNode; // Добавляем ссылку на новый узел для левого узла
    }
    node->left = newNode;
    list->size++;
}


/*void insertInBeginning(List *list, Node *newNode) {
    newNode->right = list->first;
    newNode->left = NULL;
    list->first = newNode;
    list->size++;
}*/

void insertInBeginning(List *list, Node *newNode) {
    newNode->right = list->first;
    newNode->left = NULL;

    if (list->first != NULL) { // Если уже есть первый узел
        list->first->left = newNode;
    } else {
        list->last = newNode; // Если список пуст, новый узел становится последним
    }

    list->first = newNode;
    list->size++;
}


/*void append(List *list, Node *newNode) {
    newNode->right = NULL;
    newNode->left = list->last;
    if (list->last != NULL) {
        list->last->right = newNode;
    }
    list->last = newNode;
    list->size++;
}*/

void append(List *list, Node *newNode) {
    newNode->right = NULL;
    newNode->left = list->last;
    if (list->last != NULL) {
        list->last->right = newNode;
    } else { // Если список пуст, новый узел становится первым
        list->first = newNode;
    }
    list->last = newNode;
    list->size++;
}

void appendCopy(List *list, Node *node) {
    Node *newNode = malloc(sizeof(Node));
    newNode->telephoneNumber = node->telephoneNumber;
    newNode->name = node->name;
    newNode->left = NULL;
    newNode->right = NULL;
    append(list, newNode);
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
    } else if (part == 1) {
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
}

int getSize(List *list) {
    return list->size;
}