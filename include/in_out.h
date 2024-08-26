/**
 * \file in_out.h
 * \brief file contains functions for input and output coefficients of quadratic equations
 */

#ifndef IN_OUT_INCLUDE
#define IN_OUT_INCLUDE

#include "utilities.h"
#include "solve.h"

/**
 * \fn int Normal()
 * \brief a function that runs SolveSquare with user's coefficients
 * \return output outcome - without (1) or with (0) error
 */
int Normal();

/**
 * \fn Errors PrintAnswer(Solution* solutions)
 * \brief outputs the solution to the quadratic equation of the Solver() function
 * \param Solution* solutions - a pointer to structure of type Solvers
 * \return output outcome - without or with error
 */
Errors PrintAnswer(Solution* solutions);

/**
 * \fn Insert(double* coeff, int cnt)
 * \brief accepts from the user the values ​​of the coefficients of a quadratic equation in the correct data type
 * \param double* coeff - a pointer to variable containing value of next input coefficient
 * \param cnt 		    - a number of next input coefficient
 * \return input outcome - without or with error
 */
Errors Insert(double *coeff, size_t cnt);

#endif // IN_OUT_INCLUDE
