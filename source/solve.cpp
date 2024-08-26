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

nRoots SolveLine(Coeff* coeff, Solvers* solutions) {

    Assert((solutions != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((coeff != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);

    if (NearZero(coeff->b)) {
        return (NearZero(coeff->c)) ? INF_ROOTS : NO_ROOTS;
    }
    else {
        solutions->x1 = (-coeff->c / coeff->b);
        solutions->x2 = NAN;
        return ONE_ROOT;
    }
}

static double GetDiscriminant(Coeff* coeff) {
    // assert
    return (coeff->b * coeff->b - 4 * coeff->a * coeff->c);
}

nRoots SolveSquare(Coeff* coeff, Solvers* solutions) {

    Assert((solutions != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((coeff != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);

    double d = GetDiscriminant(coeff);

    if(NearZero(d)) {
        solutions->x1 = ( -coeff->b / ( 2 * coeff->a ) );
        solutions->x2 = NAN;
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

    Assert((isfinite(coeff->a)), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((isfinite(coeff->b)), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((isfinite(coeff->c)), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((solutions != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);
    Assert((coeff != nullptr), __FILE__, __LINE__, __PRETTY_FUNCTION__);

    nRoots n = NO_ROOTS;
    if (NearZero(coeff->a)) {
        n = SolveLine(coeff, solutions);
    }
    else {
        n = SolveSquare(coeff, solutions);
    }
    return n;
}
