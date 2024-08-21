const double SS_MIN_VAL = 10e-6;

typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

typedef enum {
    NO_ERROR,
    WRONG_READING,
    UNDEFINED_NUMBER_ROOTS
} Errors;

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

void ClearBuffer();
int NearZero(double n);
const char* ErrorsMessenger(Errors error);
