#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "Course.h"
#include <cstring>
#include <vector>

class Student {

    private:
        char* AM;
        std::string Name;
        unsigned int Semester;
        std::vector <const Course*> SelectedCourses;
        std::vector <std::pair<Course*,float>> PassedCourses;

    public:
        Student();      
        // Απλός Constructor
        Student(const char* AM, std::string name, unsigned int semester);

        // Constructor με προκαθορισμένη τιμή `1` για το πεδίο εξάμηνο
        Student(const char* AM, std::string name);   

        Student(const Student  &studentObject);

        ~Student();

        //Getters
        const char* getAM() const ;
        std::string getName() const;  
        unsigned int getSemester() const;
        //*new
        std::vector <const Course*> getSelectedCoursesVector() const;
        std::vector <std::pair<Course*, float>> getPassedCoursesVector() const;
        float getCourseAverage() const;

        //Setters
        void setAM(const char* AM);
        void setName(std::string Name);   
        void setSemester(unsigned int semester);
        //*new
        void setSelectedCoursesVector(std::vector<const Course*> newSelectedCoursesVector);
        void setPassedCoursesVector(std::vector<std::pair <Course*, float>> newPassedCoursesVector);

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
        Student& operator = (const Student &studentObject);      // Παρόμοιο με τον Copy Constructor    
        // Συγκρίσεις εξαμήνων ανάμεσα σε αντικείμενα Student
        bool operator == (const Student& studentObject) const;
        bool operator != (const Student& studentObject) const;
        bool operator < (const Student& studentObject) const;
        bool operator <= (const Student& studentObject) const;
        bool operator > (const Student& studentObject) const;
        bool operator >= (const Student& studentObject) const;
        }; 

#endif