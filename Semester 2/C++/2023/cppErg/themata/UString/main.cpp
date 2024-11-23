#include <cstring>
#include <iostream>

using namespace std;

class uString {


    private:
        char* string;
    
    public:
        uString();
        ~uString();

};

uString::uString() {
}

uString::~uString(){
    delete [] string;
}


uString* makestring(int N, int K);

int main(int argc, char const *argv[])
{
    
    return 0;
}

uString* makestring(int N, int K) {

    uString string1 = new uString(sizeof(char));
    


}
