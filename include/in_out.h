#ifndef IN_OUT_INCLUDE
#define IN_OUT_INCLUDE

#include "utilities.h"
#include "solve.h"

/*-----------------------------------------------------------------------------

Function Normal() - a function that runs SolveSquare with user's coefficients:

return output outcome - without (1) or with (0) error

-----------------------------------------------------------------------------*/

int Normal();

/*-----------------------------------------------------------------------------

Function PrintAnswer() - outputs the solution to the quadratic equation of the Solver() function:

    Solvers* solutions - a pointer to structure of type Solvers

return output outcome - without or with error

-----------------------------------------------------------------------------*/

Errors PrintAnswer(Solvers* solutions);

/*-----------------------------------------------------------------------------

Function Insert() - accepts from the user the values ​​of the coefficients of a quadratic equation in the correct data type:

    double* coeff - a pointer to variable containing value of next input coefficient
	cnt 		  - a number of next input coefficient

return input outcome - without or with error

-----------------------------------------------------------------------------*/

Errors Insert(double *coeff, int cnt);

#endif // IN_OUT_INCLUDE
