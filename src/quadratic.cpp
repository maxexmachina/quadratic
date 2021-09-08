#include <cmath>
#include <cassert>
#include <cstdio>

#define INF_ROOTS 3 
#define EPSILON 1e-6

//------------------------------------------------------------ 
//! Solves the quadratic equation ax^2 + bx + c = 0
//!
//! @param[in]  a   a-coefficient
//! @param[in]  b   b-coefficient
//! @param[in]  c   c-coefficient
//! @param[in]  x1  Pointer to the 1st root
//! @param[in]  x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In the case of infinite roots returns INF_ROOTS
//------------------------------------------------------------ 

size_t solveQuadratic(double a, double b, double c, double *x1, double *x2); 

size_t solveQuadratic(double a, double b, double c,
                      double *x1, double *x2) {

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (a < EPSILON) {
        if (b < EPSILON) {
            return (c < EPSILON) ? INF_ROOTS : 0;
        } else { 
            *x1 = -c / b;
            return 1; 
        }
    } else {
        const double d = b * b - 4 * a * c;
        if (d < 0) {
            return 0;
        }
        const double sqrtD = sqrt(d);
        *x1 = (-b + sqrtD) / (2 * a);
        *x2 = (-b - sqrtD) / (2 * a);
        return 2;
    }
} 

int main(void) {
    printf("This program solves a quadratic equation with given coefficients\n");
    printf("Please enter a, b and c coefficients:\n");

    double a, b, c;
    scanf("%lg %lg %lg", &a, &b, &c);
    assert(std::isfinite(a));
    assert(std::isfinite(b));
    assert(std::isfinite(c));

    double x1, x2;
    const size_t nRoots = solveQuadratic(a, b, c, &x1, &x2);

    switch (nRoots) {
        case 0:
            printf("Given equation has no real solutions\n");
            break;
        case 1:
            printf("The only equation solution is %lg\n", x1);
            break;
        case 2:
            printf("Equation solutions are %lg and %lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf("Given equation has infinite solutions\n");
            break;
        default:
            printf("There was an error in the program\n");
    }
}
