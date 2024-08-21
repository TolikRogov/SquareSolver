#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/tester_header.h"

void Tester(){
    printf("%s\n", TestsMessenger(RunTests(1, 1, 0, -4, -2, 2, 2)));
    printf("%s\n", TestsMessenger(RunTests(2, 0, 0, 0, 0, 0, -1)));
    printf("%s\n", TestsMessenger(RunTests(3, 0, 0, -4, 0, 0, 0)));
    printf("%s\n", TestsMessenger(RunTests(4, 0, 4, -4, 0, 1, 1)));
    printf("%s\n", TestsMessenger(RunTests(5, 0, 1, 0, 0, 0, 1)));
    printf("%s\n", TestsMessenger(RunTests(6, 1, 0, 0, 0, 0, 1)));
    printf("%s\n", TestsMessenger(RunTests(7, 1, 1, 0, -1, 0, 2)));
    printf("%s\n", TestsMessenger(RunTests(8, 1, 1, -2, -2, 1, 2)));
}

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
