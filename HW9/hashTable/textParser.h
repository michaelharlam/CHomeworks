#ifndef TEXTPARSER_H
#define TEXTPARSER_H
#include "hashTable.h"

HashTable *textToTable(char *fileName); // функция, считающая количество слов в тексте, занося их в качестве ключей в хэш-таблицу

void printCountOfWords(HashTable *hashTable); // функция, выводящая слова и количество их повторений в тексте

#endif
