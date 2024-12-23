#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "../stack/stack.h"

bool advancedBracketBalance(char *string, int lengthOfTheString) {
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
    char *string = "{}[()]";
    int lengthOfTheString = strlen(string);
    bool result = advancedBracketBalance(string, lengthOfTheString);
    printf("%s\n", result ? "true" : "false");
}