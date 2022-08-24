#include<stdio.h>
#include<math.h>

double func(double Theta, double e, double t);
double diffFunc(double Theta, double e, double t);

int main(){
    double Theta=0.5, e =0.5, t=0.25, h=1.e-8, f, diffF, Df, Theta1=0.5, Theta0=0.5, epsilon=1.e-8;
    f = func(Theta, e, t);
    // diffF = diffFunc(Theta, e, t);
    // Df = (func(Theta + h, e, t) - func(Theta, e, t)) / h;
    // printf("f = %e df/dTheta = %.10e Df = %.10e\n", f, diffF, Df);
    while (fabs(func(Theta1, e, t)) > epsilon)
    {
        Theta1 = Theta0 - func(Theta0, e, t) / diffFunc(Theta0, e, t);
        printf("Theta1 = %f, Theta0 = %f\n", Theta1, Theta0);
        Theta0 = Theta1;
        
    }
    printf("Theta(1/4) = %f\n", Theta1);
    
    return 0;
}

double func(double Theta, double e, double t){
    return Theta - e * sin(Theta) - t;
}

double diffFunc(double Theta, double e, double t){
    return 1 - e * cos(Theta);
}