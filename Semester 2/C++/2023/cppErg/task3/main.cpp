#include <iostream>
#include "Student.h"
#include <fstream>
#include <stdexcept>

//* new
// Υπερφόρτωση του τελεστή << για να τυπώνει το αντικείμενο σε οποιοδήποτε κανάλι
std::ostream& operator << (std::ostream& ostream, const Student& studentObject);

// Αποθήκευση σε αρχείο μέσω της υπερφόρτωσης του τελεστή <<
void saveAsFile(const Student& studentObject, const std::string& fileName);

int main (int argc, char **argv){
//! Το πρόγραμμα θα τερματήσει λόγω του Exception όπου υπαρχει '//!' πρόκειται για exception 
    //* new
    Course firstCourse ("ΛΣ1", "Λειτουργικά Συστήματα Ι", 4, Semester::Χειμερινό);
    Course secondCourse ("ΔΥ1", "Δίκτυα Υπολογιστών Ι", 5, Semester::Χειμερινό);
    Course thirdCourse ("ΥΝ", "Υπολογιστική Νέφους", 4, Semester::Εαρινό);
    Course fourthCourse ("ΤΛ", "Τεχνολογία Λογισμικού", 4, Semester::Εαρινό);

    Student student1 ("19390104", "Κούμανης Βασίλειος", 8);
    Student student2 ("25872587", "Βασιλακάκος Χρήστος ", 10);
    Student student3 ("12356789", "Βέργος Αθανάσιος");
    Student student4 ("21496877", "Χανδρινός Ανδρέας", 15);
    
    Student copyStudent1 ("777777", "CopyCat", 0);

    //? Παραδείγματα για να τεσταριστεί η λειτουργία των setter
    std::vector <const Course*> selectedCourseVectorExample;
    selectedCourseVectorExample.push_back(&fourthCourse);

    std::vector<std::pair<Course*, float>> passedCourseVectorExample;
    passedCourseVectorExample.push_back(std::make_pair(&firstCourse, 8.0));
    passedCourseVectorExample.push_back(std::make_pair(&secondCourse, 6.0));
    //! passedCourseVectorExample.push_back(std::make_pair(&thirdCourse, 4.0));

    
    try { 
        student1.addPassedCourse(secondCourse, 8.0);
        student1.addPassedCourse(fourthCourse, 7.0);
        student1 += &firstCourse;
        std::cout << "[Σημείωση] Εκτύπωση ενός φοιτητή στο κανάλι cout" << std::endl;
        std::cout << student1 << std::endl;

        student2.addPassedCourse(thirdCourse, 5.0);
        student2.addPassedCourse(secondCourse, 9.0);
        student2 += &fourthCourse;
        //! student2 += &fourthCourse;

        student3.addPassedCourse(firstCourse, 10.0);
        student3 += &thirdCourse;
        //! student3.semesterSubtraction(10); 
        std::cout << student3 << std::endl;

        student4.setSelectedCoursesVector(selectedCourseVectorExample);
        student4.setPassedCoursesVector(passedCourseVectorExample); 
        std::cout << student4 << std::endl;

        std::cout << "\n[Σημέιωση] Το αντικείμενο Student copyStudent1 'CopyCat' τώρα περιέχει τις τιμές του student1 'Κούμανης Βασίλειος' \n μέσω της υπερφότρωσης του τελεστή '='. " << std::endl;
        copyStudent1 = student1;
        std::cout << copyStudent1 << std::endl;

        Student copyStudent2 (student2);
        std::cout << "[Σημέιωση] Το αντικείμενο Student copyStudent2 αρχικοποιήθηκε μέσω του Copy Constructor\nμε τις τιμές του αντικειμένου student2 'Βασιλακάκος Χρήστος'." << std::endl;
        std::cout << copyStudent2 << std::endl;

        if (student1 < student2) {
            std::cout << "\nO φοιτητής: " << student1.getName() << "\nβρίσκεται σε μικρότερο εξάμηνο φοίτησης από τον φοιτητή: " << student2.getName() << std::endl;
        }
        saveAsFile (student3, "student3_Data"); 

            //* new
    } catch (int errorCode) { 

        switch (errorCode) {

        // Εαν και εφόσον υπάρξει exception, τότε εμφανίζει στο κανάλι cout το μήνυμα καθώς και κάποιες πληροφορίες.
        case -1:
            std::cout << "\n[Error] -1 Αναποτελεσματική απόπειρα ανοίγματος του αρχείου εξόδου: " << std::endl;
            break;

        case -2:
            std::cout << "\n[Error] -2 Δεν ήταν δυνατή η αφαίρεση εξαμήνου: Έχει ήδη τη μικρότερη τιμή. " << std::endl;
            break;
        
        case -3:
            std::cout << "\n[Error] -3 Δεν γίνεται να υπολογιστεί ο Μ.Ο. : Δεν υπάρχουν μαθήματα." << std::endl;
            break;   
        
        case -4:
            std::cout << "\n[Error] -4 Ένας βαθμός του νέου vector είναι < 5 το : Το μάθημα δεν θεωρείτε ολοκληρωμένο." << std::endl;
            break;

        case -5:
            std::cout << "\n[Error] -5 Δεν γίνεται να δηλωθεί μάθημα πάνω από μία φορά." << std::endl;
            break;
        }
    }
    return 0;
}     

//* new
std::ostream& operator << (std::ostream& ostream, const Student& studentObject) {
    ostream << "\nΌνοματεπώνημο Φοιτητή >> " << studentObject.getName() 
    << "\nAM Φοιτητή >> " << studentObject.getAM() 
    << "\nΕξάμηνο Φοίτησης >> " << studentObject.getSemester()
    << "\n---Δηλωμένα μαθήματα--- >>" << std::endl;
    for (int i = 0; i < studentObject.getSelectedCoursesVector().size(); i++) {
        ostream << "\tΔηλωμένο Μάθημα [" << i+1 << "]: " << studentObject.getSelectedCoursesVector()[i]->getCourseCode() <<"\t"<< studentObject.getSelectedCoursesVector()[i]->getCourseName() <<  std::endl; 
    }

    ostream << "\n---Περασμένα μαθήματα και αναλυτική βαθμολογία--- >>" << std::endl;
    for (int j = 0; j < studentObject.getPassedCoursesVector().size(); j++) {
        ostream << "\tΠερασμένο Μάθημα [" << j+1 << "]: " << studentObject.getPassedCoursesVector()[j].first->getCourseCode() <<"\t"<< studentObject.getPassedCoursesVector()[j].first->getCourseName() << "\tΒαθμός Μαθήματος: " << studentObject.getPassedCoursesVector()[j].second << std::endl;
    }

    ostream << "\tΜέσος Όρος περασμένων μαθημάτων του φοιτητή >> " << studentObject.getCourseAverage() << std::endl;
    return ostream;
}

void saveAsFile(const Student& studentObject, const std::string& fileName) {

        std::ofstream outputFile(fileName);  //* [Σημείωση] το αρχείο ανοίγει με write by-default και όχι με append, δεν το άλλαξα διότι θεώρησα πως είναι σωστή αυτή η λειτουργικότητα (το να κάνει write έναντι του append.)
        if (outputFile.is_open()) { 
           outputFile << studentObject << std::endl; // Χρήση της υπερφόρτωσης '<<'
            outputFile.close(); 
            std::cout << "\nΗ διαδικασία αποθήκευσης ολοκληρώθηκε με επιτυχία στο αρχείο: " << fileName << std::endl;
        } else {
            throw -1; //exception για το αρχείο
        }
}