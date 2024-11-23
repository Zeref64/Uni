#include <iostream>
#include "Student.h"
#include <vector>

Student::Student() {}

Student::Student(const char* AM, std::string name, unsigned int semester) : Name(name), Semester(semester) {
    (*this).AM = new char(strlen (AM) + 1);
    strcpy ((*this).AM, AM);
    //* Οι Vectors θα πάρουν τιμές από τους setter  
}

// Constructor με προκαθορισμένη τιμή `1` για το πεδίο εξάμηνο
Student::Student(const char* AM, std::string name) : Name(name), Semester(1) {
    //Δυναμική δέσμευση για τον AM και αντιγραφή του με strcpy
    (*this).AM = new char(strlen (AM) + 1);             
    strcpy ((*this).AM, AM);
}

// Copy Constructor
Student::Student(const Student &studentObject) : Name(studentObject.Name), Semester(studentObject.Semester),
SelectedCourses(studentObject.SelectedCourses), //* new
PassedCourses(studentObject.PassedCourses)
{
    (*this).AM = new char[strlen(studentObject.AM) + 1];
    strcpy((*this).AM, studentObject.AM);
}

//* Επειδή έχει κληθεί new υπάρχει και το delete[] στον destructor
Student::~Student() { delete[] AM; }  

// Getters
const char* Student::getAM() const { return AM; }
std::string Student::getName() const { return Name; }
unsigned int Student::getSemester() const { return Semester; }

//* new
std::vector <const Course*> Student::getSelectedCoursesVector() const { return SelectedCourses; }
std::vector <std::pair<Course*,float>> Student::getPassedCoursesVector() const { return PassedCourses; }
float Student::getCourseAverage() const {
    float sum = 0;
    int totalCourses = 0;
    for (int i = 0; i < PassedCourses.size(); i++) {
        sum += PassedCourses[i].second;
        totalCourses++;
    }
    if (totalCourses == 0) { throw -3; }
    return sum / totalCourses;
}

// Setters
//* Αφαίρεση του προηγούμενου pointer και προσθήκη νέου
void Student::setAM(const char* AM) { 
    delete[] (*this).AM;    
    (*this).AM = new char[strlen (AM) + 1];
    strcpy ((*this).AM, AM);
}
void Student::setName(std::string name) { (*this).Name = Name; } 
void Student::setSemester(unsigned int semester) { (*this).Semester = semester; }
//* new 
void Student::setSelectedCoursesVector(std::vector<const Course*> newSelectedCoursesVector) { (*this).SelectedCourses = newSelectedCoursesVector; }
void Student::setPassedCoursesVector(std::vector<std::pair <Course*, float>> newPassedCoursesVector) {
    for (std::pair<Course*,float> course : newPassedCoursesVector) {
        if ( !((course.second >= 5) && (course.second <= 10)) )
            throw -4;
        (*this).PassedCourses.push_back(course);
    }
} 

// Αλλες Μέθοδοι
void Student::incrementSemester () { ++(*this).Semester; } // Προαύξηση του εξαμήνου
// Αυξηση εξαμήνου κατά `1`
void Student::semesterAddition (int number) { (*this).Semester += number; }
// Μείωση εξαμήνου κατά `number`
void Student::semesterSubtraction (int number) { 

    if ((*this).Semester == 1) {
        throw -2;
    }
    (*this).Semester -= number; 
}

void Student::print (std::ostream &ostream) {
    ostream << "\nAM Φοιτητή >> " << (*this).AM 
    << "\nΌνοματεπώνημο Φοιτητή >> "
    << (*this).Name << "\nΕξάμηνο Φοίτησης >> "
    << (*this).Semester << std::endl;
} 

//* new 
// Τοποθέτηση ενός νέου μαθήματος στην λίστα passedCourses με τον βαθμό του
void Student::addPassedCourse(Course& newCourse, float newGrade) {
    if (newGrade >= 5 && newGrade <= 10) {
    (*this).PassedCourses.push_back(std::make_pair(&newCourse, newGrade));
    }
}

//* Υπερφόρτωση Τελεστών
// Δήλωση νέου μαθήματος στη selectedCourses
void Student::operator += (const Course* newCourse) { 

    for (const Course* course : SelectedCourses)
        if (course == newCourse)
            throw -5;
        SelectedCourses.push_back(newCourse); }

Student& Student::operator = (const Student &studentObject) {
    delete[] (*this).AM; 
    (*this).AM = new char[strlen(studentObject.AM) + 1]; 
    strcpy((*this).AM, studentObject.AM); 
    (*this).Name = studentObject.Name;    
    (*this).Semester = studentObject.Semester;
    (*this).SelectedCourses = studentObject.SelectedCourses;
    (*this).PassedCourses = studentObject.PassedCourses; 
    return *this;
}

bool Student::operator == (const Student& studentObject) const { return (*this).Semester == studentObject.Semester; }
bool Student::operator != (const Student& studentObject) const { return (*this).Semester != studentObject.Semester; }
bool Student::operator < (const Student& studentObject) const { return (*this).Semester < studentObject.Semester; }
bool Student::operator <= (const Student& studentObject) const { return (*this).Semester <= studentObject.Semester; }
bool Student::operator > (const Student& studentObject) const { return (*this).Semester > studentObject.Semester; }
bool Student::operator >=( const Student& studentObject) const { return (*this).Semester >= studentObject.Semester; }

