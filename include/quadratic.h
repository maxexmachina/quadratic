#ifndef QUADRATIC_H
#define QUADRATIC_H

//! Determines the precision of comparison in isEqualDouble function
const double EPSILON = 1e-2;

//! Enum type with different possible
//! return values of the solveQuadratic function
enum NRoots {
    ZERO = 0,
    ONE = 1,
    TWO = 2,
    INF_ROOTS = 3
};

//------------------------------------------------------------ 
//! Solves the quadratic equation ax^2 + bx + c = 0
//!
//! @param[in]   a   a-coefficient
//! @param[in]   b   b-coefficient
//! @param[in]   c   c-coefficient
//! @param[out]  x1  Pointer to the 1st root
//! @param[out]  x2  Pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In the case of infinite roots returns INF_ROOTS
//------------------------------------------------------------ 
NRoots solveQuadratic(const double a, const double b, const double c, double *x1, double *x2); 

//------------------------------------------------------------ 
//! Solves linear equation ax + b = 0
//!
//! @param[in]  a   a-coefficient
//! @param[in]  b   b-coefficient
//!
//! @return Value of x
//------------------------------------------------------------ 
double solveLinear(const double a, const double b);

//------------------------------------------------------------ 
//! Determines if two double precision floats are equal
//! 
//! @param[in]  lhs First number
//! @param[in]  rhs Second number
//!
//! @return true if numbers are equal, false otherwise 
//!
//! @note Comparison is performed with the accuracy of EPSILON
//------------------------------------------------------------ 
bool isEqualDouble(const double lhs, const double rhs);

//------------------------------------------------------------ 
//! Gets equation coefficients from the standard input 
//!
//! @param[out] a   Pointer to a-coefficient
//! @param[out] b   Pointer to b-coefficient
//! @param[out] c   Pointer to c-coefficient
//!
//! @return 1 if operation was successful, 0 otherwise 
//------------------------------------------------------------ 
int getCoefsFromInput(double *a, double *b, double *c);

//------------------------------------------------------------ 
//! Prints program result to the standard output
//! @param[in]  nRoots   Number of roots in the solution
//! @param[in]  x1       First root
//! @param[in]  x2       Second root
//------------------------------------------------------------ 
void printResult(const NRoots nRoots, const double x1, const double x2);

//------------------------------------------------------------ 
//! Prints quadratic equation ax^2 + bx + c = 0 with given coefficients
//! 
//! @param[in]  a   a-coefficient
//! @param[in]  b   b-coefficient
//! @param[in]  c   c-coefficient
//------------------------------------------------------------ 
void printEquation(const double a, const double b, const double c);

#endif
