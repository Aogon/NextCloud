#include<stdio.h>

int func(int x, int *b, int *c){
    *b = x % 3;
    *c = x % 4;
    return x%2;
}
int main(){
    int b, c;
    printf("%d ", func(1234, &b, &c));
    printf("%d %d\n", b, c);
    return 0;
}