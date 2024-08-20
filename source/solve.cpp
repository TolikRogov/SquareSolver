#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/header.h"

nRoots SolveLine(double b, double c, double *x1, double *x2) {
    if (NearZero(b)) {
        return (NearZero(c))? INF_ROOTS : NO_ROOTS;
    }
    else {
        *x1 = -c / b;
        *x2 = -c / b;
        return ONE_ROOT;
    }
}

int GetDiscriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

nRoots SolveSquare(double a, double b, double c, double *x1, double *x2) {
    double d = GetDiscriminant(a, b, c);

    if(NearZero(d)) {
        *x1 = *x2 = -b / ( 2 * a );
        return ONE_ROOT;
    }
    else if(d > 0) {
        double q = sqrt(d);
        *x1 = ( -b + q ) / (2 * a);
        *x2 = ( -b - q ) / (2 * a);
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

nRoots Solver(double a, double b, double c, double *x1, double *x2) {
    nRoots n;
    if (NearZero(a)) {
        n = SolveLine(b, c, x1, x2);
    }
    else {
        n = SolveSquare(a, b, c, x1, x2);
    }
    return n;
}
