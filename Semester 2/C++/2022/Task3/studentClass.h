#include <string>
#include <cstring>
#include <vector>
#include "Course.h"
/*In this .h FILE only declatarions are applied*/ 

class Student {

    private:
        char *AM;
        std::string Name;
        unsigned int semester;
        std::vector <const Course*> declaredCourses;
        std::vector <std::pair<Course*,float>> completedPastCourses;

    public:
        Student(); //default constructor
        Student(const char *AM, std::string Name);   // Constructor that defaults the semester value into '1'
        Student(const char *AM, std::string Name, unsigned int semester); //Constructor
        Student(const Student  &Student_object); //copy constructor

        ~Student();

        const char *getAM();
        std::string getName();  //Getters
        unsigned int getSemester();
        std::vector <const Course*> getDeclaredCoursesVector();
        std::vector <std::pair<Course*,float>> getCompletedPastCourses();

        void setAM(const char *AM);
        void setName(std::string Name);   //Setters
        void setSemester(unsigned int semester);
        void incrementSemester ();
        void operator += (const Course* course);

        void operator = (const Student &Student_object);

        /*void Student::operator == ()
        void Student::operator != ()
        void Student::operator < ()
        void Student::operator <= ()
        void Student::operator > ()
        void Student::operator >= ()
        */
    
        void print (std::ostream &ostream); 

        }; 