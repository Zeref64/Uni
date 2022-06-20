#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int *p;
	int i = 30;
	i += 20; // 1st method
	p = &i;
	printf ("Value i = %d Address %p \n",*p,p);
	*p += 50; // second method
	printf ("Value i = %d Address %p \n",i,&i);
	*p = 64;
	return 0;
}

/*int main ()
{
	int array[6] = {10,20,30,40,50,64};
	int i=0;
	for (i=0; i<6; i++)
		printf("[%d] = %d , Address: %p \n", i, *(array+i), array+i);
}*/
