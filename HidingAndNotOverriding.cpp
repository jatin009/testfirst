#include <iostream>
using namespace std;

class A {

public:
	void val(){ cout << 1; }
	void val( int x ) { cout << "Base: " << x << endl; }

};

class B: public A {

public:
	void val( int x ) { cout << "Derived: " << x << endl; }

};

int main()
{
	A* b = new B;
	b->val(3);
}
