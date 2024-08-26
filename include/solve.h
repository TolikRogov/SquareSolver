/**
 * \file solve.h
 * \brief file that contains functions and enumerations required for solving quadratic equations
 */

#ifndef SOLVE_INCLUDE
#define SOLVE_INCLUDE

/**
 * \enum Tests
 * \brief an enumeration containing variables indicating status of the next running test
 */
typedef enum {
    FAILED_TEST, /**< test is failed */
    CORRECT_TEST /**< test is correct */
} Tests;

/**
 * \enum nRoots
 * \brief an enumeration containing integer variables indicating the number of roots of a quadratic equation
 */
typedef enum {
    INF_ROOTS = -1, /**< infinite number of roots */
    NO_ROOTS,       /**< no roots */
    ONE_ROOT,       /**< one root */
    TWO_ROOTS       /**< two roots */
} nRoots;

/**
 * \struct Coeff
 * \brief a structure containing coefficients of a quadratic equation
 */
struct Coeff {
    double a; /**< first coefficient of equation */
    double b; /**< second coefficient of equation */
    double c; /**< third coefficient of equation */
};

/**
 * \struct Solution
 * \brief a structure containing values of roots and their quantity
 */
struct Solution {
    double x1;          /**< first root of equation */
    double x2;          /**< second root of equation */
    nRoots num_roots;   /**< number of roots */
    Tests status;       /**< test status - failed or correct */
};

/**
 * \fn nRoots Solver(Coeff* coeff, Solution* solutions)
 * \brief a function that triggers the solution of a linear or quadratic equation depending on the value of parameter a
 * \param Coeff* coeff       - pointer to structure of type Coeff
 * \param Solution* solutions - pointer to structure of type Solvers
 * \return number of solutions to an equation of type nRoots
 */
nRoots Solver(Coeff* coeff, Solution* solutions);

/**
 * \fn nRoots SolveLine(Coeff* coeff, Solution* solutions)
 * \brief a function that solutes a linear equation
 * \param Coeff* coeff       - pointer to structure of type Coeff
 * \param Solution* solutions - pointer to structure of type Solvers
 * \return number of solutions to the linear equation of type nRoots
 */
nRoots SolveLine(Coeff* coeff, Solution* solutions);

/**
 * \fn nRoots SolveSquare(Coeff* coeff, Solution* solutions)
 * \brief a function that solutes a quadratic equation
 * \param Coeff* coeff       - pointer to structure of type Coeff
 * \param Solution* solutions - pointer to structure of type Solvers
 * \returns number of solutions to the quadratic equation of type nRoots
 */
nRoots SolveSquare(Coeff* coeff, Solution* solutions);

#endif // SOLVE_INCLUDE
