#ifndef INC_3D_VIEWER_TESTS_VERTEX_TEST_H
#define INC_3D_VIEWER_TESTS_VERTEX_TEST_H

#include "test-case.h"

class VertexTest final: public TestCase {
public:
    string getClassName() const final {
        return "VertexTest";
    }

    void run() const final {
        constructorTest();
        makeEdgeWithTest();
    }

private:
    void constructorTest() const;
    void makeEdgeWithTest() const;

};


#endif //INC_3D_VIEWER_TESTS_VERTEX_TEST_H
