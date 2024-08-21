#pragma once

#include "solve.h"

typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

void Tester();
Tests RunTests(Test* controller);
const char* TestsMessenger(Tests test);
