#include "vertex-test.h"
#include "object/vertex.h"

void VertexTest::constructorTest() const {
    const unsigned int vertexId = 16;
    const double vertexX = 0.99;
    const double vertexY = 2.5;
    const double vertexZ = 5.333;
    Vertex vertex(vertexId, vertexX, vertexY, vertexZ);

    test(vertex.getId() == vertexId, "constructor should set vertex id correctly");
    test(vertex.getX() == vertexX, "constructor should set vertex x coordinate correctly");
    test(vertex.getY() == vertexY, "constructor should set vertex y coordinate correctly");
    test(vertex.getZ() == vertexZ, "constructor should set vertex z coordinate correctly");
}

void VertexTest::makeEdgeWithTest() const {
    Vertex origin(0, 0.0, 0.0, 0.0);
    Vertex destiny(1, 1.1, 1.2, 1.3);
    Vertex destiny2(2, 2.5, 1.6, 1.7);
    auto& originEdges = origin.getEdges();

    origin.makeEdgeWith(destiny);
    test(originEdges.size() == 1, "makeEdgeWith should create edge on origin vertex");
    test(destiny.getEdges().empty(), "makeEdgeWith should not create edge on destiny vertex");
    test(originEdges[0].vertex == destiny, "makeEdgeWith should create edge to the correct destiny vertex");

    origin.makeEdgeWith(destiny);
    destiny.makeEdgeWith(origin);
    test(originEdges.size() == 1 && destiny.getEdges().empty(), "makeEdgeWith should not create new edge if it already exists");

    destiny2.makeEdgeWith(origin);
    test(originEdges.size() == 2, "makeEdgeWith should set origin to lower id vertex");
    test(destiny2.getEdges().empty(), "makeEdgeWith should set destiny to greater id vertex");
    test(originEdges[0].vertex == destiny, "makeEdgeWith should create edge to the correct destiny vertex");
}
