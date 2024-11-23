#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdlib>

class Student
{
private:
    int id;
    char *name;
    int semester;
    bool active;

public:
    Student(int, const char *, int, bool);
    ~Student();
    bool isActive() const;
    int getID() const;
    const char *getName() const;
};
Student::Student(int _id, const char *_name, int _semester, bool _active)
    : id(_id), semester(_semester), active(_active)
{
    unsigned int l = strlen(_name) + 1;
    name = new char[l];
    strcpy(name, _name);
    name[l] = '\0';
}

Student::~Student() {}
bool Student::isActive() const { return active; }
int Student::getID() const { return id; }
const char *Student::getName() const { return name; }


std::vector<Student> fetchStudents(const char *filename) {
    std::vector<Student> students;
    std::string line;
    std::ifstream ifile(filename);
    if (ifile.is_open())
    {
        while (std::getline(ifile, line))
        {
            std::istringstream iss(line + "\n");
            std::string fields[4];
            std::getline(iss, fields[0], ',');
            std::getline(iss, fields[1], ',');
            std::getline(iss, fields[2], ',');
            std::getline(iss, fields[3]);
            int id = atoi(fields[0].c_str());
            unsigned int s = fields[1].size() + 1;
            char *name = new char[s];
            strcpy(name, fields[1].c_str());
            name[s] = '\0';
            int semester = atoi(fields[2].c_str());
            bool active = (bool)atoi(fields[3].c_str());
            students.push_back(Student(id, name, semester, active));
        }
        ifile.close();
    }
    return students;
}
void printActive(const std::vector<Student> &students)
{
    std::vector<Student>::const_iterator citr =
        students.begin();
    for (citr; citr != students.end(); citr++)
    {
        if ((*citr).isActive())
        {
            std::cout << "ID: " << (*citr).getID() << ",Name : " << (*citr).getName() << std::endl;
        }
    }
}

int main()
{
    std::vector<Student> students =
    fetchStudents("students.csv");
    printActive(students);
    return 0;
}