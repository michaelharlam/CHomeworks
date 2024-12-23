#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "treeAVL.h"

typedef struct Node {
    const char *key;
    const char *value;
    int height;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Node *createNode(const char *key, const char *value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->height = 1;
    return newNode;
}

Tree *createTree() {
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

int getHeight(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getHeightOfTree(Tree *tree) {
    return getHeight(tree->root);
}

int maximum(const int number1, const int number2) {
    return number1 > number2 ? number1 : number2;
}

Node *leftRotate(Node **node) {
    Node *rightChild = (*node)->rightChild;
    (*node)->rightChild = rightChild->leftChild;
    (*node)->height = maximum(getHeight((*node)->leftChild), getHeight((*node)->rightChild)) + 1;
    rightChild->leftChild = (*node);
    rightChild->height = maximum(getHeight(rightChild->leftChild), getHeight(rightChild->rightChild)) + 1;

    return rightChild;
}

Node *rightRotate(Node **node) {
    Node *leftChild = (*node)->leftChild;
    (*node)->leftChild = leftChild->rightChild;
    (*node)->height = maximum(getHeight((*node)->leftChild), getHeight((*node)->rightChild)) + 1;
    leftChild->rightChild = (*node);
    leftChild->height = maximum(getHeight(leftChild->leftChild), getHeight(leftChild->rightChild)) + 1;

    return leftChild;
}

Node *leftRightRotate(Node **node) {
    Node *leftChild = leftRotate(&((*node)->leftChild));
    (*node)->leftChild = leftChild;
    Node *newNode = rightRotate(node);

    return newNode;
}

Node *rightLeftRotate(Node **node) {
    Node *rightChild = rightRotate(&((*node)->leftChild));
    (*node)->rightChild = rightChild;
    Node *newNode = leftRotate(node);

    return newNode;
}

int balanceFactor(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

Node *balanceCheck(Node **node) {
    int rootBalance = balanceFactor(*node);
    Node *root = *node;
    if ((rootBalance == 2) && (balanceFactor((*node)->rightChild) >= 0)) {
        root = leftRotate(node);
    } else if((rootBalance == -2) && (balanceFactor((*node)->leftChild) <= 0)) {
        root = rightRotate(node);
    } else if ((rootBalance == -2) && (balanceFactor((*node)->leftChild) == 1)) {
        root = leftRightRotate(node);
    } else if ((rootBalance == 2) && (balanceFactor((*node)->rightChild) == -1)) {
        root = rightLeftRotate(node);
    }
    return root;
}

Node *appendRecursive(Node **node, Node *newNode) {
    if (*node == NULL) {
        *node = newNode;
        return *node;
    }

    Node *nextNode = NULL;
    if (strcmp((*node)->key, newNode->key) == 0) {
        (*node)->value = strdup(newNode->value);
        free(newNode);
        return *node;
    } else if (strcmp((*node)->key, newNode->key) > 0) {
        nextNode = appendRecursive(&((*node)->leftChild), newNode);
        if ((*node)->leftChild == NULL) {
            (*node)->leftChild = newNode;
        }
    } else {
        nextNode = appendRecursive(&((*node)->rightChild), newNode);
        if ((*node)->rightChild == NULL) {
            (*node)->rightChild = newNode;
        }
    }

    if((*node)->leftChild != NULL || (*node)->rightChild != NULL) {
        (*node)->height = nextNode->height + 1;
    }

    (*node) = balanceCheck(node);
    return *node;
}

void append(Tree *tree, const char *key, const char *value) {
    Node *newNode = createNode(key, value);;
    if (tree->root == NULL) {
        tree->root = newNode;
    } else {
        tree->root = appendRecursive(&(tree->root), newNode);
    }
}

const char *getValue(Tree *tree, const char *key) {
    Node *root = tree->root;
    while (root != NULL) {
        if (strcmp(root->key, key) == 0) {
            return root->value;
        }
        if (strcmp(root->key, key) < 0) {
            root = root->rightChild;
        } else if (strcmp(root->key, key) > 0) {
            root = root->leftChild;
        }
    }
    return NULL;
}

bool isAvailableKey(Tree *tree, const char *key) {
    Node *root = tree->root;
    while (root != NULL) {
        if (strcmp(root->key, key) == 0) {
            return true;
        } else if (strcmp(root->key, key) < 0) {
            root = root->rightChild;
        } else if (strcmp(root->key, key) > 0) {
            root = root->leftChild;
        }
    }
    return false;
}

void freeNode(Node **node) {
    Node* temp = *node;
    *node = NULL;
    free(temp);
}

Node *deleteNode(Node **father, Node **node, const char *key) {
    if (*node == NULL) {
        return NULL;
    }

    if (strcmp((*node)->key, key) == 0) {
        Node *result = NULL;
        if (((*node)->leftChild == NULL) && ((*node)->rightChild == NULL)) {
            if ((*father) == (*node)) {
                (*father) = NULL;
            } else if ((*father)->leftChild == *node) {
                (*father)->leftChild = NULL;
            } else if ((*father)->rightChild == *node) {
                (*father)->rightChild = NULL;
            }
            freeNode(node);
        } else if ((*node)->leftChild == NULL) {
            if ((*father) == (*node)) {
                (*father) = (*node)->rightChild;
            } else if ((*father)->leftChild == *node) {
                (*father)->leftChild = (*node)->rightChild;
            } else if ((*father)->rightChild == *node) {
                (*father)->rightChild = (*node)->rightChild;
            }
            freeNode(node);
        } else if ((*node)->rightChild == NULL) {
            if ((*father) == (*node)) {
                (*father) = (*node)->leftChild;
            } else if ((*father)->leftChild == *node) {
                (*father)->leftChild = (*node)->leftChild;
            } else if ((*father)->rightChild == *node) {
                (*father)->rightChild = (*node)->leftChild;
            }
            freeNode(node);
        } else {
            Node *nodeRightChildFather = (*node)->rightChild;
            Node *nodeRightChild = (*node)->rightChild;
            while ((nodeRightChild->leftChild != NULL) ) {
                nodeRightChildFather = nodeRightChild;
                nodeRightChild = nodeRightChild->leftChild;
            }
            if (nodeRightChildFather != nodeRightChild) {
                nodeRightChildFather->leftChild = NULL;
            }
            nodeRightChild->leftChild = (*node)->leftChild;
            nodeRightChild->rightChild = (*node)->rightChild != nodeRightChild ? (*node)->rightChild: NULL;
            if ((*father) == (*node)) {
                freeNode(node);
                (*father) = nodeRightChild;
            } else if ((*father)->leftChild == *node) {
                freeNode(node);
                (*father)->leftChild = nodeRightChild;
            } else if ((*father)->rightChild == *node) {
                freeNode(node);
                (*father)->rightChild = nodeRightChild;
            }
            result = nodeRightChild;
        }
        return balanceCheck(&result);
    } else {
        Node *leftBranchNode = deleteNode(node, &((*node)->leftChild), key);
        Node *rightBranchNode = deleteNode(node, &((*node)->rightChild), key);
        if (leftBranchNode == NULL && rightBranchNode == NULL) {
            (*node)->height = 1;
        } else if ((leftBranchNode != NULL) && (rightBranchNode == NULL)) {
            (*node)->height = leftBranchNode->height + 1;
        } else if ((leftBranchNode == NULL) && (rightBranchNode != NULL)) {
            (*node)->height = rightBranchNode->height + 1;
        } else {
            (*node)->height = maximum(getHeight(leftBranchNode), getHeight(rightBranchNode)) + 1;
        }
        return balanceCheck(node);
    }
}

void deleteKey(Tree **tree, const char *key) {
    Node *root = (*tree)->root;
    Node *newRoot = deleteNode(&root, &root, key);
    (*tree)->root = newRoot;
    balanceCheck(&newRoot);
}

void deleteTreeByRoot(Node *father, Node *root) {
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
    freeNode(&root);
}

void deleteTree(Tree **tree) {
    Node *root = (*tree)->root;
    Node *father = (*tree)->root;

    deleteTreeByRoot(father, root);

    *tree = NULL;
}