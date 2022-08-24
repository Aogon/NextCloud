#include<stdio.h>
#include<math.h>

double func(double Theta, double e, double t);
double diffFunc(double Theta, double e, double t);
double Newton_Kepler(double ti, double Theta0);

int main(){
    FILE *fp_q;
    fp_q = fopen("report3-2.dat", "w");
    double Theta, e =0.5, t=0.25, Theta1=0, Theta0=0, epsilon=1.e-8, ti, dt = 0.05;
    int N = 127;
    for (int i = 1; i <= N; i++)
    {
        ti = dt * i;
        Theta = Newton_Kepler(ti, Theta0);
        Theta0 = Theta;
        fprintf(fp_q, "%d %e %e %e %e \n", i, ti, Theta0, cos(Theta0)-e, sqrt(1-e*e)*sin(Theta0));
    }
    
    
    
    return 0;
}

double func(double Theta, double e, double t){
    return Theta - e * sin(Theta) - t;
}

double diffFunc(double Theta, double e, double t){
    return 1 - e * cos(Theta);
}

double Newton_Kepler(double ti, double Theta0){
    double Theta1 = Theta0;
    double e = 0.5, epsilon = 1.e-8;
    while (fabs(func(Theta1, e, ti)) > epsilon)
    {
        Theta1 = Theta0 - func(Theta0, e, ti) / diffFunc(Theta0, e, ti);
        Theta0 = Theta1;  
        
    }
    return Theta1;
}