#include <iostream>
#include <string>

template <typename T>
class MyStack {
    private:
        T *mat;
        int size;
        int head;
    public:
        MyStack(int s) {
            mat = new T[s];
            size = s;
            head = 0 ;
        }

        T getMat(int i) const{

            return mat[i];
        }
        
        bool Push (T t){ 
            if (head == size){
                return false;
            }
            mat [head++] = t;
            return true;
        }

        bool Pop (T& t){
            if (head == 0){
                return false;
            }
            t = mat[--head];
            return true;
        }
};
int main (int argc, char **argv){
    MyStack <float> s1(50);
    s1.Push(10.2);
    s1.Push(22.3);
    float tmp;
    s1.Pop(tmp);
    std::cout<<tmp<<std::endl;
    // std::cout<<s1.getMat(1)<<std::endl;
    //Mystack <stud> s2 (5000);
    return 0;
}