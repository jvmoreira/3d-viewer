#ifndef INC_3D_VIEWER_OBJECT_H
#define INC_3D_VIEWER_OBJECT_H

#include <istream>
#include "vertex.h"

using namespace std;


class Object {
public:
    explicit Object(istream& objStream);
    ~Object();

    const vector<Vertex*>& getVertexes() const { return vertexes; }
    const Vertex& getVertex(unsigned int vertexId) const { return *getVertexes().at(vertexId); }
    unsigned int getVertexesCount() const { return getVertexes().size() - 1; }
    unsigned int getFacesCount() const { return facesCount; }
    const Vertex& getRelativePosition() const { return getVertex(0); }

private:
    friend class ObjectTest;

    vector<Vertex*> vertexes;
    unsigned int facesCount;
    Vertex& getMutableVertex(unsigned int vertexId) const { return *getVertexes().at(vertexId); }

    void setObjectRelativePosition(double x, double y, double z);
    void parseObject(istream& objStream);

    void parseVertex(istream& vertexDefinition);
    void addVertex(double x, double y, double z);

    void parseFace(istream& vertexDefinition);
    void addEdge(unsigned int originVertexId, unsigned int destinyVertexId);

    void clearVertexes();
    void clearFaces();
};


#endif //INC_3D_VIEWER_TESTS_OBJECT_H
