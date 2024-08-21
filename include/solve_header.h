typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

nRoots Solver(double a, double b, double c, double *x1, double *x2);
int NearZero(double n);
nRoots SolveLine(double b, double c, double *x1, double *x2);
static int GetDiscriminant(double a, double b, double c);
nRoots SolveSquare(double a, double b, double c, double *x1, double *x2);
