#include <stdio.h> 
#include <math.h>

#include "quadratic.h"
#include "test.h"

//#define NDEBUG_MODE

int main() {
#ifndef NDEBUG_MODE 
    printf("This program solves a quadratic equation with given coefficients\n"
           "Please enter a, b and c coefficients:\n");

    double a = NAN, b = NAN, c = NAN;

    if (!getCoefsFromInput(&a, &b, &c)) {
        printf("There was an error processing the input\n");
        return EXIT_FAILURE;
    }
    printEquation(a, b, c);

    double x1 = NAN, x2 = NAN;
    const NRoots nRoots = solveQuadratic(a, b, c, &x1, &x2);

    printResult(nRoots, x1, x2);
    return EXIT_SUCCESS;
#else 
    if (!runTests("tests.txt")) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
#endif 
}

