#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include "../include/solve_header.h"

// TODO: 1) структуры 2) скрипт, который собирает прогу за тебя, 3) документации

/*-------------------------------------------------------
Function GetDiscriminant:

    a - first coeff of equation
    b -

return
*/

static int GetDiscriminant(double a, double b, double c);

#define MAX(x, y)           \
    ((x) < (y)) ? (y) : (x) \

#define MIN(x, y)           \
    ((x) > (y)) ? (y) : (x) \

nRoots SolveLine(double b, double c, double *x1, double *x2) {

    assert(x1);
    assert(x2);

    if (NearZero(b)) {
        return (NearZero(c)) ? INF_ROOTS : NO_ROOTS;
    }
    else {
        *x1 = (((-c / b) < 0) ? (-c / b) : 0);
        *x2 = (((-c / b) > 0) ? (-c / b) : 0);
        return ONE_ROOT;
    }
}

static int GetDiscriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

nRoots SolveSquare(double a, double b, double c, double *x1, double *x2) {

    assert(x1);
    assert(x2);

    double d = GetDiscriminant(a, b, c);

    if(NearZero(d)) {
        *x1 = ( ( ( -b / ( 2 * a ) ) < 0 ) ? ( -b / ( 2 * a ) ) : 0 );
        *x2 = ( ( ( -b / ( 2 * a ) ) > 0 ) ? ( -b / ( 2 * a ) ) : 0 );
        return ONE_ROOT;
    }
    else if(d > 0) {
        double q = sqrt(d);
        *x2 = MAX( ( ( -b + q ) / ( 2 * a ) ), ( ( -b - q ) / ( 2 * a ) ) );
        *x1 = MIN( ( ( -b + q ) / ( 2 * a ) ), ( ( -b - q ) / ( 2 * a ) ) );
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

nRoots Solver(double a, double b, double c, double *x1, double *x2) {

    assert(x1);
    assert(x2);

    nRoots n;
    if (NearZero(a)) {
        n = SolveLine(b, c, x1, x2);
    }
    else {
        n = SolveSquare(a, b, c, x1, x2);
    }
    return n;
}
