#include <algorithm>
#include "vertex.h"

void Vertex::makeEdgeWith(Vertex& vertex) {
    Vertex& origin = resolveEdgeOrigin(vertex);
    Vertex& destiny = resolveEdgeDestiny(vertex);

    origin.handleNewEdge(destiny);
}

void Vertex::handleNewEdge(Vertex& destiny) {
    if(hasEdgeWith(destiny))
        return;

    edges.push_back({ destiny });
}

bool Vertex::hasEdgeWith(const Vertex& destiny) const {
    return any_of(getEdges().cbegin(), getEdges().cend(), [destiny](Edge edge) {
        return edge.vertex.getId() == destiny.getId();
    });
}

Vertex& Vertex::resolveEdgeOrigin(Vertex& vertex) {
    if(vertex.getId() < getId())
        return vertex;

    return *this;
}

Vertex& Vertex::resolveEdgeDestiny(Vertex& vertex) {
    if(getId() == resolveEdgeOrigin(vertex).getId())
        return vertex;

    return *this;
}
