#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Student {
private:
    char *AM;                     // Unique identifier for the student
    string Name;                  // Name of the student
    unsigned int CurrentSemester; // Current semester the student is in

public:
    // Default constructor
    Student();

    // Parameterized constructor
    Student(const char *AM, const string &Name);

    // Copy constructor
    Student(const Student &other);

    // Destructor
    ~Student();

    // Getter for AM
    const char *getAM() const;

    // Getter for Name
    const string &getName() const;

    // Getter for CurrentSemester
    unsigned int getCurrentSemester() const;

    // Setter for AM
    void setAM(const char *AM);

    // Setter for Name
    void setName(const string &Name);

    // Setter for CurrentSemester
    void setCurrentSemester(unsigned int CurrentSemester);

    // Overloaded increment operator
    Student &operator++();
    Student operator++(int);

    // Overloaded += and -= operators
    Student &operator+=(unsigned int semesters);
    Student &operator-=(unsigned int semesters);

    // Overloaded ostream operator<<
    friend ostream &operator<<(ostream &os, const Student &student);
};

// Default constructor implementation
Student::Student() {
    AM = new char[1];
    AM[0] = '\0';
    Name = "";
    CurrentSemester = 1;
}

// Parameterized constructor implementation
Student::Student(const char *AM, const string &Name) {
    this->Name = Name;
    CurrentSemester = 1;
    this->AM = new char[strlen(AM) + 1];
    strcpy(this->AM, AM);
}

// Copy constructor implementation
Student::Student(const Student &other) {
    Name = other.Name;
    CurrentSemester = other.CurrentSemester;
    AM = new char[strlen(other.AM) + 1];
    strcpy(AM, other.AM);
}

// Destructor implementation
Student::~Student() {
    delete[] AM;
}

// Getter for AM implementation
const char *Student::getAM() const {
    return AM;
}

// Getter for Name implementation
const string &Student::getName() const {
    return Name;
}

// Getter for CurrentSemester implementation
unsigned int Student::getCurrentSemester() const {
    return CurrentSemester;
}

// Setter for AM implementation
void Student::setAM(const char *AM) {
    delete[] this->AM;
    this->AM = new char[strlen(AM) + 1];
    strcpy(this->AM, AM);
}

// Setter for Name implementation
void Student::setName(const string &Name) {
    this->Name = Name;
}

// Setter for CurrentSemester implementation
void Student::setCurrentSemester(unsigned int CurrentSemester) {
    this->CurrentSemester = CurrentSemester;
}

// Overloaded increment operator implementation
Student &Student::operator++() {
    CurrentSemester++;
    return *this;
}

Student Student::operator++(int) {
    Student temp = *this;
    CurrentSemester++;
    return temp;
}

// Overloaded += operator implementation
Student &Student::operator+=(unsigned int semesters) {
    CurrentSemester += semesters;
    return *this;
}

// Overloaded -= operator implementation
Student &Student::operator-=(unsigned int semesters) {
if (semesters >= CurrentSemester) {
CurrentSemester = 1;
} else {
CurrentSemester -= semesters;
}
return *this;
}

// Overloaded ostream operator<< implementation
ostream &operator<<(ostream &os, const Student &student) {
os << "AM: " << student.AM << ", Name: " << student.Name << ", Current Semester: " << student.CurrentSemester;
return os;
}

int main() {
// Create a student object with the parameterized constructor
Student student1("18390173", "Nikolaos Sergis");
// Display student1's information using the overloaded << operator
cout << student1 << endl;
// Increment student1's semester using the overloaded ++ operator
student1++;

// Display student1's information again using the overloaded << operator
cout << student1 << endl;

// Add 2 semesters to student1 using the overloaded += operator
student1 += 2;

// Display student1's information again using the overloaded << operator
cout << student1 << endl;

// Subtract 3 semesters from student1 using the overloaded -= operator
student1 -= 3;

// Display student1's information again using the overloaded << operator
cout << student1 << endl;

// Create a copy of student1 using the copy constructor
Student student2(student1);

// Display student2's information (should be the same as student1)
cout << student2 << endl;

// Set new values for student2's attributes using the setters
student2.setAM("98765432");
student2.setName("John Doe");
student2.setCurrentSemester(5);

// Display student2's information again using the overloaded << operator
cout << student2 << endl;

return 0;
}