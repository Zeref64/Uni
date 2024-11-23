#include <iostream>
#include <string>
#include <exception>


using namespace std;

class calculator {
    public:
        static double divide (double num, double dieretis);

};

double calculator::divide (double num, double dieretis){
    if (dieretis == 0){
        throw logic_error("Διαιρεση με 0");
        // throw exception();
    }
    return num/dieretis;
}

int main(int argc, char const *argv[])
{
    double num1,num2;
    cout << "Αριθμος 1:" << endl;
    cin >> num1;
    cout << "Αριθμος 2:" << endl;
    cin >> num2;

    try {
        double result = calculator::divide (num1,num2);
        cout << "Αποτέλεσμα: " << result << endl;
    }
    catch (const exception & e){
        cout << "Exception " << e.what() << endl;
    }
    return 0;
}