#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void changeConstant(volatile const double &);
int* makeDynamicVariable();
int* makeDynamicArray();
void addValue(int &, int = 64);  //Default τιμή 64.
void addValue(float &, float = 64.22);   //Default τιμή 64.22.
int& returnReference (int *);



int main (int argc, char **argv) 
{

    //system ("chcp 1253"); 
    srand (time(NULL)); 

    volatile const double constVariable =32.6;
    int *dynamicVariable;
    int *dynamicArray;
    int intVariable = 1;
    float floatVariable = 3.5;

    //Αλλαγή τιμής σταθεράς.
    cout << "Παλιά const τιμή: " << constVariable << endl;
    changeConstant(constVariable);
    cout << "Νέα const τιμή: " << constVariable << endl;

    //Δημιουργία δυναμικής μεταβλιτής.
    dynamicVariable = makeDynamicVariable();

    //Δημιουργία δυναμικού πίνακα.
    dynamicArray = makeDynamicArray();

    //Προσθέτω την τιμή 64 (default τιμή)
    cout << "Παλιά τιμή = " << intVariable << endl;
    addValue(intVariable);
    cout << "Νέα τιμή:  = " << intVariable << endl;

    //Προσθέτω την τιμή 5 
    addValue(intVariable, 5);
    cout << "Default τιμή: " << intVariable << endl;

    //Υπερφόρτωση για float μεταβλητές
    cout << "Παλιά float τιμή = " << floatVariable << endl;
    addValue(floatVariable,2.5);
    cout << "Νέα float τιμή:  = " << floatVariable << endl;

    //Επιστροφή στοιχείου μέσω αναφοράς
    int &referenceElement = returnReference(dynamicArray);
    cout << "Στοιχείο που επέστρεψε: " << referenceElement << endl;
    /*Αφού αλλάξω την τιμή στο referenceElement παρατηρώ οτι αλλάζει και στον πίνακα
    επειδή το referenceElement είναι η αναφορά του στοιχείου*/
    referenceElement = 444;
    cout << "Τέταρτο στοιχείο του dynamicArray = " << *(dynamicArray + 4)<< endl; 

	delete dynamicVariable;
    delete [] dynamicArray;
    return 0;
}

//Αλλαγή const τιμής με χρήση pointer
void changeConstant(volatile const double &constVariable)
{
    double *doubleptr;
    doubleptr = (double *) &constVariable; //Αλλάζω τον τύπο της αναφοράς σε (double *) με σκοπό να μην βγάζει λάθος
    *doubleptr = 158.64;

}

/*Φτιάχνω μια δυναμική int variable με τον τελεστή new που έχει 
τιμή 64 και την επιστρέφω*/
int* makeDynamicVariable() 
{

    int *dynamicVariable = new int(64); //Δημιουργέι έναν integer στο heap με τιμή 64.
    return dynamicVariable;    
    
}

/*Φτιάχνω έναν δυναμικό πίνακα με 5 τυχαία int και τον επιστρέφω*/
int* makeDynamicArray() 
{
    int* dynamicArray = new int[5]; //Δεσμεύει δυναμικά στο heap χώρο 5 integers
    for (int i = 0; i < 5; i++)
    {
        *(dynamicArray+i) = rand() % 10 + 1;    //Γεμίζει τον πίνακα με 4 τυχαίες τιμές
        *(dynamicArray+4) = 64;     
        cout << "Element " << i << " = [" <<*(dynamicArray+i) <<  "]" << endl;
    }
    return dynamicArray;
}

//Πρόσθεση μιας τιμής με την χρήση αναφοράς
void addValue(int &destination, int value)
    {
        destination += value;
    }

//Υπερφόρτωση της παραπάνω συνάρτησης για float
void addValue(float &destination, float value)
    {
        destination += value;
    }

//Επιστροφή αναφοράς ενός στοιχείου 
int& returnReference (int *Array)
{
	for (int i=0; i<5; i++)
	{
		if (Array[i]==64)
			return Array[i];    //Επιστρέφει την αναφορά του στοιχείου εάν έχει την τιμή 64.
	}
	return Array[1];    //Αλλιώς επιστρέφει το δεύτερο στοιχείο.
}
