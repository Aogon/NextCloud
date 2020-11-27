#include<stdio.h>
#include<math.h>
double calc(double h, int N, int i);

int main(){
    double X[3], p[4];
    double h[3]={0.001, 0.0001, 0.00001};
    int N[4]={100, 1000, 10000};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3 ; j++){
            for (int k = 0; k < 4; k++)
            {
                X[0] = calc(h[i], N[j], k);
                X[1] = calc(2 * h[i], N[j] / 2, k);
                X[2] = calc(4 * h[i], N[j] / 4, k);
                p[k] = log(fabs(X[2]-X[1])/fabs(X[1]-X[0]))/log(2.);
            }
            
            printf("h = %e, N = %d, p_x = %e, p_y = %e, p_u = %e, p_v = %e\n", h[i], N[j], p[0], p[1], p[2], p[3]);
        }
    }
    
    return 0;
}

double calc(double h, int N, int i){
    const double e = 0.5;
    const double dt = h;
    double x[4] = {1 - e, 0, 0, sqrt((1 + e)/(1 - e))};
    double r, r0, time=0, E, diff;
    
    
    r0 = sqrt(x[0]*x[0] + x[1]*x[1]);
    
    for (int j = 0; j < N; j++)
    {
        time = time + dt;
        x[0] = x[0] + dt * x[2];
        x[1] = x[1] + dt * x[3];
        r = sqrt(x[0] * x[0] + x[1] * x[1]);
        x[2] = x[2] - dt * x[0] / pow(r, 3);
        x[3] = x[3] - dt * x[1] / pow(r, 3);
        E = (x[2] * x[2] + x[3] * x[3]) / 2 - 1 / r;
    }
    
    return x[i];
}


