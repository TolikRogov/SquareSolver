#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "../include/in_out.h"

#define PRINT_ERROR_STRING(err)({                                        \
    if (err != NO_ERROR) {                                              \
        printf("%s%s%s\n", colors.red, ErrorsMessenger(err), colors.end); \
        return 0;                                                       \
    }})

int Normal() {

    Solvers solutions = {};
    Coeff coeff = {};
    double* list_coeff[] = {&coeff.a, &coeff.b, &coeff.c};

    for (size_t i = 0; i < (sizeof(list_coeff) / sizeof(list_coeff[0])); ++i) {
        Errors error = Insert(list_coeff[i], i+1);
        PRINT_ERROR_STRING(error);
    }

    solutions.num_roots = Solver(&coeff , &solutions);

    PrintAnswer(&solutions);

    return 1;
}

Errors PrintAnswer(Solvers* solutions) {

    assert(solutions);
    assert(solutions);

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

Errors Insert(double* coeff, int cnt) {

    assert(coeff);

    printf("%s# Enter coefficient №%d: %s", colors.blue_bold, cnt, colors.end);
    int k = 0;
    while (scanf("%lg", coeff) != 1 || getchar() != '\n') {
        ClearBuffer();
        ++k;
        if(k > 2) {return WRONG_READING;}

        printf("%s%s%s\n", colors.red, "# Error coefficient data type", colors.end);
        printf("%s# Enter coefficient №%d with right data type: %s", colors.yellow, cnt, colors.end);

    }
    return NO_ERROR;
}
