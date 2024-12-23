#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "parseTree.h"
#include "expressionParser.h"


typedef struct Node {
    char *value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node *createNode(char *value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode->value = strdup(value);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
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

void printTreeRecursive(Node *root) {
    Node *currentNode = root;
    if (isOperation(currentNode->value[0])) {
        printf("( %c ", currentNode->value[0]);

        printTreeRecursive(currentNode->leftChild);
        printTreeRecursive(currentNode->rightChild);

        printf(") ");
    } else if (!isOperation(currentNode->value[0])) {
        printf("%s ", currentNode->value);
    }
}

void printTree(Node *root) {
    printTreeRecursive(root);
    printf("\n");
}

int treeCount(Node *root) {
    Node *currentNode = root;
    if (isOperation(currentNode->value[0])) {
        int operand1 = treeCount(currentNode->leftChild);
        int operand2 = treeCount(currentNode->rightChild);
        return operationCalculator(currentNode->value[0], operand1, operand2);
    }
    return (int)strtol(currentNode->value, NULL, 10);
}

void deleteTree(Node* father, Node *root) {
    if (root == NULL) {
        return;
    }

    deleteTree(root, root->leftChild);
    deleteTree(root, root->rightChild);

    if (father->leftChild == root) {
        father->leftChild = NULL;
    } else if (father->rightChild == root) {
        father->rightChild = NULL;
    }
    free(root);
}