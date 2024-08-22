#ifndef SOLVE_INCLUDE
#define SOLVE_INCLUDE

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

/*-----------------------------------------------------------------------------

enum nRoots - an enumeration containing integer variables indicating the number of roots of a quadratic equation:

    INF_ROOTS = -1 - infinite number of roots
    NO_ROOTS  =  0 - no roots
    ONE_ROOT  =  1 - one root
    TWO_ROOTS =  2 - two roots

-----------------------------------------------------------------------------*/

struct Coeff {
    double a;
    double b;
    double c;
};

/*-----------------------------------------------------------------------------

struct Coeff - a structure containing coefficients of a quadratic equation:

    a - first coefficient of equation
    b - second coefficient of equation
    c - third coefficient of equation

-----------------------------------------------------------------------------*/

struct Solvers {
    double x1;
    double x2;
    nRoots num_roots;
};

/*-----------------------------------------------------------------------------

struct Solvers - a structure containing values of roots and their quantity:

    x1        - first root of equation, always less then x2
    x2        - second root of equation
    num_roots - number of roots

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

struct Test - a structure containing parameters for the function RunTests():

    n_test        - number of test
    a             - first coefficient of equation
    b             - second coefficient of equation
    c             - third coefficient of equation
    x1_right      - correct value of the first root
    x2_right      - correct value of the second root
    n_roots_right - correct value of the number of roots

-----------------------------------------------------------------------------*/

nRoots Solver(Coeff* coeff, Solvers* solutions);

/*-----------------------------------------------------------------------------

Function Solver() - a function that triggers the solution of a linear or quadratic equation depending on the value of parameter a:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to an equation of type nRoots

-----------------------------------------------------------------------------*/

nRoots SolveLine(Coeff* coeff, Solvers* solutions);

/*-----------------------------------------------------------------------------

Function SolveLine() - a function that solutes a linear equation:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to the linear equation of type nRoots

-----------------------------------------------------------------------------*/

nRoots SolveSquare(Coeff* coeff, Solvers* solutions);

/*-----------------------------------------------------------------------------

Function SolveSquare() - a function that solutes a quadratic equation:

    Coeff* coeff       - pointer to structure of type Coeff
    Solvers* solutions - pointer to structure of type Solvers

returns number of solutions to the quadratic equation of type nRoots

-----------------------------------------------------------------------------*/

#endif // SOLVE_INCLUDE
