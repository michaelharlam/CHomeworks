#include <stdlib.h>
#include "graph.h"
#include "fileReader.h"
#include "algorithmOfDijkstra.h"
#include "list.h"
#define TEN_BILLIONS 10000000000


int minimumDistanceToFreeCity(int *distances, int *closedRoads, int countOfCities) {
    int minimumDistance = TEN_BILLIONS;
    for (int i = 0; i < countOfCities; i++) {
        if ((distances[i] < minimumDistance) && (closedRoads[i] == 0)) {
            minimumDistance = distances[i];
        }
    }
    return minimumDistance;
}


int *getClosedRoads(List *states, int countOfCities) {
}

void states(const char *fileName) {
    World *world = fileReader(fileName);
    Graph *map = getMap(world);
    int *capitals = getCapitals(world);
    List *states = initList();
    int countOfCapitals = getCountOfCapitals(world);
    int countOfVertices = getCountOfVertices(map);
    int *closedRoads = calloc(countOfVertices, sizeof(int));
    for (int i = 0; i < countOfCapitals; ++i) {
        int *cities = calloc(countOfVertices, sizeof(int));
        closedRoads[capitals[i]] = 1;
        append(states, capitals[i], &cities);
    }

}