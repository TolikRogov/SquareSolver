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

struct Test {
    int n_test;
    double a;
    double b;
    double c;
    double x1_right;
    double x2_right;
    int n_roots_right;
};

nRoots Solver(Coeff* coeff, Solvers* solutions);
nRoots SolveLine(Coeff* coeff, Solvers* solutions);
nRoots SolveSquare(Coeff* coeff, Solvers* solutions);
