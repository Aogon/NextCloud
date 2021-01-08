#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double maxf(double a, double b);
int main() {
    int N[4]={100, 1000, 10000, 100000}, M=100000, n=100;
    double z, w, sum[M], X[M], mu=0., s2=0., max=0.;
    
    FILE *fp_q;
    fp_q = fopen("report4-3-3.dat", "w");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        printf("%d", i);
        for (int k = 0; k < M; k++)
        {
            sum[k] = 0.;
            X[k] = 0.;
        }
        
        
        for (int k = 0; k < M; k++)
        {
            for (int j = 0; j < N[i]; j++)
            {
                z = (double)rand()/(double)RAND_MAX;
                w = 2. * (1. + z * z) / ((1. - z * z) * (1. - z * z) + z * z);
                sum[k] += w;
            }
            sum[k] = sum[k]/(double)N[i];
            // printf("sumk %f\n", sum[k]);
            mu += sum[k];
            s2 += sum[k] * sum[k];
        }
        mu = mu / (double)M;
        s2 = (s2 / (double)M) - mu * mu;
        for (int k = 0; k < M; k++)
        {
            X[k] = 100 + (sum[k] - mu) / sqrt(s2);
            max = maxf(max, X[k]);
        }
        switch (i)
        {
        case 0:{
            int h0[(int)(5. * max)+2];
            for (int k = 0; k < (int)(5. * max)+2; k++)
            {
                h0[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h0[(int)(5. * X[k])]++;
            }
            
            for (int k = 0; k < (int)(5. * max)+2; k++)
            {
                fprintf(fp_q, "%d %f %f\n", k, (double)k / 5. - 100, 5. * (double)h0[k]/((double)M));
                h0[k] = 0;
            }
        }
            break;
        
        case 1:{
            int h1[(int)(5. * max )+2];
            for (int k = 0; k < (int)(5. * max )+2; k++)
            {
                h1[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h1[(int)(5. * X[k] )]++;
            }
            
            for (int k = 0; k < (int)(5. * max)+2; k++)
            {
                fprintf(fp_q, "%d %f %f\n", k, (double)k  / 5. - 100, 5. * (double)h1[k]/((double)M));
                h1[k] = 0;
            }
        }
            break;
        case 2:{
            int h2[(int)(5. * max)+2];
            for (int k = 0; k < (int)(5. * max)+2; k++)
            {
                h2[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h2[(int)(5. * X[k] )]++;
            }
            
            for (int k = 0; k < (int)(5. * max )+2; k++)
            {
                fprintf(fp_q, "%d %f %f\n", k, (double)k  / 5. - 100, 5. * (double)h2[k]/((double)M));
                h2[k] = 0;
            }
        }
            break;
        case 3:{
            int h3[(int)(5. * max / sqrt(s2))+2];
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                h3[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h3[(int)(5. * X[k] )]++;
            }
            
            for (int k = 0; k < (int)(5. * max )+2; k++)
            {
                fprintf(fp_q, "%d %f %f\n", k, (double)k  / 5. - 100, 5. * (double)h3[k]/((double)M));
                h3[k] = 0;
            }
        }
            break;
        
        default:
            break;
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