#include <stdio.h> 
#include <math.h>
#include "../include/quadratic.h"
#include "../include/test.h"

//#define NDEBUG_MODE

int main() {
    printf("This program solves a quadratic equation with given coefficients\n"
           "Please enter a, b and c coefficients:\n");

    #ifndef NDEBUG_MODE 
    double a = NAN, b = NAN, c = NAN;

    if (!getCoefsFromInput(&a, &b, &c)) {
        printf("There was an error processing the input\n");
        return 1;
    }
    printEquation(a, b, c);

    double x1 = NAN, x2 = NAN;
    const NRoots nRoots = solveQuadratic(a, b, c, &x1, &x2);

    printResult(nRoots, x1, x2);
    #else 

    runTests("tests.txt");
    #endif 
}

