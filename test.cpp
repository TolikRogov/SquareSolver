#include <stdio.h>
#include <math.h>

const int SS_INF_ROOTS = -1;
const double SS_MIN_VAL = 10e-6;

int Solver(double a, double b, double c, double *x1, double *x2);
int NearZero(double n);
int SolveLine(double b, double c, double *x1, double *x2);
int PrintAnswer(int nRoots, double *x1, double *x2);
int GetDiscriminant(double a, double b, double c);
int SolveSquare(double a, double b, double c, double *x1, double *x2);
int Insert(double *coeff);

int main() {

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    Insert(&a);
    Insert(&b);
    Insert(&c);

    //  дальше читать про enum, сделать enum c количество корней

    int nRoots = Solver(a, b, c, &x1, &x2);

    PrintAnswer(nRoots, &x1, &x2);

    return 0;
}

int NearZero(double n) {
    return fabs(n) < SS_MIN_VAL;
}

int SolveLine(double b, double c, double *x1, double *x2) {
    if (NearZero(b)) {
        return (NearZero(c))? SS_INF_ROOTS : 0;
    }
    else {
        *x1 = -c / b;
        *x2 = -c / b;
        return 1;
    }
}

int PrintAnswer(int nRoots, double *x1, double *x2) {
    switch(nRoots) {
        case 0: {
            printf("No roots \n");
            break;
        }
        case 1: {
            printf("One root \n");
            printf("x = %lg \n", *x1);
            break;
        }
        case 2: {
            printf("Two roots \n");
            printf("x1 = %lg \n x2 = %lg \n", *x1, *x2);
            break;
        }
        case SS_INF_ROOTS: {
            printf("Infinite amount of roots \n");
            break;
        }
        default: {
            printf("main(): ERROR: nRoots = %d \n", nRoots);
            return 1;
        }
    }
    return 0;
}

int GetDiscriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

int SolveSquare(double a, double b, double c, double *x1, double *x2) {
    double d = GetDiscriminant(a, b, c);

    if(NearZero(d)) {
        *x1 = *x2 = -b / ( 2 * a );
        return 1;
    }
    else if(d > 0) {
        double q = sqrt(d);
        *x1 = ( -b + q ) / (2 * a);
        *x2 = ( -b - q ) / (2 * a);
        return 2;
    }
    return 0;
}

int Solver(double a, double b, double c, double *x1, double *x2) {
    int n = 0;
    if (NearZero(a)) {
        n = SolveLine(b, c, x1, x2);
    }
    else {
        n = SolveSquare(a, b, c, x1, x2);
    }
    return n;
}

int Insert(double *coeff) {

    printf("# Enter coefficient: ");
    while (scanf("%lf", coeff) != 1) {
        int ch = 0;

        while ()     // getchar()
    }


    return 0;
}
