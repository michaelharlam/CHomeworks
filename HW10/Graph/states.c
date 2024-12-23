#include <stdlib.h>
#include "graph.h"
#include "fileReader.h"
#include "hashTable.h"
#define BILLION 1000000000


int minimumIndex(int *vertices, int size) {
    int minimum = BILLION;
    int minimumIndex = size + 1;
    for (int i = 0; i < size; i++) {
        if ((vertices[i] < minimum) && (vertices[i] != 0)) {
            minimum = vertices[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

int nearestVertex(int **table, int countOfVertices, int vertex) {
    int *distance = calloc(countOfVertices, sizeof(int));

    for (int i = 0; i < countOfVertices; i++) {
        if (table[vertex][i] != 0) {
            distance[i] = table[vertex][i];
        }
    }
    int nearestVertex = minimumIndex(distance, countOfVertices);
    free(distance);
    if (nearestVertex == countOfVertices + 1) {
        return -1;
    }
    return nearestVertex;
}


HashTable *states(const char *fileName) {
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

    for (int i = countOfCapitals; i < (countOfVertices + 1); i++) {
        for (int j = 0; j < countOfCapitals; j++) {
            int nearestCityForState = BILLION;
            int *cities = getValueFromTable(states, capitals[j]);
            for (int city = 0; city < countOfVertices; city++) {
                if (cities[city] == 1) {
                    int nearestCity = nearestVertex(mapTable, countOfVertices, city);
                    if (nearestCity == -1) {
                        continue;
                    }
                    if (nearestCity < nearestCityForState) {
                        nearestCityForState = nearestCity;
                    }
                }
            }
            if (nearestCityForState != BILLION) {
                for (int vertex = 0; vertex < countOfVertices; vertex++) {
                    mapTable[vertex][nearestCityForState] = 0;
                }
                addToTableValue(&states, capitals[j], nearestCityForState);
            }
        }
    }

    printTable(states, countOfVertices);
    destroyWorld(world);
    return states;
}