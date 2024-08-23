#ifndef SOLVE_INCLUDE
#define SOLVE_INCLUDE

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

enum nRoots - an enumeration containing integer variables indicating the number of roots of a quadratic equation:

    INF_ROOTS = -1 - infinite number of roots
    NO_ROOTS  =  0 - no roots
    ONE_ROOT  =  1 - one root
    TWO_ROOTS =  2 - two roots

-----------------------------------------------------------------------------*/

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

/*-----------------------------------------------------------------------------

struct Coeff - a structure containing coefficients of a quadratic equation:

    a - first coefficient of equation
    b - second coefficient of equation
    c - third coefficient of equation

-----------------------------------------------------------------------------*/

struct Coeff {
    double a;
    double b;
    double c;
};

/*-----------------------------------------------------------------------------

struct Solvers - a structure containing values of roots and their quantity:

    x1        - first root of equation, always less then x2
    x2        - second root of equation
    num_roots - number of roots

-----------------------------------------------------------------------------*/

struct Solvers {
    double x1;
    double x2;
    nRoots num_roots;
    Tests status;
};

/*-----------------------------------------------------------------------------

Function Solver() - a function that triggers the solution of a linear or quadratic equation depending on the value of parameter a:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to an equation of type nRoots

-----------------------------------------------------------------------------*/

nRoots Solver(Coeff* coeff, Solvers* solutions);

/*-----------------------------------------------------------------------------

Function SolveLine() - a function that solutes a linear equation:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to the linear equation of type nRoots

-----------------------------------------------------------------------------*/

nRoots SolveLine(Coeff* coeff, Solvers* solutions);

/*-----------------------------------------------------------------------------

Function SolveSquare() - a function that solutes a quadratic equation:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to the quadratic equation of type nRoots

-----------------------------------------------------------------------------*/

nRoots SolveSquare(Coeff* coeff, Solvers* solutions);

#endif // SOLVE_INCLUDE
