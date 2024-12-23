#include <stdio.h>
#include "treeAVL.h"
#include <stdlib.h>
#include <stdbool.h>

void dictionary(void) {
    printf("Вас приветствует словарь!\n\n");
    printf("Программа поддерживает следующие команды:\n0 - выйти\n1 - добавить значение в словарь;\n2 - проверить наличие ключа в словаре;\n");
    printf("3 - получить значение по ключу;\n4 - удалить ключ и значение по ключу.\n\n");
    printf("Введите команду: ");

    int command = 0;
    scanf("%d", &command);

    Tree *map = createTree();
    char key[100] = { '\0' };
    while (command != 0) {
        if (command == 0) {
            break;
        }

        if (command == 1) {
            printf("Введите ключ: ");
            scanf("%99s", key);

            printf("Введите значение: ");
            char value[100] = { '\0' };
            scanf("%s", value);

            append(map, key, value);
            printf("Ключ и значение добавлены в словарь.\n");
        } else if (command == 2) {
            printf("Введите ключ: ");
            scanf("%s", &key);

            if (isAvailableKey(map, key)) {
                printf("Значение по такому ключу содержится в словаре.\n");
            } else {
                printf("Значение по такому ключу не содержится в словаре.\n");
            }
        } else if (command == 3) {
            printf("Введите ключ: ");
            scanf("%s", &key);

            const char *result = getValue(map, key);
            if (result == NULL) {
                printf("Такого ключа нет в словаре.\n");
            } else {
                printf("%s\n", result);
            }
        } else if (command == 4) {
            printf("Введите ключ: ");
            scanf("%s", &key);

            bool isAvailable = isAvailableKey(map, key);
            if (!isAvailable) {
                printf("Такого ключа нет в словаре.\n");
            } else {
                deleteKey(&map, key);
                isAvailable = isAvailableKey(map, key);
                if (!isAvailable) {
                    printf("Ключ и значение удалены.\n");
                } else {
                    printf("Ошибка удаления элемента. Попробуйте снова.\n");
                }
            }
        } else {
            printf("Введен неверный номер команды. Попробуйте снова.\n");
        }
        printf("Введите команду: ");
        scanf("%d", &command);
    }

    deleteTree(&map);
}