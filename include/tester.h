#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE

#include "solve.h"

typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

/*-----------------------------------------------------------------------------

enum Tests - an enumeration containing variables indicating status of the next running test:

    FAILED_TEST  - test failed
    CORRECT_TEST - test passed

-----------------------------------------------------------------------------*/

void Tester();

/*-----------------------------------------------------------------------------

Function Tester() - a function containing the massive of structures of type Test and run them using functions RunTests() and TestsMessenger()

-----------------------------------------------------------------------------*/

Tests RunTests(Test* controller);

/*-----------------------------------------------------------------------------

Function RunTests() - a function checking the operation of the algorithm for solving a quadratic equation:

    Test* controller - a pointer to a structure of type Test

return status of the next running test of type Test

-----------------------------------------------------------------------------*/

const char* TestsMessenger(Tests test);

/*-----------------------------------------------------------------------------

Function TestsMessenger() - converts an status of test of type Test to a string:

    test - a value of status of test of type Test

return a string indicating the status of test

-----------------------------------------------------------------------------*/

#endif // TESTER_INCLUDE
