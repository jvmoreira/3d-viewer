#include <vector>
#include "test-case.h"
#include "object/vertex-test.h"
#include "object/object-test.h"

unsigned int TestCase::errorCount = 0;

int main() {
    TestCase* testCases[] = {
        new VertexTest,
        new ObjectTest,
    };

    for(auto& testCase : testCases) {
        testCase->run();
        delete testCase;
    }

    return TestCase::logResults();
}
