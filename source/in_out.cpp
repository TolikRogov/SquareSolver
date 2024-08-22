#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include "../include/in_out.h"

#define PRINT_ERROR_STRING(err)({              \
    if (err != NO_ERROR) {                    \
        printf("%s\n", ErrorsMessenger(err)); \
        return 0;                             \
    }})

int Normal() {

    Solvers solutions = {};
    Coeff coeff = {};

    Errors error = Insert(&coeff.a, 1);
    PRINT_ERROR_STRING(error);
    error = Insert(&coeff.b, 2);
    PRINT_ERROR_STRING(error);
    error = Insert(&coeff.c, 3);
    PRINT_ERROR_STRING(error);

    solutions.num_roots = Solver(&coeff , &solutions);

    PrintAnswer(&solutions);

    return 1;
}

Errors PrintAnswer(Solvers* solutions) {

    assert(solutions);
    assert(solutions);

    switch(solutions->num_roots) {
        case NO_ROOTS: {
            printf("No roots \n");
            break;
        }
        case ONE_ROOT: {
            printf("One root \n");
            printf("x = %lg \n", solutions->x1);
            break;
        }
        case TWO_ROOTS: {
            printf("Two roots \n");
            printf("x1 = %lg \n", solutions->x1);
            printf("x2 = %lg \n", solutions->x2);
            break;
        }
        case INF_ROOTS: {
            printf("Infinite amount of roots \n");
            break;
        }
        default: {
            printf("main(): ERROR: amount of roots is not defined");
            return UNDEFINED_NUMBER_ROOTS;
        }
    }
    return NO_ERROR;
}

Errors Insert(double* coeff, int cnt) {

    assert(coeff);

    printf("# Enter coefficient №%d: ", cnt);
    int k = 0;
    char str[] = "";
    scanf("%s", str);
    while (NumberChecker(str) != NUMBER) {

        ClearBuffer();
        printf("%d \n", k);
        ++k;
        if(k > 2) return WRONG_READING;

        printf("# Error coefficient data type \n");
        printf("# Enter coefficient №%d with right data type: ", cnt);

        scanf("%s", str);
    }
    char* end_str;
    *coeff = strtod(str, &end_str);
    return NO_ERROR;
}
