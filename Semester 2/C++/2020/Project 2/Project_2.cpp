#include <iostream>					
#include <string.h>					// Fullname: Koumanis Vasileios
#include <string>					// AM: 	19390104
#include <cstdlib>					// Class: 11
#include <ctime>
using namespace std;
class Student
{
	private:
		char *AM;
		string name;
		unsigned int semester;
		unsigned int passed_courses;
		float *grades_array; 
	public:
		Student(const char *AMx ,string namex);
		Student(const char *AMx, string namex, unsigned int semesterx);
		Student(const char *AMx, string namex, unsigned int semesterx, unsigned int lessons);
		Student(const Student &v);
		~Student ();
		
		char* getAM () const;
		string getName () const;
		unsigned int getSemester () const;
		unsigned int getPassed_courses () const;
		float* getGradesArray () const;
		
		void setAM (char *a);
		void setName (string b);    							
		void setSemester (unsigned int c);
		void setPassed_courses (unsigned int x);
		void setGradesArray (float *g);
		
		void AddGrade (float f);
};

Student :: Student(const char *AMx, string namex)
{
	int i,len;
	len = strlen(AMx);
	AM = new char [len+1];
	for (i=0; i<len+1; i++)					// Constructor that sets default vaulues for Semester to "1" and Passed courses to "0".
		AM[i] = AMx[i];		
	semester = 1;						
	name = namex;
	passed_courses = 0;
	grades_array = NULL;
};
	
Student :: Student(const char *AMx, string namex, unsigned int semesterx)
{
	int i,len;
	len = strlen(AMx);
	AM = new char [len+1];
	for (i=0; i<len+1; i++)
		AM[i] = AMx[i];						// Constructor that sets default vaulues for Passed courses to "0".
	semester = semesterx;
	name = namex;
	passed_courses = 0;
	grades_array = NULL;	
};

Student :: Student(const char *AMx, string namex, unsigned int semesterx, unsigned int lessons)
{
	srand(time(NULL));
	int i,len;
	len = strlen(AMx);
	AM = new char [len+1];
	for (i=0; i<len+1; i++)
		AM[i] = AMx[i];
	name = namex;							// Constructor without any default values.
	semester = semesterx;
	passed_courses = lessons;
	grades_array= new float [passed_courses];
	for (i=0; i< passed_courses; i++)
		grades_array[i]=rand() %5 + 6;
};

Student :: Student (const Student &v)
{
	int l,len;
	char *ch_ptr;
	float *fl_ptr;
	delete  AM;
	delete [] grades_array;
	len = strlen(v.AM);
	ch_ptr = new char [len+1];
	for (l=0; l<len; l++)
		ch_ptr[l] = v.AM[l]; 
	AM=ch_ptr;								// Constructor that mirrors an object's data to another object.
	delete [] ch_ptr;
	name = v.name; 
	semester = v.semester;
	passed_courses = v.passed_courses;
	len = v.passed_courses;
	fl_ptr = new float [len];
	memcpy(fl_ptr,v.grades_array,len);
	grades_array = fl_ptr;
	delete [] fl_ptr;
}

Student :: ~Student()
{
	delete [] AM;		
	if (passed_courses != 0)					// Destructor.
		delete [] grades_array;
}

char* Student :: getAM () const { return AM; }

string Student :: getName () const { return name; }

unsigned int Student :: getSemester () const { return semester; }							// Getters

unsigned int Student :: getPassed_courses () const { return passed_courses; }

float* Student :: getGradesArray () const { return grades_array; }		


void Student :: setAM (char *a) 
{
	delete [] AM;
	int i,len;
	len= strlen(a);
	AM=new char [len+1];				// <-- AM setter.
	for (i=0; i<len+1; i++)
		AM[i] = a[i];
}

void Student :: setName (string b) {name = b; }								// <-- Name setter.	

void Student :: setSemester (unsigned int c){semester = c; }					// <-- Semester setter.

void Student :: setPassed_courses (unsigned int x) {passed_courses=x; }			//	<-- Passed courses setter.

void Student :: setGradesArray (float *g)										
{
	delete [] grades_array;
	int i;
	grades_array= new float [passed_courses];										
	for (i=0; i<passed_courses; i++)					// <-- Grade array setter.
		grades_array[i] = g[i];
}

void Student :: AddGrade (float f)								
{
	float *tmp;
	tmp=new float (passed_courses+1);
	for (int i=0; i<passed_courses; i++)
		tmp[i]=grades_array[i];
	tmp[passed_courses] = f;					// <-- This function when used adds a grade at the array of grades.
	passed_courses++;
	delete [] grades_array;
	grades_array=tmp;
}

ostream& operator << (ostream &channel, const Student &s);			// <-- Function that prints in ostream.
void printArray (ostream& channel, const Student &s);
int main (int argc, char **argv)
{
	float *Array;
	string Name ("Vasileios Koumanis");
	system ("chcp 1253");
	Student s1("19390104", Name);
	Student s2("19390075","Redion Kapo",2,8);
	Student s3("1996","Super Mario",6,4);
	Student s4("646464","Donkey Kong",11);
	//Student s5("000000","Mirror object",0,0);
	Student s5=s1;														// <-- The mirror object s4 is now a copy of s1
	cout << s1 << endl;	
	printArray(cout,s1);
	
	cout << s2 << endl;	
	printArray(cout,s2);
	
	cout << s3 << endl;											// <-- The operator "<<" here is overloaded. 
	printArray(cout,s3);										
	
	cout << s4 << endl;	
	printArray(cout,s4);
	
	cout << s5 << endl;
	printArray(cout,s5);									// <-- Shows the mirror image object of "s1".
	
	s3.AddGrade(rand() %(50+51)/10);  						// <-- adds a random grade (between 5,10) for the object "s3".
	cout << s3 << endl;
	printArray(cout,s3); 									// <-- Shows the updated array of the object "s3".
	
	s1.~Student();
	s2.~Student();
	s3.~Student();
	s4.~Student();
	s5.~Student();
	return 0;
}

ostream& operator << (ostream& channel, const Student &s)
{
	channel << "Name= " << s.getName() << endl;							//  " << " overload and then it prints in ostream 
	channel << "AM= " << s.getAM() << endl;
	channel << "Semester= " << s.getSemester() << endl;
	return channel;
}

void printArray (ostream& channel, const Student &s)
{
	double sum=0,avg=0;
	channel << "Passed Courses= " << s.getPassed_courses() << endl;
	if (s.getPassed_courses()!=0)
	{
		for (int j=0; j<s.getPassed_courses(); j++)
		{	
			channel << "Lesson " << j+1 << " = " << s.getGradesArray()[j] << endl;		// A function that prints in ostream
			sum+=s.getGradesArray()[j];
		}
		avg=sum/s.getPassed_courses();
	}
	else
		channel <<  "The array of grades does not exist." << endl;	
	channel << "Average= " << avg << "\n" << endl;
}
