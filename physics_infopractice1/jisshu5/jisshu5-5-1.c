#include<stdio.h>

int main(){
    int Nmax = 100, t = 0, t_max=100;
    int N[Nmax], M[Nmax];
    for (int i = 0; i < Nmax; i++)
    {
        N[i] = 0;
    }
    N[Nmax/2-1] = 1;
    for (int j = 0; j < Nmax; j++)
    {
        M[j] = N[j];
        if(N[j]==1){
                printf("%d %d\n", t, j);
        }
    }

    for (int i = 0; i < t_max; i++)
    {
        t++;
        
        for (int j = 0; j < Nmax; j++)
        {
            if ((N[(j-1)%Nmax]==1&&N[j%Nmax]==1&&N[(j+1)%Nmax]==1)||
                (N[(j-1)%Nmax]==1&&N[j%Nmax]==0&&N[(j+1)%Nmax]==1)||
                (N[(j-1)%Nmax]==0&&N[j%Nmax]==1&&N[(j+1)%Nmax]==0)||
                (N[(j-1)%Nmax]==0&&N[j%Nmax]==0&&N[(j+1)%Nmax]==0))
            {
                M[j] = 0;
            }else
            {
                M[j] = 1;
            }
        }
        
        for (int j = 0; j < Nmax; j++)
        {
            N[j] = M[j];
            if(N[j]==1){
                printf("%d %d\n", t, j);
            }
            
        }
    }
    
    return 0;
}