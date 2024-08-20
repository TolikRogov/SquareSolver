#include <stdio.h>
#include <math.h>

const int SS_INF_ROOTS = -1;

int SolveSquare(double a, double b, double c, double *x1, double *x2){
    if (a == 0){     // TODO: вынести в отдельную функцию
        if (b == 0){
            return (c == 0)? SS_INF_ROOTS : 0;
        }
        else {
            *x1 = -c / b;
            *x2 = -c / b;
            return 1;
        }
    }
    else{
        double d = b * b - 4 * a * c;

        if(d == 0) { // ADD FUNC CHECK DOUBLES
            *x1 = *x2 = -b/2/a; //  FIX CODESTYLE
            return 1;
        }
        else if(d > 0){
            *x1 = (-b + sqrt(d))/2/a;
            *x2 = (-b - sqrt(d))/2/a;
            return 2;
        }
    }
    return 0;
}

int main(){

    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;

    printf("# Enter number a, b, c: ");
    scanf("%lg %lg %lg", &a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);

    switch(nRoots) { // GetAnswer()
        case 0: {
            printf("No roots \n");
            break;
        }
        case 1: {
            printf("One root \n");
            printf("x = %lg \n", x1);
            break;
        }
        case 2: {
            printf("Two roots \n");
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
