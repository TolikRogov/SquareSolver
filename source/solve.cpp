#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>
#include "../include/solve.h"
#include "../include/utilities.h"

static int GetDiscriminant(Coeff *coeff);

#define MAX(x, y)           \
    ((x) < (y)) ? (y) : (x) \

#define MIN(x, y)           \
    ((x) > (y)) ? (y) : (x) \

nRoots SolveLine(Coeff* coeff, Solvers* solutions) {

    assert(solutions);
    assert(coeff);

    if (NearZero(coeff->b)) {
        return (NearZero(coeff->c)) ? INF_ROOTS : NO_ROOTS;
    }
    else {
        solutions->x1 = (((-coeff->c / coeff->b) < 0) ? (-coeff->c / coeff->b) : 0);
        solutions->x2 = (((-coeff->c / coeff->b) > 0) ? (-coeff->c / coeff->b) : 0);
        return ONE_ROOT;
    }
}

static int GetDiscriminant(Coeff* coeff) {
    return (coeff->b * coeff->b - 4 * coeff->a * coeff->c);
}

nRoots SolveSquare(Coeff* coeff, Solvers* solutions) {

    assert(solutions);
    assert(coeff);

    double d = GetDiscriminant(coeff);

    if(NearZero(d)) {
        solutions->x1 = ( ( ( -coeff->b / ( 2 * coeff->a ) ) < 0 ) ? ( -coeff->b / ( 2 * coeff->a ) ) : 0 );
        solutions->x2 = ( ( ( -coeff->b / ( 2 * coeff->a ) ) > 0 ) ? ( -coeff->b / ( 2 * coeff->a ) ) : 0 );
        return ONE_ROOT;
    }
    else if(d > 0) {
        double q = sqrt(d);
        solutions->x2 = MAX( ( ( -coeff->b + q ) / ( 2 * coeff->a ) ), ( ( -coeff->b - q ) / ( 2 * coeff->a ) ) );
        solutions->x1 = MIN( ( ( -coeff->b + q ) / ( 2 * coeff->a ) ), ( ( -coeff->b - q ) / ( 2 * coeff->a ) ) );
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

nRoots Solver(Coeff* coeff, Solvers* solutions) {

    assert(solutions);
    assert(coeff);

    nRoots n = NO_ROOTS;
    if (NearZero(coeff->a)) {
        n = SolveLine(coeff, solutions);
    }
    else {
        n = SolveSquare(coeff, solutions);
    }
    return n;
}
