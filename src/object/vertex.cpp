#include "vertex.h"

void Vertex::makeEdgeWith(Vertex &vertex) {
    Vertex &origin = this->resolveEdgeOrigin(vertex);
    Vertex &destiny = this->resolveEdgeDestiny(vertex);

    origin.handleNewEdge(destiny);
}

void Vertex::handleNewEdge(Vertex &destiny) {
    if(this->hasEdgeWith(destiny))
        return;

    this->edges.push_back({ destiny });
}

bool Vertex::hasEdgeWith(Vertex &destiny) const {
    for(auto &edge : this->getEdges()) {
        if (edge.vertex.getId() == destiny.getId())
            return true;
    }

    return false;
}

Vertex &Vertex::resolveEdgeOrigin(Vertex &vertex)  {
    if(vertex.getId() < this->getId())
        return vertex;

    return *this;
}

Vertex &Vertex::resolveEdgeDestiny(Vertex &vertex) {
    if(this->getId() == resolveEdgeOrigin(vertex).getId())
        return vertex;

    return *this;
}
