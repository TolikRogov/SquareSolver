/**
 * \file main.cpp
 * \brief main file of all program
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "../include/tester.h"
#include "../include/utilities.h"
#include "../include/in_out.h"
#include "../include/solve.h"

/*  TODO:
        1) readme,
        2) custom assert
        ?) html run
*/

/**
 * \fn int main(int argc, char* argv[])
 * \brief a function runs main functions of all program
 * \param int argc - variable contains count of parameters for running the program:
 * 1 - only program name, more then 1 - name and running keys
 * \param char* argv[] - massive of strings contains input running keys
 */
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
            printf("%s%s%s\n", colors.blue, "Enter example: ./ss "
                   "(--test or --normal)", colors.end);
            return 0;
        }
    }

    printf("%s%s%s\n", colors.red, "Error argument for running the program", colors.end);
    printf("%s%s%s\n", colors.green, "For more information about available argument run with '--help'", colors.end);

    return 0;
}
