#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
  srand((unsigned) time(NULL));
  int Nc = 0;
  int N = 100000;
  int i = 0;
  for(i=0; i<N; i++){
    double x = 2.*((double)rand()/RAND_MAX) - 1.;
    double y = 2.*((double)rand()/RAND_MAX) - 1.;
    double r = sqrt(x*x + y*y);
    if(r <= 1.){
      Nc++;
    }
  }
  double Pi = 4. * Nc / N;
  printf("N = %d, Pi = %f\n", N, Pi);
  return 0;
}
