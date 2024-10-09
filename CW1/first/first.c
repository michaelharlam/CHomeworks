#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool palindrome(char originalString[], int length) {
    int quantityOfSpaces = 0;
    for (int i = 0; i < length; ++i) {
        if (originalString[i] == ' ') {
            ++quantityOfSpaces;
        }
    }
    char* stringWithoutSpaces = (char*)malloc((length - quantityOfSpaces) * sizeof(char));
    int counterOfSpaces = 0;
    for (int i = 0; i < length; ++i) {
        if (originalString[i] != ' ') {
            stringWithoutSpaces[i - counterOfSpaces] = originalString[i];
        } else {
            ++counterOfSpaces;
        }
    }
    for (int i = 0; i < ((length - quantityOfSpaces) / 2); ++i) {
        if (stringWithoutSpaces[i] != stringWithoutSpaces[(length - quantityOfSpaces)- i - 1]) {
            free(stringWithoutSpaces);
            return false;
        }
    }
    free(stringWithoutSpaces);
    return true;
}

bool test1(void) {
    int length = 18;
    char string[18] = "R aaa bu iub aaa R";
    if (!palindrome(string, length)) {
        printf("The first test failed\n");
        return false;
    }
    return true;
}

bool test2(void) {
    int length = 18;
    char string[18] = "R aaa bui iub aaaR";
    if (!palindrome(string, length)) {
        printf("The second test failed\n");
        return false;
    }
    return true;
}

int main(void) {
    if (test1() && test2()) {
        printf("Program is ready for work!\n");
        int length = 19;
        char string[] = "z ble c vtxtv celbz";
        if (palindrome(string, strlen(string))) {
            printf("YES!\n");
        } else {
            printf("NO :(\n");
        }
    }
}