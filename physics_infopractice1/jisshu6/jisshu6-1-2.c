#include<stdio.h>
#include<math.h>

int main(){
    int N=32, M=30000;
    double p[N], p_new[N], q[N], q_new[N], alpha=0., dt=sqrt(1./8.), time=0.;
    FILE *fp_q;
    fp_q = fopen("q2.dat", "w");
    for (int i = 0; i < N; i++)
    {
        p[i] = 0.;
        q[i] = sin(M_PI * i / (N - 1.));
    }
    for (int i = 0; i < M; i++)
    {
        time = time + dt;
        q_new[0] = 0.;
        p_new[0] = 0.;
        for (int j = 1; j < N-1; j++)
        {
            p_new[j] = p[j] - dt * (-(q[j+1] + q[j-1] - 2. * q[j]) 
                + alpha * ((q[j+1] - q[j]) * (q[j+1] - q[j]) - (q[j] - q[j-1]) * (q[j] - q[j-1])));
            q_new[j] = q[j] + dt * p_new[j];
        }
        q_new[N-1] = 0.;
        p_new[N-1] = 0.;
        for (int j = 0; j < N; j++)
        {
            q[j] = q_new[j];
            p[j] = p_new[j];
        }
        if (i % 3 == 0)
        {
            fprintf(fp_q, "# step %d \n", i);
            for (int j = 0; j < N; j++)
            {
                fprintf(fp_q, "%d %e %e\n", j, q[j], p[j]);
            }
            fprintf(fp_q, "\n\n");
        }
        
        
        
    }
    
    
    return 0;
}