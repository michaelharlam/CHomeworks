#include <stdlib.h>


typedef struct Graph {
    int **table;
    int vertices;
    int edges;
} Graph;

typedef struct World {
    Graph *map;
    int *capitals;
    int countOfCapitals;
} World;

World *createWorld(Graph *map, int *capitals, int countOfCapitals) {
    World *world = malloc(sizeof(World));
    world->map = map;
    world->capitals = capitals;
    world->countOfCapitals = countOfCapitals;
    return world;
}

Graph *createGraph(int vertices, int edges) {
    Graph *graph = malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->table = malloc(sizeof(int*) * vertices);
    for (int i = 0; i < vertices; i++) {
        graph->table[i] = calloc(edges, sizeof(int));
    }
    return graph;
}

void setEdge(Graph *graph, int vertex1, int vertex2, int edgeLength) {
    graph->table[vertex1][vertex2] = edgeLength;
    graph->table[vertex2][vertex1] = edgeLength;
}

Graph *getMap(World *world) {
    return world->map;
}

int *getCapitals(World *world) {
    return world->capitals;
}

int getCountOfCapitals(World *world) {
    return world->countOfCapitals;
}

int **getTable(Graph *graph) {
    return graph->table;
}

int getCountOfVertices(Graph *graph) {
    return graph->vertices;
}

void removeVertex(Graph *graph, int vertex) {
    for (int i = 0; i < graph->vertices; ++i) {
        graph->table[vertex][i] = 0;
        graph->table[i][vertex] = 0;
    }
}

void destroyGraph(Graph *graph) {
    for (int i = 0; i < graph->vertices; ++i) {
        free(graph->table[i]);
    }
    free(graph->table);
    free(graph);
}

void destroyWorld(World *world) {
    free(world->map);
    free(world->capitals);
    free(world);
}