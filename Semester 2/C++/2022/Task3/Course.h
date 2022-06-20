#include <string>
#include <cstring>
/*In this .h FILE only declatarions are applied*/ 

class Course {

    private:
        std::string courseCode; 
        std::string courseName;
        unsigned int courseSemester;

    public:
        Course();
        Course(std::string code, std::string name, unsigned int semester);
        Course(const Course &sourceObject);

        ~Course();

        std::string getCourseCode();
        std::string getCourseName();
        unsigned int getCourseSemester();

        void setCourseCode(std::string code);
        void setCourseName(std::string name);
        void setCourseSemester(unsigned int semester);

        void operator = (const Course &courseObject);

        void printCourse (std::ostream &ostream); 
};