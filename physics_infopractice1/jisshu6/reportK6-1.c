#include<stdio.h>
#include<math.h>

double func(double T, double e, double t);
double diffFunc(double T, double e, double t);

int main(){
    double T=0.5, e =0.5, t=1., h=1.e-8, f, diffF, Df;
    f = func(T, e, t);
    diffF = diffFunc(T, e, t);
    Df = (func(T + h, e, t) - func(T, e, t)) / h;
    printf("f = %e df/dTheta = %.10e Df = %.10e\n", f, diffF, Df);
    return 0;
}

double func(double T, double e, double t){
    return T - e * sin(T) - t;
}

double diffFunc(double T, double e, double t){
    return 1 - e * cos(T);
}