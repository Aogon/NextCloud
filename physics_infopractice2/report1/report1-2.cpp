#include <bits/stdc++.h>

using namespace std;

int main() {
    double x = 0., y = 1., error = 0.;
    vector<int> N = {10, 100, 1000, 10000, 100000};
    double a = log((1+M_E)/M_E)/(2*(1+M_E));
    ofstream outputfile("report1-2.dat");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N[i]; j++)
        {
            y = y + exp(-y)/N[i];
        }
        //y(1)の誤差
        error = abs(y - log(1. + M_E));

        //ファイル出力
        outputfile<< N[i] << " " << y << " " << error << " "<< abs(error*N[i] - a) << endl;
        y = 1.;
    }
    outputfile.close();

    return 0;
}