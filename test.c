#include <stdio.h>

const int SS_INF_ROOTS = -1;

int SolveSquare(double a, double b, double c, double* x1, double* x2){

    return 0;
}

int main(){

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("# Enter number a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    switch(nRoots){
        case 0: {
            printf("No roots \n");
            break;
        }
        case 1: {
            printf("x1 = x2 = %lg \n", x1);
            break;
        }
        case 2: {
            printf("x1 = %lg \n x2 = %lg \n", x1, x2);
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
