#include <iostream>
#include <cstring>

class MyString
{
private:
    char *string;
    unsigned int length;

public:
    MyString();
    MyString(const char *);
    MyString(const MyString &);
    ~MyString();
    bool operator==(const MyString &);
    bool operator!=(const MyString &);
    bool operator>(const MyString &);
    bool operator<(const MyString &);
    MyString &operator+=(const char);
    const char *to_cstring();
    const unsigned int str_length();
};
MyString::MyString() : length(0)
{
    string = new char[length];
    strcpy(string, "");
}
MyString::MyString(const char *str)
{
    length = strlen(str);
    string = new char[length];
    strcpy(string, str);
}
MyString::MyString(const MyString &myString)
{
    length = myString.length;
    string = new char[length];
    strcpy(string, myString.string);
}
MyString::~MyString() { delete[] string; }
bool MyString::operator==(const MyString &myString)
{
    if (length != myString.length)
        return false;
    return strcmp(string, myString.string) == 0;
}
bool MyString::operator!=(const MyString &myString)
{
    return !(*this == myString);
}
bool MyString::operator>(const MyString &myString)
{
    return strcmp(string, myString.string) > 0;
}
bool MyString::operator<(const MyString &myString)
{
    return strcmp(string, myString.string) < 0;
}
MyString &MyString::operator+=(const char c)
{
    unsigned int newLength = length + 1;
    char *old = new char[length];
    strcpy(old, string);
    delete[] string;
    newLength;
    string = new char[newLength];
    strcpy(string, old);
    string[length] = c;
    string[newLength] = '\0';
    length = newLength;
    delete[] old;
    return *this;
}
const char *MyString::to_cstring() { return string; }
const unsigned int MyString::str_length()
{
    return length;
}
int main(int argc, char **argv)
{
    MyString str1;
    std::cout << "String: " << str1.to_cstring() << std::endl;
    std::cout << "Length: " << str1.str_length() << std::endl;
    std::cout << std::endl;
    str1 += 'a';
    str1 += 'b';
    std::cout << "String: " << str1.to_cstring() << std::endl;
    std::cout << "Length: " << str1.str_length() << std::endl;
    std::cout << std::endl;
    MyString str2("Hello, World!");
    std::cout << "String: " << str2.to_cstring() << std::endl;
    std::cout << "Length: " << str2.str_length() << std::endl;
    std::cout << std::endl;
    MyString str3(str1);
    std::cout << "String: " << str3.to_cstring() << std::endl;
    std::cout << "Length: " << str3.str_length() << std::endl;
    std::cout << std::endl;
    std::cout << "str1 == str2: " << (str1 == str2) << std::endl;
    std::cout << "str1 != str3: " << (str1 != str3) << std::endl;
    std::cout << "str2 < str3: " << (str2 < str3) << std::endl;
    std::cout << "str2 > str3: " << (str2 > str3) << std::endl;
    return 0;
}


//? Να δημιουργηθεί η κλάση “MyString” η οποία θα παριστά συμβολοσειρές. Η κλάση θα πληροί τις ακόλουθες προδιαγραφές:

//? ● Θα αρχικοποιείται με την κενή συμβολοσειρά, με
//? ένα C String, ή ένα άλλο
//? αντικείμενο MyString.

//? ● Θα υπερφορτώνει τους τελεστές “==”, “!=”, “>”
//? και “<” ώστε να εκτελούν τις
//? αντίστοιχους ελέγχους.

//? ● Θα υπερφορτώνει τον τελεστή “+=” ώστε να
//? προσθέτει ένα χαρακτήρα στο
//? τέλος της συμβολοσειράς.

//? ● Θα επιστρέφει τη συμβολοσειρά ως C String.

//? ● Θα επιστρέφει το μήκος της συμβολοσειράς.

//? Να επιδειχθεί η λειτουργία της κλάσης μέσω
//? κατάλληλης main συνάρτησης. Για την
//? υλοποίηση των παραπάνω δεν θα χρησιμοποιηθεί
//? η κλάση string της STL.