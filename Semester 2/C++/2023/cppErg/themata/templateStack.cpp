#include <iostream>
#include <string>

template <typename T>
class MyStack {
    private:
        T *mat;
        int size;
        int head;
    public:
        MyStack(int s){
            mat = new T[s];
            size = s;
            head = 0 ;
        }
        bool Push (T & t){
            if (head == size){
                return false;
            }
            mat [head++] = t;
            return true;
        }
        bool Pop (T t){
            if (head == 0){
                return false;
            }
            t = mat[--head];
            return true;
        }
};
int main (int argc, char **argv){
    MyStack <float> s1(50);
    //Mystack <stud> s2 (5000);
    return 0;
}