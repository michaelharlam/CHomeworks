#pragma once

typedef struct Node Node; // структура узла списка

typedef struct List List; // структура списка

List* initList(void); // инициализация списка; возвращает указатель на список

Node* createNode(const char *key, int value); // создание узла; возвращает указатель на узел

void append(List *list, const char *key, int value); // добавление элемента в список по строковому ключу и целочисленному значению

void removeFromList(List *list, Node *node); // удаление указанного в параметрах узла из указанного там же списка

Node *next(Node *node); // возвращает следующий узел за данным

Node *first(List *list); // возвращает первый узел списка

Node *last(List *list); // возвращает последний узел списка

int getSize(List *list); // возвращает размер списка

void freeList(List *list); // удаление списка

const char *getKey(Node *node); // получение строкового ключа из узла

int getValue(Node *node); // получение целочисленного значения из узла

void changeValue(Node *node, int value); // замена целочисленного значения в узле