#include <stdio.h>
#include <stdbool.h>
#include "parseTree.h"

void parseTreeInWork(void) {
    printf("Дерево разбора арифметического выражения.\n\n");
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }

    Node* treeRoot = buildTree(file);
    fclose(file);
    printf("Дерево построено.\n");

    printf("Дерево в распечатанном виде: ");
    printTree(treeRoot);

    printf("Результат вычисления выражения: %d", treeCount(treeRoot));
    deleteTree(treeRoot);
}

bool simpleCountingTest(void) {
    FILE *file = fopen("test1.txt", "w");
    if (file == NULL) {
        printf("Error opening file for write in test 1.");
        return false;
    }

    fputs("(* (+ 1 1) 2)", file);
    fclose(file);

    file = fopen("test1.txt", "r");
    if (file == NULL) {
        printf("Error opening file for read in test 1.");
    }

    Node *treeRoot = buildTree(file);
    fclose(file);
    remove("test1.txt");

    int result = treeCount(treeRoot);
    deleteTree(treeRoot);

    if (result != 4) {
        printf("Simple counting test is failed.");
        return false;
    }
    return true;
}

bool countingTestWithLongStrings(void) {
    FILE *file = fopen("test2.txt", "w");
    if (file == NULL) {
        printf("Error opening file for write in test 2.");
        return false;
    }

    fputs("(* (+ 100 1345) 289)", file);
    fclose(file);

    file = fopen("test2.txt", "r");
    if (file == NULL) {
        printf("Error opening file for read in test 2.");
    }

    Node *treeRoot = buildTree(file);
    fclose(file);
    remove("test2.txt");

    int result = treeCount(treeRoot);
    deleteTree(treeRoot);

    if (result != 417605) {
        printf("Counting test with long strings is failed.");
        return false;
    }
    return true;
}

bool countingTestWithAllOfOperations(void) {
    FILE *file = fopen("test3.txt", "w");
    if (file == NULL) {
        printf("Error opening file for write in test 3.");
        return false;
    }

    fputs("(* (+ (- 3 1) (* 4 5)) (/ 15 (+ 2 3)))", file);
    fclose(file);

    file = fopen("test3.txt", "r");
    if (file == NULL) {
        printf("Error opening file for read in test 3.");
    }

    Node *treeRoot = buildTree(file);
    fclose(file);
    remove("test3.txt");

    int result = treeCount(treeRoot);
    deleteTree(treeRoot);

    if (result != 66) {
        printf("Counting test with all of operators is failed.");
        return false;
    }
    return true;
}

bool runTests(void) {
    return simpleCountingTest() && countingTestWithLongStrings() && countingTestWithAllOfOperations();
}

int main(void) {
    if (!runTests()) {
        return 1;
    }

    parseTreeInWork();
    return 0;
}