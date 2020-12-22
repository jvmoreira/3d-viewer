#include <stdio.h>
#include "test-case.h"

#define ERROR_COLOR "1;31m"
#define SUCCESS_COLOR "1;32m"

int errorCount = 0;
extern int mallocCount;

void setErrorMode() {
    printf("\x1b[%s", ERROR_COLOR);
}

void setSuccessMode() {
    printf("\x1b[%s", SUCCESS_COLOR);
}

void resetColorMode() {
    printf("\x1b[0m");
}

void test(int subject, const char* message) {
    if(subject != 0)
        return;

    errorCount++;

    setErrorMode();
    printf("ERROR:\t%s\n", message);
    resetColorMode();
}

void printTestResults() {
    test(!mallocCount, "The number of calls for malloc should be equal to the number of calls of free");

    if(errorCount)
        return;

    setSuccessMode();
    printf("Test suite succeeded.\n\n");
    resetColorMode();
}
