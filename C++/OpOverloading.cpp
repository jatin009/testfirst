#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
	string name;
	int age;
	int rollno;

	Student(const string& s, int a, int r)
	{
		name = s; age = a; rollno = r;
	}
};

bool operator>= (Student& st1, Student& st2)
{
	return (st1.age >= st2.age);
}

ostream& operator<< (ostream& out, const Student& st)
{
	out << "Name: " << st.name << ", Age: " << st.age << ", RollNo.: " << st.rollno;
	return out;
}

int main()
{
	Student st1("Anjali",26,03);
	Student st2("Deepti",30,16);

	cout << st1 << endl;	
}
