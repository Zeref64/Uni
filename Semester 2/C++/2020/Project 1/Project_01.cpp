#include <iostream>
#include <stdlib.h>
using namespace std;
void changeconst (volatile const int var);
void newdouble (double &var);
int* makedynamicVariable();
int* makedynamicArray();
int& Return_Reference(int *Array);
double addition (double Value_1 , double Value_2 = 1.0);

int main (int argc, char **argv)
{
	system ("chcp 1253");
	volatile const int A=1996; 
	int *Variable;
	int *Array;
	int Reference_Element;
	cout << "Hello World ^^ " << "\n" << endl;
	cout << "constant A = " << A << endl;
 	changeconst(A);
 	double b=1.996;
 	newdouble(b);
 	Variable=makedynamicVariable();
 	cout << "dynamicVariable= " << *Variable << endl;
 	Array=makedynamicArray();
 	Reference_Element=Return_Reference (Array);
 	cout << "The element that got returned by Reference >>> " << Reference_Element << endl;
 	cout << "Addition result (non default)= " << addition(2,4)<< endl;
 	cout << "Addition result (default)= " << addition(3) << endl;
 	delete Variable;
 	delete []Array;
	return 0;
}

void changeconst (volatile const int var)
{
	int *ptr;
	ptr =(int *)&var;
	*ptr=64;
	cout << "constant A got changed to: " << var << endl;
	
}

void newdouble (double &var)
{
	cout << "Variable = " << var << endl;
	cout << "Insert the new value >>> " << endl;
	cin >> var;
	cout << "New Value: " << var << endl;
}

int* makedynamicVariable()
{
	int *dynamicVar= new int(64);
	return dynamicVar;
}

int* makedynamicArray()
{
	int* Array= new int [10];
	for(int i=1; i<=10; i++)
	{
		*(Array+i-1)= i*i;
		cout << "Element " << i << " = "<<*(Array+i-1) << endl;
	}
	return Array;
}

double addition (double Value_1, double Value_2)
{
	double result;
	result= Value_1 + Value_2;
	return result;
}

int& Return_Reference (int *Array)
{
	for (int i=0; i<10; i++)
	{
		if (Array[i]==64)
			return Array[i]; 
	}
	return Array[1];
}
