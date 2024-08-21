#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/in_out_header.h"

Errors PrintAnswer(nRoots num_roots, double *x1, double *x2) {
    switch(num_roots) {
        case NO_ROOTS: {
            printf("No roots \n");
            break;
        }
        case ONE_ROOT: {
            printf("One root \n");
            printf("x = %lg \n", *x1);
            break;
        }
        case TWO_ROOTS: {
            printf("Two roots \n");
            printf("x1 = %lg \n", *x1);
            printf("x2 = %lg \n", *x2);
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

Errors Insert(double *coeff, int cnt) {

    printf("# Enter coefficient №%d: ", cnt);
    int k = 0;
    while (scanf("%lg", coeff) != 1) {
        ClearBuffer();
        ++k;
        if(k > 2) return WRONG_READING;

        printf("# Error coefficient data type \n");
        printf("# Enter coefficient №%d with right data type: ", cnt);
    }
    return NO_ERROR;
}
