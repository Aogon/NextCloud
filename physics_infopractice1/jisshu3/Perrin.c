#include <stdio.h>
#include <math.h>

int main(){
  int Fn0=3, Fn1=0, Fn2=2, Fn3;
  int S1=0, S2=0, S3=0, S4=0, S5=0;
  int i;
  int N;
  printf("Nには3以上の整数を入力してください。\nN = ");
  scanf("%d", &N);
  printf("Fn0 = %d\nFn1 = %d\nFn2=%d\n", Fn0, Fn1, Fn2);
  for(i=3; i<=N; i++){
    Fn3 = Fn1 + Fn0;
    Fn0= Fn1;
    Fn1 = Fn2;
    Fn2 = Fn3;
    S1 = Fn3;
    if(S1 > 999){
      S2 += S1/1000;
      S1 = S1 - (S1/1000) * 1000;
    }if(S2 > 999){
      S3 += S2/1000;
      S2 = S2 - (S2/1000) * 1000;
    }if(S3 > 999){
      S4 += S3/1000;
      S3 = S3 -	(S3/1000) * 1000;
    }if(S4 > 999){
      S5 += S4/1000;
      S2 = S2 -	(S2/1000) * 1000;
    }if(S2 > 999){
      S3 += S2/1000;
      S2 = S2 -	(S2/1000) * 1000;
    }
    printf("Fn%d = %d\n", i, Fn3);
  }
  return 0;
}
