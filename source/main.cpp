#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/tester.h"
#include "../include/utilities.h"
#include "../include/in_out.h"
#include "../include/solve.h"

// TODO: 2) прочитать про header guard,а точнее  директиву ifdef

#define PRINT_ERROR_STRING(err)({              \
    if (err != NO_ERROR) {                    \
        printf("%s\n", ErrorsMessenger(err)); \
        return 0;                             \
    }})

int main() {

    Solvers solutions = {};
    Coeff coeff = {};

    Tester();

    Errors error = Insert(&coeff.a, 1);
    PRINT_ERROR_STRING(error);
    error = Insert(&coeff.b, 2);
    PRINT_ERROR_STRING(error);
    error = Insert(&coeff.c, 3);
    PRINT_ERROR_STRING(error);

    solutions.num_roots = Solver(&coeff , &solutions);

    PrintAnswer(&solutions);

    return 0;
}
