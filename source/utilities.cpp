#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/utilities_header.h"

Tests RunTests(int n_test, double a, double b, double c, double x1_right, double x2_right, int n_roots_right) {
    double x1 = 0, x2 = 0;
    nRoots n_roots = Solver(a, b, c, &x1, &x2);

    printf("%d: ", n_test);

    if (n_roots != n_roots_right || x1 != x1_right || x2 != x2_right) {
        printf("a = %lg, b = %lg, c = %lg \n"
        "x1 = %lg, x2 = %lg, n_roots = %d \n"
        "x1_right = %lg, x2_right = %lg, n_roots_right = %d \n",
        a, b, c, x1, x2, n_roots, x1_right, x2_right, n_roots_right);
        return FAILED_TEST;
    }
    return CORRECT_TEST;
}

const char* TestsMessenger(Tests test) {
    switch(test) {
        case FAILED_TEST:  return "FAILED_TEST";
        case CORRECT_TEST: return "CORRECT_TEST";
        default:           return "UNDEFINED_ERROR";
    }
}

const char* ErrorsMessenger(Errors error) {
    switch(error) {
        case NO_ERROR:               return "NO_ERROR";
        case WRONG_READING:          return "WRONG_READING";
        case UNDEFINED_NUMBER_ROOTS: return "UNDEFINED_NUMBER_ROOTS";
        default:                     return "UNDEFINED_ERROR";
    }
}

void ClearBuffer() {
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int NearZero(double n) {
    return fabs(n) < SS_MIN_VAL;
}
