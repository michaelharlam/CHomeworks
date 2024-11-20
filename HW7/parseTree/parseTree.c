#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "parseTree.h"


typedef struct Node {
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Node *createNode(char *value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = strdup(value);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Tree *createTree() {
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

Node* buildTree(FILE *file) {
    char symbol = getc(file);
    char token[100] = {'\0'};

    while (symbol == ' ') {
        symbol = getc(file);
    };

    if (symbol == '(') {
        token[0] = getc(file);
        Node *newNode = createNode(token);

        newNode->leftChild = buildTree(file);
        newNode->rightChild = buildTree(file);

        symbol = getc(file);
        return newNode;
    } else {
        int counter = 0;
        while ((symbol != ' ') && (symbol != '(') && (symbol != ')')) {
            token[counter++] = symbol;
            symbol = getc(file);
        }
        ungetc(symbol, file);
        Node *newNode = createNode(token);
        return newNode;
    }
}