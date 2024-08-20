const double SS_MIN_VAL = 10e-6;

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

const char* ErrorsMessenger(Errors error);
void ClearBuffer();
nRoots Solver(double a, double b, double c, double *x1, double *x2);
int NearZero(double n);
nRoots SolveLine(double b, double c, double *x1, double *x2);
Errors PrintAnswer(nRoots num_roots, double *x1, double *x2);
int GetDiscriminant(double a, double b, double c);
nRoots SolveSquare(double a, double b, double c, double *x1, double *x2);
Errors Insert(double *coeff, int cnt);
