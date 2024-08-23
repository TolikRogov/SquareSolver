#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/tester.h"
#include "../include/utilities.h"

void Tester(){
                    //  n_test, a, b,  c,  x1_right, x2_right, n_roots_right
    struct Test list[] = {  {1, 1, 0, -4, -2,   2,    2},
                            {2, 0, 0,  0,  NAN, NAN, -1},
                            {3, 0, 0, -4,  NAN, NAN,  0},
                            {4, 0, 4, -4,  1,   NAN,  1},
                            {5, 0, 1,  0,  0,   NAN,  1},
                            {6, 1, 0,  0,  0,   NAN,  1},
                            {7, 1, 1,  0, -1,   0,    2},
                            {8, 1, 1, -2, -2,   1,    2},
                            {9, 1e-3, -2e-3, 1, NAN, NAN, 0},
                            {10, -1e-3, -2e-3, 1, -32.638584, 30.638584, 2} };

    for (size_t i = 0; i < (sizeof(list) / sizeof(list[0])); ++i) {
        Solvers solutions = RunTests(&list[i]);
        switch(solutions.status) {
            case FAILED_TEST:{
                printf("%s%s%s\n", colors.red, TestsMessenger(solutions.status), colors.end);
                printf("%sa = %lg, b = %lg, c = %lg\nx1 = %.10lg, x2 = %.10lg, n_roots = %d\nx1_right = %.10lg, x2_right = %.10lg, n_roots_right = %d%s\n", colors.yellow, list[i].a, list[i].b, list[i].c, solutions.x1, solutions.x2, solutions.num_roots,
                list[i].x1_right, list[i].x2_right, list[i].n_roots_right, colors.end);
                break;
            }
            case CORRECT_TEST: {
                printf("%s%s%s\n", colors.green, TestsMessenger(solutions.status), colors.end);
                break;
            }
            default: {
                printf("%s%s%s", colors.red, "UNDEFINED_ERROR", colors.end);
                break;
            }
        }
    }
}

Solvers RunTests(Test* controller) {
    Coeff coeff = { controller->a, controller->b, controller->c };
    Solvers solutions = {.status = CORRECT_TEST};
    nRoots n_roots = Solver(&coeff, &solutions);

    printf("%s%2d: ", colors.teal_bold, controller->n_test);

    if (n_roots != controller->n_roots_right ||
    fabs(solutions.x1 - controller->x1_right) > eps ||
    fabs(solutions.x2 - controller->x2_right) > eps) {
        solutions.status = FAILED_TEST;
    }
    return solutions;
}

const char* TestsMessenger(Tests test) {
    switch(test) {
        case FAILED_TEST:  return "FAILED_TEST";
        case CORRECT_TEST: return "CORRECT_TEST";
        default:           return "UNDEFINED_ERROR";
    }
}
