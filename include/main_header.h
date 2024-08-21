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

#define PRINT_ERROR_STRING(err)({             \
    if (err != NO_ERROR) {                    \
        printf("%s\n", ErrorsMessenger(err)); \
        return 0;                             \
    }})

const char* TestsMessenger(Tests test);
Tests RunTests(int n_test, double a, double b, double c, double x1_right, double x2_right, int n_roots_right);
const char* ErrorsMessenger(Errors error);
nRoots Solver(double a, double b, double c, double *x1, double *x2);
Errors PrintAnswer(nRoots num_roots, double *x1, double *x2);
Errors Insert(double *coeff, int cnt);
