#include <stdlib.h>
#include "graph.h"
#include "fileReader.h"
#include "hashTable.h"
#define BILLION 1000000000


int minimumIndex(int *vertices, int size) {
    int minimum = BILLION;
    int minimumIndex = size + 1;
    for (int i = 0; i < size; i++) {
        if (vertices[i] < minimum) {
            minimum = vertices[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

int sumOfArray(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int nearestVertex(int **table, int countOfVertices, int vertex) {
    int *distance = malloc(countOfVertices * sizeof(int));

    for (int i = 0; i < countOfVertices; i++) {
        if (table[vertex][i] != 0) {
            distance[i] = table[vertex][i];
        }
    }
    int nearestVertex = minimumIndex(distance, countOfVertices);
    free(distance);
    return nearestVertex;
}


int minimumDistanceToFreeCity(int *distances, int *closedRoads, int countOfCities) {
    int minimumDistance = BILLION;
    for (int i = 0; i < countOfCities; i++) {
        if ((distances[i] < minimumDistance) && (closedRoads[i] == 0)) {
            minimumDistance = distances[i];
        }
    }
    return minimumDistance;
}

int *arrayCopy(int *array, int size) {
    int *newArray = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    return newArray;
}

void states(const char *fileName) {
    World *world = fileReader(fileName);
    Graph *map = getMap(world);
    int **mapTable = getTable(map);
    int *capitals = getCapitals(world);
    int countOfCapitals = getCountOfCapitals(world);
    int countOfVertices = getCountOfVertices(map);
    HashTable *states = createHashTable();
    for (int i = 0; i < countOfCapitals; i++) {
        int *cities = calloc(countOfVertices, sizeof(int));
        cities[capitals[i]] = 1;
        appendToTable(&states, capitals[i], cities);
    }

    for (int i = 0; i < ((countOfVertices - countOfCapitals) / countOfCapitals + 1); i++) {
        for (int j = 0; j < countOfCapitals; j++) {
            int nearestCityForState = BILLION;
            int *cities = getValueFromTable(states, capitals[j]);
            for (int city = 0; city < countOfVertices; city++) {
                if (cities[i] == 1) {
                    int nearestCity = nearestVertex(mapTable, countOfVertices, city);
                    if (nearestCity < nearestCityForState) {
                        nearestCityForState = nearestCity;
                    }
                }
            }
            for (int vertex = 0; vertex < countOfVertices; vertex++) {
                mapTable[i][vertex] = 0;
            }
            addToTableValue(&states, capitals[i], nearestCityForState);
        }
    }

    printTable(states, countOfVertices);
}