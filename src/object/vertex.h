#ifndef INC_3D_VIEWER_VERTEX_H
#define INC_3D_VIEWER_VERTEX_H

#include <vector>
using namespace std;


class Vertex {
private:
    struct Edge {
        Vertex &vertex;
    };
    struct Coordinate {
        double x, y, z;
    };
    unsigned int _id;
    Coordinate coordinate;
    vector<Edge> edges;

    void handleNewEdge(Vertex &destiny);
    bool hasEdgeWith(Vertex &destiny) const;
    Vertex &resolveEdgeOrigin(Vertex &vertex);
    Vertex &resolveEdgeDestiny(Vertex &vertex);

public:
    Vertex(
        unsigned int id,
        double x, double y, double z
    ): _id(id), coordinate({x, y, z}) {};
    unsigned int getId() const { return _id; }

    double getX() const { return coordinate.x; }
    double getY() const { return coordinate.y; }
    double getZ() const { return coordinate.z; }
    const Coordinate &getCoordinate() const { return coordinate; }
    const vector<Edge> &getEdges() const { return edges; }
    void makeEdgeWith(Vertex &vertex);

    bool operator!=(const Vertex &rhs) const {
        return !(rhs == *this);
    }

    bool operator==(const Vertex &compare) const {
        return this->getId() == compare.getId()
               && this->getX() == compare.getX()
               && this->getY() == compare.getY()
               && this->getZ() == compare.getZ();
    }
};


#endif //INC_3D_VIEWER_VERTEX_H
