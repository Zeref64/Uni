#include <string>
#include <cstring>
/*In this .h FILE only declatarions are applied*/ 

class Student {

    private:
        char *AM;
        std::string Name;
        unsigned int semester;

    public:
        Student(); //default constructor
        Student(const char *AM, std::string Name);   // Constructor that defaults the semester value into '1'
        Student(const char *AM, std::string Name, unsigned int semester); //Constructor
        Student(const Student  &Student_object); //copy constructor

        ~Student();

        const char *getAM();
        std::string getName();  //Getters
        unsigned int getSemester();

        void setAM(const char *AM);
        void setName(std::string Name);   //Setters
        void setSemester(unsigned int semester);
        void incrementSemester ();
        void print (std::ostream &ostream); 

        }; 