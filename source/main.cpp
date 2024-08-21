#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/main_header.h"

int main() {

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("%s\n", TestsMessenger(RunTests(1, 1, 0, -4, -2, 2, 2)));
    printf("%s\n", TestsMessenger(RunTests(2, 0, 0, 0, 0, 0, -1)));
    printf("%s\n", TestsMessenger(RunTests(3, 0, 0, -4, 0, 0, 0)));
    printf("%s\n", TestsMessenger(RunTests(4, 0, 4, -4, 0, 1, 1)));
    printf("%s\n", TestsMessenger(RunTests(5, 0, 1, 0, 0, 0, 1)));
    printf("%s\n", TestsMessenger(RunTests(6, 1, 0, 0, 0, 0, 1)));
    printf("%s\n", TestsMessenger(RunTests(7, 1, 1, 0, -1, 0, 2)));

    Errors error = Insert(&a, 1);
    PRINT_ERROR_STRING(error);
    error = Insert(&b, 2);
    PRINT_ERROR_STRING(error);
    error = Insert(&c, 3);
    PRINT_ERROR_STRING(error);

    nRoots num_roots = Solver(a, b, c, &x1, &x2);

    PrintAnswer(num_roots, &x1, &x2);

    return 0;
}
