#include <stdio.h>
#include <math.h>
int input ();
double Radd (int degrees);
double sinnx (double rad);
double cossx (double rad);
int diff (double x, double y);
void check(double x,double y,double z, double c);
int main ()
{
	system ("chcp 1253");
	int Degrees;
	Degrees=input();
	double rad=Radd(Degrees);
	printf("Το ημ(x) των %d Μοιρών είναι: %lf\n",Degrees,sinnx(rad));
	printf("Το ημ(x) της έτοιμης συνάρτησης Sin(x) της C είναι: %lf\n\n",sin(rad));
	printf("Το συν(x) των %d Μοιρών είναι: %lf\n",Degrees,cossx(rad));
	printf("Το συν(x) της έτοιμης συνάρτησης Cos(x) της C είναι: %lf\n\n",cos(rad));
	check(sinnx(rad),sin(rad),cossx(rad),cos(rad));
	return 0;
}

double sinnx (double rad)
{
	
	int prosimo=1,ekthetes=1;
	int i,FLAG=0;
	double SINX=0,temp=0,klasma;
	do
	{
		klasma=1;
		for(i=1;i<=ekthetes;i++)
			klasma=klasma*(rad/i);
		ekthetes+=2;
		SINX+=(prosimo*klasma);
		prosimo=prosimo*(-1);
		if (diff(temp,klasma)==1)
			FLAG=1;
		else
			FLAG=0;
		temp=klasma;
	}
	while(FLAG==0);
	return SINX;
}

double cossx (double rad)
{
	int prosimo=-1,ekthetes=2;
	int i,FLAG=0;
	double COSX,temp=0,klasma;
	COSX=1;
	do
	{
		klasma=1;
		for(i=1;i<=ekthetes;i++)
			klasma=klasma*(rad/i);
		ekthetes+=2;
		COSX+=(prosimo*klasma);
		prosimo=prosimo*(-1);
		if (diff(temp,klasma)==1)
			FLAG=1;
		else
			FLAG=0;
		temp=klasma;
	}
	while(FLAG==0);
	return COSX;
}
double Radd (int degrees)
{
	double pi=3.141592,Rad;
	Rad=degrees*pi/180;
	return Rad;
}

int diff(double x, double y)
{
	double t=0.0000009;
	if (fabs(x-y)<=t)
		return 1;
	return 0;
}

int input ()
{
	int Degrees;
	do
	{
		printf("Δώσε τις μοίρες της γωνίας : ");
		scanf("%d",&Degrees);
		printf("Οι Μοίρες που δόθηκαν είναι: %d\n",Degrees);
		if(Degrees < 0 || Degrees > 360)
		{
			printf("Δεν υπάρχει γωνία με %d μοίρες.. Παρακαλώ προσπαθήστε ξανά.\n\n",Degrees);
		}
	}while(Degrees < 0 || Degrees > 360 );
	printf("Η μετατροπή των %d Μοιρών σε Ακτίνια είναι: %lf\n\n",Degrees,Radd(Degrees));
	return Degrees;
}
void check(double x,double y,double z,double c)
{
	printf("My sin=%lf  sin=%lf\n\nMy cos=%lf  cos=%lf\n",x,y,z,c);
	if (diff(x,y)==1 && diff(z,c)==1)
		printf("\n-=[Το πρόγραμμα δουλεύει σωστά!]=-\n");
	else
		printf ("\n-=[Το πρόγραμμα είναι λάθος!]=-\n");
}
