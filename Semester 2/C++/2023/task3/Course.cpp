#include <iostream>
#include "Course.h"

        Course::Course() {}
        Course::Course(std::string code, std::string name,unsigned int hours, Semester semester) : courseCode(code), courseName(name),courseHours(hours), courseSemester(semester) {}
        Course::Course(const Course &sourceObject) : courseCode(sourceObject.courseCode), courseName(sourceObject.courseName),courseHours(sourceObject.courseHours), courseSemester(sourceObject.courseSemester) {}

        Course::~Course() {}

        std::string Course::getCourseCode() const{ return (*this).courseCode; }
        std::string Course::getCourseName() const{ return (*this).courseName; }
        unsigned int Course::getCourseHours() const{return (*this).courseHours;}
        Semester Course::getCourseSemester() const{ return (*this).courseSemester; }

        void Course::setCourseCode(std::string code) { (*this).courseCode = code; }
        void Course::setCourseName(std::string name) { (*this).courseName = name; }
        void Course::setCourseHours(unsigned int hours) { (*this).courseHours = hours; }
        void Course::setCourseSemester(Semester semester) { (*this).courseSemester = semester; }

        void Course::printCourse (std::ostream &ostream) {
            ostream << "Κωδικός μαθήματος: " << (*this).courseCode << "\tΌνομα μαθήματος: " << (*this).courseName << "/tΩρες μαθήματος:" << (*this).courseHours  << "\tΕξάμηνο μαθήματος: "<< (*this).courseSemester << std::endl; }