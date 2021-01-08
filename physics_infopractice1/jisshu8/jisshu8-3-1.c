#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int Ntotal=1000, Y=0, m=0, s=0, x[Ntotal][2];
    double y, a=0., b=1., p=0.25;
    FILE *f_pq;
    f_pq = fopen("jisshu8-3-1.dat", "w");
    srand((unsigned)time(NULL));
    for (int i = 0; i < Ntotal; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            x[i][j] = 0;
        }
        
    }
    
    for (int i = 1; i < Ntotal; i++)
    {
        y = a + rand() * (b - a) /(double)RAND_MAX;
        if (y<=p)
        {
            x[i][0] = x[i-1][0] + 1;
            x[i][1] = x[i-1][1];
        }else if (y<=2*p){
            x[i][0] = x[i-1][0] - 1;
            x[i][1] = x[i-1][1];
        }else if (y<=3*p)
        {
            x[i][0] = x[i-1][0];
            x[i][1] = x[i-1][1] + 1;
        }else
        {
            x[i][0] = x[i-1][0];
            x[i][1] = x[i-1][1] - 1;
        }
    }

    for (int i = 0; i < Ntotal; i++)
    {
        for (int j = 0; j < i; j++)
        {
            fprintf(f_pq, "%d %d\n", x[j][0], x[j][1]);
        }
        fprintf(f_pq, "\n\n");
    }
    
    return 0;
}