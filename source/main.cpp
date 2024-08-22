#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "../include/tester.h"
#include "../include/utilities.h"
#include "../include/in_out.h"
#include "../include/solve.h"

//TODO: 1) Fix insert(), 2) color terminal, 3) консольный github, 4)readme

int main(int argc, char* argv[]) {

    if (argc == 2) {
        if (!strcmp(argv[1], "--test")) {
            Tester();
            return 0;
        }
        else if (!strcmp(argv[1], "--normal")) {
            Normal();
            return 0;
        }
        else if (!strcmp(argv[1], "--help")) {
            printf("Enter example: ./ss (--test or --normal) \n");
            return 0;
        }
    }

    printf("Error argument for running the program \n"
            "For more information about available argument run with '--help' \n");

    return 0;
}
