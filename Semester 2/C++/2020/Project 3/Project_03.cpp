#include <iostream>					
#include <string.h>					// Fullname: Koumanis Vasileios
#include <string>					// AM: 	19390104
#include <cstdlib>					// Class: 11
#include <ctime>
using namespace std;

class Course 
{
	private:
		string cou_code;
		string course;
		unsigned int csemester;
	public:
		Course() {};
		Course(string cou_code1, string course1 ,unsigned int semester1);
		
		string getCou_code()const;
		string getCourse()const;
		unsigned int getCsemester()const;
		
		void setCou_code(string newCode);
		void setCourse(string newCourse);
		void setCsemester(unsigned int newCsemester);
		
		
};

class Student
{
	private:
		string AM;
		string name;
		unsigned int semester;
		unsigned int declared_courses;
		Course **course_array;
	public:	
		Student(string AM1, string Name1, unsigned int Semester1, unsigned int declared_courses1, Course *Array);
		
		string getAM()const;
		string getName()const;
		unsigned int getSemster()const;
		unsigned int getDeclared_Courses()const;
		Course **getCourse_array()const;
		
		void setAM(string newAM);
		void setName(string newName);
		void setSemester(unsigned int newSemester);
		void setDeclared_Courses(unsigned int newDeclared_Courses);
		void setCourse_Array(Course* newCourse_Array);
		
		Student operator += (Course *Array);
		int operator == (const Student &std);
		int operator != (const Student &std);
		int operator < (const Student &std);
		int operator <= (const Student &std);
		int operator > (const Student &std);
		int operator >= (const Student &std);
};
		
Course :: Course(string cou_code1, string course1 ,unsigned int semester1)			// Course Constructor
{
	cou_code=cou_code1;
	course=course1;
	csemester=semester1;
}

string Course :: getCou_code()const { return cou_code; }
string Course :: getCourse()const { return course; }						// Class "Course" Getters. 
unsigned int Course :: getCsemester ()const { return csemester; }

void Course :: setCou_code(string newCode) { cou_code = newCode; }
void Course :: setCourse(string newCourse) { course = newCourse; }
void Course :: setCsemester(unsigned int newCsemester) { csemester = newCsemester; }			// Class "Course" Setters.

Student :: Student(string AM1, string Name1, unsigned int Semester1, unsigned int declared_courses1, Course *Array)
{
	AM=AM1;
	name= Name1;
	semester=Semester1;
	declared_courses=declared_courses1;
	if (declared_courses)
	{
		course_array = (Course **) new Course [declared_courses];				// Student Constructor
		for (int i = 0; i < declared_courses; i++)
		{
			course_array[i] = new Course;
		 	course_array[i] = &Array[i];
		}
	}
}

string Student :: getAM()const { return AM; }
string Student :: getName()const { return name; }
unsigned int Student :: getSemster()const { return semester; }
unsigned int Student :: getDeclared_Courses()const { return declared_courses; }			// Class "Student" Getters
Course** Student :: getCourse_array ()const { return course_array; }

void Student :: setAM(string newAM) { AM = newAM; }
void Student :: setName (string newName) { name = newName; }
void Student :: setSemester(unsigned int newSemester) { semester = newSemester;}
void Student :: setDeclared_Courses(unsigned int newDeclared_Courses) { declared_courses = newDeclared_Courses; }
void Student :: setCourse_Array(Course* newCourse_Array)
{
	if (declared_courses)
	{
		course_array = (Course **) new Course [declared_courses];				
		for (int i = 0; i < declared_courses; i++)
			{
				course_array[i] = new Course;
		 		course_array[i] = &newCourse_Array[i];
			}
	}
}

Student Student :: operator += (Course *Array)			//{ Operator overloads   ==, !=, <, <=, >, >=, << (Both objects)
{
 		unsigned int len=(*this).declared_courses;
        Course **tmp1;
        for(int i = 0 ; i < len; i++)
        	tmp1[i]=&Array[i];
        this->course_array=new Course*[len+1];				// Problem
        for(int j=0; j < len; j++)
        	course_array[j]=tmp1[j];
        for(int k = 0; k < len ; k++)
            course_array[len+k]=&Array[k];
        this->declared_courses=len+1;
		return *this;
}

int Student :: operator == (const Student &std)
{
	if ((*this).getSemster() == std.getSemster())
        return 1;
    return 0;
}
int Student :: operator != (const Student &std)
{
	if ((*this).getSemster() != std.getSemster())
        return 1;
    return 0;
}
int Student :: operator < (const Student &std)
{
	if ((*this).getSemster() < std.getSemster())
        return 1;
    return 0;
}
int Student :: operator <= (const Student &std)
{
	if ((*this).getSemster() <= std.getSemster())
        return 1;
    return 0;	
}
int Student :: operator > (const Student &std)
{
	if ((*this).getSemster() > std.getSemster())
        return 1;
    return 0;
}
int Student :: operator >= (const Student &std)
{
	if ((*this).getSemster() >= std.getSemster())
        return 1;
    return 0;								
}																							
	
ostream& operator << (ostream& channel, const Course &c);
ostream& operator << (ostream& channel, const Student &std);

int main ()
{
	Course c1("64", "C++", 2);
	Course c2("7", "Java", 3);
	Course c3("19", "Networking", 5);
	Course c4("34", "Robotics", 7);	
	Course ArrayS1 [2];
	ArrayS1[0]= c1;
	ArrayS1[1]= c3;
	Student s1("19390104","Bill",3,2,ArrayS1);							//Main 2 Course obejcts, 1 Student obj
	Course ArrayS2 [3];
	ArrayS2[0]= c1;
	ArrayS2[1]= c3;
	ArrayS2[2]= c2;
	Student s2("641996","Mario",5,3,ArrayS2);								
	cout << s1 << endl;
	Course Array_NewS1[1];
	Array_NewS1[0]=c4;
	//s1 += (Array_NewS1);		Problem with operator += .
	cout << s2 << endl;
	Student s3 ("592020","Link",3,2,ArrayS1);
	if ( (s1==s2) == 1 )
		cout << "Both students are on the same semester" << endl;
	else
		cout << "These students are on a different semester" << endl;
		
	if ( (s1>s2) == 1 )
		cout << "The first student is on a higher semester" << endl;
	else
		cout << "The second student is on a higher semester" << endl;
		
	if ( (s1>=s3)== 1 )
		cout << "True" << endl;
	else
		cout << "False" << endl;
		
	if ( (s2<=s1)== 1 )
		cout << "True" << endl;
	else
		cout << "False" << endl;
		
	return 0;
	}

ostream& operator << (ostream& channel, const Course &c)
{
	channel << "Course Name >>> " << c.getCourse() << endl;
	channel << "Course Code >>> " << c.getCou_code() << endl;					// operator " << " overload for Course object.
	channel << "Course Semester >>> " << c.getCsemester() << endl;
	return channel;
}

ostream& operator << (ostream& channel, const Student &std) 
{
	channel << "AM >>> " << std.getAM() << endl;
	channel << "Name >>> " << std.getName() << endl;					// operator " << " overload for Subject object.
	channel << "Semester >>> " << std.getSemster() << endl;
	channel << "This student has declared " << std.getDeclared_Courses() << " Courses" << endl;
	for (int i = 0; i < std.getDeclared_Courses(); i++)
	{	
		if (std.getDeclared_Courses() != 0)
			channel << "Course " << i+1 << " = " << *std.getCourse_array()[i] << endl;
		else
			channel << "This student has not declared any Courses yet." << endl;		
	}
	return channel;
}																							//End of operator Overloads}
