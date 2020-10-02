#include <stdio.h>

int main(void)
{
    double x0, x1, x2, y0, y1, y2, 
        abx, aby, bcx, bcy, cax, cay,
        bax, bay, cbx, cby, acx, acy,
        a, b, c;
    
    const double e = 0.00001;

    printf("x0 =? ");
    scanf("%lf", &x0);
    printf("y0 =? ");
    scanf("%lf", &y0);
    printf("x1 =? ");
    scanf("%lf", &x1);
    printf("y1 =? ");
    scanf("%lf", &y1);
    printf("x2 =? ");
    scanf("%lf", &x2);
    printf("y2 =? ");
    scanf("%lf", &y2);

    abx = x1 - x0;
    aby = y1 - y0;
    bcx = x2 - x1;
    bcy = y2 - y1;
    cax = x0 - x2;
    cay = y0 - y2;

    bax = -abx;
    bay = -aby;
    cbx = -bcx;
    cby = -bcy;
    acx = -cax;
    acy = -cay;

    a = abx * acx + aby * acy;
    b = bax * bcx + bay * bcy;
    c = cax * cbx + cay * cby;

    if (-e < a && a < e) {
        printf("RIGHT\n");
    } else if (a < 0) {
        printf("OBTUSE\n");
    } else if (a > 0) {
        if (-e < b && b < e) {
            printf("RIGHT\n");
        } else if (b < 0) {
            printf("OBTUSE\n");
        } else if (b > 0) {
            if (-e < c && c < e) {
                printf("RIGHT\n");
            } else if (c < 0) {
                printf("OBTUSE\n");
            } else if (c > 0) {
                printf("ACCUTE\n");
            }
        }
    }


    return 0;
}