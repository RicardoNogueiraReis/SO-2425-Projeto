#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
    int Avenida, // A
        Rua;     // B
} Vertex;

typedef struct edge {

    struct Vertex* next;
    struct Vertex* previous;
} Edge;

typedef struct graph {
    int numVertices,
        numEdges;
    struct Vertex** vertices; // calloc
    struct Edge** edges; // calloc  
} Edge;

// O <-> O
