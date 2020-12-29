#ifndef INC_3D_VIEWER_VERTEX_H
#define INC_3D_VIEWER_VERTEX_H

#include <vector>
using namespace std;


class Vertex {
private:
    struct Edge {
        Vertex& vertex;
    };
    struct Coordinate {
        double x, y, z;
    };
    unsigned int id;
    Coordinate coordinate;
    vector<Edge> edges;

    void handleNewEdge(Vertex& destiny);
    bool hasEdgeWith(const Vertex& destiny) const;
    Vertex& resolveEdgeOrigin(Vertex& vertex);
    Vertex& resolveEdgeDestiny(Vertex& vertex);

public:
    Vertex(
        unsigned int id,
        double x, double y, double z
    ): id(id), coordinate({x, y, z}) {};
    unsigned int getId() const { return id; }

    double getX() const { return coordinate.x; }
    double getY() const { return coordinate.y; }
    double getZ() const { return coordinate.z; }
    const Coordinate& getCoordinate() const { return coordinate; }

    const vector<Edge>& getEdges() const { return edges; }
    void makeEdgeWith(Vertex& vertex);

    bool operator!=(const Vertex& compared) const {
        return !(compared == *this);
    }

    bool operator==(const Vertex& compared) const {
        return getId() == compared.getId()
          && getX() == compared.getX()
          && getY() == compared.getY()
          && getZ() == compared.getZ();
    }
};


#endif //INC_3D_VIEWER_VERTEX_H
