#include <sstream>
#include "object.h"

Object::~Object() {
    clearFaces();
    clearVertexes();
}

Object::Object(istream& objStream): facesCount(0) {
    setObjectRelativePosition(0, 0, 0);
    parseObject(objStream);
}

void Object::setObjectRelativePosition(double x, double y, double z) {
    if(getVertexes().empty())
        addVertex(x, y, z);
}

void Object::parseObject(istream &objStream) {
    string line;

    while(getline(objStream, line)) {
        istringstream lineStream(line);
        string operation;
        lineStream >> operation;

        if(operation == "v")
            parseVertex(lineStream);
        else if(operation == "f")
            parseFace(lineStream);
    }
}

void Object::parseVertex(istream& vertexDefinition) {
    double x, y, z;
    vertexDefinition >> x >> y >> z;

    addVertex(x, y, z);
}

void Object::addVertex(double x, double y, double z) {
    unsigned int vertexId = getVertexes().size();
    auto vertex = new Vertex(vertexId, x, y, z);

    vertexes.push_back(vertex);
}

void Object::parseFace(istream& vertexDefinition) {
    unsigned int currentVertexId, nextVertexId;
    vertexDefinition >> currentVertexId;
    unsigned int firstVertexId = currentVertexId;

    while(!vertexDefinition.eof() && vertexDefinition >> nextVertexId) {
        addEdge(currentVertexId, nextVertexId);
        currentVertexId = nextVertexId;
    }
    addEdge(nextVertexId, firstVertexId);
    facesCount++;
}

void Object::addEdge(unsigned int originVertexId, unsigned int destinyVertexId) {
    getMutableVertex(originVertexId).makeEdgeWith(getMutableVertex(destinyVertexId));
}

void Object::clearFaces() {
    facesCount = 0;
}

void Object::clearVertexes() {
    for(auto vertex : getVertexes()) {
        delete vertex;
    }
    vertexes.clear();
}
