#include <stdlib.h>
#include "vertex.h"

VertexPtr buildVertex(double x, double y, double z) {
    VertexPtr vertex = (VertexPtr) malloc(sizeof(Vertex));

    vertex->x = x;
    vertex->y = y;
    vertex->z = z;

    return vertex;
}
