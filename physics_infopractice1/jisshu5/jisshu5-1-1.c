#include<stdio.h>
#include<math.h>

int main(){
    int N = 100, M = 1000;
    double a[N+1];
    double b[N+1];
    double a0 = 0.5, x[M+1], W[M+1];
    int b0 = 15;
    for (int i = 0; i < M+1; i++)
    {
        W[i] = 0;
    }
    
    for (int i = 0; i < N+1; i++)
    {
        a[i] = pow(a0, i);
        b[i] = M_PI * pow(b0, i);
    }
    for (int i = 0; i < M+1; i++)
    {
        x[i] = -2. + 4. * i / (double)M;
    }
    
    for (int i = 0; i < M+1; i++)
    {
        for (int j = 0; j < N+1; j++)
        {
            W[i] += a[j] * cos(b[j] * x[i]);
            
        }
        printf("%.15e %.15e\n", x[i], W[i]);
    }
    
    
    
    return 0;
}