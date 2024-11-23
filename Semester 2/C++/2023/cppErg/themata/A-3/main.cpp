#include <iostream>
#include <cstring>

using namespace std;

template <class Q>
class Queue
{
    Q *queue;
    int bottom;
    int top;
    int size;

public:
    Queue(int S);
    
    void Empty();
    void Full();
    void Push(const Q value);
    void Pop();
    int Size();
    void Print();
    void operator==(const Queue &Q1);
};

template <class Q>
Queue<Q>::Queue(int S) : size(S)
{
    queue = new Q[size];
    bottom = top = 0;
}

template <class Q>
void Queue<Q>::Empty()
{
    if (bottom > top)
        throw 10;
    return;
}

template <class Q>
void Queue<Q>::Full()
{
    if (top >= size)
        throw 20;
    return;
}

template <class Q>
void Queue<Q>::Push(const Q value)
{
    Full();
    if (bottom == 0 && top == 0)
        bottom = 0;
    queue[top++] = value;
}

template <class Q>
int Queue<Q>::Size()
{
    return top;
}

template <class Q>
void Queue<Q>::Pop()
{
    bottom++;
    Empty();
    return;
}

template <class Q>
void Queue<Q>::Print()
{
    for (int i = bottom; i < top; i++)
        std::cout << " Data1 : " << queue[i]->GetData1() << " Data 2 : " << " | " << queue[i]->GetData2() << std::endl;
}

template <class Q>
void Queue<Q>::operator==(const Queue &Q1)
{
    int counter = 0;
    if (Q1.top > this->top)
        std::cout << "NOT EQUAL " << std::endl;
    else if (Q1.top < this->top)
        std::cout << "NOT EQUAL " << std::endl;
    else if (Q1.top == this->top)
    {
        for (int i = 0; i < this->top; i++)
        {
            if (this->queue[i]->GetData2() != Q1.queue[i]->GetData2() ||
                strcmp(this->queue[i]->GetData1(), Q1.queue[i]->GetData1()) != 0)
            {
                counter++;
            }
        }
        if (counter > 0)
            std::cout << "NOT EQUAL" << std::endl;
        else
            std::cout << "EQUAL" << std::endl;
    }
}

class Data
{
    char *Data1;
    int Data2;

public:
    Data();
    Data(const char *D1, int D2);
    const char *GetData1();
    int GetData2();
};

Data::Data() {}

Data::Data(const char *D1, int D2) : Data2(D2)
{
    Data1 = new char[strlen(D1)];
    strcpy(Data1, D1);
}

const char *Data::GetData1()
{
    return Data1;
}

int Data::GetData2()
{
    return Data2;
}

int main(int argc, char *argv[])
{
    try
    {
        Data D1("TTsKO o/ DEN KSEREIS OURES", 10);
        Data D2("TTsKO DEN KSEREIS ONTOS APO OURES", 20);
        Queue<Data *> Queue(10);
        Queue.Push(&D1);
        Queue.Push(&D2);
        Queue.Print();
        std::cout << std::endl;
        Queue.Pop();
        Queue.Print();
        std::cout << std::endl;
        Queue.Pop();
    }
    catch (int S)
    {
        if (S == 20)
            cout << "FULL" << endl;
        else if (S == 10)
            cout << "EMPTY" << endl;
    }
    return 0;
}