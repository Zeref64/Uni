#include <stdio.h>
#include <math.h>
int input1();
int input2();
void main_menu(int a, int b);
void select (int s, int a, int b);
int power (int x , int y);
int paragontiko (int x);
int validate_nums (int N, int K);
int num_combinations(int N, int K);
int plhthos_epilogwn(int j);

int main()
{
	int A,B;
	system ("chcp 1253");
	A=input1();
	B=input2();
	printf("\n\nΟι τιμές που δώθηκαν είναι: \n\n\tΑ=%d\t&     Β=%d\n",A,B);
	main_menu(A,B);
	return 0;
}

int input1 ()
{
	int A;
	printf("Παρακαλώ εισάγετε τον Πρώτο αριθμό [A]:  \n");
	scanf("%d",&A);
	return A;
}

int input2()
{
	int B;
	printf("Παρακαλώ εισάγετε τον Δεύτερο αριθμό [B]:  \n");
	scanf("%d",&B);
	return B;
}

void main_menu(int a, int b)
{
	int s,j=0;
	do
	{
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		printf("Πληκτρολογήστε την τιμή [1] για την εύρεση του %d^%d\n\n",a,b);
		printf("Πληκτρολογήστε την τιμή [2] για την εύρεση του %d! %d! \n\n",a,b);
		printf("Πληκτρολογήστε την τιμή [3] για την εύρεση του πλήθους των συνδυασμών %d ανά %d \n\n",a,b);
		printf("Πληκτρολογήστε την τιμή [4] για την εύρεση όλων των παραπάνω.\n\n");
		printf("Πληκτρολογήστε την τιμή [5] για την Έξοδο\n\n");
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		printf("Επιλογή -->  "); scanf("%d",&s);
		select(s,a,b);
		j=plhthos_epilogwn(j);
		}
	while (s !=5 );
	system ("cls");
	printf("Το Πλήθος των επιλογών σας είναι >>> %d\n\n\t-=|Το πρόγραμμα Tερματίστηκε|=- \n\t\t  [Game Over]",j-1);
}

void select (int s, int a , int b)
{
	switch (s)
		{
			case 1:
				system ("cls");
				printf("Η επιλογή σας είναι η >>> [%d]",s);
				printf("\n\nΟι τιμές που δόθηκαν είναι: \n\n\tΑ=%d\t&     Β=%d\n\n\n",a,b);
				printf("\nΟ αριθμός %d υψομένος στην δύναμη %d είναι --> %d\n\n",a,b,power(a,b)); 
				break;
			case 2:
				system ("cls");
				printf("Η επιλογή σας είναι η >>> [%d]",s);
				printf("\n\nΟι τιμές που δόθηκαν είναι: \n\n\tΑ=%d\t&     Β=%d\n\n\n",a,b);
				printf("\nΑ!= %d\tB!=%d\n\n",paragontiko(a),paragontiko(b)); 
				break;
			case 3:
				system ("cls");
				printf("Η επιλογή σας είναι η >>> [%d]\n",s);
				printf("Οι τιμές που δόθηκαν είναι: A=%d & B=%d \n\n",a,b);
				
				if(validate_nums (a,b)==1)
				{
					printf("\nΤο πλήθος των συνδυασμών %d ανά %d έίναι --> %d\n\n",a,b,num_combinations(a,b));
					break;
				}
				else
				{
					printf("\nΔεν μπορεί να υπολογιστεί το πλήθος των συνδυασμών %d ανά %d γιατί:\n 1) Eίτε ο αριθμός %d (Α) είναι μικρότερος απο τον αριθμό %d (Β)\n 2) Ένας απο τους 2 (Α=%d ή Β=%d) αριθμούς είναι αρνητικός.\n 3) Ο Αριθμός %d (B) είναι ίσος με 0\n\n",a,b,a,b,a,b,b);
				}	break;
			case 4:
				system ("cls");
				printf("Η επιλογή σας είναι η >>> [%d]\n",s);
				printf("Οι τιμές που δόθηκαν είναι: A=%d & B=%d \n",a,b);
				printf("\n[i]  Ο αριθμός %d υψομένος στην δύναμη %d είναι --> %d\n",a,b,power(a,b)); 
				printf("[ii]  %d!= %d\t%d!=%d\n",a,paragontiko(a),b,paragontiko(b));
				if(validate_nums (a,b)==1)
				{
					printf("[iii]  Το πλήθος των συνδυασμών %d ανά %d έίναι --> %d\n",a,b,num_combinations(a,b));
					break;
				}
				else
				{
					printf("[iii]  Δεν μπορεί να υπολογιστεί το πλήθος των συνδυασμών %d ανά %d γιατί:\n 1) Eίτε ο αριθμός %d (Α) είναι μικρότερος απο τον αριθμό %d (Β)\n 2) Ένας απο τους 2 (Α=%d ή Β=%d) αριθμούς είναι αρνητικός.\n 3) Ο Αριθμός %d (B) είναι ίσος με 0\n\n",a,b,a,b,a,b,b);
				}	break;
				break;
				
			default:
				system("cls");
				printf("Παρακαλώ επιλέξτε μια από τις παραπάνω επιλογές.\n\n");
		}
}

int plhthos_epilogwn(j)
{
	j++;
	return j;
}

int power (int x , int y)
{
	int i,result=x;
	for (i=1; i<y; i++)
		result*=x;
	return result;
}

int paragontiko (int x)
{
	int i,result=1;
	for (i=1; i<=x; i++)
		result*=i;
	return result;
}

int validate_nums (int N, int K)
{
	if (N>=0 && K>0 && N>K)
		return 1;
	return 0;
}

int num_combinations(int N, int K)
{
	int combinations,x;
	int A= paragontiko (N);
	int B= paragontiko (K);
	int diff= N-K;
	x=paragontiko(diff);
	combinations= A/(B*x);
	return combinations;
}
