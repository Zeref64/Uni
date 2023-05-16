#include <string>
#include <cstring>
/*In this .h FILE only declatarions are applied*/ 

class Course {

    private:
        std::string courseCode; 
        std::string courseName;
        unsigned int courseHours;
        std::string courseSemester;

    public:
        Course();
        Course(std::string code, std::string name, unsigned int hours ,std::string semester);
        Course(const Course &sourceObject);

        ~Course();

        std::string getCourseCode();
        std::string getCourseName();
        unsigned int getCourseHours();
        std::string getCourseSemester();

        void setCourseCode(std::string code);
        void setCourseName(std::string name);
        void setCourseHours(unsigned int hours);
        void setCourseSemester(std::string semester);

        void operator = (const Course &courseObject);

        void printCourse (std::ostream &ostream); 
};