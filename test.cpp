#include <stdio.h>
#include <math.h>
#include <ctype.h>

const double SS_MIN_VAL = 10e-6;

typedef enum {
    INF_ROOTS = -1,
    NO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS
} nRoots;

nRoots Solver(double a, double b, double c, double *x1, double *x2);
int NearZero(double n);
nRoots SolveLine(double b, double c, double *x1, double *x2);
int PrintAnswer(int nRoots, double *x1, double *x2);
int GetDiscriminant(double a, double b, double c);
nRoots SolveSquare(double a, double b, double c, double *x1, double *x2);
int Insert(double *coeff, int cnt);

int main() {

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    Insert(&a, 1);
    Insert(&b, 2);
    Insert(&c, 3);

    nRoots check = Solver(a, b, c, &x1, &x2);

    PrintAnswer(check, &x1, &x2);

    return 0;
}

int NearZero(double n) {
    return fabs(n) < SS_MIN_VAL;
}

nRoots SolveLine(double b, double c, double *x1, double *x2) {
    if (NearZero(b)) {
        return (NearZero(c))? INF_ROOTS : NO_ROOTS;
    }
    else {
        *x1 = -c / b;
        *x2 = -c / b;
        return ONE_ROOT;
    }
}

int PrintAnswer(nRoots check, double *x1, double *x2) {
    switch(check) {
        case NO_ROOTS: {
            printf("No roots \n");
            break;
        }
        case ONE_ROOT: {
            printf("One root \n");
            printf("x = %lg \n", *x1);
            break;
        }
        case TWO_ROOTS: {
            printf("Two roots \n");
            printf("x1 = %lg \n x2 = %lg \n", *x1, *x2);
            break;
        }
        case INF_ROOTS: {
            printf("Infinite amount of roots \n");
            break;
        }
        default: {
            printf("main(): ERROR: amount of roots is not defined");
            return 1;
        }
    }
    return 0;
}

int GetDiscriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

nRoots SolveSquare(double a, double b, double c, double *x1, double *x2) {
    double d = GetDiscriminant(a, b, c);

    if(NearZero(d)) {
        *x1 = *x2 = -b / ( 2 * a );
        return ONE_ROOT;
    }
    else if(d > 0) {
        double q = sqrt(d);
        *x1 = ( -b + q ) / (2 * a);
        *x2 = ( -b - q ) / (2 * a);
        return TWO_ROOTS;
    }
    return NO_ROOTS;
}

nRoots Solver(double a, double b, double c, double *x1, double *x2) {
    nRoots n;
    if (NearZero(a)) {
        n = SolveLine(b, c, x1, x2);
    }
    else {
        n = SolveSquare(a, b, c, x1, x2);
    }
    return n;
}

int Insert(double *coeff, int cnt) {

    printf("# Enter coefficient №%d: ", cnt);
    while (scanf("%lg", coeff) != 1) {
        printf("# Error coefficient data type \n");
        printf("# Enter coefficient №%d with right data type: ", cnt);
        int ch = 0;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
    return 0;
}
