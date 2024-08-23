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
        2) documentation doxygen
        3) custom assert
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
            printf("%s%s%s\n", colors.blue, "Enter example: ./ss (--test or --normal)", colors.end);
            return 0;
        }
    }

    printf("%s%s%s\n", colors.red, "Error argument for running the program", colors.end);
    printf("%s%s%s\n", colors.green, "For more information about available argument run with '--help'", colors.end);

    return 0;
}
