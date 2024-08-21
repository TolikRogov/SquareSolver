#pragma once

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

struct Coeff {
    double a;
    double b;
    double c;
};

struct Solvers {
    double x1;
    double x2;
    nRoots num_roots;
};

nRoots Solver(Coeff* coeff, Solvers* solutions);
nRoots SolveLine(Coeff* coeff, Solvers* solutions);
nRoots SolveSquare(Coeff* coeff, Solvers* solutions);
