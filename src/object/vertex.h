#ifndef INC_3D_VIEWER_VERTEX_H
#define INC_3D_VIEWER_VERTEX_H

typedef struct {
    double x, y, z;
} Vertex, *VertexPtr;

VertexPtr buildVertex(double x, double y, double z);
void destroyVertex(VertexPtr vertex);

#endif //INC_3D_VIEWER_VERTEX_H
