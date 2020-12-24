#ifndef INC_3D_VIEWER_VERTEX_H
#define INC_3D_VIEWER_VERTEX_H

#include <stdlib.h>

struct Vertex;
struct Edge;

typedef struct Edge {
    struct Vertex *vertex;
    struct Edge *next;
} Edge, *EdgePtr;

typedef struct Vertex {
    double x, y, z;
    unsigned int id;
    EdgePtr edges;
    unsigned int numberOfEdges;
} Vertex, *VertexPtr;

VertexPtr buildVertex(unsigned int id, double x, double y, double z);
void createEdgeBetweenVertexes(VertexPtr vertexA, VertexPtr vertexB);
void destroyVertex(VertexPtr vertex);

#endif //INC_3D_VIEWER_VERTEX_H
