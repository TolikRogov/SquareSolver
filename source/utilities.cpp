#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "../include/utilities.h"

IsNumber NumberChecker(char* str) {
    printf("%s \n", str);
    for (size_t i = 0; i < strlen(str); ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+' && str[i] != '.') {
            return NOT_NUMBER;
        }
    }
    return NUMBER;
}

const char* ErrorsMessenger(Errors error) {
    switch(error) {
        case NO_ERROR:               return "NO_ERROR";
        case WRONG_READING:          return "WRONG_READING";
        case UNDEFINED_NUMBER_ROOTS: return "UNDEFINED_NUMBER_ROOTS";
        default:                     return "UNDEFINED_ERROR";
    }
}

void ClearBuffer() {
    printf(".");
    int ch = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int NearZero(double n) {
    return fabs(n) < eps;
}
