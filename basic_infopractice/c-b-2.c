#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

double getRandom(void) {
    double x = 0.0;
    x = (random() % 10000000) / 10000000.0;
    return x;
}

int main(void)
{
    double x = 0.0;
    double y = 0.0;
    double p = 0.0;
    int n = 0;
    int m = 0;
    int k = 1;
    int i = 0;
    double s = 0.0;

    srandom((unsigned int)time(NULL));

    while (k < 7)
    {
        x = getRandom();
        y = getRandom();

        if (pow(x, 2) + pow(y, 2) < 1.0)
        {
            n++;
            m++;
        } else
        {
            n++;
        }



        p = 4.0 * m / n;

        if (fabs(p - M_PI) < pow(10, -k))
        {
            printf("pi = %.15lf, (N=%d)\n", p, n);
            k++;
        }


        
        
        
    }

    
    return 0;
}