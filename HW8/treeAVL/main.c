#include <stdio.h>
#include "treeAVL.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dictionary(void) {
    printf("Вас приветствует словарь!\n\n");
    printf("Программа поддерживает следующие команды:\n0 - выйти\n1 - добавить значение в словарь;\n2 - проверить наличие ключа в словаре;\n");
    printf("3 - получить значение по ключу;\n4 - удалить ключ и значение по ключу.\n\n");
    printf("Введите команду: ");

    int command = 0;
    scanf("%d", &command);

    Tree *map = createTree();
    char *key = malloc(sizeof(char) * 100);
    while (command != 0) {
        if (command == 0) {
            break;
        } else if (command == 1) {
            printf("Введите ключ: ");
            scanf("%s", key);

            printf("Введите значение: ");
            char *value = malloc(sizeof(char) * 100);
            scanf("%s", value);

            append(map, key, value);
            printf("Ключ и значение добавлены в словарь.\n");
        } else if (command == 2) {
            printf("Введите ключ: ");
            scanf("%s", key);

            if (isAvailableKey(map, key)) {
                printf("Значение по такому ключу содержится в словаре.\n");
            } else {
                printf("Значение по такому ключу не содержится в словаре.\n");
            }
        } else if (command == 3) {
            printf("Введите ключ: ");
            scanf("%s", key);

            const char *result = getValue(map, key);
            if (result == NULL) {
                printf("Такого ключа нет в словаре.\n");
            } else {
                printf("%s\n", result);
            }
        } else if (command == 4) {
            printf("Введите ключ: ");
            scanf("%s", key);

            deleteKey(&map, key);
            bool isAvailable = isAvailableKey(map, key);
            if (isAvailable) {
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

    deleteTree(&map);
}

bool testOfAppendAndAvailability(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");
    append(map, "025", "ddd");
    append(map, "075", "eee");
    append(map, "125", "fff");
    append(map, "175", "ggg");

    bool availability = isAvailableKey(map, "100") && isAvailableKey(map, "050") && isAvailableKey(map, "175");
    bool absenceOfAvailability = isAvailableKey(map, "015") && isAvailableKey(map, "390");

    deleteTree(&map);
    return availability && !absenceOfAvailability;
}

bool testOfAppendAndDelete(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");
    append(map, "025", "ddd");
    append(map, "075", "eee");
    append(map, "125", "fff");
    append(map, "175", "ggg");

    deleteKey(&map, "075");
    bool availabilityAfterDeleteOfNodeWithoutChildren = isAvailableKey(map, "075");

    deleteKey(&map, "150");
    bool availabilityAfterDeleteOfNodeWithOneChild = isAvailableKey(map, "150");

    deleteKey(&map, "100");
    bool availabilityAfterDeleteOfRoot = isAvailableKey(map, "100");

    deleteKey(&map, "003");

    deleteTree(&map);
    return !availabilityAfterDeleteOfNodeWithoutChildren && !availabilityAfterDeleteOfNodeWithOneChild && !availabilityAfterDeleteOfRoot;
}

bool testOfGettingValue(void) {
    Tree *map = createTree();
    append(map, "100", "aaa");
    append(map, "050", "bbb");
    append(map, "150", "ccc");

    const char *valueWithKey100 = getValue(map, "100");
    const char *valueWithKey50 = getValue(map, "050");
    const char *valueWithKey150 = getValue(map, "150");

    bool equalityOfValueWithKey100 = strcmp(valueWithKey100, "aaa") == 0;
    bool equalityOfValueWithKey50 = strcmp(valueWithKey50, "bbb") == 0;
    bool equalityOfValueWithKey150 = strcmp(valueWithKey150, "ccc") == 0;

    deleteTree(&map);
    return equalityOfValueWithKey50 && equalityOfValueWithKey150 && equalityOfValueWithKey100;
}

bool runTests(void) {
    bool result = testOfAppendAndAvailability() && testOfAppendAndDelete() && testOfGettingValue();
    return result;
}

void streemOfNumbersTest(void) {
    Tree* map = createTree();
    append(map, "01", "aaa");
    append(map, "02", "bbb");
    append(map, "03", "ccc");
    append(map, "04", "ddd");
    append(map, "05", "eee");
    append(map, "06", "fff");
    append(map, "07", "ggg");
    append(map, "08", "hhh");
    append(map, "09", "iii");
    append(map, "10", "jjj");
    append(map, "11", "iii");
    append(map, "12", "jjj");
    append(map, "13", "iii");
    append(map, "14", "jjj");
    append(map, "15", "iii");
    append(map, "16", "jjj");
    append(map, "17", "iii");
    append(map, "18", "jjj");
    append(map, "19", "iii");
    append(map, "20", "jjj");
    append(map, "21", "jjj");
}


int main(void) {
    /*if (!runTests()) {
        return 1;
    }
    dictionary();*/
    streemOfNumbersTest();
    printf("aa");
    return 0;
}