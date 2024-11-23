#include <iostream>
#include <cstring>
#include <string>

using namespace std;


template <typename type>
class MyVector {

    private:
        type* vector;
        int size;

    public:
        MyVector();
        MyVector(int size_);
        ~MyVector();

        void push_back(type item);
        void pop(int position);

        type operator[](int position);
};

template<typename type>
type MyVector<type>::operator[] (int pos) {
    if (!pos >= 0 && pos < size) {
        return vector[pos];
    }
    else {
        throw -1;
    }
}


template<typename type>
MyVector<type>::MyVector() : size(0){}

template<typename type>
MyVector<type>::~MyVector(){

    delete[] vector;
}

template<typename type>
void MyVector<type>::push_back(type item) { 

    if (size == 0){
        this->vector = new type [size + 1];
        this->vector[0] = item; 
        this->size++;
        cout<<"push size 0"<<endl;
    }else{
        cout<<"push"<<endl;
        type* newVector = new type[this->size]; 
        for (int i = 0; i < size; i++) 
            newVector[i] = this->vector[i];
        delete [] this->vector;

        this->vector = new type[this->size + 1]; 
        for (int i = 0; i < size; i++) 
            this->vector[i] = newVector[i];

        this->vector[size] = item;
        size++;
        delete[] newVector;
    }
    
}

template<typename type>
void MyVector<type>::pop(int position) {

    cout<<"pop"<<endl;
    if (size != 0) {
        type* smallerVec = new type[size - 1];
        int j = 0;
        for (int i = 0; i < size - 1; i++)
        {
            if (i != position){
                smallerVec[j] = this->vector[i]; 
                j++;
            }
        }
        delete[] this->vector;
        this->vector = smallerVec;
        size--;
    
    }

}

class Item {

    private:

        char* c_string;
        float number;

    public:
        Item();
        Item(char* cstr, float num);
        ~Item();

        float getFloat() const;
};

Item::Item(){}

Item::Item(char* cstr, float num) : number(num) {
    this->c_string = new char [strlen(cstr)+1];
    strcpy(this->c_string, cstr);
}

Item::~Item(){}

float Item::getFloat() const {
    return number;
}
int main(int argc, char const *argv[])
{

    Item item1("i am 1", 2.0);
    Item item2("i am 2", 10.0);
    Item item3("i am 2", 14.0);
    Item item4("i am 2", 20.0);
    MyVector<Item> vec1;
    vec1.push_back(item1);
    vec1.push_back(item2);
    vec1.push_back(item3);
    vec1.push_back(item4);
    vec1.pop(0);

    
    Item item10;
    item10 = vec1[0];
    cout << item10.getFloat() << endl;
    return 0;
}