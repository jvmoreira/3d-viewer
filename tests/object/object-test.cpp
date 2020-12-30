#include "object-test.h"
#include "object/object.h"

void ObjectTest::constructorTest() const {
    auto objStream = buildTestObjStream();
    Object object(objStream);

    test(object.getVertexesCount() == 4, "constructor should parse vertexes correctly");
    test(object.getFacesCount() == 4, "constructor should parse faces correctly");
    test(object.getRelativePosition() == Vertex(0, 0, 0, 0), "constructor should set relative position to the origin");
}

void ObjectTest::getVertexesTest() const {
    istringstream objStream("");
    Object object(objStream);
    auto vertex = new Vertex(1, 1.0, 2.0, 3.0);
    object.vertexes.push_back(vertex);

    test(object.getVertexes().at(1) == vertex, "getVertexes should return reference for object vertexes");
}

void ObjectTest::getVertexTest() const {
    istringstream objStream("");
    Object object(objStream);
    auto vertex = new Vertex(1, 1.0, 2.0, 3.0);
    object.vertexes.push_back(vertex);

    test(object.getVertex(1) == *vertex, "getVertexes should return reference for vertex correctly");
}

void ObjectTest::getRelativePositionTest() const {
    istringstream objStream("");
    Object object(objStream);

    test(object.getRelativePosition() == object.getVertex(0), "constructor should set relative position to the origin");
}

void ObjectTest::getVertexesCountTest() const {
    istringstream objStream("");
    Object object(objStream);
    object.vertexes.push_back(new Vertex(1, 1.0, 2.0, 3.0));

    test(object.getVertexesCount() == 1, "getVertexesCount should return number of vertexes correctly");
}

void ObjectTest::getFacesCountTest() const {
    istringstream objStream("");
    Object object(objStream);
    object.vertexes.push_back(new Vertex(1, 1.0, 1.0, 1.0));
    object.vertexes.push_back(new Vertex(2, 2.0, 2.0, 2.0));
    object.vertexes.push_back(new Vertex(3, 3.0, 3.0, 3.0));
    istringstream faceStream("1 2 3");
    object.parseFace(faceStream);

    test(object.getFacesCount() == 1, "getFacesCount should return number of faces correctly");
}

stringstream ObjectTest::buildTestObjStream() {
    stringstream testObjStream("# Test Object\n");

    testObjStream << "v 0.0 0.0 0.0" << endl;
    testObjStream << "v 1.0 0.0 0.0" << endl;
    testObjStream << "v 0.0 0.0 1.0" << endl;
    testObjStream << "v 0.0 1.0 0.0" << endl;

    testObjStream << "f 1 2 3" << endl;
    testObjStream << "f 1 2 4" << endl;
    testObjStream << "f 1 3 4" << endl;
    testObjStream << "f 2 3 4" << endl;

    return testObjStream;
}
