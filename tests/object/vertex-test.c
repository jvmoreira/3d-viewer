#include "object/vertex.h"
#include "test-case.h"
#include "vertex-test.h"

void runVertexTests() {
    buildVertexTest();
}

void buildVertexTest() {
    const double vertexX = 0.99;
    const double vertexY = 2.5;
    const double vertexZ = 5.333;
    VertexPtr vertex = buildVertex(vertexX, vertexY, vertexZ);

    test(vertex != NULL, "buildVertex returns a valid vertex pointer");
    int assertCoordinates = vertex->x == vertexX && vertex->y == vertexY && vertex->z == vertexZ;
    test(assertCoordinates, "buildVertex should set vertex's coordinate correctly");

    destroyVertex(vertex);
}
