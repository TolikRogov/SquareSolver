#ifndef UTILITIES_INCLUDE
#define UTILITIES_INCLUDE

/*-----------------------------------------------------------------------------

const double SS_MIN_VAL - a constant containing a value with which variables of type double are compared to avoid errors due to the corresponding type:

-----------------------------------------------------------------------------*/

const double eps = 1e-6;

struct Colors {
    char red[20];
    char green[20];
    char blue[20];
    char yellow[20];
    char pink[20];
    char teal[20];
    char white[20];
    char red_bold[20];
    char green_bold[20];
    char blue_bold[20];
    char yellow_bold[20];
    char pink_bold[20];
    char teal_bold[20];
    char white_bold[20];
    char end[20];
};

const Colors colors = { .red         = "\033[0;31m",
                        .blue        = "\033[0;34m",
                        .green       = "\033[0;32m",
                        .yellow      = "\033[0;33m",
                        .pink        = "\033[0;35m",
                        .teal        = "\033[0;36m",
                        .white       = "\033[0;36m",
                        .red_bold    = "\033[31;1m",
                        .green_bold  = "\033[32;1m",
                        .yellow_bold = "\033[33;1m",
                        .blue_bold   = "\033[34;1m",
                        .pink_bold   = "\033[35;1m",
                        .teal_bold   = "\033[36;1m",
                        .white_bold  = "\033[37;1m",
                        .end         = "\033[0;0m"  };

/*-----------------------------------------------------------------------------

enum Errors - an enumeration containing variables indicating the type of error with which the program terminates:

    NO_ERROR               = 0  - no error
    WRONG_READING          = 1  - error after entering coefficients of a quadratic equation three times with the wrong data type
    UNDEFINED_NUMBER_ROOTS = 2  - the cause of the program error is not determined

-----------------------------------------------------------------------------*/

typedef enum {
    NO_ERROR,
    WRONG_READING,
    UNDEFINED_NUMBER_ROOTS
} Errors;

/*-----------------------------------------------------------------------------

Function ClearBuffer() - a function waiting for a new line or end of file when entering quadratic equation coefficient values ​​with the wrong data type

-----------------------------------------------------------------------------*/

void ClearBuffer();

/*-----------------------------------------------------------------------------

Function NearZero() - a function that compares the values ​​of double variables with a very small value to determine whether the variable's value is close to zero, taking into account the double error:

    n - a variable whose value is close to zero needs to be determined

return 1 - if the value of variable is near to zero
       0 - if the value of variable is far from zero

-----------------------------------------------------------------------------*/

int NearZero(double n);

/*-----------------------------------------------------------------------------

Function ErrorsMessenger() - converts an error of type Errors to a string:

    error - a value of error of type Errors

return a string indicating the error value

-----------------------------------------------------------------------------*/

const char* ErrorsMessenger(Errors error);

#endif // UTILITIES_INCLUDE
