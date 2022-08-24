#include <bits/stdc++.h>

using namespace std;

int main() {
    //ファイル出力設定
    ofstream outputfile("report2-1.dat");

    //変数の宣言と初期値代入
    double x=1., y= 0., u=0., v=1., deltat=0.2;
    int n=100;

    //Euler法
    for (int i = 0; i < n; i++)
    {
        double x_next, y_next, u_next, v_next;
        //漸化式計算
        x_next = x + deltat * u;
        y_next = y + deltat * v;
        u_next = u - deltat * x / pow(x * x + y * y, 1.5);
        v_next = v - deltat * y / pow(x * x + y * y, 1.5);

        //計算結果を代入
        x = x_next;
        y = y_next;
        u = u_next;
        v = v_next;

        //計算結果を表示
        outputfile << x << " " << y << " " << u << " " << v << endl;
    }

    //空行2行出力
    outputfile << endl << endl;

    //変数の初期化
    x=1., y= 0., u=0., v=1.;

    //Runge-Kutta法（4次）

    double  r3[4], akx[4], aky[4], aku[4], akv[4], rx[4], ry[4], ru[4], rv[4];
                            /***  Runge-Kutta法での計算に必要な変数 ***/
    double  x_next, y_next, u_next, v_next;



    /***　初期条件の設定 ***/
    x = 1.0;
    y = 0.0;
    u = 0.0;
    v = 1.0;


    /***　時間発展の開始 ***/
    for (int i = 1; i <= n; i++)
    {

        r3[0]  = pow( sqrt( pow(x,2.0) + pow(y, 2.0) ), 3.0);
        akx[0] = u;
        aky[0] = v;
        aku[0] = -x/r3[0];
        akv[0] = -y/r3[0];

        rx[1] = x + akx[0] * deltat/2;
        ry[1] = y + aky[0] * deltat/2;
        ru[1] = u + aku[0] * deltat/2;
        rv[1] = v + akv[0] * deltat/2;

        r3[1]  = pow( sqrt( pow(rx[1],2.0) + pow(ry[1], 2.0) ), 3.0);
        akx[1] = ru[1];
        aky[1] = rv[1];
        aku[1] = -rx[1]/r3[1];
        akv[1] = -ry[1]/r3[1];

        rx[2] = x + akx[1] * deltat/2;
        ry[2] = y + aky[1] * deltat/2;
        ru[2] = u + aku[1] * deltat/2;
        rv[2] = v + akv[1] * deltat/2;

        r3[2]  = pow( sqrt( pow(rx[2],2.0) + pow(ry[2], 2.0) ), 3.0);
        akx[2] = ru[2];
        aky[2] = rv[2];
        aku[2] = -rx[2]/r3[2];
        akv[2] = -ry[2]/r3[2];

        rx[3] = x + akx[2]*deltat;
        ry[3] = y + aky[2]*deltat;
        ru[3] = u + aku[2]*deltat;
        rv[3] = v + akv[2]*deltat;

        r3[3]  = pow( sqrt( pow(rx[3],2.0) + pow(ry[3], 2.0) ), 3.0);
        akx[3] = ru[3];
        aky[3] = rv[3];
        aku[3] = -rx[3]/r3[3];
        akv[3] = -ry[3]/r3[3];

    /***  Runge-Kutta 法によって 1 step 時間発展した値  ***/
        x_next = x + deltat*(akx[0] + 2.0*akx[1] + 2.0*akx[2] + akx[3]) / 6.0;
        y_next = y + deltat*(aky[0] + 2.0*aky[1] + 2.0*aky[2] + aky[3]) / 6.0;
        u_next = u + deltat*(aku[0] + 2.0*aku[1] + 2.0*aku[2] + aku[3]) / 6.0;
        v_next = v + deltat*(akv[0] + 2.0*akv[1] + 2.0*akv[2] + akv[3]) / 6.0;

        x = x_next;
        y = y_next;
        u = u_next;
        v = v_next;

    /***  ファイルへの結果の書き出し  ***/
        outputfile << x << " " << y << " " << u << " " << v << endl;

    }

    //Sympletic-Euler法（4次）


    return 0;
}