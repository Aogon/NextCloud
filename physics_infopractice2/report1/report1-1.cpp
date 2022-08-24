#include <bits/stdc++.h>

using namespace std;

int main() {
    double x = 0., y = 1.;
    vector<int> N = {10, 100, 1000, 10000, 100000};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < N[i]; j++)
        {
            y = y + exp(-y)/N[i];
        }

        cout << "N = " << N[i] << ", y(1) = " << y << ", error = " << abs(y - log(1 + M_E)) <<endl;
        y = 1.;
    }
    cout << log((1+M_E)/M_E)/(2*(1+M_E)) << endl;

    return 0;
}