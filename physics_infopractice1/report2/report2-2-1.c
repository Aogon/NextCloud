#include<stdio.h>
#include<math.h>

int main(){
    int N= 631;
    const double e = 0.5;
    const double dt = 0.01;
    double x[2] = {1 - e, 0}, u[2] = {0, sqrt((1 + e)/(1 - e))}, r, r0, time=0, E;
    
    
    r0 = sqrt(x[0]*x[0] + x[1]*x[1]);
    
    for (int i = 0; i < N; i++)
    {
        time = time + dt;
        x[0] = x[0] + dt * u[0];
        x[1] = x[1] + dt * u[1];
        r = sqrt(x[0] * x[0] + x[1] * x[1]);
        u[0] = u[0] - dt * x[0] / pow(r, 3);
        u[1] = u[1] - dt * x[1] / pow(r, 3);
        E = (u[0] * u[0] + u[1] * u[1]) / 2 - 1 / r;
        printf("%e %e %e %e %e %e \n", time, x[0], x[1], u[0], u[1], E);
    }
    
    return 0;
}