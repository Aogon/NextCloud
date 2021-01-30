#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main() {
    FILE *fp_q;
    fp_q = fopen("report5-1-2.dat", "w");
    int Ntotal=10000, N1=Ntotal, N2=0, N3=0, M=100000;
    double p=0., p1=(double)N1/Ntotal, p2=(double)N2/Ntotal, p3=(double)N3/Ntotal;
    fprintf(fp_q, "%d %d %d %d\n", 0, N1, N2, N3);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < M; i++)
    {
        p = (double)rand()/(double)RAND_MAX;
        if (p < p1)
        {
            N1--;
            N2++;
        }
        p = (double)rand()/(double)RAND_MAX;
        if (p < p2)
        {
            N2-=2;
            N1++;
            N3++;
        }
        p = (double)rand()/(double)RAND_MAX;
        if (p < p3)
        {
            N3--;
            N2++;
        }
        fprintf(fp_q, "%d %d %d %d\n", i+1, N1, N2, N3);
        p1=(double)N1/Ntotal;
        p2=(double)N2/Ntotal;
        p3=(double)N3/Ntotal;
        
    }
    
    return 0;
}