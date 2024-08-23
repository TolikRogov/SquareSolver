#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE

#include "solve.h"

/*-----------------------------------------------------------------------------

enum Tests - an enumeration containing variables indicating status of the next running test:

    FAILED_TEST  - test failed
    CORRECT_TEST - test passed

-----------------------------------------------------------------------------*/

typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

/*-----------------------------------------------------------------------------

struct Test - a structure containing parameters for the function RunTests():

    n_test        - number of test
    a             - first coefficient of equation
    b             - second coefficient of equation
    c             - third coefficient of equation
    x1_right      - correct value of the first root
    x2_right      - correct value of the second root
    n_roots_right - correct value of the number of roots

-----------------------------------------------------------------------------*/

struct Test {
    int n_test;
    double a;
    double b;
    double c;
    double x1_right;
    double x2_right;
    int n_roots_right;
};

/*-----------------------------------------------------------------------------

Function Tester() - a function containing the massive of structures of type Test and run them using functions RunTests() and TestsMessenger()

-----------------------------------------------------------------------------*/

void Tester();

/*-----------------------------------------------------------------------------

Function RunTests() - a function checking the operation of the algorithm for solving a quadratic equation:

    Test* controller - a pointer to a structure of type Test

return status of the next running test of type Test

-----------------------------------------------------------------------------*/

Tests RunTests(Test* controller);

/*-----------------------------------------------------------------------------

Function TestsMessenger() - converts an status of test of type Test to a string:

    test - a value of status of test of type Test

return a string indicating the status of test

-----------------------------------------------------------------------------*/

const char* TestsMessenger(Tests test);

#endif // TESTER_INCLUDE
