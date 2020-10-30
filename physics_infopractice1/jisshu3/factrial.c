#include <stdio.h>

int main() {
  int i;
  int N;
  int fact = 1;
  printf("N =");
  scanf("%d", &N);
  for(i = 1; i <= N; i++) {
    fact = fact * i;
  }
  printf("%d\n", fact);
  return 0;
}
