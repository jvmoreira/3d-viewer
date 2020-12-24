#include "object/vertex.h"
#include "test-case.h"
#include "vertex-test.h"

void buildVertexTest();
void createEdgeBetweenVertexesTest();

void runVertexTests() {
    buildVertexTest();
    createEdgeBetweenVertexesTest();
}

void buildVertexTest() {
    const unsigned int vertexId = 16;
    const double vertexX = 0.99;
    const double vertexY = 2.5;
    const double vertexZ = 5.333;
    VertexPtr vertex = buildVertex(vertexId, vertexX, vertexY, vertexZ);

    test(vertex != NULL, "buildVertex returns a valid vertex pointer");
    test(vertex->id == vertexId, "buildVertex sets vertex's id correctly");
    int assertCoordinates = vertex->x == vertexX && vertex->y == vertexY && vertex->z == vertexZ;
    test(assertCoordinates, "buildVertex sets vertex's coordinates correctly");

    destroyVertex(vertex);
}

void createEdgeBetweenVertexesTest() {
    VertexPtr originVertex = buildVertex(0, 0.0, 0.0, 0.0);
    VertexPtr endVertex = buildVertex (1, 1.0, 1.0, 1.0);
    VertexPtr endVertex2 = buildVertex(2, 2.0, 2.0, 2.0);
    createEdgeBetweenVertexes(originVertex, endVertex);

    test(endVertex->numberOfEdges == 0, "createEdgeBetweenVertexes does not creates edge on end vertex");
    test(originVertex->numberOfEdges == 1, "createEdgeBetweenVertexes increments origin vertex number of edges");
    test(originVertex->edges->vertex == endVertex, "createEdgeBetweenVertexes creates an edge to the correct vertex");

    createEdgeBetweenVertexes(originVertex, endVertex);
    test(originVertex->numberOfEdges == 1, "createEdgeBetweenVertexes does not create edge if it already exists");

    createEdgeBetweenVertexes(originVertex, endVertex2);
    test(originVertex->numberOfEdges == 2, "createEdgeBetweenVertexes increments origin vertex number of edges");
    test(originVertex->edges->next->vertex == endVertex2, "createEdgeBetweenVertexes creates an edge to the correct vertex");

    destroyVertex(originVertex);
    destroyVertex(endVertex);
    destroyVertex(endVertex2);
}
