#pragma once
#ifndef EXPRESSIONPARSER_H
#define EXPRESSIONPARSER_H
#include <stdbool.h>

bool isOperation(char value);

bool isParenthesis(char value);

void expressionParser(char *expression);

#endif //EXPRESSIONPARSER_H
