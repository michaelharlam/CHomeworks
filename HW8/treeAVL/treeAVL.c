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

Node *leftRotate(Node **node) {
    Node *rightChild = (*node)->rightChild;
    (*node)->rightChild = rightChild->leftChild;
    (*node)->height = rightChild->height;
    rightChild->leftChild = (*node);

    //rightChild->height;
    return rightChild;
}

Node *rightRotate(Node **node) {
    Node *leftChild = (*node)->leftChild;
    (*node)->leftChild = leftChild->rightChild;
    (*node)->height = leftChild->height;
    leftChild->rightChild = (*node);

    //leftChild->height;
    return leftChild;
}

Node *leftRightRotate(Node **node) {
    Node *leftChild = leftRotate(&((*node)->leftChild));
    (*node)->leftChild = leftChild;
    Node *newNode = rightRotate(&(*node));

    return newNode;
}

Node *rightLeftRotate(Node **node) {
    Node *rightChild = rightRotate(&((*node)->leftChild));
    (*node)->rightChild = rightChild;
    Node *newNode = leftRotate(&(*node));

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
    Node *root = NULL;
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

int appendRecursive(Node **node, Node *newNode) {
    if (*node == NULL) {
        *node = newNode;
        return (*node)->height;
    }

    int childHeight = 1;
    if (strcmp((*node)->key, newNode->key) == 0) {
        (*node)->value = strdup(newNode->value);
        free(newNode);
        return (*node)->height;
    } else if (strcmp((*node)->key, newNode->key) > 0) {
        childHeight = appendRecursive(&((*node)->leftChild), newNode);
        if ((*node)->leftChild == NULL) {
            (*node)->leftChild = newNode;
        }
    } else {
        childHeight = appendRecursive(&((*node)->rightChild), newNode);
        if ((*node)->rightChild == NULL) {
            (*node)->rightChild = newNode;
        }
    }

    if((*node)->leftChild != NULL || (*node)->rightChild != NULL) {
        (*node)->height = childHeight + 1;
    }
    return (*node)->height;
}

void append(Tree *tree, const char *key, const char *value) {
    Node *newNode = createNode(key, value);
    Node *node = tree->root;
    if (node == NULL) {
        tree->root = newNode;
    } else {
        appendRecursive(&node, newNode);
    }
    Node *newRoot = balanceCheck(&(tree->root));
    if (newRoot == NULL) {
        return;
    }
    tree->root = newRoot;
}

char *getValue(Tree *tree, const char *key) {
    Node *root = tree->root;
    while (root != NULL) {
        if (strcmp(root->key, key) < 0) {
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

bool deleteNode(Node *father, Node *node, const char *key) {
    if (node == NULL) {
        return false;
    }

    if (strcmp(node->key, key) == 0) {
        if ((node->leftChild == NULL) && (node->rightChild == NULL)) {
            if (father->leftChild == node) {
                father->leftChild = NULL;
            } else if (father->rightChild == node) {
                father->rightChild = NULL;
            }
        } else if (node->leftChild == NULL) {
            if (father->leftChild == node) {
                father->leftChild = node->rightChild;
            } else if (father->rightChild == node) {
                father->rightChild = node->rightChild;
            }
        } else if (node->rightChild == NULL) {
            if (father->leftChild == node) {
                father->leftChild = node->leftChild;
            } else if (father->rightChild == node) {
                father->rightChild = node->leftChild;
            }
        } else {
            Node *nodeRightChildFather = node->rightChild;
            Node *nodeRightChild = node->rightChild;
            while ((nodeRightChild->leftChild != NULL) ) {
                nodeRightChildFather = nodeRightChild;
                nodeRightChild = nodeRightChild->leftChild;
            }
            if (nodeRightChildFather != nodeRightChild) {
                nodeRightChildFather->leftChild = nodeRightChild->leftChild;
            }
            nodeRightChild->leftChild = node->leftChild;
            nodeRightChild->rightChild = node->rightChild;
            if (father->leftChild == node) {
                father->leftChild = nodeRightChild;
            } else if (father->rightChild == node) {
                father->rightChild = nodeRightChild;
            }
        }
        free(node);
        return true;
    } else {
        bool isKeyInLeftBranch = deleteNode(node, node->leftChild, key);
        bool isKeyInRightBranch = deleteNode(node, node->rightChild, key);
        if (isKeyInLeftBranch || isKeyInRightBranch) {
            node->height--;
            return true;
        } else {
            return false;
        }
    }
}

bool deleteKey(Tree **tree, const char *key) {
    Node *root = (*tree)->root;
    return deleteNode(root, root, key);
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

void deleteTree(Tree **tree) {
    Node *root = (*tree)->root;
    Node *father = (*tree)->root;

    deleteTreeByRoot(father, root);

    *tree = NULL;
}