#ifndef TEST_H
#define TEST_H

#include <stddef.h>

//! Encapsulates the set of values needed for testing
typedef struct testCase {
    size_t id;     /**< Test id */
    double a;      /**< a-coefficient */
    double b;      /**< b-coefficient */
    double c;      /**< c-coefficient */
    size_t nRoots; /**< Expected number of roots */
    double x1;     /**< Expected first root */
    double x2;     /**< Expected second root */
} testCase;

//------------------------------------------------------------ 
//! Checks result of solveQuadratic function against test values
//!
//! @param[in]  test    Struct, encapsulating test info, equation coefficients and expected values
//!
//! @return 1 if test is successful, 0 otherwise
//------------------------------------------------------------ 
int checkTestCase(const testCase test);

//------------------------------------------------------------ 
//! Parses test cases from a file and runs them with checkTestCase
//!
//! @param[in]  path    Path to file, containing test cases 
//!
//! @return 1 if all tests were successful, 0 otherwise
//------------------------------------------------------------ 
int runTests(const char* path);

#endif
