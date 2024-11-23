#include <list>
#include <iostream>
#include <string>

class Person {
protected:
    std::string name;
    int age;

public:
    Person(const std::string& n,  int a) : name(n), age(a) {} //! & και const

    virtual void print() {
        std::cout << "Name: " << name << " Age: " << age << std::endl;
    }
};

class Student : public Person {
protected:
    std::string major;

public:
    Student(const std::string& n, int a, const std::string& m) : Person(n, a), major(m) {}


    void print() {
        std::cout << "Name: " << name << " Age: " << age << " Major: " << major << std::endl;
    }
};

int main() {
    Person p1("Chris", 30);
    p1.print();

    Student s1("Maria", 20, "00P");
    s1.print();

// deixnei to person se antikeimeno student
    Person* ptr = &s1;

    // std::list<Person *> list1;
    // list1.push_back(&s1);
    // list1.push_back(&p1);


    //ektelei tin virtual print
    ptr->print();

    return 0;
}