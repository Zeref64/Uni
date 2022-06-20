#include <stdio.h>
#include <math.h>
int main()
{
	

	double a,b,c,x0,x1,x2;
	printf("Give me 3 numbers\n>>>");
	scanf("%lf",&a);
	while (a==0 || a==1)
	{
		printf("Ksanadwse timh gia a (oxi 1 h 0)\t>>>");
		scanf("%lf",&a);
	}
	scanf("%lf %lf",&b,&c);
	printf("%lf>>>\n%lf>>>\n%lf>>>\n",a,b,c);
	
	
	return 0;
}
