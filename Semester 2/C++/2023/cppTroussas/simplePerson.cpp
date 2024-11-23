#include <iostream>
#include <cstring>

using namespace std;

class Person
{
	private:
		string name;
		int age;
	public:
		inline void setName(string n)
		{
			name =n;
		}
		inline void setAge(int a)
		{
			age=a;
		}
		inline int getAge()
		{
			return age;
		}
		inline string setName()
		{
			return name;
		}
};


int main()
{
	Person p1;
	p1.setName("Chris");
	p1.setAge(12);
	return 0;
}