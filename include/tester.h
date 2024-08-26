/**
 * \file tester.h
 * \brief file contains functions and structures for running unit-tests
 */

#ifndef TESTER_INCLUDE
#define TESTER_INCLUDE

#include "solve.h"

/**
 * \struct Test
 * \brief a structure containing parameters for the function RunTests()
 */
struct Test {
    int n_test;         /**< number of test */
    double a;           /**< first coefficient of equation */
    double b;           /**< second coefficient of equation */
    double c;           /**< third coefficient of equation */
    double x1_right;    /**< correct value of the first root */
    double x2_right;    /**< correct value of the second root */
    int n_roots_right;  /**< correct value of the number of roots */
};

/**
 * \fn void Tester()
 * \brief a function containing the massive of structures of type Test and run them using functions RunTests() and TestsMessenger()
 */
void Tester();

/**
 * \fn Solution RunTests(Test* controller)
 * \brief a function checking the operation of the algorithm for solving a quadratic equation
 * \param Test* controller - a pointer to a structure of type Test
 * \return status of the next running test of type Test
 */
Solution RunTests(Test* controller);

/**
 * \fn const char* TestsMessenger(Tests test)
 * \brief converts an status of test of type Test to a string
 * \param Tests test - a value of status of test of type Test
 * \return a string indicating the status of test
 */
const char* TestsMessenger(Tests test);

#endif // TESTER_INCLUDE
