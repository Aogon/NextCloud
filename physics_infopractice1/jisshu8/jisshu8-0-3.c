#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
    FILE *f_pq;
    f_pq = fopen("jisshu8-0-3.dat", "w");
    int Ntotal=1000, Y=0, m=0, s=0, Na=Ntotal;
    double y, a=0., b=1., p=0.8;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10*Ntotal; i++)
    {
        y = a + rand() * (b - a) /(double)RAND_MAX;
        p = (double)Na/Ntotal;
        if (y<=p)
        {
            Na--;
        }
        fprintf(f_pq, "%d %d\n", i, Na);
        m+=Y;
        s+=Y*Y;
    }
    m = m/Ntotal;
    s = s/Ntotal - m*m;
    
    
    
    
    return 0;
}