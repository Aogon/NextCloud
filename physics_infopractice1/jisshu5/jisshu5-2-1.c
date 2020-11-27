#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    srand((unsigned) time(NULL));
    int N=10000, x, h[6];
    for (int i = 0; i < 6; i++)
    {
        h[i] = 0;
    }
    
    for (int i = 0; i < N; i++)
    {
        x = rand() % 6 + 1;
        h[x-1]++;
    }
    for (int i = 0; i < 6; i++)
    {
        printf("%d %d\n", i+1, h[i]);
    }
    
    
    return 0;
}