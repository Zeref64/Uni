#include <stdio.h>
int main ()
{
	system ("chcp 1253");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
	int N,z,square_z,N_thet=0;
	double avg=0;
	int sum=0,sumAR=0;
	int prod=1;
	int i,j=1;
	printf("Παρακαλώ εισάγετε το πλήθος των αριθμών Ν >>>  ");
	scanf("%i",&N);

	for (i=0;i<N;i++)
	{
		printf("Δώσε την τιμή %i:\t",j);
		scanf("%d",&z);
		printf("ο αριθμος (%d) είναι: \n",z);
		if (z >= 0)
		{
			printf("Θετικός αριθμός &\n");
			sum+=z;
			N_thet+=1;
		}
		else
		{
			printf("Αρνητικός αριθμός &\n");
			prod*=z;
		}
		if (z%2==0)
		{
			printf ("Αρτιος αριθμός.\n\n");
			sumAR++;
			
		}
		else
		{
			printf("Περιττός αριθμός.\n");
			square_z=z*z;
			printf("Το τετράγωνο του συγκεκριμένου περιττόυ αριθμού %d είναι: %d\n\n",z,square_z);
		}
		j++;
	}
		
	avg= sum/N_thet;
	printf ("Το Αθροισμα των Αρτιων αριθμών είναι : %d \n",sumAR);
	printf("Το Γινόμενο των Αρνητικών τιμών είναι: %d\n",prod);
printf("Ο Μέσος Όρος των Θετικών αριθμών που δόθηκαν είναι : %lf\n",avg);
	
	return 0;
}
