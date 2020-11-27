#include<stdio.h>

int fact(int n){
    int x=1;
    for (int i = 1; i <= n; i++)
    {
        x = x * i;
    }
    return x;
    
}
int bino(int n, int k){
    return (fact(n) / (fact(k) * fact(n-k)));
}
int main(){
    for (int i = 0; i <= 6; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", bino(i, j));
        }
        printf("\n");
        
    }
    
    return 0;
}