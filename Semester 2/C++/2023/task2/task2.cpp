#include <iostream>
#include <cstring>

class Student {

    private:
        char *AM;
        std::string Name;
        unsigned int semester;

    public:
        Student(); //Constructor κενού αντικειμένου
        Student(const char *AM, std::string Name);   // Constructor με προκαθορισμένη τιμή `1` για το πεδίο εξάμηνο
        Student(const char *AM, std::string Name, unsigned int semester); //Απλός Constructor
        Student(const Student  &Student_object); //Constructor αντιγραφής

        ~Student();

        const char *getAM();
        std::string getName();  //Getters
        unsigned int getSemester();

        void setAM(const char *AM);
        void setName(std::string Name);   //Setters
        void setSemester(unsigned int semester);

        void incrementSemester (); //Αυξηση εξαμήνου κατά `1`
        void semesterAddition(int number); //Αυξηση εξαμήνου κατά `number` 
        void semesterSubtraction(int number); //Μείωση εξαμήνου κατά `number`
        void print (std::ostream &ostream);  //Εκτύπωση αντικειμένου σε όλα τα κανάλια

        }; 

    Student::Student() {}

    Student::Student(const char *AM, std::string Name) {

        //Δυναμική δέσμευση για τον AM και αντιγραφή του με strcpy
        (*this).AM = new char(strlen (AM) + 1);             
        strcpy ((*this).AM, AM);
        (*this).Name = Name;
        (*this).semester = 1;   
    }

    Student::Student(const char *AM, std::string Name, unsigned int semester) {
        (*this).AM = new char(strlen (AM) + 1);
        strcpy ((*this).AM, AM);
        (*this).Name = Name;    
        (*this).semester = semester;
    }

    Student::Student(const Student &Student_object) {
        (*this).AM = Student_object.AM;
        (*this).Name = Student_object.Name;    
        (*this).semester = Student_object.semester;
    }

    Student::~Student() { 
    delete[] (*this).AM;     //Επειδή έχει κληθεί new κλήνεται το delete στον destructor
    }


    //Getters
        const char* Student::getAM() { return (*this).AM; }
        std::string Student::getName() { return (*this).Name; }
        unsigned int Student::getSemester() { return (*this).semester; }

    //Setters
    //Αφαίρεση του προηγούμενου pointer και προσθήκη νέου
    void Student::setAM(const char *AM) { 
        delete[] (*this).AM;    
        (*this).AM = new char(strlen(AM) + 1);
        strcpy ((*this).AM, AM);
    }

    void Student::setName(std::string Name) { (*this).Name = Name; } 
    void Student::setSemester(unsigned int semester) { (*this).semester = semester; }


    void Student::incrementSemester () {
        ++(*this).semester; //Προαύξηση του εξαμήνου
    }

    void Student::semesterAddition(int number) {
    (*this).semester += number;
}

    void Student::semesterSubtraction(int number) {
    (*this).semester -= number;
}

    void Student::print (std::ostream &ostream) {
        ostream << "AM Φοιτητή: " << (*this).AM << "\tΟνοματεπώνημο: " <<(*this).Name << "\tΕξάμηνο: " << (*this).semester << std::endl;
} 


int main (int argc, char **argv){

    // Κενό αντικείμενο χρησιμοποιώντας default constructor
    Student *defaultS = new Student ();

    // Απλό αντικείμενο με όλες τις τιμές
    Student *s1 = new Student ("19390104", "VasilhsKoumanis",6); 
    (*s1).print(std::cout); // method that shows the values of the object in whatever channel
    // setter example
    std::cout << "κλήση του setter:\n" << std::endl;
    (*s1).setAM("64646464");

    // Αντικείμενο με προκαθορισμένο εξάμηνο `1`.
    Student *s2 = new Student ("42012345", "GiwrgosChronopoulos");
    (*s2).print(std::cout);
    (*s2).incrementSemester(); 
    std::cout << "Η τιμή του 'εξαμήνου' για το αντικείμενο 's2' άλλαξε σε: " << (*s2).getSemester() << std::endl;

    //After using the setters the duplicate will take the new values. Υστερα από τη χρήση των setter 
    Student *duplicate1 = s1;   // Calls the copy constructor and makes a duplicare of s1 
    std::cout << "\nΔημιουργήθηκέ ένα αντίγραφο του s1 με τη νεα τιμή στο ΑΜ και +10 στο εξάμηνο:" <<std::endl;
    (*duplicate1).semesterAddition(10);
    (*duplicate1).print(std::cout);

    return 0;
}