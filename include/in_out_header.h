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
Errors PrintAnswer(nRoots num_roots, double *x1, double *x2);
Errors Insert(double *coeff, int cnt);
