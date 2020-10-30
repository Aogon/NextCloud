#include <stdio.h>
#include <math.h>
  
int main(){
  int Fn0[10000], Fn1[10000], Fn2[10000], Fn3[10000];
  Fn0[0] = 3;
  Fn1[0] = 0;
  Fn2[0] = 2;
  Fn3[0] = 0;
  int l;
  for (l=1; l< 10000; l++) {
    Fn0[l] = 0;
    Fn1[l] = 0;
    Fn2[l] = 0;
    Fn3[l] = 0;
  }
  int i;
  int k;
  int N;
  int Nmax;
  printf("Nには3以上の整数を入力してください。\nN = ");
  scanf("%d", &N);
  /*printf("Fn0 = "); 
  for(k=9999; k>=0; k--){
    printf("%03d", Fn0[k]);
  }
  printf("\n");
  printf("Fn1 = "); 
  for(k=9999; k>=0; k--){
    printf("%03d", Fn1[k]);
  }
  printf("\n");
  printf("Fn2 = "); 
  for(k=9999; k>=0; k--){
    printf("%03d ", Fn2[k]);
  }
  printf("\n");
  */
  for(i=3; i<=N; i++){
    int j;
    for(j=0; j<=9999; j++){
      Fn3[j] = Fn1[j] + Fn0[j];
    }
    for(j=0; j<=9999; j++){
      if(Fn3[j] > 999 && j != 9999){
	Fn3[j+1] += Fn3[j]/1000;
	Fn3[j] = Fn3[j] - (Fn3[j]/1000) * 1000;
      }if(Fn3[j] > 999 && j == 9999){
	Nmax = i - 1;
	printf("Nが大きすぎます。\n");
	goto OUT;
      }
      Fn0[j] = Fn1[j];
      Fn1[j] = Fn2[j];
      Fn2[j] = Fn3[j];
      Nmax = i;
    }
    //printf("Fn%d = ", i);
    //for(j=9999; j>=0; j--){
    //printf("%03d", Fn3[j]);
    //}
    //printf("\n");
  }
 OUT:
  printf("Fn%d = ", Nmax);
  int j;
  for(j=9999; j>=0; j--){
    printf("%03d", Fn3[j]);
  }
  printf("\nN=%dが求められました。", Nmax);
  return 0;
}
