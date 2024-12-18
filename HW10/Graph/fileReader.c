#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

World *fileReader(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return NULL;
    }

    int countOfCities = 0;
    fscanf(file, "%d", &countOfCities);
    int countOfRoads = 0;
    fscanf(file, "%d", &countOfRoads);
    Graph *graph = createGraph(countOfCities, countOfRoads);
    int city1 = 0, city2 = 0, road = 0;
    for (int i = 0; i < countOfRoads; i++) {
        fscanf(file, "%d %d %d", &city1, &city2, &road);
        setEdge(graph, city1, city2, road);
    }

    int countOfCapitals = 0;
    fscanf(file, "%d", &countOfCapitals);
    int *capitals = calloc(countOfCapitals,  sizeof(int));
    for (int i = 0; i < countOfCapitals; i++) {
        fscanf(file, "%d", &capitals[i]);
    }

    fclose(file);

    World *world = createWorld(graph, capitals, countOfCapitals);
    return world;
}
