#include <stdio.h>
#include <math.h>

//a[m][i][k] m(座標番号), i(質点番号), k(時刻番号)

// void getAcceleration(int a[][][], p[][][], i, k, n)
// {
//     int j;
//     double accel;
//     for(j=0; j<=n; j++) {
//         if(j=i) {
//             break;
//         } else {
//             accel = (p[m][j][k] - p[m][i][k]) / pow(p[m][j][k] - p[m][i][k], 3);
//         }
//     }

//     a[m][i][k] = accel;

// }


int main(void)
{
    double deltaT;
    int k, n;
    scanf("%lf", &deltaT);
    scanf("%d", &k);
    scanf("%d", &n);


    double a[2][n][2 * k];
    double v[2][n][2 * k];
    double p[2][n][2 * k];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < 2 * k; l++)
            {
                a[i][j][l] = 0.0;
                v[i][j][l] = 0.0;
                p[i][j][l] = 0.0;
            }

        }

    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf("%lf", &p[j][i][0]);
        }
        for (int j = 0; j < 2; j++)
        {
            scanf("%lf", &v[j][i][0]);
        }

    }



	for (int b = 0; b < k; b++)
	{
		double distance = 0.0;



		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < 2; m++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < 2; h++)
					{
						distance += fabs(pow(p[h][j][2 * (b - 1)] - p[h][i][2 * (b - 1)], 3));
					}

					a[m][i][2 * (b - 1)] += (p[m][j][2 * (b - 1)] - p[m][i][2 * (b - 1)]) / distance;

				}

			}


		}


		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < 2; m++)
			{
				v[m][i][2 * b - 1] = v[m][i][2 * (b - 1)] + deltaT * a[m][i][2 * (b - 1)] / 2;
				p[m][i][2 * b] = p[m][i][2 * (b - 1)] + deltaT * (v[m][i][2 * (b - 1)] + deltaT * a[m][i][2 * (b - 1)] / 2);
			}


		}

		double distance2;

		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < 2; m++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int h = 0; h < 2; h++)
					{
						distance2 += fabs(pow(p[h][j][2 * b] - p[h][i][2 * b], 3));

					}

					a[m][i][2 * b] += (p[m][j][2 * b] - p[m][i][2 * b]) / distance2;

				}

			}


		}

		for (int i = 0; i < n; i++)
		{
			for (int m = 0; m < 2; m++)
			{
				v[m][i][2 * b] = v[m][i][2 * (b - 1)] + deltaT * a[m][i][2 * (b - 1)] / 2 + deltaT * a[m][i][2 * b] / 2;
			}


		}
	}

	printf("%lf", k * deltaT);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      printf("%lf", p[j][i][2 * k]);
    }
  }

    return 0;
}
