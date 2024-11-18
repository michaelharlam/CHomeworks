#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binarySearchTree.h"

typedef struct Value {
    char *value;
} Value;

typedef struct Key {
    int key;
} Key;

typedef struct Node {
    Key key;
    Value value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Key createKey(int key) {
    Key newKey;
    newKey.key = key;
    return newKey;
}

Value* createValue(char *value) {
    Value *newValue = malloc(sizeof(Value));
    newValue->value = calloc(100, sizeof(char));
    strcpy(newValue->value, value);
    return newValue;
}

Node *createNode(int key, char *value) {
    Key newKey = createKey(key);
    Value *newValue = createValue(value);
    Node *newNode = malloc(sizeof(Node));
    newNode->key = newKey;
    newNode->value = *newValue;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Tree *createTree() {
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

int getKey(Node *node) {
    return node->key.key;
}

void append(Tree *tree, int key, char *value) {
    Node *node = createNode(key, value);

    if (tree->root == NULL) {
        tree->root = node;
        return;
    }

    Node *root = tree->root;
    Node *father = tree->root;

    while (root != NULL) {
        if (getKey(root) == key) {
            root->value.value = value;
            return;
        } else if (getKey(root) < key) {
            father = root;
            root = root->rightChild;
        } else {
            father = root;
            root = root->leftChild;
        }
    }

    if (getKey(father) > key) {
        father->leftChild = node;
    } else {
        father->rightChild = node;
    }
}

char *getValue(Tree *tree, int key) {
    Node *root = tree->root;
    while (root != NULL) {
        if (getKey(root) == key) {
            return root->value.value;
        }
        if (getKey(root) < key) {
            root = root->rightChild;
        } else if (getKey(root) > key) {
            root = root->leftChild;
        }
    }
    return NULL;
}

bool isAvailableKey(Tree *tree, int key) {
    Node *root = tree->root;
    while (root != NULL) {
        if (getKey(root) == key) {
            return true;
        } else if (getKey(root) < key) {
            root = root->rightChild;
        } else if (getKey(root) > key) {
            root = root->leftChild;
        }
    }
    return false;
}

bool deleteKey(Tree *tree, int key) {
    Node *root = tree->root;
    Node *father = tree->root;

    if (root == NULL) {
        return false;
    }

    while (getKey(root) != key) {
        father = root;
        if (getKey(root) < key) {
            root = root->rightChild;
        } else if (getKey(root) > key) {
            root = root->leftChild;
        }
        if (root == NULL) {
            return false;
        }
    }

    if ((root->leftChild == NULL) && (root->rightChild == NULL)) {
        if (getKey(root) > getKey(father)) {
            father->rightChild = NULL;
        } else {
            father->leftChild = NULL;
        }
    } else if ((root->leftChild != NULL) && (root->rightChild == NULL)) {
        if (getKey(root) > getKey(father)) {
            father->rightChild = root->leftChild;
        } else {
            father->leftChild = root->leftChild;
        }
    } else if ((root->leftChild == NULL) && (root->rightChild != NULL)) {
        if (getKey(root) > getKey(father)) {
            father->rightChild = root->rightChild;
        } else {
            father->leftChild = root->rightChild;
        }
    } else {
        Node *rootRightChild = root->rightChild;
        Node *rootRightChildFather = root;
        while (rootRightChild->leftChild != NULL) {
            rootRightChildFather = rootRightChild;
            rootRightChild = rootRightChild->leftChild;
        }
        rootRightChild->rightChild = root->rightChild == rootRightChild ? NULL : root->rightChild;
        rootRightChild->leftChild = root->leftChild;
        rootRightChildFather->leftChild = NULL;
        if (getKey(father) > getKey(root)) {
            father->leftChild = rootRightChild;
        } else if (getKey(father) < getKey(root)) {
            father->rightChild = rootRightChild;
        } else {
            tree->root = rootRightChild;
        }
    }

    free(root);
    return true;
}

void deleteTreeByRoot(Node* father, Node *root) {
    if (root == NULL) {
        return;
    }

    deleteTreeByRoot(root, root->leftChild);
    deleteTreeByRoot(root, root->rightChild);

    if (father->leftChild == root) {
        father->leftChild = NULL;
    } else if (father->rightChild == root) {
        father->rightChild = NULL;
    }
    free(root);
}

void deleteTree(Tree *tree) {
    Node *root = tree->root;
    Node *father = tree->root;

    deleteTreeByRoot(father, root);
}