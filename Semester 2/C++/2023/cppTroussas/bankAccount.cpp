#include <iostream>
#include <string>
#include <exception>

using namespace std;

class FoundException: public exception {
    public:
        const char * what() const noexcept override {
            return "Error δεν υπαρχουν χρηματα";
        }
};

class BankAccount {
    private: 
        double balance;
    public:
        BankAccount(double balance): balance(balance){}
        void withdraw (double amount);
};

void BankAccount::withdraw (double amount){
    if (amount > balance){
        // throw FoundException();
        throw logic_error("dsaffdsfds");
    }
    balance -= amount;
    cout << "Επιτυχης ανάληψη: " << amount << endl;
}

int main (int c, const char * v[]){
    try{
        BankAccount account1(200.0);
        double amount;
        cout << "Χρήματα ανάληψης" << endl;
        cin >> amount;
        account1.withdraw(amount);
    }
    catch (const exception & e){
        cout << "Εξαίρεση " << e.what() << endl;
    }
    return 0;
}