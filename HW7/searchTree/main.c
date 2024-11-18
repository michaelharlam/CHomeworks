#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dictionary(void) {
    printf("Вас приветствует словарь!\n\n");
    printf("Программа поддерживает следующие команды:\n0 - выйти\n1 - добавить значение в словарь;\n2 - проверить наличие ключа в словаре;\n");
    printf("3 - получить значение по ключу;\n4 - удалить ключ и значение по ключу.\n\n");
    printf("Введите команду: ");

    int command;
    scanf("%d", &command);

    Tree *map = createTree();
    while (command != 0) {
        if (command == 0) {
            break;
        } else if (command == 1) {
            printf("Введите ключ: ");
            int key;
            scanf("%d", &key);

            printf("Введите значение: ");
            char *value = malloc(sizeof(char) * 100);
            scanf("%s", value);

            append(map, key, value);
            printf("Ключ и значение добавлены в словарь.\n");
        } else if (command == 2) {
            printf("Введите ключ: ");
            int key;
            scanf("%d", &key);

            if (isAvailableKey(map, key)) {
                printf("Значение по такому ключу содержится в словаре.\n");
            } else {
                printf("Значение по такому ключу не содержится в словаре.\n");
            }
        } else if (command == 3) {
            printf("Введите ключ: ");
            int key;
            scanf("%d", &key);

            char *result = getValue(map, key);
            if (result == NULL) {
                printf("Такого ключа нет в словаре.\n");
            } else {
                printf("%s\n", result);
            }
        } else if (command == 4) {
            printf("Введите ключ: ");
            int key;
            scanf("%d", &key);

            bool availability = deleteKey(map, key);
            if (availability) {
                printf("Ключ и значение удалены.\n");
            } else {
                printf("Такого ключа нет в словаре.\n");
            }
        } else {
            printf("Введен неверный номер команды. Попробуйте снова.\n");
        }
        printf("Введите команду: ");
        scanf("%d", &command);
    }

    deleteTree(map);
}

bool testOfAppendAndAvailability(void) {
    Tree *map = createTree();
    append(map, 100, "aaa");
    append(map, 50, "bbb");
    append(map, 150, "ccc");
    append(map, 25, "ddd");
    append(map, 75, "eee");
    append(map, 125, "fff");
    append(map, 175, "ggg");

    bool availability = isAvailableKey(map, 100) && isAvailableKey(map, 50) && isAvailableKey(map, 175);
    bool absenceOfAvailability = isAvailableKey(map, 15) && isAvailableKey(map, 390);

    deleteTree(map);
    return availability && !absenceOfAvailability;
}

bool testOfAppendAndDelete(void) {
    Tree *map = createTree();
    append(map, 100, "aaa");
    append(map, 50, "bbb");
    append(map, 150, "ccc");
    append(map, 25, "ddd");
    append(map, 75, "eee");
    append(map, 125, "fff");
    append(map, 175, "ggg");

    deleteKey(map, 75);
    bool availabilityAfterDeleteOfNodeWithoutChildren = isAvailableKey(map, 75);

    deleteKey(map, 150);
    bool availabilityAfterDeleteOfNodeWithOneChild = isAvailableKey(map, 150);

    deleteKey(map, 100);
    bool availabilityAfterDeleteOfRoot = isAvailableKey(map, 100);

    bool deleteOfAbsenceNode = deleteKey(map, 3);

    deleteTree(map);
    return !availabilityAfterDeleteOfNodeWithoutChildren && !availabilityAfterDeleteOfNodeWithOneChild && !availabilityAfterDeleteOfRoot && !deleteOfAbsenceNode;
}

bool testOfGettingValue(void) {
    Tree *map = createTree();
    append(map, 100, "aaa");
    append(map, 50, "bbb");
    append(map, 150, "ccc");

    char *valueWithKey100 = getValue(map, 100);
    char *valueWithKey50 = getValue(map, 50);
    char *valueWithKey150 = getValue(map, 150);

    bool equalityOfValueWithKey100 = strcmp(valueWithKey100, "aaa") == 0;
    bool equalityOfValueWithKey50 = strcmp(valueWithKey50, "bbb") == 0;
    bool equalityOfValueWithKey150 = strcmp(valueWithKey150, "ccc") == 0;

    deleteTree(map);
    return equalityOfValueWithKey50 && equalityOfValueWithKey150 && equalityOfValueWithKey100;
}

bool testCollector(void) {
    bool result = testOfAppendAndAvailability() && testOfAppendAndDelete() && testOfGettingValue();
    return result;
}

int main(void) {
    if (!testCollector()) {
        return 1;
    }

    dictionary();
    return 0;
}
