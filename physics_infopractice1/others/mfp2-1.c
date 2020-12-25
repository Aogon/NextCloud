#include<stdio.h>
#include<math.h>

int kaijo(long long int n){
    long long int ans = 1;
    for (long long int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    printf("%lld\n", ans);
    return ans;
    
}
int main(){
    long long int n;
    double b;
    scanf("%lld", &n);
    b = pow(kaijo(2*n)/(kaijo(n)*(kaijo(n))), 1./n);
    printf("%lld %f\n", n, b);
    return 0;
}