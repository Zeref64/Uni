#include <stdio.h>
#include <math.h>
int main()
{
	
	system("chcp 1253");
	int summary=0,difference=0,multiplication=0,division=0,power=0,modd=0;
	double float_div=0.0,square_root=0.0;
	int num1,num2;
	printf("Αυτό το πρόγραμμα θα βρίσκει: ¶θροισμα, Διαφορά, Γινόμενο, Πηλίκο,Υπόλοιπο. \n");
	printf("Επιπλέον, θα εμφανίζει τον πρώτο αριθμό υψομένο στο τετράγωνο, \n");
	printf("την τετραγωνική ρίζα της Δεύτερης τιμής και τελος το πραγματικό Πηλίκο των δύο τιμών\n");
	printf("-/============================oooo=============================\\- \n\n\n\n\n");
	/*                                                                                     */
	printf("Εισάγετε την Πρώτη τιμή >>> \t");
	scanf("%i", &num1);
	printf("Εισάγετε την Δεύτερη τιμή >>> \t");
	scanf("%i", &num2);
	printf("\n\n");
	summary= (num1 + num2);
	difference= (num1 - num2);
	multiplication= (num1 * num2);
	division= (num1 / num2);
	modd= (num1 % num2);
	float_div= (double)num1 / num2 ;
	power= pow(num1,2);
	square_root= sqrt(num2);
	/*                                               */
	printf ("\t %i \t   <-- Άθροισμα  +\n",summary);
	printf ("\t %i \t   <-- Διαφορά  -\n",difference);
	printf ("\t %i \t   <-- Γινόμενο X\n",multiplication);
	printf ("\t %i \t   <-- Πηλίκο  /\n",division);
	printf("\t %lf  <-- Πραγματικό Πηλίκο  //\n",float_div);
	printf ("\t %i \t   <-- Υπόλοιπο Διαίρεσης % \n", modd);
	printf ("\t %i \t   <-- Ύψωση στο Τετράγωνο  %i^2\t ___\n",power,num1);
	printf ("\t %lf  <-- Τετραγωνική Ρίζα του %i\tV\n", square_root,num2);
	printf("\n");
	
	return 0; 
}
