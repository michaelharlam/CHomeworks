#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "list.h"

List* fromTextFileToList(char *fileName) {
    FILE *filePointer = fopen(fileName, "r");
    if (filePointer == NULL) {
        printf("File could not be opened\n");
        return NULL;
    }

    List *list = initList();
    char name[100], telephoneNumber[100];
    while (fscanf(filePointer, "%s - %s", name, telephoneNumber) != EOF) {
        append(list, createNode(name, telephoneNumber));
    }
    fclose(filePointer);
    return list;
}

void printList(List* list) {
    if (list == NULL) {
        printf("empty ");
        return;
    }
    Node *node = first(list);
    while (node != NULL) {
        printf("%s - %s\n", getValue(node, 0), getValue(node, 1));
        node = next(node);
    }
}

List* mergeSort(List *list, int part) {
    if (getSize(list) <= 1) {
        return list;
    }

    List* leftList = initList();
    List* rightList = initList();
    int middle = getSize(list) / 2;

    Node* current = first(list);
    int counter = 0;
    while (current != NULL && counter < middle) {
        Node* nextNode = next(current);
        append(leftList, current);
        current = nextNode;
        counter++;
    }

    while (current != NULL) {
        Node* nextNode = next(current);
        append(rightList, current);
        current = nextNode;
    }

    leftList = mergeSort(leftList, part);
    rightList = mergeSort(rightList, part);

    Node* leftNode = first(leftList);
    Node* rightNode = first(rightList);

    freeList(list);
    list = initList();

    while (leftNode != NULL && rightNode != NULL) {
        char* leftValue = getValue(leftNode, part);
        char* rightValue = getValue(rightNode, part);

        if (strcmp(leftValue, rightValue) <= 0) {
            Node* nextLeft = next(leftNode);
            append(list, leftNode);
            leftNode = nextLeft;
        } else {
            Node* nextRight = next(rightNode);
            append(list, rightNode);
            rightNode = nextRight;
        }
    }

    while (leftNode != NULL) {
        Node* nextLeft = next(leftNode);
        append(list,  leftNode);
        leftNode = nextLeft;
    }

    while (rightNode != NULL) {
        Node* nextRight = next(rightNode);
        append(list, rightNode);
        rightNode = nextRight;
    }

    freeList(leftList);
    freeList(rightList);

    return list;
}

bool mergeSortTestForNames(void) {
    List *list = initList();
    append(list, createNode("C", "2"));
    append(list, createNode("A", "4"));
    append(list, createNode("B", "1"));
    append(list, createNode("D", "3"));
    list = mergeSort(list, 0);
    Node *node = first(list);
    bool firstPosition = strcmp(getValue(node, 0), "A") == 0;
    node = next(node);
    bool secondPosition = strcmp(getValue(node, 0), "B") == 0;
    node = next(node);
    bool thirdPosition = strcmp(getValue(node, 0), "C") == 0;
    node = next(node);
    bool fourthPosition = strcmp(getValue(node, 0), "D") == 0;
    freeList(list);
    return firstPosition && secondPosition && thirdPosition && fourthPosition;
}

bool mergeSortTestForTelephoneNumbers(void) {
    List *list = initList();
    append(list, createNode("C", "2"));
    append(list, createNode("A", "4"));
    append(list, createNode("B", "1"));
    append(list, createNode("D", "3"));
    list = mergeSort(list, 1);
    Node *node = first(list);
    bool firstPosition = strcmp(getValue(node, 1), "1") == 0;
    node = next(node);
    bool secondPosition = strcmp(getValue(node, 1), "2") == 0;
    node = next(node);
    bool thirdPosition = strcmp(getValue(node, 1), "3") == 0;
    node = next(node);
    bool fourthPosition = strcmp(getValue(node, 1), "4") == 0;
    freeList(list);
    return firstPosition && secondPosition && thirdPosition && fourthPosition;
}

bool tests(void) {
    bool mergeSortTestForNamesValue = mergeSortTestForNames();
    bool mergeSortTestForTelephoneNumbersValue = mergeSortTestForTelephoneNumbers();
    if (!mergeSortTestForNamesValue) {
        printf("Test with names is failed\n");
    } else if (!mergeSortTestForTelephoneNumbersValue) {
        printf("Test with telephone numbers is failed\n");
    }
    return mergeSortTestForNamesValue && mergeSortTestForTelephoneNumbersValue;
}

int main() {
    if (!tests()) {
        return 1;
    }

    char fileName[14] = "database.txt\0";
    List *list = fromTextFileToList(fileName);
    if (list == NULL) {
        return 1;
    }

    printf("Если вы хотите отсортировать список по имени, введите 0.\n");
    printf("Если вы хотите отсортировать список по номеру телефона, введите 1.\n");

    int part;
    scanf("%d", &part);

    if (part != 1 && part != 0) {
        printf("Вы ввели неверное число.");
        return 1;
    }

    list = mergeSort(list, part);
    printList(list);
    freeList(list);

    return 0;
}