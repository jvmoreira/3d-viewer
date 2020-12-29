#ifndef INC_3D_VIEWER_TESTS_TEST_CASE_H
#define INC_3D_VIEWER_TESTS_TEST_CASE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TestCase {
private:
    static unsigned int errorCount;

public:
    virtual ~TestCase() = default;
    virtual void run() const = 0;
    virtual string getClassName() const = 0;

    static int logResults() {
        if(errorCount)
            return 1;

        logSuccess("Test suite succeeded.");
        return 0;
    }

protected:
    void test(bool expression, const string& message) const {
        if(expression)
            return;

        errorCount++;
        logError(message);
    }

    void logError(const string& message) const {
        cout << "\x1b[1;31m" << getClassName() << ": " << message << "\x1b[0m" << endl;
    }

    static void logSuccess(const string& message) {
        cout << "\x1b[1;32m" << message << "\x1b[0m" << endl;
    }
};


#endif //INC_3D_VIEWER_TESTS_TEST_CASE_H
