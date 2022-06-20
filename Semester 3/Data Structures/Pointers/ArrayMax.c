#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
		int i;
		int max= 0, maxPos=0;
		int array[10];
		srand(time(NULL));
		for (i=0; i<10; i++)
		{
			array[i] = rand() % 101;
			if ( max < *(array+i) )
				{
					max = *(array+i);
					maxPos = i;
				}
			printf("[%d] = %d \n",i,*(array+i));
		}
		printf ("The Max Value of the Array is:\t %d \n at index %d ",max,maxPos);
		return 0;
}

