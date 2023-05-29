#include <iostream>
#include "Student.h"
#include <fstream>
#include <stdexcept>

//using namespace std;

//* new
// Υπερφόρτωση του τελεστή << για να τυπώνει το αντικείμενο σε οποιοδήποτε κανάλι
std::ostream& operator << (std::ostream& ostream, const Student& studentObject);
// Αποθήκευση σε αρχείο μέσω της υπερφόρτωσης του τελεστή <<
void saveAsFile(const Student& studentObject, const std::string& fileName);

int main (int argc, char **argv){

    //* new
    Course firstCourse ("ΛΣ1", "Λειτουργικά Συστήματα Ι", 4, Semester::Χειμερινό);
    Course secondCourse ("ΔΥ1", "Δίκτυα Υπολογιστών Ι", 5, Semester::Χειμερινό);
    Course thirdCourse ("ΥΝ", "Υπολογιστική Νέφους", 4, Semester::Εαρινό);
    Course fourthCourse ("ΤΛ", "Τεχνολογία Λογισμικού", 4, Semester::Εαρινό);

    Student student1 ("19390104", "Κούμανης Βασίλειος", 8);
    Student student2 ("25872587", "Βασιλακάκος Χρήστος ", 10);
    Student student3 ("12356789", "Βέργος Αθανάσιος");
    Student copyStudent1 ("777777", "CopyCat", 0);
    Student copyStudent2 (student2);


    student1.addPassedCourse(secondCourse, 8.0);
    student1.addPassedCourse(fourthCourse, 7.0);
    student1 += &firstCourse;

    student2.addPassedCourse(thirdCourse, 5.0);
    student2.addPassedCourse(secondCourse, 9.0);

    student3.addPassedCourse(firstCourse, 10.0);
    student3 += &fourthCourse;
    

    std::cout << "Εκτύπωση ενός φοιτητή στο κανάλι cout" << std::endl;
    std::cout << student1 << std::endl;

    if (student1 < student2) {
        std::cout << "O φοιτητής: " << student1.getName() << "\nβρίσκεται σε μικρότερο εξάμηνο φοίτησης από τον φοιτητή: " << student2.getName() << std::endl;
    }

    std::cout << copyStudent1 << std::endl;
    copyStudent1 = student1;
    std::cout << "Το αντικείμενο Student copyStudent1 πήρε τις τιμές του student1" << std::endl;
    std::cout << copyStudent1 << std::endl;

    std::cout << "Το αντικείμενο Student copyStudent2 αρχικοποιήθηκε μέσω του Copy Constructor\nμε τις τιμές του αντικειμένου student2" << std::endl;
    std::cout << copyStudent2 << std::endl;

    saveAsFile (student3, "student3_Data");

    return 0;
}     

//* new
std::ostream& operator << (std::ostream& ostream, const Student& studentObject) {
    ostream << "\nΌνοματεπώνημο Φοιτητή >> " << studentObject.getName() 
    << "\nAM Φοιτητή >> " << studentObject.getAM() 
    << "\nΕξάμηνο Φοίτησης >> " << studentObject.getSemester()
    << "\nΔηλωμένα μαθήματα >>" << std::endl;
    for (int i = 0; i < studentObject.getSelectedCoursesList().size(); i++) {
        ostream << "Δηλωμένο Μάθημα " << i+1 << " " << studentObject.getSelectedCoursesList()[i]->getCourseCode() << std::endl; 

        //TODO Average !!!!
    }

    ostream << "\n\nΠερασμένα μαθήματα & βαθμολογίες >>" << std::endl;
    for (int j = 0; j < studentObject.getPassedCoursesList().size(); j++) {
        ostream << "Μάθημα: " << " " << studentObject.getPassedCoursesList()[j].first->getCourseName() << "\tΒαθμός Μαθήματος: " << studentObject.getPassedCoursesList()[j].second << std::endl;
    }
    return ostream;
}

void saveAsFile(const Student& studentObject, const std::string& fileName) {
    try {
        std::ofstream outputFile(fileName); 

        if (outputFile.is_open()) { 
            outputFile << studentObject; // Χρήση της υπερφόρτωσης 
            outputFile.close(); 
            std::cout << "Η διαδικασία αποθήκευσης ολοκληρώθηκε με επιτυχία στο αρχείο: " << fileName << std::endl;
        } else {
            throw std::runtime_error("Αναποτελεσματική απόπειρα ανοίγματος του αρχείου εξόδου: " + fileName); // Δημιουργεί αντικείμενο exception με το μήνυμα σφάλματος 
        }
    } catch (const std::exception& ex) { // Εαν και εφόσον υπάρξει exception τότε εμφανίζει στο κανάλι cerr το μήνυμα καθώς και κάποιες πληροφορίες.
        std::cerr << ex.what() << std::endl;
    }
}