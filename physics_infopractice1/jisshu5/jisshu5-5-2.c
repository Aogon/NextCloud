#include<stdio.h>

int main(){
    int Nmax = 100, t = 0, t_max=1000;
    int N[Nmax][Nmax], M[Nmax][Nmax];
    for (int i = 0; i < Nmax; i++)
    {
        for (int j = 0; j < Nmax; j++)
        {
            N[i][j] = 0;
        }
        
       
    }
    N[Nmax/2-1][Nmax/2-1] = 1;
    for (int j = 0; j < Nmax; j++)
    {
        for (int k = 0; k < Nmax; k++)
        {
            M[j][k] = N[j][k];
            if(N[j][k]==1){
                printf("%d %d %d\n", t, j, k);
            }  
        }
    }
    printf("\n\n");

    for (int i = 0; i < t_max; i++)
    {
        t++;
        
        for (int j = 0; j < Nmax; j++)
        {
            for (int k = 0; k < Nmax; k++)
            {
                if ((N[(j-1)%Nmax][k%Nmax]==1&&N[j%Nmax][k%Nmax]==1&&N[(j+1)%Nmax][k%Nmax]==1&&N[j%Nmax][(k-1)%Nmax]==1&&N[j%Nmax][(k+1)%Nmax]==1)||
                    (N[(j-1)%Nmax][k%Nmax]==1&&N[j%Nmax][k%Nmax]==0&&N[(j+1)%Nmax][k%Nmax]==1&&N[j%Nmax][(k-1)%Nmax]==1&&N[j%Nmax][(k+1)%Nmax]==1)||
                    (N[(j-1)%Nmax][k%Nmax]==0&&N[j%Nmax][k%Nmax]==1&&N[(j+1)%Nmax][k%Nmax]==0&&N[j%Nmax][(k-1)%Nmax]==0&&N[j%Nmax][(k+1)%Nmax]==0)||
                    (N[(j-1)%Nmax][k%Nmax]==0&&N[j%Nmax][k%Nmax]==0&&N[(j+1)%Nmax][k%Nmax]==0&&N[j%Nmax][(k-1)%Nmax]==0&&N[j%Nmax][(k+1)%Nmax]==0))
                {
                    M[j][k] = 0;
                }else
                {
                    M[j][k] = 1;
                }
            }
            
            
        }
        
        for (int j = 0; j < Nmax; j++)
        {
            for (int k = 0; k < Nmax; k++)
            {
                N[j][k] = M[j][k];
                if(N[j][k]==1){
                    printf("%d %d %d\n", t, j, k);
                }
            }
            
        }
        printf("\n\n");
    }
    
    return 0;
}