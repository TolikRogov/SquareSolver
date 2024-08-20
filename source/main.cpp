#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/header.h"

#define PRINT_ERROR_STRING(err)({             \
    if (err != NO_ERROR) {                    \
        printf("%s\n", ErrorsMessenger(err)); \
        return 0;                             \
    }})

int main() {

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

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
