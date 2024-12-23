#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../stack/stack.h"

bool advancedBracketBalance(char *string) {
    int lengthOfTheString = strlen(string);
    Stack *stackWithBrackets = createStack();
    for (int i = 0; i < lengthOfTheString; i++) {
        if (string[i] == '(' || string[i] == '{' || string[i] == '[') {
            push(stackWithBrackets, string[i]);
        } else if (string[i] == ')' || string[i] == '}' || string[i] == ']') {
            char lastOpenBracket = pop(stackWithBrackets);
            switch (lastOpenBracket) {
                case '(':
                    if (string[i] != ')') {
                        return false;
                    }
                    break;
                case '{':
                    if (string[i] != '}') {
                        return false;
                    }
                    break;
                case '[':
                    if (string[i] != ']') {
                        return false;
                    }
                    break;
            }
        }
    }
    return true;
}

int main(void) {
    char string[100];
    printf("Продвинутый баланс скобок.\n");
    printf("Введите строку: ");
    scanf("%s", string);
    bool result = advancedBracketBalance(string);
    printf("%s\n", result ? "Баланс скобок в порядке!" : "Кажт");
}