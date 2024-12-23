#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "states.h"
#include "fileReader.h"
#include "graph.h"


bool createGraphAndGetTableTest(void) {
    Graph *graph = createGraph(6, 9);
    setEdge(graph, 0, 1, 7);
    setEdge(graph, 0, 2, 8);
    setEdge(graph, 0, 5, 9);
    setEdge(graph, 3, 4, 10);
    setEdge(graph, 4, 5, 11);
    setEdge(graph, 5, 3, 12);
    setEdge(graph, 4, 2, 13);
    setEdge(graph, 2, 5, 14);
    setEdge(graph, 1, 4, 15);

    int **table = getTable(graph);
    int countOfEdges = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (table[i][j] != 0) {
                countOfEdges++;
            }
        }
    }

    bool result = (countOfEdges == 18) && (table[0][1] == 7) && (table[0][2] == 8) && (table[0][5] == 9) && (table[3][4] == 10);
    result =  result && (table[4][5] == 11) && (table[5][3] == 12) && (table[4][2] == 13) && (table[2][5] == 14) && (table[1][4] == 15);

    destroyGraph(graph);

    if (!result) {
        printf("Test case failed on createGraphAndGetTableTest.\n");
        return false;
    }
    return true;
}

bool nearestVertexTest(void) {
    Graph *graph = createGraph(6, 9);
    setEdge(graph, 0, 1, 7);
    setEdge(graph, 0, 2, 8);
    setEdge(graph, 0, 5, 9);
    setEdge(graph, 3, 4, 10);
    setEdge(graph, 4, 5, 11);
    setEdge(graph, 5, 3, 12);
    setEdge(graph, 4, 2, 13);
    setEdge(graph, 2, 5, 14);
    setEdge(graph, 1, 4, 15);

    int **table = getTable(graph);
    int nearestNeighbourFor0 = nearestVertex(table, 6, 0);
    int nearestNeighbourFor1 = nearestVertex(table, 6, 1);
    int nearestNeighbourFor2 = nearestVertex(table, 6, 2);
    int nearestNeighbourFor3 = nearestVertex(table, 6, 3);
    int nearestNeighbourFor4 = nearestVertex(table, 6, 4);
    int nearestNeighbourFor5 = nearestVertex(table, 6, 5);

    bool result = (nearestNeighbourFor0 == 1) && (nearestNeighbourFor1 == 0) && (nearestNeighbourFor2 == 0) && (nearestNeighbourFor3 == 4);
    result = result && (nearestNeighbourFor4 == 3) && (nearestNeighbourFor5 == 0);

    destroyGraph(graph);

    if (!result) {
        printf("Test case failed on nearestVertexTest.\n");
        return false;
    }
    return true;
}

bool statesTest(void) {
    HashTable *statesOnGraph = states("testfile.txt");
    int *firstState = getValueFromTable(statesOnGraph, 0);
    int *secondState = getValueFromTable(statesOnGraph, 4);

    bool resultForFirstState = (firstState[0] == 1) && (firstState[1] == 1) && (firstState[2] == 1) && (firstState[3] == 0) && (firstState[4] == 0) && (firstState[5] == 0);
    bool resultForSecondState = (secondState[0] == 0) && (secondState[1] == 0) && (secondState[2] == 0) && (secondState[3] == 1) && (secondState[4] == 1) && (secondState[5] == 1);

    destroyHashTable(&statesOnGraph);

    if (!resultForFirstState || !resultForSecondState) {
        printf("Test case failed on statesTest.\n");
        return false;
    }
    return true;
}

bool runTests(void) {
    return createGraphAndGetTableTest() && nearestVertexTest() && statesTest();
}