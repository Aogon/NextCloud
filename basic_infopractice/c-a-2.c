#include <stdio.h>
#include <math.h>

void check(double a, double b, double c, double x)
{
    double ans = (pow(a, 2) + 1) * pow(x - a, 4) + b * pow(x - a, 2) + c;
    printf("    [Check] (a^2+1)(x-a)^4+b(x-a)^2+c =%lf \n", ans);
}

int main(void)
{
    double a, b, c, d1, x1, x2, x3, x4, y1, y2;
    const double e = 0.00001;
    printf("a =? "); scanf("%lf", &a);
    printf("b =? "); scanf("%lf", &b);
    printf("c =? "); scanf("%lf", &c);
    
    d1 = pow(b, 2) - 4 * (pow(a, 2) + 1) * c;
    

    if (-e < d1 && d1 < e)
    {
        y1 = -b / (2 * (pow(a, 2) + 1));
        if (-e < y1 && y1 < e)
        {
            x1 = a;
            printf("Solution: x=%lf", x1);
            check(a, b, c, x1);
        } else if (y1 > 0)
        {
            x1 = a + sqrt(y1);
            x2 = a - sqrt(y1);
            printf("Solution: x=%lf", x1);
            check(a, b, c, x1);
            printf("Solution: x=%lf", x2);
            check(a, b, c, x2);
        } else
        {
            printf("解ナシ \n");
        }
            
    } else if (d1 > 0)
    {
        y1 = (-b + sqrt(d1)) / (2 * (pow(a, 2) + 1));
        y2 = (-b - sqrt(d1)) / (2 * (pow(a, 2) + 1));
        if (-e < y1 && y1 < e)
        {
            x1 = a;
            printf("Solution: x=%lf", x1);
            check(a, b, c, x1);
        } else if (y1 > 0)
        {
            x1 = a + sqrt(y1);
            x2 = a - sqrt(y1);
            if (-e < y2 && y2 < e)
            {
                x3 = a;
                printf("Solution: x=%lf", x1);
                check(a, b, c, x1);
                printf("Solution: x=%lf", x2);
                check(a, b, c, x2);
                printf("Solution: x=%lf", x3);
                check(a, b, c, x3);
                
            } else if (y2 > 0)
            {
                x3 = a + sqrt(y2);
                x4 = a - sqrt(y2);
                printf("Solution: x=%lf \n", x1);
                check(a, b, c, x1);
                printf("Solution: x=%lf \n", x2);
                check(a, b, c, x2);
                printf("Solution: x=%lf \n", x3);
                check(a, b, c, x3);
                printf("Solution: x=%lf \n", x4);
                check(a, b, c, x4);
            } else
            {
                printf("解ナシ \n");
            }
            
        } else if (y1 < 0)
        {
            printf("解ナシ \n");
        }
        
        
        
    } else
    {
        printf("解ナシ \n");
    }
    
    
    return 0;
}