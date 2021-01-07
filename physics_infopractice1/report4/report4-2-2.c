#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

double convert(double x, double a, double b);


int main() {
    srand((unsigned int)time(NULL));
    double x[3], sum = 0.;
    int N=0, N0[7];
    const double a[3] = {1., 2., 3.}, V0=(2*a[0])*(2*a[1])*(2*a[2]);
    N0[0] = 100;
    for (int i = 1; i < 7; i++)
    {
        N0[i] = 10 * N0[i-1];
    }

    for (int k = 0; k < 7; k++)
    {
        for (int j = 0; j < N0[k]; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                x[i] = convert((double)rand()/(double)RAND_MAX, -a[i], a[i]);
                sum += (x[i] * x[i]) / (a[i] * a[i]);
            }
            if (sum < 1.)
            {
                N++;
            }
            sum = 0.;
        
        }
        printf("N0 = %d, (N/N0) × V0 = %f\n", N0[k],((double)N/(double)N0[k]) * V0);
        N = 0;
    }
    
    
    
    return 0;
}

double convert(double x, double a, double b) {
    return (b - a) * x + a;
}