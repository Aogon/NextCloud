//#include "stdafx.h"
#include <stdio.h>
#define N 400//s‰ñ”
#define M 1000//Œ…”
int main()
{
	int S[M];
		S[0] = 1;
		int i, j,k,l,flag=0;
			for (i = 1; i <= M-1; i++)
			{
				S[i] = 0;
			}
			for (j = 1; j <= N; j++)
			{
				for (i = 0; i <= M-1; i++)
				{
					S[i] *= j;
				}
				for (i = 0; i <= M - 2; i++)
				{
					k = S[i] /10;
					S[i + 1] += k;
					S[i] = S[i]%10;
				}
				printf("%d!=", j);
				for (i = 0; i <= M - 1; i++)
				{
					if (S[M - 1 - i] > 0)
						flag = 1;
					if (flag == 1)
						printf("%d", S[M-1-i]);
				}
				printf("\n");
				flag = 0;
			}
				
    return 0;
}

