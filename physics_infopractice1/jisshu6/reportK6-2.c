#include<stdio.h>
#include<math.h>

double func(double T, double e, double t);
double diffFunc(double T, double e, double t);

int main(){
    FILE *fp_q;
    fp_q = fopen("q3.dat", "w");
    double T=0.5, e =0.5, t=1., h=1.e-16, f, diffF, Df;
    f = func(T, e, t);
    
    for (int i = 0; i < 55; i++)
    {
        diffF = diffFunc(T, e, t);
        Df = (func(T + h, e, t) - func(T, e, t)) / h;
        fprintf(fp_q, "%e %.10e\n", h, fabs(Df - diffF));
        h = 2. * h;
    }
    
    
    return 0;
}

double func(double T, double e, double t){
    return T - e * sin(T) - t;
}

double diffFunc(double T, double e, double t){
    return 1 - e * cos(T);
}