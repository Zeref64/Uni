#include <stdio.h>
#include <math.h>
#define pi 3.141592
int main()
{
	system ("chcp 1253");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
	int prosimo=1,ekthetes=1;
	int i;
	double x,HMX=0,klasma,temp,diff,y;
	temp=0;
	printf("Δώσε μοίρες: ");
	scanf("%lf",&x);
	x=x*pi/180;
	y=sin(x);
	do
	{
		klasma=1;
		for(i=1;i<=ekthetes;i++)
			klasma=klasma*(x/i);
		ekthetes+=2;
		HMX+=(prosimo*klasma);
		prosimo=prosimo*(-1);
	}
	while(fabs(temp-klasma),temp=klasma);
	printf("το ημ(x)===%lf\n",HMX);
	printf("Το ημ(χ) απο συνάρτηση είναι==%lf",y);
	return 0;
}
