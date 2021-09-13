#include <math.h>
#include <stdio.h>
#include "../include/quadratic.h"
#include "../include/test.h"

int checkTestCase(tCase test) {
    double x1 = NAN, x2 = NAN;
    const NRoots nRoots = solveQuadratic(test.a, test.b, test.c, &x1, &x2);

    if (nRoots == test.nRoots) {
        if (nRoots == NRoots::INF_ROOTS || nRoots == NRoots::ZERO) {
            printf("Test %zu passed\n", test.id);
            return 1;
        } else if (nRoots == NRoots::ONE) {
            if (isEqualDouble(x1, test.x1)) {
                printf("Test %zu passed\n", test.id);
                return 1;
            } else {
                printf("Test %zu failed, ", test.id); 
                printf("Expected x1 = %lg, got x1 = %lg\n", test.x1, x1);
                return 0;
            }
        } else {
            if (isEqualDouble(x1, test.x1) && isEqualDouble(x2, test.x2)) {
                printf("Test %zu passed\n", test.id);
                return 1;
            } else {
                printf("Test %zu failed, ", test.id); 
                printf("Expected x1 = %lg, x2 = %lg, got x1 = %lg, x2 = %lg\n",
                        test.x1, test.x2, x1, x2);
                return 0;
            }
        }
    } else {
        printf("Test %zu failed, ", test.id);
        printf("Expected %zu roots, got %d roots\n", test.nRoots, nRoots);
        return 0;
    }
}

void runTests(const char* path) {
    tCase test;
    size_t nTests = 0;
    size_t nFailed = 0;

    printf("Running tests from %s\n", path);
    FILE *testFile = fopen(path, "r");
    while (fscanf(testFile, "%zu %lg %lg %lg %zu %lg %lg\n", &test.id, &test.a,
           &test.b, &test.c, &test.nRoots, &test.x1, &test.x2) != EOF) {
        ++nTests;
        if (!checkTestCase(test)) {
            ++nFailed;
        }
    }
    printf("%zu tests completed, %zu passed, %zu failed\n", nTests, nTests - nFailed, nFailed); 
    fclose(testFile);
}
