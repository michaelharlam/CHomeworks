#pragma once

typedef struct Graph Graph;

typedef struct World World;

World *createWorld(Graph *map, int *capitals, int countOfCapitals);

Graph *createGraph(int vertices, int edges);

void setEdge(Graph *graph, int vertex1, int vertex2, int edgeLength);

Graph *getMap(World *world);

int *getCapitals(World *world);

int getCountOfCapitals(World *world);

int **getTable(Graph *graph);

int getCountOfVertices(Graph *graph);

void removeVertex(Graph *graph, int vertex);