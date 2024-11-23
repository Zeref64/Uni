#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

class MyString {

    private:
        char* c_string;

    public:
        MyString();
        MyString(char* other_str);
        ~MyString();

        int getlen() const;

        bool operator < (const MyString&) const;
        bool operator == (const MyString&) const;
        MyString& operator = (const MyString&);

        vector<char*> substr(char delimiter);


};

MyString::MyString() {
    this->c_string = new char [1];
    strcpy(this->c_string, "\0");
}

MyString::MyString(char* other_str) {   //? arxikopoihsh string
    this->c_string = new char [strlen(other_str) + 1 ];
    strcpy(this->c_string, other_str);
}

MyString::~MyString() {
    delete [] c_string;
}

int MyString::getlen() const {
    return strlen(this->c_string);
}

bool MyString::operator < (const MyString& other) const{
        return strcmp(this->c_string, other.c_string) < 0;
}
bool MyString::operator == (const MyString& other) const{
    return !(strcmp (this->c_string, other.c_string));
}

MyString& MyString::operator = (const MyString& other) {
    delete [] this->c_string;
    this->c_string = new char [strlen(other.c_string) + 1];
    strcpy(this->c_string, other.c_string);
    return *this;
}

vector<char*> MyString::substr(char delimiter) {
    vector<char*> substring;
    int size = 0;
    for (int i = 0; i < strlen(c_string); i++){
        size++;
        if ( c_string[i] == delimiter )
        {
            char *tmp = new char [size+1];
            // cout << c_string[i]<< endl;
            for (int j=0; j < size; j++)
            {
                tmp[j] = c_string[j];
            }
                tmp[size+1] ='\n';
            
           // ;AAA;BBB
            substring.push_back(tmp);
            size = 0;
        }
    }
        return substring;
}


int main(int argc, char const *argv[])
{
    MyString s1;


    MyString s2("Lina");
    MyString s3("Li;nk;");

    s1 = s3;

    // if (s2 < s3)
    //     cout << "s2 < s3"<< endl;

    // if (s1 == s3)
    //     cout << "s1 == s3"<< endl;
    vector<char*> substr;
    substr = s3.substr(';');

    cout <<substr[1] << endl;

    return 0;
}
