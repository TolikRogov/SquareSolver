#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "../include/tester.h"
#include "../include/utilities.h"
#include "../include/in_out.h"
#include "../include/solve.h"

#define PRINT_ERROR_STRING(err)({              \
    if (err != NO_ERROR) {                    \
        printf("%s\n", ErrorsMessenger(err)); \
        return 0;                             \
    }})

int main(int argc, const char* argv[]) {

    Solvers solutions = {};
    Coeff coeff = {};

    if (argc == 2) {
        if (!strcmp(argv[1], "--test")) {
            Tester();
        }
        else if (!strcmp(argv[1], "--normal")) {
            Errors error = Insert(&coeff.a, 1);
            PRINT_ERROR_STRING(error);
            error = Insert(&coeff.b, 2);
            PRINT_ERROR_STRING(error);
            error = Insert(&coeff.c, 3);
            PRINT_ERROR_STRING(error);

            solutions.num_roots = Solver(&coeff , &solutions);

            PrintAnswer(&solutions);
        }
        else if (!strcmp(argv[1], "--help")) {
            printf("Enter example: ./ss (--test or --normal)");
        }
        else {
            printf("Error argument for running the program \n"
                   "For more information enter '--help' \n");
            return 0;
        }
    }
    else {
        printf("Error argument for running the program \n"
               "For more information enter '--help' \n");
        return 0;
    }

    return 0;
}
