# include<stdio.h>

int main(){
  int n = 0;
  printf("Enter an integer you like.\n");
  scanf("%d", &n);
  if(n % 2 == 0){
    printf("%d is even.\n", n);
  }else{
    printf("%d is odd.\n", n);
  }
  return 0;
}
