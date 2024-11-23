#include <iostream>
#include <string>

using namespace std;

class Person {

protected:
    Person();

public:

    virtual ~Person();


    virtual string getName() = 0;
};

Person::Person() {}

Person::~Person() {
    cout << "Destruction of Person" << endl;
}







class Student : public Person {
private:
    string name;
public:
    Student();
    Student(string);
    ~Student();
    string getName() override;
};

Student::Student() {
    cout << "Construction of Student" << endl;
}

Student::Student(string name) : name(name) {
    cout << "Construction of Student named " << name << endl;
}

Student::~Student() {
    cout << "Destruction of Student named " << name << endl;
}

string Student::getName() {
    return name;
}

class Professor : public Person {
private:
    string name;
public:
    Professor();
    Professor(string);
    ~Professor();
    string getName();
};

Professor::Professor() {
    cout << "Construction of Professor" << endl;
}

Professor::Professor(string name) : name(name) {
    cout << "Construction of Professor named " << name << endl;
}

Professor::~Professor() {
    cout << "Destruction of Professor named " << name << endl;
}

string Professor::getName() {
    return name;
}

int main(int argc, char** argv) {
    const int PEEPS = 4;
    Person* people[PEEPS];
    people[0] = new Student();
    people[1] = new Professor();
    people[2] = new Student("KEKW");
    people[3] = new Professor("KEKES");

    for (int i = 0; i < PEEPS; i++) {
        cout << "Name: " << people[i]->getName() << endl;
    }

    for (int i = 0; i < PEEPS; i++) {
        delete people[i];
    }

    return 0;
}