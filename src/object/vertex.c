#include <stdio.h>
#include "vertex.h"
#include "stdlib-helper.h"

EdgePtr buildEdge(VertexPtr vertex);
void addEdgeToVertex(VertexPtr vertex, EdgePtr newEdge);
short edgeAlreadyExists(VertexPtr originVertex, VertexPtr endVertex);
EdgePtr getVertexLastEdge(VertexPtr vertex);
VertexPtr resolveOriginVertex(VertexPtr vA, VertexPtr vB);
VertexPtr resolveEndVertex(VertexPtr vA, VertexPtr vB);

VertexPtr buildVertex(unsigned int id, double x, double y, double z) {
    VertexPtr vertex = (VertexPtr) malloc(sizeof(Vertex));

    vertex->id = id;
    vertex->x = x; vertex->y = y; vertex->z = z;
    vertex->numberOfEdges = 0;
    vertex->edges = NULL;

    return vertex;
}

void createEdgeBetweenVertexes(VertexPtr vertexA, VertexPtr vertexB) {
    VertexPtr originVertex = resolveOriginVertex(vertexA, vertexB);
    VertexPtr endVertex = resolveEndVertex(vertexA, vertexB);

    if(!edgeAlreadyExists(originVertex, endVertex))
        addEdgeToVertex(originVertex, buildEdge(endVertex));
}

EdgePtr buildEdge(VertexPtr vertex) {
    EdgePtr edge = (EdgePtr) malloc(sizeof(Edge));
    edge->vertex = vertex;
    edge->next = NULL;

    return edge;
}

void addEdgeToVertex(VertexPtr vertex, EdgePtr newEdge) {
    EdgePtr lastEdge = getVertexLastEdge(vertex);
    if(!lastEdge)
        vertex->edges = newEdge;
    else
        lastEdge->next = newEdge;
    vertex->numberOfEdges++;
}

short edgeAlreadyExists(VertexPtr originVertex, VertexPtr endVertex) {
    EdgePtr currentEdge = originVertex->edges;

    while(currentEdge) {
        if(currentEdge->vertex->id == endVertex->id)
            return 1;
        currentEdge = currentEdge->next;
    }

    return 0;
}

EdgePtr getVertexLastEdge(VertexPtr vertex) {
    if(!vertex->edges)
        return NULL;

    EdgePtr currentEdge = vertex->edges;
    while(currentEdge->next)
        currentEdge = currentEdge->next;

    return currentEdge;
}

inline VertexPtr resolveOriginVertex(VertexPtr vA, VertexPtr vB) {
    return vA->id < vB->id ? vA : vB;
}

inline VertexPtr resolveEndVertex(VertexPtr vA, VertexPtr vB) {
    return vA->id < vB->id ? vB : vA;
}

void destroyVertexEdges(VertexPtr vertex) {
    EdgePtr currentEdge, nextEdge;
    currentEdge = vertex->edges;

    while(currentEdge) {
        nextEdge = currentEdge->next;
        free(currentEdge);
        currentEdge = nextEdge;
    }
}

void destroyVertex(VertexPtr vertex) {
    destroyVertexEdges(vertex);
    free(vertex);
}
