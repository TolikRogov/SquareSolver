typedef enum {
    FAILED_TEST,
    CORRECT_TEST
} Tests;

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

Tests RunTests(int n_test, double a, double b, double c, double x1_right, double x2_right, int n_roots_right);
const char* TestsMessenger(Tests test);
nRoots Solver(double a, double b, double c, double *x1, double *x2);
