#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <cstring>

enum Semester {
    Χειμερινό,
    Εαρινό
};

class Course {

    private:
        std::string courseCode; 
        std::string courseName;
        unsigned int courseHours;
        Semester courseSemester;

    public:
        Course();
        Course(std::string code, std::string name, unsigned int courseHours, Semester semester);
        Course(const Course &sourceObject);

        ~Course();

        std::string getCourseCode() const;
        std::string getCourseName() const;
        unsigned int getCourseHours() const;
        Semester getCourseSemester() const;

        void setCourseCode(std::string code);
        void setCourseName(std::string name);
        void setCourseHours(unsigned int hours);
        void setCourseSemester(Semester semester);

        void printCourse (std::ostream &ostream); 
};

#endif