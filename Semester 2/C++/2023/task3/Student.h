#include <iostream>
#include <string>
#include "Course.h"
#include <cstring>
#include <vector>

class Student {

    private:
        char *AM;
        std::string Name;
        unsigned int semester;
        std::vector <const Course*> selectedCourses;
        std::vector <std::pair<Course*,float>> passedCourses;

    public:
        // Constructor κενού αντικειμένου
        Student();      
        // Απλός Constructor
        Student(const char *AM, std::string Name, unsigned int semester);

        // Constructor με προκαθορισμένη τιμή `1` για το πεδίο εξάμηνο
        Student(const char *AM, std::string Name);   

        // Copy Constructor 
        Student(const Student  &studentObject);

        // Destructor
        ~Student();

        //Getters
        const char *getAM() const ;
        std::string getName() const;  
        unsigned int getSemester() const;
        //*new
        std::vector <const Course*> getSelectedCoursesList() const;
        std::vector <std::pair<Course*, float>> getPassedCoursesList() const;
        float getCourseAverage() const;

        //Setters
        void setAM(const char *AM);
        void setName(std::string Name);   
        void setSemester(unsigned int semester);
        //*new
        void setSelectedCoursesList(std::vector<const Course*> newSelectedCoursesList);
        void setPassedCoursesList(std::vector<std::pair <Course*, float>> newPassedCoursesList);

        //* Αλλες Μέθοδοι
        // Αυξηση εξαμήνου κατά `1`
        void incrementSemester (); 
        // Αυξηση εξαμήνου κατά `number` 
        void semesterAddition(int number);
        // Μείωση εξαμήνου κατά `number` 
        void semesterSubtraction(int number); 
        // Εμφάνιση του αντικειμένου σε οποιοδήποτε κανάλι
        void print (std::ostream &ostream); 
        // Τοποθέτηση ενός νέου μαθήματος στην λίστα passedCourses με τον βαθμό του
        void addPassedCourse(Course& newCourse, float newGrade);

        //* Υπερφόρτωση Τελεστών
        // Δήλωση νέου μαθήματος στη selectedCourses
        void operator += (const Course* newCourse);
        //Παρόμοιο με τον Copy Constructor
        Student& operator = (const Student &studentObject);
        // Συγκρίσεις εξαμήνων ανάμεσα σε αντικείμενα Student
        bool operator == (const Student& studentObject) const;
        bool operator != (const Student& studentObject) const;
        bool operator < (const Student& studentObject) const;
        bool operator <= (const Student& studentObject) const;
        bool operator > (const Student& studentObject) const;
        bool operator >= (const Student& studentObject) const;
        }; 
