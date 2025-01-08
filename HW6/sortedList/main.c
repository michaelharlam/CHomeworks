#include <stdio.h>
#include <stdbool.h>
#include "list.h"

void sortedListProgram(void) {
    printf("Вас приветствует сортированный список!\n\nВот список команд для программы:\n");
    printf("0 – выйти;\n1 – добавить значение в сортированный список;\n2 – удалить значение из списка;\n3 – распечатать список.\n\n");
    printf("Введите команду: ");
    int command;
    scanf("%d", &command);
    List *list = initList();
    while (command != 0) {
        int data;
        if (command == 0) {
            break;
        } else if (command == 1) {
            printf("Введите значение: ");
            scanf("%d", &data);
            if ((getSize(list) == 0)) {
                append(list, createNode(data));
            } else if (data <= getValue(first(list))) {
                insertInBeginning(list, createNode(data));
            } else if ((data >= getValue(last(list)))) {
                append(list, createNode(data));
            } else {
                for (Node* element = first(list); element != NULL; element = next(element)) {
                    if (getValue(element) < data <= getValue(next(element))) {
                        insertAfter(list, element, createNode(data));
                    }
                }
            }
        } else if (command == 2) {
            printf("Введите значение: ");
            scanf("%d", &data);
            bool presenceOfValue = false;
            for (Node* element = first(list); element != NULL; element = next(element)) {
                if (getValue(element) == data) {
                    removeFromList(list, element);
                    presenceOfValue = true;
                }
            }
            if (!presenceOfValue) {
                printf("Такого элемента нет в списке.\n");
            }

        } else if (command == 3) {
            int counter = 0;
            for (Node* element = first(list); element != NULL; element = next(element)) {
                printf("%d: %d\n", counter, getValue(element));
                ++counter;
            }
            if (getSize(list) == 0) {
                printf("Список пуст.\n");
            }
        } else {
            printf("Неправильный формат ввода.\n");
        }

        printf("Введите команду: ");
        scanf("%d", &command);
    }
}


bool appendListTest(void) {
    List *list = initList();
    append(list, createNode(1));
    append(list, createNode(2));
    append(list, createNode(3));
    int counter = 0;
    bool result = true;
    for (Node* element = first(list); element != NULL; element = next(element)) {
        ++counter;
        if (getValue(element) != counter) {
            result = false;
        }
    }
    return result;
}

bool insertInBeginningListTest(void) {
    List *list = initList();
    append(list, createNode(1));
    append(list, createNode(2));
    append(list, createNode(3));
    insertInBeginning(list, createNode(4));
    if (getValue(first(list)) == 4) {
        return true;
    }
    printf("insertInBeginningListTest is failed.");
    return false;
}

bool insertAfterListTest(void) {
    List *list = initList();
    append(list, createNode(1));
    append(list, createNode(2));
    append(list, createNode(3));
    insertAfter(list, first(list), createNode(4));
    if (getValue(next(first(list))) == 4) {
        return true;
    }
    printf("insertAfterListTest is failed.");
    return false;
}

bool removeFromListTest(void) {
    List *list = initList();
    append(list, createNode(1));
    append(list, createNode(2));
    append(list, createNode(3));
    removeFromList(list, last(list));
    if (getValue(last(list)) == 2) {
        return true;
    }
    printf("removeFromListTest is failed.");
    return false;
}

bool testCollector(void) {
    bool firstTest = appendListTest();
    bool secondTest = insertInBeginningListTest();
    bool thirdTest = insertAfterListTest();
    bool fourthTest = removeFromListTest();
    return firstTest && secondTest && thirdTest && fourthTest;
}

int main(void) {
    if (!testCollector()) {
        return 1;
    }
    sortedListProgram();
    return 0;
}