#include <stdlib.h>
#include "graph.h"
#define tenBillions 10000000000

int indexOfUnvisitedVertexWithMinimumDistance(int *distance, int *visitedVertices, int size) {
    int minimum = tenBillions;
    int minimumIndex = size + 1;
    for (int i = 0; i < size; i++) {
        if ((distance[i] < minimum) && (visitedVertices[i] == 0)) {
            minimum = distance[i];
            minimumIndex = i;
        }
    }
    return minimumIndex;
}

int minimumIndex(int *vertices, int size) {
    int minimum = tenBillions;
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

int *algorithmOfDijkstraStep(Graph *graph, int countOfVertices, int vertex) {
    int **table = getTable(graph);
    int *distance = malloc(countOfVertices * sizeof(int));
    int *visitedVertices = malloc(countOfVertices * sizeof(int));
    for (int i = 0; i < countOfVertices; i++) {
        distance[i] = tenBillions;
        visitedVertices[i] = 0;
    }
    distance[vertex] = 0;
    int currentVertex = indexOfUnvisitedVertexWithMinimumDistance(distance, visitedVertices, countOfVertices);
    for (int i = 0; i < countOfVertices; i++) {
        if (table[currentVertex][i] == 0) {
            continue;
        }
        if ((distance[currentVertex] + table[currentVertex][i]) < distance[i]) {
            distance[i] = distance[currentVertex] + table[currentVertex][i];
        }
    }
    visitedVertices[currentVertex] = 1;
    currentVertex = indexOfUnvisitedVertexWithMinimumDistance(distance, visitedVertices, countOfVertices);
    free(visitedVertices);
    return distance;
}
