#include <stdio.h>
#include "fileReader.h"
#include "graph.h"
#include "algorithmOfDijkstra.h"


int main(void) {
    World *world = fileReader("testfile.txt");
    Graph *graph = getMap(world);
    int *distances = algorithmOfDijkstra(graph, getCountOfVertices(graph), 0);
    printf("Hello world!\n");
}
