#include<stdio.h>

int func(int x){
    return x+3;
}
int main(){
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", func(i+1));
    }
    
    return 0;
}