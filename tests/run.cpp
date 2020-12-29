#include <vector>
#include "test-case.h"
#include "object/vertex-test.h"

unsigned int TestCase::errorCount = 0;

int main() {
    TestCase* testCases[] = {
        new VertexTest,
    };

    for(auto& testCase : testCases) {
        testCase->run();
        delete testCase;
    }

    return TestCase::logResults();
}
