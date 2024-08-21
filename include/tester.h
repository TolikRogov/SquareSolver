#pragma once

#include "solve.h"

typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

void Tester();
Tests RunTests(int n_test, Coeff* coeff, double x1_right, double x2_right, int n_roots_right);
const char* TestsMessenger(Tests test);
