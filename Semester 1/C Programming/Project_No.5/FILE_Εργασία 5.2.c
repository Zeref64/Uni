#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int checkN (int N);
int getN (FILE *fp);
void getx_y (FILE *fp, int *x1, int *x2, int *y1, int *y2);
int *first_pin(FILE *fp,int N);
void swap (int *p1 , int *p2);
void bubbleSort (int *pin , int N);
int *make_array ();
int *make_arrayN (int N);
int *frequency_fill (int *array1 , int *combinations_array , int *frequency_array , int N);
void printS (int *array1, int *frequency , int N;);
int bullet_1 (int * , int num1, int num2 );
int bullet_2 (int * , int num1 , int num2);


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/
int main (int argc, char **argv)
{
	system ("chcp 1253");	
	int N,x1,x2,y1,y2;
	int i,j,k,l,m,o,z,f;
	FILE *fptr;
	int all=0 , correct=0, total_fail=0 , fail_2=0;
	int *array1, *combinations_array , *frequency_array , *frequency;
	fptr=fopen(*(argv+1),"r");
	if (fptr==NULL)
	{
		printf("Σφάλμα, το αρχείο δεν βρέθηκε.\n");
		exit(-1);
	}
	N=getN(fptr); 	
	getx_y (fptr,&x1,&x2,&y1,&y2);				 
	system ("cls");
	printf("|\tN >>> %d \t|\t",N);		//  Διαβάζω το Ν
	printf("x1 >>> %d\t|\t",x1);		//  Διαβάζω το X1
	printf("x2 >>> %d\t|\t",x2);	//  Διαβάζω το X2
	printf("y1 >>> %d\t|\t",y1);		//  Διαβάζω το Y1
	printf("y2 >>> %d\t|\n\n",y2);	//  Διαβάζω το Y2
	array1 = first_pin(fptr,N);			//  Κάνω δυναμική δέσμευση πίνακα (Ν στοιχείων) και ύστερα ο χρήστης τον γεμίζει
	combinations_array = make_array();		//  Φτιάχνω έναν πίνακα 6 στοιχείων για τις εξάδες
	frequency_array = make_arrayN(N);		//  Φτιάχνω έναν πίνακα Ν στοιχείων για τις συχνότητες
	bubbleSort( array1 , N );
	system ("cls");
	printf("Τα ταξινομημένα σας στοιχεία είναι >>>\n");
	printf("[");
	for (i=0;i<N;i++)
		printf("%d,",*(array1+i));
	printf("\b]\n");
	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Οι Εξάδες σας είναι >>>\n\n");
	for (i=1; i<=N-5; i++)
		for (j=i+1; j<=N-4; j++)
			for (k=j+1; k<=N-3; k++)
				for (l=k+1; l<=N-2; l++)
					for (m=l+1; m<=N-1; m++)
						for (o=m+1; o<=N; o++)
							{
								*(combinations_array)=(*(array1+i-1));
								*(combinations_array+1)=(*(array1+j-1));
								*(combinations_array+2)=(*(array1+k-1));		//  Υπολογίζω τις εξάδες για κάθε κελί
								*(combinations_array+3)=(*(array1+l-1));
								*(combinations_array+4)=(*(array1+m-1));
								*(combinations_array+5)=(*(array1+o-1));
								all+=1;
								if( bullet_1(combinations_array,x1,x2) == 1 )		// Έλεγχος Πρώτης κουκκίδας
								{
									if ( bullet_2 (combinations_array , y1  , y2 ))			// Έλεγχος Δεύτερης κουκκίδας
									{
										correct += 1;
										printf("[");
										for (z=0;z<6;z++)
										{
											printf("%d,",*(combinations_array+z));
											
										}
										printf("\b]");
										frequency=frequency_fill( array1 , combinations_array , frequency_array , N );
									}
									else
									{
										fail_2 += 1;
									}
								}
								else
								{
									total_fail += 1;
								}
								printf("\n");
							}
	printf("\nΤο πλήθος των συνδιασμών %d ανά 6 είναι >>> %d",N,all);
	printf("\n");
	printf("Το πλήθος των συνδιασμών που Δεν πληρούσαν ( Πρώτη κουκκίδα ) είναι >>> %d",total_fail);
	printf("\n");
	printf("Το πλήθος των συνδιασμών που Δεν πληρούσαν ( Μόνο την Δεύτερη κουκκίδα ) είναι >>> %d",fail_2);
	printf("\n");
	printf("Το πλήθος των συνδιασμών που Πληρούν ( Και τις Δύο τις κουκκίδες ) είναι >>> %d",correct);
	printf("\n");
	printS (array1, frequency , N);						
	free (array1);
	free (combinations_array);
	free (frequency_array);
	fclose(fptr);
	return 0;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

int getN(FILE *fp)				//  Συνάρτηση που διαβάζει ένα Ν μέσα στα όρια.
{
	int N;
	fscanf(fp,"%d",&N);
	if (N<= 6 || N > 49)
	{
		printf("The number N= %d is invalid (N>6 and N<=49)",N);
		exit(-1);
	}
	return N;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void getx_y (FILE *fp, int *x1, int *x2, int *y1, int *y2)
{
	int numx1,numx2,numy1,numy2;
	fscanf(fp,"%d",&numx1);
	fscanf(fp,"%d",&numx2);
	if (numx1<0 || numx1>numx2 || numx2>6)
	{
		printf("The numbers x1= %d , x2= %d are invalid. (x1 > 0 and x1 < x2 and x2 <= 6)",numx1,numx2);
		exit(-1);
	}
	fscanf(fp,"%d",&numy1);
	fscanf(fp,"%d",&numy2);
	if (numy1<21 || numy1>numy2 || numy2>279)
	{
		printf("The numbers y1= %d , y2= %d are invalid. (21<=y1<=y2<=279)",numy1,numy2);
		exit(-1);
	}
	*x1=numx1;
	*x2=numx2;
	*y1=numy1;
	*y2=numy2;
}

/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int *first_pin (FILE *fp,int N)			//Συνάρτηση για malloc N
{
	int *p;
	int i;
	p=(int *)malloc(N*sizeof(int));
	if (p==NULL)
	{
		printf("Σφάλμα κατά την δέσμευση της μνήμης.");
		exit(-1);
	}
	for (i=0;i<N;i++)
	{
		fscanf(fp,"%d",(p+i));
		if (*(p+i) <1 ||  *(p+i) >49)
		{
			printf("The number %d is not Valid. (Number >= 1 and Number <= 49)",(p+i));
			exit(-1);
		}
	}
	return p;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

void swap (int *p1 , int *p2)		//Συνάρτηση αλλαγής θέσεων 2 τιμών (Για την συνάρτηση BubbleSort)
{
	int tmp;
	tmp=*p1;
	*p1=*p2;
	*p2=tmp;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


void bubbleSort (int *pin , int N)
{
	int i,j;
	for (i=0; i<N-1; i++)
	{
		for (j=0; j<N-1-i; j++)
		{
			if (*(pin+j) > *(pin+j+1))
			{
				swap ( (pin+j) , (pin+j+1) );
			}
		}
	}
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int *make_array ()
{
	int *p;
	p=(int *)malloc(6*sizeof(int));
	if (p==NULL)
	{
		printf("Σφάλμα κατά την δέσμευση της μνήμης.");
		exit(-1);
	}
	return p;	
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int *make_arrayN (int N)
{
	int *p,i;
	p=(int *)malloc(N*sizeof(int));
	if (p==NULL)
	{
		printf("Σφάλμα κατά την δέσμευση της μνήμης.");
		exit(-1);
	}
	for (i=0; i<N; i++)
	{
		*(p+i)=0;
	}
	return p;	
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int *frequency_fill (int *array1 , int *combinations_array , int *frequency_array , int N)
{
	int i,j;
	for (i=0; i<6; i++)
	{
		for (j=0; j<N; j++)
		{
			if (*(combinations_array+i) == *(array1+j))
			{
				*(frequency_array+j) = *(frequency_array+j) +1 ;
			}
		}
	}
	return frequency_array;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int bullet_1 (int *array , int num1 , int num2)
{
	int i;
	int even=0;
	for (i=0; i<6; i++)
		if ( *(array+i) % 2 == 0 )
			even+=1;
	if ( even >= num1 && even <= num2 )
		return 1;
	return 0;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


int bullet_2 (int *array , int num1 , int num2 )
{
	int i;
	int summary=0;
	for (i=0; i<6; i++)
		summary += *(array+i);
	if ( summary >= num1 && summary <= num2 )
		return 1;
	return 0;
}


/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/


void printS (int *array1, int *frequency , int N)
{
	int i;
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("Συχνότητες Εμφάνισης:\n\n");
	for (i=0;i<N; i++)
	{
		if (*(frequency+i) != 0)
		{
			printf("η συχνότητα εμφάνισης του %d αριθμού είναι >>> %d\n",*(array1+i),*(frequency+i));
		}
	}
}
