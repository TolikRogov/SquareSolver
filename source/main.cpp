/**
 * \file main.cpp
 * \brief main file of all program
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "../include/tester.hpp"
#include "../include/utilities.hpp"
#include "../include/in_out.hpp"
#include "../include/solve.hpp"

/**
 * \fn int main(int argc, char* argv[])
 * \brief a function runs main functions of all program
 * \param int argc - variable contains count of parameters for running the program:
 * 1 - only program name, more then 1 - name and running keys
 * \param char* argv[] - massive of strings contains input running keys
 */
int main(int argc, char* argv[]) {

    if (argc == 2) {
        if (!strcmp(argv[1], flags.tester)) {
            Tester();
            return 0;
        }
        else if (!strcmp(argv[1], flags.normal)) {
            Normal();
            return 0;
        }
        else if (!strcmp(argv[1], flags.helper)) {
            Helper();
            return 0;
        }
        else if (!strcmp(argv[1], flags.docker)) {
            Docker();
            return 0;
        }
    }

    printf("%s%s%s\n", colors.red, "Error argument for running the program", colors.end);
    printf("%s%s%s\n", colors.green, "For more information about available argument run with '--help'", colors.end);

    return 0;
}
