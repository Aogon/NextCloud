#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  srand((unsigned) time(NULL));
  int uraomote;
  if(rand()%2 == 0){
    uraomote=1;
  }else{
    uraomote=-1;
  }
  printf("%d\n", RAND_MAX);
  printf("%d\n", uraomote);
  return 0;
}
