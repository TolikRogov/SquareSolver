#pragma once

const double SS_MIN_VAL = 10e-6;

/*-----------------------------------------------------------------------------

const double SS_MIN_VAL - a constant containing a value with which variables of type double are compared to avoid errors due to the corresponding type:

-----------------------------------------------------------------------------*/

typedef enum {
    NO_ERROR,
    WRONG_READING,
    UNDEFINED_NUMBER_ROOTS
} Errors;

/*-----------------------------------------------------------------------------

enum Errors - an enumeration containing variables indicating the type of error with which the program terminates:

    NO_ERROR               = 0  - no error
    WRONG_READING          = 1  - error after entering coefficients of a quadratic equation three times with the wrong data type
    UNDEFINED_NUMBER_ROOTS = 2  - the cause of the program error is not determined

-----------------------------------------------------------------------------*/

void ClearBuffer();

/*-----------------------------------------------------------------------------

Function ClearBuffer() - a function waiting for a new line or end of file when entering quadratic equation coefficient values ​​with the wrong data type

-----------------------------------------------------------------------------*/

int NearZero(double n);

/*-----------------------------------------------------------------------------

Function NearZero() - a function that compares the values ​​of double variables with a very small value to determine whether the variable's value is close to zero, taking into account the double error:

    n - a variable whose value is close to zero needs to be determined

return 1 - if the value of variable is near to zero
       0 - if the value of variable is far from zero

-----------------------------------------------------------------------------*/

const char* ErrorsMessenger(Errors error);

/*-----------------------------------------------------------------------------

Function ErrorsMessenger() - converts an error of type Errors to a string:

    error - a value of error of type Errors

return a string indicating the error value

-----------------------------------------------------------------------------*/
