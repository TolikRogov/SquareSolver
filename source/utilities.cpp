/**
 * \file utilities.cpp
 * \brief file is responsible for provision additional functions for the another files
 */

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#include "../include/utilities.h"

const char* ErrorsMessenger(Errors error) {
    switch(error) {
        case NO_ERROR:               return "NO_ERROR";
        case WRONG_READING:          return "WRONG_READING";
        case UNDEFINED_NUMBER_ROOTS: return "UNDEFINED_NUMBER_ROOTS";
        default:                     return "UNDEFINED_ERROR";
    }
}

void Docker() {
    system("doxygen documentation/Doxyfile");
    system("open documentation/html/index.html");
}

void Helper() {
    printf("%s%s%s\n", colors.blue, "Enter one of acceptable mod to run the program: "
           "(--test, --normal or --dock)", colors.end);
}

void ClearBuffer() {
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int NearZero(double n) {
    return fabs(n) < EPS;
}

Assertion Assert(int condition, const char file_name[], int line, const char func_name[]) {
    if (!condition) {
        printf("%s --Assertion Fail-- file: %s, line: %d, function: %s%s \n",
               colors.red, file_name, line, func_name, colors.end);
        return FAILED_ASSERT;
    }
    return CORRECT_ASSERT;
}
