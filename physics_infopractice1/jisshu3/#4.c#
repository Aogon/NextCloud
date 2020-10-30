#include <stdio.h>
#define N 20//試行回数
int main()
{
  int i;
 int S1=1;
 int S2=0;
 int S3=0;
 int S4=0;
 int S5=0;
  for(i=1;i<=N;i++)
    {
S1=S1*i;
      S2=S2*i;
      S3=S3*i;
      S4=S4*i;
      S5=S5*i;
	if(S1>999)
	  { S2+=S1/1000;
	    S1=S1-(S1/1000)*1000;}
	if(S2>999)
	  {  S3+=S2/1000;
	    S2=S2-(S2/1000)*1000;}
	if(S3>999)
	  {  S4+=S3/1000;
	    S3=S3-(S3/1000)*1000;}
	if(S4>999)
	  {  S5+=S4/1000;
	    S4=S4-(S4/1000)*1000;}
	printf("%d! = %d %d %d %d %d\n",i,S5,S4,S3,S2,S1);
}
}
