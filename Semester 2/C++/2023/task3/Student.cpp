#include <iostream>
#include "Student.h"
#include <vector>

Student::Student() {}

Student::Student(const char *AM, std::string Name, unsigned int semester) {
    (*this).AM = new char(strlen (AM) + 1);
    strcpy ((*this).AM, AM);
    (*this).Name = Name;    
    (*this).semester = semester;
    //* Οι Vectors θα πάρουν τιμές από τους setter  
}

// Constructor με προκαθορισμένη τιμή `1` για το πεδίο εξάμηνο
Student::Student(const char *AM, std::string Name) {
    //Δυναμική δέσμευση για τον AM και αντιγραφή του με strcpy
    (*this).AM = new char(strlen (AM) + 1);             
    strcpy ((*this).AM, AM);
    (*this).Name = Name;
    (*this).semester = 1;   
}

// Copy Constructor 
Student::Student(const Student& studentObject) {
    (*this).AM = new char[strlen(studentObject.AM) + 1];
    strcpy((*this).AM, studentObject.AM);     
    (*this).Name = studentObject.Name;    
    (*this).semester = studentObject.semester;
    //* new
    (*this).selectedCourses = studentObject.selectedCourses;
    (*this).passedCourses = studentObject.passedCourses;
}

//* Επειδή έχει κληθεί new υπάρχει και το delete[] στον destructor
Student::~Student() { delete[] AM; }  

// Getters
const char* Student::getAM() const { return AM; }
std::string Student::getName() const { return Name; }
unsigned int Student::getSemester() const { return semester; }
//* new
std::vector <const Course*> Student::getSelectedCoursesList() const { return selectedCourses; }
std::vector <std::pair<Course*,float>> Student::getPassedCoursesList() const { return passedCourses; }
float Student::getCourseAverage() const {
    float sum = 0;
    int totalCourses = 0;
    for (int i = 0; i < passedCourses.size(); i++) {
        sum += passedCourses[i].second;
        totalCourses++;
    }
    if (totalCourses == 0) { return 0.0; }
    return sum / totalCourses;
}

// Setters
//* Αφαίρεση του προηγούμενου pointer και προσθήκη νέου
void Student::setAM(const char *AM) { 
    delete[] (*this).AM;    
    (*this).AM = new char[strlen (AM) + 1];
    strcpy ((*this).AM, AM);
}
void Student::setName(std::string Name) { (*this).Name = Name; } 
void Student::setSemester(unsigned int semester) { (*this).semester = semester; }
//* new 
void Student::setSelectedCoursesList(std::vector<const Course*> newSelectedCoursesList) { (*this).selectedCourses = newSelectedCoursesList; }
void Student::setPassedCoursesList(std::vector<std::pair <Course*, float>> newPassedCoursesList) {
    for (int i = 0; i < newPassedCoursesList.size(); i++) {
        if ((newPassedCoursesList[i].second >= 5) && (newPassedCoursesList[i].second <= 10)) {
            (*this).passedCourses.push_back(newPassedCoursesList[i]);
        }
        else {
            std::cout << "wrong grade value" << std::endl;
        }
    }
} 

// Αλλες Μέθοδοι
void Student::incrementSemester () { ++(*this).semester; } //Προαύξηση του εξαμήνου
// Αυξηση εξαμήνου κατά `1`
void Student::semesterAddition (int number) { (*this).semester += number; }
// Μείωση εξαμήνου κατά `number`
void Student::semesterSubtraction (int number) { (*this).semester -= number; }

void Student::print (std::ostream &ostream) {
    ostream << "\nAM Φοιτητή >> " << (*this).AM 
    << "\nΌνοματεπώνημο Φοιτητή >> "
    << (*this).Name << "\nΕξάμηνο Φοίτησης >> "
    << (*this).semester << std::endl;
} 

//* new 
// Τοποθέτηση ενός νέου μαθήματος στην λίστα passedCourses με τον βαθμό του
void Student::addPassedCourse(Course& newCourse, float newGrade) {
    if (newGrade >= 5 && newGrade <= 10) {
    (*this).passedCourses.push_back(std::make_pair(&newCourse, newGrade));
    }
}

//* Υπερφόρτωση Τελεστών
// Δήλωση νέου μαθήματος στη selectedCourses
void Student::operator += (const Course* newCourse) { selectedCourses.push_back(newCourse); }

Student& Student::operator = (const Student &studentObject) {
    delete[] (*this).AM; 
    (*this).AM = new char[strlen(studentObject.AM) + 1]; 
    strcpy((*this).AM, studentObject.AM); 
    (*this).Name = studentObject.Name;    
    (*this).semester = studentObject.semester;
    (*this).selectedCourses = studentObject.selectedCourses;
    (*this).passedCourses = studentObject.passedCourses; 
    return *this;
}

bool Student::operator == (const Student& studentObject) const { return (*this).semester == studentObject.semester; }
bool Student::operator != (const Student& studentObject) const { return (*this).semester != studentObject.semester; }
bool Student::operator < (const Student& studentObject) const { return (*this).semester < studentObject.semester; }
bool Student::operator <= (const Student& studentObject) const { return (*this).semester <= studentObject.semester; }
bool Student::operator > (const Student& studentObject) const { return (*this).semester > studentObject.semester; }
bool Student::operator >=( const Student& studentObject) const { return (*this).semester >= studentObject.semester; }

