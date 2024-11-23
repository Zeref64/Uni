#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*
==============================================================
Προσοχή!
Υπάρχει πολύ σοβαρό λάθος....
Εντοπίστε το.....
Διορθώστε το......
*/ 

template <class T>
class Stack
{
    public:
    T *Mat;
    int Head;
    int Size;

    Stack (int);
    void push (T&);
    T pop ();
    bool isEmpty ();
    bool isFull ();
};

template <class X>
Stack<X>::Stack (int S)
{
    Size = S;
    Head = 0;
    Mat = new X[Size];
}

template <class T>
bool Stack<T>::isEmpty ()
{
    if (Head == 0)
        return true;
    return false;
}

template <typename T>
bool Stack<T>::isFull ()
{
    if (Head == Size)
        return true;
    return false;
}

template <typename T>
void Stack<T>::push (T &Elem)
{
    if (isFull ())
        throw 1;
    Mat [Head++] = Elem;
}

template <class T>
T Stack<T>::pop ()
{
    if (isEmpty ())
        throw 2;
    return Mat [--Head];
}

class TestClass
{
public:
    char *Mess;
    TestClass (char *M)
    {
        Mess = new char[strlen(M) + 1];
        strcpy (Mess, M);
    }
    TestClass () //Για τη στοίβα (New)
    {
        Mess = NULL;
    }
    ~TestClass ()
    {
        
    }
    void set (char *M)
    {
        Mess = new char[strlen(M) + 1];
        strcpy (Mess, M);
    }
};

void Load (Stack<TestClass> &V)
{
    int i;
    char Name[100];
    TestClass TC;
    for (i = 0; i<5; i++)
    {
        cout << "Enter Name: " << i << endl;
        cin >> Name;
        TC.set (Name);
        V.push (TC);        
        

    }
}

int main (int argc, char **argv)
{
    int i;
    Stack<int> S (5);
    for (i = 10; i < 15; i++)
        S.push (i);
    for (i = 1; i<=5; i++)
        cout << S.pop () << endl;
    cout << S.isEmpty () << endl;
    
    Stack<TestClass> S1 (5);
    Load (S1);
    cout << "++++++" << endl;
    for (i = 0; i < 5; i++){
        cout << S1.pop ().Mess << endl;
        delete[] S1.Mat[i].Mess;}

}
