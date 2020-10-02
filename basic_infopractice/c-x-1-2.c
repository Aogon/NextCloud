#include <stdio.h>
#include <math.h>

int main(void)
{
    typedef struct {
        double a[2];
        double v[2];
        double p[2];
    } State = {
        {0, 0}, {0, 0}, {0, 0}
    };

    typedef struct {
        State before;
        State after;
    } Particle;

    double deltaT;
    int k = 0;
    int n = 0;
    

    scanf("%lf", &deltaT);
    scanf("%d", &k);
    scanf("%d", &n);

    

    switch(n) {
        case 2:
            Particle particle0;
            Particle particle1;
            scanf("%lf", &particle0.before.p[0]);
            scanf("%lf", &particle0.before.p[1]);
            scanf("%lf", &particle0.before.v[0]);
            scanf("%lf", &particle0.before.v[1]);
            scanf("%lf", &particle1.before.p[0]);
            scanf("%lf", &particle1.before.p[1]);
            scanf("%lf", &particle1.before.v[0]);
            scanf("%lf", &particle1.before.v[1]);
            Particle partiles[] = {particle0, particle1};
            break;
        case 3:
            Particle particle0;
            Particle particle1;
            Particle particle2;
            scanf("%lf", &particle0.before.p[0]);
            scanf("%lf", &particle0.before.p[1]);
            scanf("%lf", &particle0.before.v[0]);
            scanf("%lf", &particle0.before.v[1]);
            scanf("%lf", &particle1.before.p[0]);
            scanf("%lf", &particle1.before.p[1]);
            scanf("%lf", &particle1.before.v[0]);
            scanf("%lf", &particle1.before.v[1]);
            scanf("%lf", &particle2.before.p[0]);
            scanf("%lf", &particle2.before.p[1]);
            scanf("%lf", &particle2.before.v[0]);
            scanf("%lf", &particle2.before.v[1]);
            break;
        case 4:
            Particle particle0;
            Particle particle1;
            Particle particle2;
            Particle particle3;
            scanf("%lf", &particle0.before.p[0]);
            scanf("%lf", &particle0.before.p[1]);
            scanf("%lf", &particle0.before.v[0]);
            scanf("%lf", &particle0.before.v[1]);
            scanf("%lf", &particle1.before.p[0]);
            scanf("%lf", &particle1.before.p[1]);
            scanf("%lf", &particle1.before.v[0]);
            scanf("%lf", &particle1.before.v[1]);
            scanf("%lf", &particle2.before.p[0]);
            scanf("%lf", &particle2.before.p[1]);
            scanf("%lf", &particle2.before.v[0]);
            scanf("%lf", &particle2.before.v[1]);
            scanf("%lf", &particle0.before.p[0]);
            scanf("%lf", &particle0.before.p[1]);
            scanf("%lf", &particle0.before.v[0]);
            scanf("%lf", &particle0.before.v[1]);
            break;
        default:
            printf("粒子数は２〜４の整数値で指定してください");
    }

    printf("%lf", particle1.before.v[1]);

    return 0;
}