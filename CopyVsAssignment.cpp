#include <iostream>
#include <string.h>

using namespace std;

class A {
private:
int x;
public:
	A(int a){cout << "Ctor called" << endl;x=a;}
	A(const A& obj){cout << "Copy called" << endl;this->x = obj.x;}
	void operator=(const A& obj){cout << "Assignment called" << endl;this->x = obj.x;}
};

int main (int argc, char** argv)
{
	A a1(2);
	A a2 = a1;

	A a3(1);
	a3 = a1;
}

