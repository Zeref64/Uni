#include <iostream>
#include "studentClass.h"

/*The main function uses the class file in order to create three objects and one duplicate and show the functionality.
'defaultS' is an empty object, s1 has all the values, s2 has by default the vaule of semester to 1
and lastly the duplicate1 is a duplicate of the object s1.*/

int main (int argc, char **argv){

    // Empty Student object creation using default constructor
    Student *defaultS = new Student ();

    // Student object that parses every value
    Student *s1 = new Student ("19390104", "VasilhsKoumanhs",6); 
    (*s1).print(std::cout); // method that shows the values of the object in whatever channel
    // setter example
    std::cout << "setter:" << std::endl;
    (*s1).setAM("64646464");

    // Student object that defaults the semester value.
    Student *s2 = new Student ("42012345", "GiwrgosChronopoulos");
    (*s2).print(std::cout);
    (*s2).incrementSemester();  // Method that incements the 'semester' attribute.
    std::cout << "The value of the 'semester' attribute\nof the s2 object the has changed into: " << (*s2).getSemester() << std::endl;

    //After using the setters the duplicate will take the new values.
    Student *duplicate1 = s1;   // Calls the copy constructor and makes a duplicare of s1 
    std::cout << "This is a duplicate of the object s1:" <<std::endl;
    (*duplicate1).print(std::cout);

    return 0;
}