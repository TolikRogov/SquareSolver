/**
 * \file utilities.h
 * \brief file contains additional functions, structures and enumerations for another files
 */

#ifndef UTILITIES_INCLUDE
#define UTILITIES_INCLUDE

#define ASSERT(condition) ({                                     \
    Assert(condition, __FILE__, __LINE__, __PRETTY_FUNCTION__); \
})

/**
 * \var const double SS_MIN_VAL
 * \brief a constant containing a value with which variables of type double are compared to avoid errors due to the corresponding type
 */
const double Eps = 1e-6;

/**
 * \struct Colors
 * \brief a structure containing escape-subsequence for each color for display in terminal
 */
struct Colors {
    char red[20];           /**< escape-subsequence for red color */
    char green[20];         /**< escape-subsequence for green color */
    char blue[20];          /**< escape-subsequence for blue color */
    char yellow[20];        /**< escape-subsequence for yellow color */
    char pink[20];          /**< escape-subsequence for pink color */
    char teal[20];          /**< escape-subsequence for teal color */
    char white[20];         /**< escape-subsequence for white color */
    char red_bold[20];      /**< escape-subsequence for red_bold color */
    char green_bold[20];    /**< escape-subsequence for green_bold color */
    char blue_bold[20];     /**< escape-subsequence for blue_bold color */
    char yellow_bold[20];   /**< escape-subsequence for yellow_bold color */
    char pink_bold[20];     /**< escape-subsequence for pink_bold color */
    char teal_bold[20];     /**< escape-subsequence for teal_bold color */
    char white_bold[20];    /**< escape-subsequence for white_bold color */
    char end[20];           /**< escape-subsequence for default color */
};

/**
 * \var const Colors colors
 * \brief initialization the constant structure of type Colors
*/
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

/**
 * \enum Errors
 * \brief an enumeration containing variables indicating the type of error with which the program terminates
 */
typedef enum {
    NO_ERROR,               /**< no error */
    WRONG_READING,          /**< error after entering coefficients of a quadratic equation three times with the wrong data type */
    UNDEFINED_NUMBER_ROOTS  /**< the cause of the program error is not determined */
} Errors;

typedef enum {
    FAILED_ASSERT,
    CORRECT_ASSERT
} Assertion;

Assertion Assert(int condition, const char file_name[], int line, const char func_name[]);

/**
 * \fn void ClearBuffer()
 * \brief a function waiting for a new line or end of file when entering quadratic equation coefficient values ​​with the wrong data type
 */
void ClearBuffer();

/**
 * \fn int NearZero(double n)
 * \brief a function that compares the values ​​of double variables with a very small value to determine whether the variable's value is close to zero, taking into account the double error
 * \param n - a variable whose value is close to zero needs to be determined
 * \returns 1 - if the value of variable is near to zero
            <br>0 - if the value of variable is far from zero
 */
int NearZero(double n);

/**
 * \fn const char* ErrorsMessenger(Errors error)
 * \brief converts an error of type Errors to a string
 * \param error - a value of error of type Errors
 * \return a string indicating the error value
 */
const char* ErrorsMessenger(Errors error);

#endif // UTILITIES_INCLUDE
