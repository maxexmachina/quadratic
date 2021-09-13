#include <math.h>

typedef struct testCase {
    size_t id;
    double a;
    double b;
    double c;
    size_t nRoots;
    double x1;
    double x2;
} tCase;

int checkTestCase(tCase test);

void runTests(const char* path);
