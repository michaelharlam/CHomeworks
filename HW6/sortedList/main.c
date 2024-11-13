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


int main(void) {
    sortedListProgram();
}