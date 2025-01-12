#pragma once
#include "list.h"

typedef struct HashTable HashTable; // структура с хэш-таблицей; поля: таблица, размер

HashTable *createHashTable(int size); // создание хэш-таблицы; принимает размер, возвращает хэш-таблицу

void printTable(HashTable *hashTable); // вывод хэш-таблицы

void appendToTable(HashTable **hashTable, const char *key, int value); // добавление элемента в таблицу; принимает хэш-таблицу, строковый ключ и целочисленное значение

int getValueFromTable(HashTable *hashTable, const char *key); // получение значения из таблицы по ключу; принимает хэш-таблицу и строковый ключ, возвращает целочисленное значение

List **getTable(HashTable *HashTable); // получение массива списков (самой таблицы) из хэш-таблицы

void destroyHashTable(HashTable **hashTable); // удаление хэш-таблицы

unsigned int maxLengthOfList(HashTable *HashTable); // функция находит и возвращает максимальную длину списка в хэш-таблице

float averageLengthOfList(HashTable *HashTable); // среднюю длину, в остальном аналогична предыдущей

float occupancyRate(HashTable *HashTable); // возвращает коэффициент заполнения хэш-таблицы
