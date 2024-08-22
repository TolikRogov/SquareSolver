#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/tester.h"

void Tester(){
    struct Test list[] = { {1, 1, 0, -4, -2, 2,  2},
                            {2, 0, 0,  0,  0, 0, -1},
                            {3, 0, 0, -4,  0, 0,  0},
                            {4, 0, 4, -4,  0, 1,  1},
                            {5, 0, 1,  0,  0, 0,  1},
                            {6, 1, 0,  0,  0, 0,  1},
                            {7, 1, 1,  0, -1, 0,  2},
                            {8, 1, 1, -2, -2, 1,  2} };

    for (unsigned long i = 0; i < (sizeof(list) / sizeof(list[0])); ++i) {
        printf("%s\n", TestsMessenger(RunTests(&list[i])));
    }
}

Tests RunTests(Test* controller) {
    Coeff coeff = { controller->a, controller->b, controller->c };
    Solvers solutions = {};
    nRoots n_roots = Solver(&coeff, &solutions);

    printf("%d: ", controller->n_test);

    if (n_roots != controller->n_roots_right || solutions.x1 != controller->x1_right || solutions.x2 != controller->x2_right) {
        printf("a = %lg, b = %lg, c = %lg \n"
        "x1 = %lg, x2 = %lg, n_roots = %d \n"
        "x1_right = %lg, x2_right = %lg, n_roots_right = %d \n",
        controller->a, controller->b, controller->c, solutions.x1, solutions.x2, n_roots,
        controller->x1_right, controller->x2_right, controller->n_roots_right);
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
