#include <bits/stdc++.h>
using namespace std;

int main() {
    double b = 2.5;
    double x = 0.0276 * b;
    double y = x / (1. + sqrt(1. + x * x));
    double lambda_s = 7.99e9;
    double lambda_t = 7.04e6;
    double lambda_s_prime = (lambda_s + y * y * lambda_t) / (1. + y * y);
    double lambda_t_prime = (lambda_t + y * y * lambda_s) / (1. + y * y);
    double tau_paralike = 1. / lambda_s_prime;
    double tau_ortholike = 1. / lambda_t_prime;

    cout <<"tau_paralike = " << tau_paralike << "\ntau_ortholike = " << tau_ortholike << "\n";



    return 0;
}