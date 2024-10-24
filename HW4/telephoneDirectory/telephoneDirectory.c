#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char number[100];
    char name[100];
} stringOfDatabaseText;

bool stringComparison(char *string1, char *string2) {
    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int length = length1 < length2 ? length1 : length2;
    for (int i = 0; i < length; ++i) {
        if (string1[i] != string2[i]) {
            return false;
        }
    }
    return true;
}

void databaseText(void) {
    FILE *databaseFile;

    stringOfDatabaseText  databaseText[100];

    int count = 0;

    databaseFile = fopen("database.txt", "r");

    if (databaseFile == NULL) {
        printf("Database do not exist, creating new\n");
    } else {
        do {
            fscanf(databaseFile, "%s %s\n", databaseText[count].number, databaseText[count].name);
            ++count;
        } while (!feof(databaseFile));

        fclose(databaseFile);
    }

    int command = 0;

    printf("Вас приветсвует телефонный справочник!\n");
    printf("Вы можете ввести следующие команды:\n");
    printf("0 - выйти\n1 - добавить запись (имя и телефон)\n2 - распечатать все имеющиеся записи\n3 - найти телефон по имени\n4 - найти имя по телефону\n5 - сохранить текущие данные в файл.\n");

    do {
        printf("Введите команду: ");
        scanf("%d", &command);
        if (command == 1) {
            printf("Введите номер телефона и имя через пробел: ");
            scanf("%s %s", databaseText[count].number, databaseText[count].name);
            ++count;
        } else if (command == 2) {
            printf("Вот все, что содержится в телефонном справочнике: \n");
            for (int i = 0; i < count; ++i) {
                printf("%s %s\n", databaseText[i].number, databaseText[i].name);
            }
        } else if (command == 3) {
            printf("Введите имя: ");
            char name[100] = { 0 };
            scanf("%s", name);
            for (int i = 0; i < count; ++i) {
                if (stringComparison(databaseText[i].name, name)) {
                    printf("%s\n", databaseText[i].number);
                }
            }
        } else if (command == 4) {
            printf("Введите номер телефона: ");
            char number[100] = { 0 };
            scanf("%s", number);
            for (int i = 0; i < count; ++i) {
                if (stringComparison(databaseText[i].number, number)) {
                    printf("%s\n", databaseText[i].name);
                }
            }
        } else if (command == 5) {
            databaseFile = fopen("database.txt", "w+");
            printf("Данные сохранены.\n");
            for (int i = 0; i < count; ++i) {
                fprintf(databaseFile, "%s %s\n", databaseText[i].number, databaseText[i].name);
            }
            fclose(databaseFile);
        };
    } while (command != 0);
}



int main(void) {
    databaseText();
}