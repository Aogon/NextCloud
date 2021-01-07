#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
    double z, w, sum=0.;
    int N[4] = {100, 1000, 10000, 100000};
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < N[i]; j++)
        {
            z = (double)rand()/(double)RAND_MAX;
            w = 2. * (1. + z * z) / ((1. - z * z) * (1. - z * z) + z * z);
            sum += w;
        }
        printf("N = %d, I = %f, error = %f, error × √N =%f\n", N[i], sum/(double)N[i], fabs(sum/(double)N[i] - M_PI), fabs(sum/(double)N[i] - M_PI) * sqrt(N[i]));
        sum = 0.;
    }
    
    
    return 0;
}