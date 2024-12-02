#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


char* replace(char *string) {
    int stringLength = strlen(string);
    char *newString = malloc(stringLength * sizeof(char));
    int counter = 0;
    int repetitive = 0;
    char letter = 'a';
    for (int i = 0; i < (stringLength + 1); ++i) {
        if (string[i] == letter) {
            ++counter;
            if (counter > 1) {
                ++repetitive;
            }
        } else if ((i - counter) >= 0) {
            newString[i - repetitive - 1] = letter;
            counter = 1;
            letter = string[i];
        } else {
            counter = 1;
            letter = string[i];
        }
    }
    return newString;
}

bool simpleTest(void) {
    char *string = "aafgbbba";
    char *newString = replace(string);
    bool result = strcmp(newString, "afgba") == 0;
    free(newString);
    if (!result) {
        printf("Simple test is failed.");
    }
    return result;
}

bool numbersAndSymbolsTest(void) {
    char *string = "++-778))(9";
    char *newString = replace(string);
    bool result = strcmp(newString, "+-78)(9") == 0;
    free(newString);
    if (!result) {
        printf("Numbers and symbols test is failed.");
    }
    return result;
}

bool spaceTest(void) {
    char *string = "hello world";
    char *newString = replace(string);
    bool result = strcmp(newString, "helo world") == 0;
    free(newString);
    if (!result) {
        printf("Space test is failed.");
    }
    return result;
}

bool bigAndSmallLettersTest(void) {
    char *string = "aAaaAA";
    char *newString = replace(string);
    bool result = strcmp(newString, "aAaA") == 0;
    free(newString);
    if (!result) {
        printf("Big and small letters is failed.");
    }
    return result;
}

bool mergingTests(void) {
    return simpleTest() && numbersAndSymbolsTest() && spaceTest() && bigAndSmallLettersTest();
}

int main() {
    if (!mergingTests()) {
        return -1;
    }
    printf("Введите строку с повторяющимися символами: ");
    char string[100];
    scanf("%s", string);
    char *newString = replace(string);
    printf("%s%s\n", "Без повторов: ", newString);
    free(newString);
}