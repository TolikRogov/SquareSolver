typedef enum {
    NO_ERROR,
    WRONG_READING,
    WRONG_TEST,
    UNDEFINED_NUMBER_ROOTS
} Errors;

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

const char* ErrorsMessenger(Errors error);
nRoots Solver(double a, double b, double c, double *x1, double *x2);
Errors PrintAnswer(nRoots num_roots, double *x1, double *x2);
Errors Insert(double *coeff, int cnt);
