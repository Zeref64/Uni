#include <iostream>
#include <stdlib.h>
using namespace std;

void swap(int x, int y); // call by Value
void swapPtr(int *x, int *y); //call by Pointer
void swapRef (int &x, int &y); // call by Reference

int main ()
{
	int a = 10;
	int b = 64;
	cout << "Before:\t";
	cout << "a = " << a << "\tb = " << b <<"\n";
	
	//swap (a,b);
	//swapPtr (&a,&b);
	swapRef (a,b);
	cout << "After:\t";
	cout << "a = " << a << "\tb = " << b;
	return 0;
}

void swap (int x, int y)
{
	int tmp;
	tmp = x;
	x = y;
	tmp = y;
	return;	
}

void swapPtr(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return;	
}

void swapRef (int &x, int &y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
	return;
}

