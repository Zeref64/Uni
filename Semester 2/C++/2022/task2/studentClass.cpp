#include <iostream>
#include <ostream>
#include "studentClass.h"

/*This is the class file which is used to implement functionality on the previously declared methods.
It includes: Overloaded Constructor, Destructor, Getters/Setters and two methods, one for printing through any stream
and second for incrementing the value of method 'semester' by 1.*/

//default constructor 
Student::Student() {}

// Constructor that defaultus the value of semester to 1
Student::Student(const char *AM, std::string Name) {

    /*Dynamic allocation for the char* attribute then copying using strcpy */
    (*this).AM = new char(strlen (AM) + 1);             
    strcpy ((*this).AM, AM);
    (*this).Name = Name;
    (*this).semester = 1;   
}

// Constructor that takes all the values
Student::Student(const char *AM, std::string Name, unsigned int semester) {
    (*this).AM = new char(strlen (AM) + 1);
    strcpy ((*this).AM, AM);
    (*this).Name = Name;    
    (*this).semester = semester;
}

/* Constructor that gets the values from another object
    Copy Constructor*/
Student::Student(const Student &Student_object) {
    (*this).AM = Student_object.AM;
    (*this).Name = Student_object.Name;    
    (*this).semester = Student_object.semester;

}

Student::~Student() { 
    delete[] (*this).AM;     //deallocating the memory
    std::cout<< "Destructor is called, deallocating memory." <<std::endl;
    }  

    /*I do not have to manually delete the string attribute because it's destructor is called automatically
    Same goes for the unsingned integer*/


//Getters
const char* Student::getAM() { return (*this).AM; }
std::string Student::getName() { return (*this).Name; }
unsigned int Student::getSemester() { return (*this).semester; }

//Setters
/*deleting the previous pointer and allocating a new one*/
void Student::setAM(const char *AM) { 
    delete[] (*this).AM;    
    (*this).AM = new char(strlen(AM) + 1);
    strcpy ((*this).AM, AM);
}
void Student::setName(std::string Name) { (*this).Name = Name; } 
void Student::setSemester(unsigned int semester) { (*this).semester = semester; }


void Student::incrementSemester () {
    (*this).semester ++;
}

// method that prints an object into the ostream
void Student::print (std::ostream &ostream) {
    ostream << "Student AM: " << (*this).AM << "\tName: " <<(*this).Name << "\tSemester: " << (*this).semester << std::endl;

} 

