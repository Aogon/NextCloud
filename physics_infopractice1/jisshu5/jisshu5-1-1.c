#include<stdio.h>
#include<math.h>

int main(){
    int N = 100;
    double a[N+1];
    double b[N+1];
    double a0 = 0.5, x = 0.25, sum = 0;
    int b0 = 15;
    for (int i = 0; i < N+1; i++)
    {
        a[i] = pow(a0, i);
        b[i] = M_PI * pow(b0, i);
    }
    for (int i = 0; i < N+1; i++)
    {
        sum += a[i] * cos(b[i] * x);
    }
    printf("W(x=0.25) = %.15e\n", sum);
    
    return 0;
}