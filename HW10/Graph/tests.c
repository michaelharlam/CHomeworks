#include <stdio.h>
#include <stdbool.h>
#include "hashTable.h"
#include "list.h"
#include "states.h"
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
    if (!result) {
        printf("Test case failed on createGraphAndGetTableTest.\n");
        return false;
    }
    return true;
}