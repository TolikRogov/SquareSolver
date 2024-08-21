#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "../include/utilities_header.h"

const char* ErrorsMessenger(Errors error) {
    switch(error) {
        case NO_ERROR:               return "NO_ERROR";
        case WRONG_READING:          return "WRONG_READING";
        case WRONG_TEST:             return "WRONG_TEST";
        case UNDEFINED_NUMBER_ROOTS: return "UNDEFINED_NUMBER_ROOTS";
        default:                     return "UNDEFINED_ERROR";
    }
}

void ClearBuffer() {
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int NearZero(double n) {
    return fabs(n) < SS_MIN_VAL;
}
