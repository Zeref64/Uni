#include <stdio.h>
#include <math.h>
int main()
{
	system("chcp 1253");
	double Mhkos_akmhs_Kyvou;
	double Ogkos_Kyvou,Emvadon_Kyvou;
	double Ogkos_Sfairas,Emvadon_Sfairas;
	const double pi = 3.14;
	printf("Αυτό το πρόγραμμα θα δέχεται ως είσοδο το μήκος της ακμής ενός Κυβου σε μέτρα (m)");
	printf("και ύστερα θα εμφανίζει το Εμβαδόν και τον Όγκο του συγκεκριμένου Κύβου.\n");
	printf("Επιπλέον θα υπολογίζει τον Έμβαδον και τον Όγκο μιας Σφαίρας λαμβάνοντας υπόψη την τιμή ακμής του κύβου ");
	printf("σε μέτρα (m) που δόθηκε προηγουμένως.\n");
	printf("-/============================oooo=============================\\- \n\n\n\n\n");
	/*                                                                                                               */
	printf("Εισάγετε το μήκος ακμής του Κύβου σε μέτρα (m) >>> ");
	scanf("%lf",&Mhkos_akmhs_Kyvou);
	printf("\n\n");
	Ogkos_Kyvou= pow(Mhkos_akmhs_Kyvou,3);
	Emvadon_Kyvou= 6 * pow(Mhkos_akmhs_Kyvou,2);
	Ogkos_Sfairas= 4* pi * pow(Mhkos_akmhs_Kyvou,2);
	Emvadon_Sfairas= (4.0/3) * pi * pow(Mhkos_akmhs_Kyvou,3);
	/*                                                                                                               */
	printf("\t\t\t\t/--(Κύβος)--/\n\n\n");
	printf("- Ο Όγκος ενός Κύβου όταν το μήκος ακμής του σε μέτρα (m) \n  έχει την τιμή: %lf\n",Mhkos_akmhs_Kyvou);
	printf("είναι -->   \t\t\t %lf",Ogkos_Kyvou);
	printf("   \t\t\t<--\n\n\n");
	printf("- Το Εμβαδόν ενός Κύβου όταν το μήκος ακμής του σε μέτρα (m) \n  έχει την τιμή: %lf\n",Mhkos_akmhs_Kyvou);
	printf("είναι -->   \t\t\t %lf",Emvadon_Kyvou);
	printf("   \t\t\t<--\n\n\n");
	printf("\t\t\t\t/--(Σφαίρα)--/\n\n\n");
	printf("- Ο Ογκος μιας Σφαίρας όταν το μήκος ακμής σε που δόθηκε σε μέτρα (m) \n  έχει την τιμή: %lf\n",Mhkos_akmhs_Kyvou);
	printf("είναι -->   \t\t\t %lf",Ogkos_Sfairas);
	printf("   \t\t\t<--\n\n\n");
	printf("- Το Εμβαδόν μιας Σφαίρας όταν το μήκος ακμής σε που δόθηκε σε μέτρα (m) \n  έχει την τιμή: %lf\n",Mhkos_akmhs_Kyvou);
	printf("είναι -->   \t\t\t %lf",Emvadon_Sfairas);
	printf("   \t\t\t<--\n");
	return 0;
}
