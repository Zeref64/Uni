#include <iostream>
#include "Course.h"

        Course::Course() {
            std::cout << "Κλήθηκε ο αρχικός κατασκευαστής για το αντικειμένο course" << std::endl;
        }
        Course::Course(std::string code, std::string name, unsigned int semester) : courseCode(code), courseName(name), courseSemester(semester) {
            std::cout << "Κλήθηκε κατασκευαστής για το αντικειμένο course" << std::endl;
        }
        Course::Course(const Course &sourceObject) : courseCode(sourceObject.courseCode), courseName(sourceObject.courseName), courseSemester(courseSemester) {
            std::cout << "Κλήθηκε ο Κατασκευαστής αντιγράφου για το αντικειμένο course" << std::endl;
        }

        Course::~Course() {
            std::cout << "Κλήθηκε ο Καταστροφέας του αντικειμένου course " << std::endl;
            }
        std::string Course::getCourseCode() { return (*this).courseCode; }
        std::string Course::getCourseName() { return (*this).courseName; }
        unsigned int Course::getCourseSemester() { return (*this).courseSemester; }

        void Course::setCourseCode(std::string code) { (*this).courseCode = code;}
        void Course::setCourseName(std::string name) { (*this).courseName = name; }
        void Course::setCourseSemester(unsigned int semester) { (*this).courseSemester = semester; }

        void Course::operator = (const Course &courseObject) {
            (*this).courseCode = courseObject.courseCode;
            (*this).courseName = courseObject.courseName;
            (*this).courseSemester = courseObject.courseSemester;
        }

        void Course::printCourse (std::ostream &ostream) {
    ostream << "Κωδικός μαθήματος: " << (*this).courseCode << "\tΌνομα μαθήματος: " << (*this).courseName << "\tΕξάμηνο μαθήματος: " << (*this).courseSemester << std::endl; }
