#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double maxf(double a, double b);
int main() {
    int N[4]={100, 1000, 10000, 100000}, M=100000, n=100;
    double z, w, sum[M], mu=0., s2=0., max=0.;
    
    FILE *fp_q;
    fp_q = fopen("report4-3-2.dat", "w");
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        for (int k = 0; k < M; k++)
        {
            sum[k] = 0;
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
            max = maxf(max, sum[k]);
        }
       
        int a = (int)(5. * max / sqrt(s2))+2;
       
        switch (i)
        {
        case 0:{
            int h0[(int)(5. * max / sqrt(s2))+2];
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                h0[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h0[(int)(5. * sum[k] / sqrt(s2))]++;
            }
            
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                fprintf(fp_q, "%d %f %d\n", k, k * sqrt(s2) / 5., h0[k]);
                h0[k] = 0;
            }
        }
            break;
        
        case 1:{
            int h1[(int)(5. * max / sqrt(s2))+2];
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                h1[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h1[(int)(5. * sum[k] / sqrt(s2))]++;
            }
            
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                fprintf(fp_q, "%d %f %d\n", k, k * sqrt(s2) / 5., h1[k]);
                h1[k] = 0;
            }
        }
            break;
        case 2:{
            int h2[(int)(5. * max / sqrt(s2))+2];
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                h2[k] = 0;
            }
            for (int k = 0; k < M; k++)
            {
                h2[(int)(5. * sum[k] / sqrt(s2))]++;
            }
            
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                fprintf(fp_q, "%d %f %d\n", k, k * sqrt(s2) / 5., h2[k]);
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
                h3[(int)(5. * sum[k] / sqrt(s2))]++;
            }
            
            for (int k = 0; k < (int)(5. * max / sqrt(s2))+2; k++)
            {
                fprintf(fp_q, "%d %f %d\n", k, k * sqrt(s2) / 5., h3[k]);
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