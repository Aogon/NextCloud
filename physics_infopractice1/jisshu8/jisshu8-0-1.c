#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n=100, Y=0, m=0, s=0;
    double y, a=0., b=1., p=0.8;
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        y = a + rand() * (b - a) /(double)RAND_MAX;
        if (y<=p)
        {
            Y=+1;
        }else{
            Y=-1;
        } 
        m+=Y;
        s+=Y*Y;
    }
    m = m/n;
    s = s/n - m*m;
    
    
    
    
    return 0;
}