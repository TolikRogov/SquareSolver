/**
 * \file solve.cpp
 * \brief file is responsible for solving quadratic equation with in_out.cpp file information
 */

#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <ctype.h>

#include "../include/solve.h"
#include "../include/utilities.h"


/**
 * \fn static double GetDiscriminant(Coeff* coeff)
 * \brief a static function calculating discriminant for solving quadratic equation with none zero coefficient a
 */
static double GetDiscriminant(Coeff* coeff);

#define MAX(x, y)           \
    ((x) < (y)) ? (y) : (x) \

#define MIN(x, y)           \
    ((x) > (y)) ? (y) : (x) \

nRoots SolveLine(Coeff* coeff, Solution* solutions) {

    ASSERT((solutions != nullptr));
    ASSERT((coeff != nullptr));

    double b = coeff->b, c = coeff->c;

    if (NearZero(b)) {
        return (NearZero(c)) ? INF_ROOTS : NO_ROOTS;
    }
    else {
        solutions->x1 = (-c / b);
        solutions->x2 = NAN;
        return ONE_ROOT;
    }
}

static double GetDiscriminant(Coeff* coeff) {
    return (coeff->b * coeff->b - 4 * coeff->a * coeff->c);
}

nRoots SolveSquare(Coeff* coeff, Solution* solutions) {

    ASSERT((solutions != nullptr));
    ASSERT((coeff != nullptr));

    double d = GetDiscriminant(coeff);
    double a = coeff->a, b = coeff->b;

    if(NearZero(d)) {
        solutions->x1 = ( -b / ( 2 * a ) );
        solutions->x2 = NAN;
        return ONE_ROOT;
    }
    else if(d > 0) {
        double q = sqrt(d);
        solutions->x2 = MAX( ( ( -b + q ) / ( 2 * a ) ), ( ( -b - q ) / ( 2 * a ) ) );
        solutions->x1 = MIN( ( ( -b + q ) / ( 2 * a ) ), ( ( -b - q ) / ( 2 * a ) ) );
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

nRoots Solver(Coeff* coeff, Solution* solutions) {

    ASSERT((isfinite(coeff->a)));
    ASSERT((isfinite(coeff->b)));
    ASSERT((isfinite(coeff->c)));
    ASSERT((solutions != nullptr));
    ASSERT((coeff != nullptr));

    nRoots n = NO_ROOTS;
    if (NearZero(coeff->a)) {
        n = SolveLine(coeff, solutions);
    }
    else {
        n = SolveSquare(coeff, solutions);
    }
    return n;
}
