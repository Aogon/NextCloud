#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double maxf(double a, double b);
int main() {
    int N[4] = {100, 1000, 10000, 100000}, M=100, n=100;
    double z, w, sum[4][M], mu=0., s2=0., max=0.;
    
    FILE *fp_q;
    fp_q = fopen("report4-3-1.dat", "w");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < M; k++)
        {
            for (int j = 0; j < N[i]; j++)
            {
                z = (double)rand()/(double)RAND_MAX;
                w = 2. * (1. + z * z) / ((1. - z * z) * (1. - z * z) + z * z);
                sum[i][k] += w;
            }
            sum[i][k] = sum[i][k]/(double)N[i];
            mu += sum[i][k];
            s2 += sum[i][k] * sum[i][k];
        }
        mu = mu / (double)M;
        s2 = (s2 / (double)M) - mu * mu;
        for (int k = 1; k < M; k++)
        {
            max = maxf(sum[i][k], sum[i][k-1]);
        }
        int a = (int)(5. * max / sqrt(s2))+1;
        int h[(int)(5. * max / sqrt(s2))+1];
        for (int k = 0; k < (int)(5. * max / sqrt(s2))+1; k++)
        {
            h[k] = 0;
        }
        for (int k = 0; k < M; k++)
        {
            h[(int)(5. * sum[i][k] / sqrt(s2))]++;
        }
        
        for (int k = 0; k < (int)(5. * max / sqrt(s2))+1; k++)
        {
            fprintf(fp_q, "%d %d\n", k, h[k]);
            h[k] = 0;
        }
        
        
        mu = 0.;
        s2 = 0.;
        max = 0.;
        fprintf(fp_q, "\n\n");
        
    }
    
    
    
    return 0;
}

double maxf(double a, double b) {
    if (a > b)
        return a;
    else
        return b;
}