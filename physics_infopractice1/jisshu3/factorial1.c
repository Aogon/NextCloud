#include <stdio.h>
#include <math.h>

int main(void){
  int  i, N =20;
  int  fact =1 ;


  for(i=1; i<=N; i++){

    fact  =  fact*i;
    printf("%d %d \n", i, fact);

    }

    return 0;
}


