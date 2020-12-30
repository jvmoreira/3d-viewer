#ifndef INC_3D_VIEWER_TESTS_OBJECT_TEST_H
#define INC_3D_VIEWER_TESTS_OBJECT_TEST_H

#include <sstream>
#include "test-case.h"

using namespace std;


class ObjectTest final: public TestCase {
public:
    string getClassName() const final {
        return "ObjectTest";
    }

    void run() const final {
        constructorTest();
        getVertexesTest();
        getVertexTest();
        getRelativePositionTest();
        getVertexesCountTest();
        getFacesCountTest();
    }

private:
    void constructorTest() const;
    void getVertexesTest() const;
    void getVertexTest() const;
    void getRelativePositionTest() const;
    void getVertexesCountTest() const;
    void getFacesCountTest() const;

    static inline stringstream buildTestObjStream() ;
};


#endif //INC_3D_VIEWER_TESTS_OBJECT_TEST_H
