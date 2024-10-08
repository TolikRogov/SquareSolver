/**
 * \file in_out.cpp
 * \brief file is responsible for input and output information required for solving any quadratic equation
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <cstdarg>

#include "../include/in_out.hpp"

/**
 * \def PRINT_ERROR_STRING(err)
 * \brief a macros prints error message to console if there is error
 */
#define PRINT_ERROR_STRING(err)({                                          \
    if (err != NO_ERROR) {                                                \
        printf("%s%s%s\n", colors.red, ErrorsMessenger(err), colors.end); \
        return 0;                                                         \
    }})

int Normal() {

    Solution solutions = {};
    Coeff coeff = {};
    double* list_coeff[] = {&coeff.a, &coeff.b, &coeff.c};

    for (size_t i = 0; i < (sizeof(list_coeff) / sizeof(list_coeff[0])); ++i) {
        Errors error = Insert(list_coeff[i], i + 1);
        PRINT_ERROR_STRING(error);
    }

    solutions.num_roots = Solver(&coeff , &solutions);

    PrintAnswer(&solutions);

    return 1;
}

Errors PrintAnswer(Solution* solutions) {

    ASSERT((solutions != nullptr));

    switch(solutions->num_roots) {
        case NO_ROOTS: {

            printf("%s%s%s\n", colors.red, "No roots", colors.end);

            break;
        }
        case ONE_ROOT: {

            printf("%s%s%s\n", colors.teal_bold, "One root", colors.end);
            printf("%sx = %lg%s\n", colors.yellow, solutions->x1, colors.end);

            break;
        }
        case TWO_ROOTS: {

            printf("%s%s%s\n", colors.teal_bold, "Two roots", colors.end);
            printf("%sx1 = %lg%s\n", colors.green, solutions->x1, colors.end);
            printf("%sx2 = %lg%s\n", colors.green, solutions->x2, colors.end);

            break;
        }
        case INF_ROOTS: {

            printf("%s%s%s\n", colors.pink, "Infinite amount of roots", colors.end);

            break;
        }
        default: {

            printf("%s%s%s\n", colors.red, "main(): ERROR: amount of roots is not defined", colors.end);

            return UNDEFINED_NUMBER_ROOTS;
        }
    }
    return NO_ERROR;
}

Errors Insert(double* coeff, size_t cnt) { //

    ASSERT((coeff != nullptr));

    printf("%s# Enter coefficient №%zu: %s", colors.blue_bold, cnt, colors.end);

    int k = 0;
    while (scanf("%lg", coeff) != 1 || getchar() != '\n') { //EOF
        ClearBuffer();
        ++k;
        if(k > 2) {return WRONG_READING;}

        printf("%s%s%s\n", colors.red, "# Error coefficient data type", colors.end);
        printf("%s# Enter coefficient №%zu with right data type: %s", colors.yellow, cnt, colors.end);

    }
    return NO_ERROR;
}
