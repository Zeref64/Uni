#include <iostream>
#include <string>
#include <exception>

using namespace std;

class SalaryException: public exception{
    private:
        string msg;
    public:
        SalaryException (const string & mesage ){
            msg = mesage;
        }
        const char * what() const noexcept override {
            return msg.c_str();
        }
};

class Employee{
    protected: 
        string name;
        double salary;
    public:
        Employee(const string &name, double salary): name(name){
            if (salary < 0)
                throw SalaryException("Error");
                // throw runtime_error("eee");
                // throw logic_error("fdsd");
            salary = salary;
        }
        virtual void displayInfo () const {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
};

class Manager : public Employee {
    private:
        double bonus;
    public:
        Manager (string name, double sl, double bonus) :
        Employee(name,sl), bonus(bonus){}
        void displayInfo() const override {
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
            cout << "Bonus: " << bonus << endl;
        }
};

int main (int argc, char **argv){
    try{
        Employee worker1("redi",12312);
        Manager mg1("bill",12320,500);
    }
    catch (const SalaryException & e){
        cout << e.what() << endl;
    }
    catch (const exception & e){
        cout << e.what() << endl;
    }
    return 0;
}