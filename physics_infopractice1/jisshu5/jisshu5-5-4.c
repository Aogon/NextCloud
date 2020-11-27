#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int Nmax = 100, t = 0, t_max=1000, count=0;
    int N[Nmax][Nmax], M[Nmax][Nmax];
    srand((unsigned) time(NULL));
    for (int i = 0; i < Nmax; i++)
    {
        for (int j = 0; j < Nmax; j++)
        {
            N[i][j] = rand()%2;
        }
        
       
    }
    
    
    
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
                int a[3] = {(j-1)%Nmax, j%Nmax, (j+1)%Nmax};
                int b[3] = {(k-1)%Nmax, k%Nmax, (k+1)%Nmax};
                for (int l = 0; l < 3; l++)
                {
                    for (int m = 0; m < 3; m++)
                    {
                        if (l==1&&m==1)
                        {
                            continue;
                        }else if (N[a[l]][b[m]] == 1)
                        {
                            count++;
                            // printf("%d %d %d %d %d\n", j, k, a[l], b[m], count);
                        }   
                        
                    }
                    
                }
                

                if (N[j%Nmax][k%Nmax]==0)
                {
                    if (count == 3)
                    {
                        M[j][k] = 1;
                    }else{
                        M[j][k] = 0;
                    }
                }else{
                    if (count == 2 || count == 3)
                    {
                        M[j][k] = 1;
                    }else
                    {
                        M[j][k] = 0;
                    }
                    
                    
                }

                count = 0;
                
                
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