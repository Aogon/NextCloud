#include <stdio.h>
#include <math.h>

double a[4];
double X0;
double const e = 0.0001;

double getDerivative(double x, double *a)
{
    double y;
    y = -sin(x) * (3.0 * a[0] * pow(cos(x), 2) + 2.0 * a[1] * cos(x) + a[2]);
    return y;
}

double getFunctionValue(double x, double *a)
{
    double y;
    y = a[0] * pow(cos(x), 3) + a[1] * pow(cos(x), 2) + a[2] * cos(x) + a[3];
    return y;
}

double getCandidate(double x0, double *a)
{
    double x1;
    x1 = x0 - getFunctionValue(x0, a) / getDerivative(x0, a);
    return x1;
}



int main(void) 
{
    printf("a =? "); scanf("%lf", &a[0]);
    printf("b =? "); scanf("%lf", &a[1]);
    printf("c =? "); scanf("%lf", &a[2]);
    printf("d =? "); scanf("%lf", &a[3]);
    printf("x =? "); scanf("%lf", &X0);



    for(int i = 0; i < 10000; i++)
    {
        double X1 = getCandidate(X0, a);
        double Y1 = getFunctionValue(X1, a);
        if (fabs(Y1) < e)
        {
            printf("Solution: x = %lf\n", X1);
            printf("Verification: %lf *(cos x)^3.0 + %lf *(cos x)^2.0 + %lf *(cos x) + %lf = %lf\n",
                a[0], a[1], a[2], a[3], getFunctionValue(X1, a));
            break;
        }
        X0 = X1;
    }

    
    

    return 0;
}