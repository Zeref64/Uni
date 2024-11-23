#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

template<class T> class Stack {
private:    
    T *stack;
    unsigned int size;

public:
    Stack();
    ~Stack();
    void Push(const T &);
    void Pop();
    unsigned int Size();
    void Save();
};

template<class T> Stack<T>::Stack() : size(0) {}
template<class T> Stack<T>::~Stack() { if (size > 0) delete[] stack; }

template<class T> void Stack<T>::Push(const T &item) {
    unsigned int newSize = size + 1;
    T *old = new T[size];
    for (unsigned int i = 0; i < size; i++) {
        old[i] = stack[i];
    }
    if (size > 0) delete[] stack;
    stack = new T[newSize];
    for (unsigned int i = 0; i < size; i++) {
        stack[i] = old[i];
    }
    stack[size] = item;
    size = newSize;
    delete[] old;
}

template<class T> void Stack<T>::Pop() {
    if (size == 0) return;
    unsigned int newSize = size - 1;
    T *old = new T[size];
    for (unsigned int i = newSize; i > 0; i--) {
        old[i] = stack[size - i - 1];
    }
    delete[] stack;
    stack = new T[newSize];
    for (unsigned int i = 0; i < newSize; i++) {
        stack[i] = old[i + 1];  
    }
    size = newSize;
    delete[] old;
}

template<class T> unsigned int Stack<T>::Size() { 
    return size; 
}

template<class T> void Stack<T>::Save() {
    ofstream ofile("stack.txt");
    if (ofile.is_open()) {
        for (unsigned int i = 0; i < size; i++) {
            ofile << stack[i].toString() << endl;
        }
        ofile.close();
    }
}

class StackItem {
private:
    float num;
    char *str;

public:
    StackItem();
    StackItem(float, const char*);
    ~StackItem();
    StackItem &operator=(const StackItem &);
    string toString() const;
};

StackItem::StackItem() : str(nullptr) {} // Set str to nullptr
StackItem::StackItem(float f, const char* s) {
    num = f;
    str = new char[strlen(s) + 1]; // Account for the null terminator
    strcpy(str, s);
}
StackItem::~StackItem() { 
    delete[] str; // Safe to delete even if str is nullptr
}
StackItem &StackItem::operator=(const StackItem &si) {
    num = si.num;
    if(str) delete[] str; // Check if str is not nullptr before deleting
    str = new char[strlen(si.str) + 1]; // Account for the null terminator
    strcpy(str, si.str);
    return *this;
}
string StackItem::toString() const {
    return to_string(num) + " " + str;
}

int main(int argc, char** argv) {
    Stack<StackItem> s;
    Stack<StackItem> s1(StackItem);
    for (int i = 0; i < 10; i++) {
        s.Push(StackItem(i, "cstring :V"));
    }
    s.Pop();
    cout << s.Size() << endl;
    s.Save();
    return 0;
}